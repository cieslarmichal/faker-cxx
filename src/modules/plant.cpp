#include "faker-cxx/plant.h"

#include <string_view>

#include "faker-cxx/helper.h"
#include "plant_data.h"

namespace faker::plant
{
namespace
{
const struct PlantDefinition& getPlantDefinition(Locale locale)
{
    switch (locale)
    {
    default:
        return enUSPlantDefinition;
    }
}
}

std::string_view tree(Locale locale)
{
    const auto& plantDefinition = getPlantDefinition(locale);

    return helper::randomElement(plantDefinition.trees);
}

std::string_view flower(Locale locale)
{
    const auto& plantDefinition = getPlantDefinition(locale);

    return helper::randomElement(plantDefinition.flowers);
}

std::string_view shrub(Locale locale)
{
    const auto& plantDefinition = getPlantDefinition(locale);

    return helper::randomElement(plantDefinition.shrubs);
}

std::string_view grass(Locale locale)
{
    const auto& plantDefinition = getPlantDefinition(locale);

    return helper::randomElement(plantDefinition.grasses);
}

std::string_view fern(Locale locale)
{
    const auto& plantDefinition = getPlantDefinition(locale);

    return helper::randomElement(plantDefinition.ferns);
}

std::string_view succulent(Locale locale)
{
    const auto& plantDefinition = getPlantDefinition(locale);

    return helper::randomElement(plantDefinition.succulents);
}

std::string_view vine(Locale locale)
{
    const auto& plantDefinition = getPlantDefinition(locale);

    return helper::randomElement(plantDefinition.vines);
}

std::string_view plantType(Locale locale)
{
    const auto& plantDefinition = getPlantDefinition(locale);

    return helper::randomElement(plantDefinition.plantTypes);
}
}
