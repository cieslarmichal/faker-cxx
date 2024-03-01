#include "../test_helpers.h"
#include <algorithm>
#include <common/strings.h>
#include <faker/location.h>
#include <modules/location_data.h>
#include <modules/person_data.h>
#include <modules/string_data.h>

using namespace ::testing;
using namespace faker;

const std::array<location::address_country, 14> addressCountries {
    location::address_country::usa,
    location::address_country::poland,
    location::address_country::france,
    location::address_country::russia,
    location::address_country::ukraine,
    location::address_country::italy,
    location::address_country::germany,
    location::address_country::czechia,
    location::address_country::india,
    location::address_country::denmark,
    location::address_country::australia,
    location::address_country::spain,
    location::address_country::brazil,
    location::address_country::finland,
};

const location::data::country_addresses_info& get_country_addresses(
    location::address_country country)
{
    switch (country) {
    case location::address_country::usa:
        return location::data::usa_addresses;
    case location::address_country::poland:
        return location::data::poland_addresses;
    case location::address_country::russia:
        return location::data::russia_addresses;
    case location::address_country::france:
        return location::data::france_addresses;
    case location::address_country::ukraine:
        return location::data::ukraine_addresses;
    case location::address_country::italy:
        return location::data::italy_addresses;
    case location::address_country::germany:
        return location::data::germany_addresses;
    case location::address_country::czechia:
        return location::data::czech_addresses;
    case location::address_country::australia:
        return location::data::australia_addresses;
    case location::address_country::india:
        return location::data::india_addresses;
    case location::address_country::denmark:
        return location::data::denmark_addresses;
    case location::address_country::spain:
        return location::data::spain_addresses;
    case location::address_country::brazil:
        return location::data::brazil_addresses;
    case location::address_country::finland:
        return location::data::finland_addresses;
    case location::address_country::estonia:
        return location::data::estonia_addresses;
    default:
        throw std::invalid_argument("Invalid country");
    }
}

const std::unordered_map<location::address_country, std::string> generatedTestName {
    { location::address_country::usa, "shouldGenerateAmericanAddress" },
    { location::address_country::france, "shouldGenerateFrenchAddress" },
    { location::address_country::poland, "shouldGeneratePolishAddress" },
    { location::address_country::russia, "shouldGenerateRussianAddress" },
    { location::address_country::ukraine, "shouldGenerateUkrainianAddress" },
    { location::address_country::italy, "shouldGenerateItalianAddress" },
    { location::address_country::germany, "shouldGenerateGermanAddress" },
    { location::address_country::czechia, "shouldGenerateCzechAddress" },
    { location::address_country::australia, "shouldGenerateAustraliaAddress" },
    { location::address_country::india, "shouldGenerateIndiaAddress" },
    { location::address_country::denmark, "shouldGenerateDenmarkAddress" },
    { location::address_country::spain, "shouldGenerateSpainAddress" },
    { location::address_country::brazil, "shouldGenerateBrazilAddress" },
    { location::address_country::finland, "shouldGenerateFinlandAddress" },
    { location::address_country::estonia, "shouldGenerateEstoniaAddress" },
};

class LocationTest : public TestWithParam<location::address_country> {
public:
    static bool checkIfZipCode(std::string_view zipCode)
    {
        const std::string zipCodeCharacters = "0123456789-";

        return faker::testing::all_of(zipCode, [&zipCodeCharacters](char dataCharacter) {
            return faker::testing::any_of(
                zipCodeCharacters, [dataCharacter](char numericCharacter) {
                    return numericCharacter == dataCharacter;
                });
        });
    }

    static bool checkIfAllCharactersAreNumeric(std::string_view data)
    {
        return faker::testing::all_of(data, [](char dataCharacter) {
            return faker::testing::any_of(
                string::data::digits, [dataCharacter](char numericCharacter) {
                    return numericCharacter == dataCharacter;
                });
        });
    }

    static bool checkIfCharacterIsNumeric(char character)
    {
        return faker::testing::contains(string::data::digits, character);
    }
};

TEST_P(LocationTest, shouldGenerateCounty)
{
    const auto country = GetParam();

    const auto& countryAddresses = get_country_addresses(country);

    const auto generatedCounty = location::county(country);

    ASSERT_TRUE(faker::testing::contains(countryAddresses.counties, generatedCounty)
        || (countryAddresses.counties.empty() && generatedCounty.empty()));
}

TEST_P(LocationTest, shouldGenerateState)
{
    const auto country = GetParam();
    const auto& countryAddresses = get_country_addresses(country);

    const auto generatedState = location::state(country);

    FAKER_EXPECT_CONTAINER_CONTAINS(countryAddresses.states, generatedState);
}

