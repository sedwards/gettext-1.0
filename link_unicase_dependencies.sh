#!/bin/bash
# link_unicase_dependencies.sh

ROOT_DIR="/Users/sedwards/gtk/source/gettext-1.0"
SRC_HEADER="$ROOT_DIR/gnulib-lib/unicase.h"

# Find every child folder tracking local library implementations
find . -type d -name "gnulib-lib" -o -name "intl" | while read -r target_dir; do
    # Skip the actual root folder source folder
    if [ "$target_dir" != "./gnulib-lib" ]; then
        echo "Linking unicase.h inside target scope: $target_dir"
        rm -f "$target_dir/unicase.h"
        ln -s "$SRC_HEADER" "$target_dir/unicase.h"
    fi
done

echo "Local path references updated."

