#include "faker-cxx/animal.h"

#include <string_view>

#include "animal_data.h"
#include "faker-cxx/helper.h"

namespace faker::animal
{
std::string_view bear()
{
    return helper::arrayElement(bears);
}

std::string_view bird()
{
    return helper::arrayElement(birds);
}

std::string_view cat()
{
    return helper::arrayElement(cats);
}

std::string_view cetacean()
{
    return helper::arrayElement(cetaceans);
}

std::string_view cow()
{
    return helper::arrayElement(cows);
}

std::string_view crocodile()
{
    return helper::arrayElement(crocodiles);
}

std::string_view dog()
{
    return helper::arrayElement(dogs);
}

std::string_view fish()
{
    return helper::arrayElement(fishes);
}

std::string_view horse()
{
    return helper::arrayElement(horses);
}

std::string_view insect()
{
    return helper::arrayElement(insects);
}

std::string_view lion()
{
    return helper::arrayElement(lions);
}

std::string_view rabbit()
{
    return helper::arrayElement(rabbits);
}

std::string_view rodent()
{
    return helper::arrayElement(rodents);
}

std::string_view snake()
{
    return helper::arrayElement(snakes);
}

std::string_view type()
{
    return helper::arrayElement(types);
}
}
