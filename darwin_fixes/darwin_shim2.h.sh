cat > darwin_shim.h <<EOF
#ifndef DARWIN_SHIM_H
#define DARWIN_SHIM_H

#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <fcntl.h>
#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifndef _XMALLOC_SHIM_DEFINED
#define _XMALLOC_SHIM_DEFINED
static inline void *xmalloc(size_t n) { 
    void *p = malloc(n); if (!p && n) abort(); return p; 
}
static inline void *xrealloc(void *p, size_t n) { 
    void *r = realloc(p, n); if (!r && n) abort(); return r; 
}
#endif

void error(int status, int errnum, const char *format, ...);
int fzprintf (FILE *stream, const char *format, ...);
void xalloc_die(void);

static inline int streq(const char *a, const char *b) { return strcmp(a, b) == 0; }
static inline int memeq(const void *a, const void *b, size_t n) { return memcmp(a, b, n) == 0; }

#ifndef __environ
# include <crt_externs.h>
# define environ (*_NSGetEnviron())
#endif

#ifdef __cplusplus
}
#endif

#endif /* DARWIN_SHIM_H */
EOF

