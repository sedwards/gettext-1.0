# Run this if you get "undeclared identifier" errors
cat >> ../config.h <<EOF
/* DARWIN BOOTSTRAP SHIMS */
#include <stddef.h>
#include <stdlib.h>
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
#ifndef EXIT_FAILURE
# define EXIT_FAILURE 1
#endif
EOF

