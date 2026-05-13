#ifdef __APPLE__
# include "/Users/sedwards/gtk/source/gettext-1.0/darwin_shim.h"
#endif

#ifdef __APPLE__
# include "/Users/sedwards/gtk/source/gettext-1.0/darwin_shim.h"
#endif

#ifdef __APPLE__
# include "/Users/sedwards/gtk/source/gettext-1.0/darwin_shim.h"
#endif

#ifndef _GL_WCTYPE_H
#define _GL_WCTYPE_H

/* Force the universal shim to apply context first */
#ifdef __APPLE__
# include "/Users/sedwards/gtk/source/gettext-1.0/darwin_shim.h"
#endif

/* Allow Gnulib to include the actual macOS system header next */
#define _GL_ALREADY_INCLUDING_WCTYPE_H
#include_next <wctype.h>
#undef _GL_ALREADY_INCLUDING_WCTYPE_H

#endif /* _GL_WCTYPE_H */
