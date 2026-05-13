#!/bin/bash
# header_fixes.sh

HEADERS="fcntl.h sys/types.h sys/stat.h sys/select.h unistd.h stdlib.h string.h wchar.h wctype.h float.h sys/resource.h"

for h in $HEADERS; do
    echo "Converting $h to SDK proxy..."
    find . -path "*/$h" | while read -r target; do
        # Unlock and delete
        chmod 644 "$target" 2>/dev/null
        rm -f "$target"
        
        # Ensure directory exists
        mkdir -p "$(dirname "$target")"
        
        # Create the Proxy Header
        cat > "$target" <<EOF
/* Darwin SDK Proxy Header */
#ifndef _DARWIN_PROXY_H
#define _DARWIN_PROXY_H

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif
    void *malloc(size_t);
    void *realloc(void *, size_t);
    void free(void *);
    void abort(void);
    void exit(int);
#ifdef __cplusplus
}
#endif

/* Include actual system headers */
#include <sys/types.h>
#include <time.h>
#include <sys/time.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <wchar.h>
#include <wctype.h>
#include <float.h>
#include <sys/resource.h>

#endif
EOF

        # Lock the file
        chmod 444 "$target"
    done
done

echo "Stripping Makefile placeholders..."
find . -name "Makefile" -exec sed -i '' 's/@[A-Z0-9_]\{1,\}_H@//g' {} +

