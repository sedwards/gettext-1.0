# Delete the broken Gnulib-generated headers
rm -f sys/wait.h sys/resource.h unistd.h stdlib.h string.h float.h

# If the Makefile tries to rebuild them, we 'touch' them so they look 'done'
# but we leave them empty so the compiler skips them and finds the system ones.
touch sys/wait.h sys/resource.h unistd.h stdlib.h string.h float.h

