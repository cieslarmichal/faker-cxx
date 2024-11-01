#include <algorithm>
#include <cmath>
#include <string>
#include <string_view>
#include <vector>

#include "gtest/gtest.h"

#include "common/string_helper.h"
#include "faker-cxx/location.h"
#include "faker-cxx/types/precision.h"
#include "location_data.h"
#include "person_data.h"
#include "string_data.h"

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

using namespace ::testing;
using namespace faker;
using namespace faker::location;

namespace
{
CountryAddressesInfo getAddresses(const Locale& locale)
{
    switch (locale)
    {
    case Locale::en_US:
    case Locale::es_US:
        return usaAddresses;
    case Locale::pl_PL:
        return polandAddresses;
    case Locale::ru_RU:
        return russiaAddresses;
    case Locale::fr_FR:
        return franceAddresses;
    case Locale::uk_UA:
        return ukraineAddresses;
    case Locale::it_IT:
        return italyAddresses;
    case Locale::de_DE:
        return germanyAddresses;
    case Locale::cs_CZ:
        return czechAddresses;
    case Locale::en_AU:
        return australiaAddresses;
    case Locale::as_IN:
    case Locale::bn_IN:
    case Locale::en_IN:
    case Locale::gu_IN:
    case Locale::hi_IN:
    case Locale::kn_IN:
    case Locale::ks_IN:
    case Locale::ml_IN:
    case Locale::mr_IN:
    case Locale::or_IN:
    case Locale::pa_IN:
    case Locale::sa_IN:
    case Locale::ta_IN:
    case Locale::te_IN:
        return indiaAddresses;
    case Locale::da_DK:
        return denmarkAddresses;
    case Locale::ca_ES:
    case Locale::es_ES:
        return spainAddresses;
    case Locale::pt_BR:
        return brazilAddresses;
    case Locale::fi_FI:
        return finlandAddresses;
    case Locale::et_EE:
        return estoniaAddresses;
    case Locale::en_GB:
        return unitedkingdomAddresses;
    case Locale::sk_SK:
        return slovakiaAddresses;
    case Locale::pt_PT:
        return portugalAddresses;
    case Locale::he_IL:
        return israelAddresses;
    default:
        return usaAddresses;
    }
}
}

