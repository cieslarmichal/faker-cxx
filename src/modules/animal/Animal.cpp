#include "faker-cxx/Animal.h"

#include <string_view>

#include "AnimalData.h"
#include "faker-cxx/Helper.h"

namespace faker::animal
{
std::string_view bear()
{
    return Helper::arrayElement(bears);
}

std::string_view bird()
{
    return Helper::arrayElement(birds);
}

std::string_view cat()
{
    return Helper::arrayElement(cats);
}

std::string_view cetacean()
{
    return Helper::arrayElement(cetaceans);
}

std::string_view cow()
{
    return Helper::arrayElement(cows);
}

std::string_view crocodile()
{
    return Helper::arrayElement(crocodiles);
}

std::string_view dog()
{
    return Helper::arrayElement(dogs);
}

std::string_view fish()
{
    return Helper::arrayElement(fishes);
}

std::string_view horse()
{
    return Helper::arrayElement(horses);
}

std::string_view insect()
{
    return Helper::arrayElement(insects);
}

std::string_view lion()
{
    return Helper::arrayElement(lions);
}

std::string_view rabbit()
{
    return Helper::arrayElement(rabbits);
}

std::string_view rodent()
{
    return Helper::arrayElement(rodents);
}

std::string_view snake()
{
    return Helper::arrayElement(snakes);
}

std::string_view type()
{
    return Helper::arrayElement(types);
}
}
