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
endif ()

if (BUILD_TESTING)
    enable_testing()
    set(target_code_coverage_ALL 1)
    include("cmake/cmake-coverage.cmake")
    add_code_coverage_all_targets()
endif ()

set(LIBRARY_NAME faker-cxx)

set(FAKER_SOURCES
    src/modules/airline/Airline.cpp
    src/modules/airline/AirlineData.cpp
    src/modules/animal/Animal.cpp
    src/modules/animal/AnimalData.cpp
    src/modules/book/Book.cpp
    src/modules/book/BookData.cpp
    src/modules/color/Color.cpp
    src/modules/color/ColorData.cpp
    src/modules/commerce/Commerce.cpp
    src/modules/commerce/CommerceData.cpp
    src/modules/company/Company.cpp
    src/modules/company/CompanyData.cpp
    src/modules/computer/Computer.cpp
    src/modules/computer/ComputerData.cpp
    src/modules/crypto/Crypto.cpp
    src/modules/database/Database.cpp
    src/modules/database/DatabaseData.cpp
    src/modules/datatype/Datatype.cpp
    src/modules/date/Date.cpp
    src/modules/date/DateData.cpp
    src/modules/finance/Finance.cpp
    src/modules/finance/FinanceData.cpp
    src/modules/food/Food.cpp
    src/modules/food/FoodData.cpp
    src/modules/git/Git.cpp
    src/modules/hacker/Hacker.cpp
    src/modules/helper/Helper.cpp
    src/modules/image/Image.cpp
    src/modules/internet/Internet.cpp
    src/modules/internet/InternetData.cpp
    src/modules/location/Location.cpp
    src/modules/lorem/Lorem.cpp
    src/modules/medicine/Medicine.cpp
    src/modules/medicine/MedicineData.cpp
    src/modules/movie/Movie.cpp
    src/modules/movie/MovieData.cpp
    src/modules/music/Music.cpp
    src/modules/music/MusicData.cpp
    src/modules/number/Number.cpp
    src/modules/person/Person.cpp
    src/modules/phone/Phone.cpp
    src/modules/phone/PhoneData.cpp
    src/modules/science/Science.cpp
    src/modules/sport/Sport.cpp
    src/modules/sport/SportData.cpp
    src/modules/string/String.cpp
    src/modules/system/System.cpp
    src/modules/vehicle/Vehicle.cpp
    src/modules/vehicle/VehicleData.cpp
    src/modules/videoGame/VideoGame.cpp
    src/modules/videoGame/VideoGameData.cpp
    src/modules/weather/Weather.cpp
    src/modules/word/Word.cpp
    src/common/FormatHelper.cpp
    src/common/LuhnCheck.cpp
    src/common/StringHelper.cpp
    src/common/PrecisionMapper.cpp
)

add_library(${LIBRARY_NAME} ${FAKER_SOURCES})

target_include_directories(
    ${LIBRARY_NAME} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>)

target_include_directories(
    ${LIBRARY_NAME} PRIVATE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
)

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
elseif (USE_SYSTEM_DEPENDENCIES)
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
