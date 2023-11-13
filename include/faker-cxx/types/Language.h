#pragma once

#include <map>
#include <vector>

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
    Hindi,
    Finnish,
    Nepali,
    Spanish,
    Turkish,
    Czech,
    Slovak,
};

const std::vector<Language> languages{Language::English, Language::Polish,  Language::Italian,  Language::French,
                                      Language::German,  Language::Russian, Language::Romanian, Language::Hindi,
                                      Language::Finnish, Language::Nepali,  Language::Spanish,  Language::Turkish,
                                      Language::Czech,   Language::Slovak};

inline std::string toString(Language language)
{
    std::map<Language, std::string> languageToStringMapping{
        {Language::English, "English"},   {Language::Polish, "Polish"},   {Language::Italian, "Italian"},
        {Language::French, "French"},     {Language::German, "German"},   {Language::Russian, "Russian"},
        {Language::Romanian, "Romanian"}, {Language::Hindi, "Hindi"},     {Language::Finnish, "Finnish"},
        {Language::Nepali, "Nepali"},     {Language::Spanish, "Spanish"}, {Language::Turkish, "Turkish"},
        {Language::Czech, "Czech"},       {Language::Slovak, "Slovak"}};

    return languageToStringMapping.at(language);
}

inline std::ostream& operator<<(std::ostream& os, Language language)
{
    return os << toString(language);
}

}
