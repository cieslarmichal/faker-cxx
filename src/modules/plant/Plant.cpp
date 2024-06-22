#include "faker-cxx/Plant.h"

#include <string_view>

#include "faker-cxx/Helper.h"
#include "PlantData.h"

namespace faker::plant
{
std::string_view tree()
{
    return Helper::arrayElement(trees);
}

std::string_view flower()
{
    return Helper::arrayElement(flowers);
}

std::string_view shrub()
{
    return Helper::arrayElement(shrubs);
}

std::string_view grass()
{
    return Helper::arrayElement(grasses);
}

std::string_view fern()
{
    return Helper::arrayElement(ferns);
}

std::string_view succulent()
{
    return Helper::arrayElement(succulents);
}

std::string_view vine()
{
    return Helper::arrayElement(vines);
}

std::string_view plantType()
{
    return Helper::arrayElement(plantTypes);
}
}
