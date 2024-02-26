#include "../common/string_helper.h"
#include "hacker_data.h"
#include <faker/hacker.h>
#include <faker/helper.h>

namespace faker::hacker {
std::string_view abbreviation() { return Helper::arrayElement(data::abbreviations); }

std::string_view adjective() { return Helper::arrayElement(data::adjectives); }

std::string_view noun() { return Helper::arrayElement(data::nouns); }

std::string_view verb() { return Helper::arrayElement(data::verbs); }

std::string_view ingverb() { return Helper::arrayElement(data::ingverbs); }

std::string phrase()
{
    auto splitRandomPhrase = StringHelper::split(std::string(Helper::arrayElement(data::phrases)));
    std::string ret;

    for (auto& word : splitRandomPhrase) {
        word = StringHelper::removePunctuation(word);
        if (word == "{abbreviation}") {
            word = abbreviation();
        } else if (word == "{adjective}") {
            word = adjective();
        } else if (word == "{noun}") {
            word = noun();
        } else if (word == "{verb}") {
            word = verb();
        } else if (word == "{ingverb}") {
            word = ingverb();
        }

        ret += word + " ";
    }

    return ret;
}
}
