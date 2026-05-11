#!/bin/bash
# darwin_porting_fixes.sh - Consolidated Master Darwin Porting Script
# This script consolidates various fixes for building GNU gettext on Darwin.

ROOT_DIR=$(pwd)
PREFIX="/Users/sedwards/gtk"
SDK_PATH=$(xcrun --show-sdk-path)
SDK_INC="$SDK_PATH/usr/include"

echo "--- [1/12] Fixing Libtool dependencies & Shims ---"
# Fix broken gsed path in Libtool script
LIBTOOL_BIN="$PREFIX/bin/libtool"
GSED_BIN="$PREFIX/bin/gsed"
if [ -f "$LIBTOOL_BIN" ] && [ -f "$GSED_BIN" ]; then
    sed -i '' "s|/opt/homebrew/bin/gsed|$GSED_BIN|g" "$LIBTOOL_BIN"
fi

# Patch all configure.ac files for missing Libtool macros on Darwin
find . -name "configure.ac" | while read -r confac; do
    if ! grep -q "m4_pattern_allow(\[_LT_ENABLE_SHARED_DEFAULT\])" "$confac"; then
        # Insert shims after AC_INIT
        sed -i '' '/AC_INIT/a\
m4_pattern_allow([_LT_ENABLE_SHARED_DEFAULT])\
m4_pattern_allow([_LT_ENABLE_STATIC_DEFAULT])\
m4_pattern_allow([_LT_ENABLE_FAST_INSTALL_DEFAULT])\
m4_pattern_allow([_LT_WITH_AIX_SONAME_DEFAULT])\
m4_ifndef([_LT_ENABLE_SHARED_DEFAULT], [m4_define([_LT_ENABLE_SHARED_DEFAULT], [yes])])\
m4_ifndef([_LT_ENABLE_STATIC_DEFAULT], [m4_define([_LT_ENABLE_STATIC_DEFAULT], [yes])])\
m4_ifndef([_LT_ENABLE_FAST_INSTALL_DEFAULT], [m4_define([_LT_ENABLE_FAST_INSTALL_DEFAULT], [yes])])\
m4_ifndef([_LT_WITH_AIX_SONAME_DEFAULT], [m4_define([_LT_WITH_AIX_SONAME_DEFAULT], [maybe])])
' "$confac"
    fi
done

echo "--- [2/12] Regenerating Build System (Autotools) - [DISABLED] ---"
# Note: Regeneration often introduces macro mismatch issues on Darwin.
# If needed, run manually: aclocal -I gnulib-m4 -I m4 && autoconf

echo "--- [3/12] Running Configure with Darwin Options ---"
#./configure --prefix="$PREFIX" \
#  M4="$PREFIX/bin/m4" \
#  --disable-dependency-tracking \
#  --without-libxml2 \
#  --disable-nls \
#  --disable-intl

./configure --prefix=/Users/sedwards/gtk \
  --build=arm64-apple-darwin --host=arm64-apple-darwin \
  M4="$PREFIX/bin/m4" \
  --disable-dependency-tracking \
  --with-included-gettext \
  --without-libxml2 \
  --disable-java \
  --disable-d \
  --disable-csharp \
  --disable-curses \
  --disable-libasprintf \
  --disable-modula2 \
  --without-libncurses-prefix \
  --without-libtermcap-prefix \
  --without-libxcurses-prefix \
  --without-libcurses-prefix \
  --without-libtextstyle-prefix \
  --with-included-libunistring \
  --without-emacs \

echo "--- [4/12] Cleaning up previous shim attempts ---"
find . -name "config.h" -exec sed -i '' '/DARWIN_/,/EOF/d' {} +
find . -name "config.h" -exec sed -i '' '/static inline void \*xmalloc/,/}/d' {} +
find . -name "config.h" -exec sed -i '' '/static inline void \*xrealloc/,/}/d' {} +

echo "--- [5/12] Fixing Makefile Syntax & Tab Issues ---"
# First, remove specific broken patterns that cause "missing separator"
# Specifically lines that start with spaces after a conditional is removed
find . -name "Makefile" -exec sed -i '' 's/^ \+/\t/g' {} +

