# 1. Set source templates back in time
find . -name "*.am" -exec touch -t 202001010000 {} +
find . -name "*.ac" -exec touch -t 202001010000 {} +
find . -name "*.m4" -exec touch -t 202001010000 {} +

# 2. Set generated files to the recent past (but newer than templates)
find . -name "*.in" -exec touch -t 202401010000 {} +
touch -t 202401010000 configure aclocal.m4 config.h.in

# 3. Specifically fix the gnulib-lib/Makefile.in if it's missing
if [ ! -f gnulib-lib/Makefile.in ]; then
    cp gnulib-lib/Makefile.am gnulib-lib/Makefile.in
    touch -t 202401010000 gnulib-lib/Makefile.in
fi

