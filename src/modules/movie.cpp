#include "movie_data.h"
#include <faker/helper.h>
#include <faker/movie.h>

namespace faker::movie {
std::string_view genre() { return Helper::arrayElement(genres); }

std::string_view movieTitle() { return Helper::arrayElement(movies); }

std::string_view tvShow() { return Helper::arrayElement(tvShows); }

std::string_view director() { return Helper::arrayElement(directors); }

std::string_view actor() { return Helper::arrayElement(actors); }

std::string_view actress() { return Helper::arrayElement(actresses); }

}
