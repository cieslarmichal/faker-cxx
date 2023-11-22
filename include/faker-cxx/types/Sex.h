#pragma once

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
};

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
    return "Unknown"; // Default or throw exception
}

inline std::string toString(Sex sex, Language language = Language::English)
{
    return translateSex(sex, language);
}

// inline std::string toString(Sex sex,const std::string& language = "English")
//{
//     std::map<Sex, std::string> sexToStringMapping{{Sex::Male, "Male"}, {Sex::Female, "Female"}};
//
//     return sexToStringMapping.at(sex);
// }

inline std::ostream& operator<<(std::ostream& os, Sex sex)
{
    return os << toString(sex);
}
}
