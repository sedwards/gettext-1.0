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

#endif /* __APPLE__ */

#endif /* _GL_UCHAR_H */
