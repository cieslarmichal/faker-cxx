#include "../common/helper.h"
#include "../common/string_helper.h"
#include "hacker_data.h"
#include <faker/hacker.h>

namespace faker::hacker {
std::string_view abbreviation() { return Helper::arrayElement(data::abbreviations); }

std::string_view adjective() { return Helper::arrayElement(data::adjectives); }

std::string_view noun() { return Helper::arrayElement(data::nouns); }

std::string_view verb() { return Helper::arrayElement(data::verbs); }

std::string_view ingverb() { return Helper::arrayElement(data::ingverbs); }

std::string phrase()
{
    std::string result;

    for (auto word : utils::split(Helper::arrayElement(data::phrases))) {
        auto tok = utils::remove_punctuation(word);
        if (tok == "{abbreviation}") {
            tok = abbreviation();
        } else if (tok == "{adjective}") {
            tok = adjective();
        } else if (tok == "{noun}") {
            tok = noun();
        } else if (tok == "{verb}") {
            tok = verb();
        } else if (tok == "{ingverb}") {
            tok = ingverb();
        }
        result += tok;
        result += ' ';
    }

    return result;
}
}
