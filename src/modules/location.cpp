#include "faker-cxx/location.h"

#include <cstdint>
#include <stdexcept>
#include <string>
#include <string_view>
#include <unordered_map>
#include <unordered_set>

#include "common/algo_helper.h"
#include "common/format_helper.h"
#include "faker-cxx/helper.h"
#include "faker-cxx/number.h"
#include "faker-cxx/person.h"
#include "faker-cxx/types/locale.h"
#include "faker-cxx/types/precision.h"
#include "location_data.h"

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

namespace faker::location
{
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
    case Locale::en_CA:
        return canadaEnAddresses;
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
    case Locale::hu_HU:
        return hungaryAddresses;
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
    case Locale::ar_PS:
        return palestineAddresses;
    case Locale::es_MX:
        return mexicoAddresses;
    case Locale::ro_RO:
        return romaniaAddresses;
    case Locale::nb_NO:
        return norwayAddresses;
    case Locale::is_IS:
        return icelandAddresses;
    case Locale::tr_TR:
        return turkeyAddresses;
    case Locale::ja_JP:
        return japanAddresses;
    case Locale::lt_LT:
        return lithuaniaAddresses;
    default:
        return usaAddresses;
    }
}
}

std::string_view continent(std::string_view country)
{
    static const std::vector<std::string_view> continents = {"Africa",        "Antarctica", "Asia",         "Europe",
                                                             "North America", "Australia",  "South America"};

    if (country.empty())
    {
        return helper::randomElement(continents);
    }

    auto it = countryToContinent.find(country);
    if (it != countryToContinent.end())
    {
        return it->second;
    }

    return "Unknown";
}

std::string_view country()
{
    return helper::randomElement(allCountries);
}

std::string_view countryCode()
{
    return helper::randomElement(countryCodes);
}

std::string_view state(Locale locale)
{
    const auto& localeAddresses = getAddresses(locale);

    if (localeAddresses.states.empty())
    {
        return {};
    }

    return helper::randomElement(localeAddresses.states);
}

std::string city(Locale locale)
{
    const auto& localeAddresses = getAddresses(locale);

    const auto cityFormat = static_cast<std::string>(helper::randomElement(localeAddresses.cityFormats));

    const auto dataGeneratorsMapping = std::unordered_map<std::string, std::function<std::string()>>{
        {"firstName", [&locale]() { return static_cast<std::string>(person::firstName(locale)); }},
        {"lastName", [&locale]() { return static_cast<std::string>(person::lastName(locale)); }},
        {"cityName",
         [&localeAddresses]() { return static_cast<std::string>(helper::randomElement(localeAddresses.cities)); }},
        {"cityPrefix", [&localeAddresses]()
         { return static_cast<std::string>(helper::randomElement(localeAddresses.cityPrefixes)); }},
        {"citySuffix", [&localeAddresses]()
         { return static_cast<std::string>(helper::randomElement(localeAddresses.citySuffixes)); }}};

    return common::fillTokenValues(cityFormat, dataGeneratorsMapping);
}

std::string zipCode(Locale locale)
{
    const auto& localeAddresses = getAddresses(locale);

    std::string zip_with_symbols = static_cast<std::string>(localeAddresses.zipCodeFormat);

    if (postCodeSet.count(locale) == 1)
    {
        return helper::replaceSymbolWithLetter(helper::replaceSymbolWithNumber(zip_with_symbols));
    }

    return helper::replaceSymbolWithNumber(zip_with_symbols);
}

std::string streetAddress(Locale locale)
{
    const auto& localeAddresses = getAddresses(locale);

    const auto dataGeneratorsMapping = std::unordered_map<std::string, std::function<std::string()>>{
        {"buildingNumber", [&locale]() { return buildingNumber(locale); }},
        {"street", [&locale]() { return street(locale); }},
        {"secondaryAddress", [&locale]() { return secondaryAddress(locale); }}};

    const auto addressFormat = static_cast<std::string>(helper::randomElement(localeAddresses.addressFormats));

    return common::fillTokenValues(addressFormat, dataGeneratorsMapping);
}

