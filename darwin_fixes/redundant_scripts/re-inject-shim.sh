for c in $(find . -name "config.h"); do
    if ! grep -q "DARWIN_MASTER_SHIM" "$c"; then
        cat >> "$c" <<EOF
/* DARWIN_MASTER_SHIM */
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <fcntl.h>
#ifndef __environ
# include <crt_externs.h>
# define environ (*_NSGetEnviron())
#endif
static inline void *memrchr(const void *s, int c, size_t n) {
    const unsigned char *cp = (const unsigned char *) s + n;
    while (n--) if (*--cp == (unsigned char) c) return (void *) cp;
    return 0;
}
static inline void *xmalloc(size_t n) { void *p = malloc(n); if (!p && n) abort(); return p; }
#define XNMALLOC(n, t) ((t *) xmalloc ((n) * sizeof (t)))
EOF
    fi
done

