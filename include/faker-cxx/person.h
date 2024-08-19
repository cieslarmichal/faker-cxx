#pragma once

#include <optional>
#include <string_view>

#include "faker-cxx/export.h"
#include "types/country.h"

namespace faker::person
{
enum class PassportCountry;
enum class Sex;
enum class SsnCountry;
enum class Language;

/**
 * @brief Returns a random first name.
 *
 * @param country The local country. Defaults to `Country::England`.
 * @param sex The optional sex to use.
 *
 * @returns First name starting with a capital letter.
 *
 * @code
 * faker::person::firstName() // "Michael"
 * faker::person::firstName(Country::England, Sex::Female) // "Emma"
 * faker::person::firstName(Country::England, Sex::Male) // "Arthur"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view firstName(std::optional<Country> country = std::nullopt,
                                            std::optional<Sex> sex = std::nullopt);

/**
 * @brief Returns a random last name.
 *
 * @param country The local country. Defaults to `Country::England`.
 * @param sex The optional sex to use.
 *
 * @returns Last name starting with a capital letter.
 *
 * @code
 * faker::person::lastName() // "Peterson"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view lastName(std::optional<Country> country = std::nullopt,
                                           std::optional<Sex> sex = std::nullopt);

/**
 * @brief Returns a random full name.
 *
 * @param country The local country. Defaults to `Country::England`.
 * @param sex The optional sex to use.
 *
 * @returns Full name starting with first name.
 *
 * @code
 * faker::person::fullName() // "Marcia Robinson"
 * faker::person::fullName(Country::England, Sex::Female) // "Jennifer Martin"
 * faker::person::fullName(Country::England, Sex::Male) // "Samuel Walker"
 * @endcode
 */
FAKER_CXX_EXPORT std::string fullName(std::optional<Country> country = std::nullopt,
                                      std::optional<Sex> sex = std::nullopt);

/**
 * @brief Returns a random name prefix.
 *
 * @param sex The optional sex to use.
 *
 * @returns Name prefix.
 *
 * @code
 * faker::person::prefix() // "Miss"
 * faker::person::prefix(Sex::Female) // "Ms."
 * faker::person::prefix(Sex::Male) // "Mr."
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view prefix(std::optional<Country> country = std::nullopt,
                                         std::optional<Sex> sex = std::nullopt);

/**
 * @brief Returns a random name suffix.
 *
 * @returns Name suffix.
 *
 * @code
 * faker::person::suffix() // "Jr."
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view suffix(std::optional<Country> country = std::nullopt,
                                         std::optional<Sex> sex = std::nullopt);

/**
 * @brief Returns a random bio.
 *
 * @returns Bio.
 *
 * @code
 * faker::person::bio() //"Developer"
 * @endcode
 */
FAKER_CXX_EXPORT std::string bio();

/**
 * @brief Returns a sex.
 *
 * @returns Sex.
 *
 * @code
 * faker::person::sex() // "Male"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view sex(std::optional<Language> language = std::nullopt);

/**
 * @brief Returns a random gender.
 *
 * @returns Gender.
 *
 * @code
 * faker::person::gender() // "Transexual woman"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view gender();

/**
 * @brief Returns a random job title.
 *
 * @returns Job title.
 *
 * @code
 * faker::person::jobTitle() // "Global Accounts Engineer"
 * @endcode
 */
FAKER_CXX_EXPORT std::string jobTitle();

/**
 * @brief Returns a random job descriptor.
 *
 * @returns Job descriptor.
 *
 * @code
 * faker::person::jobDescriptor() // "Senior"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view jobDescriptor();

/**
 * @brief Returns a random job area.
 *
 * @returns Job area.
 *
 * @code
 * faker::person::jobArea() // "Software"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view jobArea();

/**
 * @brief Returns a random job type.
 *
 * @returns Job type.
 *
 * @code
 * faker::person::jobType() // "Engineer"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view jobType();

/**
 * @brief Returns a random hobby.
 *
 * @returns Hobby.
 *
 * @code
 * faker::person::hobby() // "Gaming"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view hobby();

/**
 * @brief Returns a random language.
 *
 * @returns Language.
 *
 * @code
 * faker::person::language() // "Polish"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view language();

/**
 * @brief Returns a random nationality.
 *
 * @returns Nationality.
 *
 * @code
 * faker::person::nationality() // "Romanian"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view nationality();

/**
 * @brief Returns a random SSN.
 *
 * @param country The optional country to use.
 *
 * @returns Social Security Number.
 *
 * @code
 * faker::person::ssn() // "437-12-6854"
 * faker::person::ssn(SsnCountry::Polish) // "95111901567"
 * @endcode
 */
FAKER_CXX_EXPORT std::string ssn(std::optional<SsnCountry> country = std::nullopt);

/**
 * @brief Returns a random Western Zodiac
 *
 * @returns Western Zodiac
 *
 * @code
 * faker::person::westernZodiac() // "Virgo"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view westernZodiac();

/**
 * @brief Returns a random Chinese Zodiac
 *
 * @returns Chinese Zodiac
 *
 * @code
 * faker::person::chineseZodiac() // "Dragon"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view chineseZodiac();

/**
 * @brief Returns a random passport number from a given country
 *
 * @returns Passport
 *
 * @code
 * faker::person::passport(PassportCountry::Romania) // "12345678"
 * @endcode
 */
FAKER_CXX_EXPORT std::string passport(std::optional<PassportCountry> country = std::nullopt);

enum class PassportCountry
{
    France,
    Poland,
    Romania,
    Usa,
};

enum class Sex
{
    Female,
    Male,
};

enum class SsnCountry
{
    England,
    France,
    Germany,
    India,
    Italy,
    Poland,
    Spain,
    Usa,
};

enum class Language
{
    Albanian,
    Belarusian,
    Croatian,
    Czech,
    Danish,
    Dutch,
    English,
    Estonian,
    Finnish,
    French,
    German,
    Greek,
    Hindi,
    Hungarian,
    Irish,
    Italian,
    Japanese,
    Korean,
    Latvian,
    Macedonian,
    Mandarin,
    Nepali,
    Norwegian,
    Polish,
    Portuguese,
    Romanian,
    Russian,
    Serbian,
    Slovak,
    Slovene,
    Spanish,
    Swedish,
    Turkish,
    Ukrainian,
};

enum class Locale
{
    af_ZA,        // Afrikaans, South Africa
    ar_AE,        // Arabic, United Arab Emirates
    ar_BH,        // Arabic, Bahrain
    ar_DZ,        // Arabic, Algeria
    ar_EG,        // Arabic, Egypt
    ar_IQ,        // Arabic, Iraq
    ar_JO,        // Arabic, Jordan
    ar_KW,        // Arabic, Kuwait
    ar_LY,        // Arabic, Libya
    ar_MA,        // Arabic, Morocco
    ar_OM,        // Arabic, Oman
    ar_QA,        // Arabic, Qatar
    ar_SA,        // Arabic, Saudi Arabia
    ar_TN,        // Arabic, Tunisia
    ar_YE,        // Arabic, Yemen
    as_IN,        // Assamese, India
    az_AZ,        // Azerbaijani, Azerbaijan
    be_BY,        // Belarusian, Belarus
    bg_BG,        // Bulgarian, Bulgaria
    bn_IN,        // Bengali, India
    bs_BA,        // Bosnian, Bosnia and Herzegovina
    ca_ES,        // Catalan, Spain
    cs_CZ,        // Czech, Czech Republic
    da_DK,        // Danish, Denmark
    de_AT,        // German, Austria
    de_BE,        // German, Belgium
    de_CH,        // German, Switzerland
    de_DE,        // German, Germany
    de_LI,        // German, Liechtenstein
    de_LU,        // German, Luxembourg
    el_CY,        // Greek, Cyprus
    el_GR,        // Greek, Greece
    en_AU,        // English, Australia
    en_BW,        // English, Botswana
    en_CA,        // English, Canada
    en_GB,        // English, United Kingdom
    en_HK,        // English, Hong Kong SAR China
    en_IE,        // English, Ireland
    en_IN,        // English, India
    en_MT,        // English, Malta
    en_NZ,        // English, New Zealand
    en_PH,        // English, Philippines
    en_SG,        // English, Singapore
    en_US,        // English, U.S.A.
    en_ZW,        // English, Zimbabwe
    es_AR,        // Spanish, Argentina
    es_BO,        // Spanish, Bolivia
    es_CL,        // Spanish, Chile
    es_CO,        // Spanish, Colombia
    es_CR,        // Spanish, Costa Rica
    es_DO,        // Spanish, Dominican Republic
    es_EC,        // Spanish, Ecuador
    es_ES,        // Spanish, Spain
    es_GT,        // Spanish, Guatemala
    es_HN,        // Spanish, Honduras
    es_MX,        // Spanish, Mexico
    es_NI,        // Spanish, Nicaragua
    es_PA,        // Spanish, Panama
    es_PE,        // Spanish, Peru
    es_PR,        // Spanish, Puerto Rico
    es_PY,        // Spanish, Paraguay
    es_SV,        // Spanish, El Salvador
    es_US,        // Spanish, U.S.A.
    es_UY,        // Spanish, Uruguay
    es_VE,        // Spanish, Venezuela
    et_EE,        // Estonian, Estonia
    fi_FI,        // Finnish, Finland
    fr_BE,        // French, Belgium
    fr_CA,        // French, Canada
    fr_CH,        // French, Switzerland
    fr_FR,        // French, France
    fr_LU,        // French, Luxembourg
    gu_IN,        // Gujarati, India
    he_IL,        // Hebrew, Israel
    hi_IN,        // Hindi, India
    hr_HR,        // Croatian, Croatia
    hu_HU,        // Hungarian, Hungary
    hy_AM,        // Armenian, Armenia
    id_ID,        // Indonesian, Indonesia
    is_IS,        // Icelandic, Iceland
    it_CH,        // Italian, Switzerland
    it_IT,        // Italian, Italy
    ja_JP,        // Japanese, Japan
    ka_GE,        // Georgian, Georgia
    kk_KZ,        // Kazakh, Kazakhstan
    kn_IN,        // Kannada, India
    ko_KR,        // Korean, Korea
    ks_IN,        // Kashmiri, India
    ku_TR,        // Kurdish, Turkey
    ku_TR_sorani, // Kurdish (Sorani), Turkey
    ky_KG,        // Kirghiz, Kyrgyzstan
    lt_LT,        // Lithuanian, Lithuania
    lv_LV,        // Latvian, Latvia
    mk_MK,        // Macedonian, Macedonia
    ml_IN,        // Malayalam, India
    mr_IN,        // Marathi, India
    ms_MY,        // Malay, Malaysia
    mt_MT,        // Maltese, Malta
    nb_NO,        // Bokmal, Norway
    nl_BE,        // Dutch, Belgium
    nl_NL,        // Dutch, Netherlands
    nn_NO,        // Nynorsk, Norway
    or_IN,        // Oriya, India
    pa_IN,        // Punjabi, India
    pl_PL,        // Polish, Poland
    pt_BR,        // Portuguese, Brazil
    pt_PT,        // Portuguese, Portugal
    ro_RO,        // Romanian, Romania
    ru_RU,        // Russian, Russia
    ru_UA,        // Russian, Ukraine
    sa_IN,        // Sanskrit, India
    sk_SK,        // Slovak, Slovakia
    sl_SI,        // Slovenian, Slovenia
    sq_AL,        // Albanian, Albania
    sr_ME,        // Serbian, Montenegro
    sr_ME_latin,  // Serbian, Montenegro (Latin)
    sr_RS,        // Serbian, Serbia
    sr_RS_latin,  // Serbian, Serbia (Latin)
    sv_SE,        // Swedish, Sweden
    ta_IN,        // Tamil, India
    te_IN,        // Telugu, India
    th_TH,        // Thai, Thailand
    tr_TR,        // Turkish, Turkey
    uk_UA,        // Ukrainian, Ukraine
    vi_VN,        // Vietnamese, Vietnam
    zh_CN,        // Simplified Chinese, China
    zh_HK,        // Traditional Chinese, Hong Kong SAR China
    zh_SG,        // Chinese, Singapore
    zh_TW         // Traditional Chinese, Taiwan
};
}
