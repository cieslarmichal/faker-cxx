#pragma once

#include <string>
#include <unordered_map>
#include <vector>
#include <set>

namespace faker
{
enum class Locale
{
    af_ZA,  // Afrikaans, South Africa
    am_ET,  // Amharic, Ethiopia
    ar_AE,  // Arabic, United Arab Emirates
    ar_BH,  // Arabic, Bahrain
    ar_DZ,  // Arabic, Algeria
    ar_EG,  // Arabic, Egypt
    ar_IQ,  // Arabic, Iraq
    ar_JO,  // Arabic, Jordan
    ar_KW,  // Arabic, Kuwait
    ar_LB,  // Arabic, Lebanon
    ar_LY,  // Arabic, Libya
    ar_MA,  // Arabic, Morocco
    ar_OM,  // Arabic, Oman
    ar_PS,  // Arabic, Palestinian Territory
    ar_QA,  // Arabic, Qatar
    ar_SA,  // Arabic, Saudi Arabia
    ar_SD,  // Arabic, Sudan
    ar_SY,  // Arabic, Syria
    ar_TN,  // Arabic, Tunisia
    ar_YE,  // Arabic, Yemen
    arn_CL, // Mapudungun, Chile
    as_IN,  // Assamese, India
    az_AZ,  // Azerbaijani, Azerbaijan
    ba_RU,  // Bashkir, Russia
    be_BY,  // Belarusian, Belarus
    bg_BG,  // Bulgarian, Bulgaria
    bn_BD,  // Bengali, Bangladesh
    bn_IN,  // Bengali, India
    bo_CN,  // Tibetan, China
    br_FR,  // Breton, France
    bs_BA,  // Bosnian, Bosnia and Herzegovina
    ca_ES,  // Catalan, Spain
    co_FR,  // Corsican, France
    cs_CZ,  // Czech, Czech Republic
    cy_GB,  // Welsh, United Kingdom
    da_DK,  // Danish, Denmark
    de_AT,  // German, Austria
    de_BE,  // German, Belgium
    de_CH,  // German, Switzerland
    de_DE,  // German, Germany
    de_LI,  // German, Liechtenstein
    de_LU,  // German, Luxembourg
    dsb_DE, // Lower Sorbian, Germany
    dv_MV,  // Divehi, Maldives
    el_CY,  // Greek, Cyprus
    el_GR,  // Greek, Greece
    en_029, // English, Caribbean
    en_AU,  // English, Australia
    en_BW,  // English, Botswana
    en_BZ,  // English, Belize
    en_CA,  // English, Canada
    en_cb,  // English, Caribbean
    en_GB,  // English, United Kingdom
    en_GH,  // English, Ghana
    en_HK,  // English, Hong Kong SAR China
    en_IE,  // English, Ireland
    en_IN,  // English, India
    en_JM,  // English, Jamaica
    en_MT,  // English, Malta
    en_MY,  // English, Malaysia
    en_NZ,  // English, New Zealand
    en_PH,  // English, Philippines
    en_SG,  // English, Singapore
    en_TT,  // English, Trinidad and Tobago
    en_US,  // English, U.S.A.
    en_ZA,  // English, South Africa
    en_ZW,  // English, Zimbabwe
    es_AR,  // Spanish, Argentina
    es_BO,  // Spanish, Bolivia
    es_CL,  // Spanish, Chile
    es_CO,  // Spanish, Colombia
    es_CR,  // Spanish, Costa Rica
    es_DO,  // Spanish, Dominican Republic
    es_EC,  // Spanish, Ecuador
    es_ES,  // Spanish, Spain
    es_GT,  // Spanish, Guatemala
    es_HN,  // Spanish, Honduras
    es_MX,  // Spanish, Mexico
    es_NI,  // Spanish, Nicaragua
    es_PA,  // Spanish, Panama
    es_PE,  // Spanish, Peru
    es_PR,  // Spanish, Puerto Rico
    es_PY,  // Spanish, Paraguay
    es_SV,  // Spanish, El Salvador
    es_US,  // Spanish, U.S.A.
    es_UY,  // Spanish, Uruguay
    es_VE,  // Spanish, Venezuela
    et_EE,  // Estonian, Estonia
    eu_ES,  // Basque, Spain
    fa_IR,  // Persian, Iran
    fi_FI,  // Finnish, Finland
    fil_PH, // Filipino, Philippines
    fo_FO,  // Faroese, Faroe Islands
    fr_BE,  // French, Belgium
    fr_CA,  // French, Canada
    fr_CH,  // French, Switzerland
    fr_FR,  // French, France
    fr_LU,  // French, Luxembourg
    fr_MC,  // French, Monaco
    fy_NL,  // Western Frisian, Netherlands
    ga_IE,  // Irish, Ireland
    gd_GB,  // Scottish Gaelic, United Kingdom
    gd_ie,  // Gaelic, Ireland
    gl_ES,  // Galician, Spain
    gsw_FR, // Swiss German, France
    gu_IN,  // Gujarati, India
    he_IL,  // Hebrew, Israel
    hi_IN,  // Hindi, India
    hr_BA,  // Croatian, Bosnia and Herzegovina
    hr_HR,  // Croatian, Croatia
    hsb_DE, // Upper Sorbian, Germany
    hu_HU,  // Hungarian, Hungary
    hy_AM,  // Armenian, Armenia
    id_ID,  // Indonesian, Indonesia
    ig_NG,  // Igbo, Nigeria
    ii_CN,  // Sichuan Yi, China
    in_ID,  // Indonesian, Indonesia
    is_IS,  // Icelandic, Iceland
    it_CH,  // Italian, Switzerland
    it_IT,  // Italian, Italy
    iw_IL,  // Hebrew, Israel
    ja_JP,  // Japanese, Japan
    ka_GE,  // Georgian, Georgia
    kk_KZ,  // Kazakh, Kazakhstan
    kl_GL,  // Kalaallisut, Greenland
    km_KH,  // Khmer, Cambodia
    kn_IN,  // Kannada, India
    ko_KR,  // Korean, Korea
    kok_IN, // Konkani, India
    ks_IN,  // Kashmiri, India
    ku_TR,  // Kurdish, Turkey
    ky_KG,  // Kirghiz, Kyrgyzstan
    lb_LU,  // Luxembourgish, Luxembourg
    lo_LA,  // Lao, Laos
    lt_LT,  // Lithuanian, Lithuania
    lv_LV,  // Latvian, Latvia
    mi_NZ,  // Maori, New Zealand
    mk_MK,  // Macedonian, Macedonia
    ml_IN,  // Malayalam, India
    mn_MN,  // Mongolian, Mongolia
    moh_CA, // Mohawk, Canada
    mr_IN,  // Marathi, India
    ms_BN,  // Malay, Brunei
    ms_MY,  // Malay, Malaysia
    mt_MT,  // Maltese, Malta
    nb_NO,  // Norwegian Bokmal, Norway
    ne_NP,  // Nepali, Nepal
    nl_BE,  // Dutch, Belgium
    nl_NL,  // Dutch, Netherlands
    nn_NO,  // Norwegian Nynorsk, Norway
    no_no,  // Norwegian, Norway
    nso_ZA, // Northern Sotho, South Africa
    oc_FR,  // Occitan, France
    or_IN,  // Oriya, India
    pa_IN,  // Punjabi, India
    pl_PL,  // Polish, Poland
    prs_AF, // Dari, Afghanistan
    ps_AF,  // Pashto, Afghanistan
    pt_BR,  // Portuguese, Brazil
    pt_PT,  // Portuguese, Portugal
    qut_GT, // K'iche, Guatemala
    quz_BO, // Quechua, Bolivia
    quz_EC, // Quechua, Ecuador
    quz_PE, // Quechua, Peru
    rm_CH,  // Romansh, Switzerland
    ro_MD,  // Romanian, Moldova
    ro_RO,  // Romanian, Romania
    ru_RU,  // Russian, Russia
    ru_UA,  // Russian, Ukraine
    rw_RW,  // Kinyarwanda, Rwanda
    sa_IN,  // Sanskrit, India
    sah_RU, // Sakha, Russia
    se_FI,  // Northern Sami, Finland
    se_NO,  // Northern Sami, Norway
    se_SE,  // Northern Sami, Sweden
    si_LK,  // Sinhala, Sri Lanka
    sk_SK,  // Slovak, Slovakia
    sl_SI,  // Slovenian, Slovenia
    sma_NO, // Southern Sami, Norway
    sma_SE, // Southern Sami, Sweden
    smj_NO, // Lule Sami, Norway
    smj_SE, // Lule Sami, Sweden
    smn_FI, // Inari Sami, Finland
    sms_FI, // Skolt Sami, Finland
    sq_AL,  // Albanian, Albania
    sr_BA,  // Serbian, Bosnia and Herzegovina
    sr_CS,  // Serbian, Serbia and Montenegro
    sr_ME,  // Serbian, Montenegro
    sr_RS,  // Serbian, Serbia
    sv_FI,  // Swedish, Finland
    sv_SE,  // Swedish, Sweden
    sw_KE,  // Swahili, Kenya
    syr_SY, // Syriac, Syria
    ta_IN,  // Tamil, India
    te_IN,  // Telugu, India
    th_TH,  // Thai, Thailand
    tk_TM,  // Turkmen, Turkmenistan
    tn_ZA,  // Tswana, South Africa
    tr_TR,  // Turkish, Turkey
    tt_RU,  // Tatar, Russian
    ug_CN,  // Uyghur, China
    uk_UA,  // Ukrainian, Ukraine
    ur_PK,  // Urdu, Pakistan
    uz_uz,  // Uzbek, Uzbekistan
    vi_VN,  // Vietnamese, Vietnam
    wo_SN,  // Wolof, Senegal
    xh_ZA,  // Xhosa, South Africa
    yo_NG,  // Yoruba, Nigeria
    zh_CN,  // Simplified Chinese, China
    zh_HK,  // Traditional Chinese, Hong Kong SAR China
    zh_MO,  // Traditional Chinese, Macao SAR China
    zh_SG,  // Simplified Chinese, Singapore
    zh_TW,  // Traditional Chinese, Taiwan
    zu_ZA   // Zulu, South Africa
};

const std::vector<Locale> locales{
    Locale::af_ZA, Locale::am_ET, Locale::ar_AE, Locale::ar_BH, Locale::ar_DZ, Locale::ar_EG, Locale::ar_IQ,
    Locale::ar_JO, Locale::ar_KW, Locale::ar_LB, Locale::ar_LY, Locale::ar_MA, Locale::ar_OM, Locale::ar_PS,
    Locale::ar_QA, Locale::ar_SA, Locale::ar_SD, Locale::ar_SY, Locale::ar_TN, Locale::ar_YE, Locale::arn_CL,
    Locale::as_IN, Locale::az_AZ, Locale::ba_RU, Locale::be_BY, Locale::bg_BG, Locale::bn_BD, Locale::bn_IN,
    Locale::bo_CN, Locale::br_FR, Locale::bs_BA, Locale::ca_ES, Locale::co_FR, Locale::cs_CZ, Locale::cy_GB,
    Locale::da_DK, Locale::de_AT, Locale::de_BE, Locale::de_CH, Locale::de_DE, Locale::de_LI, Locale::de_LU,
    Locale::dsb_DE, Locale::dv_MV, Locale::el_CY, Locale::el_GR, Locale::en_029, Locale::en_AU, Locale::en_BW,
    Locale::en_BZ, Locale::en_CA, Locale::en_cb, Locale::en_GB, Locale::en_GH, Locale::en_HK, Locale::en_IE,
    Locale::en_IN, Locale::en_JM, Locale::en_MT, Locale::en_MY, Locale::en_NZ, Locale::en_PH, Locale::en_SG,
    Locale::en_TT, Locale::en_US, Locale::en_ZA, Locale::en_ZW, Locale::es_AR, Locale::es_BO, Locale::es_CL,
    Locale::es_CO, Locale::es_CR, Locale::es_DO, Locale::es_EC, Locale::es_ES, Locale::es_GT, Locale::es_HN,
    Locale::es_MX, Locale::es_NI, Locale::es_PA, Locale::es_PE, Locale::es_PR, Locale::es_PY, Locale::es_SV,
    Locale::es_US, Locale::es_UY, Locale::es_VE, Locale::et_EE, Locale::eu_ES, Locale::fa_IR, Locale::fi_FI,
    Locale::fil_PH, Locale::fo_FO, Locale::fr_BE, Locale::fr_CA, Locale::fr_CH, Locale::fr_FR, Locale::fr_LU,
    Locale::fr_MC, Locale::fy_NL, Locale::ga_IE, Locale::gd_GB, Locale::gd_ie, Locale::gl_ES, Locale::gsw_FR,
    Locale::gu_IN, Locale::he_IL, Locale::hi_IN, Locale::hr_BA, Locale::hr_HR, Locale::hsb_DE, Locale::hu_HU,
    Locale::hy_AM, Locale::id_ID, Locale::ig_NG, Locale::ii_CN, Locale::in_ID, Locale::is_IS, Locale::it_CH,
    Locale::it_IT, Locale::iw_IL, Locale::ja_JP, Locale::ka_GE, Locale::kk_KZ, Locale::kl_GL, Locale::km_KH,
    Locale::kn_IN, Locale::ko_KR, Locale::kok_IN, Locale::ks_IN, Locale::ku_TR, Locale::ky_KG, Locale::lb_LU,
    Locale::lo_LA, Locale::lt_LT, Locale::lv_LV, Locale::mi_NZ, Locale::mk_MK, Locale::ml_IN, Locale::mn_MN,
    Locale::moh_CA, Locale::mr_IN, Locale::ms_BN, Locale::ms_MY, Locale::mt_MT, Locale::nb_NO, Locale::ne_NP,
    Locale::nl_BE, Locale::nl_NL, Locale::nn_NO, Locale::no_no, Locale::nso_ZA, Locale::oc_FR, Locale::or_IN,
    Locale::pa_IN, Locale::pl_PL, Locale::prs_AF, Locale::ps_AF, Locale::pt_BR, Locale::pt_PT, Locale::qut_GT,
    Locale::quz_BO, Locale::quz_EC, Locale::quz_PE, Locale::rm_CH, Locale::ro_MD, Locale::ro_RO, Locale::ru_RU,
    Locale::ru_UA, Locale::rw_RW, Locale::sa_IN, Locale::sah_RU, Locale::se_FI, Locale::se_NO, Locale::se_SE,
    Locale::si_LK, Locale::sk_SK, Locale::sl_SI, Locale::sma_NO, Locale::sma_SE, Locale::smj_NO, Locale::smj_SE,
    Locale::smn_FI, Locale::sms_FI, Locale::sq_AL, Locale::sr_BA, Locale::sr_CS, Locale::sr_ME, Locale::sr_RS,
    Locale::sv_FI, Locale::sv_SE, Locale::sw_KE, Locale::syr_SY, Locale::ta_IN, Locale::te_IN, Locale::th_TH,
    Locale::tk_TM, Locale::tn_ZA, Locale::tr_TR, Locale::tt_RU, Locale::ug_CN, Locale::uk_UA, Locale::ur_PK,
    Locale::uz_uz, Locale::vi_VN, Locale::wo_SN, Locale::xh_ZA, Locale::yo_NG, Locale::zh_CN, Locale::zh_HK,
    Locale::zh_MO, Locale::zh_SG, Locale::zh_TW, Locale::zu_ZA
};

inline const std::set<Locale> postCodeSet{
    Locale::cy_GB, Locale::gd_GB, Locale::en_GB, 
    Locale::en_CA, Locale::fr_CA, Locale::moh_CA,
    Locale::fy_NL, Locale::nl_NL,
    Locale::es_AR,
    Locale::ms_BN,
    Locale::mt_MT, Locale::en_MT
};

inline std::string toString(Locale locale)
{
    std::unordered_map<Locale, std::string> localeToStringMapping{
        {Locale::af_ZA, "af_ZA"}, {Locale::am_ET, "am_ET"}, {Locale::ar_AE, "ar_AE"}, {Locale::ar_BH, "ar_BH"},
        {Locale::ar_DZ, "ar_DZ"}, {Locale::ar_EG, "ar_EG"}, {Locale::ar_IQ, "ar_IQ"}, {Locale::ar_JO, "ar_JO"},
        {Locale::ar_KW, "ar_KW"}, {Locale::ar_LB, "ar_LB"}, {Locale::ar_LY, "ar_LY"}, {Locale::ar_MA, "ar_MA"},
        {Locale::ar_OM, "ar_OM"}, {Locale::ar_PS, "ar_PS"}, {Locale::ar_QA, "ar_QA"}, {Locale::ar_SA, "ar_SA"},
        {Locale::ar_SD, "ar_SD"}, {Locale::ar_SY, "ar_SY"}, {Locale::ar_TN, "ar_TN"}, {Locale::ar_YE, "ar_YE"},
        {Locale::arn_CL, "arn_CL"}, {Locale::as_IN, "as_IN"}, {Locale::az_AZ, "az_AZ"}, {Locale::ba_RU, "ba_RU"},
        {Locale::be_BY, "be_BY"}, {Locale::bg_BG, "bg_BG"}, {Locale::bn_BD, "bn_BD"}, {Locale::bn_IN, "bn_IN"},
        {Locale::bo_CN, "bo_CN"}, {Locale::br_FR, "br_FR"}, {Locale::bs_BA, "bs_BA"}, {Locale::ca_ES, "ca_ES"},
        {Locale::co_FR, "co_FR"}, {Locale::cs_CZ, "cs_CZ"}, {Locale::cy_GB, "cy_GB"}, {Locale::da_DK, "da_DK"},
        {Locale::de_AT, "de_AT"}, {Locale::de_BE, "de_BE"}, {Locale::de_CH, "de_CH"}, {Locale::de_DE, "de_DE"},
        {Locale::de_LI, "de_LI"}, {Locale::de_LU, "de_LU"}, {Locale::dsb_DE, "dsb_DE"}, {Locale::dv_MV, "dv_MV"},
        {Locale::el_CY, "el_CY"}, {Locale::el_GR, "el_GR"}, {Locale::en_029, "en_029"}, {Locale::en_AU, "en_AU"},
        {Locale::en_BW, "en_BW"}, {Locale::en_BZ, "en_BZ"}, {Locale::en_CA, "en_CA"}, {Locale::en_cb, "en_cb"},
        {Locale::en_GB, "en_GB"}, {Locale::en_GH, "en_GH"}, {Locale::en_HK, "en_HK"}, {Locale::en_IE, "en_IE"},
        {Locale::en_IN, "en_IN"}, {Locale::en_JM, "en_JM"}, {Locale::en_MT, "en_MT"}, {Locale::en_MY, "en_MY"},
        {Locale::en_NZ, "en_NZ"}, {Locale::en_PH, "en_PH"}, {Locale::en_SG, "en_SG"}, {Locale::en_TT, "en_TT"},
        {Locale::en_US, "en_US"}, {Locale::en_ZA, "en_ZA"}, {Locale::en_ZW, "en_ZW"}, {Locale::es_AR, "es_AR"},
        {Locale::es_BO, "es_BO"}, {Locale::es_CL, "es_CL"}, {Locale::es_CO, "es_CO"}, {Locale::es_CR, "es_CR"},
        {Locale::es_DO, "es_DO"}, {Locale::es_EC, "es_EC"}, {Locale::es_ES, "es_ES"}, {Locale::es_GT, "es_GT"},
        {Locale::es_HN, "es_HN"}, {Locale::es_MX, "es_MX"}, {Locale::es_NI, "es_NI"}, {Locale::es_PA, "es_PA"},
        {Locale::es_PE, "es_PE"}, {Locale::es_PR, "es_PR"}, {Locale::es_PY, "es_PY"}, {Locale::es_SV, "es_SV"},
        {Locale::es_US, "es_US"}, {Locale::es_UY, "es_UY"}, {Locale::es_VE, "es_VE"}, {Locale::et_EE, "et_EE"},
        {Locale::eu_ES, "eu_ES"}, {Locale::fa_IR, "fa_IR"}, {Locale::fi_FI, "fi_FI"}, {Locale::fil_PH, "fil_PH"},
        {Locale::fo_FO, "fo_FO"}, {Locale::fr_BE, "fr_BE"}, {Locale::fr_CA, "fr_CA"}, {Locale::fr_CH, "fr_CH"},
        {Locale::fr_FR, "fr_FR"}, {Locale::fr_LU, "fr_LU"}, {Locale::fr_MC, "fr_MC"}, {Locale::fy_NL, "fy_NL"},
        {Locale::ga_IE, "ga_IE"}, {Locale::gd_GB, "gd_GB"}, {Locale::gd_ie, "gd_ie"}, {Locale::gl_ES, "gl_ES"},
        {Locale::gsw_FR, "gsw_FR"}, {Locale::gu_IN, "gu_IN"}, {Locale::he_IL, "he_IL"}, {Locale::hi_IN, "hi_IN"},
        {Locale::hr_BA, "hr_BA"}, {Locale::hr_HR, "hr_HR"}, {Locale::hsb_DE, "hsb_DE"}, {Locale::hu_HU, "hu_HU"},
        {Locale::hy_AM, "hy_AM"}, {Locale::id_ID, "id_ID"}, {Locale::ig_NG, "ig_NG"}, {Locale::ii_CN, "ii_CN"},
        {Locale::in_ID, "in_ID"}, {Locale::is_IS, "is_IS"}, {Locale::it_CH, "it_CH"}, {Locale::it_IT, "it_IT"},
        {Locale::iw_IL, "iw_IL"}, {Locale::ja_JP, "ja_JP"}, {Locale::ka_GE, "ka_GE"}, {Locale::kk_KZ, "kk_KZ"},
        {Locale::kl_GL, "kl_GL"}, {Locale::km_KH, "km_KH"}, {Locale::kn_IN, "kn_IN"}, {Locale::ko_KR, "ko_KR"},
        {Locale::kok_IN, "kok_IN"}, {Locale::ks_IN, "ks_IN"}, {Locale::ku_TR, "ku_TR"}, {Locale::ky_KG, "ky_KG"},
        {Locale::lb_LU, "lb_LU"}, {Locale::lo_LA, "lo_LA"}, {Locale::lt_LT, "lt_LT"}, {Locale::lv_LV, "lv_LV"},
        {Locale::mi_NZ, "mi_NZ"}, {Locale::mk_MK, "mk_MK"}, {Locale::ml_IN, "ml_IN"}, {Locale::mn_MN, "mn_MN"},
        {Locale::moh_CA, "moh_CA"}, {Locale::mr_IN, "mr_IN"}, {Locale::ms_BN, "ms_BN"}, {Locale::ms_MY, "ms_MY"},
        {Locale::mt_MT, "mt_MT"}, {Locale::nb_NO, "nb_NO"}, {Locale::ne_NP, "ne_NP"}, {Locale::nl_BE, "nl_BE"},
        {Locale::nl_NL, "nl_NL"}, {Locale::nn_NO, "nn_NO"}, {Locale::no_no, "no_no"}, {Locale::nso_ZA, "nso_ZA"},
        {Locale::oc_FR, "oc_FR"}, {Locale::or_IN, "or_IN"}, {Locale::pa_IN, "pa_IN"}, {Locale::pl_PL, "pl_PL"},
        {Locale::prs_AF, "prs_AF"}, {Locale::ps_AF, "ps_AF"}, {Locale::pt_BR, "pt_BR"}, {Locale::pt_PT, "pt_PT"},
        {Locale::qut_GT, "qut_GT"}, {Locale::quz_BO, "quz_BO"}, {Locale::quz_EC, "quz_EC"}, {Locale::quz_PE, "quz_PE"},
        {Locale::rm_CH, "rm_CH"}, {Locale::ro_MD, "ro_MD"}, {Locale::ro_RO, "ro_RO"}, {Locale::ru_RU, "ru_RU"},
        {Locale::ru_UA, "ru_UA"}, {Locale::rw_RW, "rw_RW"}, {Locale::sa_IN, "sa_IN"}, {Locale::sah_RU, "sah_RU"},
        {Locale::se_FI, "se_FI"}, {Locale::se_NO, "se_NO"}, {Locale::se_SE, "se_SE"}, {Locale::si_LK, "si_LK"},
        {Locale::sk_SK, "sk_SK"}, {Locale::sl_SI, "sl_SI"}, {Locale::sma_NO, "sma_NO"}, {Locale::sma_SE, "sma_SE"},
        {Locale::smj_NO, "smj_NO"}, {Locale::smj_SE, "smj_SE"}, {Locale::smn_FI, "smn_FI"}, {Locale::sms_FI, "sms_FI"},
        {Locale::sq_AL, "sq_AL"}, {Locale::sr_BA, "sr_BA"}, {Locale::sr_CS, "sr_CS"}, {Locale::sr_ME, "sr_ME"},
        {Locale::sr_RS, "sr_RS"}, {Locale::sv_FI, "sv_FI"}, {Locale::sv_SE, "sv_SE"}, {Locale::sw_KE, "sw_KE"},
        {Locale::syr_SY, "syr_SY"}, {Locale::ta_IN, "ta_IN"}, {Locale::te_IN, "te_IN"}, {Locale::th_TH, "th_TH"},
        {Locale::tk_TM, "tk_TM"}, {Locale::tn_ZA, "tn_ZA"}, {Locale::tr_TR, "tr_TR"}, {Locale::tt_RU, "tt_RU"},
        {Locale::ug_CN, "ug_CN"}, {Locale::uk_UA, "uk_UA"}, {Locale::ur_PK, "ur_PK"}, {Locale::uz_uz, "uz_uz"},
        {Locale::vi_VN, "vi_VN"}, {Locale::wo_SN, "wo_SN"}, {Locale::xh_ZA, "xh_ZA"}, {Locale::yo_NG, "yo_NG"},
        {Locale::zh_CN, "zh_CN"}, {Locale::zh_HK, "zh_HK"}, {Locale::zh_MO, "zh_MO"}, {Locale::zh_SG, "zh_SG"},
        {Locale::zh_TW, "zh_TW"}, {Locale::zu_ZA, "zu_ZA"}
    };

    return localeToStringMapping.at(locale);
}
}
