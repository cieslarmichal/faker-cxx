cmake_minimum_required(VERSION 3.22)

set(PROJECT_NAME faker-cxx)
project(${PROJECT_NAME} CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

option(BUILD_FAKER_TESTS DEFAULT ON)

if (MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++20 /permissive- /bigobj")
else ()
    set(CMAKE_CXX_FLAGS
        "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -Wconversion -Wformat -Werror"
    )
endif ()

set(LIBRARY_NAME faker-cxx)

set(FAKER_SOURCES
    src/modules/animal/Animal.cpp
    src/modules/book/Book.cpp
    src/modules/color/Color.cpp
    src/modules/commerce/Commerce.cpp
    src/modules/company/Company.cpp
    src/modules/datatype/Datatype.cpp
    src/modules/date/Date.cpp
    src/modules/finance/Finance.cpp
    src/modules/food/Food.cpp
    src/modules/helper/Helper.cpp
    src/modules/internet/Internet.cpp
    src/modules/location/Location.cpp
    src/modules/lorem/Lorem.cpp
    src/modules/number/Number.cpp
    src/modules/person/Person.cpp
    src/modules/string/String.cpp
    src/modules/word/Word.cpp
    src/modules/phone/Phone.cpp
    src/common/StringHelper.cpp
    src/common/FormatHelper.cpp
    src/common/LuhnCheck.cpp
    src/common/mappers/precisionMapper/PrecisionMapper.cpp
    src/modules/system/System.cpp
    src/modules/database/Database.cpp
    src/modules/music/Music.cpp
    src/modules/movie/Movie.cpp
    src/modules/git/Git.cpp
    src/modules/hacker/Hacker.cpp
    src/modules/sport/Sport.cpp
    src/modules/videoGame/VideoGame.cpp
    src/modules/medicine/Medicine.cpp
    src/modules/weather/Weather.cpp
    src/modules/airline/Airline.cpp
    src/modules/image/Image.cpp
    src/modules/crypto/Crypto.cpp
    src/modules/computer/Computer.cpp
    src/modules/vehicle/Vehicle.cpp
    src/modules/science/Science.cpp
    src/modules/structure/Structure.cpp
)

set(FAKER_UT_SOURCES
    src/modules/animal/AnimalTest.cpp
    src/modules/book/BookTest.cpp
    src/modules/color/ColorTest.cpp
    src/modules/commerce/CommerceTest.cpp
    src/modules/company/CompanyTest.cpp
    src/modules/datatype/DatatypeTest.cpp
    src/modules/date/DateTest.cpp
    src/modules/finance/FinanceTest.cpp
    src/modules/food/FoodTest.cpp
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
    src/common/FormatHelperTest.cpp
    src/common/mappers/precisionMapper/PrecisionMapperTest.cpp
    src/modules/system/SystemTest.cpp
    src/modules/database/DatabaseTest.cpp
    src/modules/music/MusicTest.cpp
    src/modules/movie/MovieTest.cpp
    src/modules/git/GitTest.cpp
    src/modules/hacker/HackerTest.cpp
    src/modules/sport/SportTest.cpp
    src/modules/videoGame/VideoGameTest.cpp
    src/modules/medicine/MedicineTest.cpp
    src/modules/weather/WeatherTest.cpp
    src/modules/airline/AirlineTest.cpp
    src/modules/image/ImageTest.cpp
    src/modules/crypto/CryptoTest.cpp
    src/modules/computer/ComputerTest.cpp
    src/modules/vehicle/VehicleTest.cpp
    src/modules/science/ScienceTest.cpp
    src/modules/structure/StructureTest.cpp
)

add_library(${LIBRARY_NAME} ${FAKER_SOURCES})

target_include_directories(
    ${LIBRARY_NAME} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>)

install(TARGETS ${LIBRARY_NAME}
    EXPORT ${LIBRARY_NAME}-targets
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin)

install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/faker-cxx
    DESTINATION include/
    FILES_MATCHING
    PATTERN "*.h"
)

install(EXPORT ${LIBRARY_NAME}-targets
    NAMESPACE ${LIBRARY_NAME}::
    FILE ${LIBRARY_NAME}-config.cmake
    DESTINATION lib/cmake/${LIBRARY_NAME})

if (APPLE OR (CMAKE_CXX_COMPILER_ID STREQUAL "GNU" AND CMAKE_CXX_COMPILER_VERSION
    VERSION_LESS 12))

    add_subdirectory(externals/fmt)
    set(FMT_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/externals/fmt/include")
    target_link_libraries(${LIBRARY_NAME} PRIVATE fmt)
endif ()

if (BUILD_FAKER_TESTS)
    add_subdirectory(externals/googletest)

    set(GTEST_INCLUDE_DIR
        "${CMAKE_SOURCE_DIR}/externals/googletest/googletest/include")
    set(GMOCK_INCLUDE_DIR
        "${CMAKE_SOURCE_DIR}/externals/googletest/googlemock/include")

    enable_testing()

    set(target_code_coverage_ALL 1)

    include("cmake/cmake-coverage.cmake")

    add_code_coverage_all_targets()

    add_executable(${LIBRARY_NAME}-UT ${FAKER_UT_SOURCES})

    target_link_libraries(${LIBRARY_NAME}-UT PRIVATE gtest_main gmock_main
        faker-cxx)

    if (APPLE OR (CMAKE_CXX_COMPILER_ID STREQUAL "GNU"
        AND CMAKE_CXX_COMPILER_VERSION VERSION_LESS 12))

        target_link_libraries(${LIBRARY_NAME}-UT PRIVATE fmt)
        target_include_directories(
            ${LIBRARY_NAME}-UT
            PRIVATE ${FMT_INCLUDE_DIR} ${GTEST_INCLUDE_DIR}
            ${GMOCK_INCLUDE_DIR} ${CMAKE_CURRENT_LIST_DIR})
    else ()
        target_include_directories(
            ${LIBRARY_NAME}-UT
            PRIVATE ${GTEST_INCLUDE_DIR} ${GMOCK_INCLUDE_DIR}
            ${CMAKE_CURRENT_LIST_DIR})
    endif ()

    add_test(
        NAME ${LIBRARY_NAME}-UT
        COMMAND ${LIBRARY_NAME}-UT
        WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR})

    target_code_coverage(${LIBRARY_NAME}-UT ALL)
endif ()