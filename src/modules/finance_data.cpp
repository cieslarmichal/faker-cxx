#include "finance_data.h"

namespace faker::finance::data {
const std::array<bic_country, 10> bic_countries { bic_country::poland, bic_country::usa,
    bic_country::england, bic_country::germany, bic_country::romania, bic_country::france,
    bic_country::italy, bic_country::spain, bic_country::netherlands, bic_country::india };

const std::array<iban_country, 27> iban_countries {
    iban_country::austria,
    iban_country::belgium,
    iban_country::bulgaria,
    iban_country::croatia,
    iban_country::cyprus,
    iban_country::czechia,
    iban_country::denmark,
    iban_country::estonia,
    iban_country::finland,
    iban_country::france,
    iban_country::germany,
    iban_country::greece,
    iban_country::hungary,
    iban_country::ireland,
    iban_country::italy,
    iban_country::latvia,
    iban_country::lithuania,
    iban_country::luxembourg,
    iban_country::malta,
    iban_country::netherlands,
    iban_country::poland,
    iban_country::portugal,
    iban_country::romania,
    iban_country::slovakia,
    iban_country::slovenia,
    iban_country::spain,
    iban_country::sweden,
};

const std::array<std::string_view, 8> account_types = {
    "Checking",
    "Savings",
    "Money Market",
    "Investment",
    "Home Loan",
    "Credit Card",
    "Auto Loan",
    "Personal Loan",
};

const std::unordered_map<bic_country, std::vector<std::string_view>> bic_countries_codes = {
    { bic_country::poland,
        { "BPKOPLPW", "PKOPPLPW", "BREXPLPWMUL", "BNPAPLP", "POLUPLPR", "BIGBPLPW", "WBKPPLPP",
            "CITIPLPX", "INGBPLPW", "DEUTPLPK", "DEUTPLP" } },
    { bic_country::usa,
        { "BOFAUS3N", "CITIUS33", "WELLSFARGO", "USBKUS44", "CHASUS33", "HSBCUS33", "PNCCUS33" } },
    { bic_country::england,
        { "BARCGB22", "HSBCKENW", "LOYDGB21", "NWBKGB2L", "RBOSGB2L", "HSBCGB2L", "DEUTGB2L" } },
    { bic_country::germany,
        { "DEUTDEFF", "DRESDEFF", "COBADEFF", "BYLADEM1", "GENODEFF", "HYVEDEMM", "MALADE51",
            "NOLADE21", "SOLADEST", "UNCRDEFF" } },
    { bic_country::romania,
        { "RNCBROBU", "BRDEROBU", "BTRLRO22", "PIRBROBU", "INGBROBU", "EXIMRO22", "CRDZROBU" } },
    { bic_country::france,
        { "BNPAFRPP", "CEPAFRPP", "CRLYFRPP", "SOGEFRPP", "AGRIFRPP", "HSBDFRPP", "CCFRFRPP",
            "BNORDRPP", "CMCIFRPP" } },
    { bic_country::italy,
        { "UNCRITMM", "BCITITMM", "INTESA", "UBSPITPA", "BLOPIT22", "CITIITMX", "BNLIITRR" } },
    { bic_country::spain,
        { "CAIXESBB", "BBVAESMM", "SABSESBB", "BSCHESMM", "POPUESMM", "INGDESMM", "CITIES2X",
            "BCOEESMM" } },
    { bic_country::netherlands,
        { "ABNANL2A", "INGBNL2A", "RABONL2U", "TRIONL2U", "KNABNL2H", "SBINNL2X", "DEUTNL2N" } },
    { bic_country::india,
        { "HDFCINBB", "ICICINBB", "SBININBB", "PNBAINBB", "UBININBB", "AXISINBB", "KKBKINBB",
            "YESBINBB", "IDBIINBB" } }
};

const std::array<credit_card_type, 4> credit_card_types { credit_card_type::american_express,
    credit_card_type::discover, credit_card_type::mastercard, credit_card_type::visa };

const std::array<std::string_view, 2> american_express_cc_formats
    = { "34##-######-####L", "37##-######-####L" };

const std::array<std::string_view, 6> discover_cc_formats
    = { "6011-####-####-###L", "65##-####-####-###L", "64[4-9]#-####-####-###L",
          "6011-62##-####-####-###L", "65##-62##-####-####-###L", "64[4-9]#-62##-####-####-###L" };

const std::array<std::string_view, 2> mastercard_cc_formats
    = { "5[1-5]##-####-####-###L", "6771-89##-####-###L" };

const std::array<std::string_view, 2> visa_cc_formats = { "4###########L", "4###-####-####-###L" };

const std::array<currency_info, 154> currencies = { { {
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
    } } };

// Iban format structure from https://bank.codes/iban/structure/
// Note: a - alphabets (letters only), c - characters (letters & numbers), n - numbers (numbers
// only)
const std::unordered_map<iban_country, std::vector<std::string_view>> iban_formats {
    { iban_country::austria, { "AT", "2n", "5n", "11n" } },
    { iban_country::belgium, { "BE", "2n", "3n", "7n", "2n" } },
    { iban_country::bulgaria, { "BG", "2n", "4a", "4n", "2n", "8c" } },
    { iban_country::croatia, { "HR", "2n", "7n", "10n" } },
    { iban_country::cyprus, { "CY", "2n", "3n", "5n", "16c" } },
    { iban_country::czechia, { "CZ", "2n", "4n", "6n", "10n" } },
    { iban_country::denmark, { "DK", "2n", "4n", "9n", "1n" } },
    { iban_country::estonia, { "EE", "2n", "2n", "2n", "11n", "1n" } },
    { iban_country::finland, { "FI", "2n", "6n", "7n", "1n" } },
    { iban_country::france, { "FR", "2n", "5n", "5n", "11c", "2n" } },
    { iban_country::germany, { "DE", "2n", "8n", "10n" } },
    { iban_country::greece, { "GR", "2n", "3n", "4n", "16c" } },
    { iban_country::hungary, { "HU", "2n", "3n", "4n", "1n", "15n", "1n" } },
    { iban_country::ireland, { "IE", "2n", "4a", "6n", "8n" } },
    { iban_country::italy, { "IT", "2n", "1a", "5n", "5n", "12c" } },
    { iban_country::latvia, { "LV", "2n", "4a", "13n" } },
    { iban_country::lithuania, { "LT", "2n", "5n", "11n" } },
    { iban_country::luxembourg, { "LU", "2n", "3n", "13c" } },
    { iban_country::malta, { "MT", "2n", "4a", "5n", "18c" } },
    { iban_country::netherlands, { "NL", "2n", "4a", "10n" } },
    { iban_country::poland, { "PL", "2n", "3n", "4n", "1n", "16n" } },
    { iban_country::portugal, { "PT", "2n", "4n", "4n", "11n", "2n" } },
    { iban_country::romania, { "RO", "2n", "4a", "16c" } },
    { iban_country::slovakia, { "SK", "2n", "4n", "6n", "10n" } },
    { iban_country::slovenia, { "SI", "2n", "2n", "3n", "8n", "2n" } },
    { iban_country::spain, { "ES", "2n", "4n", "4n", "2n", "10n" } },
    { iban_country::sweden, { "SE", "2n", "3n", "16n", "1n" } },
};
}
