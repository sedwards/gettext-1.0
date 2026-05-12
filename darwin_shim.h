#ifndef DARWIN_SHIM_H
#define DARWIN_SHIM_H

#include </Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/cdefs.h>
#include </Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/_types.h>

/* Complete core Darwin mask properties */
#define _CTYPE_A    0x00000100L
#define _CTYPE_B    0x00000200L
#define _CTYPE_C    0x00000400L
#define _CTYPE_D    0x00000800L
#define _CTYPE_G    0x00002000L
#define _CTYPE_I    0x00004000L  /* missing Ideogram attribute */
#define _CTYPE_L    0x00004000L
#define _CTYPE_P    0x00010000L
#define _CTYPE_Q    0x00200000L  /* missing Phonogram attribute */
#define _CTYPE_R    0x00020000L
#define _CTYPE_S    0x00040000L
#define _CTYPE_T    0x00400000L  /* missing Special attribute */
#define _CTYPE_U    0x00080000L
#define _CTYPE_X    0x00100000L

#include </Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_va_list.h>
#include </Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_size_t.h>
#include </Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_null.h>

typedef struct __sFILE FILE;

#include </Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/stdio.h>
#include </Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/stdlib.h>
#include </Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/string.h>
#include </Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/ctype.h>
#include </Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/wchar.h>
#include </Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/wctype.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifndef GNULIB_LOCALEDIR
# define GNULIB_LOCALEDIR "/Users/sedwards/gtk/share/locale"
#endif
#ifndef O_BINARY
# define O_BINARY 0
#endif

/* Allocation macro protection block to survive config.h redefinitions */
#ifndef _DARWIN_ALLOC_PROTECT_
#define _DARWIN_ALLOC_PROTECT_
static inline void *xmalloc(size_t n) { void *p = malloc(n); if (!p && n) abort(); return p; }
static inline void *xrealloc(void *p, size_t n) { void *r = realloc(p, n); if (!r && n) abort(); return r; }
#endif
#define XNMALLOC(n, t) ((t *) xmalloc ((n) * sizeof (t)))

void error(int status, int errnum, const char *format, ...);
void xalloc_die(void);
char *last_component(char const *name);
const char *relocate(const char *pathname);

#ifndef __environ
# include <crt_externs.h>
# define environ (*_NSGetEnviron())
#endif

#ifdef __cplusplus
}
#endif

#endif /* DARWIN_SHIM_H */
