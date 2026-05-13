#!/bin/bash
# header_fixes3.sh

# Get the actual macOS SDK path to avoid infinite loops
SDK_PATH=$(xcrun --show-sdk-path)

HEADERS="fcntl.h sys/types.h sys/stat.h sys/select.h unistd.h stdlib.h string.h wchar.h wctype.h float.h sys/resource.h time.h sys/time.h stdio.h ctype.h"

for h in $HEADERS; do
    echo "Converting $h to SDK proxy..."
    
    # Generate a clean macro-safe guard name (e.g., _DARWIN_PROXY_sys_types_h)
    guard_name=$(echo "sys_${h}" | sed 's/[.\/]/_/g')
    
    find . -path "*/$h" | while read -r target; do
        # Unlock and delete any existing Gnulib-generated blocks
        chmod 644 "$target" 2>/dev/null
        rm -f "$target"
        
        # Ensure directory structure exists
        mkdir -p "$(dirname "$target")"
        
        # Create the Base Proxy Header referencing the pristine Apple SDK
        cat > "$target" <<EOF
/* Darwin SDK Proxy Header */
#ifndef ${guard_name}
#define ${guard_name}

#include <stddef.h>

/* Forward declare core memory/exit functions */
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

/* Include the ACTUAL system headers from the SDK */
#include "$SDK_PATH/usr/include/sys/types.h"
#include "$SDK_PATH/usr/include/time.h"
#include "$SDK_PATH/usr/include/sys/time.h"
#include "$SDK_PATH/usr/include/sys/stat.h"
#include "$SDK_PATH/usr/include/fcntl.h"
#include "$SDK_PATH/usr/include/stdlib.h"
#include "$SDK_PATH/usr/include/string.h"
#include "$SDK_PATH/usr/include/unistd.h"
#include "$SDK_PATH/usr/include/wchar.h"
#include "$SDK_PATH/usr/include/wctype.h"
#include "$SDK_PATH/usr/include/float.h"
#include "$SDK_PATH/usr/include/sys/resource.h"

#endif /* ${guard_name} */
EOF

        # Lock the file down to octal 444 for macOS security compliance
        chmod 444 "$target"
    done
done

echo "Stripping Makefile placeholders..."
find . -name "Makefile" -exec sed -i '' 's/@[A-Z0-9_]\{1,\}_H@//g' {} +

echo "Base system alignment complete. Ready for specialized shim application."

