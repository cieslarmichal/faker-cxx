#include "faker-cxx/Location.h"

#include <algorithm>
#include <charconv>

#include "gtest/gtest.h"

#include "../../common/StringHelper.h"
#include "../person/data/english/EnglishFirstNamesFemales.h"
#include "../person/data/english/EnglishFirstNamesMales.h"
#include "../person/data/english/EnglishLastNames.h"
#include "../string/data/Characters.h"
#include "data/Countries.h"
#include "data/Directions.h"
#include "data/russia/RussiaCities.h"
#include "data/russia/RussiaStreetPrefixes.h"
#include "data/poland/PolandCities.h"
#include "data/poland/PolandStreetNames.h"
#include "data/poland/PolandStreetPrefixes.h"
#include "data/States.h"
#include "data/TimeZones.h"
#include "data/usa/UsaCities.h"
#include "data/usa/UsaStreetSuffixes.h"

using namespace ::testing;
using namespace faker;

class LocationTest : public Test
{
public:
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

TEST_F(LocationTest, shouldGenerateCountry)
{
    const auto generatedCountry = Location::country();

    ASSERT_TRUE(std::ranges::any_of(countries, [generatedCountry](const std::string& country)
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

TEST_F(LocationTest, shouldGenerateUsaCity)
{
    const auto generatedCity = Location::city();

    ASSERT_TRUE(
        std::ranges::any_of(usaCities, [generatedCity](const std::string& city) { return city == generatedCity; }));
}

TEST_F(LocationTest, shouldGenerateUsaZipCode)
{
    const auto generatedZipCode = Location::zipCode();

    ASSERT_EQ(generatedZipCode.size(), 5);
    ASSERT_TRUE(checkIfAllCharactersAreNumeric(generatedZipCode));
}

TEST_F(LocationTest, shouldGenerateUsaBuildingNumber)
{
    const auto generatedBuildingNumber = Location::buildingNumber();

    ASSERT_TRUE(generatedBuildingNumber.size() >= 3 && generatedBuildingNumber.size() <= 5);
    ASSERT_TRUE(checkIfAllCharactersAreNumeric(generatedBuildingNumber));
}

TEST_F(LocationTest, shouldGenerateUsaSecondaryAddress)
{
    const auto generatedSecondaryAddress = Location::secondaryAddress();

    ASSERT_TRUE(generatedSecondaryAddress.starts_with("Apt.") || generatedSecondaryAddress.starts_with("Suite"));

    const auto generatedSecondaryAddressParts = StringHelper::split(generatedSecondaryAddress, " ");

    const auto& generatedBuildingNumber = generatedSecondaryAddressParts[1];

    ASSERT_EQ(generatedBuildingNumber.size(), 3);
    ASSERT_TRUE(checkIfAllCharactersAreNumeric(generatedBuildingNumber));
}

TEST_F(LocationTest, shouldGenerateUsaStreet)
{
    const auto generatedStreet = Location::street();

    const auto generatedStreetElements = StringHelper::split(generatedStreet, " ");

    const auto& generatedFirstOrLastName = generatedStreetElements[0];
    const auto& generatedStreetSuffix = generatedStreetElements[1];

    std::vector<std::string> firstNames{englishFirstNamesMales};
    firstNames.insert(firstNames.end(), englishFirstNamesFemales.begin(), englishFirstNamesFemales.end());

    ASSERT_EQ(generatedStreetElements.size(), 2);
    ASSERT_TRUE(std::ranges::any_of(firstNames, [generatedFirstOrLastName](const std::string& firstName)
                                    { return firstName == generatedFirstOrLastName; }) ||
                std::ranges::any_of(englishLastNames, [generatedFirstOrLastName](const std::string& lastName)
                                    { return lastName == generatedFirstOrLastName; }));
    ASSERT_TRUE(std::ranges::any_of(usaStreetSuffixes, [generatedStreetSuffix](const std::string& streetSuffix)
                                    { return streetSuffix == generatedStreetSuffix; }));
}

TEST_F(LocationTest, shouldGenerateUsaStreetAddress)
{
    const auto generatedStreetAddress = Location::streetAddress();

    const auto generatedStreetAddressElements = StringHelper::split(generatedStreetAddress, " ");

    const auto& generatedBuildingNumber = generatedStreetAddressElements[0];
    const auto& generatedFirstOrLastName = generatedStreetAddressElements[1];
    const auto& generatedStreetSuffix = generatedStreetAddressElements[2];

    std::vector<std::string> firstNames{englishFirstNamesMales};
    firstNames.insert(firstNames.end(), englishFirstNamesFemales.begin(), englishFirstNamesFemales.end());

    ASSERT_EQ(generatedStreetAddressElements.size(), 3);
    ASSERT_TRUE(generatedBuildingNumber.size() >= 3 && generatedBuildingNumber.size() <= 5);
    ASSERT_TRUE(checkIfAllCharactersAreNumeric(generatedBuildingNumber));
    ASSERT_TRUE(std::ranges::any_of(firstNames, [generatedFirstOrLastName](const std::string& firstName)
                                    { return firstName == generatedFirstOrLastName; }) ||
                std::ranges::any_of(englishLastNames, [generatedFirstOrLastName](const std::string& lastName)
                                    { return lastName == generatedFirstOrLastName; }));
    ASSERT_TRUE(std::ranges::any_of(usaStreetSuffixes, [generatedStreetSuffix](const std::string& streetSuffix)
                                    { return streetSuffix == generatedStreetSuffix; }));
}

TEST_F(LocationTest, shouldGenerateRussiaCity)
{
    const auto generatedCity = Location::city(Country::Russia);

    ASSERT_TRUE(
        std::ranges::any_of(russiaCities, [generatedCity](const std::string& city) { return city == generatedCity; }));
}

TEST_F(LocationTest, shouldGenerateRussiaZipCode)
{
    const auto generatedZipCode = Location::zipCode(Country::Russia);

    ASSERT_EQ(generatedZipCode.size(), 6);
    ASSERT_TRUE(checkIfAllCharactersAreNumeric(generatedZipCode));
}

TEST_F(LocationTest, shouldGenerateRussiaBuildingNumber)
{
    const auto generatedBuildingNumber = Location::buildingNumber(Country::Russia);

    ASSERT_TRUE(generatedBuildingNumber.size() >= 1 && generatedBuildingNumber.size() <= 3);
    ASSERT_TRUE(checkIfAllCharactersAreNumeric(generatedBuildingNumber));
}

TEST_F(LocationTest, shouldGeneratePolandCity)
{
    const auto generatedCity = Location::city(Country::Poland);

    ASSERT_TRUE(
        std::ranges::any_of(polandCities, [generatedCity](const std::string& city) { return city == generatedCity; }));
}

TEST_F(LocationTest, shouldGeneratePolandZipCode)
{
    const auto generatedZipCode = Location::zipCode(Country::Poland);

    ASSERT_EQ(generatedZipCode.size(), 6);
    ASSERT_TRUE(generatedZipCode[2] == '-');
}

TEST_F(LocationTest, shouldGeneratePolandBuildingNumber)
{
    const auto generatedBuildingNumber = Location::buildingNumber(Country::Poland);

    ASSERT_TRUE(generatedBuildingNumber.size() >= 1 && generatedBuildingNumber.size() <= 3);
    ASSERT_TRUE(checkIfAllCharactersAreNumeric(generatedBuildingNumber));
}

TEST_F(LocationTest, shouldGeneratePolandStreetAddress)
{
    const auto generatedStreetAddress = Location::streetAddress(Country::Poland);

    const auto generatedStreetAddressElements = StringHelper::split(generatedStreetAddress, " ");

    std::vector<std::string> street{};

    std::string generatedStreetName{};

    if(generatedStreetAddressElements.size() > 3)
    {
        for(size_t i = 1; i < generatedStreetAddressElements.size() -1; ++i )
        {
            street.push_back(generatedStreetAddressElements.at(i));
        }
        generatedStreetName = StringHelper::join(street);
    }
    else
    {
        generatedStreetName = generatedStreetAddressElements[1];
    }

    const auto& generatedBuildingNumber = generatedStreetAddressElements.back();
    const auto& generatedStreetPrefix = generatedStreetAddressElements.front();

    ASSERT_TRUE(generatedBuildingNumber.size() >= 1 && generatedBuildingNumber.size() <= 3);
    ASSERT_TRUE(checkIfAllCharactersAreNumeric(generatedBuildingNumber));
    ASSERT_TRUE(std::ranges::any_of(polandStreetPrefixes, [generatedStreetPrefix](const std::string& prefix)
                                    { return prefix == generatedStreetPrefix; }));
    ASSERT_TRUE(std::ranges::any_of(polandStreets, [generatedStreetName](const std::string& street)
                                    { return street == generatedStreetName; }));
}

TEST_F(LocationTest, shouldGenerateLatitude)
{
    const auto latitude = Location::latitude();

    auto latitudeAsFloat{0.0f};
    std::from_chars(latitude.data(), latitude.data() + latitude.size(), latitudeAsFloat);

    const auto generatedLatitudeParts = StringHelper::split(latitude, ".");

    ASSERT_EQ(generatedLatitudeParts.size(), 2);
    ASSERT_EQ(generatedLatitudeParts[1].size(), 4);
    ASSERT_GE(latitudeAsFloat, -90);
    ASSERT_LE(latitudeAsFloat, 90);
}

TEST_F(LocationTest, shouldGenerateLatitudeWithSpecifiedPrecision)
{
    const auto latitude = Location::latitude(Precision::ThreeDp);

    auto latitudeAsFloat{0.0f};
    std::from_chars(latitude.data(), latitude.data() + latitude.size(), latitudeAsFloat);

    const auto generatedLatitudeParts = StringHelper::split(latitude, ".");

    ASSERT_EQ(generatedLatitudeParts.size(), 2);
    ASSERT_EQ(generatedLatitudeParts[1].size(), 3);
    ASSERT_GE(latitudeAsFloat, -90);
    ASSERT_LE(latitudeAsFloat, 90);
}

TEST_F(LocationTest, shouldGenerateLongitude)
{
    const auto longitude = Location::longitude();

    auto longitudeAsFloat{0.0f};
    std::from_chars(longitude.data(), longitude.data() + longitude.size(), longitudeAsFloat);

    const auto generatedLongitudeParts = StringHelper::split(longitude, ".");

    ASSERT_EQ(generatedLongitudeParts.size(), 2);
    ASSERT_EQ(generatedLongitudeParts[1].size(), 4);
    ASSERT_GE(longitudeAsFloat, -180);
    ASSERT_LE(longitudeAsFloat, 180);
}

TEST_F(LocationTest, shouldGenerateLongitudeWithSpecifiedPrecision)
{
    const auto longitude = Location::longitude(Precision::SixDp);

    auto longitudeAsFloat{0.0f};
    std::from_chars(longitude.data(), longitude.data() + longitude.size(), longitudeAsFloat);

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
