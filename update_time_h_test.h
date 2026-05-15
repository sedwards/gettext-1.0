#!/bin/bash

# Define native macOS wrapper payload for time.h
cat << 'EOF' > time.h.tmp
#ifndef _GL_TIME_H
#define _GL_TIME_H

#ifdef __APPLE__
# include <config.h>
# include_next <time.h>
#endif

#endif /* _GL_TIME_H */
EOF

# Find all auto-generated time.h files (ignoring directories like sys/)
echo "Scanning tree and applying native macOS <time.h> redirects..."
find . -name "time.h" -not -path "*/.git/*" | while read -r target; do
    echo "Rewriting shim: $target"
    chmod +w "$target" 2>/dev/null
    cp time.h.tmp "$target"
    chmod 444 "$target"
done

rm -f time.h.tmp
echo "Redirect complete."

