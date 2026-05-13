#!/bin/bash

# Define full mock standalone block for missing macOS uchar.h
cat << 'EOF' > uchar.h.tmp
#ifndef _GL_UCHAR_H
#define _GL_UCHAR_H

#ifdef __APPLE__
# include "darwin_shim.h"
# include <stdint.h>
# include <stddef.h>

/* Define the fundamental C11 types missing from Apple SDK */
# ifndef __cplusplus
#  ifndef __char16_t_defined
    typedef uint_least16_t char16_t;
#   define __char16_t_defined 1
#  endif
#  ifndef __char32_t_defined
    typedef uint_least32_t char32_t;
#   define __char32_t_defined 1
#  endif
# endif

#endif /* __APPLE__ */

#endif /* _GL_UCHAR_H */
EOF

# Deploy to every uchar.h location in the repository
echo "Deploying custom C11 uchar.h types for macOS SDK..."
find . -name "uchar.h" -not -path "*/.git/*" | while read -r target; do
    echo "Replacing shim: $target"
    chmod +w "$target" 2>/dev/null
    cp uchar.h.tmp "$target"
    chmod 444 "$target"
done

rm -f uchar.h.tmp
echo "Standalone uchar.h structure updated successfully."

