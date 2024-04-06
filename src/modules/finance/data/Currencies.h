#pragma once

#include <string>
#include <vector>

#include "faker-cxx/Finance.h"

namespace faker
{
const std::vector<Currency> currencies = {{
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
                                          }};
}
