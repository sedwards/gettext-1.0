# Find every gnulib-lib directory and force its Makefile to be a "do-nothing" dummy
find . -type d -name "gnulib-lib" | while read -r dir; do
    echo "Nuking $dir/Makefile"
    cat > "$dir/Makefile" <<EOF
all:
install:
clean:
distclean:
EOF
done

