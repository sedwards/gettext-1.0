#!/bin/bash

ROOT_DIR=$(pwd)
export PATH="/Users/sedwards/gtk/bin:$PATH"
export M4="/Users/sedwards/gtk/bin/m4"
export ACLOCAL_FLAGS="-I /Users/sedwards/gtk/share/aclocal"
export PKG_CONFIG_PATH="/Users/sedwards/gtk/lib/pkgconfig"
export LD_LIBRARY_PATH="/Users/sedwards/gtk/lib"
export XDG_DATA_DIRS="/Users/sedwards/share"
export GNULIB_SRCDIR="/Users/sedwards/gtk/source/gnulib"

echo "--- 1. Fixing include_next syntax errors ---"
# Find all generated headers and fix the broken include_next lines
# This replaces '# include_next ' with '# include <sys/wait.h>' etc.
find . -name "*.h" -exec sed -i '' 's/# include_next $/# include <sys\/wait.h>/' {} +
find . -name "*.h" -exec sed -i '' 's/#include_next $/#include <sys\/wait.h>/' {} +

echo "--- 2. Injecting missing Gnulib macros (memeq/streq) ---"
# These are used in argmatch.c and others. We put them in config.h.
for c in $(find . -name "config.h"); do
    if ! grep -q "GNULIB_MACRO_SHIMS" "$c"; then
        cat >> "$c" <<EOF

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
done

echo "--- 3. Fixing the _ macro redefinition warning ---"
find . -name "argmatch.c" -exec sed -i '' '/#define _(msgid)/ i\
#undef _
' {} +

echo "--- 4. Resume Build ---"
make

