export ACLOCAL_FLAGS="-I /Users/sedwards/gtk/share/aclocal"
#export PKG_CONFIG_PATH=/Users/sedwards/gtk/lib/pkgconfig:$PKG_CONFIG_PATH
export PKG_CONFIG_PATH="/Users/sedwards/gtk/lib/pkgconfig"
export LD_LIBRARY_PATH="/Users/sedwards/gtk/lib"
export XDG_DATA_DIRS="/Users/sedwards/share"
export GNULIB_SRCDIR="/Users/sedwards/gtk/source/gnulib"
export M4PATH="/Users/sedwards/gtk/share/m4"
export M4="/Users/sedwards/gtk/bin/m4"
export PATH="/Users/sedwards/gtk/bin:/usr/bin:/bin:/usr/sbin:/sbin"
export ACLOCAL_PATH="/Users/sedwards/gtk/share/aclocal"
export ACLOCAL_FLAGS="-I /Users/sedwards/gtk/share/aclocal"
#export PKG_CONFIG_PATH=/Users/sedwards/gtk/lib/pkgconfig:$PKG_CONFIG_PATH
export PKG_CONFIG_PATH="/Users/sedwards/gtk/lib/pkgconfig"
export LD_LIBRARY_PATH="/Users/sedwards/gtk/lib"
export XDG_DATA_DIRS="/Users/sedwards/share"
export GNULIB_SRCDIR="/Users/sedwards/gtk/source/gnulib"
export M4PATH="/Users/sedwards/gtk/share/m4"
export M4="/Users/sedwards/gtk/bin/m4"
export PATH="/Users/sedwards/gtk/bin:/usr/bin:/bin:/usr/sbin:/sbin"
export ACLOCAL_PATH="/Users/sedwards/gtk/share/aclocal"


./configure --prefix=/Users/sedwards/gtk --build=arm64-apple-darwin --host=arm64-apple-darwin M4=/Users/sedwards/gtk/bin/m4 --disable-dependency-tracking --with-included-gettext --without-libxml2 --disable-java --disable-d --disable-csharp --disable-curses --disable-libasprintf --disable-modula2 --without-libncurses-prefix --without-libtermcap-prefix --without-libxcurses-prefix --without-libcurses-prefix --without-libtextstyle-prefix --with-included-libunistring --without-emacs


# ensure all of the wctype.h fixes are in
#!/bin/bash

# Define the payload contents for the corrected wctype.h header
cat << 'EOF' > wctype.h.tmp
#ifndef _GL_WCTYPE_H
#define _GL_WCTYPE_H

/* Force the universal shim to apply context first */
#ifdef __APPLE__
# include "darwin_shim.h"
#endif

/* Allow Gnulib to include the actual macOS system header next */
#define _GL_ALREADY_INCLUDING_WCTYPE_H
#include_next <wctype.h>
#undef _GL_ALREADY_INCLUDING_WCTYPE_H

#endif /* _GL_WCTYPE_H */
EOF

# Array containing all target wctype.h paths provided
targets=(
    "./gettext-tools/tests/gnulib-lib/wctype.h"
    "./gettext-runtime/intl/gnulib-lib/wctype.h"
    "./gettext-runtime/libasprintf/gnulib-lib/wctype.h"
    "./libasprintf/gnulib-lib/wctype.h"
    "./gnulib-lib/wctype.h"
)

echo "Starting deployment of native macOS wctype.h patches..."

# Loop through each target path
for target in "${targets[@]}"; do
    # Extract the directory containing the header file
    target_dir=$(dirname "$target")
    
    # Check if the directory exists in the source tree
    if [ -d "$target_dir" ]; then
        echo "Updating shim: $target"
        
        # Unprotect file if it was set read-only by a previous failed make
        chmod +w "$target" 2>/dev/null
        
        # Copy the new header contents to the destination folder
        cp wctype.h.tmp "$target"
        
        # Keep the file read-only so Automake scripts don't easily overwrite it
        chmod r--r--r-- "$target"
    else
        echo "Skipping target directory (Not found): $target_dir"
    fi
done

# Clean up the temporary template file
rm -f wctype.h.tmp
echo "Patch complete. Try running 'make V=1' again."


/* ==========================================================================
   Native Darwin SDK Custom Bootstrapping Block
   ========================================================================== */
#ifdef __APPLE__
# ifdef HAVE_CONFIG_H
#  include "darwin_shim.h"
# endif
#endif



