cmake_minimum_required(VERSION 3.22)

set(PROJECT_NAME faker-cxx)
project(${PROJECT_NAME} CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED YES)

option(BUILD_FAKER_TESTS DEFAULT ON)

if (MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++20 /permissive-")
else ()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -Wconversion -Wformat -Werror")
endif ()

set(LIBRARY_NAME faker-cxx)

set(FAKER_SOURCES
        src/modules/book/Book.cpp
        src/modules/color/Color.cpp
        src/modules/commerce/Commerce.cpp
        src/modules/company/Company.cpp
        src/modules/datatype/Datatype.cpp
        src/modules/date/Date.cpp
        src/modules/finance/Finance.cpp
        src/modules/helper/Helper.cpp
        src/modules/internet/Internet.cpp
        src/modules/location/Location.cpp
        src/modules/lorem/Lorem.cpp
        src/modules/number/Number.cpp
        src/modules/person/Person.cpp
        src/modules/string/String.cpp
        src/modules/word/Word.cpp
        src/common/StringHelper.cpp
        src/modules/phone/Phone.cpp
        src/common/LuhnCheck.cpp
        src/common/mappers/PrecisionMapper.cpp
        src/modules/system/System.cpp
        src/modules/database/Database.cpp
        src/modules/music/Music.cpp
        src/modules/movie/Movie.cpp
        )

set(FAKER_UT_SOURCES
        src/modules/book/BookTest.cpp
        src/modules/color/ColorTest.cpp
        src/modules/commerce/CommerceTest.cpp
        src/modules/company/CompanyTest.cpp
        src/modules/datatype/DatatypeTest.cpp
        src/modules/date/DateTest.cpp
        src/modules/finance/FinanceTest.cpp
        src/modules/internet/InternetTest.cpp
        src/modules/location/LocationTest.cpp
        src/modules/lorem/LoremTest.cpp
        src/modules/number/NumberTest.cpp
        src/modules/person/PersonTest.cpp
        src/modules/string/StringTest.cpp
        src/modules/word/WordTest.cpp
        src/common/StringHelperTest.cpp
        src/modules/phone/PhoneTest.cpp
        src/modules/helper/HelperTest.cpp
        src/common/LuhnCheckTest.cpp
        src/common/mappers/PrecisionMapperTest.cpp
        src/modules/system/SystemTest.cpp
        src/modules/database/DatabaseTest.cpp
        src/modules/music/MusicTest.cpp
        src/modules/movie/MovieTest.cpp
        )

add_library(${LIBRARY_NAME} ${FAKER_SOURCES})

target_include_directories(${LIBRARY_NAME}
        INTERFACE
        "${CMAKE_CURRENT_LIST_DIR}/include"
        PRIVATE
        "${CMAKE_CURRENT_LIST_DIR}/include"
        )

if (BUILD_FAKER_TESTS)
    add_subdirectory(externals/googletest)

    set(GTEST_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/externals/googletest/googletest/include")
    set(GMOCK_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/externals/googletest/googlemock/include")

    enable_testing()

    set(target_code_coverage_ALL 1)

    include("cmake/cmake-coverage.cmake")

    add_code_coverage_all_targets()

    add_executable(${LIBRARY_NAME}-UT ${FAKER_UT_SOURCES})

    target_link_libraries(${LIBRARY_NAME}-UT PRIVATE gtest_main gmock_main faker-cxx)

    target_include_directories(${LIBRARY_NAME}-UT PRIVATE ${GTEST_INCLUDE_DIR} ${GMOCK_INCLUDE_DIR} ${CMAKE_CURRENT_LIST_DIR})

    add_test(NAME ${LIBRARY_NAME}-UT COMMAND ${LIBRARY_NAME}-UT WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR})

    target_code_coverage(${LIBRARY_NAME}-UT ALL)
endif ()
