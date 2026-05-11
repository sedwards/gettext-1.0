# 1. Enter the sub-package
cd gettext-runtime/libasprintf

# 2. Ensure the directory exists
mkdir -p gnulib-lib

# 3. Create a tiny dummy C file and compile it
echo "int dummy_symbol;" > gnulib-lib/dummy.c
gcc -c gnulib-lib/dummy.c -o gnulib-lib/dummy.o

# 4. Create the static archive (.a) using the dummy object
ar cru gnulib-lib/libgnu.a gnulib-lib/dummy.o
ranlib gnulib-lib/dummy.a

# 5. Create the libtool descriptor (.la)
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

# 6. Return to root
cd ../..

