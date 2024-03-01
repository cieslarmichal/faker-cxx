#include "../common/formatter.h"
#include "../common/random.h"
#include "person_data.h"
#include <faker/internet.h>
#include <faker/number.h>
#include <faker/person.h>
#include <faker/string.h>
#include <faker/word.h>
#include <regex>
#include <unordered_map>
#include <unordered_set>

namespace faker::person {
namespace {
    std::string_view middle_name(country_t country, std::optional<sex_t> sex)
    {
        const auto& names_data = data::people_names.at(country);
        auto male_names = names_data.males_names.middle_names;
        auto female_names = names_data.female_names.middle_names;

        if (sex == sex_t::male && !male_names.empty()) {
            return random::element(names_data.males_names.middle_names);
        } else if (sex == sex_t::female && !female_names.size()) {
            return random::element(names_data.female_names.middle_names);
        } else if (!sex && !male_names.empty() && !female_names.empty()) {
            std::vector<std::string_view> result;
            result.reserve(male_names.size() + female_names.size());
            result.insert(result.end(), male_names.begin(), male_names.end());
            result.insert(result.end(), female_names.begin(), female_names.end());
            return random::element(result);
        }

        return std::string_view();
    }

    std::string_view prefix(country_t country, std::optional<sex_t> sex)
    {
        const auto& names_data = data::people_names.at(country);
        auto male_prefixes = names_data.males_names.prefixes;
        auto female_prefixes = names_data.female_names.prefixes;

        if (sex == sex_t::male && !male_prefixes.empty()) {
            return random::element(names_data.males_names.prefixes);
        } else if (sex == sex_t::female && !female_prefixes.empty()) {
            return random::element(names_data.female_names.prefixes);
        } else if (!sex && !male_prefixes.empty() && !female_prefixes.empty()) {
            std::vector<std::string_view> result;
            result.reserve(male_prefixes.size() + female_prefixes.size());
            result.insert(result.end(), male_prefixes.begin(), male_prefixes.end());
            result.insert(result.end(), female_prefixes.begin(), female_prefixes.end());
            return random::element(result);
        }

        return std::string_view();
    }

    std::string_view suffix(country_t country, std::optional<sex_t> sex)
    {
        const auto& names_data = data::people_names.at(country);
        auto male_suffixes = names_data.males_names.suffixes;
        auto female_suffixes = names_data.female_names.suffixes;

        if (sex == sex_t::male && !male_suffixes.empty()) {
            return random::element(male_suffixes);
        } else if (sex == sex_t::female && !female_suffixes.empty()) {
            return random::element(female_suffixes);
        } else if (!sex && !male_suffixes.empty() && !female_suffixes.empty()) {
            std::vector<std::string_view> result;
            result.reserve(male_suffixes.size() + female_suffixes.size());
            result.insert(result.end(), male_suffixes.begin(), male_suffixes.end());
            result.insert(result.end(), female_suffixes.begin(), female_suffixes.end());
            return random::element(result);
        }

        return std::string_view();
    }

    std::unordered_map<std::optional<sex_t>, std::vector<std::string_view>>
    make_unique_middle_names()
    {
        std::unordered_set<std::string_view> unique_male_middle_names;
        std::unordered_set<std::string_view> unique_female_middle_names;
        std::unordered_set<std::string_view> unique_middle_names;

        for (const auto& [_, names_data] : data::people_names) {
            auto male_names = names_data.males_names.middle_names;
            auto female_names = names_data.female_names.middle_names;
            unique_male_middle_names.insert(male_names.begin(), male_names.end());
            unique_female_middle_names.insert(female_names.begin(), female_names.end());
            unique_middle_names.insert(male_names.begin(), male_names.end());
            unique_middle_names.insert(female_names.begin(), female_names.end());
        }

        std::unordered_map<std::optional<sex_t>, std::vector<std::string_view>> result;
        result.emplace(std::nullopt,
            std::vector<std::string_view> {
                unique_middle_names.begin(), unique_middle_names.end() });
        result.emplace(sex_t::male,
            std::vector<std::string_view> {
                unique_male_middle_names.begin(), unique_male_middle_names.end() });
        result.emplace(sex_t::female,
            std::vector<std::string_view> {
                unique_female_middle_names.begin(), unique_female_middle_names.end() });

        return result;
    }

