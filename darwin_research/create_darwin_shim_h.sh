cat > /Users/sedwards/gtk/source/gettext-1.0/darwin_shim.h <<EOF
#ifndef DARWIN_SHIM_H
#define DARWIN_SHIM_H

/* 1. Explicitly pull Apple SDK root headers in absolute execution order */
#include </Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/cdefs.h>
#include </Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/_types.h>

/* 2. Explicitly bind the low-level character map masks for Darwin */
#define _CTYPE_A    0x00000100L     /* Alpha */
#define _CTYPE_B    0x00000200L     /* Blank */
#define _CTYPE_C    0x00000400L     /* Control */
#define _CTYPE_D    0x00000800L     /* Digit */
#define _CTYPE_G    0x00002000L     /* Graph */
#define _CTYPE_L    0x00004000L     /* Lower */
#define _CTYPE_P    0x00010000L     /* Punct */
#define _CTYPE_R    0x00020000L     /* Print */
#define _CTYPE_S    0x00040000L     /* Space */
#define _CTYPE_U    0x00080000L     /* Upper */
#define _CTYPE_X    0x00100000L     /* Xdigit */

/* 3. Pull foundational types before wchar engines evaluate them */
#include </Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_va_list.h>
#include </Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_size_t.h>
#include </Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_null.h>

/* 4. Provide forward structure to guarantee FILE type recognition */
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

/* Allocation wrappers */
static inline void *xmalloc(size_t n) { void *p = malloc(n); if (!p && n) abort(); return p; }
static inline void *xrealloc(void *p, size_t n) { void *r = realloc(p, n); if (!r && n) abort(); return r; }
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
EOF