# Standard syntax cleanup
find . -name "Makefile" -exec sed -i '' '
    s/^[ ]*\([A-Z0-9_]\{1,\} =\)/\1/g;
    s/^[ ]*GL_GENERATE/GL_GENERATE/g;
    s/^[ ]*GL_GNULIB/GL_GNULIB/g;
    s/^[ ]*GL_GTTGL/GL_GTTGL/g;
    s/^[ ]*GL_COND/GL_COND/g;
    s/^[ ]*NEXT_SYS/NEXT_SYS/g;
    s|^if |# if |g;
    s|^else|# else|g;
    s|^endif|# endif|g;
    s/@CFLAG_VISIBILITY@//g;
    s/@[A-Z0-9_]\{1,\}_H@//g;
    s|gnulib-lib/libgnu.la|libgnu.la|g;
' {} +

# Ensure targets (lines ending in :) are not indented with Tabs
find . -name "Makefile" -exec sed -i '' 's/^\t\([a-zA-Z0-9._]\{1,\}:\)/\1/' {} +

echo "--- [6/12] Repairing Header Loops & SDK Proxying ---"
# We prefer macOS SDK headers to avoid conflicting GNU implementations
find . -name "gnulib-lib" -type d | while read -r libdir; do
    cd "$libdir"
    mkdir -p sys
    echo "#include <$SDK_INC/stdlib.h>" > stdlib.h
    echo "#include <$SDK_INC/string.h>" > string.h
    echo "#include <$SDK_INC/unistd.h>" > unistd.h
    echo "#include <$SDK_INC/float.h>" > float.h
    echo "#include <$SDK_INC/sys/wait.h>" > sys/wait.h
    echo "#include <$SDK_INC/sys/resource.h>" > sys/resource.h
    
    # Satisfy Makefile dependencies for optional GNU headers
    touch alloca.h byteswap.h stdbit.h fnmatch.h error.h uchar.h
    
    # Fix include_next in ctype.h to point directly to SDK
    if [ -f "ctype.h" ]; then
        sed -i '' "s|#include_next @NEXT_CTYPE_H@|#include <$SDK_INC/ctype.h>|" ctype.h
    fi
    cd "$ROOT_DIR"
done

echo "--- [7/12] Injecting Darwin Shims into config.h ---"
find . -name "config.h" -exec bash -c '
    cfile="$1"
    cat >> "$cfile" <<EOF
/* DARWIN_PORTING_SHIM */
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <fcntl.h>

/* Gnulib Common Macros & Attributes */
#ifndef _GL_ATTRIBUTE_ALLOC_SIZE
# define _GL_ATTRIBUTE_ALLOC_SIZE(x)
#endif
#ifndef _GL_ATTRIBUTE_RETURNS_NONNULL
# define _GL_ATTRIBUTE_RETURNS_NONNULL
#endif
#ifndef _GL_ATTRIBUTE_PURE
# define _GL_ATTRIBUTE_PURE
#endif
#ifndef _GL_ATTRIBUTE_CONST
# define _GL_ATTRIBUTE_CONST
#endif
#ifndef _GL_ATTRIBUTE_MALLOC
# define _GL_ATTRIBUTE_MALLOC
#endif
#ifndef _GL_ATTRIBUTE_NODISCARD
# define _GL_ATTRIBUTE_NODISCARD
#endif
#ifndef _GL_ATTRIBUTE_COLD
# define _GL_ATTRIBUTE_COLD
#endif
#ifndef _GL_ATTRIBUTE_NONNULL
# define _GL_ATTRIBUTE_NONNULL(x)
#endif
#ifndef _GL_ATTRIBUTE_NONNULL_IF_NONZERO
# define _GL_ATTRIBUTE_NONNULL_IF_NONZERO(x, y)
#endif
#ifndef _GL_UNUSED
# define _GL_UNUSED
#endif
#ifndef _GL_GNUC_PREREQ
# if defined __GNUC__ && defined __GNUC_MINOR__
#  define _GL_GNUC_PREREQ(maj, min) ((maj) < __GNUC__ || ((maj) == __GNUC__ && (min) <= __GNUC_MINOR__))
# else
#  define _GL_GNUC_PREREQ(maj, min) 0
# endif
#endif

