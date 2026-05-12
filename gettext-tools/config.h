#define xmalloc config_h_hidden_xmalloc
#define xrealloc config_h_hidden_xrealloc
#define xmalloc config_h_hidden_xmalloc
#define xrealloc config_h_hidden_xrealloc
/* config.h.  Generated from config.h.in by configure.  */
/* config.h.in.  Generated from configure.ac by autoheader.  */

#if defined __GNUC__ && __GNUC__ >= 15 && !defined __clang__
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wtrailing-whitespace"
#endif



/* Default value for alignment of strings in .mo file.  */
#define DEFAULT_OUTPUT_ALIGNMENT 1


/* Witness that <config.h> has been included.  */
#define _GL_CONFIG_H_INCLUDED 1


/* Define if access does not correctly handle trailing slashes. */
/* #undef ACCESS_TRAILING_SLASH_BUG */

/* Define if building universal (internal helper macro) */
/* #undef AC_APPLE_UNIVERSAL_BUILD */

/* Define if neither thread safety nor multithreading is desired. */
/* #undef AVOID_ANY_THREADS */

/* Define to the directory where to find the localizations of the translation
   domain 'bison-runtime', as a C string. */
#define BISON_LOCALEDIR "/usr/share/locale"

/* Define to the number of bits in type 'ptrdiff_t'. */
/* #undef BITSIZEOF_PTRDIFF_T */

/* Define to the number of bits in type 'sig_atomic_t'. */
/* #undef BITSIZEOF_SIG_ATOMIC_T */

/* Define to the number of bits in type 'size_t'. */
/* #undef BITSIZEOF_SIZE_T */

/* Define to the number of bits in type 'wchar_t'. */
#define BITSIZEOF_WCHAR_T 32

/* Define to the number of bits in type 'wint_t'. */
/* #undef BITSIZEOF_WINT_T */

/* Define if the c32rtomb function has an incorrect return value. */
/* #undef C32RTOMB_RETVAL_BUG */

/* Define if you wish *printf() functions that have a safe handling of
   non-IEEE-754 'long double' values. */
/* #undef CHECK_PRINTF_SAFE */

/* Define if dotnet is the preferred C# implementation. */
/* #undef CSHARP_CHOICE_DOTNET */

/* Define if mono is the preferred C# implementation. */
/* #undef CSHARP_CHOICE_MONO */

/* Define to 1 if using 'alloca.c'. */
/* #undef C_ALLOCA */

/* Define as the bit index in the word where to find bit 0 of the exponent of
   'double'. */
#define DBL_EXPBIT0_BIT 20

/* Define as the word index where to find the exponent of 'double'. */
#define DBL_EXPBIT0_WORD 1

/* Define as the bit index in the word where to find the sign of 'double'. */
/* #undef DBL_SIGNBIT_BIT */

/* Define as the word index where to find the sign of 'double'. */
/* #undef DBL_SIGNBIT_WORD */

/* the name of the file descriptor member of DIR */
/* #undef DIR_FD_MEMBER_NAME */

#ifdef DIR_FD_MEMBER_NAME
# define DIR_TO_FD(Dir_p) ((Dir_p)->DIR_FD_MEMBER_NAME)
#else
# define DIR_TO_FD(Dir_p) -1
#endif


/* Define to 1 if // is a file system root distinct from /. */
/* #undef DOUBLE_SLASH_IS_DISTINCT_ROOT */

/* Define if struct dirent has a member d_ino that actually works. */
/* #undef D_INO_IN_DIRENT */

/* Define to 1 if translation of program messages to the user's native
   language is requested. */
#define ENABLE_NLS 1

/* Define to 1 if the package shall run at any location in the file system. */
/* #undef ENABLE_RELOCATABLE */

/* Define according to the byte order of the target machine: 1 for big endian,
   0 for little endian. */
#define ENDIANNESS 0

/* Define this to 1 if F_DUPFD behavior does not match POSIX */
/* #undef FCNTL_DUPFD_BUGGY */

/* Define to nothing if C supports flexible array members, and to 1 if it does
   not. That way, with a declaration like 'struct s { int n; short
   d[FLEXIBLE_ARRAY_MEMBER]; };', the struct hack can be used with pre-C99
   compilers. Use 'FLEXSIZEOF (struct s, d, N * sizeof (short))' to calculate
   the size in bytes of such a struct containing an N-element array. */
#define FLEXIBLE_ARRAY_MEMBER /**/

/* Define as the bit index in the word where to find bit 0 of the exponent of
   'float'. */
#define FLT_EXPBIT0_BIT 23

/* Define as the word index where to find the exponent of 'float'. */
#define FLT_EXPBIT0_WORD 0

/* Define as the bit index in the word where to find the sign of 'float'. */
/* #undef FLT_SIGNBIT_BIT */

/* Define as the word index where to find the sign of 'float'. */
/* #undef FLT_SIGNBIT_WORD */

/* Define to 1 if fopen() fails to recognize a trailing slash. */
/* #undef FOPEN_TRAILING_SLASH_BUG */

/* Define to 1 if the system's ftello function has the Solaris bug. */
/* #undef FTELLO_BROKEN_AFTER_SWITCHING_FROM_READ_TO_WRITE */

/* Define to 1 if the system's ftello function has the macOS bug. */
/* #undef FTELLO_BROKEN_AFTER_UNGETC */

/* Define to 1 if fflush is known to work on stdin as per POSIX.1-2008 or
   later, 0 if fflush is known to not work, -1 if unknown. */
#define FUNC_FFLUSH_STDIN 0

/* Define to 1 if mkdir mistakenly creates a directory given with a trailing
   dot component. */
/* #undef FUNC_MKDIR_DOT_BUG */

/* Define to 1 if realpath() can malloc memory, always gives an absolute path,
   and handles a trailing slash correctly. */
/* #undef FUNC_REALPATH_NEARLY_WORKS */

/* Define to 1 if realpath() can malloc memory, always gives an absolute path,
   and handles leading slashes and a trailing slash correctly. */
/* #undef FUNC_REALPATH_WORKS */

/* Define to 1 if ungetc is broken when used on arbitrary bytes. */
/* #undef FUNC_UNGETC_BROKEN */

/* Define to 1 if futimesat mishandles a NULL file name. */
/* #undef FUTIMESAT_NULL_BUG */

/* Define this to 'void' or 'struct timezone' to match the system's
   declaration of the second argument to gettimeofday. */
/* #undef GETTIMEOFDAY_TIMEZONE */

/* Define to a C preprocessor expression that evaluates to 1 or 0, depending
   whether the gnulib module accept shall be considered present. */
/* #undef GNULIB_ACCEPT */

/* Define to a C preprocessor expression that evaluates to 1 or 0, depending
   whether the gnulib module bind shall be considered present. */
/* #undef GNULIB_BIND */

/* Define to a C preprocessor expression that evaluates to 1 or 0, depending
   whether the gnulib module canonicalize shall be considered present. */
/* #undef GNULIB_CANONICALIZE */

/* Define to a C preprocessor expression that evaluates to 1 or 0, depending
   whether the gnulib module canonicalize-lgpl shall be considered present. */
/* #undef GNULIB_CANONICALIZE_LGPL */

/* Define to a C preprocessor expression that evaluates to 1 or 0, depending
   whether the gnulib module close shall be considered present. */
#define GNULIB_CLOSE 1

/* Define to a C preprocessor expression that evaluates to 1 or 0, depending
   whether the gnulib module close-stream shall be considered present. */
/* #undef GNULIB_CLOSE_STREAM */

/* Define to a C preprocessor expression that evaluates to 1 or 0, depending
   whether the gnulib module connect shall be considered present. */
/* #undef GNULIB_CONNECT */

/* Define to a C preprocessor expression that evaluates to 1 or 0, depending
   whether the gnulib module dirname shall be considered present. */
/* #undef GNULIB_DIRNAME */

/* Define to a C preprocessor expression that evaluates to 1 or 0, depending
   whether the gnulib module fdopendir shall be considered present. */
/* #undef GNULIB_FDOPENDIR */

/* Define to a C preprocessor expression that evaluates to 1 or 0, depending
   whether the gnulib module fd-safer-flag shall be considered present. */
/* #undef GNULIB_FD_SAFER_FLAG */

/* Define to a C preprocessor expression that evaluates to 1 or 0, depending
   whether the gnulib module fflush shall be considered present. */
/* #undef GNULIB_FFLUSH */

/* Define to a C preprocessor expression that evaluates to 1 or 0, depending
   whether the gnulib module filenamecat shall be considered present. */
/* #undef GNULIB_FILENAMECAT */

/* Define to a C preprocessor expression that evaluates to 1 or 0, depending
   whether the gnulib module fopen-gnu shall be considered present. */
/* #undef GNULIB_FOPEN_GNU */

/* Define to a C preprocessor expression that evaluates to 1 or 0, depending
   whether the gnulib module fscanf shall be considered present. */
#define GNULIB_FSCANF 1

/* Define to a C preprocessor expression that evaluates to 1 or 0, depending
   whether the gnulib module fstat shall be considered present. */
#define GNULIB_FSTAT 1

/* Define to a C preprocessor expression that evaluates to 1 or 0, depending
   whether the gnulib module fstatat shall be considered present. */
/* #undef GNULIB_FSTATAT */

/* Define to a C preprocessor expression that evaluates to 1 or 0, depending
   whether the gnulib module fwriteerror shall be considered present. */
#define GNULIB_FWRITEERROR 1

/* Define to a C preprocessor expression that evaluates to 1 or 0, depending
   whether the gnulib module getcwd shall be considered present. */
/* #undef GNULIB_GETCWD */

/* Define to a C preprocessor expression that evaluates to 1 or 0, depending
   whether the gnulib module ioctl shall be considered present. */
/* #undef GNULIB_IOCTL */

/* Define to a C preprocessor expression that evaluates to 1 or 0, depending
   whether the gnulib module isblank shall be considered present. */
/* #undef GNULIB_ISBLANK */

/* Define to a C preprocessor expression that evaluates to 1 or 0, depending
   whether the gnulib module issymlink shall be considered present. */
/* #undef GNULIB_ISSYMLINK */

/* Define to a C preprocessor expression that evaluates to 1 or 0, depending
   whether the gnulib module issymlinkat shall be considered present. */
/* #undef GNULIB_ISSYMLINKAT */

/* Define to a C preprocessor expression that evaluates to 1 or 0, depending
   whether the gnulib module listen shall be considered present. */
/* #undef GNULIB_LISTEN */

/* Define to a C preprocessor expression that evaluates to 1 or 0, depending
   whether the gnulib module localeconv shall be considered present. */
#define GNULIB_LOCALECONV 1

/* Define to the directory where to find the localizations of the translation
   domain 'gnulib', as a C string. */
#define GNULIB_LOCALEDIR "/Users/sedwards/gtk/share/locale"

/* Define to a C preprocessor expression that evaluates to 1 or 0, depending
   whether the gnulib module lock shall be considered present. */
#define GNULIB_LOCK 1

/* Define to a C preprocessor expression that evaluates to 1 or 0, depending
   whether the gnulib module lstat shall be considered present. */
#define GNULIB_LSTAT 1

/* Define to a C preprocessor expression that evaluates to 1 or 0, depending
   whether the gnulib module mbrtoc32-regular shall be considered present. */
#define GNULIB_MBRTOC32_REGULAR IN_GETTEXT_TOOLS_LIBGREP

/* Define to a C preprocessor expression that evaluates to 1 or 0, depending
   whether the gnulib module msvc-nothrow shall be considered present. */
#define GNULIB_MSVC_NOTHROW 1

/* Define to a C preprocessor expression that evaluates to 1 or 0, depending
   whether the gnulib module openat shall be considered present. */
/* #undef GNULIB_OPENAT */

/* Define to a C preprocessor expression that evaluates to 1 or 0, depending
   whether the gnulib module pipe2-safer shall be considered present. */
/* #undef GNULIB_PIPE2_SAFER */

/* Define to 1 if printf and friends should be labeled with attribute
   "__gnu_printf__" instead of "__printf__" */
/* #undef GNULIB_PRINTF_ATTRIBUTE_FLAVOR_GNU */

/* Define to a C preprocessor expression that evaluates to 1 or 0, depending
   whether the gnulib module reallocarray shall be considered present. */
#define GNULIB_REALLOCARRAY 1

/* Define when the error facility is replaced by gnulib. */
/* #undef GNULIB_REPLACE_ERROR */

/* Define to a C preprocessor expression that evaluates to 1 or 0, depending
   whether the gnulib module scanf shall be considered present. */
#define GNULIB_SCANF 1

/* Define to a C preprocessor expression that evaluates to 1 or 0, depending
   whether the gnulib module select shall be considered present. */
/* #undef GNULIB_SELECT */

/* Define to a C preprocessor expression that evaluates to 1 or 0, depending
   whether the gnulib module setsockopt shall be considered present. */
/* #undef GNULIB_SETSOCKOPT */

/* Define to a C preprocessor expression that evaluates to 1 or 0, depending
   whether the gnulib module sigpipe shall be considered present. */
#define GNULIB_SIGPIPE 1

/* Define to a C preprocessor expression that evaluates to 1 or 0, depending
   whether the gnulib module snprintf shall be considered present. */
/* #undef GNULIB_SNPRINTF */

/* Define to a C preprocessor expression that evaluates to 1 or 0, depending
   whether the gnulib module socket shall be considered present. */
/* #undef GNULIB_SOCKET */

/* Define to a C preprocessor expression that evaluates to 1 or 0, depending
   whether the gnulib module stat shall be considered present. */
#define GNULIB_STAT 1

/* Define to 1 if you want the FILE stream functions getc, putc, etc. to use
   unlocked I/O if available, throughout the package. Unlocked I/O can improve
   performance, sometimes dramatically. But unlocked I/O is safe only in
   processes in which two threads never simultaneously access the same FILE
   stream. */
#define GNULIB_STDIO_SINGLE_THREAD 1

/* Define to a C preprocessor expression that evaluates to 1 or 0, depending
   whether the gnulib module strerror shall be considered present. */
#define GNULIB_STRERROR 1

/* Define to a C preprocessor expression that evaluates to 1 or 0, depending
   whether the gnulib module strerror_r-posix shall be considered present. */
#define GNULIB_STRERROR_R_POSIX 1

/* Define to a C preprocessor expression that evaluates to 1 or 0, depending
   whether the gnulib module tempname shall be considered present. */
/* #undef GNULIB_TEMPNAME */

/* Define to 1 when the gnulib module accept should be tested. */
/* #undef GNULIB_TEST_ACCEPT */

/* Define to 1 when the gnulib module access should be tested. */
/* #undef GNULIB_TEST_ACCESS */

/* Define to 1 when the gnulib module alphasort should be tested. */
/* #undef GNULIB_TEST_ALPHASORT */

/* Define to 1 when the gnulib module bind should be tested. */
/* #undef GNULIB_TEST_BIND */

/* Define to 1 when the gnulib module btoc32 should be tested. */
#define GNULIB_TEST_BTOC32 1

/* Define to 1 when the gnulib module btowc should be tested. */
/* #undef GNULIB_TEST_BTOWC */

/* Define to 1 when the gnulib module c32isalnum should be tested. */
#define GNULIB_TEST_C32ISALNUM 1

/* Define to 1 when the gnulib module c32isalpha should be tested. */
#define GNULIB_TEST_C32ISALPHA 1

/* Define to 1 when the gnulib module c32isblank should be tested. */
#define GNULIB_TEST_C32ISBLANK 1

/* Define to 1 when the gnulib module c32iscntrl should be tested. */
#define GNULIB_TEST_C32ISCNTRL 1

/* Define to 1 when the gnulib module c32isdigit should be tested. */
#define GNULIB_TEST_C32ISDIGIT 1

