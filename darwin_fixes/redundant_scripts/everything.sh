# Define the core directory
BASE_DIR="gettext-runtime/libasprintf"

# 1. Create the dummy object once
echo "int darwin_dummy = 0;" > darwin_dummy.c
gcc -c darwin_dummy.c -o darwin_dummy.o

# 2. Function to plant the dummy library
plant_dummy() {
    mkdir -p "$1"
    ar cru "$1/libgnu.a" darwin_dummy.o
    ranlib "$1/libgnu.a"
    cat > "$1/libgnu.la" <<EOF
# libgnu.la - a libtool library file
old_library='libgnu.a'
installed=no
shouldnotlink=no
EOF
}

# 3. Plant it in every likely spot for libasprintf
plant_dummy "gettext-runtime/gnulib-lib"
plant_dummy "gettext-runtime/libasprintf/gnulib-lib"
plant_dummy "gnulib-lib"

# 4. Cleanup
rm darwin_dummy.c darwin_dummy.o

# Find the specific Makefile and remove ANY reference to libgnu.la 
# so it just links against the system libraries and our config.h shims.
ASPRINTF_MAKE=$(find . -name Makefile | grep "libasprintf/Makefile")
sed -i '' 's/[^ ]*libgnu.la//g' "$ASPRINTF_MAKE"

