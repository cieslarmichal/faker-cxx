#include "faker-cxx/Movie.h"

#include <string_view>

#include "faker-cxx/Helper.h"
#include "MovieData.h"

namespace faker::movie
{
std::string_view genre()
{
    return helper::arrayElement(movieGenres);
}

std::string_view movieTitle()
{
    return helper::arrayElement(movies);
}

std::string_view tvShow()
{
    return helper::arrayElement(tvShows);
}

std::string_view director()
{
    return helper::arrayElement(directors);
}

std::string_view actor()
{
    return helper::arrayElement(actors);
}

std::string_view actress()
{
    return helper::arrayElement(actresses);
}

}
