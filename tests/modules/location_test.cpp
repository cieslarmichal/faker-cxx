#include "../test_helpers.h"
#include <algorithm>
#include <common/string_helper.h>
#include <faker/location.h>
#include <modules/location_data.h>
#include <modules/person_data.h>
#include <modules/string_data.h>

using namespace ::testing;
using namespace faker;

namespace {

const CountryAddresses& countryToCountryAddressesMapping(AddressCountry country)
{
    static const std::unordered_map<AddressCountry, CountryAddresses> items {
        { AddressCountry::Usa, usaAddresses },
        { AddressCountry::Poland, polandAddresses },
        { AddressCountry::Russia, russiaAddresses },
        { AddressCountry::France, franceAddresses },
        { AddressCountry::Ukraine, ukraineAddresses },
        { AddressCountry::Italy, italyAddresses },
        { AddressCountry::Germany, germanyAddresses },
        { AddressCountry::Czech, czechAddresses },
        { AddressCountry::Australia, australiaAddresses },
        { AddressCountry::India, indiaAddresses },
        { AddressCountry::Denmark, denmarkAddresses },
        { AddressCountry::Spain, spainAddresses },
        { AddressCountry::Brazil, brazilAddresses },
        { AddressCountry::Finland, finlandAddresses },
        { AddressCountry::Estonia, estoniaAddresses },
    };

    return items.at(country);
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
}

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
                numericCharacters, [dataCharacter](char numericCharacter) {
                    return numericCharacter == dataCharacter;
                });
        });
    }

    static bool checkIfCharacterIsNumeric(char character)
    {
        return faker::testing::any_of(numericCharacters,
            [character](char numericCharacter) { return numericCharacter == character; });
    }
};

TEST_P(LocationTest, shouldGenerateCounty)
{
    const auto country = GetParam();

    const auto& countryAddresses = countryToCountryAddressesMapping(country);

    const auto generatedCounty = location::county(country);

    ASSERT_TRUE(
        faker::testing::any_of(countryAddresses.counties,
            [&generatedCounty](const std::string& county) { return county == generatedCounty; })
        || (countryAddresses.counties.empty() && generatedCounty.empty()));
}

TEST_P(LocationTest, shouldGenerateState)
{
    const auto country = GetParam();

    const auto& countryAddresses = countryToCountryAddressesMapping(country);

    const auto generatedState = location::state(country);

    ASSERT_TRUE(faker::testing::any_of(countryAddresses.states,
        [&generatedState](const std::string& state) { return state == generatedState; }));
}

