#include "faker-cxx/animal.h"

#include <string_view>

#include "animal_data.h"
#include "faker-cxx/helper.h"

namespace faker::animal
{
namespace
{
const struct AnimalDefinition& getAnimalDefinition(Locale locale)
{
    switch (locale)
    {
    default:
        return enUSAnimalDefinition;
    }
}
}

std::string_view bear(Locale locale)
{
    const auto& animalDefinition = getAnimalDefinition(locale);

    return helper::randomElement(animalDefinition.bears);
}

std::string_view bird(Locale locale)
{
    const auto& animalDefinition = getAnimalDefinition(locale);

    return helper::randomElement(animalDefinition.birds);
}

std::string_view cat(Locale locale)
{
    const auto& animalDefinition = getAnimalDefinition(locale);

    return helper::randomElement(animalDefinition.cats);
}

std::string_view cetacean(Locale locale)
{
    const auto& animalDefinition = getAnimalDefinition(locale);

    return helper::randomElement(animalDefinition.cetaceans);
}

std::string_view cow(Locale locale)
{
    const auto& animalDefinition = getAnimalDefinition(locale);

    return helper::randomElement(animalDefinition.cows);
}

std::string_view crocodile(Locale locale)
{
    const auto& animalDefinition = getAnimalDefinition(locale);

    return helper::randomElement(animalDefinition.crocodiles);
}

std::string_view dog(Locale locale)
{
    const auto& animalDefinition = getAnimalDefinition(locale);

    return helper::randomElement(animalDefinition.dogs);
}

std::string_view fish(Locale locale)
{
    const auto& animalDefinition = getAnimalDefinition(locale);

    return helper::randomElement(animalDefinition.fishes);
}

std::string_view horse(Locale locale)
{
    const auto& animalDefinition = getAnimalDefinition(locale);

    return helper::randomElement(animalDefinition.horses);
}

std::string_view insect(Locale locale)
{
    const auto& animalDefinition = getAnimalDefinition(locale);

    return helper::randomElement(animalDefinition.insects);
}

std::string_view lion(Locale locale)
{
    const auto& animalDefinition = getAnimalDefinition(locale);

    return helper::randomElement(animalDefinition.lions);
}

std::string_view rabbit(Locale locale)
{
    const auto& animalDefinition = getAnimalDefinition(locale);

    return helper::randomElement(animalDefinition.rabbits);
}

std::string_view rodent(Locale locale)
{
    const auto& animalDefinition = getAnimalDefinition(locale);

    return helper::randomElement(animalDefinition.rodents);
}

std::string_view snake(Locale locale)
{
    const auto& animalDefinition = getAnimalDefinition(locale);

    return helper::randomElement(animalDefinition.snakes);
}

std::string_view type(Locale locale)
{
    const auto& animalDefinition = getAnimalDefinition(locale);

    return helper::randomElement(animalDefinition.types);
}
}
