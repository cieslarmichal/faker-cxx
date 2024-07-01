#include "faker-cxx/Location.h"

#include <algorithm>
#include <string>
#include <string_view>
#include <unordered_map>
#include <vector>

#include "gtest/gtest.h"

#include "common/StringHelper.h"
#include "faker-cxx/types/Precision.h"
#include "location/LocationData.h"
#include "person/PersonData.h"
#include "string/StringData.h"

using namespace ::testing;
using namespace faker;
using namespace faker::location;

namespace
{
const std::vector<AddressCountry> addressCountries{
    AddressCountry::Usa,     AddressCountry::Poland,  AddressCountry::France,    AddressCountry::Russia,
    AddressCountry::Ukraine, AddressCountry::Italy,   AddressCountry::Germany,   AddressCountry::Czech,
    AddressCountry::India,   AddressCountry::Denmark, AddressCountry::Australia, AddressCountry::Spain,
    AddressCountry::Brazil,  AddressCountry::Finland, AddressCountry::Estonia,
};

CountryAddressesInfo getAddresses(const AddressCountry& country)
{
    switch (country)
    {
    case AddressCountry::Usa:
        return usaAddresses;
    case AddressCountry::Poland:
        return polandAddresses;
    case AddressCountry::Russia:
        return russiaAddresses;
    case AddressCountry::France:
        return franceAddresses;
    case AddressCountry::Ukraine:
        return ukraineAddresses;
    case AddressCountry::Italy:
        return italyAddresses;
    case AddressCountry::Germany:
        return germanyAddresses;
    case AddressCountry::Czech:
        return czechAddresses;
    case AddressCountry::Australia:
        return australiaAddresses;
    case AddressCountry::India:
        return indiaAddresses;
    case AddressCountry::Denmark:
        return denmarkAddresses;
    case AddressCountry::Spain:
        return spainAddresses;
    case AddressCountry::Brazil:
        return brazilAddresses;
    case AddressCountry::Finland:
        return finlandAddresses;
    case AddressCountry::Estonia:
        return estoniaAddresses;
    default:
        return usaAddresses;
    }
}

const std::unordered_map<AddressCountry, std::string> generatedTestName{
    {AddressCountry::Usa, "shouldGenerateAmericanAddress"},
    {AddressCountry::France, "shouldGenerateFrenchAddress"},
    {AddressCountry::Poland, "shouldGeneratePolishAddress"},
    {AddressCountry::Russia, "shouldGenerateRussianAddress"},
    {AddressCountry::Ukraine, "shouldGenerateUkrainianAddress"},
    {AddressCountry::Italy, "shouldGenerateItalianAddress"},
    {AddressCountry::Germany, "shouldGenerateGermanAddress"},
    {AddressCountry::Czech, "shouldGenerateCzechAddress"},
    {AddressCountry::Australia, "shouldGenerateAustraliaAddress"},
    {AddressCountry::India, "shouldGenerateIndiaAddress"},
    {AddressCountry::Denmark, "shouldGenerateDenmarkAddress"},
    {AddressCountry::Spain, "shouldGenerateSpainAddress"},
    {AddressCountry::Brazil, "shouldGenerateBrazilAddress"},
    {AddressCountry::Finland, "shouldGenerateFinlandAddress"},
    {AddressCountry::Estonia, "shouldGenerateEstoniaAddress"},
};
}

class LocationTest : public TestWithParam<AddressCountry>
{
public:
    static bool checkIfZipCode(const std::string& zipCode)
    {
        const std::string zipCodeCharacters = "0123456789-";

        return std::ranges::all_of(zipCode,
                                   [&zipCodeCharacters](char dataCharacter)
                                   {
                                       return std::ranges::any_of(zipCodeCharacters,
                                                                  [dataCharacter](char numericCharacter)
                                                                  { return numericCharacter == dataCharacter; });
                                   });
    }

    static bool checkIfAllCharactersAreNumeric(const std::string& data)
    {
        return std::ranges::all_of(data,
                                   [](char dataCharacter)
                                   {
                                       return std::ranges::any_of(string::numericCharacters,
                                                                  [dataCharacter](char numericCharacter)
                                                                  { return numericCharacter == dataCharacter; });
                                   });
    }

    static bool checkIfCharacterIsNumeric(char character)
    {
        return std::ranges::any_of(string::numericCharacters,
                                   [character](char numericCharacter) { return numericCharacter == character; });
    }
};

TEST_P(LocationTest, shouldGenerateState)
{
    const auto country = GetParam();

    const auto& countryAddresses = getAddresses(country);

    // TODO: remove
    if (country == AddressCountry::Estonia)
    {
        return;
    }

    const auto generatedState = state(country);

    ASSERT_TRUE(std::ranges::any_of(countryAddresses.states, [&generatedState](const std::string_view& state)
                                    { return state == generatedState; }));
}

