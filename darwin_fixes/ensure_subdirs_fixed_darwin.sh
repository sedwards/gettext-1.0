# Fix separators and logic gates in the subdirectories
find gettext-tools gettext-runtime -name "Makefile" -exec sed -i '' '
    s/^[ ]*GL_GENERATE/GL_GENERATE/g;
    s/^[ ]*GL_COND/GL_COND/g;
    s/^if /# if /g;
    s/^else/# else/g;
    s/^endif/# endif/g;
    s/^    /\t/g;
' {} +

