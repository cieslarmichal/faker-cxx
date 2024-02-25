#include "../common/format_helper.h"
#include "vehicle_data.h"
#include <faker/helper.h>
#include <faker/number.h>
#include <faker/string.h>
#include <faker/vehicle.h>

namespace faker::vehicle {

std::string bicycle() { return Helper::arrayElement(bicycle_types); }

std::string color() { return Helper::arrayElement(vehicle_colors); }

std::string fuel() { return Helper::arrayElement(fuel_types); }

std::string manufacturer() { return Helper::arrayElement(manufacturers); }

std::string model() { return Helper::arrayElement(models); }

std::string type() { return Helper::arrayElement(vehicle_types); }

std::string vehicle() { return FormatHelper::format("{} {}", manufacturer(), model()); }

std::string vin()
{
    std::string exclude_characters { "oiqOIQ" };

    return FormatHelper::format("{}{}{}{}",
        String::alphanumeric(10, StringCasing::Upper, exclude_characters),
        String::alpha(1, StringCasing::Upper, exclude_characters),
        String::alphanumeric(1, StringCasing::Upper, exclude_characters),
        number::integer(10000, 99999));
}

std::string vrm()
{
    return FormatHelper::format("{}{}{}", String::alpha(2, StringCasing::Upper),
        String::numeric(2, true), String::alpha(3, StringCasing::Upper));
}

}
