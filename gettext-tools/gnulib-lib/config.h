#define xmalloc config_h_hidden_xmalloc
#define xrealloc config_h_hidden_xrealloc
#define xmalloc config_h_hidden_xmalloc
#define xrealloc config_h_hidden_xrealloc
/* Force system types and time definitions to prevent 'incomplete type' errors */
#include <sys/types.h>
#include <time.h>
#include <sys/time.h>
#include <fcntl.h>
#include <sys/stat.h>
#undef xmalloc
#undef xrealloc

#undef xmalloc
#undef xrealloc

