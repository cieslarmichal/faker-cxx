cmake_minimum_required(VERSION 3.22)

include("${CMAKE_SOURCE_DIR}/cmake/CompilerWarnings.cmake")

set(FAKER_SOURCES
    modules/airline/Airline.cpp
    modules/animal/Animal.cpp
    modules/book/Book.cpp
    modules/color/Color.cpp
    modules/commerce/Commerce.cpp
    modules/company/Company.cpp
    modules/computer/Computer.cpp
    modules/crypto/Crypto.cpp
    modules/database/Database.cpp
    modules/datatype/Datatype.cpp
    modules/date/Date.cpp
    modules/finance/Finance.cpp
    modules/food/Food.cpp
    modules/git/Git.cpp
    modules/hacker/Hacker.cpp
    modules/helper/Helper.cpp
    modules/image/Image.cpp
    modules/internet/Internet.cpp
    modules/location/Location.cpp
    modules/lorem/Lorem.cpp
    modules/medicine/Medicine.cpp
    modules/movie/Movie.cpp
    modules/music/Music.cpp
    modules/person/Person.cpp
    modules/phone/Phone.cpp
    modules/plant/Plant.cpp
    modules/science/Science.cpp
    modules/sport/Sport.cpp
    modules/string/String.cpp
    modules/system/System.cpp
    modules/vehicle/Vehicle.cpp
    modules/videoGame/VideoGame.cpp
    modules/weather/Weather.cpp
    modules/word/Word.cpp
    modules/e-sport/E-sport.cpp
    common/FormatHelper.cpp
    common/LuhnCheck.cpp
    common/StringHelper.cpp
)

set(FAKER_HEADERS
    common/LuhnCheck.h
    common/FormatHelper.h
    common/AlgoHelper.h
    common/StringHelper.h
    modules/plant/PlantData.h
    modules/person/PersonData.h
    modules/internet/InternetData.h
    modules/sport/SportData.h
    modules/airline/AirlineData.h
    modules/location/LocationData.h
    modules/book/BookData.h
    modules/string/StringData.h
    modules/videoGame/VideoGameData.h
    modules/medicine/MedicineData.h
    modules/vehicle/VehicleData.h
    modules/hacker/HackerData.h
    modules/science/ScienceData.h
    modules/date/DateData.h
    modules/system/SystemData.h
    modules/commerce/CommerceData.h
    modules/computer/ComputerData.h
    modules/weather/WeatherData.h
    modules/music/MusicData.h
    modules/database/DatabaseData.h
    modules/movie/MovieData.h
    modules/food/FoodData.h
    modules/word/WordData.h
    modules/word/WordStore.h
    modules/animal/AnimalData.h
    modules/company/CompanyData.h
    modules/finance/FinanceData.h
    modules/phone/PhoneData.h
    modules/color/ColorData.h
    modules/lorem/LoremData.h
    modules/e-sport/E-sportData.h
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
    "${CMAKE_BINARY_DIR}/include/faker-cxx/Version.h"
    @ONLY
)

include(GenerateExportHeader)
generate_export_header(${CMAKE_PROJECT_NAME}
    BASE_NAME FAKER_CXX
    EXPORT_FILE_NAME ${CMAKE_BINARY_DIR}/include/faker-cxx/Export.h
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
