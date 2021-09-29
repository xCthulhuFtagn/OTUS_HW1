cmake_minimum_required(VERSION 3.0)

project(IP_sort VERSION 0.0.1)

add_subdirectory(lib)
add_subdirectory(src)

enable_testing()

SET(CPACK_GENERATOR "DEB")
SET(CPACK_DEBIAN_PACKAGE_MAINTAINER "KK") #required
INCLUDE(CPack)
