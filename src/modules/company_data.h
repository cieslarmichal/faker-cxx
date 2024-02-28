#ifndef FAKER_MODULES_COMPANY_DATA_H
#define FAKER_MODULES_COMPANY_DATA_H

#include <array>
#include <string_view>

namespace faker::company::data {
extern const std::array<std::string_view, 65> buzz_adjectives;
extern const std::array<std::string_view, 40> buzz_nouns;
extern const std::array<std::string_view, 60> buzz_verbs;
extern const std::array<std::string_view, 100> catch_phrase_adjectives;
extern const std::array<std::string_view, 101> catch_phrase_descriptors;
extern const std::array<std::string_view, 104> catch_phrase_nouns;
extern const std::array<std::string_view, 8> company_types;
extern const std::array<std::string_view, 147> company_industries;
extern const std::array<std::string_view, 3> company_suffixes;
}

#endif