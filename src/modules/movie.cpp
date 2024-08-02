#include "faker-cxx/movie.h"

#include <string_view>

#include "faker-cxx/helper.h"
#include "movie_data.h"

namespace faker::movie
{
std::string_view genre()
{
    return helper::randomElement(movieGenres);
}

std::string_view movieTitle()
{
    return helper::randomElement(movies);
}

std::string_view tvShow()
{
    return helper::randomElement(tvShows);
}

std::string_view director()
{
    return helper::randomElement(directors);
}

std::string_view actor()
{
    return helper::randomElement(actors);
}

std::string_view actress()
{
    return helper::randomElement(actresses);
}

}
