# Fix separators and Automake logic in subdirectories
find gettext-tools gettext-runtime -name "Makefile" -exec sed -i '' '
    s/^[ ]*GL_GENERATE/GL_GENERATE/g;
    s/^[ ]*GL_COND/GL_COND/g;
    s/^if /# if /g;
    s/^else/# else/g;
    s/^endif/# endif/g;
    s/^    /\t/g;
' {} +

# Strip placeholders that often cause "No rule to make target"
find . -name "Makefile" -exec sed -i '' 's/@[A-Z0-9_]\{1,\}_H@//g' {} +

