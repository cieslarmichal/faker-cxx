#include "../test_helpers.h"
#include <algorithm>
#include <common/string_helper.h>
#include <faker/location.h>
#include <modules/location_data.h>
#include <modules/person_data.h>
#include <modules/string_data.h>

using namespace ::testing;
using namespace faker;

const location::data::CountryAddresses& countryToCountryAddressesMapping(AddressCountry country)
{
    switch (country) {
    case AddressCountry::Usa:
        return location::data::usaAddresses;
    case AddressCountry::Poland:
        return location::data::polandAddresses;
    case AddressCountry::Russia:
        return location::data::russiaAddresses;
    case AddressCountry::France:
        return location::data::franceAddresses;
    case AddressCountry::Ukraine:
        return location::data::ukraineAddresses;
    case AddressCountry::Italy:
        return location::data::italyAddresses;
    case AddressCountry::Germany:
        return location::data::germanyAddresses;
    case AddressCountry::Czech:
        return location::data::czechAddresses;
    case AddressCountry::Australia:
        return location::data::australiaAddresses;
    case AddressCountry::India:
        return location::data::indiaAddresses;
    case AddressCountry::Denmark:
        return location::data::denmarkAddresses;
    case AddressCountry::Spain:
        return location::data::spainAddresses;
    case AddressCountry::Brazil:
        return location::data::brazilAddresses;
    case AddressCountry::Finland:
        return location::data::finlandAddresses;
    case AddressCountry::Estonia:
        return location::data::estoniaAddresses;
    default:
        throw std::invalid_argument("Invalid country");
    }
}

const std::unordered_map<AddressCountry, std::string> generatedTestName {
    { AddressCountry::Usa, "shouldGenerateAmericanAddress" },
    { AddressCountry::France, "shouldGenerateFrenchAddress" },
    { AddressCountry::Poland, "shouldGeneratePolishAddress" },
    { AddressCountry::Russia, "shouldGenerateRussianAddress" },
    { AddressCountry::Ukraine, "shouldGenerateUkrainianAddress" },
    { AddressCountry::Italy, "shouldGenerateItalianAddress" },
    { AddressCountry::Germany, "shouldGenerateGermanAddress" },
    { AddressCountry::Czech, "shouldGenerateCzechAddress" },
    { AddressCountry::Australia, "shouldGenerateAustraliaAddress" },
    { AddressCountry::India, "shouldGenerateIndiaAddress" },
    { AddressCountry::Denmark, "shouldGenerateDenmarkAddress" },
    { AddressCountry::Spain, "shouldGenerateSpainAddress" },
    { AddressCountry::Brazil, "shouldGenerateBrazilAddress" },
    { AddressCountry::Finland, "shouldGenerateFinlandAddress" },
    { AddressCountry::Estonia, "shouldGenerateEstoniaAddress" },
};

class LocationTest : public TestWithParam<AddressCountry> {
public:
    static bool checkIfZipCode(const std::string& zipCode)
    {
        const std::string zipCodeCharacters = "0123456789-";

        return faker::testing::all_of(zipCode, [&zipCodeCharacters](char dataCharacter) {
            return faker::testing::any_of(
                zipCodeCharacters, [dataCharacter](char numericCharacter) {
                    return numericCharacter == dataCharacter;
                });
        });
    }

    static bool checkIfAllCharactersAreNumeric(const std::string& data)
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

    FAKER_EXPECT_CONTAINS(countryAddresses.states, generatedState);
}

TEST_P(LocationTest, shouldGenerateCity)
{
    const auto country = GetParam();

    const auto& countryAddresses = countryToCountryAddressesMapping(country);

    const auto generatedCity = location::city(country);

    if (country == faker::AddressCountry::Brazil) {
        const auto generatedCityElements = StringHelper::split(generatedCity, " ");

        const auto& generatedCityPrefix = generatedCityElements[0];

        std::vector<std::string_view> firstNames { person::data::brazilianMalesFirstNames };
        firstNames.insert(firstNames.end(), person::data::brazilianFemalesFirstNames.begin(),
            person::data::brazilianFemalesFirstNames.end());

        std::vector<std::string_view> lastNames { person::data::brazilianLastNames };

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
        FAKER_EXPECT_CONTAINS(countryAddresses.cities, generatedCity);
    }
}

