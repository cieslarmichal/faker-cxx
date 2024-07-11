cmake_minimum_required(VERSION 3.22)

include("${CMAKE_SOURCE_DIR}/cmake/CompilerWarnings.cmake")

set(FAKER_SOURCES
    modules/airline/airline.cpp
    modules/animal/animal.cpp
    modules/book/book.cpp
    modules/color/color.cpp
    modules/commerce/commerce.cpp
    modules/company/company.cpp
    modules/computer/computer.cpp
    modules/crypto/crypto.cpp
    modules/database/database.cpp
    modules/datatype/datatype.cpp
    modules/date/date.cpp
    modules/finance/finance.cpp
    modules/food/food.cpp
    modules/git/git.cpp
    modules/hacker/hacker.cpp
    modules/helper/helper.cpp
    modules/image/image.cpp
    modules/internet/internet.cpp
    modules/location/location.cpp
    modules/lorem/lorem.cpp
    modules/medicine/medicine.cpp
    modules/movie/movie.cpp
    modules/music/music.cpp
    modules/person/person.cpp
    modules/phone/phone.cpp
    modules/plant/plant.cpp
    modules/science/science.cpp
    modules/sport/sport.cpp
    modules/string/string.cpp
    modules/system/system.cpp
    modules/vehicle/vehicle.cpp
    modules/video_game/video_game.cpp
    modules/weather/weather.cpp
    modules/word/word.cpp
    common/format_helper.cpp
    common/luhn_check.cpp
    common/string_helper.cpp
)

set(FAKER_HEADERS
    common/luhn_check.h
    common/format_helper.h
    common/algo_helper.h
    common/string_helper.h
    modules/plant/plant_data.h
    modules/person/person_data.h
    modules/internet/internet_data.h
    modules/sport/sport_data.h
    modules/airline/airline_data.h
    modules/location/location_data.h
    modules/book/book_data.h
    modules/string/string_data.h
    modules/video_game/video_game_data.h
    modules/medicine/medicine_data.h
    modules/vehicle/vehicle_data.h
    modules/hacker/hacker_data.h
    modules/science/science_data.h
    modules/date/date_data.h
    modules/system/system_data.h
    modules/commerce/commerce_data.h
    modules/computer/computer_data.h
    modules/weather/weather_data.h
    modules/music/music_data.h
    modules/database/database_data.h
    modules/movie/movie_data.h
    modules/food/food_data.h
    modules/word/word_data.h
    modules/word/word_store.h
    modules/animal/animal_data.h
    modules/company/company_data.h
    modules/finance/finance_data.h
    modules/phone/phone_data.h
    modules/color/color_data.h
    modules/lorem/lorem_data.h
)

target_sources(${CMAKE_PROJECT_NAME} PRIVATE ${FAKER_SOURCES} ${FAKER_HEADERS})
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE $<IF:$<TARGET_EXISTS:fmt::fmt>,fmt::fmt,${FMT_LIBRARY}>)
if (USE_STD_FORMAT)
    target_compile_definitions(${CMAKE_PROJECT_NAME} PRIVATE USE_STD_FORMAT)
endif()

target_include_directories(
    ${CMAKE_PROJECT_NAME} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

target_include_directories(
    ${CMAKE_PROJECT_NAME} PRIVATE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)

target_compile_features(${CMAKE_PROJECT_NAME} PUBLIC cxx_std_20)
configure_compiler_warnings(${CMAKE_PROJECT_NAME}
    "${WARNINGS_AS_ERRORS}"
    "${MSVC_WARNINGS}"
    "${CLANG_WARNINGS}"
    "${GCC_WARNINGS}")

configure_file(
    "${CMAKE_SOURCE_DIR}/cmake/Version.h.in"
    "${CMAKE_BINARY_DIR}/include/faker-cxx/version.h"
    @ONLY
)

include(GenerateExportHeader)
generate_export_header(${CMAKE_PROJECT_NAME}
    BASE_NAME FAKER_CXX
    EXPORT_FILE_NAME ${CMAKE_BINARY_DIR}/include/faker-cxx/export.h
)
set_target_properties(${CMAKE_PROJECT_NAME} PROPERTIES
    CXX_VISIBILITY_PRESET hidden
    CMAKE_VISIBILITY_INLINES_HIDDEN 1
    VERSION ${CMAKE_PROJECT_VERSION}
    SOVERSION ${CMAKE_PROJECT_VERSION_MAJOR}
)

target_include_directories(
    ${CMAKE_PROJECT_NAME}
    PUBLIC $<BUILD_INTERFACE:${CMAKE_BINARY_DIR}/include>
    PRIVATE ${CMAKE_BINARY_DIR}/include
)

include(CMakePackageConfigHelpers)
include(GNUInstallDirs)

configure_file(
    "${CMAKE_SOURCE_DIR}/cmake/${CMAKE_PROJECT_NAME}.pc.in"
    "${CMAKE_BINARY_DIR}/${CMAKE_PROJECT_NAME}.pc"
    @ONLY
)

write_basic_package_version_file(${PROJECT_BINARY_DIR}/${CMAKE_PROJECT_NAME}ConfigVersion.cmake
    VERSION ${CMAKE_PROJECT_VERSION}
    COMPATIBILITY SameMajorVersion)

install(TARGETS ${CMAKE_PROJECT_NAME}
    EXPORT ${CMAKE_PROJECT_NAME}-targets
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})

install(DIRECTORY ${CMAKE_SOURCE_DIR}/include/faker-cxx
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
    FILES_MATCHING
    PATTERN "*.h"
)

install(DIRECTORY ${CMAKE_BINARY_DIR}/include/faker-cxx
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
    FILES_MATCHING
    PATTERN "*.h"
)

install(FILES "${CMAKE_BINARY_DIR}/${CMAKE_PROJECT_NAME}.pc"
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/pkgconfig
)

install(FILES
    "${CMAKE_BINARY_DIR}/${CMAKE_PROJECT_NAME}ConfigVersion.cmake"
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake
)

install(EXPORT ${CMAKE_PROJECT_NAME}-targets
    NAMESPACE ${CMAKE_PROJECT_NAME}::
    FILE ${CMAKE_PROJECT_NAME}-config.cmake
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake
)
