#include "faker-cxx/Location.h"

#include <algorithm>

#include "gtest/gtest.h"

#include "data/Characters.h"
#include "data/FirstNamesFemales.h"
#include "data/FirstNamesMales.h"
#include "data/LastNames.h"
#include "data/location/Countries.h"
#include "data/location/States.h"
#include "data/location/usa/UsaCities.h"
#include "data/location/usa/UsaStreetSuffixes.h"
#include "StringHelper.h"

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