TEST_P(LocationTest, shouldGenerateCity)
{
    const auto country = GetParam();

    const auto& countryAddresses = get_country_addresses(country);

    const auto generatedCity = location::city(country);

    if (country == faker::location::address_country::brazil) {
        const auto generatedCityElements = utils::split(generatedCity, " ");

        const auto& generatedCityPrefix = generatedCityElements[0];

        std::vector<std::string_view> firstNames { person::data::brazilian_male_first_names.begin(),
            person::data::brazilian_male_first_names.end() };
        firstNames.insert(firstNames.end(), person::data::brazilian_female_first_names.begin(),
            person::data::brazilian_female_first_names.end());

        std::vector<std::string_view> lastNames { person::data::brazilian_last_names.begin(),
            person::data::brazilian_last_names.end() };

        ASSERT_TRUE(faker::testing::any_of(firstNames,
                        [&generatedCityPrefix](auto firstName) {
                            return generatedCityPrefix.find(firstName) != std::string::npos;
                        })
            || faker::testing::any_of(lastNames,
                [&generatedCityPrefix](auto lastName) {
                    return generatedCityPrefix.find(lastName) != std::string::npos;
                })
            || faker::testing::any_of(
                location::data::brazil_city_suffixes, [&generatedCity](auto citySuffix) {
                    return generatedCity.find(citySuffix) != std::string::npos;
                }));
    } else {
        FAKER_EXPECT_CONTAINER_CONTAINS(countryAddresses.cities, generatedCity);
    }
}

TEST_P(LocationTest, shouldGenerateZipCode)
{
    const auto country = GetParam();

    const auto& countryAddresses = get_country_addresses(country);

    const auto generatedZipCode = location::zip_code(country);

    ASSERT_EQ(generatedZipCode.size(), countryAddresses.zip_code_format.size());
    ASSERT_TRUE(checkIfZipCode(generatedZipCode));
}

TEST_P(LocationTest, shouldGenerateBuildingNumber)
{
    const auto country = GetParam();

    const auto& countryAddresses = get_country_addresses(country);

    const auto generatedBuildingNumber = location::building_number(country);

    const auto generatedBuildingNumberExceptLastCharacter
        = generatedBuildingNumber.substr(0, generatedBuildingNumber.size() - 1);

    ASSERT_TRUE(faker::testing::any_of(countryAddresses.building_number_formats,
        [&generatedBuildingNumber](auto buildingNumberFormat) {
            for (std::size_t i = 0; i < buildingNumberFormat.size(); i++) {
                if (buildingNumberFormat[i] == '#') {
                    const auto isNumeric = checkIfCharacterIsNumeric(generatedBuildingNumber[i]);

                    if (!isNumeric) {
                        return false;
                    }
                } else {
                    if (generatedBuildingNumber.find(buildingNumberFormat[i])
                        == std::string::npos) {
                        return false;
                    }
                }
            }

            return true;
        }));
}

TEST_P(LocationTest, shouldGenerateSecondaryAddress)
{
    const auto country = GetParam();

    const auto& countryAddresses = get_country_addresses(country);

    const auto generatedSecondaryAddress = location::secondary_address(country);

    ASSERT_TRUE(
        (countryAddresses.secondary_address_formats.empty() && generatedSecondaryAddress.empty())
        || faker::testing::any_of(countryAddresses.secondary_address_formats,
            [&generatedSecondaryAddress](auto secondaryAddressFormat) {
                for (std::size_t i = 0; i < secondaryAddressFormat.size(); i++) {
                    if (secondaryAddressFormat[i] == '#') {
                        const auto isNumeric
                            = checkIfCharacterIsNumeric(generatedSecondaryAddress[i]);

                        if (!isNumeric) {
                            return false;
                        }
                    } else {
                        if (generatedSecondaryAddress.find(secondaryAddressFormat[i])
                            == std::string::npos) {
                            return false;
                        }
                    }
                }

                return true;
            }));
}

INSTANTIATE_TEST_SUITE_P(TestLocationByCountries, LocationTest, ValuesIn(addressCountries),
    [](const TestParamInfo<location::address_country>& info) {
        return generatedTestName.at(info.param);
    });

TEST_F(LocationTest, shouldGenerateUsaStreet)
{
    const auto generatedStreet = location::street();

    const auto generatedStreetElements = utils::split(generatedStreet, " ");

    const auto& generatedFirstOrLastName = generatedStreetElements[0];
    const auto& generatedStreetSuffix = generatedStreetElements[1];

    std::vector<std::string_view> firstNames { person::data::english_male_first_names.begin(),
        person::data::english_male_first_names.end() };
    firstNames.insert(firstNames.end(), person::data::english_female_first_names.begin(),
        person::data::english_female_first_names.end());

    ASSERT_EQ(generatedStreetElements.size(), 2);
    ASSERT_TRUE(faker::testing::any_of(firstNames,
                    [&generatedFirstOrLastName](
                        auto firstName) { return firstName == generatedFirstOrLastName; })
        || faker::testing::any_of(
            person::data::english_last_names, [&generatedFirstOrLastName](auto lastName) {
                return lastName == generatedFirstOrLastName;
            }));
    FAKER_EXPECT_CONTAINER_CONTAINS(location::data::usa_street_suffixes, generatedStreetSuffix);
}

