#include "faker-cxx/sport.h"

#include <string_view>

#include "faker-cxx/helper.h"
#include "sport_data.h"

namespace faker::sport
{
std::string_view sportName(Locale locale)
{
    auto localeLocal = locale;    
    if (sportMapSpan.find(locale) == sportMapSpan.end())
    {
        localeLocal = Locale::en_US;
    }
    return helper::randomElement((sportMapSpan.at(localeLocal)).sportNames);
}

std::string_view soccerTeam(Locale locale)
{
    auto localeLocal = locale;    
    if (sportMapSpan.find(locale) == sportMapSpan.end())
    {
        localeLocal = Locale::en_US;
    }
    return helper::randomElement((sportMapSpan.at(localeLocal)).soccerTeams);
}

std::string_view maleAthlete(Locale locale)
{
    auto localeLocal = locale;    
    if (sportMapSpan.find(locale) == sportMapSpan.end())
    {
        localeLocal = Locale::en_US;
    }
    return helper::randomElement((sportMapSpan.at(localeLocal)).maleAthletes);
}

std::string_view femaleAthlete(Locale locale)
{
    auto localeLocal = locale;    
    if (sportMapSpan.find(locale) == sportMapSpan.end())
    {
        localeLocal = Locale::en_US;
    }
    return helper::randomElement((sportMapSpan.at(localeLocal)).femaleAthletes);
}

std::string_view sportEvent(Locale locale)
{
    auto localeLocal = locale;    
    if (sportMapSpan.find(locale) == sportMapSpan.end())
    {
        localeLocal = Locale::en_US;
    }
    return helper::randomElement((sportMapSpan.at(localeLocal)).sportEvents);
}
}
