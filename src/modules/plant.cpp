#include "faker-cxx/plant.h"

#include <string_view>

#include "faker-cxx/helper.h"
#include "plant_data.h"

namespace faker::plant
{
std::string_view tree()
{
    return helper::randomElement(trees);
}

std::string_view flower()
{
    return helper::randomElement(flowers);
}

std::string_view shrub()
{
    return helper::randomElement(shrubs);
}

std::string_view grass()
{
    return helper::randomElement(grasses);
}

std::string_view fern()
{
    return helper::randomElement(ferns);
}

std::string_view succulent()
{
    return helper::randomElement(succulents);
}

std::string_view vine()
{
    return helper::randomElement(vines);
}

std::string_view plantType()
{
    return helper::randomElement(plantTypes);
}
}