TEST_P(LocationTest, shouldGenerateCity)
{
    const auto country = GetParam();

    const auto& countryAddresses = countryToCountryAddressesMapping(country);

    const auto generatedCity = location::city(country);

    if (country == faker::AddressCountry::Brazil) {
        const auto generatedCityElements = StringHelper::split(generatedCity, " ");

        const auto& generatedCityPrefix = generatedCityElements[0];

        std::vector<std::string> firstNames { brazilianMalesFirstNames };
        firstNames.insert(
            firstNames.end(), brazilianFemalesFirstNames.begin(), brazilianFemalesFirstNames.end());

        std::vector<std::string> lastNames { brazilianLastNames };

        ASSERT_TRUE(faker::testing::any_of(firstNames,
                        [&generatedCityPrefix](const std::string& firstName) {
                            return generatedCityPrefix.find(firstName) != std::string::npos;
                        })
            || faker::testing::any_of(lastNames,
                [&generatedCityPrefix](const std::string& lastName) {
                    return generatedCityPrefix.find(lastName) != std::string::npos;
                })
            || faker::testing::any_of(
                brazilCitySuffixes, [&generatedCity](const std::string& citySuffix) {
                    return generatedCity.find(citySuffix) != std::string::npos;
                }));
    } else {
        ASSERT_TRUE(faker::testing::any_of(countryAddresses.cities,
            [&generatedCity](const std::string& city) { return city == generatedCity; }));
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
        [&generatedBuildingNumber](const std::string& buildingNumberFormat) {
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
            [&generatedSecondaryAddress](const std::string& secondaryAddressFormat) {
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

    std::vector<std::string> firstNames { englishMalesFirstNames };
    firstNames.insert(
        firstNames.end(), englishFemalesFirstNames.begin(), englishFemalesFirstNames.end());

    ASSERT_EQ(generatedStreetElements.size(), 2);
    ASSERT_TRUE(faker::testing::any_of(firstNames,
                    [&generatedFirstOrLastName](const std::string& firstName) {
                        return firstName == generatedFirstOrLastName;
                    })
        || faker::testing::any_of(
            englishLastNames, [&generatedFirstOrLastName](const std::string& lastName) {
                return lastName == generatedFirstOrLastName;
            }));
    ASSERT_TRUE(faker::testing::any_of(
        usaStreetSuffixes, [&generatedStreetSuffix](const std::string& streetSuffix) {
            return streetSuffix == generatedStreetSuffix;
        }));
}

TEST_F(LocationTest, shouldGenerateUsaStreetAddress)
{
    const auto generatedStreetAddress = location::streetAddress();

    const auto generatedStreetAddressElements = StringHelper::split(generatedStreetAddress, " ");

    const auto& generatedBuildingNumber = generatedStreetAddressElements[0];
    const auto& generatedFirstOrLastName = generatedStreetAddressElements[1];
    const auto& generatedStreetSuffix = generatedStreetAddressElements[2];

    std::vector<std::string> firstNames { englishMalesFirstNames };
    firstNames.insert(
        firstNames.end(), englishFemalesFirstNames.begin(), englishFemalesFirstNames.end());

    ASSERT_EQ(generatedStreetAddressElements.size(), 3);
    ASSERT_TRUE(generatedBuildingNumber.size() >= 3 && generatedBuildingNumber.size() <= 5);
    ASSERT_TRUE(checkIfAllCharactersAreNumeric(generatedBuildingNumber));
    ASSERT_TRUE(faker::testing::any_of(firstNames,
                    [&generatedFirstOrLastName](const std::string& firstName) {
                        return firstName == generatedFirstOrLastName;
                    })
        || faker::testing::any_of(
            englishLastNames, [&generatedFirstOrLastName](const std::string& lastName) {
                return lastName == generatedFirstOrLastName;
            }));
    ASSERT_TRUE(faker::testing::any_of(
        usaStreetSuffixes, [&generatedStreetSuffix](const std::string& streetSuffix) {
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
        polandStreetPrefixes, [&generatedStreetPrefix](const std::string& streetPrefix) {
            return streetPrefix == generatedStreetPrefix;
        }));
    ASSERT_TRUE(faker::testing::any_of(
        polandStreetNames, [&generatedStreetName](const std::string& streetName) {
            return streetName == generatedStreetName;
        }));
}

TEST_F(LocationTest, shouldGeneratePolandStreetAddress)
{
    const auto generatedStreetAddress = location::streetAddress(AddressCountry::Poland);

    ASSERT_TRUE(faker::testing::any_of(
        polandStreetPrefixes, [&generatedStreetAddress](const std::string& prefix) {
            return generatedStreetAddress.find(prefix) != std::string::npos;
        }));
    ASSERT_TRUE(faker::testing::any_of(
        polandStreetNames, [&generatedStreetAddress](const std::string& street) {
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

    std::vector<std::string> firstNames { russianMalesFirstNames };
    firstNames.insert(
        firstNames.end(), russianFemalesFirstNames.begin(), russianFemalesFirstNames.end());

    std::vector<std::string> lastNames { russianMalesLastNames };
    firstNames.insert(
        firstNames.end(), russianFemalesLastNames.begin(), russianFemalesLastNames.end());

    ASSERT_TRUE(faker::testing::any_of(
        russiaStreetPrefixes, [&generatedStreetPrefix](const std::string& streetPrefix) {
            return streetPrefix == generatedStreetPrefix;
        }));
    ASSERT_TRUE(faker::testing::any_of(firstNames,
                    [&generatedStreetSuffix](const std::string& firstName) {
                        return firstName == generatedStreetSuffix;
                    })
        || faker::testing::any_of(lastNames,
            [&generatedStreetSuffix](
                const std::string& lastName) { return lastName == generatedStreetSuffix; })
        || faker::testing::any_of(
            russiaStreetNames, [&generatedStreetSuffix](const std::string& streetName) {
                return streetName == generatedStreetSuffix;
            }));
}

TEST_F(LocationTest, shouldGenerateRussiaStreetAddress)
{
    const auto generatedStreetAddress = location::streetAddress(AddressCountry::Russia);

    std::vector<std::string> firstNames { russianMalesFirstNames };
    firstNames.insert(
        firstNames.end(), russianFemalesFirstNames.begin(), russianFemalesFirstNames.end());

    std::vector<std::string> lastNames { russianMalesLastNames };
    lastNames.insert(
        lastNames.end(), russianFemalesLastNames.begin(), russianFemalesLastNames.end());

    ASSERT_TRUE(faker::testing::any_of(
        russiaStreetPrefixes, [&generatedStreetAddress](const std::string& prefix) {
            return generatedStreetAddress.find(prefix) != std::string::npos;
        }));
    ASSERT_TRUE(faker::testing::any_of(firstNames,
                    [&generatedStreetAddress](const std::string& firstName) {
                        return generatedStreetAddress.find(firstName) != std::string::npos;
                    })
        || faker::testing::any_of(lastNames,
            [&generatedStreetAddress](const std::string& lastName) {
                return generatedStreetAddress.find(lastName) != std::string::npos;
            })
        || faker::testing::any_of(
            russiaStreetNames, [&generatedStreetAddress](const std::string& streetName) {
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
        franceStreetPrefixes, [&generatedStreetPrefix](const std::string& streetPrefix) {
            return streetPrefix == generatedStreetPrefix;
        }));
    ASSERT_TRUE(faker::testing::any_of(
        franceStreetSuffixes, [&generatedStreetSuffix](const std::string& streetSuffix) {
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
    ASSERT_TRUE(faker::testing::any_of(
        franceStreetPrefixes, [&generatedStreetPrefix](const std::string& streetPrefix) {
            return streetPrefix == generatedStreetPrefix;
        }));
    FAKER_EXPECT_CONTAINS(franceStreetSuffixes, generatedStreetSuffix);
}

TEST_F(LocationTest, shouldGenerateCountry)
{
    const auto generatedCountry = location::country();

    FAKER_EXPECT_CONTAINS(allCountries, generatedCountry);
}

TEST_F(LocationTest, shouldGenerateCountryCode)
{
    const auto generatedCountryCode = location::countryCode();

    FAKER_EXPECT_CONTAINS(countryCodes, generatedCountryCode);
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

    FAKER_EXPECT_CONTAINS(directions, generatedDirection);
}

TEST_F(LocationTest, shouldGenerateTimeZone)
{
    const auto generatedTimeZone = location::timeZone();

    FAKER_EXPECT_CONTAINS(timeZones, generatedTimeZone);
}

TEST_F(LocationTest, shouldGenerateUkraineStreet)
{
    const auto generatedStreet = location::street(AddressCountry::Ukraine);

    const auto generatedStreetElements = StringHelper::split(generatedStreet, " ");

    const auto& generatedStreetPrefix = generatedStreetElements[0];
    const auto& generatedStreetSuffix = StringHelper::join(
        { generatedStreetElements.begin() + 1, generatedStreetElements.end() });

    FAKER_EXPECT_CONTAINS(ukraineStreetPrefixes, generatedStreetPrefix);

    std::vector<std::string> firstNames { ukrainianMalesFirstNames };
    firstNames.insert(
        firstNames.end(), ukrainianFemalesFirstNames.begin(), ukrainianFemalesFirstNames.end());

    std::vector<std::string> lastNames { ukrainianMalesLastNames };
    lastNames.insert(
        lastNames.end(), ukrainianFemalesLastNames.begin(), ukrainianFemalesLastNames.end());

    ASSERT_TRUE(faker::testing::any_of(firstNames,
                    [&generatedStreetSuffix](const std::string& firstName) {
                        return generatedStreetSuffix.find(firstName) != std::string::npos;
                    })
        || faker::testing::any_of(lastNames,
            [&generatedStreetSuffix](const std::string& lastName) {
                return generatedStreetSuffix.find(lastName) != std::string::npos;
            })
        || faker::testing::any_of(
            ukraineStreetNames, [&generatedStreetSuffix](const std::string& streetName) {
                return generatedStreetSuffix.find(streetName) != std::string::npos;
            }));
}

TEST_F(LocationTest, shouldGenerateUkraineStreetAddress)
{
    const auto generatedStreetAddress = location::streetAddress(AddressCountry::Ukraine);

    ASSERT_TRUE(faker::testing::any_of(
        ukraineStreetPrefixes, [&generatedStreetAddress](const std::string& prefix) {
            return generatedStreetAddress.find(prefix) != std::string::npos;
        }));

    std::vector<std::string> firstNames { ukrainianMalesFirstNames };
    firstNames.insert(
        firstNames.end(), ukrainianFemalesFirstNames.begin(), ukrainianFemalesFirstNames.end());

    std::vector<std::string> lastNames { ukrainianMalesLastNames };
    lastNames.insert(
        lastNames.end(), ukrainianFemalesLastNames.begin(), ukrainianFemalesLastNames.end());

    ASSERT_TRUE(faker::testing::any_of(firstNames,
                    [&generatedStreetAddress](const std::string& firstName) {
                        return generatedStreetAddress.find(firstName) != std::string::npos;
                    })
        || faker::testing::any_of(lastNames,
            [&generatedStreetAddress](const std::string& lastName) {
                return generatedStreetAddress.find(lastName) != std::string::npos;
            })
        || faker::testing::any_of(
            ukraineStreetNames, [&generatedStreetAddress](const std::string& streetName) {
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
        italyStreetPrefixes, [&generatedStreetPrefix](const std::string& streetPrefix) {
            return streetPrefix == generatedStreetPrefix;
        }));

    std::vector<std::string> firstNames { italianMalesFirstNames };
    firstNames.insert(
        firstNames.end(), italianFemalesFirstNames.begin(), italianFemalesFirstNames.end());

    std::vector<std::string> lastNames { italianLastNames };

    ASSERT_TRUE(faker::testing::any_of(firstNames,
                    [&generatedStreetSuffix](const std::string& firstName) {
                        return generatedStreetSuffix.find(firstName) != std::string::npos;
                    })
        || faker::testing::any_of(lastNames, [&generatedStreetSuffix](const std::string& lastName) {
               return generatedStreetSuffix.find(lastName) != std::string::npos;
           }));
}

TEST_F(LocationTest, shouldGenerateItalyStreetAddress)
{
    const auto generatedStreetAddress = location::streetAddress(AddressCountry::Italy);

    ASSERT_TRUE(faker::testing::any_of(
        italyStreetPrefixes, [&generatedStreetAddress](const std::string& prefix) {
            return generatedStreetAddress.find(prefix) != std::string::npos;
        }));

    std::vector<std::string> firstNames { italianMalesFirstNames };
    firstNames.insert(
        firstNames.end(), italianFemalesFirstNames.begin(), italianFemalesFirstNames.end());

    std::vector<std::string> lastNames { italianLastNames };

    ASSERT_TRUE(faker::testing::any_of(firstNames,
                    [&generatedStreetAddress](const std::string& firstName) {
                        return generatedStreetAddress.find(firstName) != std::string::npos;
                    })
        || faker::testing::any_of(
            lastNames, [&generatedStreetAddress](const std::string& lastName) {
                return generatedStreetAddress.find(lastName) != std::string::npos;
            }));
}

TEST_F(LocationTest, shouldGenerateGermanyStreet)
{
    const auto generatedStreet = location::street(AddressCountry::Germany);

    ASSERT_TRUE(faker::testing::any_of(
        germanyStreetNames, [&generatedStreet](const std::string& streetName) {
            return streetName == generatedStreet;
        }));
}

TEST_F(LocationTest, shouldGenerateGermanyStreetAddress)
{
    const auto generatedStreetAddress = location::streetAddress(AddressCountry::Germany);

    std::vector<std::string> streetNames { germanyStreetNames };

    ASSERT_TRUE(faker::testing::any_of(
        streetNames, [&generatedStreetAddress](const std::string& streetName) {
            return generatedStreetAddress.find(streetName) != std::string::npos;
        }));
}

TEST_F(LocationTest, shouldGenerateCzechStreet)
{
    const auto generatedStreet = location::street(AddressCountry::Czech);

    ASSERT_TRUE(
        faker::testing::any_of(czechStreetNames, [&generatedStreet](const std::string& streetName) {
            return streetName == generatedStreet;
        }));
}

TEST_F(LocationTest, shouldGenerateCzechStreetAddress)
{
    const auto generatedStreetAddress = location::streetAddress(AddressCountry::Czech);

    std::vector<std::string> streetNames { czechStreetNames };

    ASSERT_TRUE(faker::testing::any_of(
        streetNames, [&generatedStreetAddress](const std::string& streetName) {
            return generatedStreetAddress.find(streetName) != std::string::npos;
        }));
}

TEST_F(LocationTest, shouldGenerateAustraliaStreet)
{
    const auto generatedStreet = location::street(AddressCountry::Australia);

    std::vector<std::string> firstNames { australianMalesFirstNames };
    firstNames.insert(
        firstNames.end(), australianFemalesFirstNames.begin(), australianFemalesFirstNames.end());

    std::vector<std::string> lastNames { australianLastNames };

    ASSERT_TRUE((faker::testing::any_of(firstNames,
                     [&generatedStreet](const std::string& firstName) {
                         return generatedStreet.find(firstName) != std::string::npos;
                     })
                    || faker::testing::any_of(lastNames,
                        [&generatedStreet](const std::string& lastName) {
                            return generatedStreet.find(lastName) != std::string::npos;
                        }))
        && faker::testing::any_of(
            australiaStreetSuffixes, [&generatedStreet](const std::string& streetSuffix) {
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

    std::vector<std::string> firstNames { australianMalesFirstNames };
    firstNames.insert(
        firstNames.end(), australianFemalesFirstNames.begin(), australianFemalesFirstNames.end());

    std::vector<std::string> lastNames { australianLastNames };

    ASSERT_TRUE(!generatedBuildingNumber.empty() && generatedBuildingNumber.size() <= 4);
    ASSERT_TRUE(checkIfAllCharactersAreNumeric(generatedBuildingNumber));

    ASSERT_TRUE((faker::testing::any_of(firstNames,
                     [&generatedStreetSuffix](const std::string& firstName) {
                         return generatedStreetSuffix.find(firstName) != std::string::npos;
                     })
                    || faker::testing::any_of(lastNames,
                        [&generatedStreetSuffix](const std::string& lastName) {
                            return generatedStreetSuffix.find(lastName) != std::string::npos;
                        }))
        && faker::testing::any_of(
            australiaStreetSuffixes, [&generatedStreetSuffix](const std::string& streetSuffix) {
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
    std::vector<std::string> streetNames { denmarkStreetNames };
    ASSERT_TRUE(faker::testing::any_of(
        indiaStreetSuffixes, [&generatedStreetSuffix](const std::string& streetSuffix) {
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
    ASSERT_TRUE(faker::testing::any_of(
        indiaStreetSuffixes, [&generatedStreetSuffix](const std::string& streetSuffix) {
            return streetSuffix == generatedStreetSuffix;
        }));
}

TEST_F(LocationTest, shouldGenerateDenmarkStreet)
{
    const auto generatedStreet = location::street(AddressCountry::Denmark);

    ASSERT_TRUE(faker::testing::any_of(
        denmarkStreetNames, [&generatedStreet](const std::string& streetName) {
            return streetName == generatedStreet;
        }));
}

TEST_F(LocationTest, shouldGenerateDenmarkStreetAddress)
{
    const auto generatedStreetAddress = location::streetAddress(AddressCountry::Denmark);

    ASSERT_TRUE(faker::testing::any_of(
        denmarkStreetNames, [&generatedStreetAddress](const std::string& streetName) {
            return generatedStreetAddress.find(streetName) != std::string::npos;
        }));
}

TEST_F(LocationTest, shouldGenerateSpainStreet)
{
    const auto generatedStreet = location::street(AddressCountry::Spain);

    std::vector<std::string> firstNames { spanishMalesFirstNames };
    firstNames.insert(
        firstNames.end(), spanishFemalesFirstNames.begin(), spanishFemalesFirstNames.end());

    std::vector<std::string> lastNames { spanishLastNames };

    ASSERT_TRUE((faker::testing::any_of(firstNames,
                     [&generatedStreet](const std::string& firstName) {
                         return generatedStreet.find(firstName) != std::string::npos;
                     })
                    || faker::testing::any_of(lastNames,
                        [&generatedStreet](const std::string& lastName) {
                            return generatedStreet.find(lastName) != std::string::npos;
                        }))
        && faker::testing::any_of(
            spainStreetSuffixes, [&generatedStreet](const std::string& streetSuffix) {
                return generatedStreet.find(streetSuffix) != std::string::npos;
            }));
}

TEST_F(LocationTest, shouldGenerateSpainStreetAddress)
{
    const auto generatedStreetAddress = location::streetAddress(AddressCountry::Spain);

    ASSERT_TRUE(faker::testing::any_of(
        spainStreetSuffixes, [&generatedStreetAddress](const std::string& suffix) {
            return generatedStreetAddress.find(suffix) != std::string::npos;
        }));

    std::vector<std::string> firstNames { spanishMalesFirstNames };
    firstNames.insert(
        firstNames.end(), spanishFemalesFirstNames.begin(), spanishFemalesFirstNames.end());

    std::vector<std::string> lastNames { spanishLastNames };

    ASSERT_TRUE(faker::testing::any_of(firstNames,
                    [&generatedStreetAddress](const std::string& firstName) {
                        return generatedStreetAddress.find(firstName) != std::string::npos;
                    })
        || faker::testing::any_of(
            lastNames, [&generatedStreetAddress](const std::string& lastName) {
                return generatedStreetAddress.find(lastName) != std::string::npos;
            }));
}

TEST_F(LocationTest, shouldGenerateFinlandStreet)
{
    const auto generatedStreet = location::street(AddressCountry::Finland);

    const auto generatedStreetElements = StringHelper::split(generatedStreet, " ");

    const auto& generatedStreetPrefix = generatedStreetElements[0];
    const auto& generatedStreetSuffix = generatedStreetElements[1];

    std::vector<std::string> firstNames { finnishMalesFirstNames };
    firstNames.insert(
        firstNames.end(), finnishFemalesFirstNames.begin(), finnishFemalesFirstNames.end());

    std::vector<std::string> lastNames { finnishLastNames };

    ASSERT_GE(generatedStreetElements.size(), 2);

    ASSERT_TRUE(faker::testing::any_of(
        finlandStreetSuffixes, [&generatedStreetSuffix](const std::string& streetSuffix) {
            return streetSuffix == generatedStreetSuffix;
        }));

    ASSERT_TRUE(faker::testing::any_of(firstNames,
                    [&generatedStreetPrefix](const std::string& firstName) {
                        return generatedStreetPrefix.find(firstName) != std::string::npos;
                    })
        || faker::testing::any_of(lastNames, [&generatedStreetPrefix](const std::string& lastName) {
               return generatedStreetPrefix.find(lastName) != std::string::npos;
           }));
}

TEST_F(LocationTest, shouldGenerateFinlandStreetAddress)
{
    const auto generatedStreetAddress = location::streetAddress(AddressCountry::Finland);

    ASSERT_TRUE(faker::testing::any_of(
        finlandStreetSuffixes, [&generatedStreetAddress](const std::string& suffix) {
            return generatedStreetAddress.find(suffix) != std::string::npos;
        }));

    std::vector<std::string> firstNames { finnishMalesFirstNames };
    firstNames.insert(
        firstNames.end(), finnishFemalesFirstNames.begin(), finnishFemalesFirstNames.end());

    std::vector<std::string> lastNames { finnishLastNames };

    ASSERT_TRUE(faker::testing::any_of(firstNames,
                    [&generatedStreetAddress](const std::string& firstName) {
                        return generatedStreetAddress.find(firstName) != std::string::npos;
                    })
        || faker::testing::any_of(
            lastNames, [&generatedStreetAddress](const std::string& lastName) {
                return generatedStreetAddress.find(lastName) != std::string::npos;
            }));
}

TEST_F(LocationTest, shouldGenerateEstoniaStreet)
{
    const auto generatedStreet = location::street(AddressCountry::Estonia);

    ASSERT_TRUE(faker::testing::any_of(
        estoniaStreetNames, [&generatedStreet](const std::string& streetName) {
            return generatedStreet.find(streetName) != std::string::npos;
        }));
}

TEST_F(LocationTest, shouldGenerateEstoniaStreetAddress)
{
    const auto generatedStreetAddress = location::streetAddress(AddressCountry::Estonia);

    ASSERT_TRUE(faker::testing::any_of(
        estoniaStreetNames, [&generatedStreetAddress](const std::string& streetName) {
            return generatedStreetAddress.find(streetName) != std::string::npos;
        }));
}
