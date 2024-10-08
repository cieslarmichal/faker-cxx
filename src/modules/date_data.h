#pragma once

#include <array>
#include <string_view>

namespace faker::date
{
const auto monthNames = std::to_array<std::string_view>({
    "April",
    "August",
    "December",
    "February",
    "January",
    "July",
    "June",
    "March",
    "May",
    "November",
    "October",
    "September",
});

const auto monthAbbreviatedNames = std::to_array<std::string_view>({
    "Apr",
    "Aug",
    "Dec",
    "Feb",
    "Jan",
    "July",
    "June",
    "Mar",
    "May",
    "Nov",
    "Oct",
    "Sept",
});

const auto weekdayNames = std::to_array<std::string_view>({
    "Friday",
    "Monday",
    "Saturday",
    "Sunday",
    "Thursday",
    "Tuesday",
    "Wednesday",
});

const auto weekdayAbbreviatedNames = std::to_array<std::string_view>({
    "Fri",
    "Mon",
    "Sat",
    "Sun",
    "Thu",
    "Tue",
    "Wed",
});

const auto timezonesAbbreviatedNames = std::to_array<std::string_view>({
    "ACDT",  "ACST", "ACT",          "ACT",  "ACWST", "ADT",   "AEDT",  "AEST",  "AET (AEST/AEDT)",
    "AFT",   "AKDT", "AKST",         "ALMT", "AMST",  "AMT",   "AMT",   "ANAT",  "AQTT",
    "ART",   "AST",  "AST",          "AWST", "AZOST", "AZOT",  "AZT",   "BIOT",  "BIT",
    "BNT",   "BOT",  "BRST",         "BRT",  "BST",   "BST",   "BST",   "BTT",   "CAT",
    "CCT",   "CDT",  "CDT",          "CEST", "CET",   "CHADT", "CHAST", "CHOST", "CHOT",
    "CHST",  "CHUT", "CIST",         "CKT",  "CLST",  "CLT",   "COST",  "COT",   "CST",
    "CST",   "CST",  "CT (CST/CDT)", "CVT",  "CWST",  "CXT",   "DAVT",  "DDUT",  "DFT",
    "EASST", "EAST", "EAT",          "ECT",  "ECT",   "EDT",   "EEST",  "EET",   "EGST",
    "EGT",   "EST",  "ET (EST/EDT)", "FET",  "FJT",   "FKST",  "FKT",   "FNT",   "GALT",
    "GAMT",  "GET",  "GFT",          "GILT", "GIT",   "GMT",   "GST",   "GST",   "GYT",
    "HAEC",  "HDT",  "HKT",          "HMT",  "HOVST", "HOVT",  "HST",   "ICT",   "IDLW",
    "IDT",   "IOT",  "IRDT",         "IRKT", "IRST",  "IST",   "IST",   "IST",   "JST",
    "KALT",  "KGT",  "KOST",         "KRAT", "KST",   "LHST",  "LHST",  "LINT",  "MAGT",
    "MART",  "MAWT", "MDT",          "MEST", "MET",   "MHT",   "MIST",  "MIT",   "MMT",
    "MSK",   "MST",  "MST",          "MUT",  "MVT",   "MYT",   "NCT",   "NDT",   "NFT",
    "NOVT",  "NPT",  "NST",          "NT",   "NUT",   "NZDT",  "NZST",  "OMST",  "ORAT",
    "PDT",   "PET",  "PETT",         "PGT",  "PHOT",  "PHST",  "PHT",   "PKT",   "PMDT",
    "PMST",  "PONT", "PST",          "PWT",  "PYST",  "PYT",   "RET",   "ROTT",  "SAKT",
    "SAMT",  "SAST", "SBT",          "SCT",  "SDT",   "SGT",   "SLST",  "SRET",  "SRT",
    "SST",   "SST",  "SYOT",         "TAHT", "TFT",   "THA",   "TJT",   "TKT",   "TLT",
    "TMT",   "TOT",  "TRT",          "TST",  "TVT",   "ULAST", "ULAT",  "UTC",   "UYST",
    "UYT",   "UZT",  "VET",          "VLAT", "VOLT",  "VOST",  "VUT",   "WAKT",  "WAST",
    "WAT",   "WEST", "WET",          "WGST", "WGT",   "WIB",   "WIT",   "WITA",  "WST",
    "YAKT",  "YEKT",
});

}
