#!/bin/bash
# enforce_config_first.sh

ROOT_DIR="/Users/sedwards/gtk/source/gettext-1.0"
MASTER_CONFIG="$ROOT_DIR/config.h"

# The target files we want to hard-inject
TARGET_FILES="getlocalename_l-unsafe.c c32tolower.c c32width.c c32isalnum.c"

echo "=== Enforcing Master config.h Injection at Source Code Level ==="

for name in $TARGET_FILES; do
    # Search the entire tree for every copy of the target C source files
    find . -type f -name "$name" -not -path "*/.git/*" | while read -r target_c; do
        echo "Injecting master config hook into: $target_c"
        
        # Lift any potential write protection constraints
        chmod 644 "$target_c" 2>/dev/null
        
        # Strip out any older custom hook statements we injected previously to avoid duplicates
        sed -i '' '/MASTER CONFIG ENFORCER BLOCK/,$d' "$target_c" 2>/dev/null
        
        # Build a temporary file with the master config.h forced at line 1
        cat << EOF > source.tmp
/* MASTER CONFIG ENFORCER BLOCK (Forced Early Phase Native Darwin Port) */
#ifndef MASTER_CONFIG_ENFORCED
#define MASTER_CONFIG_ENFORCED
# include "$MASTER_CONFIG"
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

