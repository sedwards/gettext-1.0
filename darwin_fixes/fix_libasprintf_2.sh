# Find the actual path and fix it
ASPRINTF_MAKE=$(find . -name Makefile | grep "libasprintf/Makefile")
if [ -f "$ASPRINTF_MAKE" ]; then
    sed -i '' 's/gnulib-lib\/libgnu.la//g' "$ASPRINTF_MAKE"
    echo "Fixed $ASPRINTF_MAKE"
else
    echo "Makefile not found in libasprintf, checking subdirectories..."
fi

# 1. Create the directory
mkdir -p gettext-runtime/libasprintf/gnulib-lib

# 2. Create the dummy library file
cat > gettext-runtime/libasprintf/gnulib-lib/libgnu.la <<EOF
# libgnu.la - a libtool library file
dlname=''
library_names=''
old_library=''
inherited_linker_flags=''
dependency_libs=''
current=0
age=0
revision=0
installed=no
shouldnotlink=no
EOF

# 3. Create a dummy archive for the linker
ar cru gettext-runtime/libasprintf/gnulib-lib/libgnu.a
ranlib gettext-runtime/libasprintf/gnulib-lib/libgnu.a