TEST_F(LocationTest, shouldGenerateUsaStreetAddress)
{
    const auto generatedStreetAddress = location::street_address();

    const auto generatedStreetAddressElements = utils::split(generatedStreetAddress, " ");

    const auto& generatedBuildingNumber = generatedStreetAddressElements[0];
    const auto& generatedFirstOrLastName = generatedStreetAddressElements[1];
    const auto& generatedStreetSuffix = generatedStreetAddressElements[2];

    std::vector<std::string_view> firstNames { person::data::english_male_first_names.begin(),
        person::data::english_male_first_names.end() };
    firstNames.insert(firstNames.end(), person::data::english_female_first_names.begin(),
        person::data::english_female_first_names.end());

    ASSERT_EQ(generatedStreetAddressElements.size(), 3);
    ASSERT_TRUE(generatedBuildingNumber.size() >= 3 && generatedBuildingNumber.size() <= 5);
    ASSERT_TRUE(checkIfAllCharactersAreNumeric(generatedBuildingNumber));
    ASSERT_TRUE(faker::testing::any_of(firstNames,
                    [&generatedFirstOrLastName](
                        auto firstName) { return firstName == generatedFirstOrLastName; })
        || faker::testing::any_of(
            person::data::english_last_names, [&generatedFirstOrLastName](auto lastName) {
                return lastName == generatedFirstOrLastName;
            }));
    ASSERT_TRUE(faker::testing::any_of(
        location::data::usa_street_suffixes, [&generatedStreetSuffix](auto streetSuffix) {
            return streetSuffix == generatedStreetSuffix;
        }));
}

TEST_F(LocationTest, shouldGeneratePolandStreet)
{
    const auto generatedStreet = location::street(location::address_country::poland);

    const auto generatedStreetElements = utils::split(generatedStreet, " ");

    const auto& generatedStreetPrefix = generatedStreetElements[0];
    const auto& generatedStreetName
        = utils::join({ generatedStreetElements.begin() + 1, generatedStreetElements.end() });

    ASSERT_TRUE(faker::testing::any_of(
        location::data::poland_street_prefixes, [&generatedStreetPrefix](auto streetPrefix) {
            return streetPrefix == generatedStreetPrefix;
        }));
    ASSERT_TRUE(faker::testing::any_of(location::data::poland_street_names,
        [&generatedStreetName](auto streetName) { return streetName == generatedStreetName; }));
}

TEST_F(LocationTest, shouldGeneratePolandStreetAddress)
{
    const auto generatedStreetAddress = location::street_address(location::address_country::poland);

    ASSERT_TRUE(faker::testing::any_of(
        location::data::poland_street_prefixes, [&generatedStreetAddress](auto prefix) {
            return generatedStreetAddress.find(prefix) != std::string::npos;
        }));
    ASSERT_TRUE(faker::testing::any_of(
        location::data::poland_street_names, [&generatedStreetAddress](auto street) {
            return generatedStreetAddress.find(street) != std::string::npos;
        }));
}

TEST_F(LocationTest, shouldGenerateRussiaStreet)
{
    const auto generatedStreet = location::street(location::address_country::russia);

    const auto generatedStreetElements = utils::split(generatedStreet, " ");

    const auto& generatedStreetPrefix = generatedStreetElements[0];
    const auto& generatedStreetSuffix
        = utils::join({ generatedStreetElements.begin() + 1, generatedStreetElements.end() });

    std::vector<std::string_view> firstNames { person::data::russian_male_first_names.begin(),
        person::data::russian_male_first_names.end() };
    firstNames.insert(firstNames.end(), person::data::russian_female_first_names.begin(),
        person::data::russian_female_first_names.end());

    std::vector<std::string_view> lastNames { person::data::russian_male_last_names.begin(),
        person::data::russian_male_last_names.end() };
    firstNames.insert(firstNames.end(), person::data::russian_female_last_names.begin(),
        person::data::russian_female_last_names.end());

    ASSERT_TRUE(faker::testing::any_of(
        location::data::russia_street_prefixes, [&generatedStreetPrefix](auto streetPrefix) {
            return streetPrefix == generatedStreetPrefix;
        }));
    ASSERT_TRUE(
        faker::testing::any_of(firstNames,
            [&generatedStreetSuffix](auto firstName) { return firstName == generatedStreetSuffix; })
        || faker::testing::any_of(lastNames,
            [&generatedStreetSuffix](auto lastName) { return lastName == generatedStreetSuffix; })
        || faker::testing::any_of(
            location::data::russia_street_names, [&generatedStreetSuffix](auto streetName) {
                return streetName == generatedStreetSuffix;
            }));
}

