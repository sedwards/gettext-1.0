dnl Example for use of GNU gettext.
dnl This file is in the public domain.
dnl
dnl Configuration file - processed by autoconf.

AC_INIT([hello-c++-gnome3], [0], , [hello-c++-gnome3])
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

AC_PROG_CC
AC_PROG_CXX
AM_GNU_GETTEXT([external])
AM_GNU_GETTEXT_VERSION([1.0])

dnl Define localedir_c and localedir_c_make.
gl_BUILD_TO_HOST_LOCALEDIR

dnl Check GNOME specific stuff.
dnl
dnl If you have full GNOME development environment installed on your
dnl system, you should be able to use the following macros:
dnl
dnl   AM_PATH_GLIB_2_0
dnl   PKG_CHECK_MODULES([GTK], [gtk+-3.0 >= 3.10], ,
dnl     [AC_MSG_ERROR([can't find gtk+-3.0])])
dnl
dnl Here, in gettext-tools/examples, we do the checks manually for
dnl simplicity.

AC_PATH_PROG([GLIB_COMPILE_RESOURCES], [glib-compile-resources])
AS_IF([test -z "$GLIB_COMPILE_RESOURCES"], [
  AC_MSG_ERROR([can't find glib-compile-resources])
])

AC_PATH_PROG([PKG_CONFIG], [pkg-config])
AS_IF([test -z "$PKG_CONFIG"], [
  AC_MSG_ERROR([can't find pkg-config])
])

GTKMM="gtkmm-3.0 >= 3.0"
AS_IF(["$PKG_CONFIG" --exists "$GTKMM"], , [
  AC_MSG_ERROR([can't find $GTKMM])
])

GTKMM_CFLAGS=`"$PKG_CONFIG" --cflags "$GTKMM"`
AC_SUBST([GTKMM_CFLAGS])

GTKMM_LIBS=`"$PKG_CONFIG" --libs "$GTKMM"`
AC_SUBST([GTKMM_LIBS])

AC_CONFIG_FILES([Makefile])
AC_CONFIG_FILES([m4/Makefile])
AC_CONFIG_FILES([po/Makefile.in])
AC_OUTPUT
