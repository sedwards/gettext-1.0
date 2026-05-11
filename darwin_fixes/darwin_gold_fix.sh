#!/bin/bash
# darwin_gold_fix.sh

echo "--- 1. Sanitizing all config.h files ---"
find . -name "config.h" -exec sed -i '' '/DARWIN_PORTING_SHIM/,/EOF/d' {} +
find . -name "config.h" -exec sed -i '' '/DARWIN_SYNTAX_FIX/,/EOF/d' {} +
find . -name "config.h" -exec sed -i '' '/DARWIN_MASTER_SHIM/,/EOF/d' {} +

for c in $(find . -name "config.h"); do
    cat >> "$c" <<EOF
/* DARWIN_PORTING_SHIM */
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <wchar.h>
#include <uchar.h>

/* Missing Types on Darwin / Gnulib conflict */
typedef __mbstate_t mbstate_t;
#ifndef char32_t
typedef __uint32_t char32_t;
#endif

/* Gnulib Inline Macros */
#ifndef _GL_INLINE
# define _GL_INLINE static inline
#endif
#ifndef _GL_INLINE_HEADER_BEGIN
# define _GL_INLINE_HEADER_BEGIN
#endif
#ifndef _GL_INLINE_HEADER_END
# define _GL_INLINE_HEADER_END
#endif

/* Standard Function Declarations (Force C Linkage) */
#ifdef __cplusplus
extern "C" {
#endif
  void error(int status, int errnum, const char *format, ...);
  void mbszero(mbstate_t *ps);
  size_t mbrtoc32(char32_t *pc, const char *s, size_t n, mbstate_t *ps);
  void *reallocarray(void *ptr, size_t nmemb, size_t size);
  
  /* Use unique names for inlines to avoid redefinition errors */
  static inline int darwin_streq(const char *a, const char *b) { return strcmp(a, b) == 0; }
  static inline int darwin_memeq(const void *a, const void *b, size_t n) { return memcmp(a, b, n) == 0; }
#ifdef __cplusplus
}
#endif

/* Map Gnulib names to our safe inlines */
#define streq darwin_streq
#define memeq darwin_memeq

/* Environment for Darwin */
#ifndef __environ
# include <crt_externs.h>
# define environ (*_NSGetEnviron())
#endif
EOF
done

echo "--- 2. Fixing Makefile Syntax & Dependencies ---"
find . -name "Makefile" -exec sed -i '' '
    s/^[ ]*GL_GENERATE/GL_GENERATE/g;
    s/^[ ]*GL_COND/GL_COND/g;
    s/^if /# if /g;
    s/^else/# else/g;
    s/^endif/# endif/g;
    s/^    /\t/g;
    s|gnulib-lib/libgnu.la|libgnu.la|g;
' {} +

echo "--- 3. Freezing Build State ---"
find . -name "*.in" -exec touch -t 202401010000 {} +
touch -t 202401010000 configure aclocal.m4 config.h.in

echo "Finalizing: Running make -k"
make -k