TEST_F(LocationTest, shouldGenerateRussiaStreetAddress)
{
    const auto generatedStreetAddress = location::street_address(location::address_country::russia);

    std::vector<std::string_view> firstNames { person::data::russian_male_first_names.begin(),
        person::data::russian_male_first_names.end() };
    firstNames.insert(firstNames.end(), person::data::russian_female_first_names.begin(),
        person::data::russian_female_first_names.end());

    std::vector<std::string_view> lastNames { person::data::russian_male_last_names.begin(),
        person::data::russian_male_last_names.end() };
    lastNames.insert(lastNames.end(), person::data::russian_female_last_names.begin(),
        person::data::russian_female_last_names.end());

    ASSERT_TRUE(faker::testing::any_of(
        location::data::russia_street_prefixes, [&generatedStreetAddress](auto prefix) {
            return generatedStreetAddress.find(prefix) != std::string::npos;
        }));
    ASSERT_TRUE(faker::testing::any_of(firstNames,
                    [&generatedStreetAddress](auto firstName) {
                        return generatedStreetAddress.find(firstName) != std::string::npos;
                    })
        || faker::testing::any_of(lastNames,
            [&generatedStreetAddress](auto lastName) {
                return generatedStreetAddress.find(lastName) != std::string::npos;
            })
        || faker::testing::any_of(
            location::data::russia_street_names, [&generatedStreetAddress](auto streetName) {
                return generatedStreetAddress.find(streetName) != std::string::npos;
            }));
}

TEST_F(LocationTest, shouldGenerateFranceStreet)
{
    const auto generatedStreet = location::street(location::address_country::france);

    const auto generatedStreetElements = utils::split(generatedStreet, " ");

    const auto& generatedStreetPrefix = generatedStreetElements[0];
    const auto& generatedStreetSuffix
        = utils::join({ generatedStreetElements.begin() + 1, generatedStreetElements.end() });

    ASSERT_GE(generatedStreetElements.size(), 2);
    ASSERT_TRUE(faker::testing::any_of(
        location::data::france_street_prefixes, [&generatedStreetPrefix](auto streetPrefix) {
            return streetPrefix == generatedStreetPrefix;
        }));
    ASSERT_TRUE(faker::testing::any_of(
        location::data::france_street_suffixes, [&generatedStreetSuffix](auto streetSuffix) {
            return streetSuffix == generatedStreetSuffix;
        }));
}

TEST_F(LocationTest, shouldGenerateFranceStreetAddress)
{
    const auto generatedStreetAddress = location::street_address(location::address_country::france);

    const auto generatedStreetAddressElements = utils::split(generatedStreetAddress, " ");

    const auto& generatedBuildingNumber = generatedStreetAddressElements[0];
    const auto& generatedStreetPrefix = generatedStreetAddressElements[1];
    const auto& generatedStreetSuffix = utils::join(
        { generatedStreetAddressElements.begin() + 2, generatedStreetAddressElements.end() });

    ASSERT_GE(generatedStreetAddressElements.size(), 3);
    ASSERT_TRUE(!generatedBuildingNumber.empty() && generatedBuildingNumber.size() <= 4);
    ASSERT_TRUE(checkIfAllCharactersAreNumeric(generatedBuildingNumber));
    ASSERT_TRUE(
        faker::testing::contains(location::data::france_street_prefixes, generatedStreetPrefix));
    FAKER_EXPECT_CONTAINER_CONTAINS(location::data::france_street_suffixes, generatedStreetSuffix);
}

TEST_F(LocationTest, shouldGenerateCountry)
{
    const auto generatedCountry = location::country_name();

    FAKER_EXPECT_CONTAINER_CONTAINS(location::data::all_countries, generatedCountry);
}

TEST_F(LocationTest, shouldGenerateCountryCode)
{
    const auto generatedCountryCode = location::country_code();

    FAKER_EXPECT_CONTAINER_CONTAINS(location::data::country_codes, generatedCountryCode);
}

TEST_F(LocationTest, shouldGenerateLatitude)
{
    const auto latitude = location::latitude();

    auto offset = latitude.size();
    const auto latitudeAsFloat = std::stof(latitude, &offset);

    const auto generatedLatitudeParts = utils::split(latitude, ".");

    ASSERT_EQ(generatedLatitudeParts.size(), 2);
    ASSERT_EQ(generatedLatitudeParts[1].size(), 4);
    ASSERT_GE(latitudeAsFloat, -90);
    ASSERT_LE(latitudeAsFloat, 90);
}

TEST_F(LocationTest, shouldGenerateLatitudeWithSpecifiedPrecision)
{
    const auto latitude = location::latitude(precision_t::three_dp);

    auto offset = latitude.size();
    const auto latitudeAsFloat = std::stof(latitude, &offset);

    const auto generatedLatitudeParts = utils::split(latitude, ".");

    ASSERT_EQ(generatedLatitudeParts.size(), 2);
    ASSERT_EQ(generatedLatitudeParts[1].size(), 3);
    ASSERT_GE(latitudeAsFloat, -90);
    ASSERT_LE(latitudeAsFloat, 90);
}

