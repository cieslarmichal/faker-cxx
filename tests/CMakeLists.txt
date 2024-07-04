cmake_minimum_required(VERSION 3.22)
project(${CMAKE_PROJECT_NAME}-UT CXX)

include(CTest)
include("${CMAKE_SOURCE_DIR}/cmake/CompilerWarnings.cmake")

set(FAKER_UT_SOURCES
    common/FormatHelperTest.cpp
    common/LuhnCheckTest.cpp
    common/StringHelperTest.cpp
    modules/airline/AirlineTest.cpp
    modules/animal/AnimalTest.cpp
    modules/book/BookTest.cpp
    modules/color/ColorTest.cpp
    modules/commerce/CommerceTest.cpp
    modules/company/CompanyTest.cpp
    modules/computer/ComputerTest.cpp
    modules/crypto/CryptoTest.cpp
    modules/database/DatabaseTest.cpp
    modules/datatype/DatatypeTest.cpp
    modules/date/DateTest.cpp
    modules/finance/FinanceTest.cpp
    modules/food/FoodTest.cpp
    modules/git/GitTest.cpp
    modules/hacker/HackerTest.cpp
    modules/helper/HelperTest.cpp
    modules/image/ImageTest.cpp
    modules/internet/InternetTest.cpp
    modules/location/LocationTest.cpp
    modules/lorem/LoremTest.cpp
    modules/medicine/MedicineTest.cpp
    modules/movie/MovieTest.cpp
    modules/music/MusicTest.cpp
    modules/number/NumberTest.cpp
    modules/person/PersonTest.cpp
    modules/phone/PhoneTest.cpp
    modules/plant/PlantTest.cpp
    modules/science/ScienceTest.cpp
    modules/sport/SportTest.cpp
    modules/string/StringTest.cpp
    modules/system/SystemTest.cpp
    modules/vehicle/VehicleTest.cpp
    modules/version/VersionTest.cpp
    modules/videoGame/VideoGameTest.cpp
    modules/weather/WeatherTest.cpp
    modules/word/WordTest.cpp
)

add_executable(${PROJECT_NAME} ${FAKER_UT_SOURCES})
configure_compiler_warnings(${PROJECT_NAME}
    "${WARNINGS_AS_ERRORS}"
    "${MSVC_WARNINGS}"
    "${CLANG_WARNINGS}"
    "${GCC_WARNINGS}")

target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_SOURCE_DIR}/src/common
    ${CMAKE_SOURCE_DIR}/src/modules
)

if (USE_SYSTEM_DEPENDENCIES)
    find_package(GTest REQUIRED)
    target_link_libraries(${PROJECT_NAME} PRIVATE GTest::gtest GTest::gtest_main GTest::gmock GTest::gmock_main faker-cxx)
else ()
    add_subdirectory("${CMAKE_SOURCE_DIR}/externals/googletest" "${CMAKE_BINARY_DIR}/googletest")

    set(GTEST_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/externals/googletest/googletest/include")
    set(GMOCK_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/externals/googletest/googlemock/include")

    target_link_libraries(${PROJECT_NAME} PRIVATE gtest_main gmock_main faker-cxx)
endif ()

if (USE_STD_FORMAT)
    target_include_directories(${PROJECT_NAME} PRIVATE ${GTEST_INCLUDE_DIR} ${GMOCK_INCLUDE_DIR} ${CMAKE_CURRENT_LIST_DIR})
    target_compile_definitions(${PROJECT_NAME} PRIVATE USE_STD_FORMAT)
else ()
    target_link_libraries(${PROJECT_NAME} PRIVATE $<IF:$<TARGET_EXISTS:fmt::fmt>,fmt::fmt,${FMT_LIBRARY}>)
    target_include_directories(${PROJECT_NAME} PRIVATE ${FMT_INCLUDE_DIR} ${GTEST_INCLUDE_DIR} ${GMOCK_INCLUDE_DIR} ${CMAKE_CURRENT_LIST_DIR})
endif ()

add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME} WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR})
set_tests_properties(${PROJECT_NAME} PROPERTIES ENVIRONMENT_MODIFICATION
                     "PATH=path_list_prepend:$<$<BOOL:${WIN32}>:$<TARGET_FILE_DIR:faker-cxx>>")

if (CODE_COVERAGE)
    target_code_coverage(${PROJECT_NAME} ALL)
endif ()
