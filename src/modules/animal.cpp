#include "faker-cxx/animal.h"

#include <string_view>

#include "animal_data.h"
#include "faker-cxx/helper.h"

namespace faker::animal
{
std::string_view bear()
{
    return helper::randomElement(bears);
}

std::string_view bird()
{
    return helper::randomElement(birds);
}

std::string_view cat()
{
    return helper::randomElement(cats);
}

std::string_view cetacean()
{
    return helper::randomElement(cetaceans);
}

std::string_view cow()
{
    return helper::randomElement(cows);
}

std::string_view crocodile()
{
    return helper::randomElement(crocodiles);
}

std::string_view dog()
{
    return helper::randomElement(dogs);
}

std::string_view fish()
{
    return helper::randomElement(fishes);
}

std::string_view horse()
{
    return helper::randomElement(horses);
}

std::string_view insect()
{
    return helper::randomElement(insects);
}

std::string_view lion()
{
    return helper::randomElement(lions);
}

std::string_view rabbit()
{
    return helper::randomElement(rabbits);
}

std::string_view rodent()
{
    return helper::randomElement(rodents);
}

std::string_view snake()
{
    return helper::randomElement(snakes);
}

std::string_view type()
{
    return helper::randomElement(types);
}
}
