# CMakeLists.txt for project THEMIS

cmake_minimum_required(VERSION 3.10)
project(themis CXX)
set(CMAKE_VERBOSE_MAKEFILE 1)

enable_language(CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


add_library(themis INTERFACE)

set(THEMIS_HEADERS
  exception.h
  inttype.h
  noncopyable.h
)


install(TARGETS themis
  EXPORT themis-export
#  ARCHIVE DESTINATION lib
  INCLUDES DESTINATION include
#  PUBLIC_HEADER DESTINATION include/themis
)

install(EXPORT themis-export
  FILE themis-config.cmake
  DESTINATION share/cmake/themis/
#  EXPORT_LINK_INTERFACE_LIBRARIES
)

install(FILES
    ${THEMIS_HEADERS}
  DESTINATION
    include/themis
)


#eof
