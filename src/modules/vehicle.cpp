#include "faker-cxx/vehicle.h"

#include <string>
#include <string_view>

#include "common/format_helper.h"
#include "faker-cxx/helper.h"
#include "faker-cxx/number.h"
#include "faker-cxx/string.h"
#include "faker-cxx/types/locale.h"
#include "vehicle_data.h"

namespace faker::vehicle
{
namespace
{
const struct VehicleDefinition& getVehicleDefinition(Locale locale)
{
    return enUSVehicleDefinition ;
}
}

std::string_view bicycle(Locale locale)
{
    const auto& vehicleDefinition = getVehicleDefinition(locale);
    return helper::randomElement(vehicleDefinition.bicycles);
}

std::string_view color(Locale locale)
{
    const auto& vehicleDefinition = getVehicleDefinition(locale);
    return helper::randomElement(vehicleDefinition.colors);
}

std::string_view fuel(Locale locale)
{
    const auto& vehicleDefinition = getVehicleDefinition(locale);
    return helper::randomElement(vehicleDefinition.fuelTypes);
}

std::string_view manufacturer(Locale locale)
{
    const auto& vehicleDefinition = getVehicleDefinition(locale);
    return helper::randomElement(vehicleDefinition.manufacturers);
}

std::string_view model(Locale locale)
{
    const auto& vehicleDefinition = getVehicleDefinition(locale);
    return helper::randomElement(vehicleDefinition.models);
}

std::string_view type(Locale locale)
{
    const auto& vehicleDefinition = getVehicleDefinition(locale);
    return helper::randomElement(vehicleDefinition.vehicles);
}

std::string vehicleName(Locale locale)
{
    return common::format("{} {}", manufacturer(locale), model(locale));
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
