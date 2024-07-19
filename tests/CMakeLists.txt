cmake_minimum_required(VERSION 3.22)
project(${CMAKE_PROJECT_NAME}-UT CXX)

include(CTest)
include("${CMAKE_SOURCE_DIR}/cmake/CompilerWarnings.cmake")

set(FAKER_UT_SOURCES
    common/format_helper_test.cpp
    common/luhn_check_test.cpp
    common/string_helper_test.cpp
    modules/airline_test.cpp
    modules/animal_test.cpp
    modules/book_test.cpp
    modules/color_test.cpp
    modules/commerce_test.cpp
    modules/company_test.cpp
    modules/computer_test.cpp
    modules/crypto_test.cpp
    modules/database_test.cpp
    modules/datatype_test.cpp
    modules/date_test.cpp
    modules/finance_test.cpp
    modules/food_test.cpp
    modules/git_test.cpp
    modules/hacker_test.cpp
    modules/helper_test.cpp
    modules/image_test.cpp
    modules/internet_test.cpp
    modules/location_test.cpp
    modules/lorem_test.cpp
    modules/medicine_test.cpp
    modules/movie_test.cpp
    modules/music_test.cpp
    modules/number_test.cpp
    modules/person_test.cpp
    modules/phone_test.cpp
    modules/plant_test.cpp
    modules/science_test.cpp
    modules/sport_test.cpp
    modules/string_test.cpp
    modules/system_test.cpp
    modules/vehicle_test.cpp
    modules/version_test.cpp
    modules/video_game_test.cpp
    modules/weather_test.cpp
    modules/word_test.cpp
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