TEST_P(LocationTest, shouldGenerateCity)
{
    const auto country = GetParam();

    const auto& countryAddresses = getAddresses(country);

    const auto generatedCity = city(country);

    if (country == location::AddressCountry::Brazil)
    {
        const auto generatedCityElements = common::split(generatedCity, " ");

        const auto& generatedCityPrefix = generatedCityElements[0];

        std::vector<std::string_view> firstNames(person::brazilianMaleFirstNames.begin(),
                                                 person::brazilianMaleFirstNames.end());
        firstNames.insert(firstNames.end(), person::brazilianFemaleFirstNames.begin(),
                          person::brazilianFemaleFirstNames.end());

        std::vector<std::string_view> lastNames(person::brazilianLastNames.begin(), person::brazilianLastNames.end());

        ASSERT_TRUE(std::ranges::any_of(firstNames, [&generatedCityPrefix](const std::string_view& firstName)
                                        { return generatedCityPrefix.find(firstName) != std::string::npos; }) ||
                    std::ranges::any_of(lastNames, [&generatedCityPrefix](const std::string_view& lastName)
                                        { return generatedCityPrefix.find(lastName) != std::string::npos; }) ||
                    std::ranges::any_of(brazilCitySuffixes, [&generatedCity](const std::string_view& citySuffix)
                                        { return generatedCity.find(citySuffix) != std::string::npos; }));
    }
    else
    {
        ASSERT_TRUE(std::ranges::any_of(countryAddresses.cities, [&generatedCity](const std::string_view& city)
                                        { return city == generatedCity; }));
    }
}

TEST_P(LocationTest, shouldGenerateZipCode)
{
    const auto country = GetParam();

    const auto& countryAddresses = getAddresses(country);

    const auto generatedZipCode = zipCode(country);

    ASSERT_EQ(generatedZipCode.size(), countryAddresses.zipCodeFormat.size());

    ASSERT_TRUE(checkIfZipCode(generatedZipCode));
}

