#pragma once

#include <array>
#include <string_view>
#include <unordered_map>
#include <vector>

#include "faker-cxx/finance.h"

namespace faker::finance
{
const auto bicCountries = std::to_array<BicCountry>({
    BicCountry::Poland,  BicCountry::UnitedStates, BicCountry::UnitedKingdom,
    BicCountry::Germany, BicCountry::Romania,      BicCountry::France,
    BicCountry::Italy,   BicCountry::Spain,        BicCountry::Netherlands,
    BicCountry::India
});

const auto ibanCountries = std::to_array<IbanCountry>({
    IbanCountry::Austria,  IbanCountry::Belgium,     IbanCountry::Bulgaria,
    IbanCountry::Croatia,  IbanCountry::Cyprus,      IbanCountry::Czechia,
    IbanCountry::Denmark,  IbanCountry::Estonia,     IbanCountry::Finland,
    IbanCountry::France,   IbanCountry::Germany,     IbanCountry::Greece,
    IbanCountry::Hungary,  IbanCountry::Ireland,     IbanCountry::Italy,
    IbanCountry::Latvia,   IbanCountry::Lithuania,   IbanCountry::Luxembourg,
    IbanCountry::Malta,    IbanCountry::Netherlands, IbanCountry::Poland,
    IbanCountry::Portugal, IbanCountry::Romania,     IbanCountry::Slovakia,
    IbanCountry::Slovenia, IbanCountry::Spain,       IbanCountry::Sweden,
});

const auto accountTypes = std::to_array<std::string_view>({
    "Checking", "Savings", "Money Market", "Investment", "Home Loan", "Credit Card", "Auto Loan", "Personal Loan",
});

const std::unordered_map<BicCountry, std::vector<std::string_view>> bicCountriesCodes = {
    {BicCountry::Poland,
     {"BPKOPLPW", "PKOPPLPW", "BREXPLPWMUL", "BNPAPLP", "POLUPLPR", "BIGBPLPW", "WBKPPLPP", "CITIPLPX", "INGBPLPW",
      "DEUTPLPK", "DEUTPLP"}},
    {BicCountry::UnitedStates,
     {"BOFAUS3N", "CITIUS33", "WELLSFARGO", "USBKUS44", "CHASUS33", "HSBCUS33", "PNCCUS33"}},
    {BicCountry::UnitedKingdom,
     {"BARCGB22", "HSBCKENW", "LOYDGB21", "NWBKGB2L", "RBOSGB2L", "HSBCGB2L", "DEUTGB2L"}},
    {BicCountry::Germany,
     {"DEUTDEFF", "DRESDEFF", "COBADEFF", "BYLADEM1", "GENODEFF", "HYVEDEMM", "MALADE51", "NOLADE21", "SOLADEST",
      "UNCRDEFF"}},
    {BicCountry::Romania,
     {"RNCBROBU", "BRDEROBU", "BTRLRO22", "PIRBROBU", "INGBROBU", "EXIMRO22", "CRDZROBU"}},
    {BicCountry::France,
     {"BNPAFRPP", "CEPAFRPP", "CRLYFRPP", "SOGEFRPP", "AGRIFRPP", "HSBDFRPP", "CCFRFRPP", "BNORDRPP", "CMCIFRPP"}},
    {BicCountry::Italy, {"UNCRITMM", "BCITITMM", "INTESA", "UBSPITPA", "BLOPIT22", "CITIITMX", "BNLIITRR"}},
    {BicCountry::Spain,
     {"CAIXESBB", "BBVAESMM", "SABSESBB", "BSCHESMM", "POPUESMM", "INGDESMM", "CITIES2X", "BCOEESMM"}},
    {BicCountry::Netherlands,
     {"ABNANL2A", "INGBNL2A", "RABONL2U", "TRIONL2U", "KNABNL2H", "SBINNL2X", "DEUTNL2N"}},
    {
        BicCountry::India,
        {"HDFCINBB", "ICICINBB", "SBININBB", "PNBAINBB", "UBININBB", "AXISINBB", "KKBKINBB", "YESBINBB", "IDBIINBB"},
    }};

const auto americanExpressCreditCardFormats = std::to_array<std::string_view>({
    "34##-######-####L",
    "37##-######-####L",
});

const auto discoverCreditCardFormats = std::to_array<std::string_view>({
    "6011-####-####-###L",      "65##-####-####-###L",      "64[4-9]#-####-####-###L",
    "6011-62##-####-####-###L", "65##-62##-####-####-###L", "64[4-9]#-62##-####-####-###L",
});

const auto masterCardCreditCardFormats = std::to_array<std::string_view>({
    "5[1-5]##-####-####-###L",
    "6771-89##-####-###L",
});

const auto visaCreditCardFormats = std::to_array<std::string_view>({
    "4###########L",
    "4###-####-####-###L",
});

const auto creditCardTypes = std::to_array<CreditCardType>({
    CreditCardType::Visa,
    CreditCardType::AmericanExpress,
    CreditCardType::MasterCard,
    CreditCardType::Discover,
});

const auto creditCardNames = std::to_array<std::string_view>({
    "Visa",
    "American Express",
    "MasterCard",
    "Discover",
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
    }
});

