# 1. Find the actual source
GETTEXT_C_PATH=$(find . -name "gettext.c" | grep "src/gettext.c")
GETTEXT_DIR=$(dirname "$GETTEXT_C_PATH")
echo "Building in $GETTEXT_DIR"

cd "$GETTEXT_DIR"

# 2. Compile with the correct relative path to the shim
gcc -DLOCALEDIR=\"/Users/sedwards/gtk/share/locale\" \
    -DINSTALLDIR=\"/Users/sedwards/gtk/bin\" \
    -DHAVE_CONFIG_H -I. -I.. -I../intl -I../gnulib-lib \
    -include "../../darwin_shim.h" \
    -g -O2 -c gettext.c -o local_gettext.o

# 3. Compile stubs (copy them here if needed)
cp ../../gettext-tools/src/darwin_linker_stubs.c .
gcc -c darwin_linker_stubs.c -o darwin_linker_stubs.o

# 4. Link using the local support library (libgrt.a or libgrtsrc.a)
# We find any .a file in this tree to help the link
gcc -g -O2 -o gettext local_gettext.o darwin_linker_stubs.o ../gnulib-lib/.libs/libgrt.a

# 5. Test
./gettext --version