std::string street(Locale locale)
{
    const auto& localeAddresses = getAddresses(locale);

    const auto streetFormat = static_cast<std::string>(helper::randomElement(localeAddresses.streetFormats));

    const auto dataGeneratorsMapping = std::unordered_map<std::string, std::function<std::string()>>{
        {"firstName", [&locale]() { return static_cast<std::string>(person::firstName(locale)); }},
        {"lastName", [&locale]() { return static_cast<std::string>(person::lastName(locale)); }},
        {"streetName",
         [&localeAddresses]() { return static_cast<std::string>(helper::randomElement(localeAddresses.streetNames)); }},
        {"streetPrefix", [&localeAddresses]()
         { return static_cast<std::string>(helper::randomElement(localeAddresses.streetPrefixes)); }},
        {"streetSuffix", [&localeAddresses]()
         { return static_cast<std::string>(helper::randomElement(localeAddresses.streetSuffixes)); }}};

    return common::fillTokenValues(streetFormat, dataGeneratorsMapping);
}

std::string buildingNumber(Locale locale)
{
    const auto& localeAddresses = getAddresses(locale);

    const auto buildingNumberFormat =
        static_cast<std::string>(helper::randomElement(localeAddresses.buildingNumberFormats));

    return helper::replaceSymbolWithNumber(buildingNumberFormat);
}

std::string secondaryAddress(Locale locale)
{
    const auto& localeAddresses = getAddresses(locale);

    if (localeAddresses.secondaryAddressFormats.empty())
    {
        return "";
    }

    const auto secondaryAddressFormat =
        static_cast<std::string>(helper::randomElement(localeAddresses.secondaryAddressFormats));

    return helper::replaceSymbolWithNumber(secondaryAddressFormat);
}

std::string latitude(Precision precision)
{
    const std::floating_point auto latitude = number::decimal<double>(-90.0, 90.0);

    return common::precisionFormat(precision, latitude);
}

std::string longitude(Precision precision)
{
    const std::floating_point auto longitude = number::decimal<double>(-180.0, 180.0);

    return common::precisionFormat(precision, longitude);
}

std::string mgrs(int precision)
{
    if (precision < 0 || precision > 5)
    {
        throw std::invalid_argument("Precision must be between 0 and 5");
    }
    static const std::string_view eastings[] = {
        "ABCDEFGH", // UTM zones 1-3
        "JKLMNPQR", // UTM zones 4-6
        "STUVWXYZ"  // UTM zones 7-9
    };

    // we avoid areas near the poles because the MGRS grid is not well defined there
    static const std::string_view northings = "CDEFGHJKLMNPQRST";

    std::string mgrs_str;
    mgrs_str.reserve(static_cast<size_t>(precision * 2 + 5));
    int zone = number::integer(1, 60);

    mgrs_str += std::to_string(zone);

    char band = helper::randomElement(northings);
    mgrs_str.push_back(band);

    std::string_view easting_group = eastings[(zone - 1) % 3];

    char grid1_idx = helper::randomElement(easting_group);
    char grid2_idx = helper::randomElement(northings);

    mgrs_str.push_back(grid1_idx);
    mgrs_str.push_back(grid2_idx);

    std::string easting_block = "";
    std::string northing_block = "";

    while (precision-- > 0)
    {
        easting_block.push_back(static_cast<char>(number::integer(int('0'), int('9'))));
        northing_block.push_back(static_cast<char>(number::integer(int('0'), int('9'))));
    }
    mgrs_str += easting_block;
    mgrs_str += northing_block;
    return mgrs_str;
}

std::string_view direction()
{
    return helper::randomElement(directions);
}

std::string_view ordinalDirection(bool abbreviated)
{
    return abbreviated ? helper::randomElement(ordinalDirections).second :
                         helper::randomElement(ordinalDirections).first;
}

std::string_view timeZone()
{
    return helper::randomElement(timeZones);
}

