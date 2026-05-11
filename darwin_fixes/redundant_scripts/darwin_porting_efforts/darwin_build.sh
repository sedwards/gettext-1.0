 #!/bin/bash

ROOT_DIR=$(pwd)
export PATH="/Users/sedwards/gtk/bin:$PATH"
export M4="/Users/sedwards/gtk/bin/m4"
export ACLOCAL_FLAGS="-I /Users/sedwards/gtk/share/aclocal"
export PKG_CONFIG_PATH="/Users/sedwards/gtk/lib/pkgconfig"
export LD_LIBRARY_PATH="/Users/sedwards/gtk/lib"
export XDG_DATA_DIRS="/Users/sedwards/share"
export GNULIB_SRCDIR="/Users/sedwards/gtk/source/gnulib"


echo "--- 1. Patching configure.ac ---"
# Add gl_EARLY after AC_PROG_CC if missing
grep -q "gl_EARLY" configure.ac || sed -i '' '/AC_PROG_CC/a\
gl_EARLY' configure.ac

# Add gl_INIT if missing
grep -q "gl_INIT" configure.ac || sed -i '' '/gl_EARLY/a\
gl_INIT' configure.ac

# Ensure gnulib-lib/Makefile is in the config files list
grep -q "gnulib-lib/Makefile" configure.ac || sed -i '' 's|AC_CONFIG_FILES(\[|AC_CONFIG_FILES([gnulib-lib/Makefile |' configure.ac

echo "--- 2. Patching Makefile.am ---"
# Ensure gnulib-lib is in SUBDIRS
grep -q "gnulib-lib" Makefile.am || sed -i '' 's/SUBDIRS =/SUBDIRS = gnulib-lib /' Makefile.am

# Ensure ACLOCAL_AMFLAGS includes the new m4 directory
grep -q "gnulib-m4" Makefile.am || sed -i '' 's/ACLOCAL_AMFLAGS =/ACLOCAL_AMFLAGS = -I gnulib-m4 /' Makefile.am

echo "--- 3. Running autoreconf ---"
# Use absolute paths to prevent the directory-not-found errors in subdirs
autoreconf -fiv \
  -I "$ROOT_DIR/m4" \
  -I "$ROOT_DIR/gnulib-m4" \
  -I "$ROOT_DIR/gettext-tools/gnulib-m4"

echo "--- 4. Re-configuring ---"
./configure --prefix=/Users/sedwards/gtk \
  --disable-dependency-tracking \
  --without-libxml2 \
  --disable-nls \
  --disable-intl

echo "--- 5. Applying Darwin config.h shims ---"
# This puts our fixes back since 'configure' just overwrote config.h
for c in $(find . -name "config.h"); do
    grep -q "DARWIN_BOOTSTRAP_SHIMS" "$c" || cat >> "$c" <<EOF

/* DARWIN_BOOTSTRAP_SHIMS */
#include <stddef.h>
#include <string.h>
#ifndef _GL_MEMRCHR_DEFINED
#define _GL_MEMRCHR_DEFINED
static inline void *memrchr(const void *s, int c, size_t n) {
    const unsigned char *cp = (const unsigned char *) s + n;
    while (n--) if (*--cp == (unsigned char) c) return (void *) cp;
    return 0;
}
#endif
#ifndef __environ
# include <crt_externs.h>
# define environ (*_NSGetEnviron())
#endif
EOF
done

echo "--- 6. Final cleanup and build ---"
find . -name "*.o" -delete
make