/* Missing GNU Macros */
#ifndef streq
# define streq(a, b) (strcmp (a, b) == 0)
#endif
#ifndef memeq
# define memeq(a, b, n) (memcmp (a, b, n) == 0)
#endif
#ifndef EXIT_FAILURE
# define EXIT_FAILURE 1
#endif
#ifndef VERSION
# define VERSION "1.0"
#endif
#ifndef PACKAGE
# define PACKAGE "gettext"
#endif
#ifndef DLL_VARIABLE
# define DLL_VARIABLE
#endif

/* Gnulib Memory Wrappers */
static inline void *xmalloc(size_t n) { 
    void *p = malloc(n); if (!p && n) abort(); return p; 
}
static inline void *xrealloc(void *p, size_t n) { 
    void *r = realloc(p, n); if (!r && n) abort(); return r; 
}
#ifndef XNMALLOC
# define XNMALLOC(n, t) ((t *) xmalloc ((n) * sizeof (t)))
#endif

/* POSIX / Darwin IO Compatibility */
#ifndef O_BINARY
# define O_BINARY 0
#endif

/* Missing GNU Constants */
#ifndef GNULIB_LOCALEDIR
# define GNULIB_LOCALEDIR "$PREFIX/share/locale"
#endif

/* Standard Function Declarations (Force C Linkage) */
#ifdef __cplusplus
extern "C" {
#endif
  void error(int status, int errnum, const char *format, ...);
  void error_at_line(int status, int errnum, const char *fname, unsigned int lineno, const char *format, ...);
  void *reallocarray(void *ptr, size_t nmemb, size_t size);
  
  static inline void *memrchr(const void *s, int c, size_t n) {
      const unsigned char *cp = (const unsigned char *) s + n;
      while (n--) if (*--cp == (unsigned char) c) return (void *) cp;
      return 0;
  }
#ifdef __cplusplus
}
#endif

#ifndef HAVE_MEMRCHR
# define HAVE_MEMRCHR 1
#endif
#ifndef HAVE_REALLOCARRAY
# define HAVE_REALLOCARRAY 1
#endif

/* Darwin Environment */
#ifndef __environ
# include <crt_externs.h>
# define environ (*_NSGetEnviron())
#endif
EOF
' -- {} \;

echo "--- [8/12] Fixing Corrupted Header Preprocessor Logic ---"
# Fixes "#if ( &&" or "#elif &&" caused by empty GNULIB variables
find . -name "*.h" -exec sed -i '' 's/#if (  *&&/#if (0 \&\&/g' {} +
find . -name "*.h" -exec sed -i '' 's/#elif  *&&/#elif 0 \&\&/g' {} +
find . -name "*.h" -exec sed -i '' 's/#if  *&&/#if 0 \&\&/g' {} +

echo "--- [9/12] Clearing root blockage (gnulib-lib) ---"
if [ -d "gnulib-lib" ]; then
    cat > gnulib-lib/Makefile <<EOF
all:
	@echo "Bypassing root gnulib-lib..."
install:
clean:
EOF
fi

echo "--- [10/12] Fixing libasprintf libgnu.la requirement ---"
for dir in "libasprintf" "gettext-runtime/libasprintf"; do
    if [ -d "$dir" ]; then
        mkdir -p "$dir/gnulib-lib"
        cat > "$dir/gnulib-lib/libgnu.la" <<EOF
# libgnu.la - a libtool library file
dlname=''
library_names=''
old_library=''
inherited_linker_flags=''
dependency_libs=''
current=0
age=0
revision=0
installed=no
shouldnotlink=no
libdir=''
EOF
        find "$dir" -name "Makefile" -exec sed -i '' 's/gnulib-lib\/libgnu.la//g' {} +
    fi
done

echo "--- [11/12] Creating Linker Stubs ---"
# We create stubs for both tools and runtime to avoid missing symbols
for dir in "gettext-tools/src" "gettext-runtime/src"; do
    if [ -d "$dir" ]; then
        cat > "$dir/darwin_linker_stubs.c" <<EOF
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

