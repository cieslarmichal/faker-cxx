#include "WeatherHelper.h"

namespace faker
{
double WeatherHelper::celsiusToFahrenheit(double celsius)
{
    return (celsius * 9.0 / 5.0) + 32;
}

double WeatherHelper::kPaToPsi(double kPa)
{
    return kPa * 0.14503773773375;
}

double WeatherHelper::milesToKilometers(double miles)
{
    return miles * 1.609344;
}
}
