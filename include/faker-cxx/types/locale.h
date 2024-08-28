#pragma once

#include <string>
#include <unordered_map>
#include <vector>

namespace faker
{
enum class Locale
{
    af_ZA, // Afrikaans, South Africa
    ar_AE, // Arabic, United Arab Emirates
    ar_BH, // Arabic, Bahrain
    ar_DZ, // Arabic, Algeria
    ar_EG, // Arabic, Egypt
    ar_IQ, // Arabic, Iraq
    ar_JO, // Arabic, Jordan
    ar_KW, // Arabic, Kuwait
    ar_LB, // Arabic, Lebanon
    ar_LY, // Arabic, Libya
    ar_MA, // Arabic, Morocco
    ar_OM, // Arabic, Oman
    ar_PS, // Arabic, Palestinian Territory
    ar_QA, // Arabic, Qatar
    ar_SA, // Arabic, Saudi Arabia
    ar_SY, // Arabic, Syria
    ar_TN, // Arabic, Tunisia
    ar_YE, // Arabic, Yemen
    as_IN, // Assamese, India
    az_AZ, // Azerbaijani, Azerbaijan
    be_BY, // Belarusian, Belarus
    bg_BG, // Bulgarian, Bulgaria
    bn_IN, // Bengali, India
    bs_BA, // Bosnian, Bosnia and Herzegovina
    ca_ES, // Catalan, Spain
    cs_CZ, // Czech, Czech Republic
    da_DK, // Danish, Denmark
    de_AT, // German, Austria
    de_BE, // German, Belgium
    de_CH, // German, Switzerland
    de_DE, // German, Germany
    de_LI, // German, Liechtenstein
    de_LU, // German, Luxembourg
    dv_MV, // Divehi, Maldives
    el_CY, // Greek, Cyprus
    el_GR, // Greek, Greece
    en_AU, // English, Australia
    en_BW, // English, Botswana
    en_CA, // English, Canada
    en_GB, // English, United Kingdom
    en_GH, // English, Ghana
    en_HK, // English, Hong Kong SAR China
    en_IE, // English, Ireland
    en_IN, // English, India
    en_MT, // English, Malta
    en_NZ, // English, New Zealand
    en_PH, // English, Philippines
    en_SG, // English, Singapore
    en_US, // English, U.S.A.
    en_ZW, // English, Zimbabwe
    es_AR, // Spanish, Argentina
    es_BO, // Spanish, Bolivia
    es_CL, // Spanish, Chile
    es_CO, // Spanish, Colombia
    es_CR, // Spanish, Costa Rica
    es_DO, // Spanish, Dominican Republic
    es_EC, // Spanish, Ecuador
    es_ES, // Spanish, Spain
    es_GT, // Spanish, Guatemala
    es_HN, // Spanish, Honduras
    es_MX, // Spanish, Mexico
    es_NI, // Spanish, Nicaragua
    es_PA, // Spanish, Panama
    es_PE, // Spanish, Peru
    es_PR, // Spanish, Puerto Rico
    es_PY, // Spanish, Paraguay
    es_SV, // Spanish, El Salvador
    es_US, // Spanish, U.S.A.
    es_UY, // Spanish, Uruguay
    es_VE, // Spanish, Venezuela
    et_EE, // Estonian, Estonia
    fi_FI, // Finnish, Finland
    fr_BE, // French, Belgium
    fr_CA, // French, Canada
    fr_CH, // French, Switzerland
    fr_FR, // French, France
    fr_LU, // French, Luxembourg
    fr_MC, // French, Monaco
    ga_IE, // Irish, Ireland
    gu_IN, // Gujarati, India
    he_IL, // Hebrew, Israel
    hi_IN, // Hindi, India
    hr_HR, // Croatian, Croatia
    hu_HU, // Hungarian, Hungary
    hy_AM, // Armenian, Armenia
    id_ID, // Indonesian, Indonesia
    is_IS, // Icelandic, Iceland
    it_CH, // Italian, Switzerland
    it_IT, // Italian, Italy
    ja_JP, // Japanese, Japan
    ka_GE, // Georgian, Georgia
    kk_KZ, // Kazakh, Kazakhstan
    kn_IN, // Kannada, India
    ko_KR, // Korean, Korea
    ks_IN, // Kashmiri, India
    ku_TR, // Kurdish, Turkey
    ky_KG, // Kirghiz, Kyrgyzstan
    lt_LT, // Lithuanian, Lithuania
    lv_LV, // Latvian, Latvia
    mk_MK, // Macedonian, Macedonia
    ml_IN, // Malayalam, India
    mr_IN, // Marathi, India
    ms_MY, // Malay, Malaysia
    mt_MT, // Maltese, Malta
    nb_NO, // Bokmal, Norway
    ne_NP, // Nepali, Nepal
    nl_BE, // Dutch, Belgium
    nl_NL, // Dutch, Netherlands
    nn_NO, // Nynorsk, Norway
    or_IN, // Oriya, India
    pa_IN, // Punjabi, India
    pl_PL, // Polish, Poland
    pt_BR, // Portuguese, Brazil
    pt_PT, // Portuguese, Portugal
    ro_RO, // Romanian, Romania
    ro_MD, // Romanian, Moldova
    ru_RU, // Russian, Russia
    ru_UA, // Russian, Ukraine
    sa_IN, // Sanskrit, India
    sk_SK, // Slovak, Slovakia
    sl_SI, // Slovenian, Slovenia
    sq_AL, // Albanian, Albania
    sr_ME, // Serbian, Montenegro
    sr_RS, // Serbian, Serbia
    sv_SE, // Swedish, Sweden
    ta_IN, // Tamil, India
    te_IN, // Telugu, India
    th_TH, // Thai, Thailand
    tr_TR, // Turkish, Turkey
    uk_UA, // Ukrainian, Ukraine
    vi_VN, // Vietnamese, Vietnam
    zh_CN, // Simplified Chinese, China
    zh_HK, // Traditional Chinese, Hong Kong SAR China
    zh_SG, // Chinese, Singapore
    zh_TW  // Traditional Chinese, Taiwan
};

const std::vector<Locale> locales{
    Locale::af_ZA, Locale::ar_AE, Locale::ar_BH, Locale::ar_DZ, Locale::ar_EG, Locale::ar_IQ, Locale::ar_JO,
    Locale::ar_KW, Locale::ar_LY, Locale::ar_MA, Locale::ar_OM, Locale::ar_QA, Locale::ar_SA, Locale::ar_TN,
    Locale::ar_YE, Locale::as_IN, Locale::az_AZ, Locale::be_BY, Locale::bg_BG, Locale::bn_IN, Locale::bs_BA,
    Locale::ca_ES, Locale::cs_CZ, Locale::da_DK, Locale::de_AT, Locale::de_BE, Locale::de_CH, Locale::de_DE,
    Locale::de_LI, Locale::de_LU, Locale::el_CY, Locale::el_GR, Locale::en_AU, Locale::en_BW, Locale::en_CA,
    Locale::en_GB, Locale::en_HK, Locale::en_IE, Locale::en_IN, Locale::en_MT, Locale::en_NZ, Locale::en_PH,
    Locale::en_SG, Locale::en_US, Locale::en_ZW, Locale::es_AR, Locale::es_BO, Locale::es_CL, Locale::es_CO,
    Locale::es_CR, Locale::es_DO, Locale::es_EC, Locale::es_ES, Locale::es_GT, Locale::es_HN, Locale::es_MX,
    Locale::es_NI, Locale::es_PA, Locale::es_PE, Locale::es_PR, Locale::es_PY, Locale::es_SV, Locale::es_US,
    Locale::es_UY, Locale::es_VE, Locale::et_EE, Locale::fi_FI, Locale::fr_BE, Locale::fr_CA, Locale::fr_CH,
    Locale::fr_FR, Locale::fr_LU, Locale::gu_IN, Locale::he_IL, Locale::hi_IN, Locale::hr_HR, Locale::hu_HU,
    Locale::hy_AM, Locale::id_ID, Locale::is_IS, Locale::it_CH, Locale::it_IT, Locale::ja_JP, Locale::ka_GE,
    Locale::kk_KZ, Locale::kn_IN, Locale::ko_KR, Locale::ks_IN, Locale::ku_TR, Locale::ky_KG, Locale::lt_LT,
    Locale::lv_LV, Locale::mk_MK, Locale::ml_IN, Locale::mr_IN, Locale::ms_MY, Locale::mt_MT, Locale::nb_NO,
    Locale::nl_BE, Locale::nl_NL, Locale::nn_NO, Locale::or_IN, Locale::pa_IN, Locale::pl_PL, Locale::pt_BR,
    Locale::pt_PT, Locale::ro_RO, Locale::ru_RU, Locale::ru_UA, Locale::sa_IN, Locale::sk_SK, Locale::sl_SI,
    Locale::sq_AL, Locale::sr_ME, Locale::sr_RS, Locale::sv_SE, Locale::ta_IN, Locale::te_IN, Locale::th_TH,
    Locale::tr_TR, Locale::uk_UA, Locale::vi_VN, Locale::zh_CN, Locale::zh_HK, Locale::zh_SG, Locale::zh_TW,
};

inline std::string toString(Locale locale)
{
    std::unordered_map<Locale, std::string> localeToStringMapping{
        {Locale::af_ZA, "af_ZA"}, {Locale::ar_AE, "ar_AE"}, {Locale::ar_BH, "ar_BH"}, {Locale::ar_DZ, "ar_DZ"},
        {Locale::ar_EG, "ar_EG"}, {Locale::ar_IQ, "ar_IQ"}, {Locale::ar_JO, "ar_JO"}, {Locale::ar_KW, "ar_KW"},
        {Locale::ar_LY, "ar_LY"}, {Locale::ar_MA, "ar_MA"}, {Locale::ar_OM, "ar_OM"}, {Locale::ar_QA, "ar_QA"},
        {Locale::ar_SA, "ar_SA"}, {Locale::ar_TN, "ar_TN"}, {Locale::ar_YE, "ar_YE"}, {Locale::as_IN, "as_IN"},
        {Locale::az_AZ, "az_AZ"}, {Locale::be_BY, "be_BY"}, {Locale::bg_BG, "bg_BG"}, {Locale::bn_IN, "bn_IN"},
        {Locale::bs_BA, "bs_BA"}, {Locale::ca_ES, "ca_ES"}, {Locale::cs_CZ, "cs_CZ"}, {Locale::da_DK, "da_DK"},
        {Locale::de_AT, "de_AT"}, {Locale::de_BE, "de_BE"}, {Locale::de_CH, "de_CH"}, {Locale::de_DE, "de_DE"},
        {Locale::de_LI, "de_LI"}, {Locale::de_LU, "de_LU"}, {Locale::el_CY, "el_CY"}, {Locale::el_GR, "el_GR"},
        {Locale::en_AU, "en_AU"}, {Locale::en_BW, "en_BW"}, {Locale::en_CA, "en_CA"}, {Locale::en_GB, "en_GB"},
        {Locale::en_HK, "en_HK"}, {Locale::en_IE, "en_IE"}, {Locale::en_IN, "en_IN"}, {Locale::en_MT, "en_MT"},
        {Locale::en_NZ, "en_NZ"}, {Locale::en_PH, "en_PH"}, {Locale::en_SG, "en_SG"}, {Locale::en_US, "en_US"},
        {Locale::en_ZW, "en_ZW"}, {Locale::es_AR, "es_AR"}, {Locale::es_BO, "es_BO"}, {Locale::es_CL, "es_CL"},
        {Locale::es_CO, "es_CO"}, {Locale::es_CR, "es_CR"}, {Locale::es_DO, "es_DO"}, {Locale::es_EC, "es_EC"},
        {Locale::es_ES, "es_ES"}, {Locale::es_GT, "es_GT"}, {Locale::es_HN, "es_HN"}, {Locale::es_MX, "es_MX"},
        {Locale::es_NI, "es_NI"}, {Locale::es_PA, "es_PA"}, {Locale::es_PE, "es_PE"}, {Locale::es_PR, "es_PR"},
        {Locale::es_PY, "es_PY"}, {Locale::es_SV, "es_SV"}, {Locale::es_US, "es_US"}, {Locale::es_UY, "es_UY"},
        {Locale::es_VE, "es_VE"}, {Locale::et_EE, "et_EE"}, {Locale::fi_FI, "fi_FI"}, {Locale::fr_BE, "fr_BE"},
        {Locale::fr_CA, "fr_CA"}, {Locale::fr_CH, "fr_CH"}, {Locale::fr_FR, "fr_FR"}, {Locale::fr_LU, "fr_LU"},
        {Locale::gu_IN, "gu_IN"}, {Locale::he_IL, "he_IL"}, {Locale::hi_IN, "hi_IN"}, {Locale::hr_HR, "hr_HR"},
        {Locale::hu_HU, "hu_HU"}, {Locale::hy_AM, "hy_AM"}, {Locale::id_ID, "id_ID"}, {Locale::is_IS, "is_IS"},
        {Locale::it_CH, "it_CH"}, {Locale::it_IT, "it_IT"}, {Locale::ja_JP, "ja_JP"}, {Locale::ka_GE, "ka_GE"},
        {Locale::kk_KZ, "kk_KZ"}, {Locale::kn_IN, "kn_IN"}, {Locale::ko_KR, "ko_KR"}, {Locale::ks_IN, "ks_IN"},
        {Locale::ku_TR, "ku_TR"}, {Locale::ky_KG, "ky_KG"}, {Locale::lt_LT, "lt_LT"}, {Locale::lv_LV, "lv_LV"},
        {Locale::mk_MK, "mk_MK"}, {Locale::ml_IN, "ml_IN"}, {Locale::mr_IN, "mr_IN"}, {Locale::ms_MY, "ms_MY"},
        {Locale::mt_MT, "mt_MT"}, {Locale::nb_NO, "nb_NO"}, {Locale::nl_BE, "nl_BE"}, {Locale::nl_NL, "nl_NL"},
        {Locale::nn_NO, "nn_NO"}, {Locale::or_IN, "or_IN"}, {Locale::pa_IN, "pa_IN"}, {Locale::pl_PL, "pl_PL"},
        {Locale::pt_BR, "pt_BR"}, {Locale::pt_PT, "pt_PT"}, {Locale::ro_RO, "ro_RO"}, {Locale::ru_RU, "ru_RU"},
        {Locale::ru_UA, "ru_UA"}, {Locale::sa_IN, "sa_IN"}, {Locale::sk_SK, "sk_SK"}, {Locale::sl_SI, "sl_SI"},
        {Locale::sq_AL, "sq_AL"}, {Locale::sr_ME, "sr_ME"}, {Locale::sr_RS, "sr_RS"}, {Locale::sv_SE, "sv_SE"},
        {Locale::ta_IN, "ta_IN"}, {Locale::te_IN, "te_IN"}, {Locale::th_TH, "th_TH"}, {Locale::tr_TR, "tr_TR"},
        {Locale::uk_UA, "uk_UA"}, {Locale::vi_VN, "vi_VN"}, {Locale::zh_CN, "zh_CN"}, {Locale::zh_HK, "zh_HK"},
        {Locale::zh_SG, "zh_SG"}, {Locale::zh_TW, "zh_TW"},
    };

    return localeToStringMapping.at(locale);
}

}
