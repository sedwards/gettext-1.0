##### Move to header handling
# Find every single directory containing code and drop unictype.h into it
find . -type d | while read -r subdir; do
    # Only drop the header if the folder contains source files
    if ls "$subdir"/*.c >/dev/null 2>&1 || ls "$subdir"/*.h >/dev/null 2>&1; then
        cat > "$subdir/unictype.h" <<EOF
#ifndef _GL_UNICTYPE_H
#define _GL_UNICTYPE_H
#include <stdbool.h>
#include <ctype.h>
typedef struct { unsigned int code; } uc_property_t;
#define uc_is_alnum(wc) isalnum(wc)
#define uc_is_alpha(wc) isalpha(wc)
#endif
EOF
    fi
done



# Force the system to never trigger an interactive override prompt during file moves
export FORCE_UNLINK=1

# Change the default behavior of the make recipe by clearing existing readonly states
find . -name "sys" -type d | while read -r sysdir; do
    rm -f "$sysdir/types.h" "$sysdir/stat.h" "$sysdir/wait.h" 2>/dev/null
done

##### Move to config.h creation/manipulation
# This forces config.h to hide its own xmalloc/xrealloc definitions
find . -name "config.h" -exec sed -i '' '1s|^|#define xmalloc config_h_hidden_xmalloc\n#define xrealloc config_h_hidden_xrealloc\n|' {} +

# Add a trailing cleanup to the end of config.h files to un-poison the names
find . -name "config.h" -exec sed -i '' '$s|$|\n#undef xmalloc\n#undef xrealloc\n|' {} +

