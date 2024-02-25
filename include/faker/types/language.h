#pragma once

#include <string_view>

namespace faker {

enum class Language {
    English,
    Polish,
    French,
    German,
    Italian,
    Russian,
    Romanian,
    Hindi,
    Finnish,
    Nepali,
    Spanish,
    Turkish,
    Czech,
    Slovak,
    Ukrainian,
    Danish,
    Swedish,
    Portuguese,
    Norwegian,
    Japanese,
    Hungarian,
    Croatian,
    Greek,
    Slovene,
    Dutch,
    Mandarin,
    Korean,
    Serbian,
    Macedonian,
    Albanian,
    Latvian,
    Irish,
    Belarusian,
    Estonian
};

std::string_view toString(Language language);

}
