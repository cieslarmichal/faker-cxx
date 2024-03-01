#ifndef FAKER_MODULES_LOCATION_DATA_H
#define FAKER_MODULES_LOCATION_DATA_H

#include "../common/span.h"
#include <array>
#include <string_view>

namespace faker::location::data {
struct country_addresses_info {
    std::string_view zip_code_format;
    utils::span<const std::string_view> address_formats;
    utils::span<const std::string_view> secondary_address_formats;
    utils::span<const std::string_view> street_formats;
    utils::span<const std::string_view> street_prefixes;
    utils::span<const std::string_view> street_names;
    utils::span<const std::string_view> street_suffixes;
    utils::span<const std::string_view> building_number_formats;
    utils::span<const std::string_view> city_formats;
    utils::span<const std::string_view> city_prefixes;
    utils::span<const std::string_view> cities;
    utils::span<const std::string_view> city_suffixes;
    utils::span<const std::string_view> states;
    utils::span<const std::string_view> counties;
};

extern const std::array<std::string_view, 246> all_countries;
extern const std::array<std::string_view, 249> country_codes;
extern const std::array<std::string_view, 8> directions;
extern const std::array<std::string_view, 418> time_zones;

// Australia

extern const std::array<std::string_view, 323> australia_cities;
extern const std::array<std::string_view, 8> australia_states;
extern const std::array<std::string_view, 37> australia_street_suffixes;
extern const std::array<std::string_view, 1> australia_address_formats;
extern const std::array<std::string_view, 3> australia_building_number_formats;
extern const std::array<std::string_view, 2> australia_street_formats;
extern const std::array<std::string_view, 1> australia_city_formats;
extern const std::string_view australia_zip_code_format;
extern const country_addresses_info australia_addresses;

// Brazil

extern const std::array<std::string_view, 4> brazil_city_suffixes;
extern const std::array<std::string_view, 27> brazil_states;
extern const std::array<std::string_view, 6> brazil_street_suffixes;
extern const std::array<std::string_view, 2> brazil_address_formats;
extern const std::array<std::string_view, 5> brazil_secondary_address_formats;
extern const std::array<std::string_view, 3> brazil_building_number_formats;
extern const std::array<std::string_view, 2> brazil_street_formats;
extern const std::array<std::string_view, 2> brazil_city_formats;
extern const std::string_view brazil_zip_code_format;
extern const country_addresses_info brazil_addresses;

// Czech Republic

extern const std::array<std::string_view, 602> czech_cities;
extern const std::array<std::string_view, 14> czech_states;
extern const std::array<std::string_view, 7526> czech_street_names;
extern const std::array<std::string_view, 2> czech_address_formats;
extern const std::array<std::string_view, 2> czech_secondary_address_formats;
extern const std::array<std::string_view, 3> czech_building_number_formats;
extern const std::array<std::string_view, 1> czech_street_formats;
extern const std::array<std::string_view, 1> czech_city_formats;
extern const std::string_view czech_zip_code_format;
extern const country_addresses_info czech_addresses;

// Denmark

extern const std::array<std::string_view, 221> denmark_cities;
extern const std::array<std::string_view, 5> denmark_states;
extern const std::array<std::string_view, 158> denmark_street_names;
extern const std::array<std::string_view, 2> denmark_address_formats;
extern const std::array<std::string_view, 2> denmark_secondary_address_formats;
extern const std::array<std::string_view, 5> denmark_building_number_formats;
extern const std::array<std::string_view, 1> denmark_street_formats;
extern const std::array<std::string_view, 1> denmark_city_formats;
extern const std::string_view denmark_zip_code_format;
extern const country_addresses_info denmark_addresses;

// Estonia

extern const std::array<std::string_view, 5> estonia_cities;
extern const std::array<std::string_view, 15> estonia_counties;
extern const std::array<std::string_view, 31> estonia_street_names;
extern const std::array<std::string_view, 7> estonia_street_suffixes;
extern const std::array<std::string_view, 1> estonia_address_formats;
extern const std::array<std::string_view, 3> estonia_building_number_formats;
extern const std::array<std::string_view, 1> estonia_street_formats;
extern const std::array<std::string_view, 1> estonia_city_formats;
extern const std::string_view estonia_zip_code_format;
extern const country_addresses_info estonia_addresses;

// Finland

extern const std::array<std::string_view, 20> finland_cities;
extern const std::array<std::string_view, 19> finland_states;
extern const std::array<std::string_view, 11> finland_street_suffixes;
extern const std::array<std::string_view, 2> finland_address_formats;
extern const std::array<std::string_view, 9> finland_secondary_address_formats;
extern const std::array<std::string_view, 3> finland_building_number_formats;
extern const std::array<std::string_view, 2> finland_street_formats;
extern const std::array<std::string_view, 1> finland_city_formats;
extern const std::string_view finland_zip_code_format;
extern const country_addresses_info finland_addresses;

// France

extern const std::array<std::string_view, 1000> france_cities;
extern const std::array<std::string_view, 22> france_states;
extern const std::array<std::string_view, 11> france_street_prefixes;
extern const std::array<std::string_view, 66> france_street_suffixes;
extern const std::array<std::string_view, 1> france_address_formats;
extern const std::array<std::string_view, 4> france_building_number_formats;
extern const std::array<std::string_view, 2> france_secondary_address_formats;
extern const std::array<std::string_view, 1> france_street_formats;
extern const std::array<std::string_view, 1> france_city_formats;
extern const std::string_view france_zip_code_format;
extern const country_addresses_info france_addresses;

// Germany

extern const std::array<std::string_view, 200> germany_cities;
extern const std::array<std::string_view, 16> germany_states;
extern const std::array<std::string_view, 1031> germany_street_names;
extern const std::array<std::string_view, 2> germany_address_formats;
extern const std::array<std::string_view, 3> germany_secondary_address_formats;
extern const std::array<std::string_view, 6> germany_building_number_formats;
extern const std::array<std::string_view, 1> germany_street_formats;
extern const std::array<std::string_view, 1> germany_city_formats;
extern const std::string_view germany_zip_code_format;
extern const country_addresses_info germany_addresses;

// India

extern const std::array<std::string_view, 1198> india_cities;
extern const std::array<std::string_view, 36> india_states;
extern const std::array<std::string_view, 35> india_street_suffixes;
extern const std::array<std::string_view, 1> india_address_formats;
extern const std::array<std::string_view, 2> india_secondary_address_formats;
extern const std::array<std::string_view, 3> india_building_number_formats;
extern const std::array<std::string_view, 2> india_street_formats;
extern const std::array<std::string_view, 1> india_city_formats;
extern const std::string_view india_zip_code_format;
extern const country_addresses_info india_addresses;

// Italy

extern const std::array<std::string_view, 979> italy_cities;
extern const std::array<std::string_view, 110> italy_states;
extern const std::array<std::string_view, 7> italy_street_prefixes;
extern const std::array<std::string_view, 2> italy_address_formats;
extern const std::array<std::string_view, 2> italy_secondary_address_formats;
extern const std::array<std::string_view, 3> italy_building_number_formats;
extern const std::array<std::string_view, 2> italy_street_formats;
extern const std::array<std::string_view, 1> italy_city_formats;
extern const std::string_view italy_zip_code_format;
extern const country_addresses_info italy_addresses;

// Poland

extern const std::array<std::string_view, 978> poland_cities;
extern const std::array<std::string_view, 16> poland_states;
extern const std::array<std::string_view, 5355> poland_street_names;
extern const std::array<std::string_view, 6> poland_street_prefixes;
extern const std::array<std::string_view, 3> poland_address_formats;
extern const std::array<std::string_view, 3> poland_secondary_address_formats;
extern const std::array<std::string_view, 3> poland_building_number_formats;
extern const std::array<std::string_view, 1> poland_street_formats;
extern const std::array<std::string_view, 1> poland_city_formats;
extern const std::string_view poland_zip_code_format;
extern const country_addresses_info poland_addresses;

// Russia

extern const std::array<std::string_view, 322> russia_cities;
extern const std::array<std::string_view, 84> russia_states;
extern const std::array<std::string_view, 297> russia_street_names;
extern const std::array<std::string_view, 12> russia_street_prefixes;
extern const std::array<std::string_view, 2> russia_address_formats;
extern const std::array<std::string_view, 3> russia_secondary_address_formats;
extern const std::array<std::string_view, 3> russia_building_number_formats;
extern const std::array<std::string_view, 3> russia_street_formats;
extern const std::array<std::string_view, 1> russia_city_formats;
extern const std::string_view russia_zip_code_format;
extern const country_addresses_info russia_addresses;

// Spain

extern const std::array<std::string_view, 130> spain_cities;
extern const std::array<std::string_view, 50> spain_counties;
extern const std::array<std::string_view, 17> spain_states;
extern const std::array<std::string_view, 70> spain_street_suffixes;
extern const std::array<std::string_view, 2> spain_address_formats;
extern const std::array<std::string_view, 2> spain_secondary_address_formats;
extern const std::array<std::string_view, 3> spain_building_number_formats;
extern const std::array<std::string_view, 2> spain_street_formats;
extern const std::array<std::string_view, 1> spain_city_formats;
extern const std::string_view spain_zip_code_format;
extern const country_addresses_info spain_addresses;

// Ukraine

extern const std::array<std::string_view, 480> ukraine_cities;
extern const std::array<std::string_view, 27> ukraine_states;
extern const std::array<std::string_view, 61> ukraine_street_names;
extern const std::array<std::string_view, 10> ukraine_street_prefixes;
extern const std::array<std::string_view, 2> ukraine_address_formats;
extern const std::array<std::string_view, 3> ukraine_secondary_address_formats;
extern const std::array<std::string_view, 3> ukraine_building_number_formats;
extern const std::array<std::string_view, 3> ukraine_street_formats;
extern const std::array<std::string_view, 1> ukraine_city_formats;
extern const std::string_view ukraine_zip_code_format;
extern const country_addresses_info ukraine_addresses;

// USA

extern const std::array<std::string_view, 923> usa_cities;
extern const std::array<std::string_view, 36> usa_counties;
extern const std::array<std::string_view, 50> usa_states;
extern const std::array<std::string_view, 195> usa_street_suffixes;
extern const std::array<std::string_view, 1> usa_address_formats;
extern const std::array<std::string_view, 2> usa_secondary_address_formats;
extern const std::array<std::string_view, 3> usa_building_number_formats;
extern const std::array<std::string_view, 2> usa_street_formats;
extern const std::array<std::string_view, 1> usa_city_formats;
extern const std::string_view usa_zip_code_format;
extern const country_addresses_info usa_addresses;

}

#endif