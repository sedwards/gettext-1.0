 #!/bin/bash

echo "1. Physical Reset: Restoring string.h files..."
# We use a more aggressive approach: delete the Gnulib string.h 
# and let the Makefile regenerate a clean one, or we bypass it.
find . -name "string.h" -delete

echo "2. Injecting Darwin fixes into config.h (The safe zone)..."
for c in $(find . -name "config.h"); do
    # Remove any previous shim blocks to avoid duplicates
    sed -i '' '/DARWIN_BOOTSTRAP_SHIMS/,/endif/d' "$c"
    
    cat >> "$c" <<EOF
/* DARWIN_BOOTSTRAP_SHIMS */
#include <stddef.h>
#include <string.h>

/* Implementation of missing memrchr */
#ifndef _GL_MEMRCHR_DEFINED
#define _GL_MEMRCHR_DEFINED
static inline void *memrchr(const void *s, int c, size_t n) {
    const unsigned char *cp = (const unsigned char *) s + n;
    while (n--) if (*--cp == (unsigned char) c) return (void *) cp;
    return 0;
}
#endif

/* Global Darwin Compatibility */
#define HAVE_MEMRCHR 1
#define HAVE_STRCHRNUL 1
#define HAVE_REALLOCARRAY 1
#define HAVE_POSIX_SPAWN 1
#define GNULIB_POSIX_SPAWN 0
#define REPLACE_POSIX_SPAWN 0
#undef HAVE_RANDOM_R
#undef HAVE_STRUCT_RANDOM_DATA

/* macOS Environ */
#ifndef __environ
# include <crt_externs.h>
# define environ (*_NSGetEnviron())
#endif
EOF
done

echo "3. Bypassing Gnulib's string handling..."
# This tells the Makefiles NOT to use the replacement string.h
find . -name "Makefile" -exec sed -i '' 's/gl_LIBOBJS += memrchr.lo//g' {} +
find . -name "Makefile" -exec sed -i '' 's/string.h//g' {} +

echo "4. Mop up objects..."
find . -name "*.o" -delete
find . -type d -name "gnulib-lib" -exec touch "{}/stdbit.h" \;

echo "Reset complete. Please run 'make'."

