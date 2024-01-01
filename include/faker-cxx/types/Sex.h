#pragma once

#include "Language.h"

namespace faker
{
enum class Sex
{
    Male,
    Female,
};

const std::map<Language, std::map<Sex, std::string>> sexTranslations = {
    {Language::English, {{Sex::Male, "Male"}, {Sex::Female, "Female"}}},
    {Language::Polish, {{Sex::Male, "Mężczyzna"}, {Sex::Female, "Kobieta"}}},
    {Language::Italian, {{Sex::Male, "Maschio"}, {Sex::Female, "Femmina"}}},
    {Language::French, {{Sex::Male, "Homme"}, {Sex::Female, "Femme"}}},
    {Language::German, {{Sex::Male, "Mann"}, {Sex::Female, "Frau"}}},
    {Language::Russian, {{Sex::Male, "Мужчина"}, {Sex::Female, "Женщина"}}},
    {Language::Romanian, {{Sex::Male, "Bărbat"}, {Sex::Female, "Femeie"}}},
    {Language::Hindi, {{Sex::Male, "पुरुष"}, {Sex::Female, "महिला"}}},
    {Language::Finnish, {{Sex::Male, "Mies"}, {Sex::Female, "Nainen"}}},
    {Language::Nepali, {{Sex::Male, "पुरुष"}, {Sex::Female, "महिला"}}},
    {Language::Spanish, {{Sex::Male, "Hombre"}, {Sex::Female, "Mujer"}}},
    {Language::Turkish, {{Sex::Male, "Erkek"}, {Sex::Female, "Kadın"}}},
    {Language::Czech, {{Sex::Male, "Muž"}, {Sex::Female, "Žena"}}},
    {Language::Slovak, {{Sex::Male, "Muž"}, {Sex::Female, "Žena"}}},
    {Language::Ukrainian, {{Sex::Male, "Чоловік"}, {Sex::Female, "Жінка"}}},
    {Language::Danish, {{Sex::Male, "Mand"}, {Sex::Female, "Kvinde"}}},
    {Language::Swedish, {{Sex::Male, "Man"}, {Sex::Female, "Kvinna"}}},
    {Language::Portuguese, {{Sex::Male, "Homem"}, {Sex::Female, "Mulher"}}},
    {Language::Norwegian, {{Sex::Male, "Mann"}, {Sex::Female, "Kvinne"}}},
    {Language::Japanese, {{Sex::Male, "男性"}, {Sex::Female, "女性"}}},
    {Language::Hungarian, {{Sex::Male, "Férfi"}, {Sex::Female, "Nő"}}},
    {Language::Croatian, {{Sex::Male, "Muškarac"}, {Sex::Female, "Žena"}}},
    {Language::Greek, {{Sex::Male, "Άνδρας"}, {Sex::Female, "Γυναίκα"}}},
    {Language::Slovene, {{Sex::Male, "Moški"}, {Sex::Female, "Ženska"}}},
    {Language::Dutch, {{Sex::Male, "Man"}, {Sex::Female, "Vrouw"}}},
    {Language::Mandarin, {{Sex::Male, "男"}, {Sex::Female, "女"}}},
    {Language::Korean, {{Sex::Male, "남자"}, {Sex::Female, "여자"}}},
    {Language::Serbian, {{Sex::Male, "Мушкарац"}, {Sex::Female, "Жена"}}},
    {Language::Macedonian, {{Sex::Male, "Маж"}, {Sex::Female, "Жена"}}},
    {Language::Albanian, {{Sex::Male, "Mashkull"}, {Sex::Female, "Femër"}}},
    {Language::Latvian, {{Sex::Male, "Vīrietis"}, {Sex::Female, "Sieviete"}}},
    {Language::Belarusian, {{Sex::Male, "Мужчына"}, {Sex::Female, "Жанчына"}}},
    {Language::Estonian, {{Sex::Male, "Mees"}, {Sex::Female, "Naine"}}},
    {Language::Irish, {{Sex::Male, "fireannach"}, {Sex::Female, "baineann"}}}};

inline std::string translateSex(Sex sex, Language language = Language::English)
{
    auto langItr = sexTranslations.find(language);
    if (langItr != sexTranslations.end())
    {
        auto sexItr = langItr->second.find(sex);
        if (sexItr != langItr->second.end())
        {
            return sexItr->second;
        }
    }
    return "Unknown";
}

inline std::string toString(Sex sex, Language language = Language::English)
{
    return translateSex(sex, language);
}

inline std::ostream& operator<<(std::ostream& os, Sex sex)
{
    return os << toString(sex);
}
}
