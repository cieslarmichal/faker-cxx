#include "faker-cxx/Person.h"

#include <map>
#include <regex>
#include <set>

#include "../../common/FormatHelper.h"
#include "data/argentina/ArgentinianPeopleNames.h"
#include "data/australia/AustralianPeopleNames.h"
#include "data/austria/AustrianPeopleNames.h"
#include "data/belgium/BelgianPeopleNames.h"
#include "data/brazil/BrazilianPeopleNames.h"
#include "data/canada/CanadianPeopleNames.h"
#include "data/china/ChinesePeopleNames.h"
#include "data/croatia/CroatianPeopleNames.h"
#include "data/czech/CzechPeopleNames.h"
#include "data/denmark/DanishPeopleNames.h"
#include "data/england/EnglishPeopleNames.h"
#include "data/finland/FinnishPeopleNames.h"
#include "data/france/FrenchPeopleNames.h"
#include "data/Gender.h"
#include "data/germany/GermanPeopleNames.h"
#include "data/greece/GreekPeopleNames.h"
#include "data/Hobbies.h"
#include "data/hungary/HungarianPeopleNames.h"
#include "data/india/IndianPeopleNames.h"
#include "data/ireland/IrishPeopleNames.h"
#include "data/italy/ItalianPeopleNames.h"
#include "data/japan/JapanesePeopleNames.h"
#include "data/JobTitles.h"
#include "data/korea/KoreanPeopleNames.h"
#include "data/Languages.h"
#include "data/latvia/LatvianPeopleNames.h"
#include "data/macedonia/MacedonianPeopleNames.h"
#include "data/mexico/MexicanPeopleNames.h"
#include "data/Nationalities.h"
#include "data/nederlands/DutchPeopleNames.h"
#include "data/nepal/NepalesePeopleNames.h"
#include "data/norway/NorwegianPeopleNames.h"
#include "data/poland/PolishPeopleNames.h"
#include "data/portugal/PortuguesePeopleNames.h"
#include "data/romania/RomanianPeopleNames.h"
#include "data/russia/RussianPeopleNames.h"
#include "data/serbia/SerbianPeopleNames.h"
#include "data/slovakia/SlovakPeopleNames.h"
#include "data/slovenia/SlovenianPeopleNames.h"
#include "data/spain/SpanishPeopleNames.h"
#include "data/sweden/SwedishPeopleNames.h"
#include "data/switzerland/SwissPeopleNames.h"
#include "data/turkey/TurkishPeopleNames.h"
#include "data/ukraine/UkrainianPeopleNames.h"
#include "data/usa/UsaPeopleNames.h"
#include "data/ZodiacSigns.h"
#include "faker-cxx/Helper.h"
#include "fmt/format.h"

