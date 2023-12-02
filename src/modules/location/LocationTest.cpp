#include "faker-cxx/Location.h"

#include <algorithm>

#include "gtest/gtest.h"

#include "../../common/StringHelper.h"
#include "../person/data/england/EnglishFirstNames.h"
#include "../person/data/england/EnglishLastNames.h"
#include "../person/data/russia/RussianFirstNames.h"
#include "../person/data/russia/RussianLastNames.h"
#include "../string/data/Characters.h"
#include "data/Countries.h"
#include "data/CountryAddresses.h"
#include "data/Directions.h"
#include "data/france/FranceAddresses.h"
#include "data/poland/PolandAddresses.h"
#include "data/russia/RussiaAddresses.h"
#include "data/States.h"
#include "data/TimeZones.h"
#include "data/ukraine/UkraineAddresses.h"
#include "data/usa/UsaAddresses.h"

using namespace ::testing;
using namespace faker;

namespace
{
const std::map<AddressCountry, CountryAddresses> countryToCountryAddressesMapping{
    {AddressCountry::Usa, usaAddresses},         {AddressCountry::Poland, polandAddresses},
    {AddressCountry::Russia, russiaAddresses},   {AddressCountry::France, franceAddresses},
    {AddressCountry::Ukraine, ukraineAddresses},
};

const std::map<AddressCountry, std::string> generatedTestName{
    {AddressCountry::Usa, "shouldGenerateAmericanAddress"},    {AddressCountry::France, "shouldGenerateFrenchAddress"},
    {AddressCountry::Poland, "shouldGeneratePolishAddress"},   {AddressCountry::Russia, "shouldGenerateRussianAddress"},
    {AddressCountry::Ukraine, "shouldGenerateUkraineAddress"},
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
                                       return std::ranges::any_of(numericCharacters,
                                                                  [dataCharacter](char numericCharacter)
                                                                  { return numericCharacter == dataCharacter; });
                                   });
    }
};

TEST_P(LocationTest, shouldGenerateCity)
{
    const auto country = GetParam();

    const auto& countryAddresses = countryToCountryAddressesMapping.at(country);

    const auto generatedCity = Location::city(country);

    ASSERT_TRUE(std::ranges::any_of(countryAddresses.cities,
                                    [&generatedCity](const std::string& city) { return city == generatedCity; }));
}

TEST_P(LocationTest, shouldGenerateZipCode)
{
    const auto country = GetParam();

    const auto& countryAddresses = countryToCountryAddressesMapping.at(country);

    const auto generatedZipCode = Location::zipCode(country);

    ASSERT_EQ(generatedZipCode.size(), countryAddresses.zipCodeFormat.size());
    ASSERT_TRUE(checkIfZipCode(generatedZipCode));
}

TEST_P(LocationTest, shouldGenerateBuildingNumber)
{
    const auto country = GetParam();

    const auto& countryAddresses = countryToCountryAddressesMapping.at(country);

    const auto generatedBuildingNumber = Location::buildingNumber(country);

    ASSERT_TRUE(std::ranges::any_of(countryAddresses.buildingNumberFormats,
                                    [&generatedBuildingNumber](const std::string& buildingNumberFormat)
                                    { return buildingNumberFormat.size() == generatedBuildingNumber.size(); }));
    ASSERT_TRUE(checkIfAllCharactersAreNumeric(generatedBuildingNumber));
}