const char *program_name = "gettext";
void set_program_name(const char *name) { program_name = name; }
void close_stdout(void) { fflush(stdout); }
void xalloc_die(void) { abort(); }

/* Variadic/Complex signatures to satisfy the linker */
void _gl_start_options (int argc, char **argv, const void *options, 
                       size_t count, const void *long_options, 
                       const char *short_options, int nonopt_handling, 
                       int error_handling) { }

int get_next_option(void) { return -1; }
const char *proper_name(const char *name) { return name; }
int fzprintf (FILE *stream, const char *format, ...) { return 0; }

char *last_component(char const *name) {
    char *p = strrchr(name, '/');
    return p ? p + 1 : (char *) name;
}

void error(int status, int errnum, const char *format, ...) {
    va_list ap; va_start(ap, format);
    fprintf(stderr, "%s: ", program_name);
    vfprintf(stderr, format, ap); fprintf(stderr, "\n");
    va_end(ap); if (status) exit(status);
}

void *xmalloc(size_t n) { void *p = malloc(n); if (!p && n) abort(); return p; }
void *xrealloc(void *p, size_t n) { void *r = realloc(p, n); if (!r && n) abort(); return r; }
EOF
        gcc -c "$dir/darwin_linker_stubs.c" -o "$dir/darwin_linker_stubs.o"
        
        # Inject the stub object into the specific binary target in Makefile
        if [ -f "$dir/Makefile" ]; then
            sed -i '' 's/gettext-gettext.o/gettext-gettext.o darwin_linker_stubs.o/g' "$dir/Makefile"
        fi
    fi
done

echo "--- [12/12] Freezing Timestamps (Bypass Remake Loop) ---"
find . -name "*.am" -exec touch -t 202001010000 {} +
find . -name "*.ac" -exec touch -t 202001010000 {} +
find . -name "*.m4" -exec touch -t 202001010000 {} +
find . -name "*.in" -exec touch -t 202401010000 {} +
touch -t 202401010000 configure aclocal.m4 config.h.in
find . -name "Makefile.in" -exec touch {} +

echo "--- [13/13] Shim to use system SDK everwhere we can
echo "Fix all Makefiles"
# Add this to your Master Porting Script to catch all unexpanded conditionals
find . -name "Makefile" -exec sed -i '' 's/^@[A-Z0-9_]\{1,\}@//' {} +

#!/bin/bash
# header_fixes.sh

HEADERS="fcntl.h sys/types.h sys/stat.h sys/select.h unistd.h stdlib.h string.h wchar.h wctype.h float.h sys/resource.h"

for h in $HEADERS; do
    echo "Converting $h to SDK proxy..."
    find . -path "*/$h" | while read -r target; do
        # Unlock and delete
        chmod 644 "$target" 2>/dev/null
        rm -f "$target"
        
        # Ensure directory exists
        mkdir -p "$(dirname "$target")"
        
        # Create the Proxy Header
        cat > "$target" <<EOF
/* Darwin SDK Proxy Header */
#ifndef _DARWIN_PROXY_H
#define _DARWIN_PROXY_H

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif
    void *malloc(size_t);
    void *realloc(void *, size_t);
    void free(void *);
    void abort(void);
    void exit(int);
#ifdef __cplusplus
}
#endif

/* Include actual system headers */
#include <sys/types.h>
#include <time.h>
#include <sys/time.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <wchar.h>
#include <wctype.h>
#include <float.h>
#include <sys/resource.h>

#endif
EOF

        # Lock the file
        chmod 444 "$target"
    done
done

echo "Stripping Makefile placeholders..."
find . -name "Makefile" -exec sed -i '' 's/@[A-Z0-9_]\{1,\}_H@//g' {} +

# Audit: Supposedly another Makefile fix
sed -i '' 's/@[A-Z0-9_]\{1,\}_H@//g' Makefile

sed -i '' 's/@[A-Z0-9_]\{1,\}_H@//g' Makefile

echo "Master porting fixes and configuration applied. You can now run 'make -k'"
