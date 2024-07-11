#include "faker-cxx/vehicle.h"

#include <string>
#include <string_view>

#include "common/format_helper.h"
#include "faker-cxx/helper.h"
#include "faker-cxx/number.h"
#include "faker-cxx/string.h"
#include "vehicle_data.h"

namespace faker::vehicle
{
std::string_view bicycle()
{
    return helper::arrayElement(bicycle_types);
}

std::string_view color()
{
    return helper::arrayElement(vehicle_colors);
}

std::string_view fuel()
{
    return helper::arrayElement(fuel_types);
}

std::string_view manufacturer()
{
    return helper::arrayElement(manufacturers);
}

std::string_view model()
{
    return helper::arrayElement(models);
}

std::string_view type()
{
    return helper::arrayElement(vehicle_types);
}

std::string vehicleName()
{
    return common::format("{} {}", manufacturer(), model());
}

std::string vin()
{
    std::string exclude_characters{"oiqOIQ"};

    return common::format("{}{}{}{}", string::alphanumeric(10, string::StringCasing::Upper, exclude_characters),
                                string::alpha(1, string::StringCasing::Upper, exclude_characters),
                                string::alphanumeric(1, string::StringCasing::Upper, exclude_characters),
                                number::integer(10000, 99999));
}

std::string vrm()
{
    return common::format("{}{}{}", string::alpha(2, string::StringCasing::Upper), string::numeric(2, true),
                                string::alpha(3, string::StringCasing::Upper));
}

}