TEST_P(LocationTest, shouldGenerateSecondaryAddress)
{
    const auto country = GetParam();

    const auto& countryAddresses = countryToCountryAddressesMapping.at(country);

    const auto generatedSecondaryAddress = Location::secondaryAddress(country);

    ASSERT_TRUE(std::ranges::any_of(
        countryAddresses.secondaryAddressFormats,
        [&generatedSecondaryAddress](const std::string& secondaryAddressFormat)
        {
            const auto secondaryAddressElements = StringHelper::split(secondaryAddressFormat, " ");

            const auto& secondaryAddressPrefix = secondaryAddressElements[0];

            const auto generatedSecondaryAddressElements = StringHelper::split(generatedSecondaryAddress, " ");

            const auto& generatedSecondaryAddressPrefix = generatedSecondaryAddressElements[0];

            const auto& generatedSecondaryAddressNumber = generatedSecondaryAddressElements[1];

            return generatedSecondaryAddressPrefix == secondaryAddressPrefix &&
                   checkIfAllCharactersAreNumeric(generatedSecondaryAddressNumber) &&
                   generatedSecondaryAddress.size() == secondaryAddressFormat.size();
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
    ASSERT_TRUE(std::ranges::any_of(usaStreetSuffixes, [&generatedStreetSuffix](const std::string& streetSuffix)
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
    ASSERT_TRUE(std::ranges::any_of(usaStreetSuffixes, [&generatedStreetSuffix](const std::string& streetSuffix)
                                    { return streetSuffix == generatedStreetSuffix; }));
}

TEST_F(LocationTest, shouldGeneratePolandStreet)
{
    const auto generatedStreet = Location::street(AddressCountry::Poland);

    const auto generatedStreetElements = StringHelper::split(generatedStreet, " ");

    const auto& generatedStreetPrefix = generatedStreetElements[0];
    const auto& generatedStreetName =
        StringHelper::join({generatedStreetElements.begin() + 1, generatedStreetElements.end()});

    ASSERT_TRUE(std::ranges::any_of(polandStreetPrefixes, [&generatedStreetPrefix](const std::string& streetPrefix)
                                    { return streetPrefix == generatedStreetPrefix; }));
    ASSERT_TRUE(std::ranges::any_of(polandStreetNames, [&generatedStreetName](const std::string& streetName)
                                    { return streetName == generatedStreetName; }));
}

TEST_F(LocationTest, shouldGeneratePolandStreetAddress)
{
    const auto generatedStreetAddress = Location::streetAddress(AddressCountry::Poland);

    ASSERT_TRUE(std::ranges::any_of(polandStreetPrefixes, [&generatedStreetAddress](const std::string& prefix)
                                    { return generatedStreetAddress.find(prefix) != std::string::npos; }));
    ASSERT_TRUE(std::ranges::any_of(polandStreetNames, [&generatedStreetAddress](const std::string& street)
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

    ASSERT_TRUE(std::ranges::any_of(russiaStreetPrefixes, [&generatedStreetPrefix](const std::string& streetPrefix)
                                    { return streetPrefix == generatedStreetPrefix; }));
    ASSERT_TRUE(std::ranges::any_of(firstNames, [&generatedStreetSuffix](const std::string& firstName)
                                    { return firstName == generatedStreetSuffix; }) ||
                std::ranges::any_of(lastNames, [&generatedStreetSuffix](const std::string& lastName)
                                    { return lastName == generatedStreetSuffix; }) ||
                std::ranges::any_of(russiaStreetNames, [&generatedStreetSuffix](const std::string& streetName)
                                    { return streetName == generatedStreetSuffix; }));
}

TEST_F(LocationTest, shouldGenerateRussiaStreetAddress)
{
    const auto generatedStreetAddress = Location::streetAddress(AddressCountry::Russia);

    std::vector<std::string> firstNames{russianMalesFirstNames};
    firstNames.insert(firstNames.end(), russianFemalesFirstNames.begin(), russianFemalesFirstNames.end());

    std::vector<std::string> lastNames{russianMalesLastNames};
    firstNames.insert(firstNames.end(), russianFemalesLastNames.begin(), russianFemalesLastNames.end());

    ASSERT_TRUE(std::ranges::any_of(russiaStreetPrefixes, [&generatedStreetAddress](const std::string& prefix)
                                    { return generatedStreetAddress.find(prefix) != std::string::npos; }));
    ASSERT_TRUE(std::ranges::any_of(firstNames, [&generatedStreetAddress](const std::string& firstName)
                                    { return generatedStreetAddress.find(firstName) != std::string::npos; }) ||
                std::ranges::any_of(lastNames, [&generatedStreetAddress](const std::string& lastName)
                                    { return generatedStreetAddress.find(lastName) != std::string::npos; }) ||
                std::ranges::any_of(russiaStreetNames,
                                    [&generatedStreetAddress](const std::string& streetName)
                                    {
                                        return generatedStreetAddress.find(streetName) != std::string::npos;
                                        ;
                                    }));
}

TEST_F(LocationTest, shouldGenerateUkraineStreet)
{
    const auto generatedStreet = Location::street(AddressCountry::Ukraine);

    const auto generatedStreetElements = StringHelper::split(generatedStreet, " ");

    const auto& generatedStreetPrefix = generatedStreetElements[0];
    const auto& generatedStreetSuffix =
        StringHelper::join({generatedStreetElements.begin() + 1, generatedStreetElements.end()});

    ASSERT_TRUE(std::ranges::any_of(ukraineStreetPrefixes, [&generatedStreetPrefix](const std::string& streetPrefix)
                                    { return streetPrefix == generatedStreetPrefix; }));
}

TEST_F(LocationTest, shouldGenerateUkraineStreetAddress)
{
    const auto generatedStreetAddress = Location::streetAddress(AddressCountry::Ukraine);

    ASSERT_TRUE(std::ranges::any_of(ukraineStreetPrefixes, [&generatedStreetAddress](const std::string& prefix)
                                    { return generatedStreetAddress.find(prefix) != std::string::npos; }));
    ASSERT_TRUE(std::ranges::any_of(firstNames, [&generatedStreetAddress](const std::string& firstName)
                                    { return generatedStreetAddress.find(firstName) != std::string::npos; }) ||
                std::ranges::any_of(lastNames, [&generatedStreetAddress](const std::string& lastName)
                                    { return generatedStreetAddress.find(lastName) != std::string::npos; }) ||
                std::ranges::any_of(ukraineStreetNames,
                                    [&generatedStreetAddress](const std::string& streetName)
                                    {
                                        return generatedStreetAddress.find(streetName) != std::string::npos;
                                        ;
                                    }));
}

TEST_F(LocationTest, shouldGenerateFranceStreet)
{
    const auto generatedStreet = Location::street(AddressCountry::France);

    const auto generatedStreetElements = StringHelper::split(generatedStreet, " ");

    const auto& generatedStreetPrefix = generatedStreetElements[0];
    const auto& generatedStreetSuffix =
        StringHelper::join({generatedStreetElements.begin() + 1, generatedStreetElements.end()});

    ASSERT_GE(generatedStreetElements.size(), 2);
    ASSERT_TRUE(std::ranges::any_of(franceStreetPrefixes, [&generatedStreetPrefix](const std::string& streetPrefix)
                                    { return streetPrefix == generatedStreetPrefix; }));
    ASSERT_TRUE(std::ranges::any_of(franceStreetSuffixes, [&generatedStreetSuffix](const std::string& streetSuffix)
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
    ASSERT_TRUE(std::ranges::any_of(franceStreetPrefixes, [&generatedStreetPrefix](const std::string& streetPrefix)
                                    { return streetPrefix == generatedStreetPrefix; }));
    ASSERT_TRUE(std::ranges::any_of(franceStreetSuffixes, [&generatedStreetSuffix](const std::string& streetSuffix)
                                    { return streetSuffix == generatedStreetSuffix; }));
}

TEST_F(LocationTest, shouldGenerateCountry)
{
    const auto generatedCountry = Location::country();

    ASSERT_TRUE(std::ranges::any_of(allCountries, [generatedCountry](const std::string& country)
                                    { return country == generatedCountry; }));
}

TEST_F(LocationTest, shouldGenerateCountryCode)
{
    const auto generatedCountryCode = Location::countryCode();

    ASSERT_TRUE(std::ranges::any_of(countryCodes, [generatedCountryCode](const std::string& countryCode)
                                    { return countryCode == generatedCountryCode; }));
}

TEST_F(LocationTest, shouldGenerateState)
{
    const auto generatedState = Location::state();

    ASSERT_TRUE(
        std::ranges::any_of(states, [generatedState](const std::string& state) { return state == generatedState; }));
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

    ASSERT_TRUE(std::ranges::any_of(directions, [generatedDirection](const std::string& direction)
                                    { return direction == generatedDirection; }));
}

TEST_F(LocationTest, shouldGenerateTimeZone)
{
    const auto generatedTimeZone = Location::timeZone();

    ASSERT_TRUE(std::ranges::any_of(timeZones, [generatedTimeZone](const std::string& timeZone)
                                    { return timeZone == generatedTimeZone; }));
}
