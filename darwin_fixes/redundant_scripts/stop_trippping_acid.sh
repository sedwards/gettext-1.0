#!/bin/bash

echo "--- 1. Fixing Syntax & Missing Macros in config.h ---"
for c in $(find . -name "config.h"); do
    # Remove previous shim attempts
    sed -i '' '/DARWIN_SYNTAX_FIX/,/EOF/d' "$c"
    
    cat >> "$c" <<EOF
/* DARWIN_SYNTAX_FIX */
#include <stddef.h>
#include <stdbool.h>

/* Gnulib Inline Macros (Fixes c-ctype.h and xalloc.h errors) */
#ifndef _GL_INLINE
# define _GL_INLINE static inline
#endif
#ifndef _GL_INLINE_HEADER_BEGIN
# define _GL_INLINE_HEADER_BEGIN
#endif
#ifndef _GL_INLINE_HEADER_END
# define _GL_INLINE_HEADER_END
#endif

/* Missing GNU Constants (Fixes printf_gettext.c errors) */
#ifndef GNULIB_LOCALEDIR
# define GNULIB_LOCALEDIR "/Users/sedwards/gtk/share/locale"
#endif

/* Provide 'error' function declaration (Fixes ngettext.c errors) */
#ifdef __cplusplus
extern "C" {
#endif
  void error(int status, int errnum, const char *format, ...);
  void error_at_line(int status, int errnum, const char *fname, unsigned int lineno, const char *format, ...);
#ifdef __cplusplus
}
#endif

/* Re-apply the basic porting shims */
#ifndef __environ
# include <crt_externs.h>
# define environ (*_NSGetEnviron())
#endif
EOF
done

echo "--- 2. Fixing Makefile Separators (Line 92/4143/7033) ---"
# This flushes all variable assignments left and converts recipe spaces to tabs
find . -name "Makefile" -exec sed -i '' '
    s/^[ ]*\([A-Z0-9_]\{1,\} =\)/\1/g;
    s/^if /# if /g;
    s/^else/# else/g;
    s/^endif/# endif/g;
    s/^    /\t/g;
' {} +

echo "--- 3. Bypassing 'libgnu.la' Dependency Loop ---"
# If a Makefile wants libgnu.la but it's not being built, we point it to the source
find . -name "Makefile" -exec sed -i '' 's|gnulib-lib/libgnu.la|../gnulib-lib/libgnu.la|g' {} +

echo "--- 4. Final Timestamp Freeze ---"
find . -name "*.in" -exec touch -t 202401010000 {} +
touch -t 202401010000 configure aclocal.m4 config.h.in

echo "Ready. Running make -k"
make -k

