#include "faker-cxx/Vehicle.h"

#include <string>
#include <string_view>

#include "common/FormatHelper.h"
#include "faker-cxx/Helper.h"
#include "faker-cxx/Number.h"
#include "faker-cxx/String.h"
#include "VehicleData.h"

namespace faker::vehicle
{

std::string_view bicycle()
{
    return Helper::arrayElement(bicycle_types);
}

std::string_view color()
{
    return Helper::arrayElement(vehicle_colors);
}

std::string_view fuel()
{
    return Helper::arrayElement(fuel_types);
}

std::string_view manufacturer()
{
    return Helper::arrayElement(manufacturers);
}

std::string_view model()
{
    return Helper::arrayElement(models);
}

std::string_view type()
{
    return Helper::arrayElement(vehicle_types);
}

std::string vehicleName()
{
    return FormatHelper::format("{} {}", manufacturer(), model());
}

std::string vin()
{
    std::string exclude_characters{"oiqOIQ"};

    return FormatHelper::format("{}{}{}{}", String::alphanumeric(10, StringCasing::Upper, exclude_characters),
                                String::alpha(1, StringCasing::Upper, exclude_characters),
                                String::alphanumeric(1, StringCasing::Upper, exclude_characters),
                                number::integer(10000, 99999));
}

std::string vrm()
{
    return FormatHelper::format("{}{}{}", String::alpha(2, StringCasing::Upper), String::numeric(2, true),
                                String::alpha(3, StringCasing::Upper));
}

}
