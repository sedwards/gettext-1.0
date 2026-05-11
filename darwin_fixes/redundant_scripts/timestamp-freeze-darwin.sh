# Make templates look old
find . -name "*.am" -exec touch -t 202001010000 {} +
find . -name "*.ac" -exec touch -t 202001010000 {} +

# Make generated files look new (recent past so they don't fail sanity checks)
find . -name "*.in" -exec touch -t 202401010000 {} +
touch -t 202401010000 configure aclocal.m4 config.h.in