TEST_F(LocationTest, shouldGenerateLongitude)
{
    const auto longitude = location::longitude();

    auto offset = longitude.size();
    const auto longitudeAsFloat = std::stof(longitude, &offset);

    const auto generatedLongitudeParts = utils::split(longitude, ".");

    ASSERT_EQ(generatedLongitudeParts.size(), 2);
    ASSERT_EQ(generatedLongitudeParts[1].size(), 4);
    ASSERT_GE(longitudeAsFloat, -180);
    ASSERT_LE(longitudeAsFloat, 180);
}

TEST_F(LocationTest, shouldGenerateLongitudeWithSpecifiedPrecision)
{
    const auto longitude = location::longitude(precision_t::six_dp);

    auto offset = longitude.size();
    const auto longitudeAsFloat = std::stof(longitude, &offset);

    const auto generatedLongitudeParts = utils::split(longitude, ".");

    ASSERT_EQ(generatedLongitudeParts.size(), 2);
    ASSERT_EQ(generatedLongitudeParts[1].size(), 6);
    ASSERT_GE(longitudeAsFloat, -180);
    ASSERT_LE(longitudeAsFloat, 180);
}

TEST_F(LocationTest, shouldGenerateDirection)
{
    const auto generatedDirection = location::direction();

    FAKER_EXPECT_CONTAINER_CONTAINS(location::data::directions, generatedDirection);
}

TEST_F(LocationTest, shouldGenerateTimeZone)
{
    const auto generatedTimeZone = location::time_zone();

    FAKER_EXPECT_CONTAINER_CONTAINS(location::data::time_zones, generatedTimeZone);
}

TEST_F(LocationTest, shouldGenerateUkraineStreet)
{
    const auto generatedStreet = location::street(location::address_country::ukraine);

    const auto generatedStreetElements = utils::split(generatedStreet, " ");

    const auto& generatedStreetPrefix = generatedStreetElements[0];
    const auto& generatedStreetSuffix
        = utils::join({ generatedStreetElements.begin() + 1, generatedStreetElements.end() });

    FAKER_EXPECT_CONTAINER_CONTAINS(location::data::ukraine_street_prefixes, generatedStreetPrefix);

    std::vector<std::string_view> firstNames { person::data::ukrainian_male_first_names.begin(),
        person::data::ukrainian_male_first_names.end() };
    firstNames.insert(firstNames.end(), person::data::ukrainian_female_first_names.begin(),
        person::data::ukrainian_female_first_names.end());

    std::vector<std::string_view> lastNames { person::data::ukrainian_males_last_names.begin(),
        person::data::ukrainian_males_last_names.end() };
    lastNames.insert(lastNames.end(), person::data::ukrainian_female_last_names.begin(),
        person::data::ukrainian_female_last_names.end());

    ASSERT_TRUE(faker::testing::any_of(firstNames,
                    [&generatedStreetSuffix](auto firstName) {
                        return generatedStreetSuffix.find(firstName) != std::string::npos;
                    })
        || faker::testing::any_of(lastNames,
            [&generatedStreetSuffix](auto lastName) {
                return generatedStreetSuffix.find(lastName) != std::string::npos;
            })
        || faker::testing::any_of(
            location::data::ukraine_street_names, [&generatedStreetSuffix](auto streetName) {
                return generatedStreetSuffix.find(streetName) != std::string::npos;
            }));
}

TEST_F(LocationTest, shouldGenerateUkraineStreetAddress)
{
    const auto generatedStreetAddress
        = location::street_address(location::address_country::ukraine);

    ASSERT_TRUE(faker::testing::any_of(
        location::data::ukraine_street_prefixes, [&generatedStreetAddress](auto prefix) {
            return generatedStreetAddress.find(prefix) != std::string::npos;
        }));

    std::vector<std::string_view> firstNames { person::data::ukrainian_male_first_names.begin(),
        person::data::ukrainian_male_first_names.end() };
    firstNames.insert(firstNames.end(), person::data::ukrainian_female_first_names.begin(),
        person::data::ukrainian_female_first_names.end());

    std::vector<std::string_view> lastNames { person::data::ukrainian_males_last_names.begin(),
        person::data::ukrainian_males_last_names.end() };
    lastNames.insert(lastNames.end(), person::data::ukrainian_female_last_names.begin(),
        person::data::ukrainian_female_last_names.end());

    ASSERT_TRUE(faker::testing::any_of(firstNames,
                    [&generatedStreetAddress](auto firstName) {
                        return generatedStreetAddress.find(firstName) != std::string::npos;
                    })
        || faker::testing::any_of(lastNames,
            [&generatedStreetAddress](auto lastName) {
                return generatedStreetAddress.find(lastName) != std::string::npos;
            })
        || faker::testing::any_of(
            location::data::ukraine_street_names, [&generatedStreetAddress](auto streetName) {
                return generatedStreetAddress.find(streetName) != std::string::npos;
            }));
}

