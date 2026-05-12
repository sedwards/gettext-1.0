#define xmalloc config_h_hidden_xmalloc
#define xrealloc config_h_hidden_xrealloc
#define xmalloc config_h_hidden_xmalloc
#define xrealloc config_h_hidden_xrealloc
/* Force system types and time definitions to prevent 'incomplete type' errors */
#include <sys/types.h>
#include <time.h>
#include <sys/time.h>
#include <fcntl.h>
#include <sys/stat.h>
#undef xmalloc
#undef xrealloc

#undef xmalloc
#undef xrealloc

/* DARWIN_PORTING_SHIM */
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <fcntl.h>

/* Gnulib Common Macros & Attributes */
#ifndef _GL_ATTRIBUTE_ALLOC_SIZE
# define _GL_ATTRIBUTE_ALLOC_SIZE(x)
#endif
#ifndef _GL_ATTRIBUTE_RETURNS_NONNULL
# define _GL_ATTRIBUTE_RETURNS_NONNULL
#endif
#ifndef _GL_ATTRIBUTE_PURE
# define _GL_ATTRIBUTE_PURE
#endif
#ifndef _GL_ATTRIBUTE_CONST
# define _GL_ATTRIBUTE_CONST
#endif
#ifndef _GL_ATTRIBUTE_MALLOC
# define _GL_ATTRIBUTE_MALLOC
#endif
#ifndef _GL_ATTRIBUTE_NODISCARD
# define _GL_ATTRIBUTE_NODISCARD
#endif
#ifndef _GL_ATTRIBUTE_COLD
# define _GL_ATTRIBUTE_COLD
#endif
#ifndef _GL_ATTRIBUTE_NONNULL
# define _GL_ATTRIBUTE_NONNULL(x)
#endif
#ifndef _GL_ATTRIBUTE_NONNULL_IF_NONZERO
# define _GL_ATTRIBUTE_NONNULL_IF_NONZERO(x, y)
#endif
#ifndef _GL_UNUSED
# define _GL_UNUSED
#endif
#ifndef _GL_GNUC_PREREQ
# if defined __GNUC__ && defined __GNUC_MINOR__
#  define _GL_GNUC_PREREQ(maj, min) ((maj) < __GNUC__ || ((maj) == __GNUC__ && (min) <= __GNUC_MINOR__))
# else
#  define _GL_GNUC_PREREQ(maj, min) 0
# endif
#endif

/* Missing GNU Macros */
#ifndef streq
# define streq(a, b) (strcmp (a, b) == 0)
#endif
#ifndef memeq
# define memeq(a, b, n) (memcmp (a, b, n) == 0)
#endif
#ifndef EXIT_FAILURE
# define EXIT_FAILURE 1
#endif
#ifndef VERSION
# define VERSION "1.0"
#endif
#ifndef PACKAGE
# define PACKAGE "gettext"
#endif
#ifndef DLL_VARIABLE
# define DLL_VARIABLE
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

/* POSIX / Darwin IO Compatibility */
#ifndef O_BINARY
# define O_BINARY 0
#endif

/* Missing GNU Constants */
#ifndef GNULIB_LOCALEDIR
# define GNULIB_LOCALEDIR "/share/locale"
#endif

/* Standard Function Declarations (Force C Linkage) */
#ifdef __cplusplus
extern "C" {
#endif
  void error(int status, int errnum, const char *format, ...);
  void error_at_line(int status, int errnum, const char *fname, unsigned int lineno, const char *format, ...);
  void *reallocarray(void *ptr, size_t nmemb, size_t size);
  
  static inline void *memrchr(const void *s, int c, size_t n) {
      const unsigned char *cp = (const unsigned char *) s + n;
      while (n--) if (*--cp == (unsigned char) c) return (void *) cp;
      return 0;
  }
#ifdef __cplusplus
}
#endif

#ifndef HAVE_MEMRCHR
# define HAVE_MEMRCHR 1
#endif
#ifndef HAVE_REALLOCARRAY
# define HAVE_REALLOCARRAY 1
#endif

/* Darwin Environment */
#ifndef __environ
# include <crt_externs.h>
# define environ (*_NSGetEnviron())
#endif
