#!/bin/bash
# enforce_config_first.sh (Directory-Aware Local Fix)

TARGET_FILES="getlocalename_l-unsafe.c c32tolower.c c32width.c c32isalnum.c"

echo "=== Enforcing Local config.h Injections at Source Code Level ==="

for name in $TARGET_FILES; do
    # Search the entire tree for every copy of the target C source files
    find . -type f -name "$name" -not -path "*/.git/*" | while read -r target_c; do
        echo "Processing file: $target_c"
        
        # Lift any potential write protection constraints
        chmod 644 "$target_c" 2>/dev/null
        
        # Strip out any older custom hook statements we injected previously
        sed -i '' '/MASTER CONFIG ENFORCER BLOCK/,$d' "$target_c" 2>/dev/null
        
        # Build a temporary file using the relative "config.h" string.
        # This guarantees it binds seamlessly to the sub-folder's own -I paths.
        cat << EOF > source.tmp
/* MASTER CONFIG ENFORCER BLOCK (Forced Early Phase Native Darwin Port) */
#ifndef MASTER_CONFIG_ENFORCED
#define MASTER_CONFIG_ENFORCED
# include "config.h"
#endif

EOF
        # Append the rest of the original C code to the temporary file
        cat "$target_c" >> source.tmp
        mv source.tmp "$target_c"
        
        # Keep the source file locked down so it isn't easily wiped by Automake
        chmod 444 "$target_c"
    done
done

echo "Enforcement loop complete. All source entry points unified."

