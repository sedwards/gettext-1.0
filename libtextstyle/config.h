/* config.h.  Generated from config.h.in by configure.  */
#ifdef __APPLE__
# include "/Users/sedwards/gtk/source/gettext-1.0/darwin_shim.h"
#endif

// ==========================================================================
//   Native Darwin SDK Custom Bootstrapping Block (Forced Early Phase)
//   ========================================================================
#ifdef __APPLE__
/* 1. Force the low-level keyword for static assertions */
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

#endif <stdio.h>

// ==========================================================================
