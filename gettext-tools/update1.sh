 #!/bin/bash

# 1. Fix the corrupted string.h from the previous sed attempt
# This reverts the broken guard and applies a cleaner one
echo "Fixing string.h redefinition errors..."
find . -name "string.h" -exec sed -i '' '/static inline void \*memrchr/,/}/d' {} +
find . -name "string.h" -exec bash -c 'cat >> "$1" <<EOF
#ifndef _GL_MEMRCHR_DEFINED
#define _GL_MEMRCHR_DEFINED
static inline void *memrchr(const void *s, int c, size_t n) {
  const unsigned char *cp = (const unsigned char *) s + n;
  while (n--) if (*--cp == (unsigned char) c) return (void *) cp;
  return 0;
}
#endif
EOF' -- {} \;

# 2. Create missing standard headers that Gnulib expects
echo "Creating missing C23 headers..."
find . -type d -name "gnulib-lib" -exec touch "{}/stdbit.h" \;

# 3. Address "undeclared function" errors (Darwin missing GNU extensions)
# We force the config.h to define these so the compiler sees the prototypes
echo "Patching config.h to enable GNU extensions..."
find . -name "config.h" -exec bash -c 'cat >> "$1" <<EOF
#define HAVE_REALLOCARRAY 1
#define HAVE_MEMRCHR 1
#define HAVE_STRCHRNUL 1
#define HAVE_SECURE_GETENV 1
#define HAVE_SETLOCALE_NULL 1
#define HAVE_MEMSET_EXPLICIT 1
#ifndef __environ
# include <crt_externs.h>
# define environ (*_NSGetEnviron())
#endif
EOF' -- {} \;

# 4. Fix "conflicting types for posix_spawn" 
# Darwin has these, but Gnulib tries to override them. 
# We tell Gnulib to stay away from spawn.
echo "Patching spawn issues..."
find . -name "config.h" -exec sed -i '' 's/.*HAVE_POSIX_SPAWN.*/#define HAVE_POSIX_SPAWN 1/' {} +

echo "Done. Please try running 'make' again."

