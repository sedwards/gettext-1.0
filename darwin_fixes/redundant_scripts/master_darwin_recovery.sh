#!/bin/bash
# master_darwin_recovery.sh

ROOT_DIR=$(pwd)
PREFIX="/Users/sedwards/gtk"
SDK_PATH=$(xcrun --show-sdk-path)

# --- 1. Environment ---
export PATH="$PREFIX/bin:$PATH"
export M4="$PREFIX/bin/m4"

echo "--- [1/5] Resetting Makefile Syntax (Tabs & Separators) ---"
# Fixes leading spaces, Automake 'if' logic, and placeholder variables
find . -name "Makefile" -exec sed -i '' '
    s/^[ ]*GL_GENERATE/GL_GENERATE/g;
    s/^[ ]*GL_COND/GL_COND/g;
    s/^[ ]*NEXT_SYS/NEXT_SYS/g;
    s/^if /# if /g;
    s/^else/# else/g;
    s/^endif/# endif/g;
    s/^    /\t/g;
    s/^        /\t/g;
    s/@CFLAG_VISIBILITY@//g;
    s/@[A-Z0-9_]\{1,\}_H@//g;
' {} +

# Ensure targets (lines ending in :) are not indented with Tabs
find . -name "Makefile" -exec sed -i '' 's/^\t\([a-zA-Z0-9._]\{1,\}:\)/\1/' {} +

echo "--- [2/5] Repairing Header Loop & SDK Proxying ---"
# Deletes broken wrappers and proxies directly to macOS SDK
find . -name "gnulib-lib" -type d | while read -r libdir; do
    cd "$libdir"
    mkdir -p sys
    echo "#include <$SDK_PATH/usr/include/stdlib.h>" > stdlib.h
    echo "#include <$SDK_PATH/usr/include/string.h>" > string.h
    echo "#include <$SDK_PATH/usr/include/unistd.h>" > unistd.h
    echo "#include <$SDK_PATH/usr/include/sys/wait.h>" > sys/wait.h
    # Satisfy Makefile dependencies for optional GNU headers
    touch alloca.h byteswap.h stdbit.h fnmatch.h
    cd "$ROOT_DIR"
done

echo "--- [3/5] Injecting config.h Shims (Nuclear Option) ---"
find . -name "config.h" -exec bash -c '
    cfile="$1"
    if ! grep -q "DARWIN_FINAL_SHIM" "$cfile"; then
        cat >> "$cfile" <<EOF
/* DARWIN_FINAL_SHIM */
#include <stddef.h>
#ifdef __cplusplus
extern "C" {
#endif
    void exit(int);
    size_t strlen(const char *);
    int strcmp(const char *, const char *);
    int strncmp(const char *, const char *, size_t);
    int memcmp(const void *, const void *, size_t);
#ifdef __cplusplus
}
#endif
#ifndef EXIT_FAILURE
# define EXIT_FAILURE 1
#endif
#ifndef streq
# define streq(a, b) (strcmp (a, b) == 0)
#endif
#ifndef memeq
# define memeq(a, b, n) (memcmp (a, b, n) == 0)
#endif
#ifndef __environ
# include <crt_externs.h>
# define environ (*_NSGetEnviron())
#endif
static inline void *memrchr(const void *s, int c, size_t n) {
    const unsigned char *cp = (const unsigned char *) s + n;
    while (n--) if (*--cp == (unsigned char) c) return (void *) cp;
    return 0;
}
#define HAVE_MEMRCHR 1
#define HAVE_REALLOCARRAY 1
EOF
    fi
' -- {} \;

echo "--- [4/5] Freezing Timestamps (Bypass Remake Loop) ---"
find . -name "*.am" -exec touch -t 202001010000 {} +
find . -name "*.ac" -exec touch -t 202001010000 {} +
find . -name "*.in" -exec touch -t 202401010000 {} +
touch -t 202401010000 configure aclocal.m4 config.h.in
find . -name "Makefile.in" -exec touch {} +

echo "--- [5/5] Resuming Build ---"
make

