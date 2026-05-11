# Enter the problematic directory
cd gettext-runtime/libasprintf

# Ensure the directory exists
mkdir -p gnulib-lib

# Create a dummy C file with an actual exported symbol (to satisfy ranlib)
echo "int darwin_bootstrap_dummy = 0;" > gnulib-lib/dummy.c
gcc -c gnulib-lib/dummy.c -o gnulib-lib/dummy.o

# Create the archive correctly
ar cru gnulib-lib/libgnu.a gnulib-lib/dummy.o
ranlib gnulib-lib/libgnu.a

# Re-create the .la file just to be sure
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

# Go back to root
cd ../..

