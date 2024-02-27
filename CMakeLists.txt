cmake_minimum_required(VERSION 3.16)

project(faker VERSION 0.0.1)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(scripts/cmake/ClangFormat.cmake)
include(scripts/cmake/SafetyFeatures.cmake)

# 3rd party dependencies
find_package(fmt CONFIG REQUIRED)
find_path(
    TCB_SPAN_INCLUDE_DIRS 
    "tcb/span.hpp" 
    PATHS 
        ${CMAKE_CURRENT_SOURCE_DIR}/vcpkg_installed/arm64-osx/include
)
find_package(GTest CONFIG REQUIRED)

message(STATUS "TCB_SPAN_INCLUDE_DIRS: ${TCB_SPAN_INCLUDE_DIRS}")

enable_testing()

add_library(faker STATIC)
target_include_directories(
    faker
    PRIVATE
        ${TCB_SPAN_INCLUDE_DIRS}
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)
target_link_libraries(
    faker
    PRIVATE
        fmt::fmt
)

turn_on_warnings(faker)

add_subdirectory(src)
add_subdirectory(tests)