/* Define to 1 when the gnulib module c32isgraph should be tested. */
#define GNULIB_TEST_C32ISGRAPH 1

/* Define to 1 when the gnulib module c32islower should be tested. */
#define GNULIB_TEST_C32ISLOWER 1

/* Define to 1 when the gnulib module c32isprint should be tested. */
#define GNULIB_TEST_C32ISPRINT 1

/* Define to 1 when the gnulib module c32ispunct should be tested. */
#define GNULIB_TEST_C32ISPUNCT 1

/* Define to 1 when the gnulib module c32isspace should be tested. */
#define GNULIB_TEST_C32ISSPACE 1

/* Define to 1 when the gnulib module c32isupper should be tested. */
#define GNULIB_TEST_C32ISUPPER 1

/* Define to 1 when the gnulib module c32isxdigit should be tested. */
#define GNULIB_TEST_C32ISXDIGIT 1

/* Define to 1 when the gnulib module c32rtomb should be tested. */
#define GNULIB_TEST_C32RTOMB 1

/* Define to 1 when the gnulib module c32tob should be tested. */
/* #undef GNULIB_TEST_C32TOB */

/* Define to 1 when the gnulib module c32tolower should be tested. */
#define GNULIB_TEST_C32TOLOWER 1

/* Define to 1 when the gnulib module c32toupper should be tested. */
#define GNULIB_TEST_C32TOUPPER 1

/* Define to 1 when the gnulib module c32width should be tested. */
#define GNULIB_TEST_C32WIDTH 1

/* Define to 1 when the gnulib module c32_apply_type_test should be tested. */
#define GNULIB_TEST_C32_APPLY_TYPE_TEST 1

/* Define to 1 when the gnulib module c32_get_type_test should be tested. */
#define GNULIB_TEST_C32_GET_TYPE_TEST 1

/* Define to 1 when the gnulib module calloc-gnu should be tested. */
#define GNULIB_TEST_CALLOC_GNU 1

/* Define to 1 when the gnulib module calloc-posix should be tested. */
#define GNULIB_TEST_CALLOC_POSIX 1

/* Define to 1 when the gnulib module canonicalize should be tested. */
/* #undef GNULIB_TEST_CANONICALIZE */

/* Define to 1 when the gnulib module canonicalize_file_name should be tested.
   */
/* #undef GNULIB_TEST_CANONICALIZE_FILE_NAME */

/* Define to 1 when the gnulib module chdir should be tested. */
/* #undef GNULIB_TEST_CHDIR */

/* Define to 1 when the gnulib module cloexec should be tested. */
#define GNULIB_TEST_CLOEXEC 1

/* Define to 1 when the gnulib module close should be tested. */
#define GNULIB_TEST_CLOSE 1

/* Define to 1 when the gnulib module closedir should be tested. */
/* #undef GNULIB_TEST_CLOSEDIR */

/* Define to 1 when the gnulib module connect should be tested. */
/* #undef GNULIB_TEST_CONNECT */

/* Define to 1 when the gnulib module copy-file-range should be tested. */
/* #undef GNULIB_TEST_COPY_FILE_RANGE */

/* Define to 1 when the gnulib module creat should be tested. */
/* #undef GNULIB_TEST_CREAT */

/* Define to 1 when the gnulib module dirfd should be tested. */
/* #undef GNULIB_TEST_DIRFD */

/* Define to 1 when the gnulib module dup should be tested. */
/* #undef GNULIB_TEST_DUP */

/* Define to 1 when the gnulib module dup2 should be tested. */
#define GNULIB_TEST_DUP2 1

/* Define to 1 when the gnulib module environ should be tested. */
/* #undef GNULIB_TEST_ENVIRON */

/* Define to 1 when the gnulib module fchdir should be tested. */
/* #undef GNULIB_TEST_FCHDIR */

/* Define to 1 when the gnulib module fcntl should be tested. */
#define GNULIB_TEST_FCNTL 1

/* Define to 1 when the gnulib module fdopen should be tested. */
#define GNULIB_TEST_FDOPEN 1

/* Define to 1 when the gnulib module fdopendir should be tested. */
/* #undef GNULIB_TEST_FDOPENDIR */

/* Define to 1 when the gnulib module fflush should be tested. */
/* #undef GNULIB_TEST_FFLUSH */

/* Define to 1 when the gnulib module fgetc should be tested. */
#define GNULIB_TEST_FGETC 1

/* Define to 1 when the gnulib module fgets should be tested. */
#define GNULIB_TEST_FGETS 1

/* Define to 1 when the gnulib module fnmatch should be tested. */
/* #undef GNULIB_TEST_FNMATCH */

/* Define to 1 when the gnulib module fopen should be tested. */
#define GNULIB_TEST_FOPEN 1

/* Define to 1 when the gnulib module fopen-gnu should be tested. */
/* #undef GNULIB_TEST_FOPEN_GNU */

/* Define to 1 when the gnulib module fprintf should be tested. */
#define GNULIB_TEST_FPRINTF 1

/* Define to 1 when the gnulib module fpurge should be tested. */
/* #undef GNULIB_TEST_FPURGE */

/* Define to 1 when the gnulib module fputc should be tested. */
#define GNULIB_TEST_FPUTC 1

/* Define to 1 when the gnulib module fputs should be tested. */
#define GNULIB_TEST_FPUTS 1

/* Define to 1 when the gnulib module fread should be tested. */
#define GNULIB_TEST_FREAD 1

/* Define to 1 when the gnulib module free-posix should be tested. */
#define GNULIB_TEST_FREE_POSIX 1

/* Define to 1 when the gnulib module freopen should be tested. */
/* #undef GNULIB_TEST_FREOPEN */

/* Define to 1 when the gnulib module frexp should be tested. */
#define GNULIB_TEST_FREXP 1

/* Define to 1 when the gnulib module frexpl should be tested. */
#define GNULIB_TEST_FREXPL 1

/* Define to 1 when the gnulib module fscanf should be tested. */
#define GNULIB_TEST_FSCANF 1

/* Define to 1 when the gnulib module fseek should be tested. */
/* #undef GNULIB_TEST_FSEEK */

/* Define to 1 when the gnulib module fseeko should be tested. */
/* #undef GNULIB_TEST_FSEEKO */

/* Define to 1 when the gnulib module fstat should be tested. */
#define GNULIB_TEST_FSTAT 1

/* Define to 1 when the gnulib module fstatat should be tested. */
/* #undef GNULIB_TEST_FSTATAT */

/* Define to 1 when the gnulib module ftell should be tested. */
/* #undef GNULIB_TEST_FTELL */

/* Define to 1 when the gnulib module ftello should be tested. */
/* #undef GNULIB_TEST_FTELLO */

/* Define to 1 when the gnulib module ftruncate should be tested. */
/* #undef GNULIB_TEST_FTRUNCATE */

/* Define to 1 when the gnulib module fwrite should be tested. */
#define GNULIB_TEST_FWRITE 1

/* Define to 1 when the gnulib module getaddrinfo should be tested. */
/* #undef GNULIB_TEST_GETADDRINFO */

/* Define to 1 when the gnulib module getc should be tested. */
#define GNULIB_TEST_GETC 1

/* Define to 1 when the gnulib module getchar should be tested. */
#define GNULIB_TEST_GETCHAR 1

/* Define to 1 when the gnulib module getcwd should be tested. */
/* #undef GNULIB_TEST_GETCWD */

/* Define to 1 when the gnulib module getdelim should be tested. */
#define GNULIB_TEST_GETDELIM 1

/* Define to 1 when the gnulib module getdtablesize should be tested. */
#define GNULIB_TEST_GETDTABLESIZE 1

/* Define to 1 when the gnulib module getline should be tested. */
#define GNULIB_TEST_GETLINE 1

/* Define to 1 when the gnulib module getlocalename_l-unsafe should be tested.
   */
/* #undef GNULIB_TEST_GETLOCALENAME_L_UNSAFE */

/* Define to 1 when the gnulib module getopt-posix should be tested. */
/* #undef GNULIB_TEST_GETOPT_POSIX */

/* Define to 1 when the gnulib module getpagesize should be tested. */
/* #undef GNULIB_TEST_GETPAGESIZE */

/* Define to 1 when the gnulib module getprogname should be tested. */
#define GNULIB_TEST_GETPROGNAME 1

/* Define to 1 when the gnulib module getrandom should be tested. */
/* #undef GNULIB_TEST_GETRANDOM */

/* Define to 1 when the gnulib module getrusage should be tested. */
/* #undef GNULIB_TEST_GETRUSAGE */

/* Define to 1 when the gnulib module gettimeofday should be tested. */
/* #undef GNULIB_TEST_GETTIMEOFDAY */

/* Define to 1 when the gnulib module ioctl should be tested. */
/* #undef GNULIB_TEST_IOCTL */

/* Define to 1 when the gnulib module iswblank should be tested. */
#define GNULIB_TEST_ISWBLANK 1

/* Define to 1 when the gnulib module iswctype should be tested. */
/* #undef GNULIB_TEST_ISWCTYPE */

/* Define to 1 when the gnulib module iswdigit should be tested. */
#define GNULIB_TEST_ISWDIGIT 1

/* Define to 1 when the gnulib module iswpunct should be tested. */
#define GNULIB_TEST_ISWPUNCT 1

/* Define to 1 when the gnulib module iswxdigit should be tested. */
#define GNULIB_TEST_ISWXDIGIT 1

/* Define to 1 when the gnulib module link should be tested. */
/* #undef GNULIB_TEST_LINK */

/* Define to 1 when the gnulib module listen should be tested. */
/* #undef GNULIB_TEST_LISTEN */

/* Define to 1 when the gnulib module localeconv should be tested. */
#define GNULIB_TEST_LOCALECONV 1

/* Define to 1 when the gnulib module localename-environ should be tested. */
/* #undef GNULIB_TEST_LOCALENAME_ENVIRON */

/* Define to 1 when the gnulib module localename-unsafe should be tested. */
/* #undef GNULIB_TEST_LOCALENAME_UNSAFE */

/* Define to 1 when the gnulib module localtime should be tested. */
/* #undef GNULIB_TEST_LOCALTIME */

/* Define to 1 when the gnulib module lseek should be tested. */
/* #undef GNULIB_TEST_LSEEK */

/* Define to 1 when the gnulib module lstat should be tested. */
#define GNULIB_TEST_LSTAT 1

/* Define to 1 when the gnulib module malloc-gnu should be tested. */
#define GNULIB_TEST_MALLOC_GNU 1

/* Define to 1 when the gnulib module malloc-posix should be tested. */
#define GNULIB_TEST_MALLOC_POSIX 1

/* Define to 1 when the gnulib module mbrlen should be tested. */
#define GNULIB_TEST_MBRLEN 1

/* Define to 1 when the gnulib module mbrtoc32 should be tested. */
#define GNULIB_TEST_MBRTOC32 1

/* Define to 1 when the gnulib module mbrtowc should be tested. */
#define GNULIB_TEST_MBRTOWC 1

/* Define to 1 when the gnulib module mbsinit should be tested. */
#define GNULIB_TEST_MBSINIT 1

/* Define to 1 when the gnulib module mbslen should be tested. */
/* #undef GNULIB_TEST_MBSLEN */

/* Define to 1 when the gnulib module mbsnlen should be tested. */
#define GNULIB_TEST_MBSNLEN 1

/* Define to 1 when the gnulib module mbsrtoc32s should be tested. */
/* #undef GNULIB_TEST_MBSRTOC32S */

/* Define to 1 when the gnulib module mbsrtowcs should be tested. */
/* #undef GNULIB_TEST_MBSRTOWCS */

/* Define to 1 when the gnulib module mbsstr should be tested. */
/* #undef GNULIB_TEST_MBSSTR */

/* Define to 1 when the gnulib module mbszero should be tested. */
#define GNULIB_TEST_MBSZERO 1

/* Define to 1 when the gnulib module mbtowc should be tested. */
/* #undef GNULIB_TEST_MBTOWC */

/* Define to 1 when the gnulib module memchr should be tested. */
#define GNULIB_TEST_MEMCHR 1

/* Define to 1 when the gnulib module memeq should be tested. */
#define GNULIB_TEST_MEMEQ 1

/* Define to 1 when the gnulib module memmem should be tested. */
#define GNULIB_TEST_MEMMEM 1

/* Define to 1 when the gnulib module mempcpy should be tested. */
/* #undef GNULIB_TEST_MEMPCPY */

/* Define to 1 when the gnulib module memrchr should be tested. */
#define GNULIB_TEST_MEMRCHR 1

/* Define to 1 when the gnulib module memset_explicit should be tested. */
/* #undef GNULIB_TEST_MEMSET_EXPLICIT */

/* Define to 1 when the gnulib module mkdir should be tested. */
/* #undef GNULIB_TEST_MKDIR */

/* Define to 1 when the gnulib module mkdtemp should be tested. */
/* #undef GNULIB_TEST_MKDTEMP */

/* Define to 1 when the gnulib module mkfifo should be tested. */
/* #undef GNULIB_TEST_MKFIFO */

/* Define to 1 when the gnulib module nanosleep should be tested. */
/* #undef GNULIB_TEST_NANOSLEEP */

/* Define to 1 when the gnulib module nl_langinfo should be tested. */
#define GNULIB_TEST_NL_LANGINFO 1

/* Define to 1 when the gnulib module open should be tested. */
#define GNULIB_TEST_OPEN 1

/* Define to 1 when the gnulib module openat should be tested. */
/* #undef GNULIB_TEST_OPENAT */

/* Define to 1 when the gnulib module opendir should be tested. */
/* #undef GNULIB_TEST_OPENDIR */

/* Define to 1 when the gnulib module perror should be tested. */
/* #undef GNULIB_TEST_PERROR */

/* Define to 1 when the gnulib module pipe should be tested. */
/* #undef GNULIB_TEST_PIPE */

/* Define to 1 when the gnulib module pipe2 should be tested. */
/* #undef GNULIB_TEST_PIPE2 */

/* Define to 1 when the gnulib module posix_spawn should be tested. */
/* #undef GNULIB_TEST_POSIX_SPAWN */

/* Define to 1 when the gnulib module posix_spawnattr_destroy should be
   tested. */
/* #undef GNULIB_TEST_POSIX_SPAWNATTR_DESTROY */

/* Define to 1 when the gnulib module posix_spawnattr_init should be tested.
   */
/* #undef GNULIB_TEST_POSIX_SPAWNATTR_INIT */

/* Define to 1 when the gnulib module posix_spawnattr_setflags should be
   tested. */
/* #undef GNULIB_TEST_POSIX_SPAWNATTR_SETFLAGS */

/* Define to 1 when the gnulib module posix_spawnattr_setpgroup should be
   tested. */
/* #undef GNULIB_TEST_POSIX_SPAWNATTR_SETPGROUP */

/* Define to 1 when the gnulib module posix_spawnattr_setsigmask should be
   tested. */
/* #undef GNULIB_TEST_POSIX_SPAWNATTR_SETSIGMASK */

/* Define to 1 when the gnulib module posix_spawnp should be tested. */
/* #undef GNULIB_TEST_POSIX_SPAWNP */

/* Define to 1 when the gnulib module posix_spawn_file_actions_addchdir should
   be tested. */
/* #undef GNULIB_TEST_POSIX_SPAWN_FILE_ACTIONS_ADDCHDIR */

/* Define to 1 when the gnulib module posix_spawn_file_actions_addclose should
   be tested. */
/* #undef GNULIB_TEST_POSIX_SPAWN_FILE_ACTIONS_ADDCLOSE */

/* Define to 1 when the gnulib module posix_spawn_file_actions_adddup2 should
   be tested. */
/* #undef GNULIB_TEST_POSIX_SPAWN_FILE_ACTIONS_ADDDUP2 */

