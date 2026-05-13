#!/bin/bash

# Define the target block to inject at the very top of each file
SHIM_BLOCK=$(cat << 'EOF'
#ifdef __APPLE__
# include "darwin_shim.h"
#endif
EOF
)

# Explicit list of targets found in your search
targets=(
    "./gettext-runtime/intl/gnulib-lib/stdio.h"
    "./gettext-runtime/libasprintf/gnulib-lib/stdio.h"
    "./gnulib-lib/stdio.h"
)

echo "Starting deployment of native macOS stdio.h patches..."

for target in "${targets[@]}"; do
    if [ -f "$target" ]; then
        echo "Injecting shim into: $target"
        
        # Unlock the file if it is currently read-only
        chmod +w "$target" 2>/dev/null
        
        # Create a modified temporary file with the block prepended
        (echo "$SHIM_BLOCK"; echo ""; cat "$target") > stdio.h.tmp
        
        # Overwrite the original file with the patched version
        mv stdio.h.tmp "$target"
        
        # Lock the file back down to protect it from Automake overwrites
        chmod 444 "$target"
    else
        echo "Skipping target (File not found): $target"
    fi
done

echo "Injection complete. Try re-running your compilation."

