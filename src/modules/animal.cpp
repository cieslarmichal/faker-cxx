#include "../common/random.h"
#include "animal_data.h"
#include <faker/animal.h>

namespace faker::animal {
std::string_view bear() { return random::element(data::bears); }

std::string_view bird() { return random::element(data::birds); }

std::string_view cat() { return random::element(data::cats); }

std::string_view cetacean() { return random::element(data::cetaceans); }

std::string_view cow() { return random::element(data::cows); }

std::string_view crocodilia() { return random::element(data::crocodilia); }

std::string_view dog() { return random::element(data::dogs); }

std::string_view fish() { return random::element(data::fishes); }

std::string_view horse() { return random::element(data::horses); }

std::string_view insect() { return random::element(data::insects); }

std::string_view lion() { return random::element(data::lions); }

std::string_view rabbit() { return random::element(data::rabbits); }

std::string_view rodent() { return random::element(data::rodents); }

std::string_view snake() { return random::element(data::snakes); }

std::string_view type() { return random::element(data::types); }
}