/* Define to 1 when the gnulib module posix_spawn_file_actions_addopen should
   be tested. */
/* #undef GNULIB_TEST_POSIX_SPAWN_FILE_ACTIONS_ADDOPEN */

/* Define to 1 when the gnulib module posix_spawn_file_actions_destroy should
   be tested. */
/* #undef GNULIB_TEST_POSIX_SPAWN_FILE_ACTIONS_DESTROY */

/* Define to 1 when the gnulib module posix_spawn_file_actions_init should be
   tested. */
/* #undef GNULIB_TEST_POSIX_SPAWN_FILE_ACTIONS_INIT */

/* Define to 1 when the gnulib module printf should be tested. */
#define GNULIB_TEST_PRINTF 1

/* Define to 1 when the gnulib module pselect should be tested. */
/* #undef GNULIB_TEST_PSELECT */

/* Define to 1 when the gnulib module pthread-cond should be tested. */
/* #undef GNULIB_TEST_PTHREAD_COND */

/* Define to 1 when the gnulib module pthread-mutex should be tested. */
/* #undef GNULIB_TEST_PTHREAD_MUTEX */

/* Define to 1 when the gnulib module pthread_mutex_timedlock should be
   tested. */
/* #undef GNULIB_TEST_PTHREAD_MUTEX_TIMEDLOCK */

/* Define to 1 when the gnulib module pthread-once should be tested. */
#define GNULIB_TEST_PTHREAD_ONCE 1

/* Define to 1 when the gnulib module pthread-rwlock should be tested. */
/* #undef GNULIB_TEST_PTHREAD_RWLOCK */

/* Define to 1 when the gnulib module pthread_sigmask should be tested. */
#define GNULIB_TEST_PTHREAD_SIGMASK 1

/* Define to 1 when the gnulib module pthread-thread should be tested. */
/* #undef GNULIB_TEST_PTHREAD_THREAD */

/* Define to 1 when the gnulib module putc should be tested. */
#define GNULIB_TEST_PUTC 1

/* Define to 1 when the gnulib module putchar should be tested. */
#define GNULIB_TEST_PUTCHAR 1

/* Define to 1 when the gnulib module putenv should be tested. */
/* #undef GNULIB_TEST_PUTENV */

/* Define to 1 when the gnulib module puts should be tested. */
#define GNULIB_TEST_PUTS 1

/* Define to 1 when the gnulib module raise should be tested. */
#define GNULIB_TEST_RAISE 1

/* Define to 1 when the gnulib module random should be tested. */
/* #undef GNULIB_TEST_RANDOM */

/* Define to 1 when the gnulib module random_r should be tested. */
/* #undef GNULIB_TEST_RANDOM_R */

/* Define to 1 when the gnulib module rawmemchr should be tested. */
#define GNULIB_TEST_RAWMEMCHR 1

/* Define to 1 when the gnulib module read should be tested. */
/* #undef GNULIB_TEST_READ */

/* Define to 1 when the gnulib module readdir should be tested. */
/* #undef GNULIB_TEST_READDIR */

/* Define to 1 when the gnulib module readlink should be tested. */
/* #undef GNULIB_TEST_READLINK */

/* Define to 1 when the gnulib module readlinkat should be tested. */
/* #undef GNULIB_TEST_READLINKAT */

/* Define to 1 when the gnulib module reallocarray should be tested. */
#define GNULIB_TEST_REALLOCARRAY 1

/* Define to 1 when the gnulib module realloc-posix should be tested. */
#define GNULIB_TEST_REALLOC_POSIX 1

/* Define to 1 when the gnulib module realpath should be tested. */
/* #undef GNULIB_TEST_REALPATH */

/* Define to 1 when the gnulib module rename should be tested. */
/* #undef GNULIB_TEST_RENAME */

/* Define to 1 when the gnulib module rewinddir should be tested. */
/* #undef GNULIB_TEST_REWINDDIR */

/* Define to 1 when the gnulib module rmdir should be tested. */
/* #undef GNULIB_TEST_RMDIR */

/* Define to 1 when the gnulib module scandir should be tested. */
/* #undef GNULIB_TEST_SCANDIR */

/* Define to 1 when the gnulib module scanf should be tested. */
#define GNULIB_TEST_SCANF 1

/* Define to 1 when the gnulib module sched_yield should be tested. */
/* #undef GNULIB_TEST_SCHED_YIELD */

/* Define to 1 when the gnulib module secure_getenv should be tested. */
/* #undef GNULIB_TEST_SECURE_GETENV */

/* Define to 1 when the gnulib module select should be tested. */
/* #undef GNULIB_TEST_SELECT */

/* Define to 1 when the gnulib module setenv should be tested. */
/* #undef GNULIB_TEST_SETENV */

/* Define to 1 when the gnulib module setlocale should be tested. */
/* #undef GNULIB_TEST_SETLOCALE */

/* Define to 1 when the gnulib module setlocale_null should be tested. */
#define GNULIB_TEST_SETLOCALE_NULL 1

/* Define to 1 when the gnulib module setsockopt should be tested. */
/* #undef GNULIB_TEST_SETSOCKOPT */

/* Define to 1 when the gnulib module sigaction should be tested. */
/* #undef GNULIB_TEST_SIGACTION */

/* Define to 1 when the gnulib module signbit-no-cxx should be tested. */
#define GNULIB_TEST_SIGNBIT_NO_CXX 1

/* Define to 1 when the gnulib module sigprocmask should be tested. */
#define GNULIB_TEST_SIGPROCMASK 1

/* Define to 1 when the gnulib module sleep should be tested. */
/* #undef GNULIB_TEST_SLEEP */

/* Define to 1 when the gnulib module snprintf should be tested. */
/* #undef GNULIB_TEST_SNPRINTF */

/* Define to 1 when the gnulib module socket should be tested. */
/* #undef GNULIB_TEST_SOCKET */

/* Define to 1 when the gnulib module stat should be tested. */
#define GNULIB_TEST_STAT 1

/* Define to 1 when the gnulib module stdc_memreverse8u should be tested. */
/* #undef GNULIB_TEST_STDC_MEMREVERSE8U */

/* Define to 1 when the gnulib module stpcpy should be tested. */
#define GNULIB_TEST_STPCPY 1

/* Define to 1 when the gnulib module stpncpy should be tested. */
#define GNULIB_TEST_STPNCPY 1

/* Define to 1 when the gnulib module strchrnul should be tested. */
#define GNULIB_TEST_STRCHRNUL 1

/* Define to 1 when the gnulib module strdup should be tested. */
/* #undef GNULIB_TEST_STRDUP */

/* Define to 1 when the gnulib module streq should be tested. */
#define GNULIB_TEST_STREQ 1

/* Define to 1 when the gnulib module strerror should be tested. */
#define GNULIB_TEST_STRERROR 1

/* Define to 1 when the gnulib module strerror_r should be tested. */
#define GNULIB_TEST_STRERROR_R 1

/* Define to 1 when the gnulib module strncpy should be tested. */
#define GNULIB_TEST_STRNCPY 1

/* Define to 1 when the gnulib module strnlen should be tested. */
#define GNULIB_TEST_STRNLEN 1

/* Define to 1 when the gnulib module strnul should be tested. */
#define GNULIB_TEST_STRNUL 1

/* Define to 1 when the gnulib module strpbrk should be tested. */
/* #undef GNULIB_TEST_STRPBRK */

/* Define to 1 when the gnulib module strstr should be tested. */
#define GNULIB_TEST_STRSTR 1

/* Define to 1 when the gnulib module strtol should be tested. */
/* #undef GNULIB_TEST_STRTOL */

/* Define to 1 when the gnulib module strtoul should be tested. */
/* #undef GNULIB_TEST_STRTOUL */

/* Define to 1 when the gnulib module str_endswith should be tested. */
/* #undef GNULIB_TEST_STR_ENDSWITH */

/* Define to 1 when the gnulib module str_startswith should be tested. */
#define GNULIB_TEST_STR_STARTSWITH 1

/* Define to 1 when the gnulib module symlink should be tested. */
/* #undef GNULIB_TEST_SYMLINK */

/* Define to 1 when the gnulib module symlinkat should be tested. */
/* #undef GNULIB_TEST_SYMLINKAT */

/* Define to 1 when the gnulib module time should be tested. */
/* #undef GNULIB_TEST_TIME */

/* Define to 1 when the gnulib module uninorm/u8-normalize should be tested.
   */
/* #undef GNULIB_TEST_UNINORM_U8_NORMALIZE */

/* Define to 1 when the gnulib module unlink should be tested. */
/* #undef GNULIB_TEST_UNLINK */

/* Define to 1 when the gnulib module unlinkat should be tested. */
/* #undef GNULIB_TEST_UNLINKAT */

/* Define to 1 when the gnulib module unsetenv should be tested. */
/* #undef GNULIB_TEST_UNSETENV */

/* Define to 1 when the gnulib module usleep should be tested. */
/* #undef GNULIB_TEST_USLEEP */

/* Define to 1 when the gnulib module utime should be tested. */
/* #undef GNULIB_TEST_UTIME */

/* Define to 1 when the gnulib module vasprintf should be tested. */
#define GNULIB_TEST_VASPRINTF 1

/* Define to 1 when the gnulib module vaszprintf should be tested. */
#define GNULIB_TEST_VASZPRINTF 1

/* Define to 1 when the gnulib module vfprintf should be tested. */
#define GNULIB_TEST_VFPRINTF 1

/* Define to 1 when the gnulib module vprintf should be tested. */
#define GNULIB_TEST_VPRINTF 1

/* Define to 1 when the gnulib module vsnzprintf should be tested. */
/* #undef GNULIB_TEST_VSNZPRINTF */

/* Define to 1 when the gnulib module waitpid should be tested. */
/* #undef GNULIB_TEST_WAITPID */

/* Define to 1 when the gnulib module wcrtomb should be tested. */
#define GNULIB_TEST_WCRTOMB 1

/* Define to 1 when the gnulib module wctob should be tested. */
/* #undef GNULIB_TEST_WCTOB */

/* Define to 1 when the gnulib module wctomb should be tested. */
/* #undef GNULIB_TEST_WCTOMB */

/* Define to 1 when the gnulib module wctype should be tested. */
/* #undef GNULIB_TEST_WCTYPE */

/* Define to 1 when the gnulib module wcwidth should be tested. */
#define GNULIB_TEST_WCWIDTH 1

/* Define to 1 when the gnulib module wmemchr should be tested. */
/* #undef GNULIB_TEST_WMEMCHR */

/* Define to 1 when the gnulib module wmempcpy should be tested. */
/* #undef GNULIB_TEST_WMEMPCPY */

/* Define to 1 when the gnulib module write should be tested. */
#define GNULIB_TEST_WRITE 1

/* Define to a C preprocessor expression that evaluates to 1 or 0, depending
   whether the gnulib module unistd-safer shall be considered present. */
/* #undef GNULIB_UNISTD_SAFER */

/* Define to a C preprocessor expression that evaluates to 1 or 0, depending
   whether the gnulib module unistr/u16-mbtouc shall be considered present. */
#define GNULIB_UNISTR_U16_MBTOUC 1

/* Define to a C preprocessor expression that evaluates to 1 or 0, depending
   whether the gnulib module unistr/u16-mbtoucr shall be considered present.
   */
/* #undef GNULIB_UNISTR_U16_MBTOUCR */

/* Define to a C preprocessor expression that evaluates to 1 or 0, depending
   whether the gnulib module unistr/u8-mbtouc shall be considered present. */
#define GNULIB_UNISTR_U8_MBTOUC 1

/* Define to a C preprocessor expression that evaluates to 1 or 0, depending
   whether the gnulib module unistr/u8-mbtoucr shall be considered present. */
#define GNULIB_UNISTR_U8_MBTOUCR 1

/* Define to a C preprocessor expression that evaluates to 1 or 0, depending
   whether the gnulib module unistr/u8-mbtouc-unsafe shall be considered
   present. */
#define GNULIB_UNISTR_U8_MBTOUC_UNSAFE 1

/* Define to a C preprocessor expression that evaluates to 1 or 0, depending
   whether the gnulib module unistr/u8-uctomb shall be considered present. */
#define GNULIB_UNISTR_U8_UCTOMB 1

/* Define to a C preprocessor expression that evaluates to 1 or 0, depending
   whether the gnulib module xalloc shall be considered present. */
#define GNULIB_XALLOC 1

/* Define to a C preprocessor expression that evaluates to 1 or 0, depending
   whether the gnulib module xalloc-die shall be considered present. */
#define GNULIB_XALLOC_DIE 1

/* Define to a C preprocessor expression that evaluates to 1 or 0, depending
   whether the gnulib module xstring-buffer shall be considered present. */
/* #undef GNULIB_XSTRING_BUFFER */

/* Define to a C preprocessor expression that evaluates to 1 or 0, depending
   whether the gnulib module xstring-buffer-reversed shall be considered
   present. */
/* #undef GNULIB_XSTRING_BUFFER_REVERSED */

/* Define to 1 if you have the `aclsort' function. */
/* #undef HAVE_ACLSORT */

/* Define to 1 if you have the <aclv.h> header file. */
/* #undef HAVE_ACLV_H */

/* Define to 1 if you have the `aclx_get' function. */
/* #undef HAVE_ACLX_GET */

/* Define to 1 if you have the `acl_copy_ext_native' function. */
/* #undef HAVE_ACL_COPY_EXT_NATIVE */

/* Define to 1 if you have the `acl_create_entry_np' function. */
/* #undef HAVE_ACL_CREATE_ENTRY_NP */

/* Define to 1 if you have the `acl_delete_def_file' function. */
/* #undef HAVE_ACL_DELETE_DEF_FILE */

/* Define to 1 if you have the `acl_delete_fd_np' function. */
/* #undef HAVE_ACL_DELETE_FD_NP */

/* Define to 1 if you have the `acl_delete_file_np' function. */
/* #undef HAVE_ACL_DELETE_FILE_NP */

/* Define to 1 if libc or libacl defines the function acl_entries. */
/* #undef HAVE_ACL_ENTRIES */

/* Define to 1 if you have the `acl_extended_file' function. */
/* #undef HAVE_ACL_EXTENDED_FILE */

/* Define to 1 if the constant ACL_FIRST_ENTRY exists. */
/* #undef HAVE_ACL_FIRST_ENTRY */

/* Define to 1 if you have the `acl_free' function. */
/* #undef HAVE_ACL_FREE */

/* Define to 1 if you have the `acl_free_text' function. */
/* #undef HAVE_ACL_FREE_TEXT */

/* Define to 1 if you have the `acl_from_mode' function. */
/* #undef HAVE_ACL_FROM_MODE */

/* Define to 1 if you have the `acl_from_text' function. */
/* #undef HAVE_ACL_FROM_TEXT */

/* Define to 1 if you have the `acl_get_fd' function. */
/* #undef HAVE_ACL_GET_FD */

/* Define to 1 if you have the `acl_get_file' function. */
/* #undef HAVE_ACL_GET_FILE */

/* Define to 1 if you have the `acl_get_link_np' function. */
/* #undef HAVE_ACL_GET_LINK_NP */

/* Define to 1 if you have the <acl/libacl.h> header file. */
/* #undef HAVE_ACL_LIBACL_H */

/* Define to 1 if you have the `acl_set_fd' function. */
/* #undef HAVE_ACL_SET_FD */

/* Define to 1 if you have the `acl_set_file' function. */
/* #undef HAVE_ACL_SET_FILE */

/* Define to 1 if you have the `acl_to_short_text' function. */
/* #undef HAVE_ACL_TO_SHORT_TEXT */

/* Define to 1 if you have the `acl_trivial' function. */
/* #undef HAVE_ACL_TRIVIAL */

