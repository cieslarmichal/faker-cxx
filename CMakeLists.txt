cmake_minimum_required(VERSION 3.22)

set(PROJECT_NAME faker-cxx)
project(${PROJECT_NAME} CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

option(USE_SYSTEM_DEPENDENCIES "Use fmt and GTest from system" OFF)

if (NOT USE_SYSTEM_DEPENDENCIES)
    set(CMAKE_REQUIRED_FLAGS -std=c++20)
    include(CheckCXXSourceCompiles)
    check_cxx_source_compiles("#include <format>\nint main(){ auto var = std::format(\"{}\", \"Hello\"); return 0; }"
        HAS_STD_FORMAT)
endif()

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

add_library(${LIBRARY_NAME} ${FAKER_SOURCES})

target_include_directories(
    ${LIBRARY_NAME} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>)

target_compile_features(${LIBRARY_NAME} PUBLIC cxx_std_20)
if (MSVC)
    target_compile_options(${LIBRARY_NAME} PRIVATE /permissive- /bigobj)
else ()
    target_compile_options(${LIBRARY_NAME} PRIVATE -Wall -Wextra -Wpedantic -Wconversion -Wformat)
endif ()

include(GNUInstallDirs)
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

if (HAS_STD_FORMAT AND NOT USE_SYSTEM_DEPENDENCIES)
    target_compile_definitions(${LIBRARY_NAME} PRIVATE HAS_STD_FORMAT)
elseif(USE_SYSTEM_DEPENDENCIES)
    find_package(fmt REQUIRED)
    target_link_libraries(${LIBRARY_NAME} PRIVATE fmt::fmt)
else ()
    add_subdirectory(externals/fmt)
    set(FMT_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/externals/fmt/include")
    target_link_libraries(${LIBRARY_NAME} PRIVATE fmt)
endif ()

if (BUILD_TESTING)
    add_subdirectory(tests)
endif ()
