#include "faker-cxx/Location.h"

#include <algorithm>

#include "gtest/gtest.h"

#include "../../common/StringHelper.h"
#include "../person/data/FirstNamesFemales.h"
#include "../person/data/FirstNamesMales.h"
#include "../person/data/LastNames.h"
#include "../string/data/Characters.h"
#include "data/Countries.h"
#include "data/Directions.h"
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
        return std::all_of(data.begin(), data.end(),
                           [](char dataCharacter)
                           {
                               return std::any_of(numericCharacters.begin(), numericCharacters.end(),
                                                  [dataCharacter](char numericCharacter)
                                                  { return numericCharacter == dataCharacter; });
                           });
    }
};

TEST_F(LocationTest, shouldGenerateCountry)
{
    const auto generatedCountry = Location::country();

    ASSERT_TRUE(std::any_of(countries.begin(), countries.end(),
                            [generatedCountry](const std::string& country) { return country == generatedCountry; }));
}

TEST_F(LocationTest, shouldGenerateCountryCode)
{
    const auto generatedCountryCode = Location::countryCode();

    ASSERT_TRUE(std::any_of(countryCodes.begin(), countryCodes.end(),
                            [generatedCountryCode](const std::string& countryCode)
                            { return countryCode == generatedCountryCode; }));
}

TEST_F(LocationTest, shouldGenerateState)
{
    const auto generatedState = Location::state();

    ASSERT_TRUE(std::any_of(states.begin(), states.end(),
                            [generatedState](const std::string& state) { return state == generatedState; }));
}

TEST_F(LocationTest, shouldGenerateUsaCity)
{
    const auto generatedCity = Location::city();

    ASSERT_TRUE(std::any_of(usaCities.begin(), usaCities.end(),
                            [generatedCity](const std::string& city) { return city == generatedCity; }));
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

    std::vector<std::string> firstNames{firstNamesMales};
    firstNames.insert(firstNames.end(), firstNamesFemales.begin(), firstNamesFemales.end());

    ASSERT_EQ(generatedStreetElements.size(), 2);
    ASSERT_TRUE(std::any_of(firstNames.begin(), firstNames.end(),
                            [generatedFirstOrLastName](const std::string& firstName)
                            { return firstName == generatedFirstOrLastName; }) ||
                std::any_of(lastNames.begin(), lastNames.end(),
                            [generatedFirstOrLastName](const std::string& lastName)
                            { return lastName == generatedFirstOrLastName; }));
    ASSERT_TRUE(std::any_of(usaStreetSuffixes.begin(), usaStreetSuffixes.end(),
                            [generatedStreetSuffix](const std::string& streetSuffix)
                            { return streetSuffix == generatedStreetSuffix; }));
}

TEST_F(LocationTest, shouldGenerateUsaStreetAddress)
{
    const auto generatedStreetAddress = Location::streetAddress();

    const auto generatedStreetAddressElements = StringHelper::split(generatedStreetAddress, " ");

    const auto& generatedBuildingNumber = generatedStreetAddressElements[0];
    const auto& generatedFirstOrLastName = generatedStreetAddressElements[1];
    const auto& generatedStreetSuffix = generatedStreetAddressElements[2];

    std::vector<std::string> firstNames{firstNamesMales};
    firstNames.insert(firstNames.end(), firstNamesFemales.begin(), firstNamesFemales.end());

    ASSERT_EQ(generatedStreetAddressElements.size(), 3);
    ASSERT_TRUE(generatedBuildingNumber.size() >= 3 && generatedBuildingNumber.size() <= 5);
    ASSERT_TRUE(checkIfAllCharactersAreNumeric(generatedBuildingNumber));
    ASSERT_TRUE(std::any_of(firstNames.begin(), firstNames.end(),
                            [generatedFirstOrLastName](const std::string& firstName)
                            { return firstName == generatedFirstOrLastName; }) ||
                std::any_of(lastNames.begin(), lastNames.end(),
                            [generatedFirstOrLastName](const std::string& lastName)
                            { return lastName == generatedFirstOrLastName; }));
    ASSERT_TRUE(std::any_of(usaStreetSuffixes.begin(), usaStreetSuffixes.end(),
                            [generatedStreetSuffix](const std::string& streetSuffix)
                            { return streetSuffix == generatedStreetSuffix; }));
}

TEST_F(LocationTest, shouldGenerateLatitude)
{
    const auto latitude = Location::latitude();

    const auto latitudeAsFloat = std::stof(latitude);

    const auto generatedLatitudeParts = StringHelper::split(latitude, ".");

    ASSERT_EQ(generatedLatitudeParts.size(), 2);
    ASSERT_EQ(generatedLatitudeParts[1].size(), 4);
    ASSERT_GE(latitudeAsFloat, -90);
    ASSERT_LE(latitudeAsFloat, 90);
}

TEST_F(LocationTest, shouldGenerateLatitudeWithSpecifiedPrecision)
{
    const auto latitude = Location::latitude(Precision::ThreeDp);

    const auto latitudeAsFloat = std::stof(latitude);

    const auto generatedLatitudeParts = StringHelper::split(latitude, ".");

    ASSERT_EQ(generatedLatitudeParts.size(), 2);
    ASSERT_EQ(generatedLatitudeParts[1].size(), 3);
    ASSERT_GE(latitudeAsFloat, -90);
    ASSERT_LE(latitudeAsFloat, 90);
}

TEST_F(LocationTest, shouldGenerateLongitude)
{
    const auto longitude = Location::longitude();

    const auto longitudeAsFloat = std::stof(longitude);

    const auto generatedLongitudeParts = StringHelper::split(longitude, ".");

    ASSERT_EQ(generatedLongitudeParts.size(), 2);
    ASSERT_EQ(generatedLongitudeParts[1].size(), 4);
    ASSERT_GE(longitudeAsFloat, -180);
    ASSERT_LE(longitudeAsFloat, 180);
}

TEST_F(LocationTest, shouldGenerateLongitudeWithSpecifiedPrecision)
{
    const auto longitude = Location::longitude(Precision::SixDp);

    const auto longitudeAsFloat = std::stof(longitude);

    const auto generatedLongitudeParts = StringHelper::split(longitude, ".");

    ASSERT_EQ(generatedLongitudeParts.size(), 2);
    ASSERT_EQ(generatedLongitudeParts[1].size(), 6);
    ASSERT_GE(longitudeAsFloat, -180);
    ASSERT_LE(longitudeAsFloat, 180);
}

TEST_F(LocationTest, shouldGenerateDirection)
{
    const auto generatedDirection = Location::direction();

    ASSERT_TRUE(std::any_of(directions.begin(), directions.end(),
                            [generatedDirection](const std::string& direction)
                            { return direction == generatedDirection; }));
}

TEST_F(LocationTest, shouldGenerateTimeZone)
{
    const auto generatedTimeZone = Location::timeZone();

    ASSERT_TRUE(std::any_of(timeZones.begin(), timeZones.end(),
                            [generatedTimeZone](const std::string& timeZone)
                            { return timeZone == generatedTimeZone; }));
}
