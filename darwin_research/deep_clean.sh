find . -name "autom4te.cache" -type d -exec rm -rf {} +

find . -name "gnulib-lib" -type d | while read -r libdir; do
    find "$libdir" -name "*.h" -type f -maxdepth 1 -exec sed -i '' 's/_DARWIN_PROXY_\([a-z0-9_]\{1,\}\)\.h/_DARWIN_PROXY_\1_H/g' {} +
done


