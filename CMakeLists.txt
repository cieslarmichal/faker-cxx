cmake_minimum_required(VERSION 3.22)
project(faker-cxx
    LANGUAGES CXX
    VERSION 4.0.1
    DESCRIPTION "C++ Faker library for generating fake (but realistic) data."
    HOMEPAGE_URL "https://github.com/cieslarmichal/faker-cxx")

include(cmake/CompilerWarnings.cmake)
include(CMakeDependentOption)

option(USE_SYSTEM_DEPENDENCIES "Use GTest from system" OFF)
option(FAKER_BUILD_TESTING "Build tests" ON)
option(CODE_COVERAGE "Build faker-cxx with coverage support" OFF)

SET(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if (MSVC)
    set(CMAKE_REQUIRED_FLAGS /std:c++20)
else ()
    set(CMAKE_REQUIRED_FLAGS -std=c++20)
endif ()

cmake_dependent_option(USE_STD_FORMAT "Use std::format when available" ON "HAS_STD_FORMAT" OFF)

add_library(${PROJECT_NAME})

add_subdirectory(src)

if (CODE_COVERAGE)
    set(target_code_coverage_ALL 1)
    include("cmake/cmake-coverage.cmake")
    add_code_coverage_all_targets(EXCLUDE tests/*)
    target_code_coverage(${PROJECT_NAME} ALL)
endif ()

if (BUILD_TESTING)
    enable_testing()
    add_subdirectory(tests)
endif ()
