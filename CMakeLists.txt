cmake_minimum_required(VERSION 3.22)
project(faker-cxx LANGUAGES CXX)

include(cmake/CompilerWarnings.cmake)

option(USE_SYSTEM_DEPENDENCIES "Use fmt and GTest from system" OFF)
option(USE_STD_FORMAT "Use std::format when available" ON)
option(BUILD_EXAMPLES "Build examples" OFF)
option(BUILD_TESTING "Build tests" ON)

if (USE_STD_FORMAT)
    set(CMAKE_REQUIRED_FLAGS -std=c++20)
    include(CheckCXXSourceCompiles)
    check_cxx_source_compiles("#include <format>\nint main(){ auto var = std::format(\"{}\", \"Hello\"); return 0; }"
        HAS_STD_FORMAT)
endif ()

if (BUILD_TESTING)
    enable_testing()
    set(target_code_coverage_ALL 1)
    include("cmake/cmake-coverage.cmake")
    add_code_coverage_all_targets()
endif ()

set(FAKER_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/modules/airline/Airline.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/modules/animal/Animal.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/modules/book/Book.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/modules/color/Color.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/modules/commerce/Commerce.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/modules/company/Company.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/modules/computer/Computer.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/modules/crypto/Crypto.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/modules/database/Database.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/modules/datatype/Datatype.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/modules/date/Date.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/modules/finance/Finance.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/modules/food/Food.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/modules/git/Git.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/modules/hacker/Hacker.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/modules/helper/Helper.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/modules/image/Image.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/modules/internet/Internet.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/modules/location/Location.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/modules/lorem/Lorem.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/modules/medicine/Medicine.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/modules/movie/Movie.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/modules/music/Music.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/modules/person/Person.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/modules/phone/Phone.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/modules/plant/Plant.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/modules/science/Science.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/modules/sport/Sport.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/modules/string/String.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/modules/system/System.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/modules/vehicle/Vehicle.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/modules/videoGame/VideoGame.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/modules/weather/Weather.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/modules/word/Word.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/common/FormatHelper.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/common/LuhnCheck.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/common/StringHelper.cpp
)

add_library(${CMAKE_PROJECT_NAME} ${FAKER_SOURCES})

target_include_directories(
    ${CMAKE_PROJECT_NAME} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

target_include_directories(
    ${CMAKE_PROJECT_NAME} PRIVATE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
)

target_compile_features(${CMAKE_PROJECT_NAME} PUBLIC cxx_std_20)
configure_compiler_warnings(${CMAKE_PROJECT_NAME}
    "${WARNINGS_AS_ERRORS}"
    "${MSVC_WARNINGS}"
    "${CLANG_WARNINGS}"
    "${GCC_WARNINGS}")

include(GenerateExportHeader)
generate_export_header(${CMAKE_PROJECT_NAME} BASE_NAME FAKER_CXX EXPORT_FILE_NAME ${CMAKE_CURRENT_BINARY_DIR}/include/faker-cxx/Export.h)
set_target_properties(${CMAKE_PROJECT_NAME} PROPERTIES
    CXX_VISIBILITY_PRESET hidden
    CMAKE_VISIBILITY_INLINES_HIDDEN 1
)

target_include_directories(
    ${CMAKE_PROJECT_NAME}
    PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/include>
    PRIVATE ${CMAKE_CURRENT_BINARY_DIR}/include
)

include(GNUInstallDirs)
install(TARGETS ${CMAKE_PROJECT_NAME}
    EXPORT ${CMAKE_PROJECT_NAME}-targets
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})

install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/faker-cxx
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
    FILES_MATCHING
    PATTERN "*.h"
)

install(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/include/faker-cxx
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
    FILES_MATCHING
    PATTERN "*.h"
)

install(EXPORT ${CMAKE_PROJECT_NAME}-targets
    NAMESPACE ${CMAKE_PROJECT_NAME}::
    FILE ${CMAKE_PROJECT_NAME}-config.cmake
    DESTINATION lib/cmake/${CMAKE_PROJECT_NAME})

if (HAS_STD_FORMAT)
    target_compile_definitions(${CMAKE_PROJECT_NAME} PRIVATE HAS_STD_FORMAT)
elseif (USE_SYSTEM_DEPENDENCIES)
    find_package(fmt CONFIG REQUIRED)
    target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE fmt::fmt)
else ()
    add_subdirectory(externals/fmt)
    set(FMT_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/externals/fmt/include")
    target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE fmt)
endif ()

if (BUILD_TESTING)
    add_subdirectory(tests)
endif ()

if (BUILD_EXAMPLES)
    add_subdirectory(examples)
endif ()
