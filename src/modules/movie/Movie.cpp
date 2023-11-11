#include "faker-cxx/Movie.h"

#include "data/Actors.h"
#include "data/Actresses.h"
#include "data/Directors.h"
#include "data/Genres.h"
#include "data/Movies.h"
#include "data/TvShows.h"
#include "faker-cxx/Helper.h"

namespace faker
{
std::string Movie::genre()
{
    return Helper::arrayElement<std::string>(genres);
}

std::string Movie::movieTitle()
{
    return Helper::arrayElement<std::string>(movies);
}

std::string Movie::tvShow()
{
    return Helper::arrayElement<std::string>(tvShows);
}

std::string Movie::director()
{
    return Helper::arrayElement<std::string>(directors);
}

std::string Movie::actor()
{
    return Helper::arrayElement<std::string>(actors);
}

std::string Movie::actress()
{
    return Helper::arrayElement<std::string>(actresses);
}

}
