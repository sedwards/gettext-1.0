find . -name "Makefile" -exec sed -i '' 's/@LTLIBICONV@//g' {} +
find . -name "Makefile" -exec sed -i '' 's/@LIBICONV@//g' {} +
find . -name "Makefile" -exec sed -i '' 's/@LTLIBINTL@//g' {} +

