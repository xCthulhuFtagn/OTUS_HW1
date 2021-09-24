cmake_minimum_required(VERSION 3.0)

project(Library VERSION 0.0.1)

add_library(lib STATIC lib.h lib.cpp)

set_target_properties(
    lib PROPERTIES
    CXX_VERSION 11
    CXX_VERSION_REQUIRED ON
)

target_include_directories(
    lib
    PRIVATE
    {CMAKE_CURRENT_BINARY_DIR}
)