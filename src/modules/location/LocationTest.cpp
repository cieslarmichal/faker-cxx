#include "faker-cxx/Location.h"

#include <algorithm>

#include "gtest/gtest.h"

#include "../../common/StringHelper.h"
#include "../person/data/england/EnglishFirstNames.h"
#include "../person/data/england/EnglishLastNames.h"
#include "../string/data/Characters.h"
#include "data/Countries.h"
#include "data/Directions.h"
#include "data/turkiye/TurkiyeAddressFormat.h"
#include "data/turkiye/TurkiyeCities.h"
#include "data/turkiye/TurkiyeDistricts.h"
#include "data/turkiye/TurkiyeNeighbourhoods.h"
#include "data/turkiye/TurkiyeStreetNames.h"
#include "data/turkiye/TurkiyeStreetNumberPrefix.h"
#include "data/france/FranceCities.h"
#include "data/france/FranceStreetPrefixes.h"
#include "data/france/FranceStreetSuffixes.h"
#include "data/poland/PolandCities.h"
#include "data/poland/PolandStreetNames.h"
#include "data/poland/PolandStreetPrefixes.h"
#include "data/russia/RussiaCities.h"
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

    std::vector<std::string> firstNames{englishMalesFirstNames};
    firstNames.insert(firstNames.end(), englishFemalesFirstNames.begin(), englishFemalesFirstNames.end());

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

    std::vector<std::string> firstNames{englishMalesFirstNames};
    firstNames.insert(firstNames.end(), englishFemalesFirstNames.begin(), englishFemalesFirstNames.end());

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

    ASSERT_TRUE(!generatedBuildingNumber.empty() && generatedBuildingNumber.size() <= 3);
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

    ASSERT_TRUE(!generatedBuildingNumber.empty() && generatedBuildingNumber.size() <= 3);
    ASSERT_TRUE(checkIfAllCharactersAreNumeric(generatedBuildingNumber));
}

