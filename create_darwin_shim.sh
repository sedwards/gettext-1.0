#!/bin/bash
# create_darwin_shim.sh

SDK_PATH=$(xcrun --show-sdk-path)

# Define the complete consolidated payload for the master darwin_shim.h
cat << EOF > darwin_shim.h.tmp
#ifndef DARWIN_SHIM_H
#define DARWIN_SHIM_H

/* Force standard system features and architecture layouts */
#include <sys/cdefs.h>
#include <_types.h>

/* Complete core Darwin mask properties to insulate from header loop bugs */
#define _CTYPE_A    0x00000100L
#define _CTYPE_B    0x00000200L
#define _CTYPE_C    0x00000400L
#define _CTYPE_D    0x00000800L
#define _CTYPE_G    0x00002000L
#define _CTYPE_I    0x00010000L
#define _CTYPE_L    0x00001000L
#define _CTYPE_P    0x00000800L
#define _CTYPE_Q    0x00020000L
#define _CTYPE_R    0x00040000L
#define _CTYPE_S    0x00000080L
#define _CTYPE_T    0x00400000L
#define _CTYPE_U    0x00004000L
#define _CTYPE_X    0x00000200L

#define _DARWIN_CTYPE_A _CTYPE_A
#define _DARWIN_CTYPE_B _CTYPE_B

/* Core prerequisite scalar types */
#include <sys/_types/_va_list.h>
#include <sys/_types/_size_t.h>
#include <sys/_types/_null.h>

/* Primitives for Modern macOS SDK compilation stability */
#ifndef __cplusplus
# include <stdbool.h>
#endif

/* Native Apple SDK Deep-Linking Fallbacks for Locales */
#include "$SDK_PATH/usr/include/xlocale.h"
#include "$SDK_PATH/usr/include/locale.h"

/* Ensure POSIX context blocks map cleanly independently of SDK variations */
#ifndef LC_GLOBAL_LOCALE
# define LC_GLOBAL_LOCALE ((locale_t)-1)
#endif

/* Fix: Forward declare the complete structure bounds to avoid incomplete enum fields */
enum storage {
    STORAGE_THREAD,
    STORAGE_GLOBAL
};

/* Global expansion fallbacks for un-substituted Gnulib parameters */
#ifndef _GL_ATTRIBUTE_NODISCARD
# define _GL_ATTRIBUTE_NODISCARD
#endif
#ifndef _GL_ATTRIBUTE_DEPRECATED
# define _GL_ATTRIBUTE_DEPRECATED
#endif
#ifndef _GL_ATTRIBUTE_FALLTHROUGH
# define _GL_ATTRIBUTE_FALLTHROUGH ((void)0)
#endif
#ifndef _GL_ATTRIBUTE_DEALLOC
# define _GL_ATTRIBUTE_DEALLOC(f, g)
#endif
#ifndef _GL_ATTRIBUTE_FORMAT
# define _GL_ATTRIBUTE_FORMAT(spec)
#endif
#ifndef _GL_ATTRIBUTE_SPEC_PRINTF_STANDARD
# define _GL_ATTRIBUTE_SPEC_PRINTF_STANDARD 1
#endif

#ifndef _GL_CMP
# define _GL_CMP(n1, n2) (((n1) > (n2)) - ((n1) < (n2)))
#endif

#ifndef LIBGETTEXTSRC_DLL_VARIABLE
# define LIBGETTEXTSRC_DLL_VARIABLE
#endif
#ifndef LIBGETTEXTLIB_DLL_VARIABLE
# define LIBGETTEXTLIB_DLL_VARIABLE
#endif

/* ARM64 Circuit Breaker: FPU Control Words do not exist on modern Mac Silicon hardware */
#ifdef __arm64__
# undef HAVE_FPUCW_H
# define HAVE_FPUCW_H 0
#endif

/* Complete circuit breaker for macOS FILE dependencies in _wchar.h */
#ifndef __sFILE_defined
struct __sFILE;
typedef struct __sFILE FILE;
#define __sFILE_defined 1
#define _FILE_DEFINED 1
#define _FILE_DEFINED_
#endif

/* Native macOS SDK Base Layer Inclusions - Forced to bypass local stubs */
#include "$SDK_PATH/usr/include/stdio.h"
#include "$SDK_PATH/usr/include/stdlib.h"
#include "$SDK_PATH/usr/include/string.h"
#include "$SDK_PATH/usr/include/ctype.h"
#include "$SDK_PATH/usr/include/wchar.h"
#include "$SDK_PATH/usr/include/wctype.h"

/* Robust standard C fallback definition for static_assert */
#undef static_assert
#define _GL_PASTE(a, b) a ## b
#define _GL_MANGLE(a, b) _GL_PASTE(a, b)
#define static_assert(expr, ...) \
   typedef int _GL_MANGLE(_compile_time_assert_, __LINE__)[(expr) ? 1 : -1] __attribute__((unused))

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
# ifndef xmalloc
static inline void *xmalloc(size_t n) { void *p = malloc(n); if (!p && n) abort(); return p; }
# endif
# ifndef xrealloc
static inline void *xrealloc(void *p, size_t n) { void *r = realloc(p, n); if (!r && n) abort(); return r; }
# endif
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
EOF

targets=(
    "./darwin_shim.h"
    "./gettext-tools/src/darwin_shim.h"
)

echo "Deploying absolute consolidated darwin_shim.h master records..."
for target in "${targets[@]}"; do
    target_dir=$(dirname "$target")
    if [ -d "$target_dir" ]; then
        echo "Writing macro master to: $target"
        chmod +w "$target" 2>/dev/null
        cp darwin_shim.h.tmp "$target"
        chmod 444 "$target"
    else
        echo "Skipping destination folder: $target_dir"
    fi
done

rm -f darwin_shim.h.tmp
echo "All shims consolidated and active."

