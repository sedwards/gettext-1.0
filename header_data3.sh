#!/bin/bash

echo "Searching for proxy macro files containing dot syntax..."

# Find all .h files containing the invalid proxy pattern
find . -type f -name "*.h" -not -path "*/.git/*" | while read -r file; do
    if grep -q "#ifndef _DARWIN_PROXY_" "$file"; then
        echo "Fixing macro guards in: $file"
        
        # Remove read-only lock if it exists
        chmod +w "$file" 2>/dev/null
        
        # macOS sed requires an empty string "" argument for in-place edits without backup
        sed -i "" 's/\(#ifndef _DARWIN_PROXY_[a-zA-Z0-9_-]*\)\.\(h\)/\1_\2/g' "$file"
        sed -i "" 's/\(#define _DARWIN_PROXY_[a-zA-Z0-9_-]*\)\.\(h\)/\1_\2/g' "$file"
        sed -i "" 's/\(#endif \/\* _DARWIN_PROXY_[a-zA-Z0-9_-]*\)\.\(h\)/\1_\2/g' "$file"
        
        # Re-lock file to preserve it from being overridden by Automake targets
        chmod 444 "$file"
    fi
done

echo "Macro guard sanitation complete."

