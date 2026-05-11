#!/bin/bash
# master_darwin_porting.sh
# Target: macOS/Darwin (No Homebrew)
# Project: GNU gettext 1.0 + gnulib-tool

ROOT_DIR=$(pwd)
PREFIX="/Users/sedwards/gtk"
SDK_PATH=$(xcrun --show-sdk-path)

# --- 1. Environment & Path Setup ---
export PATH="$PREFIX/bin:$PATH"
export M4="$PREFIX/bin/m4"

echo "--- [1/6] Atomic Cleanup of Generated Headers ---"
# We delete then proxy headers to stop infinite loops and missing declarations.
# This part is NOT idempotent (it forces a fresh proxy state).
find . -name "gnulib-lib" -type d | while read -r libdir; do
    cd "$libdir"
    mkdir -p sys
    
    # Create Proxy Headers to macOS SDK
    echo "#include <$SDK_PATH/usr/include/stdlib.h>" > stdlib.h
    echo "#include <$SDK_PATH/usr/include/string.h>" > string.h
    echo "#include <$SDK_PATH/usr/include/unistd.h>" > unistd.h
    echo "#include <$SDK_PATH/usr/include/float.h>" > float.h
    echo "#include <$SDK_PATH/usr/include/sys/wait.h>" > sys/wait.h
    echo "#include <$SDK_PATH/usr/include/sys/resource.h>" > sys/resource.h
    
    # Touch missing headers that aren't in the SDK but needed by Makefile targets
    touch stdbit.h byteswap.h fnmatch.h alloca.h
    cd "$ROOT_DIR"
done

echo "--- [2/6] Global config.h Shims (Idempotent) ---"
# Injects missing GNU extensions and Darwin environment fixes
find . -name "config.h" -exec bash -c '
    cfile="$1"
    if ! grep -q "DARWIN_MASTER_SHIM" "$cfile"; then
        cat >> "$cfile" <<EOF

/* DARWIN_MASTER_SHIM */
#include <stddef.h>
#include <string.h>
#include <stdlib.h>

/* Missing GNU Macros */
#ifndef streq
# define streq(a, b) (strcmp (a, b) == 0)
#endif
#ifndef memeq
# define memeq(a, b, n) (memcmp (a, b, n) == 0)
#endif
#ifndef EXIT_FAILURE
# define EXIT_FAILURE 1
#endif

/* Darwin/macOS Environment */
#ifndef __environ
# include <crt_externs.h>
# define environ (*_NSGetEnviron())
#endif

/* Feature Overrides */
#define HAVE_MEMRCHR 1
#define HAVE_REALLOCARRAY 1
#define HAVE_POSIX_SPAWN 1
#define GNULIB_POSIX_SPAWN 0
#define REPLACE_POSIX_SPAWN 0
#undef HAVE_RANDOM_R
#undef HAVE_STRUCT_RANDOM_DATA

/* Function Shims */
static inline void *memrchr(const void *s, int c, size_t n) {
    const unsigned char *cp = (const unsigned char *) s + n;
    while (n--) if (*--cp == (unsigned char) c) return (void *) cp;
    return 0;
}
EOF
    fi
' -- {} \;

echo "--- [3/6] Makefile Separator & Syntax Repair ---"
# Fixes 'missing separator' and '@PLACEHOLDERS@'
find . -name "Makefile" -exec sed -i '' '
    s/^[ ]*GL_GNULIB/GL_GNULIB/g;
    s/^[ ]*GL_GTTGL/GL_GTTGL/g;
    s/^[ ]*NEXT_SYS/NEXT_SYS/g;
    s/^    /\t/g;
    s/@CFLAG_VISIBILITY@//g;
    s/@[A-Z0-9_]\{1,\}_H@//g;
' {} +

echo "--- [4/6] Fixing Corrupted Automake Logic ---"
# Stops Clang from exploding on empty include_next
find . -name "*.h" -exec sed -i '' 's/# [ ]*include_next[ ]*$/# include <unistd.h>/' {} +

echo "--- [5/6] Building Internal Dependencies First ---"
# Build gnulib-lib specifically to satisfy libgnu.la dependencies
if [ -f "gettext-tools/gnulib-lib/Makefile" ]; then
    (cd gettext-tools/gnulib-lib && make -j$(sysctl -n hw.ncpu))
fi

echo "--- [6/6] Freezing System Timestamps ---"
# Prevent Automake from triggering a remake loop
touch configure aclocal.m4 Makefile.in config.h.in
find . -name "Makefile.in" -exec touch {} +

echo "Master porting complete. Run 'make' to continue."

