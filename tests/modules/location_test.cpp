#include "../test_helpers.h"
#include <algorithm>
#include <common/string_helper.h>
#include <faker/location.h>
#include <modules/location_data.h>
#include <modules/person_data.h>
#include <modules/string_data.h>

using namespace ::testing;
using namespace faker;

const std::array<location::AddressCountry, 14> addressCountries {
    location::AddressCountry::Usa,
    location::AddressCountry::Poland,
    location::AddressCountry::France,
    location::AddressCountry::Russia,
    location::AddressCountry::Ukraine,
    location::AddressCountry::Italy,
    location::AddressCountry::Germany,
    location::AddressCountry::Czech,
    location::AddressCountry::India,
    location::AddressCountry::Denmark,
    location::AddressCountry::Australia,
    location::AddressCountry::Spain,
    location::AddressCountry::Brazil,
    location::AddressCountry::Finland,
};

const location::data::CountryAddresses& countryToCountryAddressesMapping(
    location::AddressCountry country)
{
    switch (country) {
    case location::AddressCountry::Usa:
        return location::data::usaAddresses;
    case location::AddressCountry::Poland:
        return location::data::polandAddresses;
    case location::AddressCountry::Russia:
        return location::data::russiaAddresses;
    case location::AddressCountry::France:
        return location::data::franceAddresses;
    case location::AddressCountry::Ukraine:
        return location::data::ukraineAddresses;
    case location::AddressCountry::Italy:
        return location::data::italyAddresses;
    case location::AddressCountry::Germany:
        return location::data::germanyAddresses;
    case location::AddressCountry::Czech:
        return location::data::czechAddresses;
    case location::AddressCountry::Australia:
        return location::data::australiaAddresses;
    case location::AddressCountry::India:
        return location::data::indiaAddresses;
    case location::AddressCountry::Denmark:
        return location::data::denmarkAddresses;
    case location::AddressCountry::Spain:
        return location::data::spainAddresses;
    case location::AddressCountry::Brazil:
        return location::data::brazilAddresses;
    case location::AddressCountry::Finland:
        return location::data::finlandAddresses;
    case location::AddressCountry::Estonia:
        return location::data::estoniaAddresses;
    default:
        throw std::invalid_argument("Invalid country");
    }
}

const std::unordered_map<location::AddressCountry, std::string> generatedTestName {
    { location::AddressCountry::Usa, "shouldGenerateAmericanAddress" },
    { location::AddressCountry::France, "shouldGenerateFrenchAddress" },
    { location::AddressCountry::Poland, "shouldGeneratePolishAddress" },
    { location::AddressCountry::Russia, "shouldGenerateRussianAddress" },
    { location::AddressCountry::Ukraine, "shouldGenerateUkrainianAddress" },
    { location::AddressCountry::Italy, "shouldGenerateItalianAddress" },
    { location::AddressCountry::Germany, "shouldGenerateGermanAddress" },
    { location::AddressCountry::Czech, "shouldGenerateCzechAddress" },
    { location::AddressCountry::Australia, "shouldGenerateAustraliaAddress" },
    { location::AddressCountry::India, "shouldGenerateIndiaAddress" },
    { location::AddressCountry::Denmark, "shouldGenerateDenmarkAddress" },
    { location::AddressCountry::Spain, "shouldGenerateSpainAddress" },
    { location::AddressCountry::Brazil, "shouldGenerateBrazilAddress" },
    { location::AddressCountry::Finland, "shouldGenerateFinlandAddress" },
    { location::AddressCountry::Estonia, "shouldGenerateEstoniaAddress" },
};

class LocationTest : public TestWithParam<location::AddressCountry> {
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
                string::data::numericCharacters, [dataCharacter](char numericCharacter) {
                    return numericCharacter == dataCharacter;
                });
        });
    }

    static bool checkIfCharacterIsNumeric(char character)
    {
        return faker::testing::contains(string::data::numericCharacters, character);
    }
};

TEST_P(LocationTest, shouldGenerateCounty)
{
    const auto country = GetParam();

    const auto& countryAddresses = countryToCountryAddressesMapping(country);

    const auto generatedCounty = location::county(country);

    ASSERT_TRUE(faker::testing::contains(countryAddresses.counties, generatedCounty)
        || (countryAddresses.counties.empty() && generatedCounty.empty()));
}

