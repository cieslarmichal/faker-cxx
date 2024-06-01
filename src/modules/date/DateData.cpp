#include "DateData.h"

#include <array>
#include <string_view>

namespace faker
{
const std::array<std::string_view, 12> monthNames = {
    "January", "February", "March",     "April",   "May",      "June",
    "July",    "August",   "September", "October", "November", "December",
};

const std::array<std::string_view, 12> monthAbbreviatedNames = {"Jan",  "Feb", "Mar",  "Apr", "May", "June",
                                                                "July", "Aug", "Sept", "Oct", "Nov", "Dec"};

const std::array<std::string_view, 7> weekdayNames = {"Monday", "Tuesday",  "Wednesday", "Thursday",
                                                      "Friday", "Saturday", "Sunday"};

const std::array<std::string_view, 7> weekdayAbbreviatedNames = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};

const std::array<std::string_view, 209> timezonesAbbreviatedNames = {
    "ACDT",  "ACST", "ACT",          "ACT",  "ACWST", "ADT",   "AEDT",  "AEST", "AET (AEST/AEDT)",
    "AFT",   "AKDT", "AKST",         "ALMT", "AMST",  "AMT",   "AMT",   "ANAT", "AQTT",
    "ART",   "AST",  "AST",          "AWST", "AZOST", "AZOT",  "AZT",   "BNT",  "BIOT",
    "BIT",   "BOT",  "BRST",         "BRT",  "BST",   "BST",   "BST",   "BTT",  "CAT",
    "CCT",   "CDT",  "CDT",          "CEST", "CET",   "CHADT", "CHAST", "CHOT", "CHOST",
    "CHST",  "CHUT", "CIST",         "CKT",  "CLST",  "CLT",   "COST",  "COT",  "CST",
    "CST",   "CST",  "CT (CST/CDT)", "CVT",  "CWST",  "CXT",   "DAVT",  "DDUT", "DFT",
    "EASST", "EAST", "EAT",          "ECT",  "ECT",   "EDT",   "EEST",  "EET",  "EGST",
    "EGT",   "EST",  "ET (EST/EDT)", "FET",  "FJT",   "FKST",  "FKT",   "FNT",  "GALT",
    "GAMT",  "GET",  "GFT",          "GILT", "GIT",   "GMT",   "GST",   "GST",  "GYT",
    "HDT",   "HAEC", "HST",          "HKT",  "HMT",   "HOVST", "HOVT",  "ICT",  "IDLW",
    "IDT",   "IOT",  "IRDT",         "IRKT", "IRST",  "IST",   "IST",   "IST",  "JST",
    "KALT",  "KGT",  "KOST",         "KRAT", "KST",   "LHST",  "LHST",  "LINT", "MAGT",
    "MART",  "MAWT", "MDT",          "MET",  "MEST",  "MHT",   "MIST",  "MIT",  "MMT",
    "MSK",   "MST",  "MST",          "MUT",  "MVT",   "MYT",   "NCT",   "NDT",  "NFT",
    "NOVT",  "NPT",  "NST",          "NT",   "NUT",   "NZDT",  "NZST",  "OMST", "ORAT",
    "PDT",   "PET",  "PETT",         "PGT",  "PHOT",  "PHT",   "PHST",  "PKT",  "PMDT",
    "PMST",  "PONT", "PST",          "PWT",  "PYST",  "PYT",   "RET",   "ROTT", "SAKT",
    "SAMT",  "SAST", "SBT",          "SCT",  "SDT",   "SGT",   "SLST",  "SRET", "SRT",
    "SST",   "SST",  "SYOT",         "TAHT", "THA",   "TFT",   "TJT",   "TKT",  "TLT",
    "TMT",   "TRT",  "TOT",          "TST",  "TVT",   "ULAST", "ULAT",  "UTC",  "UYST",
    "UYT",   "UZT",  "VET",          "VLAT", "VOLT",  "VOST",  "VUT",   "WAKT", "WAST",
    "WAT",   "WEST", "WET",          "WIB",  "WIT",   "WITA",  "WGST",  "WGT",  "WST",
    "YAKT",  "YEKT"};
}