/* Define to 1 if the ACL type ACL_TYPE_EXTENDED exists. */
/* #undef HAVE_ACL_TYPE_EXTENDED */

/* Define to 1 if you have the <afunix.h> header file. */
/* #undef HAVE_AFUNIX_H */

/* Define if the __locale_t type contains the name of the LC_MESSAGES
   category. */
/* #undef HAVE_AIX72_LOCALES */

/* Define to 1 if you have 'alloca' after including <alloca.h>, a header that
   may be supplied by this distribution. */
#define HAVE_ALLOCA 1

/* Define to 1 if <alloca.h> works. */
#define HAVE_ALLOCA_H 1

/* Define to 1 if you have the `alphasort' function. */
/* #undef HAVE_ALPHASORT */

/* Define to 1 if you have the <arpa/inet.h> header file. */
#define HAVE_ARPA_INET_H 1

/* Define to 1 if you have the `atexit' function. */
/* #undef HAVE_ATEXIT */

/* Define to 1 if the GCC 4.1 primitives for atomic compare-and-swap can be
   used. */
/* #undef HAVE_ATOMIC_COMPARE_AND_SWAP_GCC41 */

/* Define to 1 if you have the <bcrypt.h> header file. */
/* #undef HAVE_BCRYPT_H */

/* Define to 1 if you have the <bp-sym.h> header file. */
/* #undef HAVE_BP_SYM_H */

/* Define to 1 if you have the `btowc' function. */
/* #undef HAVE_BTOWC */

/* Define to 1 if nanosleep mishandles large arguments. */
/* #undef HAVE_BUG_BIG_NANOSLEEP */

/* Define to 1 if you have the <byteswap.h> header file. */
/* #undef HAVE_BYTESWAP_H */

/* Define to 1 if you have the `canonicalize_file_name' function. */
/* #undef HAVE_CANONICALIZE_FILE_NAME */

/* Define to 1 if you have the `catgets' function. */
#define HAVE_CATGETS 1

/* Define to 1 if you have the Mac OS X function
   CFLocaleCopyPreferredLanguages in the CoreFoundation framework. */
#define HAVE_CFLOCALECOPYPREFERREDLANGUAGES 1

/* Define to 1 if you have the Mac OS X function CFPreferencesCopyAppValue in
   the CoreFoundation framework. */
#define HAVE_CFPREFERENCESCOPYAPPVALUE 1

/* Define to 1 if you have the `chown' function. */
/* #undef HAVE_CHOWN */

/* Define to 1 if you have the `clock_getres' function. */
/* #undef HAVE_CLOCK_GETRES */

/* Define to 1 if you have the `clock_gettime' function. */
/* #undef HAVE_CLOCK_GETTIME */

/* Define to 1 if you have the `clock_settime' function. */
/* #undef HAVE_CLOCK_SETTIME */

/* Define to 1 if you have the `closedir' function. */
/* #undef HAVE_CLOSEDIR */

/* Define to 1 if you have the `close_range' function. */
/* #undef HAVE_CLOSE_RANGE */

/* Define to 1 if you have the `confstr' function. */
/* #undef HAVE_CONFSTR */

/* Define if the copysignf function is declared in <math.h> and available in
   libc. */
/* #undef HAVE_COPYSIGNF_IN_LIBC */

/* Define if the copysignl function is declared in <math.h> and available in
   libc. */
/* #undef HAVE_COPYSIGNL_IN_LIBC */

/* Define if the copysign function is declared in <math.h> and available in
   libc. */
/* #undef HAVE_COPYSIGN_IN_LIBC */

/* Define to 1 if you have the `copy_file_range' function. */
/* #undef HAVE_COPY_FILE_RANGE */

/* Define to 1 if you have the <crtdefs.h> header file. */
/* #undef HAVE_CRTDEFS_H */

/* Define to 1 if C++ nullptr works, 0 if not, (-1) if it is a <stddef.h>
   macro. */
#define HAVE_CXX_NULLPTR 1

/* Define to 1 if the alignas and alignof keywords work. */
/* #undef HAVE_C_ALIGNASOF */

/* Define to 1 if bool, true and false work as per C2023. */
/* #undef HAVE_C_BOOL */

/* Define to 1 if C nullptr is known to work. */
/* #undef HAVE_C_NULLPTR */

/* Define to 1 if the static_assert keyword works. */
/* #undef HAVE_C_STATIC_ASSERT */

/* Define to 1 if C supports variable-length arrays. */
#define HAVE_C_VARARRAYS 1

/* Define if the GNU dcgettext() function is already present or preinstalled.
   */
/* #undef HAVE_DCGETTEXT */

/* Define to 1 if you have the declaration of `alarm', and to 0 if you don't.
   */
#define HAVE_DECL_ALARM 1

/* Define to 1 if you have the declaration of `clearerr_unlocked', and to 0 if
   you don't. */
#define HAVE_DECL_CLEARERR_UNLOCKED 1

/* Define to 1 if you have the declaration of `copysign', and to 0 if you
   don't. */
/* #undef HAVE_DECL_COPYSIGN */

/* Define to 1 if you have the declaration of `copysignf', and to 0 if you
   don't. */
/* #undef HAVE_DECL_COPYSIGNF */

/* Define to 1 if you have the declaration of `copysignl', and to 0 if you
   don't. */
/* #undef HAVE_DECL_COPYSIGNL */

/* Define to 1 if you have the declaration of `dirfd', and to 0 if you don't.
   */
/* #undef HAVE_DECL_DIRFD */

/* Define to 1 if you have the declaration of `ecvt', and to 0 if you don't.
   */
#define HAVE_DECL_ECVT 1

/* Define to 1 if you have the declaration of `execvpe', and to 0 if you
   don't. */
#define HAVE_DECL_EXECVPE 0

/* Define to 1 if you have the declaration of `fchdir', and to 0 if you don't.
   */
/* #undef HAVE_DECL_FCHDIR */

/* Define to 1 if you have the declaration of `fcloseall', and to 0 if you
   don't. */
#define HAVE_DECL_FCLOSEALL 0

/* Define to 1 if you have the declaration of `fcvt', and to 0 if you don't.
   */
#define HAVE_DECL_FCVT 1

/* Define to 1 if you have the declaration of `fdopendir', and to 0 if you
   don't. */
/* #undef HAVE_DECL_FDOPENDIR */

/* Define to 1 if you have the declaration of `feof_unlocked', and to 0 if you
   don't. */
#define HAVE_DECL_FEOF_UNLOCKED 1

/* Define to 1 if you have the declaration of `ferror_unlocked', and to 0 if
   you don't. */
#define HAVE_DECL_FERROR_UNLOCKED 1

/* Define to 1 if you have the declaration of `fflush_unlocked', and to 0 if
   you don't. */
#define HAVE_DECL_FFLUSH_UNLOCKED 0

/* Define to 1 if you have the declaration of `fgets_unlocked', and to 0 if
   you don't. */
#define HAVE_DECL_FGETS_UNLOCKED 0

/* Define to 1 if you have the declaration of `fileno_unlocked', and to 0 if
   you don't. */
#define HAVE_DECL_FILENO_UNLOCKED 1

/* Define to 1 if you have the declaration of `fpurge', and to 0 if you don't.
   */
/* #undef HAVE_DECL_FPURGE */

/* Define to 1 if you have the declaration of `fputc_unlocked', and to 0 if
   you don't. */
#define HAVE_DECL_FPUTC_UNLOCKED 0

/* Define to 1 if you have the declaration of `fputs_unlocked', and to 0 if
   you don't. */
#define HAVE_DECL_FPUTS_UNLOCKED 0

/* Define to 1 if you have the declaration of `fread_unlocked', and to 0 if
   you don't. */
#define HAVE_DECL_FREAD_UNLOCKED 0

/* Define to 1 if you have the declaration of `freeaddrinfo', and to 0 if you
   don't. */
/* #undef HAVE_DECL_FREEADDRINFO */

/* Define to 1 if you have the declaration of `fseeko', and to 0 if you don't.
   */
/* #undef HAVE_DECL_FSEEKO */

/* Define to 1 if you have the declaration of `ftello', and to 0 if you don't.
   */
/* #undef HAVE_DECL_FTELLO */

/* Define to 1 if you have the declaration of `fwrite_unlocked', and to 0 if
   you don't. */
#define HAVE_DECL_FWRITE_UNLOCKED 0

/* Define to 1 if you have the declaration of `gai_strerror', and to 0 if you
   don't. */
/* #undef HAVE_DECL_GAI_STRERROR */

/* Define to 1 if you have the declaration of `gai_strerrorA', and to 0 if you
   don't. */
/* #undef HAVE_DECL_GAI_STRERRORA */

/* Define to 1 if you have the declaration of `gcvt', and to 0 if you don't.
   */
#define HAVE_DECL_GCVT 1

/* Define to 1 if you have the declaration of `getaddrinfo', and to 0 if you
   don't. */
/* #undef HAVE_DECL_GETADDRINFO */

/* Define to 1 if you have the declaration of `getchar_unlocked', and to 0 if
   you don't. */
#define HAVE_DECL_GETCHAR_UNLOCKED 1

/* Define to 1 if you have the declaration of `getcwd', and to 0 if you don't.
   */
/* #undef HAVE_DECL_GETCWD */

/* Define to 1 if you have the declaration of `getc_unlocked', and to 0 if you
   don't. */
#define HAVE_DECL_GETC_UNLOCKED 1

/* Define to 1 if you have the declaration of `getdelim', and to 0 if you
   don't. */
#define HAVE_DECL_GETDELIM 1

/* Define to 1 if you have the declaration of `getdtablesize', and to 0 if you
   don't. */
#define HAVE_DECL_GETDTABLESIZE 1

/* Define to 1 if you have the declaration of `getline', and to 0 if you
   don't. */
#define HAVE_DECL_GETLINE 1

/* Define to 1 if you have the declaration of `getnameinfo', and to 0 if you
   don't. */
/* #undef HAVE_DECL_GETNAMEINFO */

/* Define to 1 if you have the declaration of `getw', and to 0 if you don't.
   */
#define HAVE_DECL_GETW 1

/* Define to 1 if you have the declaration of `htonl', and to 0 if you don't.
   */
/* #undef HAVE_DECL_HTONL */

/* Define to 1 if you have the declaration of `htons', and to 0 if you don't.
   */
/* #undef HAVE_DECL_HTONS */

/* Define to 1 if you have the declaration of `inet_ntop', and to 0 if you
   don't. */
/* #undef HAVE_DECL_INET_NTOP */

/* Define to 1 if you have the declaration of `inet_pton', and to 0 if you
   don't. */
/* #undef HAVE_DECL_INET_PTON */

/* Define to 1 if you have the declaration of `initstate', and to 0 if you
   don't. */
/* #undef HAVE_DECL_INITSTATE */

/* Define to 1 if you have the declaration of `isblank', and to 0 if you
   don't. */
#define HAVE_DECL_ISBLANK 1

/* Define to 1 if you have the declaration of `iswblank', and to 0 if you
   don't. */
#define HAVE_DECL_ISWBLANK 1

/* Define to 1 if you have the declaration of `mbrlen', and to 0 if you don't.
   */
/* #undef HAVE_DECL_MBRLEN */

/* Define to 1 if you have the declaration of `mbrtowc', and to 0 if you
   don't. */
/* #undef HAVE_DECL_MBRTOWC */

/* Define to 1 if you have the declaration of `mbsinit', and to 0 if you
   don't. */
/* #undef HAVE_DECL_MBSINIT */

/* Define to 1 if you have the declaration of `mbsrtowcs', and to 0 if you
   don't. */
/* #undef HAVE_DECL_MBSRTOWCS */

/* Define to 1 if you have the declaration of `memeq', and to 0 if you don't.
   */
#define HAVE_DECL_MEMEQ 0

/* Define to 1 if you have the declaration of `memmem', and to 0 if you don't.
   */
#define HAVE_DECL_MEMMEM 1

/* Define to 1 if you have the declaration of `memrchr', and to 0 if you
   don't. */
#define HAVE_DECL_MEMRCHR 0

/* Define to 1 if you have the declaration of `ntohl', and to 0 if you don't.
   */
/* #undef HAVE_DECL_NTOHL */

/* Define to 1 if you have the declaration of `ntohs', and to 0 if you don't.
   */
/* #undef HAVE_DECL_NTOHS */

/* Define to 1 if you have the declaration of `posix_spawn', and to 0 if you
   don't. */
/* #undef HAVE_DECL_POSIX_SPAWN */

/* Define to 1 if you have the declaration of `program_invocation_name', and
   to 0 if you don't. */
#define HAVE_DECL_PROGRAM_INVOCATION_NAME 0

/* Define to 1 if you have the declaration of `program_invocation_short_name',
   and to 0 if you don't. */
/* #undef HAVE_DECL_PROGRAM_INVOCATION_SHORT_NAME */

/* Define to 1 if you have the declaration of `putchar_unlocked', and to 0 if
   you don't. */
#define HAVE_DECL_PUTCHAR_UNLOCKED 1

/* Define to 1 if you have the declaration of `putc_unlocked', and to 0 if you
   don't. */
#define HAVE_DECL_PUTC_UNLOCKED 1

/* Define to 1 if you have the declaration of `putw', and to 0 if you don't.
   */
#define HAVE_DECL_PUTW 1

/* Define to 1 if you have the declaration of `setenv', and to 0 if you don't.
   */
/* #undef HAVE_DECL_SETENV */

/* Define to 1 if you have the declaration of `setstate', and to 0 if you
   don't. */
/* #undef HAVE_DECL_SETSTATE */

/* Define to 1 if you have the declaration of `sleep', and to 0 if you don't.
   */
/* #undef HAVE_DECL_SLEEP */

/* Define to 1 if you have the declaration of `snprintf', and to 0 if you
   don't. */
/* #undef HAVE_DECL_SNPRINTF */

/* Define to 1 if you have the declaration of `stdc_rotate_left_uc', and to 0
   if you don't. */
/* #undef HAVE_DECL_STDC_ROTATE_LEFT_UC */

/* Define to 1 if you have the declaration of `stpncpy', and to 0 if you
   don't. */
#define HAVE_DECL_STPNCPY 1

/* Define to 1 if you have the declaration of `strdup', and to 0 if you don't.
   */
/* #undef HAVE_DECL_STRDUP */

/* Define to 1 if you have the declaration of `streq', and to 0 if you don't.
   */
#define HAVE_DECL_STREQ 0

/* Define to 1 if you have the declaration of `strerror_r', and to 0 if you
   don't. */
#define HAVE_DECL_STRERROR_R 1

/* Define to 1 if you have the declaration of `strnlen', and to 0 if you
   don't. */
#define HAVE_DECL_STRNLEN 1

/* Define to 1 if you have the declaration of `towlower', and to 0 if you
   don't. */
/* #undef HAVE_DECL_TOWLOWER */

/* Define to 1 if you have the declaration of `unsetenv', and to 0 if you
   don't. */
/* #undef HAVE_DECL_UNSETENV */

/* Define to 1 if you have the declaration of `wcrtomb', and to 0 if you
   don't. */
/* #undef HAVE_DECL_WCRTOMB */

/* Define to 1 if you have the declaration of `wcsdup', and to 0 if you don't.
   */
#define HAVE_DECL_WCSDUP 1

/* Define to 1 if you have the declaration of `wcwidth', and to 0 if you
   don't. */
#define HAVE_DECL_WCWIDTH 1

/* Define to 1 if you have the declaration of `_fseeki64', and to 0 if you
   don't. */
/* #undef HAVE_DECL__FSEEKI64 */

/* Define to 1 if you have the declaration of `_putenv', and to 0 if you
   don't. */
/* #undef HAVE_DECL__PUTENV */

