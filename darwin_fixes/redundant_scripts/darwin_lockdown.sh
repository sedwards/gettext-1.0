#!/bin/bash
# darwin_lockdown.sh

ROOT_DIR=$(pwd)
PREFIX="/Users/sedwards/gtk"

echo "--- 1. Creating the Immutable Darwin Shim ---"
# We create a single header that contains EVERY missing GNU-ism
cat > "$ROOT_DIR/darwin_shim.h" <<EOF
#ifndef DARWIN_SHIM_H
#define DARWIN_SHIM_H

#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <fcntl.h>
#include <stdio.h>

/* Missing GNU Constants */
#ifndef GNULIB_LOCALEDIR
# define GNULIB_LOCALEDIR "$PREFIX/share/locale"
#endif
#ifndef O_BINARY
# define O_BINARY 0
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

/* Missing GNU Function Prototypes */
#ifdef __cplusplus
extern "C" {
#endif
    void error(int status, int errnum, const char *format, ...);
    static inline int streq(const char *a, const char *b) { return strcmp(a, b) == 0; }
    static inline int memeq(const void *a, const void *b, size_t n) { return memcmp(a, b, n) == 0; }
#ifdef __cplusplus
}
#endif

/* Darwin Environment */
#ifndef __environ
# include <crt_externs.h>
# define environ (*_NSGetEnviron())
#endif

#endif /* DARWIN_SHIM_H */
EOF

echo "--- 2. Force-Injecting Shim into all Makefiles ---"
# Instead of editing config.h, we force-include our shim via CFLAGS
# This is "invincible" to config.h overwrites.
find . -name "Makefile" -exec sed -i '' "s|^CFLAGS = |CFLAGS = -include $ROOT_DIR/darwin_shim.h |g" {} +

echo "--- 3. Fixing Makefile Syntax & Dependency Loops ---"
find . -name "Makefile" -exec sed -i '' '
    s/^[ ]*\([A-Z0-9_]\{1,\} =\)/\1/g;
    s/^if /# if /g;
    s/^else/# else/g;
    s/^endif/# endif/g;
    s/^    /\t/g;
    s|gnulib-lib/libgnu.la|libgnu.la|g;
    s|@CFLAG_VISIBILITY@||g;
' {} +

echo "--- 4. Final Bypass for missing targets ---"
# Neutralizes the root gnulib-lib that was blocking the build
cat > gnulib-lib/Makefile <<EOF
all:
	@echo "Bypassing root gnulib-lib..."
install:
clean:
EOF

echo "--- 5. Freezing Build State ---"
touch configure aclocal.m4 Makefile.in config.h.in
find . -name "*.in" -exec touch -t 202401010000 {} +

echo "Lockdown complete. Running make -k -j$(sysctl -n hw.ncpu)"
make -k -j$(sysctl -n hw.ncpu)

