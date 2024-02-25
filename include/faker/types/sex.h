#pragma once

#include <faker/types/language.h>
#include <string_view>
#include <unordered_map>

namespace faker {
enum class Sex {
    Male,
    Female,
};

extern const std::unordered_map<Language, std::unordered_map<Sex, std::string_view>>
    sexTranslations;

std::string_view translateSex(Sex sex, Language language = Language::English);

inline std::string_view toString(Sex sex, Language language = Language::English)
{
    return translateSex(sex, language);
}

}
