cmake_minimum_required(VERSION 3.23)

set(PROJECT_NAME faker-cxx)
project(${PROJECT_NAME} CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED YES)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")

find_package(Boost REQUIRED)
find_package(GTest REQUIRED)

enable_testing()

set(target_code_coverage_ALL 1)
include("cmake/cmake-coverage.cmake")
add_code_coverage_all_targets()

set(LIBRARY_NAME faker-cxx)

set(SOURCES
        src/Person.cpp
        src/Internet.cpp
        src/Number.cpp
        src/String.cpp
        src/Lorem.cpp
        include/faker-cxx/Helper.h
        )

set(UT_SOURCES
        src/NumberTest.cpp
        src/StringTest.cpp
        src/PersonTest.cpp
        src/LoremTest.cpp
        src/InternetTest.cpp
        )

add_library(${LIBRARY_NAME} ${SOURCES})

target_include_directories(${LIBRARY_NAME}
        PUBLIC
        "include"
        PRIVATE
        "include/faker-cxx"
        )

add_executable(${LIBRARY_NAME}UT ${SOURCES} ${UT_SOURCES})

target_link_libraries(${LIBRARY_NAME}UT PRIVATE
        GTest::gtest_main
        )

target_include_directories(${LIBRARY_NAME}UT
        PRIVATE
        "include/faker-cxx"
        ${Boost_INCLUDE_DIR}
        ${GTEST_INCLUDE_DIR}
        )

add_test(NAME ${LIBRARY_NAME}UT COMMAND ${LIBRARY_NAME}UT WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR})

target_code_coverage(${LIBRARY_NAME}UT ALL)
