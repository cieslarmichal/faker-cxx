cmake_minimum_required(VERSION 3.16)

project(faker VERSION 0.0.1)

option(USE_CXX20 "Use C++20 functionality" OFF)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

if (USE_CXX20)
    set(CMAKE_CXX_STANDARD 20)
else()
    set(CMAKE_CXX_STANDARD 17)
endif()

set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(scripts/cmake/ClangFormat.cmake)
include(scripts/cmake/SafetyFeatures.cmake)

# 3rd party dependencies

find_package(fmt CONFIG REQUIRED)
find_package(GTest CONFIG REQUIRED)

if (NOT USE_CXX20)
    find_path(
        TCB_SPAN_INCLUDE_DIRS 
        "tcb/span.hpp" 
        PATHS 
            ${CMAKE_CURRENT_SOURCE_DIR}/vcpkg_installed/arm64-osx/include
    )
endif()

enable_testing()

add_library(faker STATIC)
target_include_directories(faker PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

if (NOT USE_CXX20)
    target_include_directories(faker PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/vcpkg_installed/arm64-osx/include)
endif()

target_link_libraries(faker PRIVATE fmt::fmt)

if (USE_CXX20)
    target_compile_definitions(faker PUBLIC -DFAKER_USE_STD_SPAN)
endif()

turn_on_warnings(faker)

add_subdirectory(src)
add_subdirectory(tests)