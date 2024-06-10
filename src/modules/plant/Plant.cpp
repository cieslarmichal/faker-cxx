#include "faker-cxx/Plant.h"

#include <string_view>

#include "PlantData.h"
#include "faker-cxx/Helper.h"

namespace faker
{
std::string_view Plant::tree()
{
    return Helper::arrayElement(trees);
}

std::string_view Plant::flower()
{
    return Helper::arrayElement(flowers);
}

std::string_view Plant::shrub()
{
    return Helper::arrayElement(shrubs);
}

std::string_view Plant::grass()
{
    return Helper::arrayElement(grasses);
}

std::string_view Plant::fern()
{
    return Helper::arrayElement(ferns);
}

std::string_view Plant::succulent()
{
    return Helper::arrayElement(succulents);
}

std::string_view Plant::vine()
{
    return Helper::arrayElement(vines);
}

std::string_view Plant::plantType()
{
    return Helper::arrayElement(plantTypes);
}
}