#include "../common/random.h"
#include "../common/strings.h"
#include "hacker_data.h"
#include <faker/hacker.h>

namespace faker::hacker {
std::string_view abbreviation() { return random::element(data::abbreviations); }

std::string_view adjective() { return random::element(data::adjectives); }

std::string_view noun() { return random::element(data::nouns); }

std::string_view verb() { return random::element(data::verbs); }

std::string_view ingverb() { return random::element(data::ingverbs); }

std::string phrase()
{
    std::string result;

    for (auto word : utils::split(random::element(data::phrases))) {
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
