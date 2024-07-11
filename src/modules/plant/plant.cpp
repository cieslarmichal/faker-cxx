#include "faker-cxx/plant.h"

#include <string_view>

#include "faker-cxx/helper.h"
#include "plant_data.h"

namespace faker::plant
{
std::string_view tree()
{
    return helper::arrayElement(trees);
}

std::string_view flower()
{
    return helper::arrayElement(flowers);
}

std::string_view shrub()
{
    return helper::arrayElement(shrubs);
}

std::string_view grass()
{
    return helper::arrayElement(grasses);
}

std::string_view fern()
{
    return helper::arrayElement(ferns);
}

std::string_view succulent()
{
    return helper::arrayElement(succulents);
}

std::string_view vine()
{
    return helper::arrayElement(vines);
}

std::string_view plantType()
{
    return helper::arrayElement(plantTypes);
}
}
