#include "../common/conversions.h"
#include "../common/helper.h"
#include "weather_data.h"
#include <faker/number.h>
#include <faker/weather.h>

namespace faker::weather {
Temperature temperature()
{
    double metric = number::decimal(10.0, 30.0);
    double imperial = utils::celsius_to_fahrenheit(metric);

    return { metric, imperial };
}

Pressure pressure()
{
    double metric = number::decimal(100.0, 102.0);
    double imperial = utils::kpa_to_psi(metric);

    return { metric, imperial };
}

Visibility visibility()
{
    double metric = number::decimal(1.0, 10.0);
    double imperial = utils::mile_to_km(metric);

    return { metric, imperial };
}

WindSpeed wind_speed() { return { number::decimal(0.1, 24.2), number::decimal(0.1, 15.0) }; }

int uv_index() { return number::integer(0, 11); }

int humidity() { return number::integer(0, 100); }

std::string_view description() { return Helper::arrayElement(data::weatherDescriptions); }

int cloud_cover() { return number::integer(0, 100); }
}
