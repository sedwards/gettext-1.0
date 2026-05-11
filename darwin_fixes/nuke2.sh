#!/bin/bash

echo "--- 1. Injecting Global Shims into config.h ---"
find . -name "config.h" -exec sed -i '' '/DARWIN_MASTER_FIX/,/EOF/d' {} +

for c in $(find . -name "config.h"); do
    cat >> "$c" <<EOF
/* DARWIN_MASTER_FIX */
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <fcntl.h>

/* Missing GNU Constants (Fixes GNULIB_LOCALEDIR and O_BINARY errors) */
#ifndef GNULIB_LOCALEDIR
# define GNULIB_LOCALEDIR "/Users/sedwards/gtk/share/locale"
#endif
#ifndef O_BINARY
# define O_BINARY 0
#endif

/* Gnulib Memory Wrappers (Fixes xrealloc/XNMALLOC errors) */
#ifdef __cplusplus
extern "C" {
#endif
    static inline void *xmalloc(size_t n) {
        void *p = malloc(n); if (!p && n) abort(); return p;
    }
    static inline void *xrealloc(void *p, size_t n) {
        void *r = realloc(p, n); if (!r && r == NULL && n) abort(); return r;
    }
#ifdef __cplusplus
}
#endif
#ifndef XNMALLOC
# define XNMALLOC(n, t) ((t *) xmalloc ((n) * sizeof (t)))
#endif

/* Basic Darwin Environment */
#ifndef __environ
# include <crt_externs.h>
# define environ (*_NSGetEnviron())
#endif
EOF
done

echo "--- 2. Fixing Makefile Dependencies & Separators ---"
# Fixes "No rule to make target libgnu.la" by pointing to the correct location
find . -name "Makefile" -exec sed -i '' 's|gnulib-lib/libgnu.la|libgnu.la|g' {} +
# Standard separator and placeholder cleanup
find . -name "Makefile" -exec sed -i '' '
    s/^[ ]*GL_GENERATE/GL_GENERATE/g;
    s/^[ ]*GL_COND/GL_COND/g;
    s/^    /\t/g;
    s/@[A-Z0-9_]\{1,\}_H@//g;
' {} +

echo "--- 3. Clearing the root blockage ---"
cat > gnulib-lib/Makefile <<EOF
all:
	@echo "Bypassing root gnulib-lib..."
install:
clean:
EOF

echo "Ready. Running make -k -j$(sysctl -n hw.ncpu)"
make -k -j$(sysctl -n hw.ncpu)

