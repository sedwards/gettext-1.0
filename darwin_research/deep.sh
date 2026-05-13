
# 1. Fix separators and tabs in every Makefile found
find . -name "Makefile" -exec sed -i '' 's/^[ ]*GL_GENERATE/GL_GENERATE/g' {} +
find . -name "Makefile" -exec sed -i '' 's/^[ ]*GL_COND/GL_COND/g' {} +
find . -name "Makefile" -exec sed -i '' $'s/^    /\t/g' {} +

# 2. Re-apply the Darwin shims to every config.h
for c in $(find . -name "config.h"); do
    if ! grep -q "DARWIN_PORTING_SHIM" "$c"; then
        cat >> "$c" <<EOF
/* DARWIN_PORTING_SHIM */
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
EOF
    fi
done

