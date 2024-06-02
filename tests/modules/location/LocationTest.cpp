#include "faker-cxx/Location.h"

#include <algorithm>
#include <cstddef>
#include <string>
#include <string_view>
#include <unordered_map>
#include <vector>

#include "gtest/gtest.h"

#include "common/StringHelper.h"
#include "faker-cxx/types/Precision.h"
#include "location/LocationData.h"
#include "person/data/australia/AustralianFirstNames.h"
#include "person/data/australia/AustralianLastNames.h"
#include "person/data/brazil/BrazilianFirstNames.h"
#include "person/data/brazil/BrazilianLastNames.h"
#include "person/data/england/EnglishFirstNames.h"
#include "person/data/england/EnglishLastNames.h"
#include "person/data/finland/FinnishFirstNames.h"
#include "person/data/finland/FinnishLastNames.h"
#include "person/data/italy/ItalianFirstNames.h"
#include "person/data/italy/ItalianLastNames.h"
#include "person/data/russia/RussianFirstNames.h"
#include "person/data/russia/RussianLastNames.h"
#include "person/data/spain/SpanishFirstNames.h"
#include "person/data/spain/SpanishLastNames.h"
#include "person/data/ukraine/UkrainianFirstNames.h"
#include "person/data/ukraine/UkrainianLastNames.h"
#include "string/StringData.h"

using namespace ::testing;
using namespace faker;

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

TEST_P(LocationTest, shouldGenerateCounty)
{
    const auto country = GetParam();

    const auto& countryAddresses = getAddresses(country);

    const auto generatedCounty = Location::county(country);

    ASSERT_TRUE(std::ranges::any_of(countryAddresses.counties, [&generatedCounty](const std::string_view& county)
                                    { return county == generatedCounty; }) ||
                (countryAddresses.counties.empty() && generatedCounty.empty()));
}

TEST_P(LocationTest, shouldGenerateState)
{
    const auto country = GetParam();

    const auto& countryAddresses = getAddresses(country);

    // TODO: remove
    if (country == AddressCountry::Estonia)
    {
        return;
    }

    const auto generatedState = Location::state(country);

    ASSERT_TRUE(std::ranges::any_of(countryAddresses.states, [&generatedState](const std::string_view& state)
                                    { return state == generatedState; }));
}

