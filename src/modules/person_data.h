#ifndef FAKER_MODULES_PERSON_DATA_H
#define FAKER_MODULES_PERSON_DATA_H

#include "../common/span.h"
#include <array>
#include <faker/person.h>
#include <faker/types/country.h>
#include <string_view>
#include <unordered_map>
#include <vector>

namespace faker::person::data {
extern const std::array<std::string_view, 41> bio_parts;
extern const std::array<std::string_view, 7> bio_supporters;
extern const std::array<std::string_view, 8> bio_formats;
extern const std::array<std::string_view, 76> genders;
extern const std::array<std::string_view, 44> hobbies;
extern const std::array<std::string_view, 25> job_descriptors;
extern const std::array<std::string_view, 38> job_areas;
extern const std::array<std::string_view, 25> job_types;
extern const std::array<std::string_view, 18> languages;

struct NameFormat {
    std::string_view format;
    unsigned weight;
};

using NameFormats = std::vector<NameFormat>;

extern const std::array<std::string_view, 62> nationalities;

struct PersonNames {
    utils::span<const std::string_view> first_names;
    utils::span<const std::string_view> middle_names;
    utils::span<const std::string_view> last_names;
    utils::span<const std::string_view> prefixes;
    utils::span<const std::string_view> suffixes;
};

struct PeopleNames {
    PersonNames males_names;
    PersonNames female_names;
    NameFormats name_formats;
};

extern const std::unordered_map<ssn_country_t, std::string_view> ssn_formats;
extern const std::array<std::string_view, 12> western_zodiacs;
extern const std::array<std::string_view, 11> chinese_zodiacs;
extern const std::unordered_map<language_t, std::unordered_map<sex_t, std::string_view>>
    sex_translations;
extern const std::array<ssn_country_t, 8> supported_ssn_countries;
extern const std::unordered_map<ssn_country_t, unsigned> ssn_lengths;

// Albania

extern const std::array<std::string_view, 157> albanian_male_first_names;
extern const std::array<std::string_view, 141> albanian_female_first_names;
extern const std::array<std::string_view, 140> albanian_last_names;
extern const NameFormats albanian_person_name_formats;
extern const PeopleNames albanian_people_names;

// Argentina

extern const std::array<std::string_view, 350> argentinian_male_first_names;
extern const std::array<std::string_view, 350> argentinian_female_first_names;
extern const std::array<std::string_view, 348> argentinian_last_names;
extern const NameFormats argentinian_name_formats;
extern const PeopleNames argentinian_people_names;

// Australia

extern const std::array<std::string_view, 100> australian_male_first_names;
extern const std::array<std::string_view, 100> australian_female_first_names;
extern const std::array<std::string_view, 286> australian_last_names;
extern const NameFormats australian_name_formats;
extern const PeopleNames australian_people_names;

// Austria

extern const std::array<std::string_view, 572> austrian_male_first_names;
extern const std::array<std::string_view, 573> austrian_female_first_names;
extern const std::array<std::string_view, 1688> austrian_last_names;
extern const std::array<std::string_view, 3> austrian_male_prefixes;
extern const std::array<std::string_view, 3> austrian_female_prefixes;
extern const NameFormats austrian_name_formats;
extern const PeopleNames austrian_people_names;

// Azerbaijan

extern const std::array<std::string_view, 35> azerbaijani_male_first_names;
extern const std::array<std::string_view, 73> azerbaijani_female_first_names;
extern const std::array<std::string_view, 10> azerbaijani_male_last_names;
extern const std::array<std::string_view, 10> azerbaijani_female_last_names;
extern const NameFormats azerbaijani_name_formats;
extern const PeopleNames azerbaijani_people_names;

// Belarus

extern const std::array<std::string_view, 350> belarusian_male_first_names;
extern const std::array<std::string_view, 350> belarusian_female_first_names;
extern const std::array<std::string_view, 261> belarusian_male_last_names;
extern const std::array<std::string_view, 89> belarusian_female_last_names;
extern const NameFormats belarusian_name_formats;
extern const PeopleNames belarusian_people_names;

// Belgium

extern const std::array<std::string_view, 100> belgian_male_first_names;
extern const std::array<std::string_view, 99> belgian_female_first_names;
extern const std::array<std::string_view, 32> belgian_last_names;
extern const std::array<std::string_view, 2> belgian_suffixes;
extern const std::array<std::string_view, 4> belgian_prefixes;
extern const NameFormats belgian_name_formats;
extern const PeopleNames belgian_people_names;

// Bosnia

extern const std::array<std::string_view, 100> bosnian_male_first_names;
extern const std::array<std::string_view, 100> bosnian_female_first_names;
extern const std::array<std::string_view, 128> bosnian_last_names;
extern const NameFormats bosnian_name_formats;
extern const PeopleNames bosnian_people_names;

// Brazil

extern const std::array<std::string_view, 88> brazilian_male_first_names;
extern const std::array<std::string_view, 80> brazilian_female_first_names;
extern const std::array<std::string_view, 21> brazilian_last_names;
extern const std::array<std::string_view, 3> brazilian_suffixes;
extern const std::array<std::string_view, 2> brazilian_male_prefixes;
extern const std::array<std::string_view, 3> brazilian_female_prefixes;
extern const NameFormats brazilian_name_formats;
extern const PeopleNames brazilian_people_names;

// Bulgaria

extern const std::array<std::string_view, 30> bulgarian_male_first_names;
extern const std::array<std::string_view, 32> bulgarian_female_first_names;
extern const std::array<std::string_view, 25> bulgarian_last_names;
extern const std::array<std::string_view, 2> bulgarian_suffixes;
extern const std::array<std::string_view, 3> bulgarian_male_prefixes;
extern const std::array<std::string_view, 4> bulgarian_female_prefixes;
extern const NameFormats bulgarian_name_formats;
extern const PeopleNames bulgarian_people_names;

// Canada

extern const std::array<std::string_view, 350> canadian_male_first_names;
extern const std::array<std::string_view, 350> canadian_female_first_names;
extern const std::array<std::string_view, 346> canadian_last_names;
extern const NameFormats canadian_name_formats;
extern const PeopleNames canadian_people_names;

// China

extern const std::array<std::string_view, 1000> chinese_last_names;
extern const std::array<std::string_view, 78> chinese_male_first_names;
extern const std::array<std::string_view, 85> chinese_female_first_names;
extern const NameFormats chinese_name_formats;
extern const PeopleNames chinese_people_names;

// Croatia

extern const std::array<std::string_view, 171> croatian_male_first_names;
extern const std::array<std::string_view, 238> croatian_female_first_names;
extern const std::array<std::string_view, 11617> croatian_last_names;
extern const std::array<std::string_view, 2> croatian_suffixes;
extern const std::array<std::string_view, 2> croatian_male_prefixes;
extern const std::array<std::string_view, 3> croatian_female_prefixes;
extern const NameFormats croatian_name_formats;
extern const PeopleNames croatian_people_names;

// Czechia

extern const std::array<std::string_view, 795> czech_male_first_names;
extern const std::array<std::string_view, 785> czech_female_first_names;
extern const std::array<std::string_view, 999> czech_male_last_names;
extern const std::array<std::string_view, 991> czech_female_last_names;
extern const std::array<std::string_view, 4> czech_prefixes;
extern const std::array<std::string_view, 1> czech_suffixes;
extern const NameFormats czech_name_formats;
extern const PeopleNames czech_people_names;

// Denmark

extern const std::array<std::string_view, 118> danish_male_first_names;
extern const std::array<std::string_view, 109> danish_female_first_names;
extern const std::array<std::string_view, 106> danish_last_names;
extern const std::array<std::string_view, 30> danish_middle_names;
extern const std::array<std::string_view, 1> danish_male_prefixes;
extern const std::array<std::string_view, 1> danish_female_prefixes;
extern const NameFormats danish_name_formats;
extern const PeopleNames danish_people_names;

// Dutch

extern const std::array<std::string_view, 587> dutch_male_first_names;
extern const std::array<std::string_view, 514> dutch_female_first_names;
extern const std::array<std::string_view, 131> dutch_last_names;
extern const std::array<std::string_view, 2> dutch_suffixes;
extern const std::array<std::string_view, 7> dutch_male_prefixes;
extern const std::array<std::string_view, 7> dutch_female_prefixes;
extern const NameFormats dutch_name_formats;
extern const PeopleNames dutch_people_names;

// England

extern const std::array<std::string_view, 500> english_male_first_names;
extern const std::array<std::string_view, 500> english_female_first_names;
extern const std::array<std::string_view, 463> english_last_names;
extern const std::array<std::string_view, 11> english_suffixes;
extern const std::array<std::string_view, 2> english_male_prefixes;
extern const std::array<std::string_view, 4> english_female_prefixes;
extern const NameFormats english_name_formats;
extern const PeopleNames english_people_names;

// Estonia

extern const std::array<std::string_view, 350> estonian_male_first_names;
extern const std::array<std::string_view, 350> estonian_female_first_names;
extern const std::array<std::string_view, 350> estonian_last_names;
extern const NameFormats estonian_name_formats;
extern const PeopleNames estonian_people_names;

// Finland

extern const std::array<std::string_view, 45> finnish_male_first_names;
extern const std::array<std::string_view, 46> finnish_female_first_names;
extern const std::array<std::string_view, 46> finnish_last_names;
extern const NameFormats finnish_name_formats;
extern const PeopleNames finnish_people_names;

// France

extern const std::array<std::string_view, 496> french_male_first_names;
extern const std::array<std::string_view, 451> french_female_first_names;
extern const std::array<std::string_view, 150> french_last_names;
extern const std::array<std::string_view, 3> french_male_prefixes;
extern const std::array<std::string_view, 4> french_female_prefixes;
extern const NameFormats french_name_formats;
extern const PeopleNames french_people_names;

// Germany

extern const std::array<std::string_view, 572> german_male_first_names;
extern const std::array<std::string_view, 583> german_female_first_names;
extern const std::array<std::string_view, 1688> german_last_names;
extern const std::array<std::string_view, 3> german_male_prefixes;
extern const std::array<std::string_view, 3> german_female_prefixes;
extern const NameFormats german_name_formats;
extern const PeopleNames german_people_names;

// Ghana

extern const std::array<std::string_view, 132> ghanaian_male_first_names;
extern const std::array<std::string_view, 132> ghanaian_female_first_names;
extern const std::array<std::string_view, 120> ghanaian_last_names;
extern const NameFormats ghanaian_name_formats;
extern const PeopleNames ghanaian_people_names;

// Greece

extern const std::array<std::string_view, 350> greek_male_first_names;
extern const std::array<std::string_view, 350> greek_female_first_names;
extern const std::array<std::string_view, 350> greek_last_names;
extern const NameFormats greek_name_formats;
extern const PeopleNames greek_people_names;

// Hungary

extern const std::array<std::string_view, 100> hungarian_male_first_names;
extern const std::array<std::string_view, 100> hungarian_female_first_names;
extern const std::array<std::string_view, 100> hungarian_last_names;
extern const std::array<std::string_view, 2> hungarian_prefixes;
extern const NameFormats hungarian_name_formats;
extern const PeopleNames hungarian_people_names;

// Iceland

extern const std::array<std::string_view, 157> icelandic_male_first_names;
extern const std::array<std::string_view, 141> icelandic_female_first_names;
extern const std::array<std::string_view, 140> icelandic_last_names;
extern const NameFormats icelandic_person_name_formats;
extern const PeopleNames icelandic_people_names;

// India

extern const std::array<std::string_view, 351> indian_male_first_names;
extern const std::array<std::string_view, 228> indian_female_first_names;
extern const std::array<std::string_view, 184> indian_last_names;
extern const NameFormats indian_name_formats;
extern const PeopleNames indian_people_names;

// Ireland

extern const std::array<std::string_view, 350> irish_male_first_names;
extern const std::array<std::string_view, 350> irish_female_first_names;
extern const std::array<std::string_view, 350> irish_last_names;
extern const std::array<std::string_view, 11> irish_suffixes;
extern const std::array<std::string_view, 2> irish_male_prefixes;
extern const std::array<std::string_view, 4> irish_female_prefixes;
// TODO: add handling lastName-lastName
extern const NameFormats irish_name_formats;
extern const PeopleNames irish_people_names;

// Israel

extern const std::array<std::string_view, 297> israelis_male_first_names;
extern const std::array<std::string_view, 297> israelis_female_first_names;
extern const std::array<std::string_view, 270> israelis_last_names;
extern const NameFormats israelis_name_formats;
extern const PeopleNames israeli_people_names;

// Italy

extern const std::array<std::string_view, 1083> italian_male_first_names;
extern const std::array<std::string_view, 617> italian_female_first_names;
extern const std::array<std::string_view, 2170> italian_last_names;
extern const std::array<std::string_view, 4> italian_prefixes;
extern const NameFormats italian_name_formats;
extern const PeopleNames italian_people_names;

// Japan

extern const std::array<std::string_view, 135> japanese_male_first_names;
extern const std::array<std::string_view, 145> japanese_female_first_names;
extern const std::array<std::string_view, 20> japanese_last_names;
extern const NameFormats japanese_name_formats;
extern const PeopleNames japanese_people_names;

// Kazakhstan

extern const std::array<std::string_view, 200> kazakh_male_first_names;
extern const std::array<std::string_view, 121> kazakh_female_first_names;
extern const std::array<std::string_view, 21> kazakh_male_last_names;
extern const std::array<std::string_view, 18> kazakh_female_last_names;
extern const NameFormats kazakh_person_name_formats;
extern const PeopleNames kazakh_people_names;

// Korea

extern const std::array<std::string_view, 2963> korean_male_first_names;
extern const std::array<std::string_view, 112> korean_last_names;
extern const NameFormats korean_name_formats;
extern const PeopleNames korean_people_names;

// Latvia

extern const std::array<std::string_view, 91> latvian_male_first_names;
extern const std::array<std::string_view, 105> latvian_female_first_names;
extern const std::array<std::string_view, 206> latvian_male_last_names;
extern const std::array<std::string_view, 207> latvian_female_last_names;
extern const std::array<std::string_view, 2> latvian_suffixes;
extern const std::array<std::string_view, 3> latvian_prefixes;
extern const NameFormats latvian_name_formats;
extern const PeopleNames latvian_people_names;

// Lebanon

extern const std::array<std::string_view, 700> lebanese_male_first_names;
extern const std::array<std::string_view, 350> lebanese_female_first_names;
extern const std::array<std::string_view, 350> lebanese_last_names;
extern const NameFormats lebanese_name_formats;
extern const PeopleNames lebanese_people_names;

// Lithuania

extern const std::array<std::string_view, 350> lithuanian_male_first_names;
extern const std::array<std::string_view, 350> lithuanian_female_first_names;
extern const std::array<std::string_view, 350> lithuanian_last_names;
extern const NameFormats lithuanian_name_formats;
extern const PeopleNames lithuanian_people_names;

// Macedonia

extern const std::array<std::string_view, 283> macedonian_male_first_names;
extern const std::array<std::string_view, 232> macedonian_female_first_names;
extern const std::array<std::string_view, 493> macedonian_male_last_names;
extern const std::array<std::string_view, 495> macedonian_female_last_names;
extern const std::array<std::string_view, 3> macedonian_male_prefixes;
extern const std::array<std::string_view, 4> macedonian_female_prefixes;
extern const NameFormats macedonian_name_formats;
extern const PeopleNames macedonian_people_names;

// Maldives

extern const std::array<std::string_view, 14> maldivians_male_first_names;
extern const std::array<std::string_view, 49> maldivians_female_first_names;
extern const std::array<std::string_view, 112> maldivians_male_last_names;
extern const std::array<std::string_view, 248> maldivians_female_last_names;
extern const std::array<std::string_view, 4> maldivians_male_prefixes;
extern const std::array<std::string_view, 4> maldivians_female_prefixes;
extern const NameFormats maldivians_name_formats;
extern const PeopleNames maldivians_people_names;

// Malta

extern const std::array<std::string_view, 100> maltese_male_first_names;
extern const std::array<std::string_view, 100> maltese_female_first_names;
extern const std::array<std::string_view, 100> maltese_last_names;
extern const NameFormats maltese_name_formats;
extern const PeopleNames maltese_people_names;

// Mexico

extern const std::array<std::string_view, 139> mexican_male_first_names;
extern const std::array<std::string_view, 161> mexican_female_first_names;
extern const std::array<std::string_view, 687> mexican_last_names;
extern const std::array<std::string_view, 15> mexican_suffixes;
extern const std::array<std::string_view, 1> mexican_male_prefixes;
extern const std::array<std::string_view, 2> mexican_female_prefixes;
extern const NameFormats mexican_name_formats;
extern const PeopleNames mexican_people_names;

// Moldova

extern const std::array<std::string_view, 350> moldovan_male_first_names;
extern const std::array<std::string_view, 350> moldovan_female_first_names;
extern const std::array<std::string_view, 350> moldovan_last_names;
extern const NameFormats moldovan_name_formats;
extern const PeopleNames moldovan_people_names;

// Monaco

extern const std::array<std::string_view, 201> monacan_male_first_names;
extern const std::array<std::string_view, 350> monacan_female_first_names;
extern const std::array<std::string_view, 326> monacan_last_names;
extern const NameFormats monacan_name_formats;
extern const PeopleNames monacan_people_names;

// Nepal

extern const std::array<std::string_view, 104> nepalese_male_first_names;
extern const std::array<std::string_view, 99> nepalese_female_first_names;
extern const std::array<std::string_view, 64> nepalese_last_names;
extern const NameFormats nepalese_name_formats;
extern const PeopleNames nepalese_people_names;

// Norway

extern const std::array<std::string_view, 50> norwegian_male_first_names;
extern const std::array<std::string_view, 50> norwegian_female_first_names;
extern const std::array<std::string_view, 100> norwegian_last_names;
extern const std::array<std::string_view, 7> norwegian_suffixes;
extern const std::array<std::string_view, 2> norwegian_prefixes;
extern const NameFormats norwegian_name_formats;
extern const PeopleNames norwegian_people_names;

// Palestine

extern const std::array<std::string_view, 299> palestinian_male_first_names;
extern const std::array<std::string_view, 350> palestinian_female_first_names;
extern const std::array<std::string_view, 305> palestinian_last_names;
extern const NameFormats palestinian_name_formats;
extern const PeopleNames palestinian_people_names;

// Persian

extern const std::array<std::string_view, 61> persian_male_first_names;
extern const std::array<std::string_view, 65> persian_female_first_names;
extern const std::array<std::string_view, 111> persian_last_names;
extern const std::array<std::string_view, 3> persian_male_prefixes;
extern const std::array<std::string_view, 3> persian_female_prefixes;
extern const NameFormats persian_name_formats;
extern const PeopleNames persian_people_names;

// Poland

extern const std::array<std::string_view, 230> polish_male_first_names;
extern const std::array<std::string_view, 163> polish_female_first_names;
extern const std::array<std::string_view, 712> polish_last_names;
extern const std::array<std::string_view, 1> polish_male_prefixes;
extern const std::array<std::string_view, 1> polish_female_prefixes;
extern const NameFormats polish_name_formats;
extern const PeopleNames polish_people_names;

// Portugal

extern const std::array<std::string_view, 95> portuguese_male_first_names;
extern const std::array<std::string_view, 93> portuguese_female_first_names;
extern const std::array<std::string_view, 101> portuguese_last_names;
extern const std::array<std::string_view, 4> portuguese_male_prefixes;
extern const std::array<std::string_view, 4> portuguese_female_prefixes;
extern const NameFormats portuguese_name_formats;
extern const PeopleNames portuguese_people_names;

// Romania

extern const std::array<std::string_view, 65> romanian_male_first_names;
extern const std::array<std::string_view, 63> romanian_female_first_names;
extern const std::array<std::string_view, 101> romanian_last_names;
extern const std::array<std::string_view, 2> romanian_suffixes;
extern const std::array<std::string_view, 2> romanian_male_prefixes;
extern const std::array<std::string_view, 2> romanian_female_refixes;
extern const NameFormats romanian_name_formats;
extern const PeopleNames romanian_people_names;

// Russia

extern const std::array<std::string_view, 200> russian_male_first_names;
extern const std::array<std::string_view, 110> russian_female_first_names;
extern const std::array<std::string_view, 568> russian_male_last_names;
extern const std::array<std::string_view, 562> russian_female_last_names;
extern const std::array<std::string_view, 132> russian_male_middle_names;
extern const std::array<std::string_view, 79> russian_female_middle_names;
extern const NameFormats russian_name_formats;
extern const PeopleNames russian_people_names;

// Serbia

extern const std::array<std::string_view, 200> serbian_male_first_names;
extern const std::array<std::string_view, 200> serbian_female_first_names;
extern const std::array<std::string_view, 999> serbian_last_names;
extern const NameFormats serbian_name_formats;
extern const PeopleNames serbian_people_names;

// Slovakia

extern const std::array<std::string_view, 192> slovak_male_first_names;
extern const std::array<std::string_view, 200> slovak_female_first_names;
extern const std::array<std::string_view, 257> slovak_male_last_names;
extern const std::array<std::string_view, 251> slovak_females_last_names;
extern const std::array<std::string_view, 1> slovak_suffixes;
extern const std::array<std::string_view, 4> slovak_prefixes;
extern const NameFormats slovak_name_formats;
extern const PeopleNames slovak_people_names;

// Slovenia

extern const std::array<std::string_view, 350> slovenian_male_first_names;
extern const std::array<std::string_view, 350> slovenian_female_first_names;
extern const std::array<std::string_view, 350> slovenian_last_names;
extern const NameFormats slovenian_name_formats;
extern const PeopleNames slovenian_people_names;

// South Africa

extern const std::array<std::string_view, 113> south_african_male_first_names;
extern const std::array<std::string_view, 107> south_african_female_first_names;
extern const std::array<std::string_view, 162> south_african_last_names;
extern const NameFormats south_african_name_formats;
extern const PeopleNames south_african_people_names;

// Spain

extern const std::array<std::string_view, 113> spanish_male_first_names;
extern const std::array<std::string_view, 147> spanish_female_first_names;
extern const std::array<std::string_view, 625> spanish_last_names;
extern const std::array<std::string_view, 1> spanish_male_prefixes;
extern const std::array<std::string_view, 2> spanish_female_prefixes;
extern const NameFormats spanish_name_formats;
extern const PeopleNames spanish_people_names;

// Sweden

extern const std::array<std::string_view, 100> swedish_male_first_names;
extern const std::array<std::string_view, 100> swedish_female_first_names;
extern const std::array<std::string_view, 100> swedish_last_names;
extern const std::array<std::string_view, 3> swedish_prefixes;
extern const NameFormats swedish_name_formats;
extern const PeopleNames swedish_people_names;

// Switzerland

extern const std::array<std::string_view, 179> swiss_male_first_names;
extern const std::array<std::string_view, 138> swiss_female_first_names;
extern const std::array<std::string_view, 209> swiss_last_names;
extern const std::array<std::string_view, 3> swiss_male_prefixes;
extern const std::array<std::string_view, 3> swiss_female_prefixes;
extern const NameFormats swiss_name_formats;
extern const PeopleNames swiss_people_names;

// Syria

extern const std::array<std::string_view, 350> syrian_male_first_names;
extern const std::array<std::string_view, 350> syrian_female_first_names;
extern const std::array<std::string_view, 350> syrian_last_names;
extern const NameFormats syrian_name_formats;
extern const PeopleNames syrian_people_names;

// Turkey

extern const std::array<std::string_view, 44> turkish_male_first_names;
extern const std::array<std::string_view, 43> turkish_female_first_names;
extern const std::array<std::string_view, 52> turkish_last_names;
extern const std::array<std::string_view, 3> turkish_male_prefixes;
extern const std::array<std::string_view, 3> turkish_female_prefixes;
extern const NameFormats turkish_person_name_formats;
extern const PeopleNames turkish_people_names;

// Ukraine

extern const std::array<std::string_view, 195> ukrainian_male_first_names;
extern const std::array<std::string_view, 192> ukrainian_female_first_names;
extern const std::array<std::string_view, 239> ukrainian_males_last_names;
extern const std::array<std::string_view, 230> ukrainian_female_last_names;
extern const std::array<std::string_view, 116> ukrainian_male_middle_names;
extern const std::array<std::string_view, 116> ukrainian_female_middle_names;
extern const std::array<std::string_view, 1> ukrainian_male_prefixes;
extern const std::array<std::string_view, 1> ukrainian_female_prefixes;
extern const NameFormats ukrainian_name_formats;
extern const PeopleNames ukrainian_people_names;

// USA

extern const NameFormats usa_name_formats;
extern const PeopleNames usa_people_names;

// Vietnam

extern const std::array<std::string_view, 1224> vietnamese_male_first_names;
extern const std::array<std::string_view, 1300> vietnamese_female_first_names;
extern const std::array<std::string_view, 27> vietnamese_last_names;
extern const NameFormats vietnamese_name_formats;
extern const PeopleNames vietnamese_people_names;

// Mapping

extern const std::unordered_map<country_t, PeopleNames> people_names;

}

#endif