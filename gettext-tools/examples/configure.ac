dnl Configuration for the gettext-tools/examples directory of GNU gettext
dnl Copyright (C) 2006-2025 Free Software Foundation, Inc.
dnl
dnl This program is free software: you can redistribute it and/or modify
dnl it under the terms of the GNU General Public License as published by
dnl the Free Software Foundation; either version 3 of the License, or
dnl (at your option) any later version.
dnl
dnl This program is distributed in the hope that it will be useful,
dnl but WITHOUT ANY WARRANTY; without even the implied warranty of
dnl MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
dnl GNU General Public License for more details.
dnl
dnl You should have received a copy of the GNU General Public License
dnl along with this program.  If not, see <https://www.gnu.org/licenses/>.

dnl Process this file with autoconf to produce a configure script.

AC_PREREQ([2.64])
AC_INIT([gettext], [package], [bug-gettext@gnu.org])
m4_pattern_allow([_LT_ENABLE_SHARED_DEFAULT])
m4_pattern_allow([_LT_ENABLE_STATIC_DEFAULT])
m4_pattern_allow([_LT_ENABLE_FAST_INSTALL_DEFAULT])
m4_pattern_allow([_LT_WITH_AIX_SONAME_DEFAULT])
m4_ifndef([_LT_ENABLE_SHARED_DEFAULT], [m4_define([_LT_ENABLE_SHARED_DEFAULT], [yes])])
m4_ifndef([_LT_ENABLE_STATIC_DEFAULT], [m4_define([_LT_ENABLE_STATIC_DEFAULT], [yes])])
m4_ifndef([_LT_ENABLE_FAST_INSTALL_DEFAULT], [m4_define([_LT_ENABLE_FAST_INSTALL_DEFAULT], [yes])])
m4_ifndef([_LT_WITH_AIX_SONAME_DEFAULT], [m4_define([_LT_WITH_AIX_SONAME_DEFAULT], [maybe])])
AC_CONFIG_SRCDIR([installpaths.in])
AC_CONFIG_AUX_DIR([../../build-aux])
VERSION_NUMBER=`cd $srcdir/../.. \
                && build-aux/git-version-gen .tarball-version`
gl_INIT_PACKAGE_VERSION([$VERSION_NUMBER])
AM_INIT_AUTOMAKE([silent-rules])

dnl Installation directories.
test "$docdir" != '${datarootdir}/doc/${PACKAGE_TARNAME}' || docdir='${datarootdir}/doc/gettext'

AM_PO_SUBDIRS

aclocaldir='${datadir}/aclocal'
AC_SUBST([aclocaldir])

AC_CONFIG_FILES([Makefile],
                [FIX_MAKEFILE_TOPDIR_DISTRIB])
AC_CONFIG_FILES([installpaths])
AC_CONFIG_FILES([po/Makefile], [AM_POSTPROCESS_PO_MAKEFILE])

AC_OUTPUT
