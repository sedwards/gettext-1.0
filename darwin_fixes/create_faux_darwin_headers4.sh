if [ -f config.h ]; then
    grep -q "GNULIB_MACRO_SHIMS" config.h || cat >> config.h <<EOF
/* GNULIB_MACRO_SHIMS */
#include <string.h>
#ifndef streq
# define streq(a, b) (strcmp (a, b) == 0)
#endif
#ifndef memeq
# define memeq(a, b, n) (memcmp (a, b, n) == 0)
#endif
EOF
fi

