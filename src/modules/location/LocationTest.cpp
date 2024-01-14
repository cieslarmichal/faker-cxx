#include "faker-cxx/Location.h"

#include <algorithm>

#include "gtest/gtest.h"

#include "../../common/StringHelper.h"
#include "../person/data/england/EnglishFirstNames.h"
#include "../person/data/england/EnglishLastNames.h"
#include "../person/data/spain/SpanishFirstNames.h"
#include "../person/data/spain/SpanishLastNames.h"
#include "../person/data/brazil/BrazilianFirstNames.h"
#include "../person/data/brazil/BrazilianLastNames.h"
#include "../person/data/russia/RussianFirstNames.h"
#include "../person/data/russia/RussianLastNames.h"
#include "../person/data/ukraine/UkrainianFirstNames.h"
#include "../person/data/ukraine/UkrainianLastNames.h"
#include "../person/data/italy/ItalianFirstNames.h"
#include "../person/data/italy/ItalianLastNames.h"
#include "../person/data/australia/AustralianFirstNames.h"
#include "../person/data/australia/AustralianLastNames.h"
#include "../person/data/finland/FinnishFirstNames.h"
#include "../person/data/finland/FinnishLastNames.h"
#include "../string/data/Characters.h"
#include "data/Countries.h"
#include "data/CountryAddresses.h"
#include "data/Directions.h"
#include "data/australia/AustraliaAddresses.h"
#include "data/czech/CzechAddresses.h"
#include "data/france/FranceAddresses.h"
#include "data/poland/PolandAddresses.h"
#include "data/russia/RussiaAddresses.h"
#include "data/TimeZones.h"
#include "data/ukraine/UkraineAddresses.h"
#include "data/italy/ItalyAddresses.h"
#include "data/germany/GermanyAddresses.h"
#include "data/usa/UsaAddresses.h"
#include "data/india/IndiaAddresses.h"
#include "data/denmark/DenmarkAddresses.h"
#include "data/spain/SpainAddresses.h"
#include "data/brazil/BrazilAddresses.h"
#include "data/finland/FinlandAddresses.h"

using namespace ::testing;
using namespace faker;

namespace
{
    const std::map<AddressCountry, CountryAddresses> countryToCountryAddressesMapping{
            {AddressCountry::Usa, usaAddresses},         {AddressCountry::Poland, polandAddresses},
            {AddressCountry::Russia, russiaAddresses},   {AddressCountry::France, franceAddresses},
            {AddressCountry::Ukraine, ukraineAddresses}, {AddressCountry::Italy, italyAddresses},
            {AddressCountry::Germany, germanyAddresses}, {AddressCountry::Czech, czechAddresses},
            {AddressCountry::Australia, australiaAddresses}, {AddressCountry::India, indiaAddresses},
            {AddressCountry::Denmark, denmarkAddresses}, {AddressCountry::Spain, spainAddresses},
            {AddressCountry::Brazil, brazilAddresses},   {AddressCountry::Finland, finlandAddresses},
    };

