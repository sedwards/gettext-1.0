# 1. Create the directory if it's missing
mkdir -p libasprintf/gnulib-lib

# 2. Create a dummy libgnu.la so the linker doesn't stop
# (libtool just needs the .la text file to exist to proceed)
cat > libasprintf/gnulib-lib/libgnu.la <<EOF
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
libdir=''
EOF

# Remove the specific requirement for libgnu.la from the libasprintf Makefile
find libasprintf -name "Makefile" -exec sed -i '' 's/gnulib-lib\/libgnu.la//g' {} +

