# Ensure the directory exists
mkdir -p libasprintf/gnulib-lib

# Create a minimal valid libtool library file
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
EOF