/* Define to 1 if you have the declaration of `_snprintf', and to 0 if you
   don't. */
#define HAVE_DECL__SNPRINTF 0

/* Define to 1 if you have the declaration of `__argv', and to 0 if you don't.
   */
/* #undef HAVE_DECL___ARGV */

/* Define to 1 if you have the declaration of `__fpending', and to 0 if you
   don't. */
/* #undef HAVE_DECL___FPENDING */

/* Define to 1 if you have the <dirent.h> header file. */
/* #undef HAVE_DIRENT_H */

/* Define to 1 if you have the `dirfd' function. */
/* #undef HAVE_DIRFD */

/* Define to 1 if dladdr exists and is defined in libc. */
#define HAVE_DLADDR_IN_LIBC 1

/* Define to 1 if you have the <dlfcn.h> header file. */
#define HAVE_DLFCN_H 1

/* Define to 1 if you have the `duplocale' function. */
/* #undef HAVE_DUPLOCALE */

/* Define to 1 if you have the <endian.h> header file. */
/* #undef HAVE_ENDIAN_H */

/* Define if you have the declaration of environ. */
/* #undef HAVE_ENVIRON_DECL */

/* Define to 1 if you have the `error' function. */
/* #undef HAVE_ERROR */

/* Define to 1 if you have the <error.h> header file. */
/* #undef HAVE_ERROR_H */

/* Define to 1 if you have the `explicit_memset' function. */
/* #undef HAVE_EXPLICIT_MEMSET */

/* Define to 1 if you have the `faccessat' function. */
/* #undef HAVE_FACCESSAT */

/* Define to 1 if you have the `facl' function. */
/* #undef HAVE_FACL */

/* Define if the locale_t type contains insufficient information, as on
   OpenBSD. */
/* #undef HAVE_FAKE_LOCALES */

/* Define to 1 if you have the `fchdir' function. */
#define HAVE_FCHDIR 1

/* Define to 1 if you have the `fchmod' function. */
/* #undef HAVE_FCHMOD */

/* Define to 1 if you have the `fcntl' function. */
#define HAVE_FCNTL 1

/* Define to 1 if you have the `fdopendir' function. */
/* #undef HAVE_FDOPENDIR */

/* Define to 1 if you have the <features.h> header file. */
/* #undef HAVE_FEATURES_H */

/* Define to 1 if you have the `flockfile' function. */
#define HAVE_FLOCKFILE 1

/* Define to 1 if you have the `fnmatch' function. */
/* #undef HAVE_FNMATCH */

/* Define to 1 if you have the <fnmatch.h> header file. */
/* #undef HAVE_FNMATCH_H */

/* Define to 1 if you have the `fpurge' function. */
/* #undef HAVE_FPURGE */

/* Define to 1 if you have the `freelocale' function. */
/* #undef HAVE_FREELOCALE */

/* Define if the 'free' function is guaranteed to preserve errno. */
/* #undef HAVE_FREE_POSIX */

/* Define if the frexpl function is available in libc. */
#define HAVE_FREXPL_IN_LIBC 1

/* Define if the frexp function is available in libc. */
#define HAVE_FREXP_IN_LIBC 1

/* Define to 1 if the system has the fseeko function. */
/* #undef HAVE_FSEEKO */

/* Define to 1 if you have the `fstatat' function. */
/* #undef HAVE_FSTATAT */

/* Define to 1 if the system has the ftello function. */
/* #undef HAVE_FTELLO */

/* Define to 1 if you have the `ftruncate' function. */
/* #undef HAVE_FTRUNCATE */

/* Define to 1 if you have the `funlockfile' function. */
#define HAVE_FUNLOCKFILE 1

/* Define to 1 if you have the `futimens' function. */
/* #undef HAVE_FUTIMENS */

/* Define to 1 if you have the `futimes' function. */
/* #undef HAVE_FUTIMES */

/* Define to 1 if you have the `futimesat' function. */
/* #undef HAVE_FUTIMESAT */

/* Define to 1 if you have the `getacl' function. */
/* #undef HAVE_GETACL */

/* Define to 1 if getaddrinfo exists, or to 0 otherwise. */
/* #undef HAVE_GETADDRINFO */

/* Define to 1 if you have the `getcwd' function. */
/* #undef HAVE_GETCWD */

/* Define to 1 if getcwd works, but with shorter paths than is generally
   tested with the replacement. */
/* #undef HAVE_GETCWD_SHORTER */

/* Define to 1 if you have the `getdelim' function. */
#define HAVE_GETDELIM 1

/* Define to 1 if you have the `getdtablesize' function. */
#define HAVE_GETDTABLESIZE 1

/* Define to 1 if you have the `getegid' function. */
/* #undef HAVE_GETEGID */

/* Define to 1 if you have the `geteuid' function. */
/* #undef HAVE_GETEUID */

/* Define to 1 if you have the `getexecname' function. */
/* #undef HAVE_GETEXECNAME */

/* Define to 1 if you have the `getgid' function. */
/* #undef HAVE_GETGID */

/* Define to 1 if you have the `gethostbyname' function. */
#define HAVE_GETHOSTBYNAME 1

/* Define to 1 if you have the `gethostname' function. */
#define HAVE_GETHOSTNAME 1

/* Define to 1 if you have the `getline' function. */
#define HAVE_GETLINE 1

/* Define to 1 if you have the `getlocalename_l' function. */
/* #undef HAVE_GETLOCALENAME_L */

/* Define to 1 if you have the <getopt.h> header file. */
/* #undef HAVE_GETOPT_H */

/* Define to 1 if you have the `getopt_long_only' function. */
/* #undef HAVE_GETOPT_LONG_ONLY */

/* Define to 1 if you have the `getppriv' function. */
/* #undef HAVE_GETPPRIV */

/* Define to 1 if you have the `getprogname' function. */
#define HAVE_GETPROGNAME 1

/* Define to 1 if you have the `getrandom' function. */
/* #undef HAVE_GETRANDOM */

/* Define to 1 if you have the `getrlimit' function. */
#define HAVE_GETRLIMIT 1

/* Define to 1 if you have the `getrusage' function. */
/* #undef HAVE_GETRUSAGE */

/* Define to 1 if you have the `getservbyname' function. */
/* #undef HAVE_GETSERVBYNAME */

/* Define if the GNU gettext() function is already present or preinstalled. */
/* #undef HAVE_GETTEXT */

/* Define to 1 if you have the `gettimeofday' function. */
/* #undef HAVE_GETTIMEOFDAY */

/* Define to 1 if you have the `getuid' function. */
/* #undef HAVE_GETUID */

/* Define if the uselocale function exists, may be safely called, and returns
   sufficient information. */
/* #undef HAVE_GOOD_USELOCALE */

/* Define if you have the iconv() function and it works. */
/* #undef HAVE_ICONV */

/* Define to 1 if you have the <iconv.h> header file. */
#define HAVE_ICONV_H 1

/* Define to 1 if you have the `inet_ntop' function. */
#define HAVE_INET_NTOP 1

/* Define to 1 if you have the `inet_pton' function. */
/* #undef HAVE_INET_PTON */

/* Define to 1 if you have the `initstate' function. */
/* #undef HAVE_INITSTATE */

/* Define to 1 if the compiler supports one of the keywords 'inline',
   '__inline__', '__inline' and effectively inlines functions marked as such.
   */
#define HAVE_INLINE 1

/* Define if you have the 'intmax_t' type in <stdint.h> or <inttypes.h>. */
#define HAVE_INTMAX_T 1

/* Define to 1 if you have the <inttypes.h> header file. */
#define HAVE_INTTYPES_H 1

/* Define if <inttypes.h> exists, doesn't clash with <sys/types.h>, and
   declares uintmax_t. */
#define HAVE_INTTYPES_H_WITH_UINTMAX 1

/* Define to 1 if you have the `ioctl' function. */
/* #undef HAVE_IOCTL */

/* Define to 1 if <sys/socket.h> defines AF_INET. */
/* #undef HAVE_IPV4 */

/* Define if <sys/socket.h> defines AF_INET6. */
#define HAVE_IPV6 1

/* Define to 1 if you have the `isblank' function. */
#define HAVE_ISBLANK 1

/* Define if the isnan(double) function is available in libc. */
#define HAVE_ISNAND_IN_LIBC 1

/* Define if the isnan(float) function is available in libc. */
#define HAVE_ISNANF_IN_LIBC 1

/* Define if the isnan(long double) function is available in libc. */
#define HAVE_ISNANL_IN_LIBC 1

/* Define to 1 if you have the `issetugid' function. */
/* #undef HAVE_ISSETUGID */

/* Define to 1 if you have the `iswblank' function. */
#define HAVE_ISWBLANK 1

/* Define to 1 if you have the `iswcntrl' function. */
#define HAVE_ISWCNTRL 1

/* Define to 1 if you have the `iswctype' function. */
#define HAVE_ISWCTYPE 1

/* Define if you have <langinfo.h> and nl_langinfo(CODESET). */
#define HAVE_LANGINFO_CODESET 1

/* Define to 1 if you have the <langinfo.h> header file. */
#define HAVE_LANGINFO_H 1

/* Define if your <locale.h> file defines LC_MESSAGES. */
/* #undef HAVE_LC_MESSAGES */

/* Define if the ldexpl function is available in libc. */
#define HAVE_LDEXPL_IN_LIBC 1

/* Define if the ldexp function is available in libc. */
#define HAVE_LDEXP_IN_LIBC 1

/* Define to 1 if you have the <libcx/spawn2.h> header file. */
/* #undef HAVE_LIBCX_SPAWN2_H */

/* Define to 1 if you have the <libintl.h> header file. */
/* #undef HAVE_LIBINTL_H */

/* Define if you have the libtextstyle library. */
/* #undef HAVE_LIBTEXTSTYLE */

/* Define if you have the libunistring library. */
/* #undef HAVE_LIBUNISTRING */

/* Define to 1 if the bcrypt library is guaranteed to be present. */
/* #undef HAVE_LIB_BCRYPT */

/* Define to 1 if you have the <limits.h> header file. */
#define HAVE_LIMITS_H 1

/* Define to 1 if you have the `link' function. */
/* #undef HAVE_LINK */

/* Define to 1 if you have the <linux/fs.h> header file. */
/* #undef HAVE_LINUX_FS_H */

/* Define to 1 if you have the <linux/xattr.h> header file. */
/* #undef HAVE_LINUX_XATTR_H */

/* Define to 1 if you have the `listxattr' function. */
/* #undef HAVE_LISTXATTR */

/* Define to 1 if you support file names longer than 14 characters. */
/* #undef HAVE_LONG_FILE_NAMES */

/* Define to 1 if the system has the type 'long long int'. */
#define HAVE_LONG_LONG_INT 1

/* Define to 1 if you have the `lstat' function. */
#define HAVE_LSTAT 1

/* Define to 1 if you have the `lutimens' function. */
/* #undef HAVE_LUTIMENS */

/* Define to 1 if you have the `lutimes' function. */
/* #undef HAVE_LUTIMES */

/* Define to 1 if you have the <mach-o/dyld.h> header file. */
/* #undef HAVE_MACH_O_DYLD_H */

/* Define to 1 if malloc (0) returns nonnull. */
#define HAVE_MALLOC_0_NONNULL 1

/* Define to 1 if you have the <malloc.h> header file. */
/* #undef HAVE_MALLOC_H */

/* Define if malloc and calloc set errno on allocation failure. */
#define HAVE_MALLOC_POSIX 1

/* Define to 1 if malloc-like functions do not allocate objects larger than
   PTRDIFF_MAX bytes. */
#define HAVE_MALLOC_PTRDIFF 1

/* Define to 1 if you have the <math.h> header file. */
#define HAVE_MATH_H 1

/* Define to 1 if you have the `mbrlen' function. */
#define HAVE_MBRLEN 1

/* Define to 1 if you have the `mbrtowc' function. */
#define HAVE_MBRTOWC 1

/* Define to 1 if you have the `mbsinit' function. */
#define HAVE_MBSINIT 1

/* Define to 1 if you have the `mbslen' function. */
/* #undef HAVE_MBSLEN */

/* Define to 1 if you have the `mbsrtowcs' function. */
/* #undef HAVE_MBSRTOWCS */

/* Define to 1 if <wchar.h> declares mbstate_t. */
#define HAVE_MBSTATE_T 1

/* Define to 1 if you have the `mbtowc' function. */
/* #undef HAVE_MBTOWC */

/* Define to 1 if you have the `memmem' function. */
#define HAVE_MEMMEM 1

/* Define to 1 if you have the `memmove' function. */
/* #undef HAVE_MEMMOVE */

/* Define to 1 if you have the `mempcpy' function. */
/* #undef HAVE_MEMPCPY */

/* Define to 1 if you have the `memrchr' function. */
/* #undef HAVE_MEMRCHR */

/* Define to 1 if you have the `memset' function. */
/* #undef HAVE_MEMSET */

/* Define to 1 if you have the `memset_explicit' function. */
/* #undef HAVE_MEMSET_EXPLICIT */

/* Define to 1 if you have the `memset_s' function. */
/* #undef HAVE_MEMSET_S */

/* Define to 1 if memset_s support zero-length operations. */
/* #undef HAVE_MEMSET_S_SUPPORTS_ZERO */

/* Define to 1 if getcwd minimally works, that is, its result can be trusted
   when it succeeds. */
/* #undef HAVE_MINIMALLY_WORKING_GETCWD */

/* Define to 1 if you have the <minix/config.h> header file. */
/* #undef HAVE_MINIX_CONFIG_H */

/* Define to 1 if <limits.h> defines the MIN and MAX macros. */
/* #undef HAVE_MINMAX_IN_LIMITS_H */

/* Define to 1 if <sys/param.h> defines the MIN and MAX macros. */
#define HAVE_MINMAX_IN_SYS_PARAM_H 1

/* Define to 1 if you have the `mkdtemp' function. */
/* #undef HAVE_MKDTEMP */

/* Define to 1 if you have a 'mkfifo' function. */
/* #undef HAVE_MKFIFO */

/* Define to 1 if you have the `mprotect' function. */
#define HAVE_MPROTECT 1

/* Define to 1 if you have the `mquery' function. */
/* #undef HAVE_MQUERY */

/* Define to 1 on MSVC platforms that have the "invalid parameter handler"
   concept. */
/* #undef HAVE_MSVC_INVALID_PARAMETER_HANDLER */

/* Define if the locale_t type does not contain the name of each locale
   category. */
/* #undef HAVE_NAMELESS_LOCALES */

/* Define to 1 if you have the <netdb.h> header file. */
/* #undef HAVE_NETDB_H */

/* Define to 1 if you have the <netinet/in.h> header file. */
/* #undef HAVE_NETINET_IN_H */

/* Define to 1 if you have the `newlocale' function. */
/* #undef HAVE_NEWLOCALE */

/* Define to 1 if you have the `nl_langinfo' function. */
#define HAVE_NL_LANGINFO 1

/* Define to 1 if you have the <obstack.h> header file. */
/* #undef HAVE_OBSTACK_H */

/* Define to 1 if you have the `openat' function. */
/* #undef HAVE_OPENAT */

/* Define to 1 if you have the `opendir' function. */
/* #undef HAVE_OPENDIR */

/* Define to 1 if you have the <OS.h> header file. */
/* #undef HAVE_OS_H */

/* Define to 1 if getcwd works, except it sometimes fails when it shouldn't,
   setting errno to ERANGE, ENAMETOOLONG, or ENOENT. */
/* #undef HAVE_PARTLY_WORKING_GETCWD */

/* Define to 1 if you have the `pathconf' function. */
/* #undef HAVE_PATHCONF */

/* Define to 1 if you have the <paths.h> header file. */
/* #undef HAVE_PATHS_H */

/* Define to 1 if you have the `pipe' function. */
/* #undef HAVE_PIPE */