TEST_P(LocationTest, shouldGenerateZipCode)
{
    const auto country = GetParam();

    const auto& countryAddresses = countryToCountryAddressesMapping(country);

    const auto generatedZipCode = location::zipCode(country);

    ASSERT_EQ(generatedZipCode.size(), countryAddresses.zipCodeFormat.size());
    ASSERT_TRUE(checkIfZipCode(generatedZipCode));
}

TEST_P(LocationTest, shouldGenerateBuildingNumber)
{
    const auto country = GetParam();

    const auto& countryAddresses = countryToCountryAddressesMapping(country);

    const auto generatedBuildingNumber = location::buildingNumber(country);

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

    const auto generatedSecondaryAddress = location::secondaryAddress(country);

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
    [](const TestParamInfo<AddressCountry>& info) { return generatedTestName.at(info.param); });

TEST_F(LocationTest, shouldGenerateUsaStreet)
{
    const auto generatedStreet = location::street();

    const auto generatedStreetElements = StringHelper::split(generatedStreet, " ");

    const auto& generatedFirstOrLastName = generatedStreetElements[0];
    const auto& generatedStreetSuffix = generatedStreetElements[1];

    std::vector<std::string_view> firstNames { person::data::englishMalesFirstNames };
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
    FAKER_EXPECT_CONTAINS(location::data::usaStreetSuffixes, generatedStreetSuffix);
}

TEST_F(LocationTest, shouldGenerateUsaStreetAddress)
{
    const auto generatedStreetAddress = location::streetAddress();

    const auto generatedStreetAddressElements = StringHelper::split(generatedStreetAddress, " ");

    const auto& generatedBuildingNumber = generatedStreetAddressElements[0];
    const auto& generatedFirstOrLastName = generatedStreetAddressElements[1];
    const auto& generatedStreetSuffix = generatedStreetAddressElements[2];

    std::vector<std::string_view> firstNames { person::data::englishMalesFirstNames };
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
    const auto generatedStreet = location::street(AddressCountry::Poland);

    const auto generatedStreetElements = StringHelper::split(generatedStreet, " ");

    const auto& generatedStreetPrefix = generatedStreetElements[0];
    const auto& generatedStreetName = StringHelper::join(
        { generatedStreetElements.begin() + 1, generatedStreetElements.end() });

    ASSERT_TRUE(faker::testing::any_of(
        location::data::polandStreetPrefixes, [&generatedStreetPrefix](auto streetPrefix) {
            return streetPrefix == generatedStreetPrefix;
        }));
    ASSERT_TRUE(faker::testing::any_of(location::data::polandStreetNames,
        [&generatedStreetName](auto streetName) { return streetName == generatedStreetName; }));
}

