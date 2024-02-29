#include "../common/formatter.h"
#include "../common/random.h"
#include "person_data.h"
#include <faker/internet.h>
#include <faker/number.h>
#include <faker/person.h>
#include <faker/string.h>
#include <faker/word.h>
#include <regex>
#include <unordered_set>

namespace faker::person {
namespace {
    std::string middleNameForCountry(Country country, std::optional<Sex> sex);
    std::string prefixForCountry(Country country, std::optional<Sex> sex);
    std::string suffixForCountry(Country country, std::optional<Sex> sex);
}

std::string_view to_string(Sex sex, Language language)
{
    const auto& sexTranslation = data::sexTranslations.find(language);

    if (sexTranslation == data::sexTranslations.end()) {
        throw std::runtime_error { "Sex not found." };
    }

    return sexTranslation->second.at(sex);
}

std::string first_name(Country country, std::optional<Sex> sex)
{
    const auto& peopleNames = data::countryToPeopleNamesMapping.at(country);

    std::vector<std::string> firstNames;

    if (sex == Sex::male) {
        const auto& malesFirstNames = peopleNames.malesNames.firstNames;

        firstNames.insert(firstNames.end(), malesFirstNames.begin(), malesFirstNames.end());
    } else if (sex == Sex::female) {
        const auto& femalesFirstNames = peopleNames.femalesNames.firstNames;

        firstNames.insert(firstNames.end(), femalesFirstNames.begin(), femalesFirstNames.end());
    } else {
        const auto& malesFirstNames = peopleNames.malesNames.firstNames;
        const auto& femalesFirstNames = peopleNames.femalesNames.firstNames;

        firstNames.insert(firstNames.end(), malesFirstNames.begin(), malesFirstNames.end());
        firstNames.insert(firstNames.end(), femalesFirstNames.begin(), femalesFirstNames.end());
    }

    return random::element<std::string>(firstNames);
}

std::string last_name(Country country, std::optional<Sex> sex)
{
    const auto& peopleNames = data::countryToPeopleNamesMapping.at(country);

    std::vector<std::string> lastNames;

    if (sex == Sex::male) {
        const auto& malesLastNames = peopleNames.malesNames.lastNames;

        lastNames.insert(lastNames.end(), malesLastNames.begin(), malesLastNames.end());
    } else if (sex == Sex::female) {
        const auto& femalesLastNames = peopleNames.femalesNames.lastNames;

        lastNames.insert(lastNames.end(), femalesLastNames.begin(), femalesLastNames.end());
    } else {
        const auto& malesLastNames = peopleNames.malesNames.lastNames;
        const auto& femalesLastNames = peopleNames.femalesNames.lastNames;

        lastNames.insert(lastNames.end(), malesLastNames.begin(), malesLastNames.end());
        lastNames.insert(lastNames.end(), femalesLastNames.begin(), femalesLastNames.end());
    }

    return random::element<std::string>(lastNames);
}

std::string middle_name(std::optional<Sex> sex)
{
    std::vector<std::string> allMiddleNames;

    for (const auto& [_, peopleNames] : data::countryToPeopleNamesMapping) {
        std::vector<std::string> middleNames;

        if (sex == Sex::male) {
            const auto& malesMiddleNames = peopleNames.malesNames.middleNames;

            middleNames.insert(middleNames.end(), malesMiddleNames.begin(), malesMiddleNames.end());
        } else if (sex == Sex::female) {
            const auto& femalesMiddleNames = peopleNames.femalesNames.middleNames;

            middleNames.insert(
                middleNames.end(), femalesMiddleNames.begin(), femalesMiddleNames.end());
        } else {
            const auto& malesMiddleNames = peopleNames.malesNames.middleNames;
            const auto& femalesMiddleNames = peopleNames.femalesNames.middleNames;

            middleNames.insert(middleNames.end(), malesMiddleNames.begin(), malesMiddleNames.end());
            middleNames.insert(
                middleNames.end(), femalesMiddleNames.begin(), femalesMiddleNames.end());
        }

        std::unordered_set<std::string> uniqueMiddleNames(middleNames.begin(), middleNames.end());

        middleNames.assign(uniqueMiddleNames.begin(), uniqueMiddleNames.end());

        allMiddleNames.insert(allMiddleNames.end(), middleNames.begin(), middleNames.end());
    }

    if (allMiddleNames.empty()) {
        throw std::runtime_error { utils::format(
            "No middle name fround, sex: {}.", sex ? to_string(*sex) : "none") };
    }

    return random::element<std::string>(allMiddleNames);
}

std::string full_name(Country country, std::optional<Sex> sex)
{
    const auto& peopleNames = data::countryToPeopleNamesMapping.at(country);

    std::vector<random::WeightedElement<std::string_view>> weightedElements;
    for (const auto& nameFormat : peopleNames.nameFormats) {
        weightedElements.push_back({ nameFormat.weight, nameFormat.format });
    }

    const auto nameFormat = random::weighted_element(weightedElements);

    return utils::fill_token_values(nameFormat, [country, sex](auto token) {
        if (token == "firstName") {
            return first_name(country, sex);
        } else if (token == "middleName") {
            return middleNameForCountry(country, sex);
        } else if (token == "lastName") {
            return last_name(country, sex);
        } else if (token == "prefix") {
            return prefixForCountry(country, sex);
        } else if (token == "suffix") {
            return suffixForCountry(country, sex);
        } else {
            return std::string();
        }
    });
}

std::string prefix(std::optional<Sex> sex)
{
    std::vector<std::string> allPrefixes;

    for (const auto& [_, peopleNames] : data::countryToPeopleNamesMapping) {
        std::vector<std::string> prefixes;

        if (sex == Sex::male) {
            const auto& malesPrefixes = peopleNames.malesNames.prefixes;

            prefixes.insert(prefixes.end(), malesPrefixes.begin(), malesPrefixes.end());
        } else if (sex == Sex::female) {
            const auto& femalesPrefixes = peopleNames.femalesNames.prefixes;

            prefixes.insert(prefixes.end(), femalesPrefixes.begin(), femalesPrefixes.end());
        } else {
            const auto& malesPrefixes = peopleNames.malesNames.prefixes;
            const auto& femalesPrefixes = peopleNames.femalesNames.prefixes;

            prefixes.insert(prefixes.end(), malesPrefixes.begin(), malesPrefixes.end());
            prefixes.insert(prefixes.end(), femalesPrefixes.begin(), femalesPrefixes.end());
        }

        std::unordered_set<std::string> uniquePrefixes(prefixes.begin(), prefixes.end());

        prefixes.assign(uniquePrefixes.begin(), uniquePrefixes.end());

        allPrefixes.insert(allPrefixes.end(), prefixes.begin(), prefixes.end());
    }

    if (allPrefixes.empty()) {
        throw std::runtime_error { utils::format(
            "No prefixes fround, sex: {}.", sex ? to_string(*sex) : "none") };
    }

    return random::element<std::string>(allPrefixes);
}

std::string bio()
{
    const auto randomBioFormat = random::element(data::bioFormats);

    return utils::fill_token_values(std::string(randomBioFormat), [](std::string_view token) {
        if (token == "bio_part") {
            return std::string(random::element(data::bioPart));
        } else if (token == "bio_supporter") {
            return std::string(random::element(data::bioSupporter));
        } else if (token == "noun") {
            return std::string(word::noun());
        } else if (token == "emoji") {
            return std::string(internet::emoji());
        } else {
            return std::string();
        }
    });
}

std::string suffix()
{
    std::vector<std::string> allSuffixes;

    for (const auto& [_, peopleNames] : data::countryToPeopleNamesMapping) {
        std::vector<std::string> suffixes;

        const auto& malesSuffixes = peopleNames.malesNames.suffixes;
        const auto& femalesSuffixes = peopleNames.femalesNames.suffixes;

        suffixes.insert(suffixes.end(), malesSuffixes.begin(), malesSuffixes.end());
        suffixes.insert(suffixes.end(), femalesSuffixes.begin(), femalesSuffixes.end());

        std::unordered_set<std::string> uniqueSuffixes(suffixes.begin(), suffixes.end());

        suffixes.assign(uniqueSuffixes.begin(), uniqueSuffixes.end());

        allSuffixes.insert(allSuffixes.end(), suffixes.begin(), suffixes.end());
    }

    return random::element<std::string>(allSuffixes);
}

std::string_view sex(Language language)
{
    static const std::array<Sex, 2> sexes { Sex::male, Sex::female };

    const auto chosenSex = random::element(sexes);

    return to_string(chosenSex, language);
}

std::string_view gender() { return random::element(data::genders); }

std::string job_title()
{
    return utils::format("{} {} {}", job_descriptor(), job_area(), job_type());
}

std::string_view job_descriptor() { return random::element(data::jobDescriptors); }

std::string_view job_area() { return random::element(data::jobAreas); }

std::string_view job_type() { return random::element(data::jobTypes); }

std::string_view hobby() { return random::element(data::hobbies); }

std::string_view language() { return random::element(data::languages); }

std::string_view nationality() { return random::element(data::nationalities); }

std::string ssn(std::optional<ssn_country> country)
{
    const auto ssnCountry = country ? *country : random::element(data::supportedSsnCountries);

    const auto& ssnFormat = data::ssnFormats.at(ssnCountry);

    auto ssnWithoutRegexes = random::regexp_style_string_parse(ssnFormat);

    std::string ssn;

    for (const auto& ssnFormatCharacter : ssnWithoutRegexes) {
        if (ssnFormatCharacter == 'L') {
            ssn += string::alpha(1, string::string_case::upper);
        } else if (ssnFormatCharacter == 'F') {
            ssn += string::alphanumeric(1, string::string_case::upper);
        } else if (ssnFormatCharacter == '#') {
            ssn += std::to_string(number::integer(0, 9));
        } else {
            ssn += ssnFormatCharacter;
        }
    }

    return ssn;
}

std::string_view western_zodiac() { return random::element(data::westernZodiacs); }

std::string_view chinese_zodiac() { return random::element(data::chineseZodiacs); }

namespace {
    std::string middleNameForCountry(Country country, std::optional<Sex> sex)
    {
        const auto& peopleNames = data::countryToPeopleNamesMapping.at(country);

        std::vector<std::string> middleNames;

        if (sex == Sex::male) {
            const auto& malesMiddleNames = peopleNames.malesNames.middleNames;

            middleNames.insert(middleNames.end(), malesMiddleNames.begin(), malesMiddleNames.end());
        } else if (sex == Sex::female) {
            const auto& femalesMiddleNames = peopleNames.femalesNames.middleNames;

            middleNames.insert(
                middleNames.end(), femalesMiddleNames.begin(), femalesMiddleNames.end());
        } else {
            const auto& malesMiddleNames = peopleNames.malesNames.middleNames;
            const auto& femalesMiddleNames = peopleNames.femalesNames.middleNames;

            middleNames.insert(middleNames.end(), malesMiddleNames.begin(), malesMiddleNames.end());
            middleNames.insert(
                middleNames.end(), femalesMiddleNames.begin(), femalesMiddleNames.end());
        }

        return random::element<std::string>(middleNames);
    }

