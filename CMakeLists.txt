cmake_minimum_required(VERSION 2.8)
project(heatpumpctl)

include(cmake/dependencies.cmake)
include(cmake/testing.cmake)

set(CMAKE_INSTALL_PREFIX /usr)
set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0")
set(CMAKE_CXX_FLAGS_RELEASE "-O2")

set(LIB_SERIAL serial)
add_subdirectory(lib)
include_directories(lib)
add_subdirectory(src)
add_subdirectory(test)
