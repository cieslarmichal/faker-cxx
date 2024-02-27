#include "../common/random.h"
#include "movie_data.h"
#include <faker/movie.h>

namespace faker::movie {
std::string_view genre() { return random::element(data::genres); }

std::string_view movie_title() { return random::element(data::movies); }

std::string_view tv_show() { return random::element(data::tvShows); }

std::string_view director() { return random::element(data::directors); }

std::string_view actor() { return random::element(data::actors); }

std::string_view actress() { return random::element(data::actresses); }

}
