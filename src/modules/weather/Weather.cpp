#include "faker-cxx/Weather.h"

#include <string>

#include "data/WeatherDescription.h"
#include "faker-cxx/Helper.h"
#include "faker-cxx/Number.h"
#include "../../common/WeatherHelper.h"

namespace faker
{
Weather::Temperature Weather::temperature()
{
    double metric = Number::decimal(10.0, 30.0);
    double imperial = WeatherHelper::celsiusToFahrenheit(metric);

    return {metric, imperial};
}

Weather::Pressure Weather::pressure()
{
    double metric = Number::decimal(100.0, 102.0);
    double imperial = WeatherHelper::kPaToPsi(metric);

    return {metric, imperial};
}

Weather::Visibility Weather::visibility() {
    double metric = Number::decimal(1.0, 10.0);
    double imperial = WeatherHelper::milesToKilometers(metric);

    return {metric, imperial};
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
