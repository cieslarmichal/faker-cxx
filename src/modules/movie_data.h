#ifndef FAKER_MODULES_MOVIE_DATA_H
#define FAKER_MODULES_MOVIE_DATA_H

#include <array>
#include <string_view>

namespace faker::movie {
extern const std::array<std::string_view, 299> actors;
extern const std::array<std::string_view, 300> actresses;
extern const std::array<std::string_view, 300> directors;
extern const std::array<std::string_view, 9> genres;
extern const std::array<std::string_view, 250> movies;
extern const std::array<std::string_view, 122> tvShows;
}

#endif