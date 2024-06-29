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
