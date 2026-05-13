cat << 'EOF' > unicase.h
#ifndef _GL_UNICASE_H
#define _GL_UNICASE_H

#include <wctype.h>

/* Fallback macro mappings to bypass libunistring dependency */
inline wint_t u32_tolower(wint_t wc) { return towlower(wc); }
inline wint_t u32_toupper(wint_t wc) { return towupper(wc); }

#endif

