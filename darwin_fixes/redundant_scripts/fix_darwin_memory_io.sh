#!/bin/bash

echo "--- 1. Injecting Gnulib Convenience Shims into config.h ---"
for c in $(find . -name "config.h"); do
    # Remove previous DARWIN_SYNTAX_FIX block to avoid duplication
    sed -i '' '/DARWIN_SYNTAX_FIX/,/EOF/d' "$c"
    
    cat >> "$c" <<EOF
/* DARWIN_SYNTAX_FIX */
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <fcntl.h>

/* Gnulib Memory Wrappers (Fixes printf-command.c and escapes.h) */
static inline void *xmalloc(size_t n) { 
    void *p = malloc(n); if (!p && n) abort(); return p; 
}
static inline void *xrealloc(void *p, size_t n) { 
    void *r = realloc(p, n); if (!r && n) abort(); return r; 
}
#define XNMALLOC(n, t) ((t *) xmalloc ((n) * sizeof (t)))

/* Gnulib Inline Macros (Fixes c-ctype.h and xalloc.h) */
#ifndef _GL_INLINE
# define _GL_INLINE static inline
#endif
#ifndef _GL_INLINE_HEADER_BEGIN
# define _GL_INLINE_HEADER_BEGIN
#endif
#ifndef _GL_INLINE_HEADER_END
# define _GL_INLINE_HEADER_END
#endif

/* POSIX / Darwin IO Compatibility (Fixes envsubst.c) */
#ifndef O_BINARY
# define O_BINARY 0
#endif

/* Missing GNU Constants */
#ifndef GNULIB_LOCALEDIR
# define GNULIB_LOCALEDIR "/Users/sedwards/gtk/share/locale"
#endif

/* Standard Function Declarations */
#ifdef __cplusplus
extern "C" {
#endif
  void error(int status, int errnum, const char *format, ...);
  static inline int streq(const char *a, const char *b) { return strcmp(a, b) == 0; }
  static inline int memeq(const void *a, const void *b, size_t n) { return memcmp(a, b, n) == 0; }
#ifdef __cplusplus
}
#endif

#ifndef __environ
# include <crt_externs.h>
# define environ (*_NSGetEnviron())
#endif
EOF
done

echo "--- 2. Repairing libgnu.la path mismatches ---"
# This fixes the "No rule to make target libgnu.la" error in subdirectories
find . -name "Makefile" -exec sed -i '' 's|gnulib-lib/libgnu.la|libgnu.la|g' {} +

echo "Ready. Running make -k -j$(sysctl -n hw.ncpu)"
make -k -j$(sysctl -n hw.ncpu)

