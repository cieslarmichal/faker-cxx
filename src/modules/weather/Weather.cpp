#include "faker-cxx/Weather.h"

#include <string>

#include "data/WeatherDescription.h"
#include "faker-cxx/Helper.h"
#include "faker-cxx/Number.h"

namespace faker
{
Weather::Temperature Weather::temperature()
{
    return {Number::integer(10, 30), Number::integer(50, 90)};
}

Weather::Pressure Weather::pressure()
{
    return {Number::integer(1000, 1100), Number::integer(14, 16) + Number::decimal(0.1, 0.9)};
}

Weather::Visibility Weather::visibility()
{
    return {Number::decimal(0.1, 10.0), Number::decimal(0.1, 6.2)};
}

Weather::WindSpeed Weather::windSpeed()
{
    return {Number::decimal(0.1, 24.2), Number::decimal(0.1, 15.0)};
}

int Weather::uvIndex()
{
    return Number::integer(0, 11);
}

int Weather::humidity()
{
    return Number::integer(0, 100);
}

std::string Weather::weatherDescription()
{
    return Helper::arrayElement<std::string>(weatherDescriptions);
}

int Weather::cloudCover()
{
    return Number::integer(0, 100);
}
}
