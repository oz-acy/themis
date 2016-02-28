# CMakeLists.txt for project THEMIS

CMAKE_MINIMUM_REQUIRED(VERSION 3.1)
SET(CMAKE_VERBOSE_MAKEFILE 1)

#PROJECT(themis CXX)

SET(CMAKE_CXX_COMPILER /usr/bin/x86_64-w64-mingw32-clang++)
SET(CMAKE_CXX_FLAGS "-Wall -std=c++14 -O3")

ADD_LIBRARY(themis STATIC
  strconv.cpp
  strconv_tolower.cpp
  wstrconv_tolower.cpp
)

INSTALL(TARGETS themis DESTINATION lib)
INSTALL(FILES
    except.h
    inttype.h
    listen.h
    strconv.h
  DESTINATION
    include/themis
)


#eof
