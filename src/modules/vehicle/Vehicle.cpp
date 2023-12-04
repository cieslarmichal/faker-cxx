#include "faker-cxx/Vehicle.h"

#include "data/Bicycle.h"
#include "data/Fuel.h"
#include "data/Manufacturer.h"
#include "data/Model.h"
#include "data/Type.h"
#include "faker-cxx/Helper.h"

namespace faker
{

std::string Vehicle::bicycle()
{
    return Helper::arrayElement(bicycle_types);
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

}