#pragma once

#include <array>
#include <string_view>
#include <unordered_map>
#include <vector>

#include "faker-cxx/types/locale.h"

namespace faker::finance
{
const auto accountTypes = std::to_array<std::string_view>({
    "Auto Loan",
    "Checking",
    "Credit Card",
    "Home Loan",
    "Investment",
    "Money Market",
    "Personal Loan",
    "Savings",
});

const std::unordered_map<Locale, std::vector<std::string_view>> bicCountriesCodes = {
    {Locale::pl_PL,
     {"BPKOPLPW", "PKOPPLPW", "BREXPLPWMUL", "BNPAPLP", "POLUPLPR", "BIGBPLPW", "WBKPPLPP", "CITIPLPX", "INGBPLPW",
      "DEUTPLPK", "DEUTPLP"}},
    {Locale::en_US, {"BOFAUS3N", "CITIUS33", "WELLSFARGO", "USBKUS44", "CHASUS33", "HSBCUS33", "PNCCUS33"}},
    {Locale::en_GB, {"BARCGB22", "HSBCKENW", "LOYDGB21", "NWBKGB2L", "RBOSGB2L", "HSBCGB2L", "DEUTGB2L"}},
    {Locale::de_DE,
     {"DEUTDEFF", "DRESDEFF", "COBADEFF", "BYLADEM1", "GENODEFF", "HYVEDEMM", "MALADE51", "NOLADE21", "SOLADEST",
      "UNCRDEFF"}},
    {Locale::ro_RO, {"RNCBROBU", "BRDEROBU", "BTRLRO22", "PIRBROBU", "INGBROBU", "EXIMRO22", "CRDZROBU"}},
    {Locale::fr_FR,
     {"BNPAFRPP", "CEPAFRPP", "CRLYFRPP", "SOGEFRPP", "AGRIFRPP", "HSBDFRPP", "CCFRFRPP", "BNORDRPP", "CMCIFRPP"}},
    {Locale::it_IT, {"UNCRITMM", "BCITITMM", "INTESA", "UBSPITPA", "BLOPIT22", "CITIITMX", "BNLIITRR"}},
    {Locale::es_ES, {"CAIXESBB", "BBVAESMM", "SABSESBB", "BSCHESMM", "POPUESMM", "INGDESMM", "CITIES2X", "BCOEESMM"}},
    {Locale::nl_NL, {"ABNANL2A", "INGBNL2A", "RABONL2U", "TRIONL2U", "KNABNL2H", "SBINNL2X", "DEUTNL2N"}},
    {
        Locale::hi_IN,
        {"HDFCINBB", "ICICINBB", "SBININBB", "PNBAINBB", "UBININBB", "AXISINBB", "KKBKINBB", "YESBINBB", "IDBIINBB"},
    },
};

// Iban format structure from https://bank.codes/iban/structure/
// Note: a - alphabets (letters only), c - characters (letters & numbers), n - numbers (numbers only)
const std::unordered_map<Locale, std::vector<std::string_view>> ibanFormats{
    {Locale::de_AT, {"AT", "2n", "5n", "11n"}},
    {Locale::de_BE, {"BE", "2n", "3n", "7n", "2n"}},
    {Locale::bg_BG, {"BG", "2n", "4a", "4n", "2n", "8c"}},
    {Locale::hr_HR, {"HR", "2n", "7n", "10n"}},
    {Locale::el_CY, {"CY", "2n", "3n", "5n", "16c"}},
    {Locale::cs_CZ, {"CZ", "2n", "4n", "6n", "10n"}},
    {Locale::da_DK, {"DK", "2n", "4n", "9n", "1n"}},
    {Locale::et_EE, {"EE", "2n", "2n", "2n", "11n", "1n"}},
    {Locale::fi_FI, {"FI", "2n", "6n", "7n", "1n"}},
    {Locale::fr_FR, {"FR", "2n", "5n", "5n", "11c", "2n"}},
    {Locale::de_DE, {"DE", "2n", "8n", "10n"}},
    {Locale::el_GR, {"GR", "2n", "3n", "4n", "16c"}},
    {Locale::hu_HU, {"HU", "2n", "3n", "4n", "1n", "15n", "1n"}},
    {Locale::en_IE, {"IE", "2n", "4a", "6n", "8n"}},
    {Locale::it_IT, {"IT", "2n", "1a", "5n", "5n", "12c"}},
    {Locale::lv_LV, {"LV", "2n", "4a", "13n"}},
    {Locale::lt_LT, {"LT", "2n", "5n", "11n"}},
    {Locale::de_LU, {"LU", "2n", "3n", "13c"}},
    {Locale::en_MT, {"MT", "2n", "4a", "5n", "18c"}},
    {Locale::nl_NL, {"NL", "2n", "4a", "10n"}},
    {Locale::pl_PL, {"PL", "2n", "3n", "4n", "1n", "16n"}},
    {Locale::pt_PT, {"PT", "2n", "4n", "4n", "11n", "2n"}},
    {Locale::ro_RO, {"RO", "2n", "4a", "16c"}},
    {Locale::sk_SK, {"SK", "2n", "4n", "6n", "10n"}},
    {Locale::sl_SI, {"SI", "2n", "2n", "3n", "8n", "2n"}},
    {Locale::es_ES, {"ES", "2n", "4n", "4n", "2n", "10n"}},
    {Locale::sv_SE, {"SE", "2n", "3n", "16n", "1n"}},
};

const auto americanExpressCreditCardFormats = std::to_array<std::string_view>({
    "34##-######-####L",
    "37##-######-####L",
});

const auto discoverCreditCardFormats = std::to_array<std::string_view>({
    "6011-####-####-###L",
    "6011-62##-####-####-###L",
    "64[4-9]#-####-####-###L",
    "64[4-9]#-62##-####-####-###L",
    "65##-####-####-###L",
    "65##-62##-####-####-###L",
});

const auto masterCardCreditCardFormats = std::to_array<std::string_view>({
    "5[1-5]##-####-####-###L",
    "6771-89##-####-###L",
});

const auto visaCreditCardFormats = std::to_array<std::string_view>({
    "4###########L",
    "4###-####-####-###L",
});

const auto creditCardNames = std::to_array<std::string_view>({
    "American Express",
    "Discover",
    "MasterCard",
    "Visa",
});

const auto currencies = std::to_array<Currency>({
    {
        "UAE Dirham",
        "AED",
        "",
    },
    {
        "Afghani",
        "AFN",
        "؋",
    },
    {
        "Lek",
        "ALL",
        "Lek",
    },
    {
        "Armenian Dram",
        "AMD",
        "",
    },
    {
        "Netherlands Antillian Guilder",
        "ANG",
        "ƒ",
    },
    {
        "Kwanza",
        "AOA",
        "",
    },
    {
        "Argentine Peso",
        "ARS",
        "$",
    },
    {
        "Australian Dollar",
        "AUD",
        "$",
    },
    {
        "Aruban Guilder",
        "AWG",
        "ƒ",
    },
    {
        "Azerbaijanian Manat",
        "AZN",
        "ман",
    },
    {
        "Convertible Marks",
        "BAM",
        "KM",
    },
    {
        "Barbados Dollar",
        "BBD",
        "$",
    },
    {
        "Taka",
        "BDT",
        "",
    },
    {
        "Bulgarian Lev",
        "BGN",
        "лв",
    },
    {
        "Bahraini Dinar",
        "BHD",
        "",
    },
    {
        "Burundi Franc",
        "BIF",
        "",
    },
    {
        "Bermudian Dollar (customarily known as Bermuda Dollar)",
        "BMD",
        "$",
    },
    {
        "Brunei Dollar",
        "BND",
        "$",
    },
    {
        "Boliviano boliviano",
        "BOB",
        "Bs",
    },
    {
        "Brazilian Real",
        "BRL",
        "R$",
    },
    {
        "Bahamian Dollar",
        "BSD",
        "$",
    },
    {
        "Pula",
        "BWP",
        "P",
    },
    {
        "Belarusian Ruble",
        "BYN",
        "Rbl",
    },
    {
        "Belize Dollar",
        "BZD",
        "BZ$",
    },
    {
        "Canadian Dollar",
        "CAD",
        "$",
    },
    {
        "Congolese Franc",
        "CDF",
        "",
    },
    {
        "Swiss Franc",
        "CHF",
        "CHF",
    },
    {
        "Chilean Peso",
        "CLP",
        "$",
    },
    {
        "Yuan Renminbi",
        "CNY",
        "¥",
    },
    {
        "Colombian Peso",
        "COP",
        "$",
    },
    {
        "Costa Rican Colon",
        "CRC",
        "₡",
    },
    {
        "Cuban Peso",
        "CUP",
        "₱",
    },
    {
        "Cape Verde Escudo",
        "CVE",
        "",
    },
    {
        "Czech Koruna",
        "CZK",
        "Kč",
    },
    {
        "Djibouti Franc",
        "DJF",
        "",
    },
    {
        "Danish Krone",
        "DKK",
        "kr",
    },
    {
        "Dominican Peso",
        "DOP",
        "RD$",
    },
    {
        "Algerian Dinar",
        "DZD",
        "",
    },
    {
        "Egyptian Pound",
        "EGP",
        "£",
    },
    {
        "Nakfa",
        "ERN",
        "",
    },
    {
        "Ethiopian Birr",
        "ETB",
        "",
    },
    {
        "Euro",
        "EUR",
        "€",
    },
    {
        "Fiji Dollar",
        "FJD",
        "$",
    },
    {
        "Falkland Islands Pound",
        "FKP",
        "£",
    },
    {
        "Pound Sterling",
        "GBP",
        "£",
    },
    {
        "Lari",
        "GEL",
        "",
    },
    {
        "Cedi",
        "GHS",
        "",
    },
    {
        "Gibraltar Pound",
        "GIP",
        "£",
    },
    {
        "Dalasi",
        "GMD",
        "",
    },
    {
        "Guinea Franc",
        "GNF",
        "",
    },
    {
        "Quetzal",
        "GTQ",
        "Q",
    },
    {
        "Guyana Dollar",
        "GYD",
        "$",
    },
    {
        "Hong Kong Dollar",
        "HKD",
        "$",
    },
    {
        "Lempira",
        "HNL",
        "L",
    },
    {
        "Gourde",
        "HTG",
        "",
    },
    {
        "Forint",
        "HUF",
        "Ft",
    },
    {
        "Rupiah",
        "IDR",
        "Rp",
    },
    {
        "New Israeli Sheqel",
        "ILS",
        "₪",
    },
    {
        "Bhutanese Ngultrum",
        "BTN",
        "Nu",
    },
    {
        "Indian Rupee",
        "INR",
        "₹",
    },
    {
        "Iraqi Dinar",
        "IQD",
        "",
    },
    {
        "Iranian Rial",
        "IRR",
        "﷼",
    },
    {
        "Iceland Krona",
        "ISK",
        "kr",
    },
    {
        "Jamaican Dollar",
        "JMD",
        "J$",
    },
    {
        "Jordanian Dinar",
        "JOD",
        "",
    },
    {
        "Yen",
        "JPY",
        "¥",
    },
    {
        "Kenyan Shilling",
        "KES",
        "",
    },
    {
        "Som",
        "KGS",
        "лв",
    },
    {
        "Riel",
        "KHR",
        "៛",
    },
    {
        "Comoro Franc",
        "KMF",
        "",
    },
    {
        "North Korean Won",
        "KPW",
        "₩",
    },
    {
        "Won",
        "KRW",
        "₩",
    },
    {
        "Kuwaiti Dinar",
        "KWD",
        "",
    },
    {
        "Cayman Islands Dollar",
        "KYD",
        "$",
    },
    {
        "Tenge",
        "KZT",
        "лв",
    },
    {
        "Kip",
        "LAK",
        "₭",
    },
    {
        "Lebanese Pound",
        "LBP",
        "£",
    },
    {
        "Sri Lanka Rupee",
        "LKR",
        "₨",
    },
    {
        "Liberian Dollar",
        "LRD",
        "$",
    },
    {
        "Libyan Dinar",
        "LYD",
        "",
    },
    {
        "Moroccan Dirham",
        "MAD",
        "",
    },
    {
        "Moldovan Leu",
        "MDL",
        "",
    },
    {
        "Malagasy Ariary",
        "MGA",
        "",
    },
    {
        "Denar",
        "MKD",
        "ден",
    },
    {
        "Kyat",
        "MMK",
        "",
    },
    {
        "Tugrik",
        "MNT",
        "₮",
    },
    {
        "Pataca",
        "MOP",
        "",
    },
    {
        "Ouguiya",
        "MRU",
        "",
    },
    {
        "Mauritius Rupee",
        "MUR",
        "₨",
    },
    {
        "Rufiyaa",
        "MVR",
        "",
    },
    {
        "Kwacha",
        "MWK",
        "",
    },
    {
        "Mexican Peso",
        "MXN",
        "$",
    },
    {
        "Malaysian Ringgit",
        "MYR",
        "RM",
    },
    {
        "Metical",
        "MZN",
        "MT",
    },
    {
        "Naira",
        "NGN",
        "₦",
    },
    {
        "Cordoba Oro",
        "NIO",
        "C$",
    },
    {
        "Norwegian Krone",
        "NOK",
        "kr",
    },
    {
        "Nepalese Rupee",
        "NPR",
        "₨",
    },
    {
        "New Zealand Dollar",
        "NZD",
        "$",
    },
    {
        "Rial Omani",
        "OMR",
        "﷼",
    },
    {
        "Balboa",
        "PAB",
        "B/.",
    },
    {
        "Nuevo Sol",
        "PEN",
        "S/.",
    },
    {
        "Kina",
        "PGK",
        "",
    },
    {
        "Philippine Peso",
        "PHP",
        "Php",
    },
    {
        "Pakistan Rupee",
        "PKR",
        "₨",
    },
    {
        "Zloty",
        "PLN",
        "zł",
    },
    {
        "Guarani",
        "PYG",
        "Gs",
    },
    {
        "Qatari Rial",
        "QAR",
        "﷼",
    },
    {
        "New Leu",
        "RON",
        "lei",
    },
    {
        "Serbian Dinar",
        "RSD",
        "Дин.",
    },
    {
        "Russian Ruble",
        "RUB",
        "руб",
    },
    {
        "Rwanda Franc",
        "RWF",
        "",
    },
    {
        "Saudi Riyal",
        "SAR",
        "﷼",
    },
    {
        "Solomon Islands Dollar",
        "SBD",
        "$",
    },
    {
        "Seychelles Rupee",
        "SCR",
        "₨",
    },
    {
        "Sudanese Pound",
        "SDG",
        "",
    },
    {
        "Swedish Krona",
        "SEK",
        "kr",
    },
    {
        "Singapore Dollar",
        "SGD",
        "$",
    },
    {
        "Saint Helena Pound",
        "SHP",
        "£",
    },
    {
        "Leone",
        "SLE",
        "",
    },
    {
        "Somali Shilling",
        "SOS",
        "S",
    },
    {
        "Surinam Dollar",
        "SRD",
        "$",
    },
    {
        "South Sudanese pound",
        "SSP",
        "",
    },
    {
        "Dobra",
        "STN",
        "Db",
    },
    {
        "Syrian Pound",
        "SYP",
        "£",
    },
    {
        "Lilangeni",
        "SZL",
        "",
    },
    {
        "Baht",
        "THB",
        "฿",
    },
    {
        "Somoni",
        "TJS",
        "",
    },
    {
        "Manat",
        "TMT",
        "",
    },
    {
        "Tunisian Dinar",
        "TND",
        "",
    },
    {
        "Pa' anga ",
        "TOP",
        "",
    },
    {
        "Turkish Lira",
        "TRY",
        "₺",
    },
    {
        "Trinidad and Tobago Dollar",
        "TTD",
        "TT$",
    },
    {
        "New Taiwan Dollar",
        "TWD",
        "NT$",
    },
    {
        "Tanzanian Shilling",
        "TZS",
        "",
    },
    {
        "Hryvnia",
        "UAH",
        "₴",
    },
    {
        "Uganda Shilling",
        "UGX",
        "",
    },
    {
        "US Dollar",
        "USD",
        "$",
    },
    {
        "Peso Uruguayo",
        "UYU",
        "$U",
    },
    {
        "Uzbekistan Sum",
        "UZS",
        "лв",
    },
    {
        "Venezuelan bolívar",
        "VES",
        "Bs",
    },
    {
        "Dong",
        "VND",
        "₫",
    },
    {
        "Vatu",
        "VUV",
        "",
    },
    {
        "Tala",
        "WST",
        "",
    },
    {
        "CFA Franc BEAC",
        "XAF",
        "",
    },
    {
        "East Caribbean Dollar",
        "XCD",
        "$",
    },
    {
        "CFA Franc BCEAO",
        "XOF",
        "",
    },
    {
        "CFP Franc",
        "XPF",
        "",
    },
    {
        "Yemeni Rial",
        "YER",
        "﷼",
    },
    {
        "Rand",
        "ZAR",
        "R",
    },
    {
        "Lesotho Loti",
        "LSL",
        "",
    },
    {
        "Namibia Dollar",
        "NAD",
        "N$",
    },
    {
        "Zambian Kwacha",
        "ZMW",
        "K",
    },
    {
        "Zimbabwe Dollar",
        "ZWL",
        "",
    },
});
}
