cd gettext-tools/src

# 1. Re-compile the stubs in this folder
gcc -c darwin_linker_stubs.c -o darwin_linker_stubs.o

# 2. Run the linker using local paths
/bin/sh ../libtool --tag=CC --mode=link gcc \
  -DINSTALLDIR="/Users/sedwards/gtk/bin" \
  -include "$(pwd)/../../darwin_shim.h" -g -O2 \
  -o gettext \
  gettext-gettext.o \
  darwin_linker_stubs.o \
  libgrtsrc.a

# 3. Verify it worked
./gettext --version

