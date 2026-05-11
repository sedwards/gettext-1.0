#!/bin/bash
# master_darwin_porting.sh

ROOT_DIR=$(pwd)
PREFIX="/Users/sedwards/gtk"

echo "--- [1/4] Cleaning up broken local headers ---"
# Deleting these forces the compiler to use our config.h declarations 
# and look for system headers in the standard SDK paths.
find . -name "gnulib-lib" -type d | while read -r libdir; do
    rm -f "$libdir/stdlib.h" "$libdir/string.h" "$libdir/unistd.h" \
          "$libdir/sys/wait.h" "$libdir/sys/resource.h" "$libdir/float.h"
done

echo "--- [2/4] Injecting Nuclear Declarations into config.h ---"
find . -name "config.h" -exec bash -c '
    cfile="$1"
    if ! grep -q "DARWIN_MASTER_SHIM" "$cfile"; then
        cat >> "$cfile" <<EOF

/* DARWIN_MASTER_SHIM */
#include <stddef.h>

/* Forward declare standard library functions to bypass header mess */
#ifdef __cplusplus
extern "C" {
#endif
    void exit(int);
    void *malloc(size_t);
    void free(void *);
    size_t strlen(const char *);
    int strcmp(const char *, const char *);
    int strncmp(const char *, const char *, size_t);
    int memcmp(const void *, const void *, size_t);
#ifdef __cplusplus
}
#endif

#ifndef EXIT_FAILURE
# define EXIT_FAILURE 1
#endif

/* Gnulib Specific Macros */
#ifndef streq
# define streq(a, b) (strcmp (a, b) == 0)
#endif
#ifndef memeq
# define memeq(a, b, n) (memcmp (a, b, n) == 0)
#endif

/* Darwin/macOS Environment */
#ifndef __environ
# include <crt_externs.h>
# define environ (*_NSGetEnviron())
#endif

#define HAVE_MEMRCHR 1
#define HAVE_REALLOCARRAY 1
static inline void *memrchr(const void *s, int c, size_t n) {
    const unsigned char *cp = (const unsigned char *) s + n;
    while (n--) if (*--cp == (unsigned char) c) return (void *) cp;
    return 0;
}
EOF
    fi
' -- {} \;

echo "--- [3/4] Fixing Makefile Syntax ---"
find . -name "Makefile" -exec sed -i '' '
    s/^[ ]*GL_GNULIB/GL_GNULIB/g;
    s/^[ ]*GL_GTTGL/GL_GTTGL/g;
    s/^    /\t/g;
    s/@CFLAG_VISIBILITY@//g;
    s/@[A-Z0-9_]\{1,\}_H@//g;
' {} +

echo "--- [4/4] Freezing Timestamps & Building ---"
touch configure aclocal.m4 Makefile.in config.h.in
find . -name "Makefile.in" -exec touch {} +

# Try to build the core library first
if [ -f "gettext-tools/gnulib-lib/Makefile" ]; then
    cd gettext-tools/gnulib-lib && make -j$(sysctl -n hw.ncpu)
fi

