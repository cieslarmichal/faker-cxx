#include "faker-cxx/esport.h"

#include <string_view>

#include "esport_data.h"
#include "faker-cxx/helper.h"

namespace faker::esport
{

namespace
{
const struct EsportDefinition& getEsportDefinition(Locale locale)
{
    switch (locale)
    {
    default:
        return enUSEsportDefinition;
    }
}
}

std::string_view player(Locale locale)
{
    const auto& esportDefinition = getEsportDefinition(locale);

    return helper::randomElement(esportDefinition.players);
}

std::string_view team(Locale locale)
{
    const auto& esportDefinition = getEsportDefinition(locale);

    return helper::randomElement(esportDefinition.teams);
}

std::string_view league(Locale locale)
{
    const auto& esportDefinition = getEsportDefinition(locale);

    return helper::randomElement(esportDefinition.leagues);
}

std::string_view event(Locale locale)
{
    const auto& esportDefinition = getEsportDefinition(locale);

    return helper::randomElement(esportDefinition.events);
}

std::string_view game(Locale locale)
{
    const auto& esportDefinition = getEsportDefinition(locale);

    return helper::randomElement(esportDefinition.games);
}
}