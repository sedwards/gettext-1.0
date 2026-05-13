#!/bin/bash
# apply_absolute_shims.sh

# The exact absolute layout path to your master macro shim
MASTER_SHIM="/Users/sedwards/gtk/source/gettext-1.0/darwin_shim.h"

# Core targets we want to ensure parse using absolute locations
TARGET_NAMES="stdio.h time.h wctype.h uchar.h stdlib.h"

echo "Applying absolute master path mappings to all local proxy files..."

for name in $TARGET_NAMES; do
    find . -type f -name "$name" -not -path "*/.git/*" | while read -r target; do
        echo "Processing target: $target"
        
        # Strip write lock
        chmod +w "$target" 2>/dev/null
        
        # Check if the file already contains an older relative layout block
        if grep -q "include \"darwin_shim.h\"" "$target"; then
            # Replace the relative string directly with the absolute path string
            sed -i '' "s|include \"darwin_shim.h\"|include \"$MASTER_SHIM\"|g" "$target"
        else
            # If no shim tracking header block exists, prepend it explicitly to the top
            cat << EOF > header.tmp
#ifdef __APPLE__
# include "$MASTER_SHIM"
#endif

EOF
            cat "$target" >> header.tmp
            mv header.tmp "$target"
        fi
        
        # Lock file permissions back down to 444
        chmod 444 "$target"
    done
done

echo "Absolute macro alignment complete."

