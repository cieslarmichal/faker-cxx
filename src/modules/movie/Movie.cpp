#include "faker-cxx/Movie.h"

#include "MovieData.h"
#include "faker-cxx/Helper.h"

namespace faker
{
std::string_view Movie::genre()
{
    return Helper::arrayElement(genres);
}

std::string_view Movie::movieTitle()
{
    return Helper::arrayElement(movies);
}

std::string_view Movie::tvShow()
{
    return Helper::arrayElement(tvShows);
}

std::string_view Movie::director()
{
    return Helper::arrayElement(directors);
}

std::string_view Movie::actor()
{
    return Helper::arrayElement(actors);
}

std::string_view Movie::actress()
{
    return Helper::arrayElement(actresses);
}

}
