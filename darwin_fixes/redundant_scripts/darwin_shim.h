#ifndef DARWIN_SHIM_H
#define DARWIN_SHIM_H
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Missing Constants */
#ifndef GNULIB_LOCALEDIR
# define GNULIB_LOCALEDIR "/Users/sedwards/gtk/share/locale"
#endif

/* Prototypes (Only if not already defined by headers) */
void error(int status, int errnum, const char *format, ...);
void xalloc_die(void);
char *last_component(char const *name);
void *xmalloc(size_t n);
void *xrealloc(void *p, size_t n);

#ifndef __environ
# include <crt_externs.h>
# define environ (*_NSGetEnviron())
#endif

#ifdef __cplusplus
}
#endif
#define XNMALLOC(n, t) ((t *) xmalloc ((n) * sizeof (t)))
#endif