    std::unordered_map<std::optional<sex_t>, std::vector<std::string_view>> make_unique_prefixes()
    {
        std::unordered_set<std::string_view> unique_male_prefixes;
        std::unordered_set<std::string_view> unique_female_prefixes;
        std::unordered_set<std::string_view> unique_middle_prefixes;

        for (const auto& [_, names_data] : data::people_names) {
            auto male_prefixes = names_data.males_names.prefixes;
            auto female_prefixes = names_data.female_names.prefixes;
            unique_male_prefixes.insert(male_prefixes.begin(), male_prefixes.end());
            unique_female_prefixes.insert(female_prefixes.begin(), female_prefixes.end());
            unique_middle_prefixes.insert(male_prefixes.begin(), male_prefixes.end());
            unique_middle_prefixes.insert(female_prefixes.begin(), female_prefixes.end());
        }

        std::unordered_map<std::optional<sex_t>, std::vector<std::string_view>> result;
        result.emplace(std::nullopt,
            std::vector<std::string_view> {
                unique_middle_prefixes.begin(), unique_middle_prefixes.end() });
        result.emplace(sex_t::male,
            std::vector<std::string_view> {
                unique_male_prefixes.begin(), unique_male_prefixes.end() });
        result.emplace(sex_t::female,
            std::vector<std::string_view> {
                unique_female_prefixes.begin(), unique_female_prefixes.end() });

        return result;
    }

