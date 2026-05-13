#!/bin/bash

#We must incude this before our other shims are brought in to play

# Locate all config.h.in template files in your repository
find . -name "config.h.in" -not -path "*/.git/*" | while read -r template; do
    echo "Positioning master shim at top of: $template"
    chmod +w "$template" 2>/dev/null
    
    # 1. Strip any previous bottom-loaded custom blocks to avoid duplicates
    sed -i '' '/Native Darwin SDK Custom Bootstrapping Block/,$d' "$template" 2>/dev/null
    
    # 2. Prepend the loader block to the absolute top of the template file
    cat << 'EOF' > template.tmp
/* ==========================================================================
   Native Darwin SDK Custom Bootstrapping Block (Forced Early Phase)
   ========================================================================== */
#ifdef __APPLE__
# include "/Users/sedwards/gtk/source/gettext-1.0/darwin_shim.h"
#endif

EOF
    cat "$template" >> template.tmp
    mv template.tmp "$template"
    chmod 444 "$template"
done

