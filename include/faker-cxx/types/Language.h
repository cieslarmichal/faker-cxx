#pragma once

#include <map>

namespace faker
{
enum class Language
{
    English,
    Polish,
    Italian,
    French,
    German,
    Russian,
    Romanian,
};

inline std::string toString(Language language)
{
    std::map<Language, std::string> languageToStringMapping{
        {Language::English, "English"},  {Language::Polish, "Polish"}, {Language::Italian, "Italian"},
        {Language::French, "French"},    {Language::German, "German"}, {Language::Russian, "Russian"},
        {Language::Romanian, "Romanian"}};

    return languageToStringMapping.at(language);
}

inline std::ostream& operator<<(std::ostream& os, Language language)
{
    return os << toString(language);
}

}
