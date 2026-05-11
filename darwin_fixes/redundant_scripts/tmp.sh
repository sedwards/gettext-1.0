for c in $(find . -name "config.h"); do
     grep -q "DARWIN_PORTING_SHIM" "$c" || cat >> "$c" <<EOF
 /* DARWIN_PORTING_SHIM */
 #include <stddef.h>
 #include <string.h>
 #ifndef __environ
 # include <crt_externs.h>
 # define environ (*_NSGetEnviron())
 #endif
 static inline void *memrchr(const void *s, int c, size_t n) {
     const unsigned char *cp = (const unsigned char *) s + n;
     while (n--) if (*--cp == (unsigned char) c) return (void *) cp;
     return 0;
 }
 EOF
 
 

