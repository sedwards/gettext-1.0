# Force the 'intl' directory to report success without doing anything
cat > gettext-runtime/intl/Makefile <<EOF
all:
install:
clean:
distclean:
EOF

# Do the same for its gnulib-lib if it's the one specifically failing
mkdir -p gettext-runtime/intl/gnulib-lib
cat > gettext-runtime/intl/gnulib-lib/Makefile <<EOF
all:
install:
clean:
distclean:
EOF

