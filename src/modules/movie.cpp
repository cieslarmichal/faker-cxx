#include "../common/helper.h"
#include "movie_data.h"
#include <faker/movie.h>

namespace faker::movie {
std::string_view genre() { return Helper::arrayElement(data::genres); }

std::string_view movieTitle() { return Helper::arrayElement(data::movies); }

std::string_view tvShow() { return Helper::arrayElement(data::tvShows); }

std::string_view director() { return Helper::arrayElement(data::directors); }

std::string_view actor() { return Helper::arrayElement(data::actors); }

std::string_view actress() { return Helper::arrayElement(data::actresses); }

}
