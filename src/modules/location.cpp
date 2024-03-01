#include "../common/formatter.h"
#include "../common/random.h"
#include "location_data.h"
#include <faker/location.h>
#include <faker/number.h>
#include <faker/person.h>
#include <faker/string.h>

namespace faker::location {
namespace {
    const data::country_addresses_info& get_country_addresses(address_country country)
    {
        switch (country) {
        case address_country::usa:
            return data::usa_addresses;
        case address_country::poland:
            return data::poland_addresses;
        case address_country::russia:
            return data::russia_addresses;
        case address_country::france:
            return data::france_addresses;
        case address_country::ukraine:
            return data::ukraine_addresses;
        case address_country::italy:
            return data::italy_addresses;
        case address_country::germany:
            return data::germany_addresses;
        case address_country::czechia:
            return data::czech_addresses;
        case address_country::australia:
            return data::australia_addresses;
        case address_country::india:
            return data::india_addresses;
        case address_country::denmark:
            return data::denmark_addresses;
        case address_country::spain:
            return data::spain_addresses;
        case address_country::brazil:
            return data::brazil_addresses;
        case address_country::finland:
            return data::finland_addresses;
        case address_country::estonia:
            return data::estonia_addresses;
        default:
            throw std::invalid_argument("Invalid country");
        }
    }

    country_t get_country(address_country country)
    {
        switch (country) {
        case address_country::usa:
            return country_t::usa;
        case address_country::poland:
            return country_t::poland;
        case address_country::russia:
            return country_t::russia;
        case address_country::france:
            return country_t::france;
        case address_country::ukraine:
            return country_t::ukraine;
        case address_country::italy:
            return country_t::italy;
        case address_country::germany:
            return country_t::germany;
        case address_country::czechia:
            return country_t::czech;
        case address_country::australia:
            return country_t::australia;
        case address_country::india:
            return country_t::india;
        case address_country::denmark:
            return country_t::denmark;
        case address_country::spain:
            return country_t::spain;
        case address_country::brazil:
            return country_t::brazil;
        case address_country::finland:
            return country_t::finland;
        case address_country::estonia:
            return country_t::estonia;
        default:
            throw std::invalid_argument("Invalid country");
        }
    }
}

std::string_view country_name() { return random::element(data::all_countries); }

std::string_view country_code() { return random::element(data::country_codes); }

std::string_view county(address_country country)
{
    auto& addresses = get_country_addresses(country);
    return addresses.counties.empty() ? "" : random::element(addresses.counties);
}

std::string_view state(address_country country)
{
    return random::element(get_country_addresses(country).states);
}

std::string city(address_country country)
{
    auto& addresses = get_country_addresses(country);
    auto city_format = random::element(addresses.city_formats);

    return utils::fill_token_values(city_format, [country, &addresses](std::string_view token) {
        if (token == "firstName") {
            return std::string(person::first_name(get_country(country)));
        } else if (token == "lastName") {
            return std::string(person::last_name(get_country(country)));
        } else if (token == "cityName") {
            return std::string(random::element(addresses.cities));
        } else if (token == "cityPrefix") {
            return std::string(random::element(addresses.city_prefixes));
        } else if (token == "citySuffix") {
            return std::string(random::element(addresses.city_suffixes));
        } else {
            return std::string();
        }
    });
}

std::string zip_code(address_country country)
{
    auto& addresses = get_country_addresses(country);
    return random::replace_symbol_with_number(addresses.zip_code_format);
}

std::string street_address(address_country country)
{
    auto& addresses = get_country_addresses(country);
    auto address_format = random::element(addresses.address_formats);

    return utils::fill_token_values(address_format, [country](std::string_view token) {
        if (token == "buildingNumber") {
            return building_number(country);
        } else if (token == "street") {
            return street(country);
        } else if (token == "secondaryAddress") {
            return secondary_address(country);
        } else {
            return std::string();
        }
    });
}

std::string street(address_country country)
{
    auto& addresses = get_country_addresses(country);
    auto street_format = random::element(addresses.street_formats);

    return utils::fill_token_values(street_format, [country, &addresses](std::string_view token) {
        if (token == "firstName") {
            return std::string(person::first_name(get_country(country)));
        } else if (token == "lastName") {
            return std::string(person::last_name(get_country(country)));
        } else if (token == "streetName") {
            return std::string(random::element(addresses.street_names));
        } else if (token == "streetPrefix") {
            return std::string(random::element(addresses.street_prefixes));
        } else if (token == "streetSuffix") {
            return std::string(random::element(addresses.street_suffixes));
        } else {
            return std::string();
        }
    });
}

std::string building_number(address_country country)
{
    auto& addresses = get_country_addresses(country);
    auto building_number_format = random::element(addresses.building_number_formats);
    return random::replace_symbol_with_number(building_number_format);
}

std::string secondary_address(address_country country)
{
    auto& addresses = get_country_addresses(country);
    auto secondary_address_format = addresses.secondary_address_formats.empty()
        ? ""
        : random::element(addresses.secondary_address_formats);

    return random::replace_symbol_with_number(secondary_address_format);
}

std::string latitude(precision_t prec)
{
    auto latitude = number::decimal(-90.0, 90.0);
    return utils::format(utils::precision_format_str(prec), latitude);
}

std::string longitude(precision_t prec)
{
    auto longitude = number::decimal(-180.0, 180.0);
    return utils::format(utils::precision_format_str(prec), longitude);
}

std::string_view direction() { return random::element(data::directions); }

std::string_view time_zone() { return random::element(data::time_zones); }

}
