 export PATH="/Users/sedwards/gtk/bin:$PATH"
export M4="/Users/sedwards/gtk/bin/m4"

# 1. Clear the old, broken macro library
rm -f aclocal.m4
rm -rf autom4te.cache

# 2. Force aclocal to look in the parallel gnulib folder and your prefix
# Replace ../gnulib with the actual path to your parallel gnulib folder if different
aclocal --force -v \
  -I m4 \
  -I gnulib-m4 \
  -I gettext-tools/gnulib-m4 \
  -I ../gnulib/m4 \
  -I /Users/sedwards/gtk/share/aclocal

# 3. Verify: If this returns nothing, automake will FAIL.
grep "AC_DEFUN(\[GL_GENERATE_ALLOCA_H\]" aclocal.m4

