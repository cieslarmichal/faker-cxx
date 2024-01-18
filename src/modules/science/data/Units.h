#pragma once

#include <vector>

#include "faker-cxx/types/Unit.h"

namespace faker
{
const std::vector<Unit> distanceUnits = {
    {"Millimeter", "mm", "Length"}, {"Centimeter", "cm", "Length"}, {"Meter", "m", "Length"},
    {"Kilometer", "km", "Length"},  {"Inch", "in", "Length"},       {"Foot", "ft", "Length"},
    {"Yard", "yd", "Length"},       {"Mile", "mi", "Length"},
};

const std::vector<Unit> massUnits = {
    {"Gram", "g", "Mass"},       {"Kilogram", "kg", "Mass"}, {"Milligram", "mg", "Mass"}, {"Microgram", "μg", "Mass"},
    {"Metric ton", "t", "Mass"}, {"Ounce", "oz", "Mass"},    {"Pound", "lb", "Mass"},     {"Slug", "sl", "Mass"},
};

const std::vector<Unit> timeUnits = {
    {"Second", "s", "Time"}, {"Minute", "min", "Time"}, {"Hour", "hr", "Time"}, {"Day", "d", "Time"},
    {"Week", "wk", "Time"},  {"Month", "mo", "Time"},   {"Year", "yr", "Time"},
};

const std::vector<Unit> currentUnits = {
    {"Ampere", "A", "Electric Current"},
    {"Milliampere", "mA", "Electric Current"},
    {"Microampere", "μA", "Electric Current"},
};

const std::vector<Unit> temperatureUnits = {
    {"Celcius", "°C", "Temperature"},
    {"Fahrenheit", "°F", "Temperature"},
    {"Kelvin", "K", "Temperature"},
};
};
