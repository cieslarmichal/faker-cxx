#include "faker-cxx/Vehicle.h"

#include "common/FormatHelper.h"
#include "VehicleData.h"
#include "faker-cxx/Helper.h"
#include "faker-cxx/Number.h"
#include "faker-cxx/String.h"

namespace faker
{

std::string_view Vehicle::bicycle()
{
    return Helper::arrayElement(vehicle::bicycle_types);
}

std::string_view Vehicle::color()
{
    return Helper::arrayElement(vehicle::vehicle_colors);
}

std::string_view Vehicle::fuel()
{
    return Helper::arrayElement(vehicle::fuel_types);
}

std::string_view Vehicle::manufacturer()
{
    return Helper::arrayElement(vehicle::manufacturers);
}

std::string_view Vehicle::model()
{
    return Helper::arrayElement(vehicle::models);
}

std::string_view Vehicle::type()
{
    return Helper::arrayElement(vehicle::vehicle_types);
}

std::string Vehicle::vehicle()
{
    return FormatHelper::format("{} {}", manufacturer(), model());
}

std::string Vehicle::vin()
{
    std::string exclude_characters{"oiqOIQ"};

    return FormatHelper::format("{}{}{}{}", String::alphanumeric(10, StringCasing::Upper, exclude_characters),
                                String::alpha(1, StringCasing::Upper, exclude_characters),
                                String::alphanumeric(1, StringCasing::Upper, exclude_characters),
                                Number::integer(10000, 99999));
}

std::string Vehicle::vrm()
{
    return FormatHelper::format("{}{}{}", String::alpha(2, StringCasing::Upper), String::numeric(2, true),
                                String::alpha(3, StringCasing::Upper));
}

}