TEST_F(LocationTest, shouldGeneratePolandStreetAddress)
{
    const auto generatedStreetAddress = location::streetAddress(AddressCountry::Poland);

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
    const auto generatedStreet = location::street(AddressCountry::Russia);

    const auto generatedStreetElements = StringHelper::split(generatedStreet, " ");

    const auto& generatedStreetPrefix = generatedStreetElements[0];
    const auto& generatedStreetSuffix = StringHelper::join(
        { generatedStreetElements.begin() + 1, generatedStreetElements.end() });

    std::vector<std::string_view> firstNames { person::data::russianMalesFirstNames };
    firstNames.insert(firstNames.end(), person::data::russianFemalesFirstNames.begin(),
        person::data::russianFemalesFirstNames.end());

    std::vector<std::string_view> lastNames { person::data::russianMalesLastNames };
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
    const auto generatedStreetAddress = location::streetAddress(AddressCountry::Russia);

    std::vector<std::string_view> firstNames { person::data::russianMalesFirstNames };
    firstNames.insert(firstNames.end(), person::data::russianFemalesFirstNames.begin(),
        person::data::russianFemalesFirstNames.end());

    std::vector<std::string_view> lastNames { person::data::russianMalesLastNames };
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
    const auto generatedStreet = location::street(AddressCountry::France);

    const auto generatedStreetElements = StringHelper::split(generatedStreet, " ");

    const auto& generatedStreetPrefix = generatedStreetElements[0];
    const auto& generatedStreetSuffix = StringHelper::join(
        { generatedStreetElements.begin() + 1, generatedStreetElements.end() });

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
    const auto generatedStreetAddress = location::streetAddress(AddressCountry::France);

    const auto generatedStreetAddressElements = StringHelper::split(generatedStreetAddress, " ");

    const auto& generatedBuildingNumber = generatedStreetAddressElements[0];
    const auto& generatedStreetPrefix = generatedStreetAddressElements[1];
    const auto& generatedStreetSuffix = StringHelper::join(
        { generatedStreetAddressElements.begin() + 2, generatedStreetAddressElements.end() });

    ASSERT_GE(generatedStreetAddressElements.size(), 3);
    ASSERT_TRUE(!generatedBuildingNumber.empty() && generatedBuildingNumber.size() <= 4);
    ASSERT_TRUE(checkIfAllCharactersAreNumeric(generatedBuildingNumber));
    ASSERT_TRUE(
        faker::testing::contains(location::data::franceStreetPrefixes, generatedStreetPrefix));
    FAKER_EXPECT_CONTAINS(location::data::franceStreetSuffixes, generatedStreetSuffix);
}

TEST_F(LocationTest, shouldGenerateCountry)
{
    const auto generatedCountry = location::country();

    FAKER_EXPECT_CONTAINS(location::data::allCountries, generatedCountry);
}

TEST_F(LocationTest, shouldGenerateCountryCode)
{
    const auto generatedCountryCode = location::countryCode();

    FAKER_EXPECT_CONTAINS(location::data::countryCodes, generatedCountryCode);
}

TEST_F(LocationTest, shouldGenerateLatitude)
{
    const auto latitude = location::latitude();

    auto offset = latitude.size();
    const auto latitudeAsFloat = std::stof(latitude, &offset);

    const auto generatedLatitudeParts = StringHelper::split(latitude, ".");

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

    const auto generatedLatitudeParts = StringHelper::split(latitude, ".");

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

    const auto generatedLongitudeParts = StringHelper::split(longitude, ".");

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

    const auto generatedLongitudeParts = StringHelper::split(longitude, ".");

    ASSERT_EQ(generatedLongitudeParts.size(), 2);
    ASSERT_EQ(generatedLongitudeParts[1].size(), 6);
    ASSERT_GE(longitudeAsFloat, -180);
    ASSERT_LE(longitudeAsFloat, 180);
}

TEST_F(LocationTest, shouldGenerateDirection)
{
    const auto generatedDirection = location::direction();

    FAKER_EXPECT_CONTAINS(location::data::directions, generatedDirection);
}

TEST_F(LocationTest, shouldGenerateTimeZone)
{
    const auto generatedTimeZone = location::timeZone();

    FAKER_EXPECT_CONTAINS(location::data::timeZones, generatedTimeZone);
}

