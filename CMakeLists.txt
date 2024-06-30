cmake_minimum_required(VERSION 3.22)
project(faker-cxx LANGUAGES CXX VERSION 2.0.0)

include(cmake/CompilerWarnings.cmake)

option(USE_SYSTEM_DEPENDENCIES "Use fmt and GTest from system" OFF)
option(BUILD_EXAMPLES "Build examples" OFF)
option(BUILD_TESTING "Build tests" ON)

if (MSVC)
    set(CMAKE_REQUIRED_FLAGS /std:c++20)
else()
    set(CMAKE_REQUIRED_FLAGS -std=c++20)
endif()
include(CheckCXXSourceCompiles)
check_cxx_source_compiles("#include <format>\nint main(){ auto var = std::format(\"{}\", \"Hello\"); return 0; }"
    HAS_STD_FORMAT)
if (NOT HAS_STD_FORMAT)
    message(STATUS "Compiler has no support for std::format. Need to use fmt library as dependency.")
endif()

include(CMakeDependentOption)
cmake_dependent_option(USE_STD_FORMAT "Use std::format when available" ON "HAS_STD_FORMAT" OFF)

if (BUILD_TESTING)
    enable_testing()
    set(target_code_coverage_ALL 1)
    include("cmake/cmake-coverage.cmake")
    add_code_coverage_all_targets()
endif ()

set(FAKER_SOURCES
    src/modules/airline/Airline.cpp
    src/modules/animal/Animal.cpp
    src/modules/book/Book.cpp
    src/modules/color/Color.cpp
    src/modules/commerce/Commerce.cpp
    src/modules/company/Company.cpp
    src/modules/computer/Computer.cpp
    src/modules/crypto/Crypto.cpp
    src/modules/database/Database.cpp
    src/modules/datatype/Datatype.cpp
    src/modules/date/Date.cpp
    src/modules/finance/Finance.cpp
    src/modules/food/Food.cpp
    src/modules/git/Git.cpp
    src/modules/hacker/Hacker.cpp
    src/modules/helper/Helper.cpp
    src/modules/image/Image.cpp
    src/modules/internet/Internet.cpp
    src/modules/location/Location.cpp
    src/modules/lorem/Lorem.cpp
    src/modules/medicine/Medicine.cpp
    src/modules/movie/Movie.cpp
    src/modules/music/Music.cpp
    src/modules/person/Person.cpp
    src/modules/phone/Phone.cpp
    src/modules/plant/Plant.cpp
    src/modules/science/Science.cpp
    src/modules/sport/Sport.cpp
    src/modules/string/String.cpp
    src/modules/system/System.cpp
    src/modules/vehicle/Vehicle.cpp
    src/modules/videoGame/VideoGame.cpp
    src/modules/weather/Weather.cpp
    src/modules/word/Word.cpp
    src/common/FormatHelper.cpp
    src/common/LuhnCheck.cpp
    src/common/StringHelper.cpp
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

configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake/Version.h.in"
    "${CMAKE_CURRENT_BINARY_DIR}/include/faker-cxx/Version.h"
)

include(GenerateExportHeader)
generate_export_header(${CMAKE_PROJECT_NAME} BASE_NAME FAKER_CXX EXPORT_FILE_NAME ${CMAKE_CURRENT_BINARY_DIR}/include/faker-cxx/Export.h)
set_target_properties(${CMAKE_PROJECT_NAME} PROPERTIES
    CXX_VISIBILITY_PRESET hidden
    CMAKE_VISIBILITY_INLINES_HIDDEN 1
    VERSION ${PROJECT_VERSION}
    SOVERSION ${PROJECT_VERSION_MAJOR}
)

target_include_directories(
    ${CMAKE_PROJECT_NAME}
    PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/include>
    PRIVATE ${CMAKE_CURRENT_BINARY_DIR}/include
)

include(CMakePackageConfigHelpers)
include(GNUInstallDirs)

write_basic_package_version_file(${PROJECT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY SameMajorVersion)

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

install(FILES
    "${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_PROJECT_NAME}ConfigVersion.cmake"
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${CMAKE_PROJECT_NAME}
)

install(EXPORT ${CMAKE_PROJECT_NAME}-targets
    NAMESPACE ${CMAKE_PROJECT_NAME}::
    FILE ${CMAKE_PROJECT_NAME}-config.cmake
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${CMAKE_PROJECT_NAME})

if (USE_STD_FORMAT)
    target_compile_definitions(${CMAKE_PROJECT_NAME} PRIVATE USE_STD_FORMAT)
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
