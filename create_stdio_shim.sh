#!/bin/bash
# update_stdio_shim_test.sh

# Explicitly use the absolute path to your master shim
SHIM_BLOCK=$(cat << 'EOF'
#ifdef __APPLE__
# include "/Users/sedwards/gtk/source/gettext-1.0/darwin_shim.h"
#endif
EOF
)

# The exact targets found in your directory tree search
targets=(
    "./gettext-runtime/intl/gnulib-lib/stdio.h"
    "./gettext-runtime/libasprintf/gnulib-lib/stdio.h"
    "./gnulib-lib/stdio.h"
)

echo "Deploying absolute path corrections to local stdio.h proxy stubs..."

for target in "${targets[@]}"; do
    if [ -f "$target" ]; then
        echo "Updating file: $target"
        
        # Lift any write protection
        chmod +w "$target" 2>/dev/null
        
        # Prepend the absolute path block to the top of the file
        (echo "$SHIM_BLOCK"; echo ""; cat "$target") > stdio.h.tmp
        
        # Overwrite the original file
        mv stdio.h.tmp "$target"
        
        # Re-lock the file to preserve it during make
        chmod 444 "$target"
    else
        echo "Target missing, skipping: $target"
    fi
done

echo "Deployment complete."

