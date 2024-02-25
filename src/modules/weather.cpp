#include "../common/weather_helper.h"
#include "weather_data.h"
#include <faker/helper.h>
#include <faker/number.h>
#include <faker/weather.h>

namespace faker::weather {
Temperature temperature()
{
    double metric = number::decimal(10.0, 30.0);
    double imperial = WeatherHelper::celsiusToFahrenheit(metric);

    return { metric, imperial };
}

Pressure pressure()
{
    double metric = number::decimal(100.0, 102.0);
    double imperial = WeatherHelper::kPaToPsi(metric);

    return { metric, imperial };
}

Visibility visibility()
{
    double metric = number::decimal(1.0, 10.0);
    double imperial = WeatherHelper::milesToKilometers(metric);

    return { metric, imperial };
}

WindSpeed windSpeed() { return { number::decimal(0.1, 24.2), number::decimal(0.1, 15.0) }; }

int uvIndex() { return number::integer(0, 11); }

int humidity() { return number::integer(0, 100); }

std::string_view weatherDescription() { return Helper::arrayElement(data::weatherDescriptions); }

int cloudCover() { return number::integer(0, 100); }
}