TEST_F(LocationTest, shouldGenerateUkraineStreet)
{
    const auto generatedStreet = location::street(AddressCountry::Ukraine);

    const auto generatedStreetElements = StringHelper::split(generatedStreet, " ");

    const auto& generatedStreetPrefix = generatedStreetElements[0];
    const auto& generatedStreetSuffix = StringHelper::join(
        { generatedStreetElements.begin() + 1, generatedStreetElements.end() });

    FAKER_EXPECT_CONTAINS(location::data::ukraineStreetPrefixes, generatedStreetPrefix);

    std::vector<std::string_view> firstNames { person::data::ukrainianMalesFirstNames };
    firstNames.insert(firstNames.end(), person::data::ukrainianFemalesFirstNames.begin(),
        person::data::ukrainianFemalesFirstNames.end());

    std::vector<std::string_view> lastNames { person::data::ukrainianMalesLastNames };
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
    const auto generatedStreetAddress = location::streetAddress(AddressCountry::Ukraine);

    ASSERT_TRUE(faker::testing::any_of(
        location::data::ukraineStreetPrefixes, [&generatedStreetAddress](auto prefix) {
            return generatedStreetAddress.find(prefix) != std::string::npos;
        }));

    std::vector<std::string_view> firstNames { person::data::ukrainianMalesFirstNames };
    firstNames.insert(firstNames.end(), person::data::ukrainianFemalesFirstNames.begin(),
        person::data::ukrainianFemalesFirstNames.end());

    std::vector<std::string_view> lastNames { person::data::ukrainianMalesLastNames };
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
    const auto generatedStreet = location::street(AddressCountry::Italy);

    const auto generatedStreetElements = StringHelper::split(generatedStreet, " ");

    const auto& generatedStreetPrefix = generatedStreetElements[0];
    const auto& generatedStreetSuffix = StringHelper::join(
        { generatedStreetElements.begin() + 1, generatedStreetElements.end() });

    ASSERT_TRUE(faker::testing::any_of(
        location::data::italyStreetPrefixes, [&generatedStreetPrefix](auto streetPrefix) {
            return streetPrefix == generatedStreetPrefix;
        }));

    std::vector<std::string_view> firstNames { person::data::italianMalesFirstNames };
    firstNames.insert(firstNames.end(), person::data::italianFemalesFirstNames.begin(),
        person::data::italianFemalesFirstNames.end());

    std::vector<std::string_view> lastNames { person::data::italianLastNames };

    ASSERT_TRUE(faker::testing::any_of(firstNames, [&generatedStreetSuffix](auto firstName) {
        return generatedStreetSuffix.find(firstName) != std::string::npos;
    }) || faker::testing::any_of(lastNames, [&generatedStreetSuffix](auto lastName) {
        return generatedStreetSuffix.find(lastName) != std::string::npos;
    }));
}

TEST_F(LocationTest, shouldGenerateItalyStreetAddress)
{
    const auto generatedStreetAddress = location::streetAddress(AddressCountry::Italy);

    ASSERT_TRUE(faker::testing::any_of(
        location::data::italyStreetPrefixes, [&generatedStreetAddress](auto prefix) {
            return generatedStreetAddress.find(prefix) != std::string::npos;
        }));

    std::vector<std::string_view> firstNames { person::data::italianMalesFirstNames };
    firstNames.insert(firstNames.end(), person::data::italianFemalesFirstNames.begin(),
        person::data::italianFemalesFirstNames.end());

    std::vector<std::string_view> lastNames { person::data::italianLastNames };

    ASSERT_TRUE(faker::testing::any_of(firstNames, [&generatedStreetAddress](auto firstName) {
        return generatedStreetAddress.find(firstName) != std::string::npos;
    }) || faker::testing::any_of(lastNames, [&generatedStreetAddress](auto lastName) {
        return generatedStreetAddress.find(lastName) != std::string::npos;
    }));
}

TEST_F(LocationTest, shouldGenerateGermanyStreet)
{
    const auto generatedStreet = location::street(AddressCountry::Germany);

    FAKER_EXPECT_CONTAINS(location::data::germanyStreetNames, generatedStreet);
}

TEST_F(LocationTest, shouldGenerateGermanyStreetAddress)
{
    const auto generatedStreetAddress = location::streetAddress(AddressCountry::Germany);

    ASSERT_TRUE(faker::testing::any_of(
        location::data::germanyStreetNames, [&generatedStreetAddress](auto streetName) {
            return generatedStreetAddress.find(streetName) != std::string::npos;
        }));
}

TEST_F(LocationTest, shouldGenerateCzechStreet)
{
    const auto generatedStreet = location::street(AddressCountry::Czech);

    ASSERT_TRUE(faker::testing::any_of(location::data::czechStreetNames,
        [&generatedStreet](auto streetName) { return streetName == generatedStreet; }));
}

