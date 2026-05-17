/* config.h.  Generated from config.h.in by configure.  */
#ifdef __APPLE__
# include "/Users/sedwards/gtk/source/gettext-1.0/darwin_shim.h"
#endif

// ==========================================================================
//   Native Darwin SDK Custom Bootstrapping Block (Forced Early Phase)
//   ========================================================================
#ifdef __APPLE__
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

typedef __uint32_t char32_t;

/* Force the low-level keyword for static assertions */
# undef static_assert
# define static_assert _Static_assert

# undef _GL_ATTRIBUTE_DEALLOC
# define _GL_ATTRIBUTE_DEALLOC(f, i)

# undef _GL_ATTRIBUTE_MALLOC
# define _GL_ATTRIBUTE_MALLOC

# undef _GL_ATTRIBUTE_FORMAT
# define _GL_ATTRIBUTE_FORMAT(spec)

# undef _GL_ATTRIBUTE_SPEC_PRINTF_STANDARD
# define _GL_ATTRIBUTE_SPEC_PRINTF_STANDARD

#include <stdio.h>
#endif

// ==========================================================================