TEST_F(LocationTest, shouldGeneratePolandStreetAddress)
{
    const auto generatedStreetAddress = Location::streetAddress(Country::Poland);

    const auto generatedStreetAddressElements = StringHelper::split(generatedStreetAddress, " ");

    std::vector<std::string> street{};

    std::string generatedStreetName{};

    if (generatedStreetAddressElements.size() > 3)
    {
        for (size_t i = 1; i < generatedStreetAddressElements.size() - 1; ++i)
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

    ASSERT_TRUE(!generatedBuildingNumber.empty() && generatedBuildingNumber.size() <= 3);
    ASSERT_TRUE(checkIfAllCharactersAreNumeric(generatedBuildingNumber));
    ASSERT_TRUE(std::ranges::any_of(polandStreetPrefixes, [generatedStreetPrefix](const std::string& prefix)
                                    { return prefix == generatedStreetPrefix; }));
    ASSERT_TRUE(std::ranges::any_of(polandStreets, [generatedStreetName](const std::string& street)
                                    { return street == generatedStreetName; }));
}

TEST_F(LocationTest, shouldGenerateFranceCity)
{
    const auto generatedCity = Location::city(Country::France);

    ASSERT_TRUE(
        std::ranges::any_of(franceCities, [generatedCity](const std::string& city) { return city == generatedCity; }));
}

TEST_F(LocationTest, shouldGenerateFranceZipCode)
{
    const auto generatedZipCode = Location::zipCode(Country::France);

    ASSERT_EQ(generatedZipCode.size(), 5);
    ASSERT_TRUE(checkIfAllCharactersAreNumeric(generatedZipCode));
}

TEST_F(LocationTest, shouldGenerateFranceBuildingNumber)
{
    const auto generatedBuildingNumber = Location::buildingNumber(Country::France);

    ASSERT_TRUE(!generatedBuildingNumber.empty() && generatedBuildingNumber.size() <= 4);
    ASSERT_TRUE(checkIfAllCharactersAreNumeric(generatedBuildingNumber));
}

TEST_F(LocationTest, shouldGenerateFranceSecondaryAddress)
{
    const auto generatedSecondaryAddress = Location::secondaryAddress(Country::France);

    ASSERT_TRUE(generatedSecondaryAddress.starts_with("Apt. ") || generatedSecondaryAddress.starts_with("Étage "));

    const auto generatedSecondaryAddressParts = StringHelper::split(generatedSecondaryAddress, " ");

    const auto& generatedBuildingNumber = generatedSecondaryAddressParts[1];

    ASSERT_TRUE(generatedBuildingNumber.size() == 3 || generatedBuildingNumber.size() == 1);
    ASSERT_TRUE(checkIfAllCharactersAreNumeric(generatedBuildingNumber));
}

TEST_F(LocationTest, shouldGenerateFranceStreet)
{
    const auto generatedStreet = Location::street(Country::France);

    const auto generatedStreetElements = StringHelper::split(generatedStreet, " ");

    const auto& generatedStreetPrefix = generatedStreetElements[0];
    const auto& generatedStreetSuffix =
        StringHelper::join({generatedStreetElements.begin() + 1, generatedStreetElements.end()});

    ASSERT_GE(generatedStreetElements.size(), 2);
    ASSERT_TRUE(std::ranges::any_of(franceStreetPrefixes, [generatedStreetPrefix](const std::string& streetPrefix)
                                    { return streetPrefix == generatedStreetPrefix; }));
    ASSERT_TRUE(std::ranges::any_of(franceStreetSuffixes, [generatedStreetSuffix](const std::string& streetSuffix)
                                    { return streetSuffix == generatedStreetSuffix; }));
}

TEST_F(LocationTest, shouldGenerateFranceStreetAddress)
{
    const auto generatedStreetAddress = Location::streetAddress(Country::France);

    const auto generatedStreetAddressElements = StringHelper::split(generatedStreetAddress, " ");

    const auto& generatedBuildingNumber = generatedStreetAddressElements[0];
    const auto& generatedStreetPrefix = generatedStreetAddressElements[1];
    const auto& generatedStreetSuffix =
        StringHelper::join({generatedStreetAddressElements.begin() + 2, generatedStreetAddressElements.end()});

    ASSERT_GE(generatedStreetAddressElements.size(), 3);
    ASSERT_TRUE(!generatedBuildingNumber.empty() && generatedBuildingNumber.size() <= 4);
    ASSERT_TRUE(checkIfAllCharactersAreNumeric(generatedBuildingNumber));
    ASSERT_TRUE(std::ranges::any_of(franceStreetPrefixes, [generatedStreetPrefix](const std::string& streetPrefix)
                                    { return streetPrefix == generatedStreetPrefix; }));
    ASSERT_TRUE(std::ranges::any_of(franceStreetSuffixes, [generatedStreetSuffix](const std::string& streetSuffix)
                                    { return streetSuffix == generatedStreetSuffix; }));
}

TEST_F(LocationTest, shouldGenerateTurkiyeCity)
{
    const auto generatedCity = Location::city(Country::Turkiye);

    ASSERT_TRUE(
        std::ranges::any_of(turkeyCities, [generatedCity](const std::string& city) { return city == generatedCity; }));
}

TEST_F(LocationTest, shouldGenerateTurkiyeZipCode)
{
    const auto generatedZipCode = Location::zipCode(Country::Turkiye);

    ASSERT_EQ(generatedZipCode.size(), 6);
    ASSERT_TRUE(generatedZipCode[2] == '-');
}

TEST_F(LocationTest, shouldGenerateTurkiyeBuildingNumber)
{
    const auto generatedBuildingNumber = Location::buildingNumber(Country::Turkiye);

    ASSERT_TRUE(generatedBuildingNumber.size() >= 1 && generatedBuildingNumber.size() <= 3);
    ASSERT_TRUE(checkIfAllCharactersAreNumeric(generatedBuildingNumber));
}

TEST(FakerTest, TurkiyeStreetNumberTest)
{
    for (int i = 0; i < 1000; ++i)
    {
        std::string streetNumber = faker::turkiyeStreetNumber();
        bool isValidPrefix = false;
        for (const std::string &prefix : faker::turkiyeStreetNumberPrefix)
        {
            if (streetNumber.find(prefix) == 0)
            {
                isValidPrefix = true;
                break;
            }
        }
        EXPECT_TRUE(isValidPrefix);
        int number = std::stoi(streetNumber.substr(2));
        EXPECT_GE(number, 1);
        EXPECT_LE(number, 999);
    }
}

TEST_F(LocationTest, shouldGenerateTurkiyeStreetAddress)
{
    const auto generatedStreetAddress = Location::streetAddress(Country::Turkiye);

    const auto generatedStreetAddressElements = StringHelper::split(generatedStreetAddress, " ");

    std::vector<std::string> street{};

    std::string generatedStreetName{};

    if (generatedStreetAddressElements.size() > 3)
    {
        for (size_t i = 1; i < generatedStreetAddressElements.size() - 1; ++i)
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
    ASSERT_TRUE(std::ranges::any_of(turkiyeStreetPrefixes, [generatedStreetPrefix](const std::string& prefix)
                                    { return prefix == generatedStreetPrefix; }));
    ASSERT_TRUE(std::ranges::any_of(turkiyeStreets, [generatedStreetName](const std::string& street)
                                    { return street == generatedStreetName; }));
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
