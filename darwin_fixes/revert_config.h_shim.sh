# Find all config.h files and strip out ALL previous memrchr shim attempts
find . -name "config.h" -exec sed -i '' '/static inline void \*memrchr/,/}/d' {} +
find . -name "config.h" -exec sed -i '' '/DARWIN_PORTING_SHIM/d' {} +

# Inject a CLEAN, Guarded shim into every config.h
for c in $(find . -name "config.h"); do
    cat >> "$c" <<EOF
/* DARWIN_PORTING_SHIM */
#ifndef _GL_MEMRCHR_SHIM_GUARD
#define _GL_MEMRCHR_SHIM_GUARD
#include <stddef.h>
#include <string.h>
#ifndef __environ
# include <crt_externs.h>
# define environ (*_NSGetEnviron())
#endif
static inline void *memrchr(const void *s, int c, size_t n) {
    const unsigned char *cp = (const unsigned char *) s + n;
    while (n--) if (*--cp == (unsigned char) c) return (void *) cp;
    return 0;
}
#endif
EOF
done

