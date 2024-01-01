#pragma once

#include <string>
#include <vector>

#include "faker-cxx/Science.h"

namespace faker
{

const std::vector<Unit> distanceUnits = {
    /*Units to measure Length*/
    Unit("Millimeter", "mm", "Length"), Unit("Centimeter", "cm", "Length"), Unit("Meter", "m", "Length"),
    Unit("Kilometer", "km", "Length"),  Unit("Inch", "in", "Length"),       Unit("Foot", "ft", "Length"),
    Unit("Yard", "yd", "Length"),       Unit("Mile", "mi", "Length"),
};

const std::vector<Unit> massUnits = {
    /*Units to measure Mass*/
    Unit("Gram", "g", "Mass"),       Unit("Kilogram", "kg", "Mass"),  Unit("Milligram", "mg", "Mass"),
    Unit("Microgram", "μg", "Mass"), Unit("Metric ton", "t", "Mass"), Unit("Ounce", "oz", "Mass"),
    Unit("Pound", "lb", "Mass"),     Unit("Slug", "sl", "Mass"),
};

const std::vector<Unit> timeUnits = {
    /*Units to measure Time*/
    Unit("Second", "s", "Time"), Unit("Minute", "min", "Time"), Unit("Hour", "hr", "Time"), Unit("Day", "d", "Time"),
    Unit("Week", "wk", "Time"),  Unit("Month", "mo", "Time"),   Unit("Year", "yr", "Time"),
};

const std::vector<Unit> currentUnits = {
    /*Units to measure Electric Current*/
    Unit("Ampere", "A", "Electric Current"),
    Unit("Milliampere", "mA", "Electric Current"),
    Unit("Microampere", "μA", "Electric Current"),
};

const std::vector<Unit> temperatureUnits = {
    /*Units to measure Temperature*/
    Unit("Celcius", "°C", "Temperature"),
    Unit("Fahrenheit", "°F", "Temperature"),
    Unit("Kelvin", "K", "Temperature"),
};

};