/* Define to 1 if you have the `pipe2' function. */
/* #undef HAVE_PIPE2 */

/* Define to 1 if you have the `posix_spawn' function. */
/* #undef HAVE_POSIX_SPAWN */

/* Define to 1 if the system has the type `posix_spawnattr_t'. */
/* #undef HAVE_POSIX_SPAWNATTR_T */

/* Define to 1 if you have the `posix_spawn_file_actions_addchdir' function.
   */
/* #undef HAVE_POSIX_SPAWN_FILE_ACTIONS_ADDCHDIR */

/* Define to 1 if you have the `posix_spawn_file_actions_addchdir_np'
   function. */
/* #undef HAVE_POSIX_SPAWN_FILE_ACTIONS_ADDCHDIR_NP */

/* Define to 1 if the system has the type `posix_spawn_file_actions_t'. */
/* #undef HAVE_POSIX_SPAWN_FILE_ACTIONS_T */

/* Define to 1 if you have the <priv.h> header file. */
/* #undef HAVE_PRIV_H */

/* Define to 1 if you have the `pselect' function. */
/* #undef HAVE_PSELECT */

/* Define to 1 if you have the `pstat_getprocvm' function. */
/* #undef HAVE_PSTAT_GETPROCVM */

/* Define if you have the <pthread.h> header and the POSIX threads API. */
#define HAVE_PTHREAD_API 1

/* Define to 1 if you have the `pthread_atfork' function. */
#define HAVE_PTHREAD_ATFORK 1

/* Define to 1 if you have the <pthread.h> header file. */
#define HAVE_PTHREAD_H 1

/* Define if the <pthread.h> defines PTHREAD_MUTEX_RECURSIVE. */
#define HAVE_PTHREAD_MUTEX_RECURSIVE 1

/* Define if the POSIX multithreading library has read/write locks. */
#define HAVE_PTHREAD_RWLOCK 1

/* Define if the 'pthread_rwlock_rdlock' function prefers a writer to a
   reader. */
#define HAVE_PTHREAD_RWLOCK_RDLOCK_PREFER_WRITER 1

/* Define to 1 if the pthread_sigmask function can be used (despite bugs). */
#define HAVE_PTHREAD_SIGMASK 1

/* Define to 1 if the system has the type `pthread_spinlock_t'. */
/* #undef HAVE_PTHREAD_SPINLOCK_T */

/* Define to 1 if the system has the type `pthread_t'. */
#define HAVE_PTHREAD_T 1

/* Define to 1 if the system has the type `ptrdiff_t'. */
#define HAVE_PTRDIFF_T 1

/* Define to 1 if you have the <pwd.h> header file. */
#define HAVE_PWD_H 1

/* Define to 1 if you have the `raise' function. */
#define HAVE_RAISE 1

/* Define to 1 if you have the <random.h> header file. */
/* #undef HAVE_RANDOM_H */

/* Define to 1 if you have the `random_r' function. */
/* #undef HAVE_RANDOM_R */

/* Define to 1 if you have the `rawmemchr' function. */
/* #undef HAVE_RAWMEMCHR */

/* Define to 1 if you have the `readdir' function. */
/* #undef HAVE_READDIR */

/* Define to 1 if you have the `readlink' function. */
/* #undef HAVE_READLINK */

/* Define to 1 if you have the `readlinkat' function. */
/* #undef HAVE_READLINKAT */

/* Define to 1 if you have the `reallocarray' function. */
/* #undef HAVE_REALLOCARRAY */

/* Define to 1 if realloc (..., 0) returns nonnull. */
#define HAVE_REALLOC_0_NONNULL 1

/* Define if realloc sets errno on allocation failure. */
#define HAVE_REALLOC_POSIX 1

/* Define to 1 if you have the `realpath' function. */
/* #undef HAVE_REALPATH */

/* Define to 1 if you have the `renameat' function. */
/* #undef HAVE_RENAMEAT */

/* Define to 1 if you have the `renameat2' function. */
/* #undef HAVE_RENAMEAT2 */

/* Define to 1 if you have the `rewinddir' function. */
/* #undef HAVE_REWINDDIR */

/* Define to 1 if 'long double' and 'double' have the same representation. */
#define HAVE_SAME_LONG_DOUBLE_AS_DOUBLE 1

/* Define to 1 if the system has the type `sa_family_t'. */
/* #undef HAVE_SA_FAMILY_T */

/* Define to 1 if you have the `scandir' function. */
/* #undef HAVE_SCANDIR */

/* Define to 1 if you have the <sched.h> header file. */
#define HAVE_SCHED_H 1

/* Define to 1 if you have the `sched_setparam' function. */
/* #undef HAVE_SCHED_SETPARAM */

/* Define to 1 if you have the `sched_setscheduler' function. */
/* #undef HAVE_SCHED_SETSCHEDULER */

/* Define to 1 if you have the <sdkddkver.h> header file. */
/* #undef HAVE_SDKDDKVER_H */

/* Define to 1 if you have the <search.h> header file. */
/* #undef HAVE_SEARCH_H */

/* Define to 1 if you have the `secure_getenv' function. */
/* #undef HAVE_SECURE_GETENV */

/* Define to 1 if you have the `select' function. */
#define HAVE_SELECT 1

/* Define to 1 if you have the <selinux/selinux.h> header file. */
/* #undef HAVE_SELINUX_SELINUX_H */

/* Define to 1 if you have the <semaphore.h> header file. */
/* #undef HAVE_SEMAPHORE_H */

/* Define to 1 if you have the `setdtablesize' function. */
/* #undef HAVE_SETDTABLESIZE */

/* Define to 1 if you have the `setegid' function. */
/* #undef HAVE_SETEGID */

/* Define to 1 if you have the `setenv' function. */
/* #undef HAVE_SETENV */

/* Define to 1 if you have the `seteuid' function. */
/* #undef HAVE_SETEUID */

/* Define to 1 if you have the `setrlimit' function. */
#define HAVE_SETRLIMIT 1

/* Define to 1 if you have the `setstate' function. */
/* #undef HAVE_SETSTATE */

/* Define to 1 if you have the `shutdown' function. */
/* #undef HAVE_SHUTDOWN */

/* Define to 1 if you have the `sigaction' function. */
/* #undef HAVE_SIGACTION */

/* Define to 1 if you have the `sigaltstack' function. */
/* #undef HAVE_SIGALTSTACK */

/* Define to 1 if the system has the type `siginfo_t'. */
/* #undef HAVE_SIGINFO_T */

/* Define to 1 if you have the `siginterrupt' function. */
/* #undef HAVE_SIGINTERRUPT */

/* Define to 1 if 'sig_atomic_t' is a signed integer type. */
/* #undef HAVE_SIGNED_SIG_ATOMIC_T */

/* Define to 1 if 'wchar_t' is a signed integer type. */
/* #undef HAVE_SIGNED_WCHAR_T */

/* Define to 1 if 'wint_t' is a signed integer type. */
/* #undef HAVE_SIGNED_WINT_T */

/* Define to 1 if you have the `sigprocmask' function. */
#define HAVE_SIGPROCMASK 1

/* Define to 1 if the system has the type `sigset_t'. */
#define HAVE_SIGSET_T 1

/* Define to 1 if the system has the type `sig_atomic_t'. */
/* #undef HAVE_SIG_ATOMIC_T */

/* Define to 1 if you have the `sleep' function. */
/* #undef HAVE_SLEEP */

/* Define to 1 if libsmack is usable. */
/* #undef HAVE_SMACK */

/* Define to 1 if you have the `snprintf' function. */
#define HAVE_SNPRINTF 1

/* Define if the return value of the snprintf function is the number of of
   bytes (excluding the terminating NUL) that would have been produced if the
   buffer had been large enough. */
#define HAVE_SNPRINTF_RETVAL_C99 1

/* Define if the string produced by the snprintf function is always NUL
   terminated. */
#define HAVE_SNPRINTF_TRUNCATION_C99 1

/* Define if the locale_t type is as on Solaris 11.4. */
/* #undef HAVE_SOLARIS114_LOCALES */

/* Define to 1 if you have the <spawn.h> header file. */
/* #undef HAVE_SPAWN_H */

/* Define to 1 if you have the `statacl' function. */
/* #undef HAVE_STATACL */

/* Define to 1 if you have the <stdbit.h> header file. */
/* #undef HAVE_STDBIT_H */

/* Define to 1 if you have the <stdbool.h> header file. */
#define HAVE_STDBOOL_H 1

/* Define to 1 if you have the <stdckdint.h> header file. */
#define HAVE_STDCKDINT_H 1

/* Define to 1 if you have the <stdcountof.h> header file. */
#define HAVE_STDCOUNTOF_H 1

/* Define to 1 if you have the <stdint.h> header file. */
#define HAVE_STDINT_H 1

/* Define if <stdint.h> exists, doesn't clash with <sys/types.h>, and declares
   uintmax_t. */
#define HAVE_STDINT_H_WITH_UINTMAX 1

/* Define to 1 if you have the <stdio_ext.h> header file. */
/* #undef HAVE_STDIO_EXT_H */

/* Define to 1 if you have the <stdio.h> header file. */
#define HAVE_STDIO_H 1

/* Define to 1 if you have the <stdlib.h> header file. */
#define HAVE_STDLIB_H 1

/* Define to 1 if you have the `stpcpy' function. */
#define HAVE_STPCPY 1

/* Define if you have the stpncpy() function and it works. */
#define HAVE_STPNCPY 1

/* Define to 1 if you have the `strchrnul' function. */
#define HAVE_STRCHRNUL 1

/* Define to 1 if you have the `strcspn' function. */
/* #undef HAVE_STRCSPN */

/* Define to 1 if you have the `strerrorname_np' function. */
/* #undef HAVE_STRERRORNAME_NP */

/* Define to 1 if you have the `strerror_r' function. */
#define HAVE_STRERROR_R 1

/* Define to 1 if you have the <strings.h> header file. */
#define HAVE_STRINGS_H 1

/* Define to 1 if you have the <string.h> header file. */
#define HAVE_STRING_H 1

/* Define to 1 if you have the `strnlen' function. */
#define HAVE_STRNLEN 1

/* Define to 1 if you have the `strpbrk' function. */
/* #undef HAVE_STRPBRK */

/* Define to 1 if you have the `strtol' function. */
/* #undef HAVE_STRTOL */

/* Define to 1 if you have the `strtoul' function. */
/* #undef HAVE_STRTOUL */

/* Define to 1 if the system has the type `struct addrinfo'. */
/* #undef HAVE_STRUCT_ADDRINFO */

/* Define to 1 if `decimal_point' is a member of `struct lconv'. */
/* #undef HAVE_STRUCT_LCONV_DECIMAL_POINT */

/* Define to 1 if `int_p_cs_precedes' is a member of `struct lconv'. */
/* #undef HAVE_STRUCT_LCONV_INT_P_CS_PRECEDES */

/* Define to 1 if the system has the type `struct random_data'. */
/* #undef HAVE_STRUCT_RANDOM_DATA */

/* Define to 1 if `sa_sigaction' is a member of `struct sigaction'. */
/* #undef HAVE_STRUCT_SIGACTION_SA_SIGACTION */

/* Define to 1 if `sa_len' is a member of `struct sockaddr'. */
/* #undef HAVE_STRUCT_SOCKADDR_SA_LEN */

/* Define to 1 if the system has the type `struct sockaddr_storage'. */
/* #undef HAVE_STRUCT_SOCKADDR_STORAGE */

/* Define to 1 if `ss_family' is a member of `struct sockaddr_storage'. */
/* #undef HAVE_STRUCT_SOCKADDR_STORAGE_SS_FAMILY */

/* Define to 1 if `st_atimensec' is a member of `struct stat'. */
/* #undef HAVE_STRUCT_STAT_ST_ATIMENSEC */

/* Define to 1 if `st_atimespec.tv_nsec' is a member of `struct stat'. */
#define HAVE_STRUCT_STAT_ST_ATIMESPEC_TV_NSEC 1

/* Define to 1 if `st_atim.st__tim.tv_nsec' is a member of `struct stat'. */
/* #undef HAVE_STRUCT_STAT_ST_ATIM_ST__TIM_TV_NSEC */

/* Define to 1 if `st_atim.tv_nsec' is a member of `struct stat'. */
/* #undef HAVE_STRUCT_STAT_ST_ATIM_TV_NSEC */

/* Define to 1 if `st_birthtimensec' is a member of `struct stat'. */
/* #undef HAVE_STRUCT_STAT_ST_BIRTHTIMENSEC */

/* Define to 1 if `st_birthtimespec.tv_nsec' is a member of `struct stat'. */
#define HAVE_STRUCT_STAT_ST_BIRTHTIMESPEC_TV_NSEC 1

/* Define to 1 if `st_birthtim.tv_nsec' is a member of `struct stat'. */
/* #undef HAVE_STRUCT_STAT_ST_BIRTHTIM_TV_NSEC */

/* Define to 1 if you have the `symlink' function. */
#define HAVE_SYMLINK 1

/* Define to 1 if you have the `symlinkat' function. */
/* #undef HAVE_SYMLINKAT */

/* Define to 1 if you have the <sys/acl.h> header file. */
/* #undef HAVE_SYS_ACL_H */

/* Define to 1 if you have the <sys/bitypes.h> header file. */
/* #undef HAVE_SYS_BITYPES_H */

/* Define to 1 if you have the <sys/endian.h> header file. */
/* #undef HAVE_SYS_ENDIAN_H */

/* Define to 1 if you have the <sys/inttypes.h> header file. */
/* #undef HAVE_SYS_INTTYPES_H */

/* Define to 1 if you have the <sys/ioctl.h> header file. */
/* #undef HAVE_SYS_IOCTL_H */

/* Define to 1 if you have the <sys/mman.h> header file. */
#define HAVE_SYS_MMAN_H 1

/* Define to 1 if you have the <sys/param.h> header file. */
#define HAVE_SYS_PARAM_H 1

/* Define to 1 if you have the <sys/process.h> header file. */
/* #undef HAVE_SYS_PROCESS_H */

/* Define to 1 if you have the <sys/random.h> header file. */
/* #undef HAVE_SYS_RANDOM_H */

/* Define to 1 if you have the <sys/resource.h> header file. */
/* #undef HAVE_SYS_RESOURCE_H */

/* Define to 1 if you have the <sys/select.h> header file. */
/* #undef HAVE_SYS_SELECT_H */

/* Define to 1 if you have the <sys/single_threaded.h> header file. */
/* #undef HAVE_SYS_SINGLE_THREADED_H */

/* Define to 1 if you have the <sys/socket.h> header file. */
#define HAVE_SYS_SOCKET_H 1

/* Define to 1 if you have the <sys/stat.h> header file. */
#define HAVE_SYS_STAT_H 1

/* Define to 1 if you have the <sys/time.h> header file. */
#define HAVE_SYS_TIME_H 1

/* Define to 1 if you have the <sys/types.h> header file. */
#define HAVE_SYS_TYPES_H 1

/* Define to 1 if you have the <sys/uio.h> header file. */
/* #undef HAVE_SYS_UIO_H */

/* Define to 1 if you have the <sys/un.h> header file. */
/* #undef HAVE_SYS_UN_H */

/* Define to 1 if you have the <sys/wait.h> header file. */
/* #undef HAVE_SYS_WAIT_H */

/* Define to 1 if you have the `thrd_create' function. */
/* #undef HAVE_THRD_CREATE */

/* Define to 1 if you have the <threads.h> header file. */
/* #undef HAVE_THREADS_H */

/* Define if you have the timespec_get function. */
/* #undef HAVE_TIMESPEC_GET */

/* Define to 1 if you have the `towlower' function. */
#define HAVE_TOWLOWER 1

