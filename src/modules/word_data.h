#ifndef FAKER_MODULES_WORD_DATA_H
#define FAKER_MODULES_WORD_DATA_H

#include <array>
#include <string_view>

namespace faker::word::data {
extern const std::array<std::string_view, 1328> adjectives;
extern const std::array<std::string_view, 325> adverbs;
extern const std::array<std::string_view, 51> conjunctions;
extern const std::array<std::string_view, 46> interjections;
extern const std::array<std::string_view, 6659> nouns;
extern const std::array<std::string_view, 109> prepositions;
extern const std::array<std::string_view, 5910> verbs;
}

#endif