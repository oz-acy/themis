#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([Themis],[0.2.1],[acy@hiemalis.org])
AC_CONFIG_SRCDIR([config.h.in])
AC_CONFIG_HEADERS([config.h])
AM_INIT_AUTOMAKE

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC
AC_PROG_RANLIB


# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADER([iconv.h],[], [AC_MSG_ERROR(iconv.h is not found.)])

# Checks for typedefs, structures, and compiler characteristics.
AC_C_CONST
AC_C_INLINE
AC_TYPE_SIZE_T


# Checks for library functions.


# ==== check others ================================================

AC_MSG_CHECKING([type check of iconv()'s 2nd arg in C])
iconv_2nd_arg='char**'
AC_COMPILE_IFELSE(
[AC_LANG_PROGRAM([[#include <iconv.h>]],
[[
iconv_t cv;
const char* ip;
size_t il;
char* op;
size_t ol;
iconv(cv, &ip, &il, &op, &ol);
]])],
[CFLAGS="-DICONV_CONST='const' $CFLAGS" iconv_2nd_arg='const char**'],
[CFLAGS="-DICONV_CONST='' $CFLAGS" iconv_2nd_arg='char**'])
AC_MSG_RESULT([$iconv_2nd_arg])





AC_LANG_PUSH(C++)

AC_MSG_CHECKING([type check of iconv()'s 2nd arg in C++])
iconv_2nd_arg='char**'
AC_COMPILE_IFELSE(
[AC_LANG_PROGRAM([[#include <iconv.h>]],
[[
iconv_t cv;
const char* ip;
size_t il;
char* op;
size_t ol;
iconv(cv, &ip, &il, &op, &ol);
]])],
[CXXFLAGS="-DICONV_CONST='const' $CXXFLAGS" iconv_2nd_arg='const char**'],
[CXXFLAGS="-DICONV_CONST='' $CXXFLAGS" iconv_2nd_arg='char**'])
AC_MSG_RESULT([$iconv_2nd_arg])

AC_MSG_CHECKING([checking for std::wstring])
iswstring=no
AC_COMPILE_IFELSE(
[AC_LANG_PROGRAM([[#include <string>]], [[std::wstring ws;]])],
[CXXFLAGS="-DHAVE_STD_WSTRING $CXXFLAGS" iswstring=yes],
[])
AC_MSG_RESULT([$iswstring])

AC_LANG_POP()




# output
AC_CONFIG_FILES([Makefile])
AC_OUTPUT
