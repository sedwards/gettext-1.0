#!/bin/bash

# 1. Physical Cleanup: Get rid of all generated headers that are causing brace errors
find . -name "string.h" -delete
find . -name "byteswap.h" -delete
find . -name "spawn.h" -delete

# 2. Re-inject fixes into the NEWLY generated config.h
for c in $(find . -name "config.h"); do
    cat >> "$c" <<EOF
/* DARWIN BOOTSTRAP SHIMS - NO HEADERS TOUCHED */
#include <stddef.h>
#include <sys/types.h>
#include <string.h>

/* Missing GNU prototypes */
static inline void *memrchr(const void *s, int c, size_t n) {
    const unsigned char *cp = (const unsigned char *) s + n;
    while (n--) if (*--cp == (unsigned char) c) return (void *) cp;
    return 0;
}
void *reallocarray(void *ptr, size_t nmemb, size_t size);
char *strnul(const char *s);
int vaszprintf(char **resultp, const char *format, va_list args);
int vsnzprintf(char *str, size_t size, const char *format, va_list args);

/* Darwin/macOS Environment */
#ifndef __environ
# include <crt_externs.h>
# define environ (*_NSGetEnviron())
#endif

/* System Feature Overrides */
#define HAVE_MEMRCHR 1
#define HAVE_STRCHRNUL 1
#define HAVE_REALLOCARRAY 1
#define HAVE_POSIX_SPAWN 1
#define GNULIB_POSIX_SPAWN 0
#define REPLACE_POSIX_SPAWN 0
#undef HAVE_RANDOM_R
#undef HAVE_STRUCT_RANDOM_DATA
EOF
done

# 3. Prevent Makefile from trying to build the missing headers again
find . -name "Makefile" -exec sed -i '' 's/string.h//g' {} +
find . -name "Makefile" -exec sed -i '' 's/byteswap.h//g' {} +

echo "Fixes injected. Running make..."

