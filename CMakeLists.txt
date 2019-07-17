# CMakeLists.txt for project THEMIS

CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
SET(CMAKE_VERBOSE_MAKEFILE 1)
PROJECT(themis CXX)

SET(CMAKE_CXX_FLAGS "-Wall -std=c++17 -O3")

ADD_LIBRARY(themis INTERFACE)

SET(THEMIS_HEADERS
  except.h
  inttype.h
)


INSTALL(TARGETS themis
  EXPORT themis-export
#  ARCHIVE DESTINATION lib
  INCLUDES DESTINATION include
#  PUBLIC_HEADER DESTINATION include/themis
)

INSTALL(EXPORT themis-export
  FILE themis-config.cmake
  DESTINATION share/cmake/themis/
#  EXPORT_LINK_INTERFACE_LIBRARIES
)

INSTALL(FILES
    ${THEMIS_HEADERS}
  DESTINATION
    include/themis
)


#eof
