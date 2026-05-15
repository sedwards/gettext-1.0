        cat > libtextstyle/lib/stdint.h <<EOF
/* Darwin SDK Proxy Header */
#ifndef STDINT_H
#define STDINT_H

/* Include the ACTUAL system headers from the SDK */
#include "$SDK_PATH/usr/include/stdint.h"

#endif /* STDINT_H */
EOF

