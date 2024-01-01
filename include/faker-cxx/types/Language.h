#pragma once

#include <map>
#include <vector>

namespace faker
{

enum class Language
{
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

inline std::string toString(Language language)
{
    static const std::map<Language, std::string> languageToStringMapping{
        {Language::English, "English"},     {Language::Polish, "Polish"},         {Language::Italian, "Italian"},
        {Language::French, "French"},       {Language::German, "German"},         {Language::Russian, "Russian"},
        {Language::Romanian, "Romanian"},   {Language::Hindi, "Hindi"},           {Language::Finnish, "Finnish"},
        {Language::Nepali, "Nepali"},       {Language::Spanish, "Spanish"},       {Language::Turkish, "Turkish"},
        {Language::Czech, "Czech"},         {Language::Slovak, "Slovak"},         {Language::Ukrainian, "Ukrainian"},
        {Language::Danish, "Danish"},       {Language::Swedish, "Swedish"},       {Language::Portuguese, "Portuguese"},
        {Language::Norwegian, "Norwegian"}, {Language::Japanese, "Japanese"},     {Language::Hungarian, "Hungarian"},
        {Language::Croatian, "Croatian"},   {Language::Greek, "Greek"},           {Language::Slovene, "Slovene"},
        {Language::Dutch, "Dutch"},         {Language::Mandarin, "Mandarin"},     {Language::Korean, "Korean"},
        {Language::Serbian, "Serbian"},     {Language::Macedonian, "Macedonian"}, {Language::Albanian, "Albanian"},
        {Language::Latvian, "Latvian"},     {Language::Irish, "Irish"},           {Language::Belarusian, "Belarusian"},
        {Language::Estonian, "Estonian"}};

    return languageToStringMapping.at(language);
}

inline std::ostream& operator<<(std::ostream& os, Language language)
{
    return os << toString(language);
}

}