    std::vector<std::string_view> make_unique_suffixes()
    {
        std::unordered_set<std::string_view> unique_suffixes;

        for (const auto& [_, peopleNames] : data::people_names) {
            auto male_suffixes = peopleNames.males_names.suffixes;
            auto female_suffixes = peopleNames.female_names.suffixes;
            unique_suffixes.insert(male_suffixes.begin(), male_suffixes.end());
            unique_suffixes.insert(female_suffixes.begin(), female_suffixes.end());
        }

        return std::vector<std::string_view> { unique_suffixes.begin(), unique_suffixes.end() };
    }
}

std::string_view to_string(sex_t sex, language_t language)
{
    const auto& i18n = data::sex_translations.find(language);

    if (i18n == data::sex_translations.end()) {
        throw std::runtime_error { "Sex not found." };
    }

    return i18n->second.at(sex);
}

std::string_view first_name(country_t country, std::optional<sex_t> sex)
{
    const auto& names_data = data::people_names.at(country);

    if (sex == sex_t::male) {
        return random::element(names_data.males_names.first_names);
    } else if (sex == sex_t::female) {
        return random::element(names_data.female_names.first_names);
    }

    auto male_names = names_data.males_names.first_names;
    auto female_names = names_data.female_names.first_names;

    std::vector<std::string_view> result;
    result.reserve(male_names.size() + female_names.size());
    result.insert(result.end(), male_names.begin(), male_names.end());
    result.insert(result.end(), female_names.begin(), female_names.end());

    return random::element(result);
}

std::string_view last_name(country_t country, std::optional<sex_t> sex)
{
    const auto& names_data = data::people_names.at(country);

    if (sex == sex_t::male) {
        return random::element(names_data.males_names.last_names);
    } else if (sex == sex_t::female) {
        return random::element(names_data.female_names.last_names);
    }

    const auto& male_names = names_data.males_names.last_names;
    const auto& female_names = names_data.female_names.last_names;

    std::vector<std::string_view> result;
    result.reserve(male_names.size() + female_names.size());
    result.insert(result.end(), male_names.begin(), male_names.end());
    result.insert(result.end(), female_names.begin(), female_names.end());

    return random::element(result);
}

std::string_view middle_name(std::optional<sex_t> sex)
{
    static std::unordered_map<std::optional<sex_t>, std::vector<std::string_view>>
        unique_middle_names = make_unique_middle_names();

    if (unique_middle_names.empty()) {
        throw std::runtime_error { utils::format(
            "No middle name fround, sex: {}.", sex ? to_string(*sex) : "none") };
    }

    return random::element(unique_middle_names[sex]);
}

std::string full_name(country_t country, std::optional<sex_t> sex)
{
    const auto& names_data = data::people_names.at(country);

    std::vector<unsigned> name_formats_weights;
    for (const auto& nameFormat : names_data.name_formats) {
        name_formats_weights.push_back(nameFormat.weight);
    }

    auto format_index = random::weighted_container_index(name_formats_weights);

    return utils::fill_token_values(
        names_data.name_formats[format_index].format, [country, sex](auto token) {
            if (token == "firstName") {
                return std::string(first_name(country, sex));
            } else if (token == "middleName") {
                return std::string(middle_name(country, sex));
            } else if (token == "lastName") {
                return std::string(last_name(country, sex));
            } else if (token == "prefix") {
                return std::string(prefix(country, sex));
            } else if (token == "suffix") {
                return std::string(suffix(country, sex));
            } else {
                return std::string();
            }
        });
}

std::string_view prefix(std::optional<sex_t> sex)
{
    static std::unordered_map<std::optional<sex_t>, std::vector<std::string_view>> unique_prefixes
        = make_unique_prefixes();

    if (unique_prefixes.empty()) {
        throw std::runtime_error { utils::format(
            "No prefixes fround, sex: {}.", sex ? to_string(*sex) : "none") };
    }

    return random::element(unique_prefixes[sex]);
}

std::string bio()
{
    auto final_format = random::element(data::bio_formats);

    return utils::fill_token_values(std::string(final_format), [](std::string_view token) {
        if (token == "bio_part") {
            return std::string(random::element(data::bio_parts));
        } else if (token == "bio_supporter") {
            return std::string(random::element(data::bio_supporters));
        } else if (token == "noun") {
            return std::string(word::noun());
        } else if (token == "emoji") {
            return std::string(internet::emoji());
        } else {
            return std::string();
        }
    });
}

std::string_view suffix()
{
    static const std::vector<std::string_view> unique_suffixes = make_unique_suffixes();
    return random::element<std::string_view>(unique_suffixes);
}

std::string_view sex(language_t language)
{
    static const std::array<sex_t, 2> sexes { sex_t::male, sex_t::female };

    const auto final_sex = random::element(sexes);

    return to_string(final_sex, language);
}

std::string_view gender() { return random::element(data::genders); }

std::string job_title()
{
    return utils::format("{} {} {}", job_descriptor(), job_area(), job_type());
}

std::string_view job_descriptor() { return random::element(data::job_descriptors); }

std::string_view job_area() { return random::element(data::job_areas); }

std::string_view job_type() { return random::element(data::job_types); }

std::string_view hobby() { return random::element(data::hobbies); }

std::string_view language() { return random::element(data::languages); }

std::string_view nationality() { return random::element(data::nationalities); }

std::string ssn(std::optional<ssn_country_t> country)
{
    const auto& ssn_format
        = data::ssn_formats.at(country ? *country : random::element(data::supported_ssn_countries));

    auto ssn_without_regexes = random::regexp_style_string_parse(ssn_format);

    std::string result;

    for (auto ch : ssn_without_regexes) {
        if (ch == 'L') {
            result += string::alpha(1, string::string_case::upper);
        } else if (ch == 'F') {
            result += string::alphanumeric(1, string::string_case::upper);
        } else if (ch == '#') {
            result += std::to_string(number::integer(0, 9));
        } else {
            result += ch;
        }
    }

    return result;
}

std::string_view western_zodiac() { return random::element(data::western_zodiacs); }

std::string_view chinese_zodiac() { return random::element(data::chinese_zodiacs); }

}
