#include "faker-cxx/Animal.h"

#include "data/Bears.h"
#include "data/Birds.h"
#include "data/Cats.h"
#include "data/Cetaceans.h"
#include "data/Cows.h"
#include "data/Crocodilia.h"
#include "data/Dogs.h"
#include "data/Fishes.h"
#include "data/Horses.h"
#include "data/Insects.h"
#include "data/Lions.h"
#include "data/Rabbits.h"
#include "data/Rodents.h"
#include "data/Snakes.h"
#include "data/Types.h"
#include "faker-cxx/Helper.h"

namespace faker
{
std::string Animal::bear()
{
    return Helper::arrayElement<std::string>(bears);
}

std::string Animal::bird()
{
    return Helper::arrayElement<std::string>(birds);
}

std::string Animal::cat()
{
    return Helper::arrayElement<std::string>(cats);
}

std::string Animal::cetacean()
{
    return Helper::arrayElement<std::string>(cetaceans);
}

std::string Animal::cow()
{
    return Helper::arrayElement<std::string>(cows);
}

std::string Animal::crocodile()
{
    return Helper::arrayElement<std::string>(faker::crocodilia);
}

std::string Animal::dog()
{
    return Helper::arrayElement<std::string>(dogs);
}

std::string Animal::fish()
{
    return Helper::arrayElement<std::string>(fishes);
}

std::string Animal::horse()
{
    return Helper::arrayElement<std::string>(horses);
}

std::string Animal::insect()
{
    return Helper::arrayElement<std::string>(insects);
}

std::string Animal::lion()
{
    return Helper::arrayElement<std::string>(lions);
}

std::string Animal::rabbit()
{
    return Helper::arrayElement<std::string>(rabbits);
}

std::string Animal::rodent()
{
    return Helper::arrayElement<std::string>(rodents);
}

std::string Animal::snake()
{
    return Helper::arrayElement<std::string>(snakes);
}

std::string Animal::type()
{
    return Helper::arrayElement<std::string>(types);
}
}
