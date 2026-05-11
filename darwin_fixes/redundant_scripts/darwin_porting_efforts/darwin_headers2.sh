#!/bin/bash
# Run this inside gettext-tools/gnulib-lib/

echo "Cleaning up unexpanded placeholders..."
# Strips any remaining @STUFF_H@ from the Makefile
sed -i '' 's/@[A-Z0-9_]\{1,\}_H@//g' Makefile

echo "Fixing corrupted header logic..."
# Fixes the 'expected FILENAME' error for sys/wait.h and unistd.h
[ -f sys/wait.h ] && sed -i '' 's/# [ ]*include_next[ ]*$/# include <sys\/wait.h>/' sys/wait.h
[ -f unistd.h ] && sed -i '' 's/# [ ]*include_next[ ]*$/# include <unistd.h>/' unistd.h

echo "Applying Darwin shims to current directory..."
# Ensuring memeq/streq are available here
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

echo "Resuming build in gnulib-lib..."
make