TEST_F(LocationTest, shouldGenerateCzechStreetAddress)
{
    const auto generatedStreetAddress = location::streetAddress(AddressCountry::Czech);

    ASSERT_TRUE(faker::testing::any_of(
        location::data::czechStreetNames, [&generatedStreetAddress](auto streetName) {
            return generatedStreetAddress.find(streetName) != std::string::npos;
        }));
}

TEST_F(LocationTest, shouldGenerateAustraliaStreet)
{
    const auto generatedStreet = location::street(AddressCountry::Australia);

    std::vector<std::string_view> firstNames { person::data::australianMalesFirstNames };
    firstNames.insert(firstNames.end(), person::data::australianFemalesFirstNames.begin(),
        person::data::australianFemalesFirstNames.end());

    std::vector<std::string_view> lastNames { person::data::australianLastNames };

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
    const auto generatedStreetAddress = location::streetAddress(AddressCountry::Australia);

    const auto generatedStreetAddressElements = StringHelper::split(generatedStreetAddress, " ");

    const auto& generatedBuildingNumber = generatedStreetAddressElements[0];
    const auto& generatedStreetSuffix = StringHelper::join(
        { generatedStreetAddressElements.begin() + 1, generatedStreetAddressElements.end() });

    std::vector<std::string_view> firstNames { person::data::australianMalesFirstNames };
    firstNames.insert(firstNames.end(), person::data::australianFemalesFirstNames.begin(),
        person::data::australianFemalesFirstNames.end());

    std::vector<std::string_view> lastNames { person::data::australianLastNames };

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
    const auto generatedStreet = location::street(AddressCountry::India);

    const auto generatedStreetElements = StringHelper::split(generatedStreet, " ");

    const auto& generatedStreetSuffix = StringHelper::join(
        { generatedStreetElements.begin() + 1, generatedStreetElements.end() });

    ASSERT_GE(generatedStreetElements.size(), 2);
    ASSERT_TRUE(faker::testing::any_of(
        location::data::indiaStreetSuffixes, [&generatedStreetSuffix](auto streetSuffix) {
            return streetSuffix == generatedStreetSuffix;
        }));
}

TEST_F(LocationTest, shouldGenerateIndiaStreetAddress)
{
    const auto generatedStreetAddress = location::streetAddress(AddressCountry::India);

    const auto generatedStreetAddressElements = StringHelper::split(generatedStreetAddress, " ");

    const auto& generatedBuildingNumber = generatedStreetAddressElements[0];
    const auto& generatedStreetSuffix = StringHelper::join(
        { generatedStreetAddressElements.begin() + 2, generatedStreetAddressElements.end() });

    ASSERT_GE(generatedStreetAddressElements.size(), 3);
    ASSERT_TRUE(!generatedBuildingNumber.empty());
    ASSERT_TRUE(checkIfAllCharactersAreNumeric(generatedBuildingNumber));
    FAKER_EXPECT_CONTAINS(location::data::indiaStreetSuffixes, generatedStreetSuffix);
}

TEST_F(LocationTest, shouldGenerateDenmarkStreet)
{
    const auto generatedStreet = location::street(AddressCountry::Denmark);

    FAKER_EXPECT_CONTAINS(location::data::denmarkStreetNames, generatedStreet);
}

TEST_F(LocationTest, shouldGenerateDenmarkStreetAddress)
{
    const auto generatedStreetAddress = location::streetAddress(AddressCountry::Denmark);

    ASSERT_TRUE(faker::testing::any_of(
        location::data::denmarkStreetNames, [&generatedStreetAddress](auto streetName) {
            return generatedStreetAddress.find(streetName) != std::string::npos;
        }));
}

