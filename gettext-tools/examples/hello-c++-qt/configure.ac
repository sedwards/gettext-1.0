dnl Example for use of GNU gettext.
dnl This file is in the public domain.
dnl
dnl Configuration file - processed by autoconf.

AC_INIT([hello-c++-qt], [0], , [hello-c++-qt])
m4_pattern_allow([_LT_ENABLE_SHARED_DEFAULT])
m4_pattern_allow([_LT_ENABLE_STATIC_DEFAULT])
m4_pattern_allow([_LT_ENABLE_FAST_INSTALL_DEFAULT])
m4_pattern_allow([_LT_WITH_AIX_SONAME_DEFAULT])
m4_ifndef([_LT_ENABLE_SHARED_DEFAULT], [m4_define([_LT_ENABLE_SHARED_DEFAULT], [yes])])
m4_ifndef([_LT_ENABLE_STATIC_DEFAULT], [m4_define([_LT_ENABLE_STATIC_DEFAULT], [yes])])
m4_ifndef([_LT_ENABLE_FAST_INSTALL_DEFAULT], [m4_define([_LT_ENABLE_FAST_INSTALL_DEFAULT], [yes])])
m4_ifndef([_LT_WITH_AIX_SONAME_DEFAULT], [m4_define([_LT_WITH_AIX_SONAME_DEFAULT], [maybe])])
AC_CONFIG_SRCDIR([hello.cc])
AM_INIT_AUTOMAKE([1.11])

AC_PROG_CXX
FUN_TYPE_BOOL
FUN_HEADER_STDCXX
FUN_CHECK_PTHREAD
FUN_CHECK_QT(220)

dnl Support for the po directory.
AM_PO_SUBDIRS

AC_CONFIG_FILES([Makefile])
AC_CONFIG_FILES([m4/Makefile])
AC_CONFIG_FILES([po/Makefile], [AM_POSTPROCESS_PO_MAKEFILE])
AC_OUTPUT