TEST_P(LocationTest, shouldGenerateState)
{
    const auto country = GetParam();
    const auto& countryAddresses = countryToCountryAddressesMapping(country);

    const auto generatedState = location::state(country);

    FAKER_EXPECT_CONTAINER_CONTAINS(countryAddresses.states, generatedState);
}

TEST_P(LocationTest, shouldGenerateCity)
{
    const auto country = GetParam();

    const auto& countryAddresses = countryToCountryAddressesMapping(country);

    const auto generatedCity = location::city(country);

    if (country == faker::location::AddressCountry::Brazil) {
        const auto generatedCityElements = utils::split(generatedCity, " ");

        const auto& generatedCityPrefix = generatedCityElements[0];

        std::vector<std::string_view> firstNames { person::data::brazilianMalesFirstNames.begin(),
            person::data::brazilianMalesFirstNames.end() };
        firstNames.insert(firstNames.end(), person::data::brazilianFemalesFirstNames.begin(),
            person::data::brazilianFemalesFirstNames.end());

        std::vector<std::string_view> lastNames { person::data::brazilianLastNames.begin(),
            person::data::brazilianLastNames.end() };

        ASSERT_TRUE(faker::testing::any_of(firstNames,
                        [&generatedCityPrefix](auto firstName) {
                            return generatedCityPrefix.find(firstName) != std::string::npos;
                        })
            || faker::testing::any_of(lastNames,
                [&generatedCityPrefix](auto lastName) {
                    return generatedCityPrefix.find(lastName) != std::string::npos;
                })
            || faker::testing::any_of(
                location::data::brazilCitySuffixes, [&generatedCity](auto citySuffix) {
                    return generatedCity.find(citySuffix) != std::string::npos;
                }));
    } else {
        FAKER_EXPECT_CONTAINER_CONTAINS(countryAddresses.cities, generatedCity);
    }
}

TEST_P(LocationTest, shouldGenerateZipCode)
{
    const auto country = GetParam();

    const auto& countryAddresses = countryToCountryAddressesMapping(country);

    const auto generatedZipCode = location::zip_code(country);

    ASSERT_EQ(generatedZipCode.size(), countryAddresses.zipCodeFormat.size());
    ASSERT_TRUE(checkIfZipCode(generatedZipCode));
}

