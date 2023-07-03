cmake_minimum_required(VERSION 3.23)

set(PROJECT_NAME faker-cxx)
project(${PROJECT_NAME} CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED YES)

find_package(Boost REQUIRED)
find_package(GTest REQUIRED)

enable_testing()

set(LIBRARY_NAME faker-cxx)

set(SOURCES
        src/PersonDataGenerator.cpp
        src/InternetDataGenerator.cpp
        src/NumberDataGenerator.cpp
        src/HelperDataGenerator.h
        src/StringDataGenerator.cpp
        src/LoremDataGenerator.cpp
        )

set(UT_SOURCES
        src/NumberDataGeneratorTest.cpp
        )

add_library(${LIBRARY_NAME} ${SOURCES})

add_executable(${LIBRARY_NAME}UT ${SOURCES} ${UT_SOURCES})

target_link_libraries(${LIBRARY_NAME}UT PRIVATE
        GTest::gtest_main
        )

target_include_directories(${LIBRARY_NAME}UT
        PRIVATE
        ${Boost_INCLUDE_DIR}
        ${GTEST_INCLUDE_DIR}
        )

add_test(NAME ${LIBRARY_NAME}UT COMMAND ${LIBRARY_NAME}UT WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR})
