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
# define GNULIB_LOCALEDIR "/Users/sedwards/gtk/share/locale"
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