    std::string prefixForCountry(Country country, std::optional<Sex> sex)
    {
        const auto& peopleNames = data::countryToPeopleNamesMapping.at(country);

        std::vector<std::string> prefixes;

        if (sex == Sex::male) {
            const auto& malesPrefixes = peopleNames.malesNames.prefixes;

            prefixes.insert(prefixes.end(), malesPrefixes.begin(), malesPrefixes.end());
        } else if (sex == Sex::female) {
            const auto& femalesPrefixes = peopleNames.femalesNames.prefixes;

            prefixes.insert(prefixes.end(), femalesPrefixes.begin(), femalesPrefixes.end());
        } else {
            const auto& malesPrefixes = peopleNames.malesNames.prefixes;
            const auto& femalesPrefixes = peopleNames.femalesNames.prefixes;

            prefixes.insert(prefixes.end(), malesPrefixes.begin(), malesPrefixes.end());
            prefixes.insert(prefixes.end(), femalesPrefixes.begin(), femalesPrefixes.end());
        }

        return random::element<std::string>(prefixes);
    }

    std::string suffixForCountry(Country country, std::optional<Sex> sex)
    {
        const auto& peopleNames = data::countryToPeopleNamesMapping.at(country);

        std::vector<std::string> suffixes;

        if (sex == Sex::male) {
            const auto& malesSuffixes = peopleNames.malesNames.suffixes;

            suffixes.insert(suffixes.end(), malesSuffixes.begin(), malesSuffixes.end());
        } else if (sex == Sex::female) {
            const auto& femalesSuffixes = peopleNames.femalesNames.suffixes;

            suffixes.insert(suffixes.end(), femalesSuffixes.begin(), femalesSuffixes.end());
        } else {
            const auto& malesSuffixes = peopleNames.malesNames.suffixes;
            const auto& femalesSuffixes = peopleNames.femalesNames.suffixes;

            suffixes.insert(suffixes.end(), malesSuffixes.begin(), malesSuffixes.end());
            suffixes.insert(suffixes.end(), femalesSuffixes.begin(), femalesSuffixes.end());
        }

        return random::element<std::string>(suffixes);
    }
}
}
