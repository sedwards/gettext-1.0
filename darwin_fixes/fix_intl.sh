# Specifically target the line make is complaining about
sed -i '' '4143s/^[ ]*//' gettext-runtime/intl/gnulib-lib/Makefile

# Broad fix for that whole subdirectory
find gettext-runtime/intl -name "Makefile" -exec sed -i '' 's/^[ ]*GL_GENERATE/GL_GENERATE/g; s/^[ ]*GL_COND/GL_COND/g; s/^    /\t/g' {} +

