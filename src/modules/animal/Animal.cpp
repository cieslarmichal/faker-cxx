#include "faker-cxx/Animal.h"

#include <string_view>

#include "AnimalData.h"
#include "faker-cxx/Helper.h"

namespace faker
{
std::string_view Animal::bear()
{
    return Helper::arrayElement(bears);
}

std::string_view Animal::bird()
{
    return Helper::arrayElement(birds);
}

std::string_view Animal::cat()
{
    return Helper::arrayElement(cats);
}

std::string_view Animal::cetacean()
{
    return Helper::arrayElement(cetaceans);
}

std::string_view Animal::cow()
{
    return Helper::arrayElement(cows);
}

std::string_view Animal::crocodile()
{
    return Helper::arrayElement(faker::crocodiles);
}

std::string_view Animal::dog()
{
    return Helper::arrayElement(dogs);
}

std::string_view Animal::fish()
{
    return Helper::arrayElement(fishes);
}

std::string_view Animal::horse()
{
    return Helper::arrayElement(horses);
}

std::string_view Animal::insect()
{
    return Helper::arrayElement(insects);
}

std::string_view Animal::lion()
{
    return Helper::arrayElement(lions);
}

std::string_view Animal::rabbit()
{
    return Helper::arrayElement(rabbits);
}

std::string_view Animal::rodent()
{
    return Helper::arrayElement(rodents);
}

std::string_view Animal::snake()
{
    return Helper::arrayElement(snakes);
}

std::string_view Animal::type()
{
    return Helper::arrayElement(types);
}
}
