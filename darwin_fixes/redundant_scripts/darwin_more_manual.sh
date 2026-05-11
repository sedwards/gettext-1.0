#!/bin/bash
ROOT_DIR=$(pwd)
SRC_DIR="$ROOT_DIR/gettext-tools/src"

echo "--- 1. Locating objects ---"
GETTEXT_O=$(find . -name "gettext-gettext.o" | head -n 1)
LIBGRT_A=$(find . -name "libgrtsrc.a" | head -n 1)
STUBS_C="$SRC_DIR/darwin_linker_stubs.c"

if [ -z "$GETTEXT_O" ] || [ -z "$LIBGRT_A" ]; then
    echo "Error: Could not find build objects. Run 'make' in gettext-tools/src first."
    exit 1
fi

echo "--- 2. Compiling stubs ---"
gcc -c "$STUBS_C" -o "$SRC_DIR/darwin_linker_stubs.o"

echo "--- 3. Direct Linking (Bypassing libtool) ---"
# We link directly with clang to avoid libtool's path confusion
gcc -g -O2 -o "$SRC_DIR/gettext" \
    "$GETTEXT_O" \
    "$SRC_DIR/darwin_linker_stubs.o" \
    "$LIBGRT_A"

if [ -f "$SRC_DIR/gettext" ]; then
    echo "--- SUCCESS! Binary created at $SRC_DIR/gettext ---"
    "$SRC_DIR/gettext" --version | head -n 1
else
    echo "--- FAILED to link gettext ---"
fi

