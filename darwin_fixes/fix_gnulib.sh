# Move to the problematic subdirectory
cd gettext-runtime/libasprintf

# Create the directory if it was deleted/nuked
mkdir -p gnulib-lib

# Create a dummy .la file (Libtool instruction file)
cat > gnulib-lib/libgnu.la <<EOF
# libgnu.la - a libtool library file
dlname=''
library_names=''
old_library='libgnu.a'
inherited_linker_flags=''
dependency_libs=''
current=0
age=0
revision=0
installed=no
shouldnotlink=no
EOF

# Create a dummy .a file (The actual archive)
# This is a valid, empty static library that Darwin's linker will accept
ar cru gnulib-lib/libgnu.a
ranlib gnulib-lib/libgnu.a

# Return to the root
cd ../..

