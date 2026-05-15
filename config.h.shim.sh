#!/bin/bash
# config.h.shim.sh

#!/bin/bash
# config.h.shim.sh

SHIM_PATH="/Users/sedwards/gtk/source/gettext-1.0/darwin_shim.h"

echo "=== Injecting Absolute Master Shim Hook into config.h.in Templates ==="

# Locate all config.h.in template files in your repository
find . -name "config.h.in" -not -path "*/.git/*" | while read -r template; do
    echo "Processing template: $template"
    
    # Lift read-only restrictions
    chmod 644 "$template" 2>/dev/null
    
    # Clean-up Step: Delete ONLY lines that mention darwin_shim.h to prevent file truncation
    if [ -f "$template" ]; then
        sed -i '' '/darwin_shim\.h/d' "$template" 2>/dev/null
        sed -i '' '/DARWIN_SHIM_H/d' "$template" 2>/dev/null
    fi
    
    # Prepend the absolute include hook to the absolute top of the template file without any comments
    cat << EOF > template.tmp
#ifdef __APPLE__
# include "$SHIM_PATH"
#endif

EOF
    # Safely append the rest of the pristine config.h.in contents
    cat "$template" >> template.tmp
    mv template.tmp "$template"
    
    # Secure permissions back down
    chmod 444 "$template"
done

echo "Template updates complete. Regenerating concrete config.h child layers..."

# Force AutoConf to safely distribute the completed config.h to all child directories
if [ -f "./config.status" ]; then
    ./config.status
else
    echo "WARNING: ./config.status not found. Please run ./configure first to apply."
fi


