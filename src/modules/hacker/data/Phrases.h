#pragma once

#include <string>
#include <vector>

#include "Abbreviations.h"
#include "Adjectives.h"
#include "faker-cxx/Helper.h"
#include "fmt/format.h"
#include "Ingverbs.h"
#include "Nouns.h"
#include "Verbs.h"

namespace faker {
    // use fmt::format() to format each phrase w/ random word
    const std::vector<std::string> phrases = {
            fmt::format("If we {} the {}, we can get to the {} {} through the {} {} {}!", Helper::arrayElement<std::string>(verbs), Helper::arrayElement<std::string>(nouns), Helper::arrayElement<std::string>(abbreviations), Helper::arrayElement<std::string>(nouns), Helper::arrayElement<std::string>(adjectives), Helper::arrayElement<std::string>(abbreviations), Helper::arrayElement<std::string>(nouns)),
            fmt::format("We need to {} the {} {} {}!", Helper::arrayElement<std::string>(verbs), Helper::arrayElement<std::string>(adjectives), Helper::arrayElement<std::string>(abbreviations), Helper::arrayElement<std::string>(nouns)),
            fmt::format("Try to {} the {} {}, maybe it will {} the {} {}!", Helper::arrayElement<std::string>(verbs), Helper::arrayElement<std::string>(abbreviations), Helper::arrayElement<std::string>(nouns), Helper::arrayElement<std::string>(verbs), Helper::arrayElement<std::string>(adjectives), Helper::arrayElement<std::string>(nouns)),
            fmt::format("You can't {} the {} without {} the {} {} {}!", Helper::arrayElement<std::string>(verbs), Helper::arrayElement<std::string>(nouns), Helper::arrayElement<std::string>(ingverbs), Helper::arrayElement<std::string>(adjectives), Helper::arrayElement<std::string>(abbreviations), Helper::arrayElement<std::string>(nouns)),
            fmt::format("Use the {} {} {}, then you can {} the {} {}!", Helper::arrayElement<std::string>(adjectives), Helper::arrayElement<std::string>(abbreviations), Helper::arrayElement<std::string>(nouns), Helper::arrayElement<std::string>(verbs), Helper::arrayElement<std::string>(adjectives), Helper::arrayElement<std::string>(nouns)),
            fmt::format("The {} {} is down, {} the {} {} so we can {} the {} {}!", Helper::arrayElement<std::string>(abbreviations), Helper::arrayElement<std::string>(nouns), Helper::arrayElement<std::string>(verbs), Helper::arrayElement<std::string>(adjectives), Helper::arrayElement<std::string>(nouns), Helper::arrayElement<std::string>(verbs), Helper::arrayElement<std::string>(abbreviations), Helper::arrayElement<std::string>(nouns)),
            fmt::format("{} the {} won't do anything, we need to {} the {} {} {}!", Helper::arrayElement<std::string>(ingverbs), Helper::arrayElement<std::string>(nouns), Helper::arrayElement<std::string>(verbs), Helper::arrayElement<std::string>(adjectives), Helper::arrayElement<std::string>(abbreviations), Helper::arrayElement<std::string>(nouns)),
            fmt::format("I'll {} the {} {} {}, that should {} the {} {}!", Helper::arrayElement<std::string>(verbs), Helper::arrayElement<std::string>(adjectives), Helper::arrayElement<std::string>(abbreviations), Helper::arrayElement<std::string>(nouns), Helper::arrayElement<std::string>(nouns), Helper::arrayElement<std::string>(abbreviations), Helper::arrayElement<std::string>(nouns)),
    };
}