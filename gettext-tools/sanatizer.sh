#!/bin/bash

# 1. ATOMIC CLEANUP OF STRING.H
echo "Sanitizing all string.h files..."
for f in $(find . -name "string.h"); do
    # Create a clean version without ANY previous patches/guards/shims
    grep -v "_GL_MEMRCHR_DEFINED" "$f" | \
    grep -v "static inline void \*memrchr" | \
    grep -v "const unsigned char \*cp =" | \
    grep -v "while (n--) if (\*--cp" | \
    grep -v "return (void \*) cp;" | \
    grep -v "return 0;" > "$f.clean"

    # Now create the new file: Shim first, then the rest of the clean file
    cat > "$f" <<EOF
#include <stddef.h>
#ifndef _GL_MEMRCHR_DEFINED
#define _GL_MEMRCHR_DEFINED
static inline void *memrchr(const void *s, int c, size_t n) {
    const unsigned char *cp = (const unsigned char *) s + n;
    while (n--) if (*--cp == (unsigned char) c) return (void *) cp;
    return 0;
}
#endif
EOF
    cat "$f.clean" >> "$f"
    rm "$f.clean"
done

# 2. FIX RANDOM_DATA IN CONFIG.H
# The "incomplete definition of type 'struct random_data'" happens because 
# Gnulib thinks you have it but you don't.
echo "Patching config.h to solve random_r and spawn..."
for c in $(find . -name "config.h"); do
    # Clean out any previous Darwin shims to prevent duplicates
    sed -i '' '/DARWIN BOOTSTRAP SHIMS/,/endif/d' "$c"
    
    cat >> "$c" <<EOF
/* DARWIN BOOTSTRAP SHIMS */
#define HAVE_REALLOCARRAY 1
#define HAVE_STRCHRNUL 1
#define HAVE_SECURE_GETENV 1
#define HAVE_SETLOCALE_NULL 1
#define HAVE_MEMSET_EXPLICIT 1
#define HAVE_GETRANDOM 1
#define HAVE_PIPE2 1
#define HAVE_MEMRCHR 1
#define HAVE_MBSSTR 1
#define HAVE_MBSLEN 1
#define HAVE_MBSZERO 1
#define HAVE_VASZPRINTF 1
#define HAVE_VSNZPRINTF 1

/* Force Gnulib to use its own random.c instead of system */
#undef HAVE_RANDOM_R
#undef HAVE_STRUCT_RANDOM_DATA
#undef HAVE_RANDOM_H

/* Use MacOS native spawn */
#define HAVE_POSIX_SPAWN 1
#define GNULIB_POSIX_SPAWN 0

/* macOS Environ */
#ifndef __environ
# include <crt_externs.h>
# define environ (*_NSGetEnviron())
#endif
EOF
done

# 3. Final cleanup of objects
find . -name "*.o" -delete
touch gnulib-lib/stdbit.h

echo "Sanitization complete. Please run 'make'."

