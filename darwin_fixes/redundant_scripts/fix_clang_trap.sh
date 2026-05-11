# Delete all local generated C headers that are confusing the C++ compiler
find . -name "stdlib.h" -not -path "*/usr/include/*" -delete
find . -name "string.h" -not -path "*/usr/include/*" -delete
find . -name "unistd.h" -not -path "*/usr/include/*" -delete

