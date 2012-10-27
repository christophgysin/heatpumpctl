cmake_minimum_required(VERSION 2.8)
project(heatpumpctl)

include(cmake/dependencies.cmake)
include(cmake/testing.cmake)

set(CMAKE_INSTALL_PREFIX /usr)
set(CMAKE_BUILD_TYPE Release)

set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG -g -O0)
set(CMAKE_CXX_FLAGS_RELEASE -O2)

add_subdirectory(src)