TEST_F(LocationTest, shouldGenerateItalyStreet)
{
    const auto generatedStreet = location::street(location::address_country::italy);

    const auto generatedStreetElements = utils::split(generatedStreet, " ");

    const auto& generatedStreetPrefix = generatedStreetElements[0];
    const auto& generatedStreetSuffix
        = utils::join({ generatedStreetElements.begin() + 1, generatedStreetElements.end() });

    ASSERT_TRUE(faker::testing::any_of(
        location::data::italy_street_prefixes, [&generatedStreetPrefix](auto streetPrefix) {
            return streetPrefix == generatedStreetPrefix;
        }));

    std::vector<std::string_view> firstNames { person::data::italian_male_first_names.begin(),
        person::data::italian_male_first_names.end() };
    firstNames.insert(firstNames.end(), person::data::italian_female_first_names.begin(),
        person::data::italian_female_first_names.end());

    std::vector<std::string_view> lastNames { person::data::italian_last_names.begin(),
        person::data::italian_last_names.end() };

    ASSERT_TRUE(faker::testing::any_of(firstNames, [&generatedStreetSuffix](auto firstName) {
        return generatedStreetSuffix.find(firstName) != std::string::npos;
    }) || faker::testing::any_of(lastNames, [&generatedStreetSuffix](auto lastName) {
        return generatedStreetSuffix.find(lastName) != std::string::npos;
    }));
}

TEST_F(LocationTest, shouldGenerateItalyStreetAddress)
{
    const auto generatedStreetAddress = location::street_address(location::address_country::italy);

    ASSERT_TRUE(faker::testing::any_of(
        location::data::italy_street_prefixes, [&generatedStreetAddress](auto prefix) {
            return generatedStreetAddress.find(prefix) != std::string::npos;
        }));

    std::vector<std::string_view> firstNames { person::data::italian_male_first_names.begin(),
        person::data::italian_male_first_names.end() };
    firstNames.insert(firstNames.end(), person::data::italian_female_first_names.begin(),
        person::data::italian_female_first_names.end());

    std::vector<std::string_view> lastNames { person::data::italian_last_names.begin(),
        person::data::italian_last_names.end() };

    ASSERT_TRUE(faker::testing::any_of(firstNames, [&generatedStreetAddress](auto firstName) {
        return generatedStreetAddress.find(firstName) != std::string::npos;
    }) || faker::testing::any_of(lastNames, [&generatedStreetAddress](auto lastName) {
        return generatedStreetAddress.find(lastName) != std::string::npos;
    }));
}

TEST_F(LocationTest, shouldGenerateGermanyStreet)
{
    const auto generatedStreet = location::street(location::address_country::germany);

    FAKER_EXPECT_CONTAINER_CONTAINS(location::data::germany_street_names, generatedStreet);
}

TEST_F(LocationTest, shouldGenerateGermanyStreetAddress)
{
    const auto generatedStreetAddress
        = location::street_address(location::address_country::germany);

    ASSERT_TRUE(faker::testing::any_of(
        location::data::germany_street_names, [&generatedStreetAddress](auto streetName) {
            return generatedStreetAddress.find(streetName) != std::string::npos;
        }));
}

TEST_F(LocationTest, shouldGenerateCzechStreet)
{
    const auto generatedStreet = location::street(location::address_country::czechia);

    ASSERT_TRUE(faker::testing::any_of(location::data::czech_street_names,
        [&generatedStreet](auto streetName) { return streetName == generatedStreet; }));
}

TEST_F(LocationTest, shouldGenerateCzechStreetAddress)
{
    const auto generatedStreetAddress
        = location::street_address(location::address_country::czechia);

    ASSERT_TRUE(faker::testing::any_of(
        location::data::czech_street_names, [&generatedStreetAddress](auto streetName) {
            return generatedStreetAddress.find(streetName) != std::string::npos;
        }));
}

TEST_F(LocationTest, shouldGenerateAustraliaStreet)
{
    const auto generatedStreet = location::street(location::address_country::australia);

    std::vector<std::string_view> firstNames { person::data::australian_male_first_names.begin(),
        person::data::australian_male_first_names.end() };
    firstNames.insert(firstNames.end(), person::data::australian_female_first_names.begin(),
        person::data::australian_female_first_names.end());

    std::vector<std::string_view> lastNames { person::data::australian_last_names.begin(),
        person::data::australian_last_names.end() };

    ASSERT_TRUE((faker::testing::any_of(firstNames,
                     [&generatedStreet](auto firstName) {
                         return generatedStreet.find(firstName) != std::string::npos;
                     })
                    || faker::testing::any_of(lastNames,
                        [&generatedStreet](auto lastName) {
                            return generatedStreet.find(lastName) != std::string::npos;
                        }))
        && faker::testing::any_of(
            location::data::australia_street_suffixes, [&generatedStreet](auto streetSuffix) {
                return generatedStreet.find(streetSuffix) != std::string::npos;
            }));
}

