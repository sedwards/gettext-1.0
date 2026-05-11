#!/bin/bash

ROOT_DIR=$(pwd)
export PATH="/Users/sedwards/gtk/bin:$PATH"
export M4="/Users/sedwards/gtk/bin/m4"
export ACLOCAL_FLAGS="-I /Users/sedwards/gtk/share/aclocal"
export PKG_CONFIG_PATH="/Users/sedwards/gtk/lib/pkgconfig"
export LD_LIBRARY_PATH="/Users/sedwards/gtk/lib"
export XDG_DATA_DIRS="/Users/sedwards/share"
export GNULIB_SRCDIR="/Users/sedwards/gtk/source/gnulib"



echo "--- 1. Resetting build system ---"
# Remove previous broken Makefiles to force a clean slate
find . -name "Makefile" -delete

echo "--- 2. Re-configuring (Generating fresh Makefiles) ---"
./configure --prefix=/Users/sedwards/gtk \
  --disable-dependency-tracking \
  --without-libxml2 \
  --disable-nls \
  --disable-intl

echo "--- 3. DEEP TAB REPAIR (Fixing 'Missing Separator') ---"
# This targets every Makefile in every sub-package
find . -name "Makefile" -exec sed -i '' $'s/^    /\t/g' {} +

echo "--- 4. DEEP CONFIG.H SHIMS ---"
# This ensures sub-packages like gettext-tools/config.h get the fixes
for c in $(find . -name "config.h"); do
    if ! grep -q "DARWIN_BOOTSTRAP_SHIMS" "$c"; then
        cat >> "$c" <<EOF
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
    fi
done

echo "--- 5. FREEZING TIMESTAMPS ---"
# Stop the remake loops in all subdirectories
find . -name "Makefile.in" -exec touch {} +
touch configure aclocal.m4 config.h.in

echo "--- 6. BUILD ---"
make