TEST_P(LocationTest, shouldGenerateCity)
{
    const auto country = GetParam();

    const auto& countryAddresses = getAddresses(country);

    const auto generatedCity = Location::city(country);

    if (country == faker::AddressCountry::Brazil)
    {
        const auto generatedCityElements = StringHelper::split(generatedCity, " ");

        const auto& generatedCityPrefix = generatedCityElements[0];

        std::vector<std::string> firstNames{brazilianMalesFirstNames};
        firstNames.insert(firstNames.end(), brazilianFemalesFirstNames.begin(), brazilianFemalesFirstNames.end());

        std::vector<std::string> lastNames{brazilianLastNames};

        ASSERT_TRUE(std::ranges::any_of(firstNames, [&generatedCityPrefix](const std::string& firstName)
                                        { return generatedCityPrefix.find(firstName) != std::string::npos; }) ||
                    std::ranges::any_of(lastNames, [&generatedCityPrefix](const std::string& lastName)
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

    const auto generatedZipCode = Location::zipCode(country);

    ASSERT_EQ(generatedZipCode.size(), countryAddresses.zipCodeFormat.size());

    ASSERT_TRUE(checkIfZipCode(generatedZipCode));
}

TEST_P(LocationTest, shouldGenerateBuildingNumber)
{
    const auto country = GetParam();

    const auto& countryAddresses = getAddresses(country);

    const auto generatedBuildingNumber = Location::buildingNumber(country);

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

    const auto generatedSecondaryAddress = Location::secondaryAddress(country);

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
                         [](const TestParamInfo<AddressCountry>& info) { return generatedTestName.at(info.param); });

TEST_F(LocationTest, shouldGenerateUsaStreet)
{
    const auto generatedStreet = Location::street();

    const auto generatedStreetElements = StringHelper::split(generatedStreet, " ");

    const auto& generatedFirstOrLastName = generatedStreetElements[0];
    const auto& generatedStreetSuffix = generatedStreetElements[1];

    std::vector<std::string> firstNames{englishMalesFirstNames};
    firstNames.insert(firstNames.end(), englishFemalesFirstNames.begin(), englishFemalesFirstNames.end());

    ASSERT_EQ(generatedStreetElements.size(), 2);
    ASSERT_TRUE(std::ranges::any_of(firstNames, [&generatedFirstOrLastName](const std::string& firstName)
                                    { return firstName == generatedFirstOrLastName; }) ||
                std::ranges::any_of(englishLastNames, [&generatedFirstOrLastName](const std::string& lastName)
                                    { return lastName == generatedFirstOrLastName; }));
    ASSERT_TRUE(std::ranges::any_of(usaStreetSuffixes, [&generatedStreetSuffix](const std::string_view& streetSuffix)
                                    { return streetSuffix == generatedStreetSuffix; }));
}

TEST_F(LocationTest, shouldGenerateUsaStreetAddress)
{
    const auto generatedStreetAddress = Location::streetAddress();

    const auto generatedStreetAddressElements = StringHelper::split(generatedStreetAddress, " ");

    const auto& generatedBuildingNumber = generatedStreetAddressElements[0];
    const auto& generatedFirstOrLastName = generatedStreetAddressElements[1];
    const auto& generatedStreetSuffix = generatedStreetAddressElements[2];

    std::vector<std::string> firstNames{englishMalesFirstNames};
    firstNames.insert(firstNames.end(), englishFemalesFirstNames.begin(), englishFemalesFirstNames.end());

    ASSERT_EQ(generatedStreetAddressElements.size(), 3);
    ASSERT_TRUE(generatedBuildingNumber.size() >= 3 && generatedBuildingNumber.size() <= 5);
    ASSERT_TRUE(checkIfAllCharactersAreNumeric(generatedBuildingNumber));
    ASSERT_TRUE(std::ranges::any_of(firstNames, [&generatedFirstOrLastName](const std::string& firstName)
                                    { return firstName == generatedFirstOrLastName; }) ||
                std::ranges::any_of(englishLastNames, [&generatedFirstOrLastName](const std::string& lastName)
                                    { return lastName == generatedFirstOrLastName; }));
    ASSERT_TRUE(std::ranges::any_of(usaStreetSuffixes, [&generatedStreetSuffix](const std::string_view& streetSuffix)
                                    { return streetSuffix == generatedStreetSuffix; }));
}

TEST_F(LocationTest, shouldGeneratePolandStreet)
{
    const auto generatedStreet = Location::street(AddressCountry::Poland);

    const auto generatedStreetElements = StringHelper::split(generatedStreet, " ");

    const auto& generatedStreetPrefix = generatedStreetElements[0];
    const auto& generatedStreetName =
        StringHelper::join({generatedStreetElements.begin() + 1, generatedStreetElements.end()});

    ASSERT_TRUE(std::ranges::any_of(polandStreetPrefixes, [&generatedStreetPrefix](const std::string_view& streetPrefix)
                                    { return streetPrefix == generatedStreetPrefix; }));
    ASSERT_TRUE(std::ranges::any_of(polandStreetNames, [&generatedStreetName](const std::string_view& streetName)
                                    { return streetName == generatedStreetName; }));
}

TEST_F(LocationTest, shouldGeneratePolandStreetAddress)
{
    const auto generatedStreetAddress = Location::streetAddress(AddressCountry::Poland);

    ASSERT_TRUE(std::ranges::any_of(polandStreetPrefixes, [&generatedStreetAddress](const std::string_view& prefix)
                                    { return generatedStreetAddress.find(prefix) != std::string::npos; }));
    ASSERT_TRUE(std::ranges::any_of(polandStreetNames, [&generatedStreetAddress](const std::string_view& street)
                                    { return generatedStreetAddress.find(street) != std::string::npos; }));
}

TEST_F(LocationTest, shouldGenerateRussiaStreet)
{
    const auto generatedStreet = Location::street(AddressCountry::Russia);

    const auto generatedStreetElements = StringHelper::split(generatedStreet, " ");

    const auto& generatedStreetPrefix = generatedStreetElements[0];
    const auto& generatedStreetSuffix =
        StringHelper::join({generatedStreetElements.begin() + 1, generatedStreetElements.end()});

    std::vector<std::string> firstNames{russianMalesFirstNames};
    firstNames.insert(firstNames.end(), russianFemalesFirstNames.begin(), russianFemalesFirstNames.end());

    std::vector<std::string> lastNames{russianMalesLastNames};
    firstNames.insert(firstNames.end(), russianFemalesLastNames.begin(), russianFemalesLastNames.end());

    ASSERT_TRUE(std::ranges::any_of(russiaStreetPrefixes, [&generatedStreetPrefix](const std::string_view& streetPrefix)
                                    { return streetPrefix == generatedStreetPrefix; }));
    ASSERT_TRUE(std::ranges::any_of(firstNames, [&generatedStreetSuffix](const std::string& firstName)
                                    { return firstName == generatedStreetSuffix; }) ||
                std::ranges::any_of(lastNames, [&generatedStreetSuffix](const std::string& lastName)
                                    { return lastName == generatedStreetSuffix; }) ||
                std::ranges::any_of(russiaStreetNames, [&generatedStreetSuffix](const std::string_view& streetName)
                                    { return streetName == generatedStreetSuffix; }));
}

TEST_F(LocationTest, shouldGenerateRussiaStreetAddress)
{
    const auto generatedStreetAddress = Location::streetAddress(AddressCountry::Russia);

    std::vector<std::string> firstNames{russianMalesFirstNames};
    firstNames.insert(firstNames.end(), russianFemalesFirstNames.begin(), russianFemalesFirstNames.end());

    std::vector<std::string> lastNames{russianMalesLastNames};
    lastNames.insert(lastNames.end(), russianFemalesLastNames.begin(), russianFemalesLastNames.end());

    ASSERT_TRUE(std::ranges::any_of(russiaStreetPrefixes, [&generatedStreetAddress](const std::string_view& prefix)
                                    { return generatedStreetAddress.find(prefix) != std::string::npos; }));
    ASSERT_TRUE(std::ranges::any_of(firstNames, [&generatedStreetAddress](const std::string& firstName)
                                    { return generatedStreetAddress.find(firstName) != std::string::npos; }) ||
                std::ranges::any_of(lastNames, [&generatedStreetAddress](const std::string& lastName)
                                    { return generatedStreetAddress.find(lastName) != std::string::npos; }) ||
                std::ranges::any_of(russiaStreetNames, [&generatedStreetAddress](const std::string_view& streetName)
                                    { return generatedStreetAddress.find(streetName) != std::string::npos; }));
}

TEST_F(LocationTest, shouldGenerateFranceStreet)
{
    const auto generatedStreet = Location::street(AddressCountry::France);

    const auto generatedStreetElements = StringHelper::split(generatedStreet, " ");

    const auto& generatedStreetPrefix = generatedStreetElements[0];
    const auto& generatedStreetSuffix =
        StringHelper::join({generatedStreetElements.begin() + 1, generatedStreetElements.end()});

    ASSERT_GE(generatedStreetElements.size(), 2);
    ASSERT_TRUE(std::ranges::any_of(franceStreetPrefixes, [&generatedStreetPrefix](const std::string_view& streetPrefix)
                                    { return streetPrefix == generatedStreetPrefix; }));
    ASSERT_TRUE(std::ranges::any_of(franceStreetSuffixes, [&generatedStreetSuffix](const std::string_view& streetSuffix)
                                    { return streetSuffix == generatedStreetSuffix; }));
}

TEST_F(LocationTest, shouldGenerateFranceStreetAddress)
{
    const auto generatedStreetAddress = Location::streetAddress(AddressCountry::France);

    const auto generatedStreetAddressElements = StringHelper::split(generatedStreetAddress, " ");

    const auto& generatedBuildingNumber = generatedStreetAddressElements[0];
    const auto& generatedStreetPrefix = generatedStreetAddressElements[1];
    const auto& generatedStreetSuffix =
        StringHelper::join({generatedStreetAddressElements.begin() + 2, generatedStreetAddressElements.end()});

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
    const auto generatedCountry = Location::country();

    ASSERT_TRUE(std::ranges::any_of(allCountries, [generatedCountry](const std::string_view& country)
                                    { return country == generatedCountry; }));
}

TEST_F(LocationTest, shouldGenerateCountryCode)
{
    const auto generatedCountryCode = Location::countryCode();

    ASSERT_TRUE(std::ranges::any_of(countryCodes, [generatedCountryCode](const std::string_view& countryCode)
                                    { return countryCode == generatedCountryCode; }));
}

TEST_F(LocationTest, shouldGenerateLatitude)
{
    const auto latitude = Location::latitude();

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
    const auto latitude = Location::latitude(Precision::ThreeDp);

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
    const auto longitude = Location::longitude();

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
    const auto longitude = Location::longitude(Precision::SixDp);

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
    const auto generatedDirection = Location::direction();

    ASSERT_TRUE(std::ranges::any_of(directions, [generatedDirection](const std::string_view& direction)
                                    { return direction == generatedDirection; }));
}

TEST_F(LocationTest, shouldGenerateTimeZone)
{
    const auto generatedTimeZone = Location::timeZone();

    ASSERT_TRUE(std::ranges::any_of(timeZones, [generatedTimeZone](const std::string_view& timeZone)
                                    { return timeZone == generatedTimeZone; }));
}

TEST_F(LocationTest, shouldGenerateUkraineStreet)
{
    const auto generatedStreet = Location::street(AddressCountry::Ukraine);

    const auto generatedStreetElements = StringHelper::split(generatedStreet, " ");

    const auto& generatedStreetPrefix = generatedStreetElements[0];
    const auto& generatedStreetSuffix =
        StringHelper::join({generatedStreetElements.begin() + 1, generatedStreetElements.end()});

    ASSERT_TRUE(std::ranges::any_of(ukraineStreetPrefixes,
                                    [&generatedStreetPrefix](const std::string_view& streetPrefix)
                                    { return streetPrefix == generatedStreetPrefix; }));

    std::vector<std::string> firstNames{ukrainianMalesFirstNames};
    firstNames.insert(firstNames.end(), ukrainianFemalesFirstNames.begin(), ukrainianFemalesFirstNames.end());

    std::vector<std::string> lastNames{ukrainianMalesLastNames};
    lastNames.insert(lastNames.end(), ukrainianFemalesLastNames.begin(), ukrainianFemalesLastNames.end());

    ASSERT_TRUE(std::ranges::any_of(firstNames, [&generatedStreetSuffix](const std::string& firstName)
                                    { return generatedStreetSuffix.find(firstName) != std::string::npos; }) ||
                std::ranges::any_of(lastNames, [&generatedStreetSuffix](const std::string& lastName)
                                    { return generatedStreetSuffix.find(lastName) != std::string::npos; }) ||
                std::ranges::any_of(ukraineStreetNames, [&generatedStreetSuffix](const std::string_view& streetName)
                                    { return generatedStreetSuffix.find(streetName) != std::string::npos; }));
}

TEST_F(LocationTest, shouldGenerateUkraineStreetAddress)
{
    const auto generatedStreetAddress = Location::streetAddress(AddressCountry::Ukraine);

    ASSERT_TRUE(std::ranges::any_of(ukraineStreetPrefixes, [&generatedStreetAddress](const std::string_view& prefix)
                                    { return generatedStreetAddress.find(prefix) != std::string::npos; }));

    std::vector<std::string> firstNames{ukrainianMalesFirstNames};
    firstNames.insert(firstNames.end(), ukrainianFemalesFirstNames.begin(), ukrainianFemalesFirstNames.end());

    std::vector<std::string> lastNames{ukrainianMalesLastNames};
    lastNames.insert(lastNames.end(), ukrainianFemalesLastNames.begin(), ukrainianFemalesLastNames.end());

    ASSERT_TRUE(std::ranges::any_of(firstNames, [&generatedStreetAddress](const std::string& firstName)
                                    { return generatedStreetAddress.find(firstName) != std::string::npos; }) ||
                std::ranges::any_of(lastNames, [&generatedStreetAddress](const std::string& lastName)
                                    { return generatedStreetAddress.find(lastName) != std::string::npos; }) ||
                std::ranges::any_of(ukraineStreetNames, [&generatedStreetAddress](const std::string_view& streetName)
                                    { return generatedStreetAddress.find(streetName) != std::string::npos; }));
}

TEST_F(LocationTest, shouldGenerateItalyStreet)
{
    const auto generatedStreet = Location::street(AddressCountry::Italy);

    const auto generatedStreetElements = StringHelper::split(generatedStreet, " ");

    const auto& generatedStreetPrefix = generatedStreetElements[0];
    const auto& generatedStreetSuffix =
        StringHelper::join({generatedStreetElements.begin() + 1, generatedStreetElements.end()});

    ASSERT_TRUE(std::ranges::any_of(italyStreetPrefixes, [&generatedStreetPrefix](const std::string_view& streetPrefix)
                                    { return streetPrefix == generatedStreetPrefix; }));

    std::vector<std::string> firstNames{italianMalesFirstNames};
    firstNames.insert(firstNames.end(), italianFemalesFirstNames.begin(), italianFemalesFirstNames.end());

    std::vector<std::string> lastNames{italianLastNames};

    ASSERT_TRUE(std::ranges::any_of(firstNames, [&generatedStreetSuffix](const std::string& firstName)
                                    { return generatedStreetSuffix.find(firstName) != std::string::npos; }) ||
                std::ranges::any_of(lastNames, [&generatedStreetSuffix](const std::string& lastName)
                                    { return generatedStreetSuffix.find(lastName) != std::string::npos; }));
}

TEST_F(LocationTest, shouldGenerateItalyStreetAddress)
{
    const auto generatedStreetAddress = Location::streetAddress(AddressCountry::Italy);

    ASSERT_TRUE(std::ranges::any_of(italyStreetPrefixes, [&generatedStreetAddress](const std::string_view& prefix)
                                    { return generatedStreetAddress.find(prefix) != std::string::npos; }));

    std::vector<std::string> firstNames{italianMalesFirstNames};
    firstNames.insert(firstNames.end(), italianFemalesFirstNames.begin(), italianFemalesFirstNames.end());

    std::vector<std::string> lastNames{italianLastNames};

    ASSERT_TRUE(std::ranges::any_of(firstNames, [&generatedStreetAddress](const std::string& firstName)
                                    { return generatedStreetAddress.find(firstName) != std::string::npos; }) ||
                std::ranges::any_of(lastNames, [&generatedStreetAddress](const std::string& lastName)
                                    { return generatedStreetAddress.find(lastName) != std::string::npos; }));
}

TEST_F(LocationTest, shouldGenerateGermanyStreet)
{
    const auto generatedStreet = Location::street(AddressCountry::Germany);

    ASSERT_TRUE(std::ranges::any_of(germanyStreetNames, [&generatedStreet](const std::string_view& streetName)
                                    { return streetName == generatedStreet; }));
}

TEST_F(LocationTest, shouldGenerateGermanyStreetAddress)
{
    const auto generatedStreetAddress = Location::streetAddress(AddressCountry::Germany);

    ASSERT_TRUE(std::ranges::any_of(germanyStreetNames, [&generatedStreetAddress](const std::string_view& streetName)
                                    { return generatedStreetAddress.find(streetName) != std::string::npos; }));
}

TEST_F(LocationTest, shouldGenerateCzechStreet)
{
    const auto generatedStreet = Location::street(AddressCountry::Czech);

    ASSERT_TRUE(std::ranges::any_of(czechStreetNames, [&generatedStreet](const std::string_view& streetName)
                                    { return streetName == generatedStreet; }));
}

TEST_F(LocationTest, shouldGenerateCzechStreetAddress)
{
    const auto generatedStreetAddress = Location::streetAddress(AddressCountry::Czech);

    ASSERT_TRUE(std::ranges::any_of(czechStreetNames, [&generatedStreetAddress](const std::string_view& streetName)
                                    { return generatedStreetAddress.find(streetName) != std::string::npos; }));
}

TEST_F(LocationTest, shouldGenerateAustraliaStreet)
{
    const auto generatedStreet = Location::street(AddressCountry::Australia);

    std::vector<std::string> firstNames{australianMalesFirstNames};
    firstNames.insert(firstNames.end(), australianFemalesFirstNames.begin(), australianFemalesFirstNames.end());

    ASSERT_TRUE((std::ranges::any_of(firstNames, [&generatedStreet](const std::string& firstName)
                                     { return generatedStreet.find(firstName) != std::string::npos; }) ||
                 std::ranges::any_of(australianLastNames, [&generatedStreet](const std::string& lastName)
                                     { return generatedStreet.find(lastName) != std::string::npos; })) &&
                std::ranges::any_of(australiaStreetSuffixes, [&generatedStreet](const std::string_view& streetSuffix)
                                    { return generatedStreet.find(streetSuffix) != std::string::npos; }));
}

TEST_F(LocationTest, shouldGenerateAustraliaStreetAddress)
{
    const auto generatedStreetAddress = Location::streetAddress(AddressCountry::Australia);

    const auto generatedStreetAddressElements = StringHelper::split(generatedStreetAddress, " ");

    const auto& generatedBuildingNumber = generatedStreetAddressElements[0];
    const auto& generatedStreetSuffix =
        StringHelper::join({generatedStreetAddressElements.begin() + 1, generatedStreetAddressElements.end()});

    std::vector<std::string> firstNames{australianMalesFirstNames};
    firstNames.insert(firstNames.end(), australianFemalesFirstNames.begin(), australianFemalesFirstNames.end());

    ASSERT_TRUE(!generatedBuildingNumber.empty() && generatedBuildingNumber.size() <= 4);
    ASSERT_TRUE(checkIfAllCharactersAreNumeric(generatedBuildingNumber));

    ASSERT_TRUE((std::ranges::any_of(firstNames, [&generatedStreetSuffix](const std::string& firstName)
                                     { return generatedStreetSuffix.find(firstName) != std::string::npos; }) ||
                 std::ranges::any_of(australianLastNames, [&generatedStreetSuffix](const std::string& lastName)
                                     { return generatedStreetSuffix.find(lastName) != std::string::npos; })) &&
                std::ranges::any_of(australiaStreetSuffixes,
                                    [&generatedStreetSuffix](const std::string_view& streetSuffix)
                                    { return generatedStreetSuffix.find(streetSuffix) != std::string::npos; }));
}

TEST_F(LocationTest, shouldGenerateIndiaStreetAddress)
{
    const auto generatedStreetAddress = Location::streetAddress(AddressCountry::India);

    const auto generatedStreetAddressElements = StringHelper::split(generatedStreetAddress, " ");

    const auto& generatedBuildingNumber = generatedStreetAddressElements[0];
    const auto& generatedStreetSuffix =
        StringHelper::join({generatedStreetAddressElements.begin() + 2, generatedStreetAddressElements.end()});

    ASSERT_GE(generatedStreetAddressElements.size(), 3);
    ASSERT_TRUE(!generatedBuildingNumber.empty());
    ASSERT_TRUE(checkIfAllCharactersAreNumeric(generatedBuildingNumber));
    ASSERT_TRUE(std::ranges::any_of(indiaStreetSuffixes, [&generatedStreetSuffix](const std::string_view& streetSuffix)
                                    { return streetSuffix == generatedStreetSuffix; }));
}

TEST_F(LocationTest, shouldGenerateDenmarkStreet)
{
    const auto generatedStreet = Location::street(AddressCountry::Denmark);

    ASSERT_TRUE(std::ranges::any_of(denmarkStreetNames, [&generatedStreet](const std::string_view& streetName)
                                    { return streetName == generatedStreet; }));
}

TEST_F(LocationTest, shouldGenerateDenmarkStreetAddress)
{
    const auto generatedStreetAddress = Location::streetAddress(AddressCountry::Denmark);

    ASSERT_TRUE(std::ranges::any_of(denmarkStreetNames, [&generatedStreetAddress](const std::string_view& streetName)
                                    { return generatedStreetAddress.find(streetName) != std::string::npos; }));
}

TEST_F(LocationTest, shouldGenerateSpainStreet)
{
    const auto generatedStreet = Location::street(AddressCountry::Spain);

    std::vector<std::string> firstNames{spanishMalesFirstNames};
    firstNames.insert(firstNames.end(), spanishFemalesFirstNames.begin(), spanishFemalesFirstNames.end());

    ASSERT_TRUE((std::ranges::any_of(firstNames, [&generatedStreet](const std::string& firstName)
                                     { return generatedStreet.find(firstName) != std::string::npos; }) ||
                 std::ranges::any_of(spanishLastNames, [&generatedStreet](const std::string& lastName)
                                     { return generatedStreet.find(lastName) != std::string::npos; })) &&
                std::ranges::any_of(spainStreetSuffixes, [&generatedStreet](const std::string_view& streetSuffix)
                                    { return generatedStreet.find(streetSuffix) != std::string::npos; }));
}

TEST_F(LocationTest, shouldGenerateSpainStreetAddress)
{
    const auto generatedStreetAddress = Location::streetAddress(AddressCountry::Spain);

    ASSERT_TRUE(std::ranges::any_of(spainStreetSuffixes, [&generatedStreetAddress](const std::string_view& suffix)
                                    { return generatedStreetAddress.find(suffix) != std::string::npos; }));

    std::vector<std::string> firstNames{spanishMalesFirstNames};
    firstNames.insert(firstNames.end(), spanishFemalesFirstNames.begin(), spanishFemalesFirstNames.end());

    ASSERT_TRUE(std::ranges::any_of(firstNames, [&generatedStreetAddress](const std::string& firstName)
                                    { return generatedStreetAddress.find(firstName) != std::string::npos; }) ||
                std::ranges::any_of(spanishLastNames, [&generatedStreetAddress](const std::string& lastName)
                                    { return generatedStreetAddress.find(lastName) != std::string::npos; }));
}

TEST_F(LocationTest, shouldGenerateFinlandStreet)
{
    const auto generatedStreet = Location::street(AddressCountry::Finland);

    const auto generatedStreetElements = StringHelper::split(generatedStreet, " ");

    const auto& generatedStreetPrefix = generatedStreetElements[0];
    const auto& generatedStreetSuffix = generatedStreetElements[1];

    std::vector<std::string> firstNames{finnishMalesFirstNames};
    firstNames.insert(firstNames.end(), finnishFemalesFirstNames.begin(), finnishFemalesFirstNames.end());

    ASSERT_GE(generatedStreetElements.size(), 2);

    ASSERT_TRUE(std::ranges::any_of(finlandStreetSuffixes,
                                    [&generatedStreetSuffix](const std::string_view& streetSuffix)
                                    { return streetSuffix == generatedStreetSuffix; }));

    ASSERT_TRUE(std::ranges::any_of(firstNames, [&generatedStreetPrefix](const std::string& firstName)
                                    { return generatedStreetPrefix.find(firstName) != std::string::npos; }) ||
                std::ranges::any_of(finnishLastNames, [&generatedStreetPrefix](const std::string& lastName)
                                    { return generatedStreetPrefix.find(lastName) != std::string::npos; }));
}

TEST_F(LocationTest, shouldGenerateFinlandStreetAddress)
{
    const auto generatedStreetAddress = Location::streetAddress(AddressCountry::Finland);

    ASSERT_TRUE(std::ranges::any_of(finlandStreetSuffixes, [&generatedStreetAddress](const std::string_view& suffix)
                                    { return generatedStreetAddress.find(suffix) != std::string::npos; }));

    std::vector<std::string> firstNames{finnishMalesFirstNames};
    firstNames.insert(firstNames.end(), finnishFemalesFirstNames.begin(), finnishFemalesFirstNames.end());

    ASSERT_TRUE(std::ranges::any_of(firstNames, [&generatedStreetAddress](const std::string& firstName)
                                    { return generatedStreetAddress.find(firstName) != std::string::npos; }) ||
                std::ranges::any_of(finnishLastNames, [&generatedStreetAddress](const std::string& lastName)
                                    { return generatedStreetAddress.find(lastName) != std::string::npos; }));
}

TEST_F(LocationTest, shouldGenerateEstoniaStreet)
{
    const auto generatedStreet = Location::street(AddressCountry::Estonia);

    ASSERT_TRUE(std::ranges::any_of(estoniaStreetNames, [&generatedStreet](const std::string_view& streetName)
                                    { return generatedStreet.find(streetName) != std::string::npos; }));
}

TEST_F(LocationTest, shouldGenerateEstoniaStreetAddress)
{
    const auto generatedStreetAddress = Location::streetAddress(AddressCountry::Estonia);

    ASSERT_TRUE(std::ranges::any_of(estoniaStreetNames, [&generatedStreetAddress](const std::string_view& streetName)
                                    { return generatedStreetAddress.find(streetName) != std::string::npos; }));
}
