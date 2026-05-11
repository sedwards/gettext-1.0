# Run this from the directory containing config.h (usually the parent or current)
cat >> config.h <<EOF
#include <stdlib.h>
#include <string.h>
#ifndef EXIT_FAILURE
# define EXIT_FAILURE 1
#endif
EOF
