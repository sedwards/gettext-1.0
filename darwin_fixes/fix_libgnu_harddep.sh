# Find all gnulib-lib folders and drop a dummy .la file in them
find . -type d -name "gnulib-lib" | while read -r dir; do
    cat > "$dir/libgnu.la" <<EOF
# libgnu.la - a libtool library file
dlname=''
library_names=''
old_library=''
current=0
age=0
revision=0
installed=no
shouldnotlink=no
EOF
done