// Iban format structure from https://bank.codes/iban/structure/
// Note: a - alphabets (letters only), c - characters (letters & numbers), n - numbers (numbers only)
const std::unordered_map<IbanCountry, std::vector<std::string_view>> ibanFormats{
    {IbanCountry::Austria, {"AT", "2n", "5n", "11n"}},
    {IbanCountry::Belgium, {"BE", "2n", "3n", "7n", "2n"}},
    {IbanCountry::Bulgaria, {"BG", "2n", "4a", "4n", "2n", "8c"}},
    {IbanCountry::Croatia, {"HR", "2n", "7n", "10n"}},
    {IbanCountry::Cyprus, {"CY", "2n", "3n", "5n", "16c"}},
    {IbanCountry::Czechia, {"CZ", "2n", "4n", "6n", "10n"}},
    {IbanCountry::Denmark, {"DK", "2n", "4n", "9n", "1n"}},
    {IbanCountry::Estonia, {"EE", "2n", "2n", "2n", "11n", "1n"}},
    {IbanCountry::Finland, {"FI", "2n", "6n", "7n", "1n"}},
    {IbanCountry::France, {"FR", "2n", "5n", "5n", "11c", "2n"}},
    {IbanCountry::Germany, {"DE", "2n", "8n", "10n"}},
    {IbanCountry::Greece, {"GR", "2n", "3n", "4n", "16c"}},
    {IbanCountry::Hungary, {"HU", "2n", "3n", "4n", "1n", "15n", "1n"}},
    {IbanCountry::Ireland, {"IE", "2n", "4a", "6n", "8n"}},
    {IbanCountry::Italy, {"IT", "2n", "1a", "5n", "5n", "12c"}},
    {IbanCountry::Latvia, {"LV", "2n", "4a", "13n"}},
    {IbanCountry::Lithuania, {"LT", "2n", "5n", "11n"}},
    {IbanCountry::Luxembourg, {"LU", "2n", "3n", "13c"}},
    {IbanCountry::Malta, {"MT", "2n", "4a", "5n", "18c"}},
    {IbanCountry::Netherlands, {"NL", "2n", "4a", "10n"}},
    {IbanCountry::Poland, {"PL", "2n", "3n", "4n", "1n", "16n"}},
    {IbanCountry::Portugal, {"PT", "2n", "4n", "4n", "11n", "2n"}},
    {IbanCountry::Romania, {"RO", "2n", "4a", "16c"}},
    {IbanCountry::Slovakia, {"SK", "2n", "4n", "6n", "10n"}},
    {IbanCountry::Slovenia, {"SI", "2n", "2n", "3n", "8n", "2n"}},
    {IbanCountry::Spain, {"ES", "2n", "4n", "4n", "2n", "10n"}},
    {IbanCountry::Sweden, {"SE", "2n", "3n", "16n", "1n"}},
};

}