class LocationTest : public TestWithParam<Locale>
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

    static bool checkIfPostCode(const std::string& postCode)
    {
        const std::string postCodeCharacters = "0123456789-ABCDEFGHIJKLMNOPQRSTUVWXYZ ";

        return std::ranges::all_of(postCode,
                                   [&postCodeCharacters](char dataCharacter)
                                   {
                                       return std::ranges::any_of(postCodeCharacters,
                                                                  [dataCharacter](char alphaNumericCharacter)
                                                                  { return alphaNumericCharacter == dataCharacter; });
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

    static constexpr double EARTH_RADIUS_KM = 6371.0;

    static double haversine(double lat1, double lon1, double lat2, double lon2)
    {
        auto toRadians = [](double degree) -> double { return degree * M_PI / 180.0; };

        const double dLat = toRadians(lat2 - lat1);
        const double dLon = toRadians(lon2 - lon1);

        lat1 = toRadians(lat1);
        lat2 = toRadians(lat2);

        const double a =
            std::pow(std::sin(dLat / 2), 2) + std::pow(std::sin(dLon / 2), 2) * std::cos(lat1) * std::cos(lat2);
        return 2 * EARTH_RADIUS_KM * std::atan2(std::sqrt(a), std::sqrt(1 - a));
    }
};

TEST_P(LocationTest, shouldGenerateState)
{
    const auto country = GetParam();

    const auto& countryAddresses = getAddresses(country);

    const auto generatedState = state(country);

    ASSERT_TRUE(std::ranges::any_of(countryAddresses.states, [&generatedState](const std::string_view& state)
                                    { return state == generatedState; }) ||
                generatedState.empty());
}

TEST_P(LocationTest, shouldGenerateCity)
{
    const auto country = GetParam();

    const auto& countryAddresses = getAddresses(country);

    const auto generatedCity = city(country);

    if (country == Locale::pt_BR)
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

    if (postCodeSet.count(country) == 1)
    {

        ASSERT_TRUE(checkIfPostCode(generatedZipCode));
    }
    else
    {

        ASSERT_TRUE(checkIfZipCode(generatedZipCode));
    }
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

INSTANTIATE_TEST_SUITE_P(TestLocationByCountries, LocationTest, ValuesIn(locales),
                         [](const TestParamInfo<Locale>& paramInfo) { return toString(paramInfo.param); });

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
    const auto generatedStreet = street(Locale::pl_PL);

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
    const auto generatedStreetAddress = streetAddress(Locale::pl_PL);

    ASSERT_TRUE(std::ranges::any_of(polandStreetPrefixes, [&generatedStreetAddress](const std::string_view& prefix)
                                    { return generatedStreetAddress.find(prefix) != std::string::npos; }));
    ASSERT_TRUE(std::ranges::any_of(polandStreetNames, [&generatedStreetAddress](const std::string_view& street)
                                    { return generatedStreetAddress.find(street) != std::string::npos; }));
}

TEST_F(LocationTest, shouldGenerateRussiaStreet)
{
    const auto generatedStreet = street(Locale::ru_RU);

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
    const auto generatedStreetAddress = streetAddress(Locale::ru_RU);

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
    const auto generatedStreet = street(Locale::fr_FR);

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
    const auto generatedStreetAddress = streetAddress(Locale::fr_FR);

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

TEST_F(LocationTest, shouldGenerateNearbyGPSCoordinateWithoutOrigin)
{
    const auto generatedNearbyGPSCoordinate = nearbyGPSCoordinate();

    auto offset = std::get<0>(generatedNearbyGPSCoordinate).size();
    const auto latitudeAsFloat = std::stof(std::get<0>(generatedNearbyGPSCoordinate), &offset);

    offset = std::get<1>(generatedNearbyGPSCoordinate).size();
    const auto longitudeAsFloat = std::stof(std::get<1>(generatedNearbyGPSCoordinate), &offset);

    const auto generatedLatitudeParts = common::split(std::get<0>(generatedNearbyGPSCoordinate), ".");
    const auto generatedLongitudeParts = common::split(std::get<1>(generatedNearbyGPSCoordinate), ".");

    ASSERT_EQ(generatedLatitudeParts.size(), 2);
    ASSERT_EQ(generatedLatitudeParts[1].size(), 4);
    ASSERT_GE(latitudeAsFloat, -90);
    ASSERT_LE(latitudeAsFloat, 90);

    ASSERT_EQ(generatedLongitudeParts.size(), 2);
    ASSERT_EQ(generatedLongitudeParts[1].size(), 4);
    ASSERT_GE(longitudeAsFloat, -180);
    ASSERT_LE(longitudeAsFloat, 180);
}

TEST_F(LocationTest, shouldGenerateNearbyGPSCoordinateWithOriginInKilometers)
{
    constexpr std::tuple origin{0, 0};
    const auto generatedNearbyGPSCoordinate = nearbyGPSCoordinate(Precision::ThreeDp, origin, 10, true);

    auto offset = std::get<0>(generatedNearbyGPSCoordinate).size();
    const auto latitudeAsFloat = std::stod(std::get<0>(generatedNearbyGPSCoordinate), &offset);

    offset = std::get<1>(generatedNearbyGPSCoordinate).size();
    const auto longitudeAsFloat = std::stod(std::get<1>(generatedNearbyGPSCoordinate), &offset);

    const auto generatedLatitudeParts = common::split(std::get<0>(generatedNearbyGPSCoordinate), ".");
    const auto generatedLongitudeParts = common::split(std::get<1>(generatedNearbyGPSCoordinate), ".");

    ASSERT_EQ(generatedLatitudeParts.size(), 2);
    ASSERT_EQ(generatedLatitudeParts[1].size(), 3);
    ASSERT_EQ(generatedLongitudeParts.size(), 2);
    ASSERT_EQ(generatedLongitudeParts[1].size(), 3);

    const auto distance = haversine(std::get<0>(origin), std::get<1>(origin), latitudeAsFloat, longitudeAsFloat);

    ASSERT_LE(distance, 10.0);
}

TEST_F(LocationTest, shouldGenerateNearbyGPSCoordinateWithOriginInMiles)
{
    constexpr std::tuple origin{0, 0};
    const auto generatedNearbyGPSCoordinate = nearbyGPSCoordinate(Precision::ThreeDp, origin, 10, false);

    auto offset = std::get<0>(generatedNearbyGPSCoordinate).size();
    const auto latitudeAsFloat = std::stod(std::get<0>(generatedNearbyGPSCoordinate), &offset);

    offset = std::get<1>(generatedNearbyGPSCoordinate).size();
    const auto longitudeAsFloat = std::stod(std::get<1>(generatedNearbyGPSCoordinate), &offset);

    const auto generatedLatitudeParts = common::split(std::get<0>(generatedNearbyGPSCoordinate), ".");
    const auto generatedLongitudeParts = common::split(std::get<1>(generatedNearbyGPSCoordinate), ".");

    ASSERT_EQ(generatedLatitudeParts.size(), 2);
    ASSERT_EQ(generatedLatitudeParts[1].size(), 3);
    ASSERT_EQ(generatedLongitudeParts.size(), 2);
    ASSERT_EQ(generatedLongitudeParts[1].size(), 3);

    const auto distanceKm = haversine(std::get<0>(origin), std::get<1>(origin), latitudeAsFloat, longitudeAsFloat);
    const auto distanceMiles = distanceKm * 0.621371;

    ASSERT_LE(distanceMiles, 10.0);
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
    const auto generatedStreet = street(Locale::uk_UA);

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
    const auto generatedStreetAddress = streetAddress(Locale::uk_UA);

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
    const auto generatedStreet = street(Locale::it_IT);

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
    const auto generatedStreetAddress = streetAddress(Locale::it_IT);

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
    const auto generatedStreet = street(Locale::de_DE);

    ASSERT_TRUE(std::ranges::any_of(germanyStreetNames, [&generatedStreet](const std::string_view& streetName)
                                    { return streetName == generatedStreet; }));
}

TEST_F(LocationTest, shouldGenerateGermanyStreetAddress)
{
    const auto generatedStreetAddress = streetAddress(Locale::de_DE);

    ASSERT_TRUE(std::ranges::any_of(germanyStreetNames, [&generatedStreetAddress](const std::string_view& streetName)
                                    { return generatedStreetAddress.find(streetName) != std::string::npos; }));
}

TEST_F(LocationTest, shouldGenerateCzechStreet)
{
    const auto generatedStreet = street(Locale::cs_CZ);

    ASSERT_TRUE(std::ranges::any_of(czechStreetNames, [&generatedStreet](const std::string_view& streetName)
                                    { return streetName == generatedStreet; }));
}

TEST_F(LocationTest, shouldGenerateCzechStreetAddress)
{
    const auto generatedStreetAddress = streetAddress(Locale::cs_CZ);

    ASSERT_TRUE(std::ranges::any_of(czechStreetNames, [&generatedStreetAddress](const std::string_view& streetName)
                                    { return generatedStreetAddress.find(streetName) != std::string::npos; }));
}

TEST_F(LocationTest, shouldGenerateAustraliaStreet)
{
    const auto generatedStreet = street(Locale::en_AU);

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
    const auto generatedStreetAddress = streetAddress(Locale::en_AU);

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
    const auto generatedStreetAddress = streetAddress(Locale::hi_IN);

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
    const auto generatedStreet = street(Locale::da_DK);

    ASSERT_TRUE(std::ranges::any_of(denmarkStreetNames, [&generatedStreet](const std::string_view& streetName)
                                    { return streetName == generatedStreet; }));
}

TEST_F(LocationTest, shouldGenerateDenmarkStreetAddress)
{
    const auto generatedStreetAddress = streetAddress(Locale::da_DK);

    ASSERT_TRUE(std::ranges::any_of(denmarkStreetNames, [&generatedStreetAddress](const std::string_view& streetName)
                                    { return generatedStreetAddress.find(streetName) != std::string::npos; }));
}

TEST_F(LocationTest, shouldGenerateSpainStreet)
{
    const auto generatedStreet = street(Locale::es_ES);

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
    const auto generatedStreetAddress = streetAddress(Locale::es_ES);

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
    const auto generatedStreet = street(Locale::fi_FI);

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
    const auto generatedStreetAddress = streetAddress(Locale::fi_FI);

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
    const auto generatedStreet = street(Locale::et_EE);

    ASSERT_TRUE(std::ranges::any_of(estoniaStreetNames, [&generatedStreet](const std::string_view& streetName)
                                    { return generatedStreet.find(streetName) != std::string::npos; }));
}

TEST_F(LocationTest, shouldGenerateEstoniaStreetAddress)
{
    const auto generatedStreetAddress = streetAddress(Locale::et_EE);

    ASSERT_TRUE(std::ranges::any_of(estoniaStreetNames, [&generatedStreetAddress](const std::string_view& streetName)
                                    { return generatedStreetAddress.find(streetName) != std::string::npos; }));
}

TEST_F(LocationTest, shouldGenerateUnitedKingdomStreet)
{
    const auto generatedStreet = street(Locale::en_GB);

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
    ASSERT_TRUE(std::ranges::any_of(unitedkingdomStreetSuffixes,
                                    [&generatedStreetSuffix](const std::string_view& streetSuffix)
                                    { return streetSuffix == generatedStreetSuffix; }));
}

TEST_F(LocationTest, shouldGenerateUnitedKingdomStreetAddress)
{
    const auto generatedStreetAddress = streetAddress(Locale::en_GB);

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
    ASSERT_TRUE(std::ranges::any_of(unitedkingdomStreetSuffixes,
                                    [&generatedStreetSuffix](const std::string_view& streetSuffix)
                                    { return streetSuffix == generatedStreetSuffix; }));
}

TEST_F(LocationTest, shouldGenerateSlovakiaStreet)
{
    const auto generatedStreet = street(Locale::sk_SK);

    ASSERT_TRUE(std::ranges::any_of(slovakiaStreetNames, [&generatedStreet](const std::string_view& street)
                                    { return generatedStreet.find(street) != std::string::npos; }));
}

TEST_F(LocationTest, shouldGenerateSlovakiaStreetAddress)
{
    const auto generatedStreetAddress = streetAddress(Locale::sk_SK);

    const auto generatedAddresses = common::split(generatedStreetAddress, ", ");
    const auto generatedStreetAddressElements = common::split(generatedAddresses[0], " ");

    const auto& generatedBuildingNumber = generatedStreetAddressElements[generatedStreetAddressElements.size() - 1];
    const auto& generatedStreetSuffix = generatedStreetAddressElements[generatedStreetAddressElements.size() - 2];
    const auto& generatedStreet =
        common::join({generatedStreetAddressElements.begin(), generatedStreetAddressElements.end() - 2});

    if (generatedAddresses.size() > 1)
    {
        const auto& generatedSecondaryAddressParts = common::split(generatedAddresses[1], " ");

        const auto& generatedUnitNumber = generatedSecondaryAddressParts[generatedSecondaryAddressParts.size() - 1];

        ASSERT_TRUE(generatedUnitNumber.size() == 1 || generatedUnitNumber.size() == 3);
        ASSERT_TRUE(checkIfAllCharactersAreNumeric(generatedUnitNumber));
    }

    ASSERT_TRUE(!generatedBuildingNumber.empty() && generatedBuildingNumber.size() <= 3);
    ASSERT_TRUE(checkIfAllCharactersAreNumeric(generatedBuildingNumber));

    ASSERT_TRUE(std::ranges::any_of(slovakiaStreetNames, [&generatedStreet](const std::string_view& streetName)
                                    { return generatedStreet.find(streetName) != std::string::npos; }));

    ASSERT_TRUE(std::ranges::any_of(slovakiaStreetSuffixes,
                                    [&generatedStreetSuffix](const std::string_view& streetSuffix)
                                    { return generatedStreetSuffix.find(streetSuffix) != std::string::npos; }));
}


TEST_F(LocationTest, shouldGeneratePortugalStreet)
{
    const auto generatedStreet = street(Locale::pt_PT);

    ASSERT_TRUE(std::ranges::any_of(portugalStreetNames, [&generatedStreet](const std::string_view& street)
                                    { return generatedStreet.find(street) != std::string::npos; }));
}

TEST_F(LocationTest, shouldGeneratePortugalStreetAddress)
{
    const auto generatedStreetAddress = streetAddress(Locale::pt_PT);

    const auto generatedAddresses = common::split(generatedStreetAddress, ", ");
    const auto generatedStreetAddressElements = common::split(generatedAddresses[0], " ");

    const auto& generatedBuildingNumber = generatedStreetAddressElements[generatedStreetAddressElements.size() - 1];
    const auto& generatedStreetSuffix = generatedStreetAddressElements[generatedStreetAddressElements.size() - 2];
    const auto& generatedStreet =
        common::join({generatedStreetAddressElements.begin(), generatedStreetAddressElements.end() - 2});

    if (generatedAddresses.size() > 1)
    {
        const auto& generatedSecondaryAddressParts = common::split(generatedAddresses[1], " ");

        const auto& generatedUnitNumber = generatedSecondaryAddressParts[generatedSecondaryAddressParts.size() - 1];

        ASSERT_TRUE(generatedUnitNumber.size() == 1 || generatedUnitNumber.size() == 3);
        ASSERT_TRUE(checkIfAllCharactersAreNumeric(generatedUnitNumber));
    }

    ASSERT_TRUE(!generatedBuildingNumber.empty() && generatedBuildingNumber.size() <= 3);
    ASSERT_TRUE(checkIfAllCharactersAreNumeric(generatedBuildingNumber));

    ASSERT_TRUE(std::ranges::any_of(portugalStreetNames, [&generatedStreet](const std::string_view& streetName)
                                    { return generatedStreet.find(streetName) != std::string::npos; }));

    ASSERT_TRUE(std::ranges::any_of(portugalStreetSuffixes,
                                    [&generatedStreetSuffix](const std::string_view& streetSuffix)
                                    { return generatedStreetSuffix.find(streetSuffix) != std::string::npos; }));
}

TEST_F(LocationTest, shouldGenerateIsraelStreet)
{
    const auto generatedStreet = street(Locale::he_IL);
    const auto generatedStreetElements = common::split(generatedStreet, " ");
    const auto& generatedStreetPrefix = generatedStreetElements[0];
    const auto& generatedStreetName =
        common::join({generatedStreetElements.begin() + 1, generatedStreetElements.end()});


    ASSERT_TRUE(std::ranges::any_of(israelStreetPrefixes, [&generatedStreetPrefix](const std::string_view& streetPrefix)
                                    { return streetPrefix == generatedStreetPrefix; }));
    ASSERT_TRUE(std::ranges::any_of(israelStreetNames, [&generatedStreetName](const std::string_view& streetName)
                                    { return streetName == generatedStreetName; }));
}

TEST_F(LocationTest, shouldGenerateIsraelStreetAddress)
{
    const auto generatedStreetAddress = streetAddress(Locale::he_IL);
    auto generatedAddresses = common::split(generatedStreetAddress, " ");
    if (generatedAddresses[generatedAddresses.size() - 2] == "דירה" || generatedAddresses[generatedAddresses.size() - 2] == "חדר") 
    {
        const auto& secondaryAddressType = generatedAddresses[generatedAddresses.size() - 2];
        const auto& secondaryAddressNumber = generatedAddresses.back();
        ASSERT_TRUE(secondaryAddressNumber.size() == 1 || secondaryAddressNumber.size() == 2);
        ASSERT_TRUE(checkIfAllCharactersAreNumeric(secondaryAddressNumber));
        ASSERT_TRUE(secondaryAddressType == "דירה" || secondaryAddressType == "חדר");
        generatedAddresses.pop_back();  // Remove unit number
        generatedAddresses.pop_back();
    }
    const auto& generatedStreetPrefix = generatedAddresses[0];
    auto generatedBuildingNumber = generatedAddresses.back();
    generatedAddresses.pop_back();
    while (!generatedBuildingNumber.empty() && !checkIfAllCharactersAreNumeric(generatedBuildingNumber)) {
        generatedBuildingNumber.pop_back(); // Remove the last byte until it's numeric
    }
    const auto& generatedStreetName =
        common::join({generatedAddresses.begin() + 1, generatedAddresses.end()});
    
    ASSERT_TRUE(!generatedBuildingNumber.empty() && generatedBuildingNumber.size() <= 3);   
    ASSERT_TRUE(checkIfAllCharactersAreNumeric(generatedBuildingNumber)); 
    ASSERT_TRUE(std::ranges::any_of(israelStreetPrefixes, [&generatedStreetPrefix](const std::string_view& streetPrefix)
                                { return streetPrefix == generatedStreetPrefix; }));
    ASSERT_TRUE(std::ranges::any_of(israelStreetNames, [&generatedStreetName](const std::string_view& streetName)
                                { return streetName == generatedStreetName; }));
}