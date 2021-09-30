cmake_minimum_required(VERSION 3.0)

set(PATCH_VERSION CACHE INTERNAL "Patch version")
set(PROJECT_VERSION 0.0.${PATCH_VERSION})
project(MAIN VERSION ${PROJECT_VERSION})

configure_file(config.h.in ${CMAKE_CURRENT_BINARY_DIR}/config.h)

add_executable(main main.cpp)

set_target_properties(
    main PROPERTIES
    CXX_VERSION 11
    CXX_VERSION_REQUIREMENTS ON
)

target_include_directories(
    main
    PRIVATE
    ${CMAKE_CURRENT_BINARY_DIR}
)

target_include_directories(
    main
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../lib
)

target_link_libraries(main lib)
