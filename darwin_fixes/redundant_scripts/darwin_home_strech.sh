#!/bin/bash
# darwin_final_crush.sh

ROOT_DIR=$(pwd)
SDK_INC=$(xcrun --show-sdk-path)/usr/include

echo "--- 1. Fixing Macro Recursion in config.h ---"
# We replace the #defines with static inlines to stop the 'expected )' errors
find . -name "config.h" -exec sed -i '' '/DARWIN_MASTER_SHIM/,/EOF/d' {} +
find . -name "config.h" -exec bash -c 'cat >> "$1" <<EOF
/* DARWIN_MASTER_SHIM */
#include <stddef.h>
#include <string.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif
  /* Use inlines instead of macros to prevent redefinition loops */
  static inline int streq(const char *a, const char *b) { return strcmp(a, b) == 0; }
  static inline int memeq(const void *a, const void *b, size_t n) { return memcmp(a, b, n) == 0; }
  
  /* Missing GNU prototypes */
  void *reallocarray(void *ptr, size_t nmemb, size_t size);
#ifdef __cplusplus
}
#endif

#ifndef __environ
# include <crt_externs.h>
# define environ (*_NSGetEnviron())
#endif
EOF' -- {} \;

echo "--- 2. Forcing Generation of Missing GNU Headers ---"
# We physically create the headers that macOS is missing so the build continues
find . -name "gnulib-lib" -type d | while read -r dir; do
    touch "$dir/error.h" "$dir/uchar.h" "$dir/stdbit.h"
    # Fix the ctype.h include_next error
    if [ -f "$dir/ctype.h" ]; then
        sed -i '' "s|#include_next @NEXT_CTYPE_H@|#include <$SDK_INC/ctype.h>|" "$dir/ctype.h"
    fi
done

echo "--- 3. Resolving Makefile Path Mismatches ---"
# Fix the libgrt.a and libgnu.la missing target errors
find . -name "Makefile" -exec sed -i '' 's|gnulib-lib/libgnu.la|libgnu.la|g' {} +
find . -name "Makefile" -exec sed -i '' 's|../gnulib-lib/libgrt.a||g' {} +

echo "--- 4. Final Timestamp Freeze ---"
touch configure aclocal.m4 Makefile.in config.h.in
find . -name "Makefile.in" -exec touch {} +

echo "Ready. Running make -k -j$(sysctl -n hw.ncpu)"
make -k -j$(sysctl -n hw.ncpu)