    const std::map<AddressCountry, std::string> generatedTestName{
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

TEST_P(LocationTest, shouldGenerateCounty)
{
    const auto country = GetParam();

    const auto& countryAddresses = countryToCountryAddressesMapping.at(country);

    const auto generatedCounty = Location::county(country);

    ASSERT_TRUE(std::ranges::any_of(countryAddresses.counties,
                                    [&generatedCounty](const std::string& county) { return county == generatedCounty; }) ||
                (countryAddresses.counties.empty() && generatedCounty.empty()));
}

TEST_P(LocationTest, shouldGenerateState)
{
    const auto country = GetParam();

    const auto& countryAddresses = countryToCountryAddressesMapping.at(country);

    const auto generatedState = Location::state(country);

    ASSERT_TRUE(std::ranges::any_of(countryAddresses.states,
                                    [&generatedState](const std::string& state) { return state == generatedState; }));
}

TEST_P(LocationTest, shouldGenerateCity)
{
    const auto country = GetParam();

    const auto& countryAddresses = countryToCountryAddressesMapping.at(country);

    const auto generatedCity = Location::city(country);

    if (country == faker::AddressCountry::Brazil)
    {
        const auto generatedCityElements = StringHelper::split(generatedCity, " ");

        const auto& generatedCityPrefix = generatedCityElements[0];

        std::vector<std::string> firstNames{brazilianMalesFirstNames};
        firstNames.insert(firstNames.end(), brazilianFemalesFirstNames.begin(), brazilianFemalesFirstNames.end());

        std::vector<std::string> lastNames{brazilianLastNames};

        ASSERT_TRUE(std::ranges::any_of(firstNames,
        [&generatedCityPrefix](const std::string& firstName) { return generatedCityPrefix.find(firstName) != std::string::npos; }) ||
                    std::ranges::any_of(lastNames, 
        [&generatedCityPrefix](const std::string& lastName) { return generatedCityPrefix.find(lastName) != std::string::npos; }) ||
                    std::ranges::any_of(brazilCitySuffixes,
        [&generatedCity](const std::string& citySuffix) { return generatedCity.find(citySuffix) != std::string::npos; }));
        
    } else 
    {
        ASSERT_TRUE(std::ranges::any_of(countryAddresses.cities,
                                [&generatedCity](const std::string& city){ return city == generatedCity; }));
    }
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

    const auto generatedBuildingNumberExceptLastCharacter = generatedBuildingNumber.substr(
            0, generatedBuildingNumber.size() - 1);

    ASSERT_TRUE(std::ranges::any_of(countryAddresses.buildingNumberFormats,
                                    [&generatedBuildingNumber](const std::string& buildingNumberFormat)
                                    { return buildingNumberFormat.size() == generatedBuildingNumber.size(); }));

    ASSERT_TRUE(checkIfAllCharactersAreNumeric(generatedBuildingNumber) ||
                checkIfAllCharactersAreNumeric(generatedBuildingNumberExceptLastCharacter) ||
                generatedBuildingNumber == spainAddresses.buildingNumberFormats[0]);
}

TEST_P(LocationTest, shouldGenerateSecondaryAddress)
{
    const auto country = GetParam();

    const auto& countryAddresses = countryToCountryAddressesMapping.at(country);

    const auto generatedSecondaryAddress = Location::secondaryAddress(country);

    ASSERT_TRUE((countryAddresses.secondaryAddressFormats.empty() && generatedSecondaryAddress.empty()) ||
        std::ranges::any_of(
            countryAddresses.secondaryAddressFormats,
            [&generatedSecondaryAddress, &country](const std::string& secondaryAddressFormat)
            {
                const auto secondaryAddressElements = StringHelper::split(secondaryAddressFormat, " ");

                const auto generatedSecondaryAddressElements = StringHelper::split(generatedSecondaryAddress, " ");

                if (country == faker::AddressCountry::Finland)
                {
                    if (generatedSecondaryAddressElements.size() == 1) 
                    {
                        return generatedSecondaryAddress == secondaryAddressFormat;
                    }
                }

                const auto& secondaryAddressPrefix = secondaryAddressElements[0];

                const auto& secondaryAddressNumber = secondaryAddressElements[1];

                const auto& generatedSecondaryAddressPrefix = generatedSecondaryAddressElements[0];

                const auto& generatedSecondaryAddressNumber = generatedSecondaryAddressElements[1];

                if (country == faker::AddressCountry::Denmark)
                {
                    const auto generatedSecondaryAddressNumberPart = generatedSecondaryAddressPrefix.substr(
                            0, generatedSecondaryAddressPrefix.size() - 1);
                    return generatedSecondaryAddressNumber == secondaryAddressNumber &&
                            generatedSecondaryAddress.size() == secondaryAddressFormat.size() &&
                            checkIfAllCharactersAreNumeric(generatedSecondaryAddressNumberPart);
                }
                else if (country == faker::AddressCountry::Germany)
                {
                    if (checkIfAllCharactersAreNumeric(generatedSecondaryAddressPrefix))
                    {
                        return generatedSecondaryAddressNumber == secondaryAddressNumber &&
                               generatedSecondaryAddress.size() == secondaryAddressFormat.size();
                    }
                }

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
    lastNames.insert(lastNames.end(), russianFemalesLastNames.begin(), russianFemalesLastNames.end());

    ASSERT_TRUE(std::ranges::any_of(russiaStreetPrefixes, [&generatedStreetAddress](const std::string& prefix)
    { return generatedStreetAddress.find(prefix) != std::string::npos; }));
    ASSERT_TRUE(std::ranges::any_of(firstNames, [&generatedStreetAddress](const std::string& firstName)
    { return generatedStreetAddress.find(firstName) != std::string::npos; }) ||
                std::ranges::any_of(lastNames, [&generatedStreetAddress](const std::string& lastName)
                { return generatedStreetAddress.find(lastName) != std::string::npos; }) ||
                std::ranges::any_of(russiaStreetNames, [&generatedStreetAddress](const std::string& streetName)
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

TEST_F(LocationTest, shouldGenerateUkraineStreet)
{
    const auto generatedStreet = Location::street(AddressCountry::Ukraine);

    const auto generatedStreetElements = StringHelper::split(generatedStreet, " ");

    const auto& generatedStreetPrefix = generatedStreetElements[0];
    const auto& generatedStreetSuffix =
            StringHelper::join({generatedStreetElements.begin() + 1, generatedStreetElements.end()});

    ASSERT_TRUE(std::ranges::any_of(ukraineStreetPrefixes, [&generatedStreetPrefix](const std::string& streetPrefix)
    { return streetPrefix == generatedStreetPrefix; }));

    std::vector<std::string> firstNames{ukrainianMalesFirstNames};
    firstNames.insert(firstNames.end(), ukrainianFemalesFirstNames.begin(), ukrainianFemalesFirstNames.end());

    std::vector<std::string> lastNames{ukrainianMalesLastNames};
    lastNames.insert(lastNames.end(), ukrainianFemalesLastNames.begin(), ukrainianFemalesLastNames.end());

    ASSERT_TRUE(std::ranges::any_of(firstNames, [&generatedStreetSuffix](const std::string& firstName)
    { return generatedStreetSuffix.find(firstName) != std::string::npos; }) ||
                std::ranges::any_of(lastNames, [&generatedStreetSuffix](const std::string& lastName)
                { return generatedStreetSuffix.find(lastName) != std::string::npos; }) ||
                std::ranges::any_of(ukraineStreetNames, [&generatedStreetSuffix](const std::string& streetName)
                { return generatedStreetSuffix.find(streetName) != std::string::npos; }));
}

TEST_F(LocationTest, shouldGenerateUkraineStreetAddress)
{
    const auto generatedStreetAddress = Location::streetAddress(AddressCountry::Ukraine);

    ASSERT_TRUE(std::ranges::any_of(ukraineStreetPrefixes, [&generatedStreetAddress](const std::string& prefix)
    { return generatedStreetAddress.find(prefix) != std::string::npos; }));

    std::vector<std::string> firstNames{ukrainianMalesFirstNames};
    firstNames.insert(firstNames.end(), ukrainianFemalesFirstNames.begin(), ukrainianFemalesFirstNames.end());

    std::vector<std::string> lastNames{ukrainianMalesLastNames};
    lastNames.insert(lastNames.end(), ukrainianFemalesLastNames.begin(), ukrainianFemalesLastNames.end());

    ASSERT_TRUE(std::ranges::any_of(firstNames, [&generatedStreetAddress](const std::string& firstName)
    { return generatedStreetAddress.find(firstName) != std::string::npos; }) ||
                std::ranges::any_of(lastNames, [&generatedStreetAddress](const std::string& lastName)
                { return generatedStreetAddress.find(lastName) != std::string::npos; }) ||
                std::ranges::any_of(ukraineStreetNames, [&generatedStreetAddress](const std::string& streetName)
                { return generatedStreetAddress.find(streetName) != std::string::npos; }));
}

TEST_F(LocationTest, shouldGenerateItalyStreet)
{
    const auto generatedStreet = Location::street(AddressCountry::Italy);

    const auto generatedStreetElements = StringHelper::split(generatedStreet, " ");

    const auto& generatedStreetPrefix = generatedStreetElements[0];
    const auto& generatedStreetSuffix =
            StringHelper::join({generatedStreetElements.begin() + 1, generatedStreetElements.end()});

    ASSERT_TRUE(std::ranges::any_of(italyStreetPrefixes, [&generatedStreetPrefix](const std::string& streetPrefix)
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

    ASSERT_TRUE(std::ranges::any_of(italyStreetPrefixes, [&generatedStreetAddress](const std::string& prefix)
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

    ASSERT_TRUE(std::ranges::any_of(germanyStreetNames, [&generatedStreet](const std::string& streetName)
    { return streetName == generatedStreet; }));
}

TEST_F(LocationTest, shouldGenerateGermanyStreetAddress)
{
    const auto generatedStreetAddress = Location::streetAddress(AddressCountry::Germany);

    std::vector<std::string> streetNames{germanyStreetNames};

    ASSERT_TRUE(std::ranges::any_of(streetNames, [&generatedStreetAddress](const std::string& streetName)
    { return generatedStreetAddress.find(streetName) != std::string::npos; }));
}

TEST_F(LocationTest, shouldGenerateCzechStreet)
{
    const auto generatedStreet = Location::street(AddressCountry::Czech);

    ASSERT_TRUE(std::ranges::any_of(czechStreetNames, [&generatedStreet](const std::string& streetName)
    { return streetName == generatedStreet; }));
}

TEST_F(LocationTest, shouldGenerateCzechStreetAddress)
{
    const auto generatedStreetAddress = Location::streetAddress(AddressCountry::Czech);

    std::vector<std::string> streetNames{czechStreetNames};

    ASSERT_TRUE(std::ranges::any_of(streetNames, [&generatedStreetAddress](const std::string& streetName)
    { return generatedStreetAddress.find(streetName) != std::string::npos; }));
}

TEST_F(LocationTest, shouldGenerateAustraliaStreet)
{   
    const auto generatedStreet = Location::street(AddressCountry::Australia);

    std::vector<std::string> firstNames{australianMalesFirstNames};
    firstNames.insert(firstNames.end(), australianFemalesFirstNames.begin(), australianFemalesFirstNames.end());

    std::vector<std::string> lastNames{australianLastNames};
    
    ASSERT_TRUE((std::ranges::any_of(firstNames, [&generatedStreet](const std::string& firstName)
    { return generatedStreet.find(firstName) != std::string::npos; }) ||
                std::ranges::any_of(lastNames, [&generatedStreet](const std::string& lastName)
    { return generatedStreet.find(lastName) != std::string::npos; })) &&
                std::ranges::any_of(australiaStreetSuffixes, [&generatedStreet](const std::string& streetSuffix)
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

    std::vector<std::string> lastNames{australianLastNames};

    ASSERT_TRUE(!generatedBuildingNumber.empty() && generatedBuildingNumber.size() <= 4);
    ASSERT_TRUE(checkIfAllCharactersAreNumeric(generatedBuildingNumber));
    
    ASSERT_TRUE((std::ranges::any_of(firstNames, [&generatedStreetSuffix](const std::string& firstName)
    { return generatedStreetSuffix.find(firstName) != std::string::npos; }) ||
                std::ranges::any_of(lastNames, [&generatedStreetSuffix](const std::string& lastName)
    { return generatedStreetSuffix.find(lastName) != std::string::npos; })) &&
                std::ranges::any_of(australiaStreetSuffixes, [&generatedStreetSuffix](const std::string& streetSuffix)
    { return generatedStreetSuffix.find(streetSuffix) != std::string::npos; }));
}

TEST_F(LocationTest, shouldGenerateIndiaStreet)
{
    const auto generatedStreet = Location::street(AddressCountry::India);

    const auto generatedStreetElements = StringHelper::split(generatedStreet, " ");

    const auto& generatedStreetSuffix =
            StringHelper::join({generatedStreetElements.begin() + 1, generatedStreetElements.end()});

    ASSERT_GE(generatedStreetElements.size(), 2);
    std::vector<std::string> streetNames{denmarkStreetNames};
    ASSERT_TRUE(std::ranges::any_of(indiaStreetSuffixes, [&generatedStreetSuffix](const std::string& streetSuffix)
    { return streetSuffix == generatedStreetSuffix; }));
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
    ASSERT_TRUE(std::ranges::any_of(indiaStreetSuffixes, [&generatedStreetSuffix](const std::string& streetSuffix)
    { return streetSuffix == generatedStreetSuffix; }));
}

TEST_F(LocationTest, shouldGenerateDenmarkStreet)
{
    const auto generatedStreet = Location::street(AddressCountry::Denmark);

    ASSERT_TRUE(std::ranges::any_of(denmarkStreetNames, [&generatedStreet](const std::string& streetName)
    { return streetName == generatedStreet; }));
}

TEST_F(LocationTest, shouldGenerateDenmarkStreetAddress)
{
    const auto generatedStreetAddress = Location::streetAddress(AddressCountry::Denmark);

    ASSERT_TRUE(std::ranges::any_of(denmarkStreetNames, [&generatedStreetAddress](const std::string& streetName)
    { return generatedStreetAddress.find(streetName) != std::string::npos; }));
}

TEST_F(LocationTest, shouldGenerateSpainStreet)
{
    const auto generatedStreet = Location::street(AddressCountry::Spain);

    std::vector<std::string> firstNames{spanishMalesFirstNames};
    firstNames.insert(firstNames.end(), spanishFemalesFirstNames.begin(), spanishFemalesFirstNames.end());

    std::vector<std::string> lastNames{spanishLastNames};
    
    ASSERT_TRUE((std::ranges::any_of(firstNames, [&generatedStreet](const std::string& firstName)
    { return generatedStreet.find(firstName) != std::string::npos; }) ||
                std::ranges::any_of(lastNames, [&generatedStreet](const std::string& lastName)
    { return generatedStreet.find(lastName) != std::string::npos; })) &&
                std::ranges::any_of(spainStreetSuffixes, [&generatedStreet](const std::string& streetSuffix)
    { return generatedStreet.find(streetSuffix) != std::string::npos; }));
}

TEST_F(LocationTest, shouldGenerateSpainStreetAddress)
{
    const auto generatedStreetAddress = Location::streetAddress(AddressCountry::Spain);

    ASSERT_TRUE(std::ranges::any_of(spainStreetSuffixes, [&generatedStreetAddress](const std::string& suffix)
    { return generatedStreetAddress.find(suffix) != std::string::npos; }));

    std::vector<std::string> firstNames{spanishMalesFirstNames};
    firstNames.insert(firstNames.end(), spanishFemalesFirstNames.begin(), spanishFemalesFirstNames.end());

    std::vector<std::string> lastNames{spanishLastNames};

    ASSERT_TRUE(std::ranges::any_of(firstNames, [&generatedStreetAddress](const std::string& firstName)
    { return generatedStreetAddress.find(firstName) != std::string::npos; }) ||
                std::ranges::any_of(lastNames, [&generatedStreetAddress](const std::string& lastName)
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

    std::vector<std::string> lastNames{finnishLastNames};

    ASSERT_GE(generatedStreetElements.size(), 2);

    ASSERT_TRUE(std::ranges::any_of(finlandStreetSuffixes, [&generatedStreetSuffix](const std::string& streetSuffix)
    { return streetSuffix == generatedStreetSuffix; }));

    ASSERT_TRUE(std::ranges::any_of(firstNames, [&generatedStreetPrefix](const std::string& firstName)
    { return generatedStreetPrefix.find(firstName) != std::string::npos; }) ||
                std::ranges::any_of(lastNames, [&generatedStreetPrefix](const std::string& lastName)
    { return generatedStreetPrefix.find(lastName) != std::string::npos; }));
}

TEST_F(LocationTest, shouldGenerateFinlandStreetAddress)
{
    const auto generatedStreetAddress = Location::streetAddress(AddressCountry::Finland);

    ASSERT_TRUE(std::ranges::any_of(finlandStreetSuffixes, [&generatedStreetAddress](const std::string& suffix)
    { return generatedStreetAddress.find(suffix) != std::string::npos; }));

    std::vector<std::string> firstNames{finnishMalesFirstNames};
    firstNames.insert(firstNames.end(), finnishFemalesFirstNames.begin(), finnishFemalesFirstNames.end());

    std::vector<std::string> lastNames{finnishLastNames};

    ASSERT_TRUE(std::ranges::any_of(firstNames, [&generatedStreetAddress](const std::string& firstName)
    { return generatedStreetAddress.find(firstName) != std::string::npos; }) ||
                std::ranges::any_of(lastNames, [&generatedStreetAddress](const std::string& lastName)
                { return generatedStreetAddress.find(lastName) != std::string::npos; }));
}