TEST_F(LocationTest, shouldGenerateSpainStreet)
{
    const auto generatedStreet = location::street(AddressCountry::Spain);

    std::vector<std::string_view> firstNames { person::data::spanishMalesFirstNames };
    firstNames.insert(firstNames.end(), person::data::spanishFemalesFirstNames.begin(),
        person::data::spanishFemalesFirstNames.end());

    std::vector<std::string_view> lastNames { person::data::spanishLastNames };

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
    const auto generatedStreetAddress = location::streetAddress(AddressCountry::Spain);

    ASSERT_TRUE(faker::testing::any_of(
        location::data::spainStreetSuffixes, [&generatedStreetAddress](auto suffix) {
            return generatedStreetAddress.find(suffix) != std::string::npos;
        }));

    std::vector<std::string_view> firstNames { person::data::spanishMalesFirstNames };
    firstNames.insert(firstNames.end(), person::data::spanishFemalesFirstNames.begin(),
        person::data::spanishFemalesFirstNames.end());

    std::vector<std::string_view> lastNames { person::data::spanishLastNames };

    ASSERT_TRUE(faker::testing::any_of(firstNames, [&generatedStreetAddress](auto firstName) {
        return generatedStreetAddress.find(firstName) != std::string::npos;
    }) || faker::testing::any_of(lastNames, [&generatedStreetAddress](auto lastName) {
        return generatedStreetAddress.find(lastName) != std::string::npos;
    }));
}

TEST_F(LocationTest, shouldGenerateFinlandStreet)
{
    const auto generatedStreet = location::street(AddressCountry::Finland);

    const auto generatedStreetElements = StringHelper::split(generatedStreet, " ");

    const auto& generatedStreetPrefix = generatedStreetElements[0];
    const auto& generatedStreetSuffix = generatedStreetElements[1];

    std::vector<std::string_view> firstNames { person::data::finnishMalesFirstNames };
    firstNames.insert(firstNames.end(), person::data::finnishFemalesFirstNames.begin(),
        person::data::finnishFemalesFirstNames.end());

    std::vector<std::string_view> lastNames { person::data::finnishLastNames };

    ASSERT_GE(generatedStreetElements.size(), 2);

    FAKER_EXPECT_CONTAINS(location::data::finlandStreetSuffixes, generatedStreetSuffix);

    ASSERT_TRUE(faker::testing::any_of(firstNames, [&generatedStreetPrefix](auto firstName) {
        return generatedStreetPrefix.find(firstName) != std::string::npos;
    }) || faker::testing::any_of(lastNames, [&generatedStreetPrefix](auto lastName) {
        return generatedStreetPrefix.find(lastName) != std::string::npos;
    }));
}

TEST_F(LocationTest, shouldGenerateFinlandStreetAddress)
{
    const auto generatedStreetAddress = location::streetAddress(AddressCountry::Finland);

    ASSERT_TRUE(faker::testing::any_of(
        location::data::finlandStreetSuffixes, [&generatedStreetAddress](auto suffix) {
            return generatedStreetAddress.find(suffix) != std::string::npos;
        }));

    std::vector<std::string_view> firstNames { person::data::finnishMalesFirstNames };
    firstNames.insert(firstNames.end(), person::data::finnishFemalesFirstNames.begin(),
        person::data::finnishFemalesFirstNames.end());

    std::vector<std::string_view> lastNames { person::data::finnishLastNames };

    ASSERT_TRUE(faker::testing::any_of(firstNames, [&generatedStreetAddress](auto firstName) {
        return generatedStreetAddress.find(firstName) != std::string::npos;
    }) || faker::testing::any_of(lastNames, [&generatedStreetAddress](auto lastName) {
        return generatedStreetAddress.find(lastName) != std::string::npos;
    }));
}

TEST_F(LocationTest, shouldGenerateEstoniaStreet)
{
    const auto generatedStreet = location::street(AddressCountry::Estonia);

    ASSERT_TRUE(faker::testing::any_of(
        location::data::estoniaStreetNames, [&generatedStreet](auto streetName) {
            return generatedStreet.find(streetName) != std::string::npos;
        }));
}

TEST_F(LocationTest, shouldGenerateEstoniaStreetAddress)
{
    const auto generatedStreetAddress = location::streetAddress(AddressCountry::Estonia);

    ASSERT_TRUE(faker::testing::any_of(
        location::data::estoniaStreetNames, [&generatedStreetAddress](auto streetName) {
            return generatedStreetAddress.find(streetName) != std::string::npos;
        }));
}
