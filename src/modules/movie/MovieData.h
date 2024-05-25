#pragma once

#include <array>
#include <string_view>

#include "faker-cxx/Movie.h"

namespace faker
{
extern const std::array<std::string_view, 299> actors;
extern const std::array<std::string_view, 300> actresses;
extern const std::array<std::string_view, 300> directors;
extern const std::array<std::string_view, 9> movieGenres;
extern const std::array<std::string_view, 250> movies;
extern const std::array<std::string_view, 122> tvShows;
}
