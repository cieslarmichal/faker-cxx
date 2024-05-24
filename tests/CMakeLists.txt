cmake_minimum_required(VERSION 3.22)
project(${CMAKE_PROJECT_NAME}-UT CXX)

include(CTest)
enable_testing()

set(target_code_coverage_ALL 1)

include("${CMAKE_SOURCE_DIR}/cmake/cmake-coverage.cmake")

add_code_coverage_all_targets()

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

add_executable(${PROJECT_NAME} ${FAKER_UT_SOURCES})
if (MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /permissive- /bigobj)
endif()

if (USE_SYSTEM_DEPENDENCIES)
    find_package(GTest REQUIRED)
    target_link_libraries(${PROJECT_NAME} PRIVATE GTest::gtest
        GTest::gtest_main GTest::gmock GTest::gmock_main faker-cxx)
else ()
    add_subdirectory(externals/googletest)

    set(GTEST_INCLUDE_DIR
        "${CMAKE_SOURCE_DIR}/externals/googletest/googletest/include")
    set(GMOCK_INCLUDE_DIR
        "${CMAKE_SOURCE_DIR}/externals/googletest/googlemock/include")

    target_link_libraries(${PROJECT_NAME} PRIVATE gtest_main gmock_main
        faker-cxx)
endif ()

if (HAS_STD_FORMAT)
    target_include_directories(
        ${PROJECT_NAME}
        PRIVATE ${GTEST_INCLUDE_DIR} ${GMOCK_INCLUDE_DIR}
        ${CMAKE_CURRENT_LIST_DIR})
    target_compile_definitions(${PROJECT_NAME} PRIVATE HAS_STD_FORMAT)
else ()
    target_link_libraries(${PROJECT_NAME} PRIVATE
        $<IF:$<TARGET_EXISTS:fmt::fmt>,fmt::fmt,fmt>)
    target_include_directories(
        ${PROJECT_NAME}
        PRIVATE ${FMT_INCLUDE_DIR} ${GTEST_INCLUDE_DIR}
        ${GMOCK_INCLUDE_DIR} ${CMAKE_CURRENT_LIST_DIR})
endif ()

add_test(
    NAME ${PROJECT_NAME}
    COMMAND ${PROJECT_NAME}
    WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR})

target_code_coverage(${PROJECT_NAME} ALL)
