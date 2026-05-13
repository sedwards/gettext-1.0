# Append a clean macro-safe loader block to the template
cat << 'EOF' >> ./config.h.in

/* ==========================================================================
   Native Darwin SDK Custom Bootstrapping Block
   ========================================================================== */
#ifdef __APPLE__
# include "/Users/sedwards/gtk/source/gettext-1.0/darwin_shim.h"
#endif
EOF

