#include "faker-cxx/esport.h"

#include <string_view>

#include "esport_data.h"
#include "faker-cxx/helper.h"

namespace faker::esport
{
std::string_view player()
{
    return helper::randomElement(players);
}

std::string_view team()
{
    return helper::randomElement(teams);
}

std::string_view league()
{
    return helper::randomElement(leagues);
}

std::string_view event()
{
    return helper::randomElement(events);
}

std::string_view game()
{
    return helper::randomElement(games);
}

}