namespace faker
{
namespace
{
const std::vector<std::string> sexes{"Male", "Female"};

const std::map<Country, PeopleNames> countryToPeopleNamesMapping{
    {Country::England, englishPeopleNames},       {Country::France, frenchPeopleNames},
    {Country::Germany, germanPeopleNames},        {Country::Italy, italianPeopleNames},
    {Country::Poland, polishPeopleNames},         {Country::Russia, russianPeopleNames},
    {Country::Romania, romanianPeopleNames},      {Country::India, indianPeopleNames},
    {Country::Finland, finnishPeopleNames},       {Country::Nepal, nepalesePeopleNames},
    {Country::Spain, spanishPeopleNames},         {Country::Turkey, turkishPeopleNames},
    {Country::Czech, czechPeopleNames},           {Country::Slovakia, slovakPeopleNames},
    {Country::Ukraine, ukrainianPeopleNames},     {Country::Denmark, danishPeopleNames},
    {Country::Sweden, swedishPeopleNames},        {Country::Usa, usaPeopleNames},
    {Country::Brazil, brazilianPeopleNames},      {Country::Norway, norwegianPeopleNames},
    {Country::Japan, japanesePeopleNames},        {Country::Portugal, portuguesePeopleNames},
    {Country::Hungary, hungarianPeopleNames},     {Country::Croatia, croatianPeopleNames},
    {Country::Greece, greekPeopleNames},          {Country::Slovenia, slovenianPeopleNames},
    {Country::Austria, austrianPeopleNames},      {Country::Switzerland, swissPeopleNames},
    {Country::Belgium, belgianPeopleNames},       {Country::Nederlands, dutchPeopleNames},
    {Country::China, chinesePeopleNames},         {Country::Korea, koreanPeopleNames},
    {Country::Canada, canadianPeopleNames},       {Country::Mexico, mexicanPeopleNames},
    {Country::Argentina, argentinianPeopleNames}, {Country::Australia, australianPeopleNames},
    {Country::Serbia, serbianPeopleNames},        {Country::Macedonia, macedonianPeopleNames},
    {Country::Latvia, latvianPeopleNames},        {Country::Ireland, irishPeopleNames},
};

std::string middleNameForCountry(Country country, std::optional<Sex> sex);
std::string prefixForCountry(Country country, std::optional<Sex> sex);
std::string suffixForCountry(Country country, std::optional<Sex> sex);
}

std::string Person::firstName(Country country, std::optional<Sex> sex)
{
    const auto& peopleNames = countryToPeopleNamesMapping.at(country);

    std::vector<std::string> firstNames;

    if (sex == Sex::Male)
    {
        const auto& malesFirstNames = peopleNames.malesNames.firstNames;

        firstNames.insert(firstNames.end(), malesFirstNames.begin(), malesFirstNames.end());
    }
    else if (sex == Sex::Female)
    {
        const auto& femalesFirstNames = peopleNames.femalesNames.firstNames;

        firstNames.insert(firstNames.end(), femalesFirstNames.begin(), femalesFirstNames.end());
    }
    else
    {
        const auto& malesFirstNames = peopleNames.malesNames.firstNames;
        const auto& femalesFirstNames = peopleNames.femalesNames.firstNames;

        firstNames.insert(firstNames.end(), malesFirstNames.begin(), malesFirstNames.end());
        firstNames.insert(firstNames.end(), femalesFirstNames.begin(), femalesFirstNames.end());
    }

    return Helper::arrayElement<std::string>(firstNames);
}

std::string Person::lastName(Country country, std::optional<Sex> sex)
{
    const auto& peopleNames = countryToPeopleNamesMapping.at(country);

    std::vector<std::string> lastNames;

    if (sex == Sex::Male)
    {
        const auto& malesLastNames = peopleNames.malesNames.lastNames;

        lastNames.insert(lastNames.end(), malesLastNames.begin(), malesLastNames.end());
    }
    else if (sex == Sex::Female)
    {
        const auto& femalesLastNames = peopleNames.femalesNames.lastNames;

        lastNames.insert(lastNames.end(), femalesLastNames.begin(), femalesLastNames.end());
    }
    else
    {
        const auto& malesLastNames = peopleNames.malesNames.lastNames;
        const auto& femalesLastNames = peopleNames.femalesNames.lastNames;

        lastNames.insert(lastNames.end(), malesLastNames.begin(), malesLastNames.end());
        lastNames.insert(lastNames.end(), femalesLastNames.begin(), femalesLastNames.end());
    }

    return Helper::arrayElement<std::string>(lastNames);
}

std::string Person::middleName(std::optional<Sex> sex)
{
    std::vector<std::string> allMiddleNames;

    for (const auto& [_, peopleNames] : countryToPeopleNamesMapping)
    {
        std::vector<std::string> middleNames;

        if (sex == Sex::Male)
        {
            const auto& malesMiddleNames = peopleNames.malesNames.middleNames;

            middleNames.insert(middleNames.end(), malesMiddleNames.begin(), malesMiddleNames.end());
        }
        else if (sex == Sex::Female)
        {
            const auto& femalesMiddleNames = peopleNames.femalesNames.middleNames;

            middleNames.insert(middleNames.end(), femalesMiddleNames.begin(), femalesMiddleNames.end());
        }
        else
        {
            const auto& malesMiddleNames = peopleNames.malesNames.middleNames;
            const auto& femalesMiddleNames = peopleNames.femalesNames.middleNames;

            middleNames.insert(middleNames.end(), malesMiddleNames.begin(), malesMiddleNames.end());
            middleNames.insert(middleNames.end(), femalesMiddleNames.begin(), femalesMiddleNames.end());
        }

        std::set<std::string> uniqueMiddleNames(middleNames.begin(), middleNames.end());

        middleNames.assign(uniqueMiddleNames.begin(), uniqueMiddleNames.end());

        allMiddleNames.insert(allMiddleNames.end(), middleNames.begin(), middleNames.end());
    }

    if (allMiddleNames.empty())
    {
        throw std::runtime_error{fmt::format("No middle name fround, sex: {}.", sex ? toString(*sex) : "none")};
    }

    return Helper::arrayElement<std::string>(allMiddleNames);
}

std::string Person::fullName(Country country, std::optional<Sex> sex)
{
    const auto& peopleNames = countryToPeopleNamesMapping.at(country);

    std::vector<Helper::WeightedElement<std::string>> weightedElements;

    for (const auto& nameFormat : peopleNames.nameFormats)
    {
        weightedElements.push_back({nameFormat.weight, nameFormat.format});
    }

    const auto nameFormat = Helper::weightedArrayElement<std::string>(weightedElements);

    const auto dataGeneratorsMapping = std::map<std::string, std::function<std::string()>>{
        {"firstName", [&country, &sex]() { return firstName(country, sex); }},
        {"middleName", [&country, &sex]() { return middleNameForCountry(country, sex); }},
        {"lastName", [&country, &sex]() { return lastName(country, sex); }},
        {"prefix", [&country, &sex]() { return prefixForCountry(country, sex); }},
        {"suffix", [&country, &sex]() { return suffixForCountry(country, sex); }}};

    return FormatHelper::fillTokenValues(nameFormat, dataGeneratorsMapping);
}

std::string Person::prefix(std::optional<Sex> sex)
{
    std::vector<std::string> allPrefixes;

    for (const auto& [_, peopleNames] : countryToPeopleNamesMapping)
    {
        std::vector<std::string> prefixes;

        if (sex == Sex::Male)
        {
            const auto& malesPrefixes = peopleNames.malesNames.prefixes;

            prefixes.insert(prefixes.end(), malesPrefixes.begin(), malesPrefixes.end());
        }
        else if (sex == Sex::Female)
        {
            const auto& femalesPrefixes = peopleNames.femalesNames.prefixes;

            prefixes.insert(prefixes.end(), femalesPrefixes.begin(), femalesPrefixes.end());
        }
        else
        {
            const auto& malesPrefixes = peopleNames.malesNames.prefixes;
            const auto& femalesPrefixes = peopleNames.femalesNames.prefixes;

            prefixes.insert(prefixes.end(), malesPrefixes.begin(), malesPrefixes.end());
            prefixes.insert(prefixes.end(), femalesPrefixes.begin(), femalesPrefixes.end());
        }

        std::set<std::string> uniquePrefixes(prefixes.begin(), prefixes.end());

        prefixes.assign(uniquePrefixes.begin(), uniquePrefixes.end());

        allPrefixes.insert(allPrefixes.end(), prefixes.begin(), prefixes.end());
    }

    if (allPrefixes.empty())
    {
        throw std::runtime_error{fmt::format("No prefixes fround, sex: {}.", sex ? toString(*sex) : "none")};
    }

    return Helper::arrayElement<std::string>(allPrefixes);
}

std::string Person::suffix()
{
    std::vector<std::string> allSuffixes;

    for (const auto& [_, peopleNames] : countryToPeopleNamesMapping)
    {
        std::vector<std::string> suffixes;

        const auto& malesSuffixes = peopleNames.malesNames.suffixes;
        const auto& femalesSuffixes = peopleNames.femalesNames.suffixes;

        suffixes.insert(suffixes.end(), malesSuffixes.begin(), malesSuffixes.end());
        suffixes.insert(suffixes.end(), femalesSuffixes.begin(), femalesSuffixes.end());

        std::set<std::string> uniqueSuffixes(suffixes.begin(), suffixes.end());

        suffixes.assign(uniqueSuffixes.begin(), uniqueSuffixes.end());

        allSuffixes.insert(allSuffixes.end(), suffixes.begin(), suffixes.end());
    }

    return Helper::arrayElement<std::string>(allSuffixes);
}

std::string Person::sex()
{
    return Helper::arrayElement<std::string>(sexes);
}

std::string Person::gender()
{
    return Helper::arrayElement<std::string>(genders);
}

std::string Person::jobTitle()
{
    return fmt::format("{} {} {}", jobDescriptor(), jobArea(), jobType());
}

std::string Person::jobDescriptor()
{
    return Helper::arrayElement<std::string>(jobDescriptors);
}

std::string Person::jobArea()
{
    return Helper::arrayElement<std::string>(jobAreas);
}

std::string Person::jobType()
{
    return Helper::arrayElement<std::string>(jobTypes);
}

std::string Person::hobby()
{
    return Helper::arrayElement<std::string>(hobbies);
}

std::string Person::language()
{
    return Helper::arrayElement<std::string>(languages);
}

std::string Person::nationality()
{
    return Helper::arrayElement<std::string>(nationalities);
}

std::string Person::westernZodiac()
{
    return Helper::arrayElement<std::string>(westernZodiacs);
}

std::string Person::chineseZodiac()
{
    return Helper::arrayElement<std::string>(chineseZodiacs);
}

namespace
{
std::string middleNameForCountry(Country country, std::optional<Sex> sex)
{
    const auto& peopleNames = countryToPeopleNamesMapping.at(country);

    std::vector<std::string> middleNames;

    if (sex == Sex::Male)
    {
        const auto& malesMiddleNames = peopleNames.malesNames.middleNames;

        middleNames.insert(middleNames.end(), malesMiddleNames.begin(), malesMiddleNames.end());
    }
    else if (sex == Sex::Female)
    {
        const auto& femalesMiddleNames = peopleNames.femalesNames.middleNames;

        middleNames.insert(middleNames.end(), femalesMiddleNames.begin(), femalesMiddleNames.end());
    }
    else
    {
        const auto& malesMiddleNames = peopleNames.malesNames.middleNames;
        const auto& femalesMiddleNames = peopleNames.femalesNames.middleNames;

        middleNames.insert(middleNames.end(), malesMiddleNames.begin(), malesMiddleNames.end());
        middleNames.insert(middleNames.end(), femalesMiddleNames.begin(), femalesMiddleNames.end());
    }

    return Helper::arrayElement<std::string>(middleNames);
}

std::string prefixForCountry(Country country, std::optional<Sex> sex)
{
    const auto& peopleNames = countryToPeopleNamesMapping.at(country);

    std::vector<std::string> prefixes;

    if (sex == Sex::Male)
    {
        const auto& malesPrefixes = peopleNames.malesNames.prefixes;

        prefixes.insert(prefixes.end(), malesPrefixes.begin(), malesPrefixes.end());
    }
    else if (sex == Sex::Female)
    {
        const auto& femalesPrefixes = peopleNames.femalesNames.prefixes;

        prefixes.insert(prefixes.end(), femalesPrefixes.begin(), femalesPrefixes.end());
    }
    else
    {
        const auto& malesPrefixes = peopleNames.malesNames.prefixes;
        const auto& femalesPrefixes = peopleNames.femalesNames.prefixes;

        prefixes.insert(prefixes.end(), malesPrefixes.begin(), malesPrefixes.end());
        prefixes.insert(prefixes.end(), femalesPrefixes.begin(), femalesPrefixes.end());
    }

    return Helper::arrayElement<std::string>(prefixes);
}

std::string suffixForCountry(Country country, std::optional<Sex> sex)
{
    const auto& peopleNames = countryToPeopleNamesMapping.at(country);

    std::vector<std::string> suffixes;

    if (sex == Sex::Male)
    {
        const auto& malesSuffixes = peopleNames.malesNames.suffixes;

        suffixes.insert(suffixes.end(), malesSuffixes.begin(), malesSuffixes.end());
    }
    else if (sex == Sex::Female)
    {
        const auto& femalesSuffixes = peopleNames.femalesNames.suffixes;

        suffixes.insert(suffixes.end(), femalesSuffixes.begin(), femalesSuffixes.end());
    }
    else
    {
        const auto& malesSuffixes = peopleNames.malesNames.suffixes;
        const auto& femalesSuffixes = peopleNames.femalesNames.suffixes;

        suffixes.insert(suffixes.end(), malesSuffixes.begin(), malesSuffixes.end());
        suffixes.insert(suffixes.end(), femalesSuffixes.begin(), femalesSuffixes.end());
    }

    return Helper::arrayElement<std::string>(suffixes);
}
}
}