/* Define to 1 if you have the `tsearch' function. */
/* #undef HAVE_TSEARCH */

/* Define to 1 if you have the <uchar.h> header file. */
/* #undef HAVE_UCHAR_H */

/* Define to 1 if you have the <unistd.h> header file. */
#define HAVE_UNISTD_H 1

/* Define to 1 if you have the <unistring/woe32dll.h> header file. */
/* #undef HAVE_UNISTRING_WOE32DLL_H */

/* Define to 1 if <sys/socket.h> defines AF_UNIX. */
/* #undef HAVE_UNIXSOCKET */

/* Define to 1 if you have the `unlinkat' function. */
/* #undef HAVE_UNLINKAT */

/* Define to 1 if you have the `unsetenv' function. */
/* #undef HAVE_UNSETENV */

/* Define to 1 if the system has the type `unsigned long long int'. */
#define HAVE_UNSIGNED_LONG_LONG_INT 1

/* Define to 1 if you have the `uselocale' function. */
#define HAVE_USELOCALE 1

/* Define to 1 if you have the `usleep' function. */
/* #undef HAVE_USLEEP */

/* Define to 1 if you have the `utime' function. */
/* #undef HAVE_UTIME */

/* Define to 1 if you have the `utimens' function. */
/* #undef HAVE_UTIMENS */

/* Define to 1 if you have the `utimensat' function. */
/* #undef HAVE_UTIMENSAT */

/* Define to 1 if you have the <utime.h> header file. */
/* #undef HAVE_UTIME_H */

/* Define if you have a global __progname variable */
/* #undef HAVE_VAR___PROGNAME */

/* Define to 1 if you have the `vasnprintf' function. */
/* #undef HAVE_VASNPRINTF */

/* Define to 1 if you have the `vasprintf' function. */
#define HAVE_VASPRINTF 1

/* Define to 1 if you have the `vfork' function. */
/* #undef HAVE_VFORK */

/* Define to 1 or 0, depending whether the compiler supports simple visibility
   declarations. */
#define HAVE_VISIBILITY 1

/* Define to 1 if you have the `waitid' function. */
/* #undef HAVE_WAITID */

/* Define to 1 if you have the <wchar.h> header file. */
#define HAVE_WCHAR_H 1

/* Define to 1 if you have the `wcrtomb' function. */
#define HAVE_WCRTOMB 1

/* Define to 1 if you have the `wcslen' function. */
#define HAVE_WCSLEN 1

/* Define to 1 if you have the `wctob' function. */
/* #undef HAVE_WCTOB */

/* Define to 1 if you have the <wctype.h> header file. */
#define HAVE_WCTYPE_H 1

/* Define to 1 if you have the `wcwidth' function. */
#define HAVE_WCWIDTH 1

/* Define to 1 if the compiler and linker support weak declarations of
   symbols. */
/* #undef HAVE_WEAK_SYMBOLS */

/* Define to 1 if <locale.h> defines the _locale_t type. */
/* #undef HAVE_WINDOWS_LOCALE_T */

/* Define to 1 if you have the <winsock2.h> header file. */
/* #undef HAVE_WINSOCK2_H */

/* Define if you have the 'wint_t' type. */
#define HAVE_WINT_T 1

/* Define to 1 if you have the `wmempcpy' function. */
/* #undef HAVE_WMEMPCPY */

/* Define if the c32rtomb function basically works. */
/* #undef HAVE_WORKING_C32RTOMB */

/* Define to 1 if fstatat (..., 0) works. For example, it does not work in AIX
   7.1. */
/* #undef HAVE_WORKING_FSTATAT_ZERO_FLAG */

/* Define if the mbrtoc32 function basically works. */
/* #undef HAVE_WORKING_MBRTOC32 */

/* Define to 1 if O_DIRECTORY works, 0 otherwise. */
#define HAVE_WORKING_O_DIRECTORY 1

/* Define to 1 if O_NOATIME works, 0 otherwise. */
#define HAVE_WORKING_O_NOATIME 1

/* Define to 1 if O_NOFOLLOW works, 0 otherwise. */
#define HAVE_WORKING_O_NOFOLLOW 1

/* Define if the renameat2 function exists and it works. */
/* #undef HAVE_WORKING_RENAMEAT2 */

/* Define to 1 if the function strerrorname_np exists and works. */
/* #undef HAVE_WORKING_STRERRORNAME_NP */

/* Define if the uselocale function exists and may safely be called. */
/* #undef HAVE_WORKING_USELOCALE */

/* Define if utimes works properly. */
/* #undef HAVE_WORKING_UTIMES */

/* Define to 1 if you have the <ws2tcpip.h> header file. */
/* #undef HAVE_WS2TCPIP_H */

/* Define to 1 if you have the <xlocale.h> header file. */
#define HAVE_XLOCALE_H 1

/* Define to 1 if you have the `_chsize' function. */
/* #undef HAVE__CHSIZE */

/* Define to 1 if you have the `_fseeki64' function. */
/* #undef HAVE__FSEEKI64 */

/* Define to 1 if you have the `_ftelli64' function. */
/* #undef HAVE__FTELLI64 */

/* Define to 1 if you have the `_NSGetExecutablePath' function. */
/* #undef HAVE__NSGETEXECUTABLEPATH */

/* Define to 1 if you have the `_set_invalid_parameter_handler' function. */
/* #undef HAVE__SET_INVALID_PARAMETER_HANDLER */

/* Define to 1 if the compiler supports __builtin_expect,
   and to 2 if <builtins.h> does.  */
#define HAVE___BUILTIN_EXPECT 1
#ifndef HAVE___BUILTIN_EXPECT
# define __builtin_expect(e, c) (e)
#elif HAVE___BUILTIN_EXPECT == 2
# include <builtins.h>
#endif


/* Define to 1 if you have the `__fpurge' function. */
/* #undef HAVE___FPURGE */

/* Define to 1 if you have the `__freading' function. */
/* #undef HAVE___FREADING */

/* Define to 1 if you have the `__fseterr' function. */
/* #undef HAVE___FSETERR */

/* Define to 1 if ctype.h defines __header_inline. */
#define HAVE___HEADER_INLINE 1

/* Please see the Gnulib manual for how to use these macros.

   Suppress extern inline with HP-UX cc, as it appears to be broken; see
   <https://lists.gnu.org/r/bug-texinfo/2013-02/msg00030.html>.

   Suppress extern inline with Sun C in standards-conformance mode, as it
   mishandles inline functions that call each other.  E.g., for 'inline void f
   (void) { } inline void g (void) { f (); }', c99 incorrectly complains
   'reference to static identifier "f" in extern inline function'.
   This bug was observed with Oracle Developer Studio 12.6
   (Sun C 5.15 SunOS_sparc 2017/05/30).

   Suppress extern inline (with or without __attribute__ ((__gnu_inline__)))
   on configurations that mistakenly use 'static inline' to implement
   functions or macros in standard C headers like <ctype.h>.  For example,
   if isdigit is mistakenly implemented via a static inline function,
   a program containing an extern inline function that calls isdigit
   may not work since C99 through C23 prohibit extern inline functions
   from calling static functions (ISO C 23 § 6.7.5 ¶ 3)).
   Although a future C standard will likely relax this restriction
   <https://www.open-std.org/jtc1/sc22/wg14/www/docs/n3622.txt>,
   respect it for now.  This bug is known to occur on:

     OS X 10.8 and earlier; see:
     https://lists.gnu.org/r/bug-gnulib/2012-12/msg00023.html

     DragonFly; see
     http://muscles.dragonflybsd.org/bulk/clang-master-potential/20141111_102002/logs/ah-tty-0.3.12.log

     FreeBSD; see:
     https://lists.gnu.org/r/bug-gnulib/2014-07/msg00104.html

   OS X 10.9 has a macro __header_inline indicating the bug is fixed for C and
   for clang but remains for g++; see <https://trac.macports.org/ticket/41033>.
   Assume DragonFly and FreeBSD will be similar.

   GCC 4.3 and above with -std=c99 or -std=gnu99 implements ISO C99
   inline semantics, unless -fgnu89-inline is used.  It defines a macro
   __GNUC_STDC_INLINE__ to indicate this situation or a macro
   __GNUC_GNU_INLINE__ to indicate the opposite situation.
   GCC 4.2 with -std=c99 or -std=gnu99 implements the GNU C inline
   semantics but warns, unless -fgnu89-inline is used:
     warning: C99 inline functions are not supported; using GNU89
     warning: to disable this warning use -fgnu89-inline or the gnu_inline function attribute
   It defines a macro __GNUC_GNU_INLINE__ to indicate this situation.
 */
#if (((defined __APPLE__ && defined __MACH__) \
      || defined __DragonFly__ || defined __FreeBSD__) \
     && (defined HAVE___HEADER_INLINE \
         ? (defined __cplusplus && defined __GNUC_STDC_INLINE__ \
            && ! defined __clang__) \
         : ((! defined _DONT_USE_CTYPE_INLINE_ \
             && (defined __GNUC__ || defined __cplusplus)) \
            || (defined _FORTIFY_SOURCE && 0 < _FORTIFY_SOURCE \
                && defined __GNUC__ && ! defined __cplusplus))))
# define _GL_EXTERN_INLINE_STDHEADER_BUG
#endif
#if ((__GNUC__ \
      ? (defined __GNUC_STDC_INLINE__ && __GNUC_STDC_INLINE__ \
         && !defined __PCC__) \
      : (199901L <= __STDC_VERSION__ \
         && !defined __HP_cc \
         && !defined __PGI \
         && !(defined __SUNPRO_C && __STDC__))) \
     && !defined _GL_EXTERN_INLINE_STDHEADER_BUG)
# define _GL_INLINE inline
# define _GL_EXTERN_INLINE extern inline
# define _GL_EXTERN_INLINE_IN_USE
#elif (2 < __GNUC__ + (7 <= __GNUC_MINOR__) && !defined __STRICT_ANSI__ \
       && !defined __PCC__ \
       && !defined _GL_EXTERN_INLINE_STDHEADER_BUG)
# if defined __GNUC_GNU_INLINE__ && __GNUC_GNU_INLINE__
   /* __gnu_inline__ suppresses a GCC 4.2 diagnostic.  */
#  define _GL_INLINE extern inline __attribute__ ((__gnu_inline__))
# else
#  define _GL_INLINE extern inline
# endif
# define _GL_EXTERN_INLINE extern
# define _GL_EXTERN_INLINE_IN_USE
#else
# define _GL_INLINE _GL_UNUSED static
# define _GL_EXTERN_INLINE _GL_UNUSED static
#endif

/* In GCC 4.6 (inclusive) to 5.1 (exclusive),
   suppress bogus "no previous prototype for 'FOO'"
   and "no previous declaration for 'FOO'" diagnostics,
   when FOO is an inline function in the header; see
   <https://gcc.gnu.org/PR54113> and
   <https://gcc.gnu.org/PR63877>.  */
#if __GNUC__ == 4 && 6 <= __GNUC_MINOR__
# if defined __GNUC_STDC_INLINE__ && __GNUC_STDC_INLINE__
#  define _GL_INLINE_HEADER_CONST_PRAGMA
# else
#  define _GL_INLINE_HEADER_CONST_PRAGMA \
     _Pragma ("GCC diagnostic ignored \"-Wsuggest-attribute=const\"")
# endif
# define _GL_INLINE_HEADER_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wmissing-prototypes\"") \
    _Pragma ("GCC diagnostic ignored \"-Wmissing-declarations\"") \
    _GL_INLINE_HEADER_CONST_PRAGMA
# define _GL_INLINE_HEADER_END \
    _Pragma ("GCC diagnostic pop")
#else
# define _GL_INLINE_HEADER_BEGIN
# define _GL_INLINE_HEADER_END
#endif

/* Define to 1 if the compiler supports the keyword '__inline'. */
#define HAVE___INLINE 1

/* Define to 1 if you have the `__secure_getenv' function. */
/* #undef HAVE___SECURE_GETENV */

/* Define to 1 if you have the `__xpg_strerror_r' function. */
/* #undef HAVE___XPG_STRERROR_R */

/* Define as const if the declaration of iconv() needs const. */
#define ICONV_CONST 

/* Define to a symbolic name denoting the flavor of iconv_open()
   implementation. */
/* #undef ICONV_FLAVOR */

/* Define to the value of ${prefix}, as a string. */
#define INSTALLPREFIX "/Users/sedwards/gtk"

/* Define as the bit index in the word where to find bit 0 of the exponent of
   'long double'. */
#define LDBL_EXPBIT0_BIT 20

/* Define as the word index where to find the exponent of 'long double'. */
#define LDBL_EXPBIT0_WORD 1

/* Define as the bit index in the word where to find the sign of 'long
   double'. */
/* #undef LDBL_SIGNBIT_BIT */

/* Define as the word index where to find the sign of 'long double'. */
/* #undef LDBL_SIGNBIT_WORD */

/* Define if libxml is being used as a static library. */
/* #undef LIBXML_STATIC */

/* Define if localename.c overrides newlocale(), duplocale(), freelocale(). */
/* #undef LOCALENAME_ENHANCE_LOCALE_FUNCS */

/* Define to 1 if lseek does not detect pipes. */
/* #undef LSEEK_PIPE_BROKEN */

/* Define to 1 if 'lstat' dereferences a symlink specified with a trailing
   slash. */
#define LSTAT_FOLLOWS_SLASHED_SYMLINK 1

/* Define to the sub-directory where libtool stores uninstalled libraries. */
#define LT_OBJDIR ".libs/"

/* Define to a substitute value for mmap()'s MAP_ANONYMOUS flag. */
/* #undef MAP_ANONYMOUS */

/* Define if the mbrtoc32 function does not return (size_t) -2 for empty
   input. */
/* #undef MBRTOC32_EMPTY_INPUT_BUG */

/* Define if the mbrtoc32 function may signal encoding errors in the C locale.
   */
/* #undef MBRTOC32_IN_C_LOCALE_MAYBE_EILSEQ */

/* Define if the mbrtoc32 function does not accept the input bytes one-by-one.
   */
/* #undef MBRTOC32_MULTIBYTE_LOCALE_BUG */

/* Define if the mbrtowc function does not return (size_t) -2 for empty input.
   */
/* #undef MBRTOWC_EMPTY_INPUT_BUG */

/* Define if the mbrtowc function may signal encoding errors in the C locale.
   */
/* #undef MBRTOWC_IN_C_LOCALE_MAYBE_EILSEQ */

/* Define if the mbrtowc function has the NULL pwc argument bug. */
/* #undef MBRTOWC_NULL_ARG1_BUG */

/* Define if the mbrtowc function does not return 0 for a NUL character. */
/* #undef MBRTOWC_NUL_RETVAL_BUG */

/* Define if the mbrtowc function returns a wrong return value. */
/* #undef MBRTOWC_RETVAL_BUG */

/* Define if the mbrtowc function stores a wide character when reporting
   incomplete input. */
/* #undef MBRTOWC_STORES_INCOMPLETE_BUG */

/* Use GNU style printf and scanf.  */
#ifndef __USE_MINGW_ANSI_STDIO
# define __USE_MINGW_ANSI_STDIO 1
#endif


/* Define to 1 if the encoding of NaN 'double's is as in IEEE 754-2008 §
   6.2.1. */
/* #undef MIPS_NAN2008_DOUBLE */

/* Define to 1 if the encoding of NaN 'float's is as in IEEE 754-2008 §
   6.2.1. */
/* #undef MIPS_NAN2008_FLOAT */

/* Define to 1 if the encoding of NaN 'long double's is as in IEEE 754-2008 §
   6.2.1. */
/* #undef MIPS_NAN2008_LONG_DOUBLE */

/* Define to 1 if mkfifo does not reject trailing slash */
/* #undef MKFIFO_TRAILING_SLASH_BUG */