std::tuple<std::string, std::string> nearbyGPSCoordinate(Precision precision, const std::tuple<double, double>& origin,
                                                         const double radius, const bool isMetric)
{
    auto toRadians = [](double degree) -> double { return degree * M_PI / 180.0; };
    auto toDegrees = [](double radian) -> double { return radian * 180.0 / M_PI; };

    // If origin is not provided, generate a random GPS coordinate.
    if (std::get<0>(origin) == std::numeric_limits<double>::max() &&
        std::get<1>(origin) == std::numeric_limits<double>::max())
    {
        return {latitude(precision), longitude(precision)};
    }

    double lat1 = toRadians(std::get<0>(origin));
    double lon1 = toRadians(std::get<1>(origin));

    const auto angleRadians = number::decimal<double>(2 * M_PI);
    double sinAlpha1 = sin(angleRadians);
    double cosAlpha1 = cos(angleRadians);

    const auto radiusMetric = isMetric ? radius : radius * 1.60934;
    const auto distanceInKm = number::decimal<double>(radiusMetric);

    // Compute new lat,lon pair via Vincenty Direct Method
    constexpr double WGS84_A = 6378137.0;               // Semi-major axis (meters)
    constexpr double WGS84_F = 1 / 298.257223563;       // Flattening
    constexpr double WGS84_B = WGS84_A * (1 - WGS84_F); // Semi-minor axis (meters)

    double U1 = atan((1 - WGS84_F) * tan(lat1));
    double sinU1 = sin(U1), cosU1 = cos(U1);

    double sigma1 = atan2(tan(U1), cosAlpha1);
    double sinAlpha = cosU1 * sinAlpha1;
    double cos2Alpha = 1 - sinAlpha * sinAlpha;

    double uSquared = cos2Alpha * (WGS84_A * WGS84_A - WGS84_B * WGS84_B) / (WGS84_B * WGS84_B);
    double A = 1 + (uSquared / 16384.0) * (4096.0 + uSquared * (-768.0 + uSquared * (320.0 - 175.0 * uSquared)));
    double B = (uSquared / 1024.0) * (256.0 + uSquared * (-128.0 + uSquared * (74.0 - 47.0 * uSquared)));

    double sigma = distanceInKm * 1000.0 / (WGS84_B * A);
    double sigmaP;
    double cos2SigmaM, sinSigma, cosSigma, deltaSigma;
    do
    {
        sigmaP = sigma;
        cos2SigmaM = cos(2 * sigma1 + sigma);
        sinSigma = sin(sigma);
        cosSigma = cos(sigma);
        deltaSigma = B * sinSigma *
                     (cos2SigmaM + (B / 4.0) * (cosSigma * (-1 + 2 * cos2SigmaM * cos2SigmaM) -
                                                (B / 6.0) * cos2SigmaM * (-3 + 4 * sinSigma * sinSigma) *
                                                    (-3 + 4 * cos2SigmaM * cos2SigmaM)));
        sigma = distanceInKm * 1000.0 / (WGS84_B * A) + deltaSigma;
    } while (fabs(sigma - sigmaP) > 1e-12);

    double tmp = sinU1 * sinSigma - cosU1 * cosSigma * cosAlpha1;
    double lat2 =
        atan2(sinU1 * cosSigma + cosU1 * sinSigma * cosAlpha1, (1 - WGS84_F) * sqrt(sinAlpha * sinAlpha + tmp * tmp));
    double lambda = atan2(sinSigma * sinAlpha1, cosU1 * cosSigma - sinU1 * sinSigma * cosAlpha1);
    double C = (WGS84_F / 16.0) * cos2Alpha * (4.0 + WGS84_F * (4.0 - 3.0 * cos2Alpha));
    double L = lambda - (1 - C) * WGS84_F * sinAlpha *
                            (sigma + C * sinSigma * (cos2SigmaM + C * cosSigma * (-1 + 2 * cos2SigmaM * cos2SigmaM)));

    double coordinateLatitude = toDegrees(lat2);
    double coordinateLongitude = toDegrees(lon1 + L);

    // Box the latitude [-90, 90]
    coordinateLatitude = std::fmod(coordinateLatitude, 180.0);
    if (coordinateLatitude < -90.0 || coordinateLatitude > 90.0)
    {
        coordinateLatitude = std::copysign(180.0, coordinateLatitude) - coordinateLatitude;
        coordinateLongitude += 180.0;
    }

    // Box the longitude [-180, 180]
    coordinateLongitude = std::fmod(std::fmod(coordinateLongitude, 360.0) + 540.0, 360.0) - 180.0;

    return {common::precisionFormat(precision, coordinateLatitude),
            common::precisionFormat(precision, coordinateLongitude)};
}
}
