#include "animal_data.h"
#include <faker/animal.h>
#include <faker/helper.h>

namespace faker::animal {
std::string_view bear() { return Helper::arrayElement(data::bears); }

std::string_view bird() { return Helper::arrayElement(data::birds); }

std::string_view cat() { return Helper::arrayElement(data::cats); }

std::string_view cetacean() { return Helper::arrayElement(data::cetaceans); }

std::string_view cow() { return Helper::arrayElement(data::cows); }

std::string_view crocodilia() { return Helper::arrayElement(data::crocodilia); }

std::string_view dog() { return Helper::arrayElement(data::dogs); }

std::string_view fish() { return Helper::arrayElement(data::fishes); }

std::string_view horse() { return Helper::arrayElement(data::horses); }

std::string_view insect() { return Helper::arrayElement(data::insects); }

std::string_view lion() { return Helper::arrayElement(data::lions); }

std::string_view rabbit() { return Helper::arrayElement(data::rabbits); }

std::string_view rodent() { return Helper::arrayElement(data::rodents); }

std::string_view snake() { return Helper::arrayElement(data::snakes); }

std::string_view type() { return Helper::arrayElement(data::types); }
}