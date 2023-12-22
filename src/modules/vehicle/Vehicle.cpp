#include "faker-cxx/Vehicle.h"

#include "data/Bicycle.h"
#include "data/Color.h"
#include "data/Fuel.h"
#include "data/Manufacturer.h"
#include "data/Model.h"
#include "data/Type.h"
#include "faker-cxx/Helper.h"
#include "faker-cxx/Number.h"
#include "faker-cxx/String.h"
#include "fmt/format.h"

namespace faker
{

std::string Vehicle::bicycle()
{
    return Helper::arrayElement(bicycle_types);
}

std::string Vehicle::color()
{
    return Helper::arrayElement(vehicle_colors);
}

std::string Vehicle::fuel()
{
    return Helper::arrayElement(fuel_types);
}

std::string Vehicle::manufacturer()
{
    return Helper::arrayElement(manufacturers);
}

std::string Vehicle::model()
{
    return Helper::arrayElement(models);
}

std::string Vehicle::type()
{
    return Helper::arrayElement(vehicle_types);
}

std::string Vehicle::vehicle()
{
    return fmt::format("{} {}", manufacturer(), model());
}

std::string Vehicle::vin()
{
    std::string exclude_characters{"oiqOIQ"};

    return fmt::format("{}{}{}{}", String::alphanumeric(10, StringCasing::Upper, exclude_characters),
                       String::alpha(1, StringCasing::Upper, exclude_characters),
                       String::alphanumeric(1, StringCasing::Upper, exclude_characters), Number::integer(10000, 99999));
}

std::string Vehicle::vrm()
{
    return fmt::format("{}{}{}", String::alpha(2, StringCasing::Upper), String::numeric(2, true),
                       String::alpha(3, StringCasing::Upper));
}

}