TEST_P(LocationTest, shouldGenerateBuildingNumber)
{
    const auto country = GetParam();

    const auto& countryAddresses = countryToCountryAddressesMapping(country);

    const auto generatedBuildingNumber = location::building_number(country);

    const auto generatedBuildingNumberExceptLastCharacter
        = generatedBuildingNumber.substr(0, generatedBuildingNumber.size() - 1);

    ASSERT_TRUE(faker::testing::any_of(countryAddresses.buildingNumberFormats,
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

    const auto& countryAddresses = countryToCountryAddressesMapping(country);

    const auto generatedSecondaryAddress = location::secondary_address(country);

    ASSERT_TRUE(
        (countryAddresses.secondaryAddressFormats.empty() && generatedSecondaryAddress.empty())
        || faker::testing::any_of(countryAddresses.secondaryAddressFormats,
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
    [](const TestParamInfo<location::AddressCountry>& info) {
        return generatedTestName.at(info.param);
    });

TEST_F(LocationTest, shouldGenerateUsaStreet)
{
    const auto generatedStreet = location::street();

    const auto generatedStreetElements = utils::split(generatedStreet, " ");

    const auto& generatedFirstOrLastName = generatedStreetElements[0];
    const auto& generatedStreetSuffix = generatedStreetElements[1];

    std::vector<std::string_view> firstNames { person::data::englishMalesFirstNames.begin(),
        person::data::englishMalesFirstNames.end() };
    firstNames.insert(firstNames.end(), person::data::englishFemalesFirstNames.begin(),
        person::data::englishFemalesFirstNames.end());

    ASSERT_EQ(generatedStreetElements.size(), 2);
    ASSERT_TRUE(faker::testing::any_of(firstNames,
                    [&generatedFirstOrLastName](
                        auto firstName) { return firstName == generatedFirstOrLastName; })
        || faker::testing::any_of(
            person::data::englishLastNames, [&generatedFirstOrLastName](auto lastName) {
                return lastName == generatedFirstOrLastName;
            }));
    FAKER_EXPECT_CONTAINER_CONTAINS(location::data::usaStreetSuffixes, generatedStreetSuffix);
}

TEST_F(LocationTest, shouldGenerateUsaStreetAddress)
{
    const auto generatedStreetAddress = location::street_address();

    const auto generatedStreetAddressElements = utils::split(generatedStreetAddress, " ");

    const auto& generatedBuildingNumber = generatedStreetAddressElements[0];
    const auto& generatedFirstOrLastName = generatedStreetAddressElements[1];
    const auto& generatedStreetSuffix = generatedStreetAddressElements[2];

    std::vector<std::string_view> firstNames { person::data::englishMalesFirstNames.begin(),
        person::data::englishMalesFirstNames.end() };
    firstNames.insert(firstNames.end(), person::data::englishFemalesFirstNames.begin(),
        person::data::englishFemalesFirstNames.end());

    ASSERT_EQ(generatedStreetAddressElements.size(), 3);
    ASSERT_TRUE(generatedBuildingNumber.size() >= 3 && generatedBuildingNumber.size() <= 5);
    ASSERT_TRUE(checkIfAllCharactersAreNumeric(generatedBuildingNumber));
    ASSERT_TRUE(faker::testing::any_of(firstNames,
                    [&generatedFirstOrLastName](
                        auto firstName) { return firstName == generatedFirstOrLastName; })
        || faker::testing::any_of(
            person::data::englishLastNames, [&generatedFirstOrLastName](auto lastName) {
                return lastName == generatedFirstOrLastName;
            }));
    ASSERT_TRUE(faker::testing::any_of(
        location::data::usaStreetSuffixes, [&generatedStreetSuffix](auto streetSuffix) {
            return streetSuffix == generatedStreetSuffix;
        }));
}

TEST_F(LocationTest, shouldGeneratePolandStreet)
{
    const auto generatedStreet = location::street(location::AddressCountry::Poland);

    const auto generatedStreetElements = utils::split(generatedStreet, " ");

    const auto& generatedStreetPrefix = generatedStreetElements[0];
    const auto& generatedStreetName
        = utils::join({ generatedStreetElements.begin() + 1, generatedStreetElements.end() });

    ASSERT_TRUE(faker::testing::any_of(
        location::data::polandStreetPrefixes, [&generatedStreetPrefix](auto streetPrefix) {
            return streetPrefix == generatedStreetPrefix;
        }));
    ASSERT_TRUE(faker::testing::any_of(location::data::polandStreetNames,
        [&generatedStreetName](auto streetName) { return streetName == generatedStreetName; }));
}

TEST_F(LocationTest, shouldGeneratePolandStreetAddress)
{
    const auto generatedStreetAddress = location::street_address(location::AddressCountry::Poland);

    ASSERT_TRUE(faker::testing::any_of(
        location::data::polandStreetPrefixes, [&generatedStreetAddress](auto prefix) {
            return generatedStreetAddress.find(prefix) != std::string::npos;
        }));
    ASSERT_TRUE(faker::testing::any_of(
        location::data::polandStreetNames, [&generatedStreetAddress](auto street) {
            return generatedStreetAddress.find(street) != std::string::npos;
        }));
}

TEST_F(LocationTest, shouldGenerateRussiaStreet)
{
    const auto generatedStreet = location::street(location::AddressCountry::Russia);

    const auto generatedStreetElements = utils::split(generatedStreet, " ");

    const auto& generatedStreetPrefix = generatedStreetElements[0];
    const auto& generatedStreetSuffix
        = utils::join({ generatedStreetElements.begin() + 1, generatedStreetElements.end() });

    std::vector<std::string_view> firstNames { person::data::russianMalesFirstNames.begin(),
        person::data::russianMalesFirstNames.end() };
    firstNames.insert(firstNames.end(), person::data::russianFemalesFirstNames.begin(),
        person::data::russianFemalesFirstNames.end());

    std::vector<std::string_view> lastNames { person::data::russianMalesLastNames.begin(),
        person::data::russianMalesLastNames.end() };
    firstNames.insert(firstNames.end(), person::data::russianFemalesLastNames.begin(),
        person::data::russianFemalesLastNames.end());

    ASSERT_TRUE(faker::testing::any_of(
        location::data::russiaStreetPrefixes, [&generatedStreetPrefix](auto streetPrefix) {
            return streetPrefix == generatedStreetPrefix;
        }));
    ASSERT_TRUE(
        faker::testing::any_of(firstNames,
            [&generatedStreetSuffix](auto firstName) { return firstName == generatedStreetSuffix; })
        || faker::testing::any_of(lastNames,
            [&generatedStreetSuffix](auto lastName) { return lastName == generatedStreetSuffix; })
        || faker::testing::any_of(
            location::data::russiaStreetNames, [&generatedStreetSuffix](auto streetName) {
                return streetName == generatedStreetSuffix;
            }));
}

TEST_F(LocationTest, shouldGenerateRussiaStreetAddress)
{
    const auto generatedStreetAddress = location::street_address(location::AddressCountry::Russia);

    std::vector<std::string_view> firstNames { person::data::russianMalesFirstNames.begin(),
        person::data::russianMalesFirstNames.end() };
    firstNames.insert(firstNames.end(), person::data::russianFemalesFirstNames.begin(),
        person::data::russianFemalesFirstNames.end());

    std::vector<std::string_view> lastNames { person::data::russianMalesLastNames.begin(),
        person::data::russianMalesLastNames.end() };
    lastNames.insert(lastNames.end(), person::data::russianFemalesLastNames.begin(),
        person::data::russianFemalesLastNames.end());

    ASSERT_TRUE(faker::testing::any_of(
        location::data::russiaStreetPrefixes, [&generatedStreetAddress](auto prefix) {
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
            location::data::russiaStreetNames, [&generatedStreetAddress](auto streetName) {
                return generatedStreetAddress.find(streetName) != std::string::npos;
            }));
}

TEST_F(LocationTest, shouldGenerateFranceStreet)
{
    const auto generatedStreet = location::street(location::AddressCountry::France);

    const auto generatedStreetElements = utils::split(generatedStreet, " ");

    const auto& generatedStreetPrefix = generatedStreetElements[0];
    const auto& generatedStreetSuffix
        = utils::join({ generatedStreetElements.begin() + 1, generatedStreetElements.end() });

    ASSERT_GE(generatedStreetElements.size(), 2);
    ASSERT_TRUE(faker::testing::any_of(
        location::data::franceStreetPrefixes, [&generatedStreetPrefix](auto streetPrefix) {
            return streetPrefix == generatedStreetPrefix;
        }));
    ASSERT_TRUE(faker::testing::any_of(
        location::data::franceStreetSuffixes, [&generatedStreetSuffix](auto streetSuffix) {
            return streetSuffix == generatedStreetSuffix;
        }));
}

TEST_F(LocationTest, shouldGenerateFranceStreetAddress)
{
    const auto generatedStreetAddress = location::street_address(location::AddressCountry::France);

    const auto generatedStreetAddressElements = utils::split(generatedStreetAddress, " ");

    const auto& generatedBuildingNumber = generatedStreetAddressElements[0];
    const auto& generatedStreetPrefix = generatedStreetAddressElements[1];
    const auto& generatedStreetSuffix = utils::join(
        { generatedStreetAddressElements.begin() + 2, generatedStreetAddressElements.end() });

    ASSERT_GE(generatedStreetAddressElements.size(), 3);
    ASSERT_TRUE(!generatedBuildingNumber.empty() && generatedBuildingNumber.size() <= 4);
    ASSERT_TRUE(checkIfAllCharactersAreNumeric(generatedBuildingNumber));
    ASSERT_TRUE(
        faker::testing::contains(location::data::franceStreetPrefixes, generatedStreetPrefix));
    FAKER_EXPECT_CONTAINER_CONTAINS(location::data::franceStreetSuffixes, generatedStreetSuffix);
}

TEST_F(LocationTest, shouldGenerateCountry)
{
    const auto generatedCountry = location::country_name();

    FAKER_EXPECT_CONTAINER_CONTAINS(location::data::allCountries, generatedCountry);
}

TEST_F(LocationTest, shouldGenerateCountryCode)
{
    const auto generatedCountryCode = location::country_code();

    FAKER_EXPECT_CONTAINER_CONTAINS(location::data::countryCodes, generatedCountryCode);
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
    const auto latitude = location::latitude(Precision::ThreeDp);

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
    const auto longitude = location::longitude(Precision::SixDp);

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

    FAKER_EXPECT_CONTAINER_CONTAINS(location::data::timeZones, generatedTimeZone);
}

TEST_F(LocationTest, shouldGenerateUkraineStreet)
{
    const auto generatedStreet = location::street(location::AddressCountry::Ukraine);

    const auto generatedStreetElements = utils::split(generatedStreet, " ");

    const auto& generatedStreetPrefix = generatedStreetElements[0];
    const auto& generatedStreetSuffix
        = utils::join({ generatedStreetElements.begin() + 1, generatedStreetElements.end() });

    FAKER_EXPECT_CONTAINER_CONTAINS(location::data::ukraineStreetPrefixes, generatedStreetPrefix);

    std::vector<std::string_view> firstNames { person::data::ukrainianMalesFirstNames.begin(),
        person::data::ukrainianMalesFirstNames.end() };
    firstNames.insert(firstNames.end(), person::data::ukrainianFemalesFirstNames.begin(),
        person::data::ukrainianFemalesFirstNames.end());

    std::vector<std::string_view> lastNames { person::data::ukrainianMalesLastNames.begin(),
        person::data::ukrainianMalesLastNames.end() };
    lastNames.insert(lastNames.end(), person::data::ukrainianFemalesLastNames.begin(),
        person::data::ukrainianFemalesLastNames.end());

    ASSERT_TRUE(faker::testing::any_of(firstNames,
                    [&generatedStreetSuffix](auto firstName) {
                        return generatedStreetSuffix.find(firstName) != std::string::npos;
                    })
        || faker::testing::any_of(lastNames,
            [&generatedStreetSuffix](auto lastName) {
                return generatedStreetSuffix.find(lastName) != std::string::npos;
            })
        || faker::testing::any_of(
            location::data::ukraineStreetNames, [&generatedStreetSuffix](auto streetName) {
                return generatedStreetSuffix.find(streetName) != std::string::npos;
            }));
}

TEST_F(LocationTest, shouldGenerateUkraineStreetAddress)
{
    const auto generatedStreetAddress = location::street_address(location::AddressCountry::Ukraine);

    ASSERT_TRUE(faker::testing::any_of(
        location::data::ukraineStreetPrefixes, [&generatedStreetAddress](auto prefix) {
            return generatedStreetAddress.find(prefix) != std::string::npos;
        }));

    std::vector<std::string_view> firstNames { person::data::ukrainianMalesFirstNames.begin(),
        person::data::ukrainianMalesFirstNames.end() };
    firstNames.insert(firstNames.end(), person::data::ukrainianFemalesFirstNames.begin(),
        person::data::ukrainianFemalesFirstNames.end());

    std::vector<std::string_view> lastNames { person::data::ukrainianMalesLastNames.begin(),
        person::data::ukrainianMalesLastNames.end() };
    lastNames.insert(lastNames.end(), person::data::ukrainianFemalesLastNames.begin(),
        person::data::ukrainianFemalesLastNames.end());

    ASSERT_TRUE(faker::testing::any_of(firstNames,
                    [&generatedStreetAddress](auto firstName) {
                        return generatedStreetAddress.find(firstName) != std::string::npos;
                    })
        || faker::testing::any_of(lastNames,
            [&generatedStreetAddress](auto lastName) {
                return generatedStreetAddress.find(lastName) != std::string::npos;
            })
        || faker::testing::any_of(
            location::data::ukraineStreetNames, [&generatedStreetAddress](auto streetName) {
                return generatedStreetAddress.find(streetName) != std::string::npos;
            }));
}

TEST_F(LocationTest, shouldGenerateItalyStreet)
{
    const auto generatedStreet = location::street(location::AddressCountry::Italy);

    const auto generatedStreetElements = utils::split(generatedStreet, " ");

    const auto& generatedStreetPrefix = generatedStreetElements[0];
    const auto& generatedStreetSuffix
        = utils::join({ generatedStreetElements.begin() + 1, generatedStreetElements.end() });

    ASSERT_TRUE(faker::testing::any_of(
        location::data::italyStreetPrefixes, [&generatedStreetPrefix](auto streetPrefix) {
            return streetPrefix == generatedStreetPrefix;
        }));

    std::vector<std::string_view> firstNames { person::data::italianMalesFirstNames.begin(),
        person::data::italianMalesFirstNames.end() };
    firstNames.insert(firstNames.end(), person::data::italianFemalesFirstNames.begin(),
        person::data::italianFemalesFirstNames.end());

    std::vector<std::string_view> lastNames { person::data::italianLastNames.begin(),
        person::data::italianLastNames.end() };

    ASSERT_TRUE(faker::testing::any_of(firstNames, [&generatedStreetSuffix](auto firstName) {
        return generatedStreetSuffix.find(firstName) != std::string::npos;
    }) || faker::testing::any_of(lastNames, [&generatedStreetSuffix](auto lastName) {
        return generatedStreetSuffix.find(lastName) != std::string::npos;
    }));
}

TEST_F(LocationTest, shouldGenerateItalyStreetAddress)
{
    const auto generatedStreetAddress = location::street_address(location::AddressCountry::Italy);

    ASSERT_TRUE(faker::testing::any_of(
        location::data::italyStreetPrefixes, [&generatedStreetAddress](auto prefix) {
            return generatedStreetAddress.find(prefix) != std::string::npos;
        }));

    std::vector<std::string_view> firstNames { person::data::italianMalesFirstNames.begin(),
        person::data::italianMalesFirstNames.end() };
    firstNames.insert(firstNames.end(), person::data::italianFemalesFirstNames.begin(),
        person::data::italianFemalesFirstNames.end());

    std::vector<std::string_view> lastNames { person::data::italianLastNames.begin(),
        person::data::italianLastNames.end() };

    ASSERT_TRUE(faker::testing::any_of(firstNames, [&generatedStreetAddress](auto firstName) {
        return generatedStreetAddress.find(firstName) != std::string::npos;
    }) || faker::testing::any_of(lastNames, [&generatedStreetAddress](auto lastName) {
        return generatedStreetAddress.find(lastName) != std::string::npos;
    }));
}

TEST_F(LocationTest, shouldGenerateGermanyStreet)
{
    const auto generatedStreet = location::street(location::AddressCountry::Germany);

    FAKER_EXPECT_CONTAINER_CONTAINS(location::data::germanyStreetNames, generatedStreet);
}

TEST_F(LocationTest, shouldGenerateGermanyStreetAddress)
{
    const auto generatedStreetAddress = location::street_address(location::AddressCountry::Germany);

    ASSERT_TRUE(faker::testing::any_of(
        location::data::germanyStreetNames, [&generatedStreetAddress](auto streetName) {
            return generatedStreetAddress.find(streetName) != std::string::npos;
        }));
}

TEST_F(LocationTest, shouldGenerateCzechStreet)
{
    const auto generatedStreet = location::street(location::AddressCountry::Czech);

    ASSERT_TRUE(faker::testing::any_of(location::data::czechStreetNames,
        [&generatedStreet](auto streetName) { return streetName == generatedStreet; }));
}

TEST_F(LocationTest, shouldGenerateCzechStreetAddress)
{
    const auto generatedStreetAddress = location::street_address(location::AddressCountry::Czech);

    ASSERT_TRUE(faker::testing::any_of(
        location::data::czechStreetNames, [&generatedStreetAddress](auto streetName) {
            return generatedStreetAddress.find(streetName) != std::string::npos;
        }));
}

TEST_F(LocationTest, shouldGenerateAustraliaStreet)
{
    const auto generatedStreet = location::street(location::AddressCountry::Australia);

    std::vector<std::string_view> firstNames { person::data::australianMalesFirstNames.begin(),
        person::data::australianMalesFirstNames.end() };
    firstNames.insert(firstNames.end(), person::data::australianFemalesFirstNames.begin(),
        person::data::australianFemalesFirstNames.end());

    std::vector<std::string_view> lastNames { person::data::australianLastNames.begin(),
        person::data::australianLastNames.end() };

    ASSERT_TRUE((faker::testing::any_of(firstNames,
                     [&generatedStreet](auto firstName) {
                         return generatedStreet.find(firstName) != std::string::npos;
                     })
                    || faker::testing::any_of(lastNames,
                        [&generatedStreet](auto lastName) {
                            return generatedStreet.find(lastName) != std::string::npos;
                        }))
        && faker::testing::any_of(
            location::data::australiaStreetSuffixes, [&generatedStreet](auto streetSuffix) {
                return generatedStreet.find(streetSuffix) != std::string::npos;
            }));
}

TEST_F(LocationTest, shouldGenerateAustraliaStreetAddress)
{
    const auto generatedStreetAddress
        = location::street_address(location::AddressCountry::Australia);

    const auto generatedStreetAddressElements = utils::split(generatedStreetAddress, " ");

    const auto& generatedBuildingNumber = generatedStreetAddressElements[0];
    const auto& generatedStreetSuffix = utils::join(
        { generatedStreetAddressElements.begin() + 1, generatedStreetAddressElements.end() });

    std::vector<std::string_view> firstNames { person::data::australianMalesFirstNames.begin(),
        person::data::australianMalesFirstNames.end() };
    firstNames.insert(firstNames.end(), person::data::australianFemalesFirstNames.begin(),
        person::data::australianFemalesFirstNames.end());

    std::vector<std::string_view> lastNames { person::data::australianLastNames.begin(),
        person::data::australianLastNames.end() };

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
            location::data::australiaStreetSuffixes, [&generatedStreetSuffix](auto streetSuffix) {
                return generatedStreetSuffix.find(streetSuffix) != std::string::npos;
            }));
}

TEST_F(LocationTest, shouldGenerateIndiaStreet)
{
    const auto generatedStreet = location::street(location::AddressCountry::India);

    const auto generatedStreetElements = utils::split(generatedStreet, " ");

    const auto& generatedStreetSuffix
        = utils::join({ generatedStreetElements.begin() + 1, generatedStreetElements.end() });

    ASSERT_GE(generatedStreetElements.size(), 2);
    ASSERT_TRUE(faker::testing::any_of(
        location::data::indiaStreetSuffixes, [&generatedStreetSuffix](auto streetSuffix) {
            return streetSuffix == generatedStreetSuffix;
        }));
}

TEST_F(LocationTest, shouldGenerateIndiaStreetAddress)
{
    const auto generatedStreetAddress = location::street_address(location::AddressCountry::India);

    const auto generatedStreetAddressElements = utils::split(generatedStreetAddress, " ");

    const auto& generatedBuildingNumber = generatedStreetAddressElements[0];
    const auto& generatedStreetSuffix = utils::join(
        { generatedStreetAddressElements.begin() + 2, generatedStreetAddressElements.end() });

    ASSERT_GE(generatedStreetAddressElements.size(), 3);
    ASSERT_TRUE(!generatedBuildingNumber.empty());
    ASSERT_TRUE(checkIfAllCharactersAreNumeric(generatedBuildingNumber));
    FAKER_EXPECT_CONTAINER_CONTAINS(location::data::indiaStreetSuffixes, generatedStreetSuffix);
}

TEST_F(LocationTest, shouldGenerateDenmarkStreet)
{
    const auto generatedStreet = location::street(location::AddressCountry::Denmark);

    FAKER_EXPECT_CONTAINER_CONTAINS(location::data::denmarkStreetNames, generatedStreet);
}

TEST_F(LocationTest, shouldGenerateDenmarkStreetAddress)
{
    const auto generatedStreetAddress = location::street_address(location::AddressCountry::Denmark);

    ASSERT_TRUE(faker::testing::any_of(
        location::data::denmarkStreetNames, [&generatedStreetAddress](auto streetName) {
            return generatedStreetAddress.find(streetName) != std::string::npos;
        }));
}

TEST_F(LocationTest, shouldGenerateSpainStreet)
{
    const auto generatedStreet = location::street(location::AddressCountry::Spain);

    std::vector<std::string_view> firstNames { person::data::spanishMalesFirstNames.begin(),
        person::data::spanishMalesFirstNames.end() };
    firstNames.insert(firstNames.end(), person::data::spanishFemalesFirstNames.begin(),
        person::data::spanishFemalesFirstNames.end());

    std::vector<std::string_view> lastNames { person::data::spanishLastNames.begin(),
        person::data::spanishLastNames.end() };

    ASSERT_TRUE((faker::testing::any_of(firstNames,
                     [&generatedStreet](auto firstName) {
                         return generatedStreet.find(firstName) != std::string::npos;
                     })
                    || faker::testing::any_of(lastNames,
                        [&generatedStreet](auto lastName) {
                            return generatedStreet.find(lastName) != std::string::npos;
                        }))
        && faker::testing::any_of(
            location::data::spainStreetSuffixes, [&generatedStreet](auto streetSuffix) {
                return generatedStreet.find(streetSuffix) != std::string::npos;
            }));
}

TEST_F(LocationTest, shouldGenerateSpainStreetAddress)
{
    const auto generatedStreetAddress = location::street_address(location::AddressCountry::Spain);

    ASSERT_TRUE(faker::testing::any_of(
        location::data::spainStreetSuffixes, [&generatedStreetAddress](auto suffix) {
            return generatedStreetAddress.find(suffix) != std::string::npos;
        }));

    std::vector<std::string_view> firstNames { person::data::spanishMalesFirstNames.begin(),
        person::data::spanishMalesFirstNames.end() };
    firstNames.insert(firstNames.end(), person::data::spanishFemalesFirstNames.begin(),
        person::data::spanishFemalesFirstNames.end());

    std::vector<std::string_view> lastNames { person::data::spanishLastNames.begin(),
        person::data::spanishLastNames.end() };

    ASSERT_TRUE(faker::testing::any_of(firstNames, [&generatedStreetAddress](auto firstName) {
        return generatedStreetAddress.find(firstName) != std::string::npos;
    }) || faker::testing::any_of(lastNames, [&generatedStreetAddress](auto lastName) {
        return generatedStreetAddress.find(lastName) != std::string::npos;
    }));
}

TEST_F(LocationTest, shouldGenerateFinlandStreet)
{
    const auto generatedStreet = location::street(location::AddressCountry::Finland);

    const auto generatedStreetElements = utils::split(generatedStreet, " ");

    const auto& generatedStreetPrefix = generatedStreetElements[0];
    const auto& generatedStreetSuffix = generatedStreetElements[1];

    std::vector<std::string_view> firstNames { person::data::finnishMalesFirstNames.begin(),
        person::data::finnishMalesFirstNames.end() };
    firstNames.insert(firstNames.end(), person::data::finnishFemalesFirstNames.begin(),
        person::data::finnishFemalesFirstNames.end());

    std::vector<std::string_view> lastNames { person::data::finnishLastNames.begin(),
        person::data::finnishLastNames.end() };

    ASSERT_GE(generatedStreetElements.size(), 2);

    FAKER_EXPECT_CONTAINER_CONTAINS(location::data::finlandStreetSuffixes, generatedStreetSuffix);

    ASSERT_TRUE(faker::testing::any_of(firstNames, [&generatedStreetPrefix](auto firstName) {
        return generatedStreetPrefix.find(firstName) != std::string::npos;
    }) || faker::testing::any_of(lastNames, [&generatedStreetPrefix](auto lastName) {
        return generatedStreetPrefix.find(lastName) != std::string::npos;
    }));
}

TEST_F(LocationTest, shouldGenerateFinlandStreetAddress)
{
    const auto generatedStreetAddress = location::street_address(location::AddressCountry::Finland);

    ASSERT_TRUE(faker::testing::any_of(
        location::data::finlandStreetSuffixes, [&generatedStreetAddress](auto suffix) {
            return generatedStreetAddress.find(suffix) != std::string::npos;
        }));

    std::vector<std::string_view> firstNames { person::data::finnishMalesFirstNames.begin(),
        person::data::finnishMalesFirstNames.end() };
    firstNames.insert(firstNames.end(), person::data::finnishFemalesFirstNames.begin(),
        person::data::finnishFemalesFirstNames.end());

    std::vector<std::string_view> lastNames { person::data::finnishLastNames.begin(),
        person::data::finnishLastNames.end() };

    ASSERT_TRUE(faker::testing::any_of(firstNames, [&generatedStreetAddress](auto firstName) {
        return generatedStreetAddress.find(firstName) != std::string::npos;
    }) || faker::testing::any_of(lastNames, [&generatedStreetAddress](auto lastName) {
        return generatedStreetAddress.find(lastName) != std::string::npos;
    }));
}

TEST_F(LocationTest, shouldGenerateEstoniaStreet)
{
    const auto generatedStreet = location::street(location::AddressCountry::Estonia);

    ASSERT_TRUE(faker::testing::any_of(
        location::data::estoniaStreetNames, [&generatedStreet](auto streetName) {
            return generatedStreet.find(streetName) != std::string::npos;
        }));
}

TEST_F(LocationTest, shouldGenerateEstoniaStreetAddress)
{
    const auto generatedStreetAddress = location::street_address(location::AddressCountry::Estonia);

    ASSERT_TRUE(faker::testing::any_of(
        location::data::estoniaStreetNames, [&generatedStreetAddress](auto streetName) {
            return generatedStreetAddress.find(streetName) != std::string::npos;
        }));
}