/* Define to 1 on musl libc. */
/* #undef MUSL_LIBC */

/* Define if the vasnprintf implementation needs special code for the 'a' and
   'A' directives. */
/* #undef NEED_PRINTF_DIRECTIVE_A */

/* Define if the vasnprintf implementation needs special code for the 'b'
   directive. */
/* #undef NEED_PRINTF_DIRECTIVE_B */

/* Define if the vasnprintf implementation needs special code for the 'F'
   directive. */
/* #undef NEED_PRINTF_DIRECTIVE_F */

/* Define if the vasnprintf implementation needs special code for the 'lc'
   directive. */
/* #undef NEED_PRINTF_DIRECTIVE_LC */

/* Define if the vasnprintf implementation needs special code for the 'ls'
   directive. */
/* #undef NEED_PRINTF_DIRECTIVE_LS */

/* Define if the vasnprintf implementation needs special code for 'double'
   arguments. */
/* #undef NEED_PRINTF_DOUBLE */

/* Define if the vasnprintf implementation needs special code for surviving
   out-of-memory conditions. */
/* #undef NEED_PRINTF_ENOMEM */

/* Define if the vasnprintf implementation needs special code for the # flag
   with a zero precision and a zero value in the 'x' and 'X' directives. */
/* #undef NEED_PRINTF_FLAG_ALT_PRECISION_ZERO */

/* Define if the vasnprintf implementation needs special code for the ' flag.
   */
/* #undef NEED_PRINTF_FLAG_GROUPING */

/* Define if the vasnprintf implementation needs special code for the ' flag,
   for integer directives only. */
/* #undef NEED_PRINTF_FLAG_GROUPING_INT */

/* Define if the vasnprintf implementation needs special code for the '-'
   flag. */
/* #undef NEED_PRINTF_FLAG_LEFTADJUST */

/* Define if the vasnprintf implementation needs special code for the 0 flag.
   */
/* #undef NEED_PRINTF_FLAG_ZERO */

/* Define if the vasnprintf implementation needs special code for infinite
   'double' arguments. */
/* #undef NEED_PRINTF_INFINITE_DOUBLE */

/* Define if the vasnprintf implementation needs special code for infinite
   'long double' arguments. */
/* #undef NEED_PRINTF_INFINITE_LONG_DOUBLE */

/* Define if the vasnprintf implementation needs special code for 'long
   double' arguments. */
/* #undef NEED_PRINTF_LONG_DOUBLE */

/* Define if the vasnprintf implementation needs special code for supporting
   large precisions without arbitrary bounds. */
/* #undef NEED_PRINTF_UNBOUNDED_PRECISION */

/* Define to 1 if realloc should abort upon undefined behaviour. */
/* #undef NEED_SANITIZED_REALLOC */

/* Define to 1 to enable general improvements of setlocale. */
/* #undef NEED_SETLOCALE_IMPROVED */

/* Define to 1 to enable a thread safety fix of setlocale. */
/* #undef NEED_SETLOCALE_MTSAFE */

/* Define to 1 if nl_langinfo is thread-safe. */
#define NL_LANGINFO_MTSAFE 0

/* Define to 1 if open() fails to recognize a trailing slash. */
/* #undef OPEN_TRAILING_SLASH_BUG */

/* Name of package */
#define PACKAGE "gettext-tools"

/* Define to the address where bug reports for this package should be sent. */
#define PACKAGE_BUGREPORT "bug-gettext@gnu.org"

/* Define to the full name of this package. */
#define PACKAGE_NAME "gettext-tools"

/* Define to the full name and version of this package. */
#define PACKAGE_STRING "gettext-tools 1.0"

/* Define to the suffix of the directory name for version-specific data files.
   */
#define PACKAGE_SUFFIX "-1.0"

/* Define to the one symbol short name of this package. */
#define PACKAGE_TARNAME "gettext-tools"

/* Define to the home page for this package. */
#define PACKAGE_URL ""

/* Define to the version of this package. */
#define PACKAGE_VERSION "1.0"

/* Define to the type that is the result of default argument promotions of
   type mode_t. */
#define PROMOTED_MODE_T int

/* Define if pthread_create is an inline function. */
/* #undef PTHREAD_CREATE_IS_INLINE */

/* Define if the pthread_in_use() detection is hard. */
/* #undef PTHREAD_IN_USE_DETECTION_HARD */

/* Define if the 'robust' attribute of pthread_mutex* doesn't exist. */
/* #undef PTHREAD_MUTEXATTR_ROBUST_UNIMPLEMENTED */

/* Define if the pthread_rwlock wait queue handling is not reasonable. */
/* #undef PTHREAD_RWLOCK_BAD_WAITQUEUE */

/* Define if the functions pthread_rwlock_timedrdlock and
   pthread_rwlock_timedwrlock don't exist. */
/* #undef PTHREAD_RWLOCK_LACKS_TIMEOUT */

/* Define if all pthread_rwlock* functions don't exist. */
/* #undef PTHREAD_RWLOCK_UNIMPLEMENTED */

/* Define to 1 if pthread_sigmask(), when it fails, returns -1 and sets errno.
   */
/* #undef PTHREAD_SIGMASK_FAILS_WITH_ERRNO */

/* Define to 1 if pthread_sigmask may return 0 and have no effect. */
/* #undef PTHREAD_SIGMASK_INEFFECTIVE */

/* Define to 1 if pthread_sigmask requires linking with some library. */
/* #undef PTHREAD_SIGMASK_NOT_IN_LIBC */

/* Define to l, ll, u, ul, ull, etc., as suitable for constants of type
   'ptrdiff_t'. */
/* #undef PTRDIFF_T_SUFFIX */

/* Define to 1 if readlink fails to recognize a trailing slash. */
/* #undef READLINK_TRAILING_SLASH_BUG */

/* Define to 1 if readlink sets errno instead of truncating a too-long link.
   */
/* #undef READLINK_TRUNCATE_BUG */

/* Define if rename does not work when the destination file exists, as on
   Cygwin 1.5 or Windows. */
/* #undef RENAME_DEST_EXISTS_BUG */

/* Define if rename fails to leave hard links alone, as on NetBSD 1.6 or
   Cygwin 1.5. */
/* #undef RENAME_HARD_LINK_BUG */

/* Define if rename does not correctly handle slashes on the destination
   argument, such as on Solaris 11 or NetBSD 1.6. */
/* #undef RENAME_TRAILING_SLASH_DEST_BUG */

/* Define if rename does not correctly handle slashes on the source argument,
   such as on Solaris 9 or cygwin 1.5. */
/* #undef RENAME_TRAILING_SLASH_SOURCE_BUG */

/* Define to 1 if gnulib's fchdir() replacement is used. */
/* #undef REPLACE_FCHDIR */

/* Define to 1 if stat needs help when passed a file name with a trailing
   slash */
/* #undef REPLACE_FUNC_STAT_FILE */

/* Define to 1 if utime needs help when passed a file name with a trailing
   slash */
/* #undef REPLACE_FUNC_UTIME_FILE */

/* Define if nl_langinfo exists but is overridden by gnulib. */
#define REPLACE_NL_LANGINFO 1

/* Define to 1 if open() should work around the inability to open a directory.
   */
/* #undef REPLACE_OPEN_DIRECTORY */

/* Define if gnulib uses its own posix_spawn and posix_spawnp functions. */
/* #undef REPLACE_POSIX_SPAWN */

/* Define to 1 if strerror(0) does not return a message implying success. */
#define REPLACE_STRERROR_0 1

/* Define if vasnprintf exists but is overridden by gnulib. */
/* #undef REPLACE_VASNPRINTF */

/* Define to 1 if setlocale (LC_ALL, NULL) is thread-safe. */
#define SETLOCALE_NULL_ALL_MTSAFE 0

/* Define to 1 if setlocale (category, NULL) is thread-safe. */
#define SETLOCALE_NULL_ONE_MTSAFE 1

/* File name of the Bourne shell.  */
#if (defined _WIN32 && !defined __CYGWIN__) || defined __CYGWIN__ || defined __ANDROID__
/* Omit the directory part because
   - For native Windows programs in a Cygwin environment, the Cygwin mounts
     are not visible.
   - For 32-bit Cygwin programs in a 64-bit Cygwin environment, the Cygwin
     mounts are not visible.
   - On Android, /bin/sh does not exist. It's /system/bin/sh instead.  */
# define BOURNE_SHELL "sh"
#else
# define BOURNE_SHELL "/bin/sh"
#endif

/* Define if lists must be signal-safe. */
/* #undef SIGNAL_SAFE_LIST */

/* Define to l, ll, u, ul, ull, etc., as suitable for constants of type
   'sig_atomic_t'. */
/* #undef SIG_ATOMIC_T_SUFFIX */

/* Define as the maximum value of type 'size_t', if the system doesn't define
   it. */
#ifndef SIZE_MAX
/* # undef SIZE_MAX */
#endif

/* Define to l, ll, u, ul, ull, etc., as suitable for constants of type
   'size_t'. */
/* #undef SIZE_T_SUFFIX */

/* If using the C implementation of alloca, define if you know the
   direction of stack growth for your system; otherwise it will be
   automatically deduced at runtime.
	STACK_DIRECTION > 0 => grows toward higher addresses
	STACK_DIRECTION < 0 => grows toward lower addresses
	STACK_DIRECTION = 0 => direction of growth unknown */
/* #undef STACK_DIRECTION */

/* Define to 1 if the `S_IS*' macros in <sys/stat.h> do not work properly. */
/* #undef STAT_MACROS_BROKEN */

/* Define to 1 if all of the C90 standard headers exist (not just the ones
   required in a freestanding environment). This macro is provided for
   backward compatibility; new code need not use it. */
#define STDC_HEADERS 1

/* Define to 1 if strerror_r returns char *. */
/* #undef STRERROR_R_CHAR_P */

/* Define to 1 if the type of the st_atim member of a struct stat is struct
   timespec. */
/* #undef TYPEOF_STRUCT_STAT_ST_ATIM_IS_STRUCT_TIMESPEC */

/* Define to 1 if unlink (dir) cannot possibly succeed. */
/* #undef UNLINK_CANNOT_UNLINK_DIR */

/* Define to 1 if unlink() on a parent directory may succeed */
/* #undef UNLINK_PARENT_BUG */

/* Define to the prefix of C symbols at the assembler and linker level, either
   an underscore or empty. */
#define USER_LABEL_PREFIX _

/* Define to nonzero if you want access control list support. */
/* #undef USE_ACL */

/* Define if the combination of the ISO C and POSIX multithreading APIs can be
   used. */
/* #undef USE_ISOC_AND_POSIX_THREADS */

/* Define if the ISO C multithreading library can be used. */
/* #undef USE_ISOC_THREADS */

/* Define to enable the declarations of ISO C 23 Annex K types and functions.  */
#if !(defined __STDC_WANT_LIB_EXT1__ && __STDC_WANT_LIB_EXT1__)
#undef/**/__STDC_WANT_LIB_EXT1__
#define __STDC_WANT_LIB_EXT1__ 1
#endif


/* Define if the POSIX multithreading library can be used. */
#define USE_POSIX_THREADS 1

/* Define if references to the POSIX multithreading library are satisfied by
   libc. */
/* #undef USE_POSIX_THREADS_FROM_LIBC */

/* Define if references to the POSIX multithreading library should be made
   weak. */
/* #undef USE_POSIX_THREADS_WEAK */

/* Define to 1 if <selinux/selinux.h> should be used, to 0 otherwise. */
/* #undef USE_SELINUX_SELINUX_H */

/* Enable extensions on AIX 3, Interix.  */
#ifndef _ALL_SOURCE
# define _ALL_SOURCE 1
#endif
/* Enable general extensions on macOS.  */
/* DARWIN_PORTING_SHIM */
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <fcntl.h>

/* Gnulib Common Macros & Attributes */
#ifndef _GL_ATTRIBUTE_ALLOC_SIZE
# define _GL_ATTRIBUTE_ALLOC_SIZE(x)
#endif
#ifndef _GL_ATTRIBUTE_RETURNS_NONNULL
# define _GL_ATTRIBUTE_RETURNS_NONNULL
#endif
#ifndef _GL_ATTRIBUTE_PURE
# define _GL_ATTRIBUTE_PURE
#endif
#ifndef _GL_ATTRIBUTE_CONST
# define _GL_ATTRIBUTE_CONST
#endif
#ifndef _GL_ATTRIBUTE_MALLOC
# define _GL_ATTRIBUTE_MALLOC
#endif
#ifndef _GL_ATTRIBUTE_NODISCARD
# define _GL_ATTRIBUTE_NODISCARD
#endif
#ifndef _GL_ATTRIBUTE_COLD
# define _GL_ATTRIBUTE_COLD
#endif
#ifndef _GL_ATTRIBUTE_NONNULL
# define _GL_ATTRIBUTE_NONNULL(x)
#endif
#ifndef _GL_ATTRIBUTE_NONNULL_IF_NONZERO
# define _GL_ATTRIBUTE_NONNULL_IF_NONZERO(x, y)
#endif
#ifndef _GL_UNUSED
# define _GL_UNUSED
#endif
#ifndef _GL_GNUC_PREREQ
# if defined __GNUC__ && defined __GNUC_MINOR__
#  define _GL_GNUC_PREREQ(maj, min) ((maj) < __GNUC__ || ((maj) == __GNUC__ && (min) <= __GNUC_MINOR__))
# else
#  define _GL_GNUC_PREREQ(maj, min) 0
# endif
#endif

/* Missing GNU Macros */
#ifndef streq
# define streq(a, b) (strcmp (a, b) == 0)
#endif
#ifndef memeq
# define memeq(a, b, n) (memcmp (a, b, n) == 0)
#endif
#ifndef EXIT_FAILURE
# define EXIT_FAILURE 1
#endif
#ifndef VERSION
# define VERSION "1.0"
#endif
#ifndef PACKAGE
# define PACKAGE "gettext"
#endif
#ifndef DLL_VARIABLE
# define DLL_VARIABLE
#endif

/* Gnulib Memory Wrappers */
static inline void *xmalloc(size_t n) { 
    void *p = malloc(n); if (!p && n) abort(); return p; 
}
static inline void *xrealloc(void *p, size_t n) { 
    void *r = realloc(p, n); if (!r && n) abort(); return r; 
}
#ifndef XNMALLOC
# define XNMALLOC(n, t) ((t *) xmalloc ((n) * sizeof (t)))
#endif

/* POSIX / Darwin IO Compatibility */
#ifndef O_BINARY
# define O_BINARY 0
#endif

/* Missing GNU Constants */
#ifndef GNULIB_LOCALEDIR
# define GNULIB_LOCALEDIR "/share/locale"
#endif

/* Standard Function Declarations (Force C Linkage) */
#ifdef __cplusplus
extern "C" {
#endif
  void error(int status, int errnum, const char *format, ...);
  void error_at_line(int status, int errnum, const char *fname, unsigned int lineno, const char *format, ...);
  void *reallocarray(void *ptr, size_t nmemb, size_t size);
  
  static inline void *memrchr(const void *s, int c, size_t n) {
      const unsigned char *cp = (const unsigned char *) s + n;
      while (n--) if (*--cp == (unsigned char) c) return (void *) cp;
      return 0;
  }
#ifdef __cplusplus
}
#endif

#ifndef HAVE_MEMRCHR
# define HAVE_MEMRCHR 1
#endif
#ifndef HAVE_REALLOCARRAY
# define HAVE_REALLOCARRAY 1
#endif

/* Darwin Environment */
#ifndef __environ
# include <crt_externs.h>
# define environ (*_NSGetEnviron())
#endif
#undef xmalloc
#undef xrealloc

#undef xmalloc
#undef xrealloc

