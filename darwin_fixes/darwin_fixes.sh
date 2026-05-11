#scrub config.h attempts
# Delete the DARWIN_MASTER_FIX block and the inline function blocks from all config.h files
find . -name "config.h" -exec sed -i '' '/DARWIN_MASTER_FIX/,/EOF/d' {} +
find . -name "config.h" -exec sed -i '' '/static inline void \*xmalloc/,/}/d' {} +
find . -name "config.h" -exec sed -i '' '/static inline void \*xrealloc/,/}/d' {} +

