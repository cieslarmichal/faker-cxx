cmake_minimum_required(VERSION 3.16)

project(faker VERSION 0.0.1)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(scripts/cmake/ClangFormat.cmake)
include(scripts/cmake/SafetyFeatures.cmake)

enable_testing()

add_library(faker STATIC)
target_include_directories(
    faker
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)
target_link_libraries(
    faker
    PUBLIC
        fmt::fmt
)
turn_on_warnings(faker)

add_subdirectory(externals)
add_subdirectory(src)
add_subdirectory(tests)