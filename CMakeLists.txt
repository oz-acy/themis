# CMakeLists.txt for project THEMIS

CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
SET(CMAKE_VERBOSE_MAKEFILE 1)

#PROJECT(themis CXX)

SET(CMAKE_CXX_FLAGS "-Wall -std=c++17 -O3")
#SET(CMAKE_CXX_FLAGS "-Wall -std=c++14 -O3")
#SET(CMAKE_CXX_FLAGS "-Wall -std=c++11 -O3")
include_directories("${CMAKE_INSTALL_PREFIX}/include")

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
