#define xmalloc config_h_hidden_xmalloc
#define xrealloc config_h_hidden_xrealloc
#define xmalloc config_h_hidden_xmalloc
#define xrealloc config_h_hidden_xrealloc
#define xmalloc config_h_hidden_xmalloc
#define xrealloc config_h_hidden_xrealloc
#define xmalloc config_h_hidden_xmalloc
#define xrealloc config_h_hidden_xrealloc
/* Complete core Darwin mask properties to insulate from header loop bugs */
#ifndef _CTYPE_A
#define _CTYPE_A    0x00000100L
#endif
#ifndef _CTYPE_B
#define _CTYPE_B    0x00000200L
#endif
#ifndef _CTYPE_C
#define _CTYPE_C    0x00000400L
#endif
#ifndef _CTYPE_D
#define _CTYPE_D    0x00000800L
#endif
#ifndef _CTYPE_G
#define _CTYPE_G    0x00002000L
#endif
#ifndef _CTYPE_I
#define _CTYPE_I    0x00010000L
#endif
#ifndef _CTYPE_L
#define _CTYPE_L    0x00001000L
#endif
#ifndef _CTYPE_P
#define _CTYPE_P    0x00000800L
#endif
#ifndef _CTYPE_Q
#define _CTYPE_Q    0x00020000L
#endif
#ifndef _CTYPE_R
#define _CTYPE_R    0x00040000L
#endif
#ifndef _CTYPE_S
#define _CTYPE_S    0x00000080L
#endif
#ifndef _CTYPE_T
#define _CTYPE_T    0x00400000L
#endif
#ifndef _CTYPE_U
#define _CTYPE_U    0x00004000L
#endif
#ifndef _CTYPE_X
#define _CTYPE_X    0x00000200L
#endif


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
#undef xmalloc
#undef xrealloc

#ifndef _GL_ATTRIBUTE_ALWAYS_INLINE
# if defined __GNUC__ || defined __clang__
#  define _GL_ATTRIBUTE_ALWAYS_INLINE __attribute__ ((__always_inline__))
# else

#  define _GL_ATTRIBUTE_ALWAYS_INLINE
# endif
#endif

#ifndef _GL_INLINE_HEADER_BEGIN
# define _GL_INLINE_HEADER_BEGIN
# define _GL_INLINE_HEADER_END
#endif

#ifdef __APPLE__
# include <runetype.h>
struct __sFILE;
typedef struct __sFILE FILE;
typedef __uint32_t char32_t;

# undef _GL_ATTRIBUTE_DEALLOC
# define _GL_ATTRIBUTE_DEALLOC(f, i)

# undef _GL_ATTRIBUTE_MALLOC
# define _GL_ATTRIBUTE_MALLOC

# undef _GL_ATTRIBUTE_FORMAT
# define _GL_ATTRIBUTE_FORMAT(spec)

# undef _GL_ATTRIBUTE_SPEC_PRINTF_STANDARD
# define _GL_ATTRIBUTE_SPEC_PRINTF_STANDARD
#endif

