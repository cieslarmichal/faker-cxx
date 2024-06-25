#include "faker-cxx/Movie.h"

#include <string_view>

#include "faker-cxx/Helper.h"
#include "MovieData.h"

namespace faker::movie
{
std::string_view genre()
{
    return Helper::arrayElement(movieGenres);
}

std::string_view movieTitle()
{
    return Helper::arrayElement(movies);
}

std::string_view tvShow()
{
    return Helper::arrayElement(tvShows);
}

std::string_view director()
{
    return Helper::arrayElement(directors);
}

std::string_view actor()
{
    return Helper::arrayElement(actors);
}

std::string_view actress()
{
    return Helper::arrayElement(actresses);
}

}