TEST_F(LocationTest, shouldGenerateAustraliaStreetAddress)
{
    const auto generatedStreetAddress
        = location::street_address(location::address_country::australia);

    const auto generatedStreetAddressElements = utils::split(generatedStreetAddress, " ");

    const auto& generatedBuildingNumber = generatedStreetAddressElements[0];
    const auto& generatedStreetSuffix = utils::join(
        { generatedStreetAddressElements.begin() + 1, generatedStreetAddressElements.end() });

    std::vector<std::string_view> firstNames { person::data::australian_male_first_names.begin(),
        person::data::australian_male_first_names.end() };
    firstNames.insert(firstNames.end(), person::data::australian_female_first_names.begin(),
        person::data::australian_female_first_names.end());

    std::vector<std::string_view> lastNames { person::data::australian_last_names.begin(),
        person::data::australian_last_names.end() };

    ASSERT_TRUE(!generatedBuildingNumber.empty() && generatedBuildingNumber.size() <= 4);
    ASSERT_TRUE(checkIfAllCharactersAreNumeric(generatedBuildingNumber));

    ASSERT_TRUE((faker::testing::any_of(firstNames,
                     [&generatedStreetSuffix](auto firstName) {
                         return generatedStreetSuffix.find(firstName) != std::string::npos;
                     })
                    || faker::testing::any_of(lastNames,
                        [&generatedStreetSuffix](auto lastName) {
                            return generatedStreetSuffix.find(lastName) != std::string::npos;
                        }))
        && faker::testing::any_of(
            location::data::australia_street_suffixes, [&generatedStreetSuffix](auto streetSuffix) {
                return generatedStreetSuffix.find(streetSuffix) != std::string::npos;
            }));
}

TEST_F(LocationTest, shouldGenerateIndiaStreet)
{
    const auto generatedStreet = location::street(location::address_country::india);

    const auto generatedStreetElements = utils::split(generatedStreet, " ");

    const auto& generatedStreetSuffix
        = utils::join({ generatedStreetElements.begin() + 1, generatedStreetElements.end() });

    ASSERT_GE(generatedStreetElements.size(), 2);
    ASSERT_TRUE(faker::testing::any_of(
        location::data::india_street_suffixes, [&generatedStreetSuffix](auto streetSuffix) {
            return streetSuffix == generatedStreetSuffix;
        }));
}

TEST_F(LocationTest, shouldGenerateIndiaStreetAddress)
{
    const auto generatedStreetAddress = location::street_address(location::address_country::india);

    const auto generatedStreetAddressElements = utils::split(generatedStreetAddress, " ");

    const auto& generatedBuildingNumber = generatedStreetAddressElements[0];
    const auto& generatedStreetSuffix = utils::join(
        { generatedStreetAddressElements.begin() + 2, generatedStreetAddressElements.end() });

    ASSERT_GE(generatedStreetAddressElements.size(), 3);
    ASSERT_TRUE(!generatedBuildingNumber.empty());
    ASSERT_TRUE(checkIfAllCharactersAreNumeric(generatedBuildingNumber));
    FAKER_EXPECT_CONTAINER_CONTAINS(location::data::india_street_suffixes, generatedStreetSuffix);
}

TEST_F(LocationTest, shouldGenerateDenmarkStreet)
{
    const auto generatedStreet = location::street(location::address_country::denmark);

    FAKER_EXPECT_CONTAINER_CONTAINS(location::data::denmark_street_names, generatedStreet);
}

TEST_F(LocationTest, shouldGenerateDenmarkStreetAddress)
{
    const auto generatedStreetAddress
        = location::street_address(location::address_country::denmark);

    ASSERT_TRUE(faker::testing::any_of(
        location::data::denmark_street_names, [&generatedStreetAddress](auto streetName) {
            return generatedStreetAddress.find(streetName) != std::string::npos;
        }));
}

TEST_F(LocationTest, shouldGenerateSpainStreet)
{
    const auto generatedStreet = location::street(location::address_country::spain);

    std::vector<std::string_view> firstNames { person::data::spanish_male_first_names.begin(),
        person::data::spanish_male_first_names.end() };
    firstNames.insert(firstNames.end(), person::data::spanish_female_first_names.begin(),
        person::data::spanish_female_first_names.end());

    std::vector<std::string_view> lastNames { person::data::spanish_last_names.begin(),
        person::data::spanish_last_names.end() };

    ASSERT_TRUE((faker::testing::any_of(firstNames,
                     [&generatedStreet](auto firstName) {
                         return generatedStreet.find(firstName) != std::string::npos;
                     })
                    || faker::testing::any_of(lastNames,
                        [&generatedStreet](auto lastName) {
                            return generatedStreet.find(lastName) != std::string::npos;
                        }))
        && faker::testing::any_of(
            location::data::spain_street_suffixes, [&generatedStreet](auto streetSuffix) {
                return generatedStreet.find(streetSuffix) != std::string::npos;
            }));
}

