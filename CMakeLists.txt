cmake_minimum_required(VERSION 3.23)

set(PROJECT_NAME faker-cxx)
project(${PROJECT_NAME} CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED YES)

find_package(Boost REQUIRED)
find_package(GTest REQUIRED)

enable_testing()

add_subdirectory(src)
