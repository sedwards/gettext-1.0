#!/bin/bash
# sync_and_link_unicode.sh (Bash 3.2 Global Multi-Header Version)

ROOT_DIR="/Users/sedwards/gtk/source/gettext-1.0"

# Explicit listing of the entire GNU libunistring / Gnulib unicode family
UNICODE_HEADERS="unicase.h unitypes.h unictype.h uninorm.h uniwidth.h uniname.h unistr.h unigbrk.h uniwbrk.h unilbrk.h uniconv.h unistdio.h"

echo "=== Phase 1: Dynamic Discovery of Unicode Anchor Sources ==="

# Initialize dynamic environment variables to track found absolute file records
for header in $UNICODE_HEADERS; do
    # Scrub out dots/dashes to construct safe variable handles for older Bash 3.2 engines
    var_name="src_$(echo "$header" | sed 's/[.-]/_/g')"
    
    # Locate a development library copy while ignoring test contexts
    FOUND_PATH=$(find . -type f -name "$header" \
        -not -path "*/install-tests/*" \
        -not -path "*/examples/*" \
        -not -path "*/gnulib-tests/*" \
        -not -path "*/tests/*" | head -n 1)

    if [ ! -z "$FOUND_PATH" ]; then
        clean_rel=$(echo "$FOUND_PATH" | sed 's|^\./||')
        ABS_PATH="$ROOT_DIR/$clean_rel"
        
        # Globally export the verified path using variable indirection
        eval "$var_name=\"\$ABS_PATH\""
        echo "  -> Found and anchored $header at: $ABS_PATH"
        chmod 644 "$ABS_PATH" 2>/dev/null
    else
        echo "  -> Note: No baseline reference discovered for $header (Skipping)"
    fi
done

echo "=== Phase 2: Matrix Linking Across All Active Compilation Folders ==="

# Scan for every directory containing a target Makefile
find . -type f -name "Makefile" | while read -r makefile; do
    target_dir=$(dirname "$makefile")
    
    # Isolate compilation execution subdirectories
    if [ "$target_dir" != "." ]; then
        echo "Synchronizing environment inside workspace: $target_dir"
        
        for header in $UNICODE_HEADERS; do
            var_name="src_$(echo "$header" | sed 's/[.-]/_/g')"
            
            # Extract the stored absolute source file location string dynamically
            SRC_FILE=$(eval echo "\$$var_name")
            
            if [ ! -z "$SRC_FILE" ]; then
                clean_target_dir=$(echo "$target_dir" | sed 's|^\./||')
                ABS_TARGET_FILE="$ROOT_DIR/$clean_target_dir/$header"
                
                # Prevent symlinking a file over itself if it is the source origin
                if [ "$SRC_FILE" != "$ABS_TARGET_FILE" ]; then
                    chmod +w "$ABS_TARGET_FILE" 2>/dev/null
                    rm -f "$ABS_TARGET_FILE"
                    
                    # Create the cross-directory absolute target symbolic link
                    ln -s "$SRC_FILE" "$ABS_TARGET_FILE"
                fi
            fi
        done
    fi
done

echo "=== System Sync Complete: Blanket Unicode linkages deployed globally ==="

