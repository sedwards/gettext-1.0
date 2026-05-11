# 1. Find where the object actually is (usually .libs/gettext-gettext.o)
REAL_OBJ=$(find . -name "gettext-gettext.o" | head -n 1)

# 2. Re-compile the stubs right here
gcc -c darwin_linker_stubs.c -o darwin_linker_stubs.o

# 3. Direct Link using the found path
gcc -g -O2 -o gettext "$REAL_OBJ" darwin_linker_stubs.o libgrtsrc.a

# 4. Verify
./gettext --version

