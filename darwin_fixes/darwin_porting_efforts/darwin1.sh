#!/bin/bash

# --- 0. ENVIRONMENT SETUP ---
ROOT_DIR=$(pwd)
# Prioritize your custom prefix tools
export PATH="/Users/sedwards/gtk/bin:$PATH"
export M4="/Users/sedwards/gtk/bin/m4"

echo "--- 1. IDEMPOTENT PATCHING (configure.ac & Makefile.am) ---"
# Add gl_EARLY and gl_INIT after AC_PROG_CC only if missing
grep -q "gl_EARLY" configure.ac || sed -i '' '/AC_PROG_CC/a\
gl_EARLY' configure.ac

grep -q "gl_INIT" configure.ac || sed -i '' '/gl_EARLY/a\
gl_INIT' configure.ac

# Register gnulib-lib/Makefile once
if ! grep -q "gnulib-lib/Makefile" configure.ac; then
    sed -i '' 's|AC_CONFIG_FILES(\[|AC_CONFIG_FILES([gnulib-lib/Makefile |' configure.ac
fi

# Wire SUBDIRS and ACLOCAL_AMFLAGS
grep -q "gnulib-lib" Makefile.am || sed -i '' 's/SUBDIRS =/SUBDIRS = gnulib-lib /' Makefile.am
grep -q "gnulib-m4" Makefile.am || sed -i '' 's/ACLOCAL_AMFLAGS =/ACLOCAL_AMFLAGS = -I gnulib-m4 /' Makefile.am

echo "--- 2. CLEAN REGENERATION (autoreconf) ---"
# Deleting old cache to prevent "already registered" errors
rm -f aclocal.m4
autoreconf -fiv \
  -I "$ROOT_DIR/m4" \
  -I "$ROOT_DIR/gnulib-m4" \
  -I "$ROOT_DIR/gettext-tools/gnulib-m4"

echo "--- 3. CONFIGURATION ---"
./configure --prefix=/Users/sedwards/gtk \
  --disable-dependency-tracking \
  --without-libxml2 \
  --disable-nls \
  --disable-intl

echo "--- 4. TAB CORRUPTION REPAIR (The 'Missing Separator' Fix) ---"
# Fixes spaces mistakenly converted from tabs in generated Makefiles
for mfile in $(find . -name "Makefile"); do
    # Replaces 4 spaces with a literal Tab if they appear at line start
    sed -i '' $'s/^    /\t/g' "$mfile"
done

echo "--- 5. DARWIN CONFIG.H SHIMS ---"
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

echo "--- 6. FREEZE TIMESTAMPS & BUILD ---"
# Stop the Automake 1.18 remake loop
touch configure aclocal.m4 Makefile.in config.h.in
find . -name "Makefile.in" -exec touch {} +
make