TEST_P(LocationTest, shouldGenerateBuildingNumber)
{
    const auto country = GetParam();

    const auto& countryAddresses = getAddresses(country);

    const auto generatedBuildingNumber = buildingNumber(country);

    const auto generatedBuildingNumberExceptLastCharacter =
        generatedBuildingNumber.substr(0, generatedBuildingNumber.size() - 1);

    ASSERT_TRUE(
        std::ranges::any_of(countryAddresses.buildingNumberFormats,
                            [&generatedBuildingNumber](const std::string_view& buildingNumberFormat)
                            {
                                for (std::size_t i = 0; i < buildingNumberFormat.size(); i++)
                                {
                                    if (buildingNumberFormat[i] == '#')
                                    {
                                        const auto isNumeric = checkIfCharacterIsNumeric(generatedBuildingNumber[i]);

                                        if (!isNumeric)
                                        {
                                            return false;
                                        }
                                    }
                                    else
                                    {
                                        if (generatedBuildingNumber.find(buildingNumberFormat[i]) == std::string::npos)
                                        {
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

    const auto& countryAddresses = getAddresses(country);

    const auto generatedSecondaryAddress = secondaryAddress(country);

    ASSERT_TRUE((countryAddresses.secondaryAddressFormats.empty() && generatedSecondaryAddress.empty()) ||
                std::ranges::any_of(
                    countryAddresses.secondaryAddressFormats,
                    [&generatedSecondaryAddress](const std::string_view& secondaryAddressFormat)
                    {
                        for (std::size_t i = 0; i < secondaryAddressFormat.size(); i++)
                        {
                            if (secondaryAddressFormat[i] == '#')
                            {
                                const auto isNumeric = checkIfCharacterIsNumeric(generatedSecondaryAddress[i]);

                                if (!isNumeric)
                                {
                                    return false;
                                }
                            }
                            else
                            {
                                if (generatedSecondaryAddress.find(secondaryAddressFormat[i]) == std::string::npos)
                                {
                                    return false;
                                }
                            }
                        }

                        return true;
                    }));
}

INSTANTIATE_TEST_SUITE_P(TestLocationByCountries, LocationTest, ValuesIn(addressCountries),
                         [](const TestParamInfo<AddressCountry>& paramInfo)
                         { return generatedTestName.at(paramInfo.param); });

TEST_F(LocationTest, shouldGenerateUsaStreet)
{
    const auto generatedStreet = street();

    const auto generatedStreetElements = common::split(generatedStreet, " ");

    const auto& generatedFirstOrLastName = generatedStreetElements[0];
    const auto& generatedStreetSuffix = generatedStreetElements[1];

    std::vector<std::string_view> firstNames(person::englishMaleFirstNames.begin(),
                                             person::englishMaleFirstNames.end());
    firstNames.insert(firstNames.end(), person::englishFemaleFirstNames.begin(), person::englishFemaleFirstNames.end());

    ASSERT_EQ(generatedStreetElements.size(), 2);
    ASSERT_TRUE(std::ranges::any_of(firstNames, [&generatedFirstOrLastName](const std::string_view& firstName)
                                    { return firstName == generatedFirstOrLastName; }) ||
                std::ranges::any_of(person::englishLastNames,
                                    [&generatedFirstOrLastName](const std::string_view& lastName)
                                    { return lastName == generatedFirstOrLastName; }));
    ASSERT_TRUE(std::ranges::any_of(usaStreetSuffixes, [&generatedStreetSuffix](const std::string_view& streetSuffix)
                                    { return streetSuffix == generatedStreetSuffix; }));
}

TEST_F(LocationTest, shouldGenerateUsaStreetAddress)
{
    const auto generatedStreetAddress = streetAddress();

    const auto generatedStreetAddressElements = common::split(generatedStreetAddress, " ");

    const auto& generatedBuildingNumber = generatedStreetAddressElements[0];
    const auto& generatedFirstOrLastName = generatedStreetAddressElements[1];
    const auto& generatedStreetSuffix = generatedStreetAddressElements[2];

    std::vector<std::string_view> firstNames(person::englishMaleFirstNames.begin(),
                                             person::englishMaleFirstNames.end());
    firstNames.insert(firstNames.end(), person::englishFemaleFirstNames.begin(), person::englishFemaleFirstNames.end());

    ASSERT_EQ(generatedStreetAddressElements.size(), 3);
    ASSERT_TRUE(generatedBuildingNumber.size() >= 3 && generatedBuildingNumber.size() <= 5);
    ASSERT_TRUE(checkIfAllCharactersAreNumeric(generatedBuildingNumber));
    ASSERT_TRUE(std::ranges::any_of(firstNames, [&generatedFirstOrLastName](const std::string_view& firstName)
                                    { return firstName == generatedFirstOrLastName; }) ||
                std::ranges::any_of(person::englishLastNames,
                                    [&generatedFirstOrLastName](const std::string_view& lastName)
                                    { return lastName == generatedFirstOrLastName; }));
    ASSERT_TRUE(std::ranges::any_of(usaStreetSuffixes, [&generatedStreetSuffix](const std::string_view& streetSuffix)
                                    { return streetSuffix == generatedStreetSuffix; }));
}

TEST_F(LocationTest, shouldGeneratePolandStreet)
{
    const auto generatedStreet = street(AddressCountry::Poland);

    const auto generatedStreetElements = common::split(generatedStreet, " ");

    const auto& generatedStreetPrefix = generatedStreetElements[0];
    const auto& generatedStreetName =
        common::join({generatedStreetElements.begin() + 1, generatedStreetElements.end()});

    ASSERT_TRUE(std::ranges::any_of(polandStreetPrefixes, [&generatedStreetPrefix](const std::string_view& streetPrefix)
                                    { return streetPrefix == generatedStreetPrefix; }));
    ASSERT_TRUE(std::ranges::any_of(polandStreetNames, [&generatedStreetName](const std::string_view& streetName)
                                    { return streetName == generatedStreetName; }));
}

TEST_F(LocationTest, shouldGeneratePolandStreetAddress)
{
    const auto generatedStreetAddress = streetAddress(AddressCountry::Poland);

    ASSERT_TRUE(std::ranges::any_of(polandStreetPrefixes, [&generatedStreetAddress](const std::string_view& prefix)
                                    { return generatedStreetAddress.find(prefix) != std::string::npos; }));
    ASSERT_TRUE(std::ranges::any_of(polandStreetNames, [&generatedStreetAddress](const std::string_view& street)
                                    { return generatedStreetAddress.find(street) != std::string::npos; }));
}

TEST_F(LocationTest, shouldGenerateRussiaStreet)
{
    const auto generatedStreet = street(AddressCountry::Russia);

    const auto generatedStreetElements = common::split(generatedStreet, " ");

    const auto& generatedStreetPrefix = generatedStreetElements[0];
    const auto& generatedStreetSuffix =
        common::join({generatedStreetElements.begin() + 1, generatedStreetElements.end()});

    std::vector<std::string_view> firstNames(person::russianMaleFirstNames.begin(),
                                             person::russianMaleFirstNames.end());
    firstNames.insert(firstNames.end(), person::russianFemaleFirstNames.begin(), person::russianFemaleFirstNames.end());

    std::vector<std::string_view> lastNames(person::russianMaleLastNames.begin(), person::russianMaleLastNames.end());
    firstNames.insert(firstNames.end(), person::russianFemaleLastNames.begin(), person::russianFemaleLastNames.end());

    ASSERT_TRUE(std::ranges::any_of(russiaStreetPrefixes, [&generatedStreetPrefix](const std::string_view& streetPrefix)
                                    { return streetPrefix == generatedStreetPrefix; }));
    ASSERT_TRUE(std::ranges::any_of(firstNames, [&generatedStreetSuffix](const std::string_view& firstName)
                                    { return firstName == generatedStreetSuffix; }) ||
                std::ranges::any_of(lastNames, [&generatedStreetSuffix](const std::string_view& lastName)
                                    { return lastName == generatedStreetSuffix; }) ||
                std::ranges::any_of(russiaStreetNames, [&generatedStreetSuffix](const std::string_view& streetName)
                                    { return streetName == generatedStreetSuffix; }));
}

TEST_F(LocationTest, shouldGenerateRussiaStreetAddress)
{
    const auto generatedStreetAddress = streetAddress(AddressCountry::Russia);

    std::vector<std::string_view> firstNames(person::russianMaleFirstNames.begin(),
                                             person::russianMaleFirstNames.end());
    firstNames.insert(firstNames.end(), person::russianFemaleFirstNames.begin(), person::russianFemaleFirstNames.end());

    std::vector<std::string_view> lastNames(person::russianMaleLastNames.begin(), person::russianMaleLastNames.end());
    firstNames.insert(firstNames.end(), person::russianFemaleLastNames.begin(), person::russianFemaleLastNames.end());

    ASSERT_TRUE(std::ranges::any_of(russiaStreetPrefixes, [&generatedStreetAddress](const std::string_view& prefix)
                                    { return generatedStreetAddress.find(prefix) != std::string::npos; }));
    ASSERT_TRUE(std::ranges::any_of(firstNames, [&generatedStreetAddress](const std::string_view& firstName)
                                    { return generatedStreetAddress.find(firstName) != std::string::npos; }) ||
                std::ranges::any_of(lastNames, [&generatedStreetAddress](const std::string_view& lastName)
                                    { return generatedStreetAddress.find(lastName) != std::string::npos; }) ||
                std::ranges::any_of(russiaStreetNames, [&generatedStreetAddress](const std::string_view& streetName)
                                    { return generatedStreetAddress.find(streetName) != std::string::npos; }));
}

TEST_F(LocationTest, shouldGenerateFranceStreet)
{
    const auto generatedStreet = street(AddressCountry::France);

    const auto generatedStreetElements = common::split(generatedStreet, " ");

    const auto& generatedStreetPrefix = generatedStreetElements[0];
    const auto& generatedStreetSuffix =
        common::join({generatedStreetElements.begin() + 1, generatedStreetElements.end()});

    ASSERT_GE(generatedStreetElements.size(), 2);
    ASSERT_TRUE(std::ranges::any_of(franceStreetPrefixes, [&generatedStreetPrefix](const std::string_view& streetPrefix)
                                    { return streetPrefix == generatedStreetPrefix; }));
    ASSERT_TRUE(std::ranges::any_of(franceStreetSuffixes, [&generatedStreetSuffix](const std::string_view& streetSuffix)
                                    { return streetSuffix == generatedStreetSuffix; }));
}

TEST_F(LocationTest, shouldGenerateFranceStreetAddress)
{
    const auto generatedStreetAddress = streetAddress(AddressCountry::France);

    const auto generatedStreetAddressElements = common::split(generatedStreetAddress, " ");

    const auto& generatedBuildingNumber = generatedStreetAddressElements[0];
    const auto& generatedStreetPrefix = generatedStreetAddressElements[1];
    const auto& generatedStreetSuffix =
        common::join({generatedStreetAddressElements.begin() + 2, generatedStreetAddressElements.end()});

    ASSERT_GE(generatedStreetAddressElements.size(), 3);
    ASSERT_TRUE(!generatedBuildingNumber.empty() && generatedBuildingNumber.size() <= 4);
    ASSERT_TRUE(checkIfAllCharactersAreNumeric(generatedBuildingNumber));
    ASSERT_TRUE(std::ranges::any_of(franceStreetPrefixes, [&generatedStreetPrefix](const std::string_view& streetPrefix)
                                    { return streetPrefix == generatedStreetPrefix; }));
    ASSERT_TRUE(std::ranges::any_of(franceStreetSuffixes, [&generatedStreetSuffix](const std::string_view& streetSuffix)
                                    { return streetSuffix == generatedStreetSuffix; }));
}

TEST_F(LocationTest, shouldGenerateCountry)
{
    const auto generatedCountry = country();

    ASSERT_TRUE(std::ranges::any_of(allCountries, [generatedCountry](const std::string_view& country)
                                    { return country == generatedCountry; }));
}

TEST_F(LocationTest, shouldGenerateCountryCode)
{
    const auto generatedCountryCode = countryCode();

    ASSERT_TRUE(std::ranges::any_of(countryCodes, [generatedCountryCode](const std::string_view& countryCode)
                                    { return countryCode == generatedCountryCode; }));
}

TEST_F(LocationTest, shouldGenerateLatitude)
{
    const auto generatedLatitude = latitude();

    auto offset = generatedLatitude.size();
    const auto latitudeAsFloat = std::stof(generatedLatitude, &offset);

    const auto generatedLatitudeParts = common::split(generatedLatitude, ".");

    ASSERT_EQ(generatedLatitudeParts.size(), 2);
    ASSERT_EQ(generatedLatitudeParts[1].size(), 4);
    ASSERT_GE(latitudeAsFloat, -90);
    ASSERT_LE(latitudeAsFloat, 90);
}

TEST_F(LocationTest, shouldGenerateLatitudeWithSpecifiedPrecision)
{
    const auto generatedLatitude = latitude(Precision::ThreeDp);

    auto offset = generatedLatitude.size();
    const auto latitudeAsFloat = std::stof(generatedLatitude, &offset);

    const auto generatedLatitudeParts = common::split(generatedLatitude, ".");

    ASSERT_EQ(generatedLatitudeParts.size(), 2);
    ASSERT_EQ(generatedLatitudeParts[1].size(), 3);
    ASSERT_GE(latitudeAsFloat, -90);
    ASSERT_LE(latitudeAsFloat, 90);
}

TEST_F(LocationTest, shouldGenerateLongitude)
{
    const auto generatedLongitude = longitude();

    auto offset = generatedLongitude.size();
    const auto longitudeAsFloat = std::stof(generatedLongitude, &offset);

    const auto generatedLongitudeParts = common::split(generatedLongitude, ".");

    ASSERT_EQ(generatedLongitudeParts.size(), 2);
    ASSERT_EQ(generatedLongitudeParts[1].size(), 4);
    ASSERT_GE(longitudeAsFloat, -180);
    ASSERT_LE(longitudeAsFloat, 180);
}

TEST_F(LocationTest, shouldGenerateLongitudeWithSpecifiedPrecision)
{
    const auto generatedLongitude = longitude(Precision::SixDp);

    auto offset = generatedLongitude.size();
    const auto longitudeAsFloat = std::stof(generatedLongitude, &offset);

    const auto generatedLongitudeParts = common::split(generatedLongitude, ".");

    ASSERT_EQ(generatedLongitudeParts.size(), 2);
    ASSERT_EQ(generatedLongitudeParts[1].size(), 6);
    ASSERT_GE(longitudeAsFloat, -180);
    ASSERT_LE(longitudeAsFloat, 180);
}

TEST_F(LocationTest, shouldGenerateDirection)
{
    const auto generatedDirection = direction();

    ASSERT_TRUE(std::ranges::any_of(directions, [generatedDirection](const std::string_view& direction)
                                    { return direction == generatedDirection; }));
}

TEST_F(LocationTest, shouldGenerateTimeZone)
{
    const auto generatedTimeZone = timeZone();

    ASSERT_TRUE(std::ranges::any_of(timeZones, [generatedTimeZone](const std::string_view& timeZone)
                                    { return timeZone == generatedTimeZone; }));
}

TEST_F(LocationTest, shouldGenerateUkraineStreet)
{
    const auto generatedStreet = street(AddressCountry::Ukraine);

    const auto generatedStreetElements = common::split(generatedStreet, " ");

    const auto& generatedStreetPrefix = generatedStreetElements[0];
    const auto& generatedStreetSuffix =
        common::join({generatedStreetElements.begin() + 1, generatedStreetElements.end()});

    ASSERT_TRUE(std::ranges::any_of(ukraineStreetPrefixes,
                                    [&generatedStreetPrefix](const std::string_view& streetPrefix)
                                    { return streetPrefix == generatedStreetPrefix; }));

    std::vector<std::string_view> firstNames(person::ukrainianMaleFirstNames.begin(),
                                             person::ukrainianMaleFirstNames.end());
    firstNames.insert(firstNames.end(), person::ukrainianFemaleFirstNames.begin(),
                      person::ukrainianFemaleFirstNames.end());

    std::vector<std::string_view> lastNames(person::ukrainianMalesLastNames.begin(),
                                            person::ukrainianMalesLastNames.end());
    firstNames.insert(firstNames.end(), person::ukrainianFemaleLastNames.begin(),
                      person::ukrainianFemaleLastNames.end());

    ASSERT_TRUE(std::ranges::any_of(firstNames, [&generatedStreetSuffix](const std::string_view& firstName)
                                    { return generatedStreetSuffix.find(firstName) != std::string::npos; }) ||
                std::ranges::any_of(lastNames, [&generatedStreetSuffix](const std::string_view& lastName)
                                    { return generatedStreetSuffix.find(lastName) != std::string::npos; }) ||
                std::ranges::any_of(ukraineStreetNames, [&generatedStreetSuffix](const std::string_view& streetName)
                                    { return generatedStreetSuffix.find(streetName) != std::string::npos; }));
}

TEST_F(LocationTest, shouldGenerateUkraineStreetAddress)
{
    const auto generatedStreetAddress = streetAddress(AddressCountry::Ukraine);

    ASSERT_TRUE(std::ranges::any_of(ukraineStreetPrefixes, [&generatedStreetAddress](const std::string_view& prefix)
                                    { return generatedStreetAddress.find(prefix) != std::string::npos; }));

    std::vector<std::string_view> firstNames(person::ukrainianMaleFirstNames.begin(),
                                             person::ukrainianMaleFirstNames.end());
    firstNames.insert(firstNames.end(), person::ukrainianFemaleFirstNames.begin(),
                      person::ukrainianFemaleFirstNames.end());

    std::vector<std::string_view> lastNames(person::ukrainianMalesLastNames.begin(),
                                            person::ukrainianMalesLastNames.end());
    firstNames.insert(firstNames.end(), person::ukrainianFemaleLastNames.begin(),
                      person::ukrainianFemaleLastNames.end());

    ASSERT_TRUE(std::ranges::any_of(firstNames, [&generatedStreetAddress](const std::string_view& firstName)
                                    { return generatedStreetAddress.find(firstName) != std::string::npos; }) ||
                std::ranges::any_of(lastNames, [&generatedStreetAddress](const std::string_view& lastName)
                                    { return generatedStreetAddress.find(lastName) != std::string::npos; }) ||
                std::ranges::any_of(ukraineStreetNames, [&generatedStreetAddress](const std::string_view& streetName)
                                    { return generatedStreetAddress.find(streetName) != std::string::npos; }));
}

TEST_F(LocationTest, shouldGenerateItalyStreet)
{
    const auto generatedStreet = street(AddressCountry::Italy);

    const auto generatedStreetElements = common::split(generatedStreet, " ");

    const auto& generatedStreetPrefix = generatedStreetElements[0];
    const auto& generatedStreetSuffix =
        common::join({generatedStreetElements.begin() + 1, generatedStreetElements.end()});

    ASSERT_TRUE(std::ranges::any_of(italyStreetPrefixes, [&generatedStreetPrefix](const std::string_view& streetPrefix)
                                    { return streetPrefix == generatedStreetPrefix; }));

    std::vector<std::string_view> firstNames(person::italianMaleFirstNames.begin(),
                                             person::italianMaleFirstNames.end());
    firstNames.insert(firstNames.end(), person::italianFemaleFirstNames.begin(), person::italianFemaleFirstNames.end());

    ASSERT_TRUE(std::ranges::any_of(firstNames, [&generatedStreetSuffix](const std::string_view& firstName)
                                    { return generatedStreetSuffix.find(firstName) != std::string::npos; }) ||
                std::ranges::any_of(person::italianLastNames, [&generatedStreetSuffix](const std::string_view& lastName)
                                    { return generatedStreetSuffix.find(lastName) != std::string::npos; }));
}

TEST_F(LocationTest, shouldGenerateItalyStreetAddress)
{
    const auto generatedStreetAddress = streetAddress(AddressCountry::Italy);

    ASSERT_TRUE(std::ranges::any_of(italyStreetPrefixes, [&generatedStreetAddress](const std::string_view& prefix)
                                    { return generatedStreetAddress.find(prefix) != std::string::npos; }));

    std::vector<std::string_view> firstNames(person::italianMaleFirstNames.begin(),
                                             person::italianMaleFirstNames.end());
    firstNames.insert(firstNames.end(), person::italianFemaleFirstNames.begin(), person::italianFemaleFirstNames.end());

    ASSERT_TRUE(std::ranges::any_of(firstNames, [&generatedStreetAddress](const std::string_view& firstName)
                                    { return generatedStreetAddress.find(firstName) != std::string::npos; }) ||
                std::ranges::any_of(person::italianLastNames,
                                    [&generatedStreetAddress](const std::string_view& lastName)
                                    { return generatedStreetAddress.find(lastName) != std::string::npos; }));
}

TEST_F(LocationTest, shouldGenerateGermanyStreet)
{
    const auto generatedStreet = street(AddressCountry::Germany);

    ASSERT_TRUE(std::ranges::any_of(germanyStreetNames, [&generatedStreet](const std::string_view& streetName)
                                    { return streetName == generatedStreet; }));
}

TEST_F(LocationTest, shouldGenerateGermanyStreetAddress)
{
    const auto generatedStreetAddress = streetAddress(AddressCountry::Germany);

    ASSERT_TRUE(std::ranges::any_of(germanyStreetNames, [&generatedStreetAddress](const std::string_view& streetName)
                                    { return generatedStreetAddress.find(streetName) != std::string::npos; }));
}

TEST_F(LocationTest, shouldGenerateCzechStreet)
{
    const auto generatedStreet = street(AddressCountry::Czech);

    ASSERT_TRUE(std::ranges::any_of(czechStreetNames, [&generatedStreet](const std::string_view& streetName)
                                    { return streetName == generatedStreet; }));
}

TEST_F(LocationTest, shouldGenerateCzechStreetAddress)
{
    const auto generatedStreetAddress = streetAddress(AddressCountry::Czech);

    ASSERT_TRUE(std::ranges::any_of(czechStreetNames, [&generatedStreetAddress](const std::string_view& streetName)
                                    { return generatedStreetAddress.find(streetName) != std::string::npos; }));
}

TEST_F(LocationTest, shouldGenerateAustraliaStreet)
{
    const auto generatedStreet = street(AddressCountry::Australia);

    std::vector<std::string_view> firstNames(person::australianMaleFirstNames.begin(),
                                             person::australianMaleFirstNames.end());
    firstNames.insert(firstNames.end(), person::australianFemaleFirstNames.begin(),
                      person::australianFemaleFirstNames.end());

    ASSERT_TRUE((std::ranges::any_of(firstNames, [&generatedStreet](const std::string_view& firstName)
                                     { return generatedStreet.find(firstName) != std::string::npos; }) ||
                 std::ranges::any_of(person::australianLastNames, [&generatedStreet](const std::string_view& lastName)
                                     { return generatedStreet.find(lastName) != std::string::npos; })) &&
                std::ranges::any_of(australiaStreetSuffixes, [&generatedStreet](const std::string_view& streetSuffix)
                                    { return generatedStreet.find(streetSuffix) != std::string::npos; }));
}

TEST_F(LocationTest, shouldGenerateAustraliaStreetAddress)
{
    const auto generatedStreetAddress = streetAddress(AddressCountry::Australia);

    const auto generatedStreetAddressElements = common::split(generatedStreetAddress, " ");

    const auto& generatedBuildingNumber = generatedStreetAddressElements[0];
    const auto& generatedStreetSuffix =
        common::join({generatedStreetAddressElements.begin() + 1, generatedStreetAddressElements.end()});

    std::vector<std::string_view> firstNames(person::australianMaleFirstNames.begin(),
                                             person::australianMaleFirstNames.end());
    firstNames.insert(firstNames.end(), person::australianFemaleFirstNames.begin(),
                      person::australianFemaleFirstNames.end());

    ASSERT_TRUE(!generatedBuildingNumber.empty() && generatedBuildingNumber.size() <= 4);
    ASSERT_TRUE(checkIfAllCharactersAreNumeric(generatedBuildingNumber));

    ASSERT_TRUE(
        (std::ranges::any_of(firstNames, [&generatedStreetSuffix](const std::string_view& firstName)
                             { return generatedStreetSuffix.find(firstName) != std::string::npos; }) ||
         std::ranges::any_of(person::australianLastNames, [&generatedStreetSuffix](const std::string_view& lastName)
                             { return generatedStreetSuffix.find(lastName) != std::string::npos; })) &&
        std::ranges::any_of(australiaStreetSuffixes, [&generatedStreetSuffix](const std::string_view& streetSuffix)
                            { return generatedStreetSuffix.find(streetSuffix) != std::string::npos; }));
}

TEST_F(LocationTest, shouldGenerateIndiaStreetAddress)
{
    const auto generatedStreetAddress = streetAddress(AddressCountry::India);

    const auto generatedStreetAddressElements = common::split(generatedStreetAddress, " ");

    const auto& generatedBuildingNumber = generatedStreetAddressElements[0];
    const auto& generatedStreetSuffix =
        common::join({generatedStreetAddressElements.begin() + 2, generatedStreetAddressElements.end()});

    ASSERT_GE(generatedStreetAddressElements.size(), 3);
    ASSERT_TRUE(!generatedBuildingNumber.empty());
    ASSERT_TRUE(checkIfAllCharactersAreNumeric(generatedBuildingNumber));
    ASSERT_TRUE(std::ranges::any_of(indiaStreetSuffixes, [&generatedStreetSuffix](const std::string_view& streetSuffix)
                                    { return streetSuffix == generatedStreetSuffix; }));
}

TEST_F(LocationTest, shouldGenerateDenmarkStreet)
{
    const auto generatedStreet = street(AddressCountry::Denmark);

    ASSERT_TRUE(std::ranges::any_of(denmarkStreetNames, [&generatedStreet](const std::string_view& streetName)
                                    { return streetName == generatedStreet; }));
}

TEST_F(LocationTest, shouldGenerateDenmarkStreetAddress)
{
    const auto generatedStreetAddress = streetAddress(AddressCountry::Denmark);

    ASSERT_TRUE(std::ranges::any_of(denmarkStreetNames, [&generatedStreetAddress](const std::string_view& streetName)
                                    { return generatedStreetAddress.find(streetName) != std::string::npos; }));
}

TEST_F(LocationTest, shouldGenerateSpainStreet)
{
    const auto generatedStreet = street(AddressCountry::Spain);

    std::vector<std::string_view> firstNames(person::spanishMaleFirstNames.begin(),
                                             person::spanishMaleFirstNames.end());
    firstNames.insert(firstNames.end(), person::spanishFemaleFirstNames.begin(), person::spanishFemaleFirstNames.end());

    ASSERT_TRUE((std::ranges::any_of(firstNames, [&generatedStreet](const std::string_view& firstName)
                                     { return generatedStreet.find(firstName) != std::string::npos; }) ||
                 std::ranges::any_of(person::spanishLastNames, [&generatedStreet](const std::string_view& lastName)
                                     { return generatedStreet.find(lastName) != std::string::npos; })) &&
                std::ranges::any_of(spainStreetSuffixes, [&generatedStreet](const std::string_view& streetSuffix)
                                    { return generatedStreet.find(streetSuffix) != std::string::npos; }));
}

TEST_F(LocationTest, shouldGenerateSpainStreetAddress)
{
    const auto generatedStreetAddress = streetAddress(AddressCountry::Spain);

    ASSERT_TRUE(std::ranges::any_of(spainStreetSuffixes, [&generatedStreetAddress](const std::string_view& suffix)
                                    { return generatedStreetAddress.find(suffix) != std::string::npos; }));

    std::vector<std::string_view> firstNames(person::spanishMaleFirstNames.begin(),
                                             person::spanishMaleFirstNames.end());
    firstNames.insert(firstNames.end(), person::spanishFemaleFirstNames.begin(), person::spanishFemaleFirstNames.end());

    ASSERT_TRUE(std::ranges::any_of(firstNames, [&generatedStreetAddress](const std::string_view& firstName)
                                    { return generatedStreetAddress.find(firstName) != std::string::npos; }) ||
                std::ranges::any_of(person::spanishLastNames,
                                    [&generatedStreetAddress](const std::string_view& lastName)
                                    { return generatedStreetAddress.find(lastName) != std::string::npos; }));
}

TEST_F(LocationTest, shouldGenerateFinlandStreet)
{
    const auto generatedStreet = street(AddressCountry::Finland);

    const auto generatedStreetElements = common::split(generatedStreet, " ");

    const auto& generatedStreetPrefix = generatedStreetElements[0];
    const auto& generatedStreetSuffix = generatedStreetElements[1];

    std::vector<std::string_view> firstNames(person::finnishMaleFirstNames.begin(),
                                             person::finnishMaleFirstNames.end());
    firstNames.insert(firstNames.end(), person::finnishFemaleFirstNames.begin(), person::finnishFemaleFirstNames.end());

    ASSERT_GE(generatedStreetElements.size(), 2);

    ASSERT_TRUE(std::ranges::any_of(finlandStreetSuffixes,
                                    [&generatedStreetSuffix](const std::string_view& streetSuffix)
                                    { return streetSuffix == generatedStreetSuffix; }));

    ASSERT_TRUE(std::ranges::any_of(firstNames, [&generatedStreetPrefix](const std::string_view& firstName)
                                    { return generatedStreetPrefix.find(firstName) != std::string::npos; }) ||
                std::ranges::any_of(person::finnishLastNames, [&generatedStreetPrefix](const std::string_view& lastName)
                                    { return generatedStreetPrefix.find(lastName) != std::string::npos; }));
}

TEST_F(LocationTest, shouldGenerateFinlandStreetAddress)
{
    const auto generatedStreetAddress = streetAddress(AddressCountry::Finland);

    ASSERT_TRUE(std::ranges::any_of(finlandStreetSuffixes, [&generatedStreetAddress](const std::string_view& suffix)
                                    { return generatedStreetAddress.find(suffix) != std::string::npos; }));

    std::vector<std::string_view> firstNames(person::finnishMaleFirstNames.begin(),
                                             person::finnishMaleFirstNames.end());
    firstNames.insert(firstNames.end(), person::finnishFemaleFirstNames.begin(), person::finnishFemaleFirstNames.end());

    ASSERT_TRUE(std::ranges::any_of(firstNames, [&generatedStreetAddress](const std::string_view& firstName)
                                    { return generatedStreetAddress.find(firstName) != std::string::npos; }) ||
                std::ranges::any_of(person::finnishLastNames,
                                    [&generatedStreetAddress](const std::string_view& lastName)
                                    { return generatedStreetAddress.find(lastName) != std::string::npos; }));
}

TEST_F(LocationTest, shouldGenerateEstoniaStreet)
{
    const auto generatedStreet = street(AddressCountry::Estonia);

    ASSERT_TRUE(std::ranges::any_of(estoniaStreetNames, [&generatedStreet](const std::string_view& streetName)
                                    { return generatedStreet.find(streetName) != std::string::npos; }));
}

TEST_F(LocationTest, shouldGenerateEstoniaStreetAddress)
{
    const auto generatedStreetAddress = streetAddress(AddressCountry::Estonia);

    ASSERT_TRUE(std::ranges::any_of(estoniaStreetNames, [&generatedStreetAddress](const std::string_view& streetName)
                                    { return generatedStreetAddress.find(streetName) != std::string::npos; }));
}
