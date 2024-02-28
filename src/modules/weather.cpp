#include "../common/conversions.h"
#include "../common/random.h"
#include "weather_data.h"
#include <faker/number.h>
#include <faker/weather.h>

namespace faker::weather {
temperature_value temperature()
{
    double metric = number::decimal(10.0, 30.0);
    double imperial = utils::celsius_to_fahrenheit(metric);

    return { metric, imperial };
}

pressure_value pressure()
{
    double metric = number::decimal(100.0, 102.0);
    double imperial = utils::kpa_to_psi(metric);

    return { metric, imperial };
}

visibility_value visibility()
{
    double metric = number::decimal(1.0, 10.0);
    double imperial = utils::mile_to_km(metric);

    return { metric, imperial };
}

wind_speed_value wind_speed() { return { number::decimal(0.1, 24.2), number::decimal(0.1, 15.0) }; }

int uv_index() { return number::integer(0, 11); }

int humidity() { return number::integer(0, 100); }

std::string_view description() { return random::element(data::weather_descriptions); }

int cloud_cover() { return number::integer(0, 100); }
}
