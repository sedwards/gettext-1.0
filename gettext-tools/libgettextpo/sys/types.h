/* Darwin SDK Proxy Header */
#ifndef _DARWIN_PROXY_H
#define _DARWIN_PROXY_H

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif
    void *malloc(size_t);
    void *realloc(void *, size_t);
    void free(void *);
    void abort(void);
    void exit(int);
#ifdef __cplusplus
}
#endif

/* Include actual system headers */
#include <sys/types.h>
#include <time.h>
#include <sys/time.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <wchar.h>
#include <wctype.h>
#include <float.h>
#include <sys/resource.h>

#endif
