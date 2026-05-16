#ifndef _GL_UCHAR_H
#define _GL_UCHAR_H

#ifdef __APPLE__
# include "/Users/sedwards/gtk/source/gettext-1.0/darwin_shim.h"
# include <stdint.h>
# include <stddef.h>

/* Define the fundamental C11 types missing from Apple SDK */
# ifndef __cplusplus
#  ifndef __char16_t_defined
    typedef uint_least16_t char16_t;
#   define __char16_t_defined 1
#  endif
#  ifndef __char32_t_defined
    typedef uint_least32_t char32_t;
#   define __char32_t_defined 1
#  endif
# endif

/* Define custom fallback signatures for the missing uchar.h symbols */
typedef unsigned int char32_t;

int c32width (char32_t wc);
int c32iscntrl (char32_t wc);
size_t mbrtoc32 (char32_t *pc32, const char *s, size_t n, mbstate_t *ps);

static inline void mbszero (mbstate_t *ps) {
    memset (ps, 0, sizeof (mbstate_t));
}

#endif /* __APPLE__ */

#endif /* _GL_UCHAR_H */
