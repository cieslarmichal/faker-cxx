#include "faker-cxx/Hacker.h"

#include <string>

#include "data/Abbreviations.h"
#include "data/Adjectives.h"
#include "data/Ingverbs.h"
#include "data/Nouns.h"
#include "data/Phrases.h"
#include "data/Verbs.h"

namespace faker {
std::string Hacker::abbreviation() {
    return faker::Helper::arrayElement<std::string>(faker::abbreviations);
}

std::string Hacker::adjective() {
    return faker::Helper::arrayElement<std::string>(faker::adjectives);
}

std::string Hacker::noun() {
    return faker::Helper::arrayElement<std::string>(faker::nouns);
}

std::string Hacker::verb() {
    return faker::Helper::arrayElement<std::string>(faker::verbs);
}

std::string Hacker::ingverb() {
    return faker::Helper::arrayElement<std::string>(faker::ingverbs);
}

std::string Hacker::phrase() {
    return faker::Helper::arrayElement<std::string>(faker::phrases);
}
}