TEST_F(LocationTest, shouldGenerateSpainStreetAddress)
{
    const auto generatedStreetAddress = location::street_address(location::address_country::spain);

    ASSERT_TRUE(faker::testing::any_of(
        location::data::spain_street_suffixes, [&generatedStreetAddress](auto suffix) {
            return generatedStreetAddress.find(suffix) != std::string::npos;
        }));

    std::vector<std::string_view> firstNames { person::data::spanish_male_first_names.begin(),
        person::data::spanish_male_first_names.end() };
    firstNames.insert(firstNames.end(), person::data::spanish_female_first_names.begin(),
        person::data::spanish_female_first_names.end());

    std::vector<std::string_view> lastNames { person::data::spanish_last_names.begin(),
        person::data::spanish_last_names.end() };

    ASSERT_TRUE(faker::testing::any_of(firstNames, [&generatedStreetAddress](auto firstName) {
        return generatedStreetAddress.find(firstName) != std::string::npos;
    }) || faker::testing::any_of(lastNames, [&generatedStreetAddress](auto lastName) {
        return generatedStreetAddress.find(lastName) != std::string::npos;
    }));
}

TEST_F(LocationTest, shouldGenerateFinlandStreet)
{
    const auto generatedStreet = location::street(location::address_country::finland);

    const auto generatedStreetElements = utils::split(generatedStreet, " ");

    const auto& generatedStreetPrefix = generatedStreetElements[0];
    const auto& generatedStreetSuffix = generatedStreetElements[1];

    std::vector<std::string_view> firstNames { person::data::finnish_male_first_names.begin(),
        person::data::finnish_male_first_names.end() };
    firstNames.insert(firstNames.end(), person::data::finnish_female_first_names.begin(),
        person::data::finnish_female_first_names.end());

    std::vector<std::string_view> lastNames { person::data::finnish_last_names.begin(),
        person::data::finnish_last_names.end() };

    ASSERT_GE(generatedStreetElements.size(), 2);

    FAKER_EXPECT_CONTAINER_CONTAINS(location::data::finland_street_suffixes, generatedStreetSuffix);

    ASSERT_TRUE(faker::testing::any_of(firstNames, [&generatedStreetPrefix](auto firstName) {
        return generatedStreetPrefix.find(firstName) != std::string::npos;
    }) || faker::testing::any_of(lastNames, [&generatedStreetPrefix](auto lastName) {
        return generatedStreetPrefix.find(lastName) != std::string::npos;
    }));
}

TEST_F(LocationTest, shouldGenerateFinlandStreetAddress)
{
    const auto generatedStreetAddress
        = location::street_address(location::address_country::finland);

    ASSERT_TRUE(faker::testing::any_of(
        location::data::finland_street_suffixes, [&generatedStreetAddress](auto suffix) {
            return generatedStreetAddress.find(suffix) != std::string::npos;
        }));

    std::vector<std::string_view> firstNames { person::data::finnish_male_first_names.begin(),
        person::data::finnish_male_first_names.end() };
    firstNames.insert(firstNames.end(), person::data::finnish_female_first_names.begin(),
        person::data::finnish_female_first_names.end());

    std::vector<std::string_view> lastNames { person::data::finnish_last_names.begin(),
        person::data::finnish_last_names.end() };

    ASSERT_TRUE(faker::testing::any_of(firstNames, [&generatedStreetAddress](auto firstName) {
        return generatedStreetAddress.find(firstName) != std::string::npos;
    }) || faker::testing::any_of(lastNames, [&generatedStreetAddress](auto lastName) {
        return generatedStreetAddress.find(lastName) != std::string::npos;
    }));
}

TEST_F(LocationTest, shouldGenerateEstoniaStreet)
{
    const auto generatedStreet = location::street(location::address_country::estonia);

    ASSERT_TRUE(faker::testing::any_of(
        location::data::estonia_street_names, [&generatedStreet](auto streetName) {
            return generatedStreet.find(streetName) != std::string::npos;
        }));
}

TEST_F(LocationTest, shouldGenerateEstoniaStreetAddress)
{
    const auto generatedStreetAddress
        = location::street_address(location::address_country::estonia);

    ASSERT_TRUE(faker::testing::any_of(
        location::data::estonia_street_names, [&generatedStreetAddress](auto streetName) {
            return generatedStreetAddress.find(streetName) != std::string::npos;
        }));
}
