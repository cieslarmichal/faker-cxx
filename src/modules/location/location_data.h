#pragma once

#include <array>
#include <span>
#include <string_view>

namespace faker::location
{
struct CountryAddressesInfo
{
    std::string_view zipCodeFormat;
    std::span<const std::string_view> addressFormats;
    std::span<const std::string_view> secondaryAddressFormats;
    std::span<const std::string_view> streetFormats;
    std::span<const std::string_view> streetPrefixes;
    std::span<const std::string_view> streetNames;
    std::span<const std::string_view> streetSuffixes;
    std::span<const std::string_view> buildingNumberFormats;
    std::span<const std::string_view> cityFormats;
    std::span<const std::string_view> cityPrefixes;
    std::span<const std::string_view> cities;
    std::span<const std::string_view> citySuffixes;
    std::span<const std::string_view> states;
};

const auto allCountries = std::to_array<std::string_view>({
    // clang-format off
    "Afghanistan",          "Jersey",               "Turkey",               "Grenada",
    "Congo",                "Northern Mariana Islands","Bhutan",            "Mauritania",
    "Hungary",              "Switzerland",          "France",               "Saint Pierre and Miquelon",
    "Namibia",              "Australia",            "Liechtenstein",        "Venezuela",
    "Slovenia",             "Ecuador",              "Portugal",             "Cameroon",
    "Aland Islands",        "Jordan",               "Turkmenistan",         "Guadeloupe",
    "Cook Islands",         "Norway",               "Bolivia",              "Mauritius",
    "Iceland",              "Syrian Arab Republic", "French Guiana",        "Saint Vincent and the Grenadines",
    "Nauru",                "Austria",              "Lithuania",            "Vietnam",
    "Solomon Islands",      "Egypt",                "Puerto Rico",          "Canada",
    "Albania",              "Kazakhstan",           "Turks and Caicos Islands","Guam",
    "Costa Rica",           "Oman",                 "Bonaire, Sint Eustatius and Saba","Mayotte",
    "India",                "Taiwan",               "French Polynesia",     "Samoa",
    "Nepal",                "Azerbaijan",           "Luxembourg",           "Virgin Islands, British",
    "Somalia",              "El Salvador",          "Qatar",                "Cape Verde",
    "Algeria",              "Kenya",                "Tuvalu",               "Guatemala",
    "Croatia",              "Pakistan",             "Bosnia and Herzegovina","Mexico",
    "Indonesia",            "Tajikistan",           "French Southern Territories","San Marino",
    "Netherlands",          "Bahamas",              "Macao",                "Virgin Islands, U.S.",
    "South Africa",         "Equatorial Guinea",    "Reunion",              "Cayman Islands",
    "American Samoa",       "Kiribati",             "Uganda",               "Guernsey",
    "Cuba",                 "Palau",                "Botswana",             "Micronesia",
    "Iran",                 "Tanzania",             "Gabon",                "Sao Tome and Principe",
    "New Caledonia",        "Bahrain",              "Madagascar",           "Wallis and Futuna",
    "South Georgia and the South Sandwich Islands","Eritrea","Romania",     "Central African Republic",
    "Andorra",              "Republic of Korea",    "Ukraine",              "Guinea",
    "Curacao",              "Palestine",            "Bouvet Island",        "Moldova",
    "Iraq",                 "Thailand",             "Gambia",               "Saudi Arabia",
    "New Zealand",          "Bangladesh",           "Malawi",               "Western Sahara",
    "South Sudan",          "Estonia",              "Russian Federation",   "Chad",
    "Angola",               "Kuwait",               "United Arab Emirates", "Guinea-Bissau",
    "Cyprus",               "Panama",               "Brazil",               "Monaco",
    "Ireland",              "Timor-Leste",          "Georgia",              "Senegal",
    "Nicaragua",            "Barbados",             "Malaysia",             "Yemen",
    "Spain",                "Eswatini",             "Rwanda",               "Chile",
    "Anguilla",             "Kyrgyz Republic",      "United Kingdom",       "Guyana",
    "Czechia",              "Papua New Guinea",     "British Indian Ocean Territory (Chagos Archipelago)","Mongolia",
    "Isle of Man",          "Togo",                 "Germany",              "Serbia",
    "Niger",                "Belarus",              "Maldives",             "Zambia",
    "Sri Lanka",            "Ethiopia",             "Saint Barthelemy",     "China",
    "Antarctica",           "Latvia",               "United States of America","Haiti",
    "Democratic Republic of the Congo","Paraguay",  "Brunei Darussalam",    "Montenegro",
    "Israel",               "Tokelau",              "Ghana",                "Seychelles",
    "Nigeria",              "Belgium",              "Mali",                 "Zimbabwe",
    "Sudan",                "Faroe Islands",        "Saint Helena",         "Christmas Island",
    "Antigua and Barbuda",  "Lebanon",              "United States Minor Outlying Islands","Heard Island and McDonald Islands",
    "Denmark",              "Peru",                 "Bulgaria",             "Montserrat",
    "Italy",                "Tonga",                "Gibraltar",            "Sierra Leone",
    "Niue",                 "Belize",               "Malta",                "Cocos (Keeling) Islands",
    "Suriname",             "Falkland Islands (Malvinas)","Saint Kitts and Nevis","Holy See (Vatican City State)",
    "Argentina",            "Lesotho",              "Uruguay",              "Morocco",
    "Djibouti",             "Philippines",          "Burkina Faso",         "Singapore",
    "Jamaica",              "Trinidad and Tobago",  "Greece",               "Colombia",
    "Norfolk Island",       "Benin",                "Marshall Islands",     "Honduras",
    "Svalbard & Jan Mayen Islands","Fiji",          "Saint Lucia",          "Mozambique",
    "Armenia",              "Liberia",              "Uzbekistan",           "Sint Maarten",
    "Dominica",             "Pitcairn Islands",     "Burundi",              "Comoros",
    "Japan",                "Tunisia",              "Greenland",            "Hong Kong",
    "North Macedonia",      "Bermuda",              "Martinique",           "Myanmar",
    "Sweden",               "Finland",              "Saint Martin",         "Slovakia",
    "Aruba",                "Libyan Arab Jamahiriya","Vanuatu",
    "Dominican Republic",   "Poland",               "Cambodia",
    // clang-format on
});

const auto countryCodes = std::to_array<std::string_view>({
    "AD", "AE", "AF", "AG", "AI", "AL", "AM", "AO", "AQ", "AR", "AS", "AT", "AU", "AW", "AX", "AZ", "BA", "BB",
    "BD", "BE", "BF", "BG", "BH", "BI", "BJ", "BL", "BM", "BN", "BO", "BQ", "BR", "BS", "BT", "BV", "BW", "BY",
    "BZ", "CA", "CC", "CD", "CF", "CG", "CH", "CI", "CK", "CL", "CM", "CN", "CO", "CR", "CU", "CV", "CW", "CX",
    "CY", "CZ", "DE", "DJ", "DK", "DM", "DO", "DZ", "EC", "EE", "EG", "EH", "ER", "ES", "ET", "FI", "FJ", "FK",
    "FM", "FO", "FR", "GA", "GB", "GD", "GE", "GF", "GG", "GH", "GI", "GL", "GM", "GN", "GP", "GQ", "GR", "GS",
    "GT", "GU", "GW", "GY", "HK", "HM", "HN", "HR", "HT", "HU", "ID", "IE", "IL", "IM", "IN", "IO", "IQ", "IR",
    "IS", "IT", "JE", "JM", "JO", "JP", "KE", "KG", "KH", "KI", "KM", "KN", "KP", "KR", "KW", "KY", "KZ", "LA",
    "LB", "LC", "LI", "LK", "LR", "LS", "LT", "LU", "LV", "LY", "MA", "MC", "MD", "ME", "MF", "MG", "MH", "MK",
    "ML", "MM", "MN", "MO", "MP", "MQ", "MR", "MS", "MT", "MU", "MV", "MW", "MX", "MY", "MZ", "NA", "NC", "NE",
    "NF", "NG", "NI", "NL", "NO", "NP", "NR", "NU", "NZ", "OM", "PA", "PE", "PF", "PG", "PH", "PK", "PL", "PM",
    "PN", "PR", "PS", "PT", "PW", "PY", "QA", "RE", "RO", "RS", "RU", "RW", "SA", "SB", "SC", "SD", "SE", "SG",
    "SH", "SI", "SJ", "SK", "SL", "SM", "SN", "SO", "SR", "SS", "ST", "SV", "SX", "SY", "SZ", "TC", "TD", "TF",
    "TG", "TH", "TJ", "TK", "TL", "TM", "TN", "TO", "TR", "TT", "TV", "TW", "TZ", "UA", "UG", "UM", "US", "UY",
    "UZ", "VA", "VC", "VE", "VG", "VI", "VN", "VU", "WF", "WS", "YE", "YT", "ZA", "ZM", "ZW",
});

const auto directions = std::to_array<std::string_view>({
    "North",
    "East",
    "South",
    "West",
    "Northeast",
    "Northwest",
    "Southeast",
    "Southwest",
});

const auto timeZones = std::to_array<std::string_view>({
    // clang-format off
    "Africa/Abidjan",               "America/Guayaquil",    "Asia/Beirut",                  "Europe/Jersey",
    "Africa/Freetown",              "America/Lima",         "Asia/Kabul",                   "Europe/San_Marino",
    "Africa/Nairobi",               "America/Nome",         "Asia/Pontianak",               "Indian/Cocos",
    "America/Argentina/Rio_Gallegos","America/Santiago",    "Asia/Ust-Nera",                "Pacific/Guam",
    "America/Caracas",              "America/Yellowknife",  "Australia/Eucla",              "Pacific/Tarawa",
    "America/Goose_Bay",            "Asia/Baghdad",         "Europe/Gibraltar",             "Africa/Dakar",
    "America/Juneau",               "Asia/Hovd",            "Europe/Podgorica",             "Africa/Maputo",
    "America/Monterrey",            "Asia/Novokuznetsk",    "Europe/Zagreb",                "America/Argentina/Catamarca",
    "America/Recife",               "Asia/Thimphu",         "Pacific/Fiji",                 "America/Bogota",
    "America/Tortola",              "Atlantic/Stanley",     "Pacific/Pohnpei",              "America/Eirunepe",
    "Asia/Anadyr",                  "Europe/Budapest",      "Africa/Bujumbura",             "America/Indiana/Vincennes",
    "Asia/Famagusta",               "Europe/Minsk",         "Africa/Lome",                  "America/Merida",
    "Asia/Magadan",                 "Europe/Vatican",       "America/Anchorage",            "America/Port_of_Spain",
    "Asia/Srednekolymsk",           "Pacific/Chatham",      "America/Barbados",             "America/Swift_Current",
    "Atlantic/Faroe",               "Pacific/Norfolk",      "America/Dawson_Creek",         "Antarctica/Vostok",
    "Europe/Belgrade",              "Africa/Bangui",        "America/Indiana/Knox",         "Asia/Damascus",
    "Europe/London",                "Africa/Khartoum",      "America/Marigot",              "Asia/Krasnoyarsk",
    "Europe/Stockholm",             "Africa/Sao_Tome",      "America/Ojinaga",              "Asia/Sakhalin",
    "Indian/Mayotte",               "America/Aruba",        "America/St_Johns",             "Asia/Yerevan",
    "Pacific/Majuro",               "America/Creston",      "Antarctica/McMurdo",           "Australia/Sydney",
    "Africa/Accra",                 "America/Guyana",       "Asia/Bishkek",                 "Europe/Kaliningrad",
    "Africa/Gaborone",              "America/Los_Angeles",  "Asia/Kamchatka",               "Europe/Sarajevo",
    "Africa/Ndjamena",              "America/Noronha",      "Asia/Pyongyang",               "Indian/Comoro",
    "America/Argentina/Salta",      "America/Santo_Domingo","Asia/Vientiane",               "Pacific/Honolulu",
    "America/Cayenne",              "Antarctica/Casey",     "Australia/Hobart",             "Pacific/Tongatapu",
    "America/Grand_Turk",           "Asia/Bahrain",         "Europe/Guernsey",              "Africa/Dar_es_Salaam",
    "America/Kentucky/Louisville",  "Asia/Irkutsk",         "Europe/Prague",                "Africa/Maseru",
    "America/Montevideo",           "Asia/Novosibirsk",     "Europe/Zurich",                "America/Argentina/Cordoba",
    "America/Regina",               "Asia/Tokyo",           "Pacific/Funafuti",             "America/Boise",
    "America/Vancouver",            "Australia/Adelaide",   "Pacific/Port_Moresby",         "America/El_Salvador",
    "Asia/Aqtau",                   "Europe/Busingen",      "Africa/Cairo",                 "America/Indiana/Winamac",
    "Asia/Gaza",                    "Europe/Monaco",        "Africa/Luanda",                "America/Metlakatla",
    "Asia/Makassar",                "Europe/Vienna",        "America/Anguilla",             "America/Porto_Velho",
    "Asia/Taipei",                  "Pacific/Chuuk",        "America/Belem",                "America/Tegucigalpa",
    "Atlantic/Madeira",             "Pacific/Noumea",       "America/Denver",               "Arctic/Longyearbyen",
    "Europe/Berlin",                "Africa/Banjul",        "America/Indiana/Marengo",      "Asia/Dhaka",
    "Europe/Luxembourg",            "Africa/Kigali",        "America/Martinique",           "Asia/Kuala_Lumpur",
    "Europe/Tallinn",               "Africa/Tripoli",       "America/Panama",               "Asia/Samarkand",
    "Indian/Reunion",               "America/Asuncion",     "America/St_Kitts",             "Atlantic/Azores",
    "Pacific/Marquesas",            "America/Cuiaba",       "Antarctica/Palmer",            "Europe/Amsterdam",
    "Africa/Addis_Ababa",           "America/Halifax",      "Asia/Brunei",                  "Europe/Kirov",
    "Africa/Harare",                "America/Lower_Princes","Asia/Karachi",                 "Europe/Saratov",
    "Africa/Niamey",                "America/North_Dakota/Beulah","Asia/Qatar",             "Indian/Kerguelen",
    "America/Argentina/San_Juan",   "America/Sao_Paulo",    "Asia/Vladivostok",             "Pacific/Kanton",
    "America/Cayman",               "Antarctica/Davis",     "Australia/Lindeman",           "Pacific/Wake",
    "America/Grenada",              "Asia/Baku",            "Europe/Helsinki",              "Africa/Djibouti",
    "America/Kentucky/Monticello",  "Asia/Jakarta",         "Europe/Riga",                  "Africa/Mbabane",
    "America/Montserrat",           "Asia/Omsk",            "Indian/Antananarivo",          "America/Argentina/Jujuy",
    "America/Resolute",             "Asia/Tomsk",           "Pacific/Galapagos",            "America/Cambridge_Bay",
    "America/Whitehorse",           "Australia/Brisbane",   "Pacific/Rarotonga",            "America/Fort_Nelson",
    "Asia/Aqtobe",                  "Europe/Chisinau",      "Africa/Casablanca",            "America/Inuvik",
    "Asia/Hebron",                  "Europe/Moscow",        "Africa/Lubumbashi",            "America/Mexico_City",
    "Asia/Manila",                  "Europe/Vilnius",       "America/Antigua",              "America/Puerto_Rico",
    "Asia/Tashkent",                "Pacific/Easter",       "America/Belize",               "America/Thule",
    "Atlantic/Reykjavik",           "Pacific/Pago_Pago",    "America/Detroit",              "Asia/Aden",
    "Europe/Bratislava",            "Africa/Bissau",        "America/Indiana/Petersburg",   "Asia/Dili",
    "Europe/Madrid",                "Africa/Kinshasa",      "America/Matamoros",            "Asia/Kuching",
    "Europe/Tirane",                "Africa/Tunis",         "America/Paramaribo",           "Asia/Seoul",
    "Pacific/Apia",                 "America/Atikokan",     "America/St_Lucia",             "Atlantic/Bermuda",
    "Pacific/Midway",               "America/Curacao",      "Antarctica/Rothera",           "Europe/Andorra",
    "Africa/Algiers",               "America/Havana",       "Asia/Chita",                   "Europe/Kyiv",
    "Africa/Johannesburg",          "America/Maceio",       "Asia/Kathmandu",               "Europe/Simferopol",
    "Africa/Nouakchott",            "America/North_Dakota/Center","Asia/Qostanay",          "Indian/Mahe",
    "America/Argentina/San_Luis",   "America/Scoresbysund", "Asia/Yakutsk",                 "Pacific/Kiritimati",
    "America/Chicago",              "Antarctica/DumontDUrville","Australia/Lord_Howe",      "Pacific/Wallis",
    "America/Guadeloupe",           "Asia/Bangkok",         "Europe/Isle_of_Man",           "Africa/Douala",
    "America/Kralendijk",           "Asia/Jayapura",        "Europe/Rome",                  "Africa/Mogadishu",
    "America/Nassau",               "Asia/Oral",            "Indian/Chagos",                "America/Argentina/La_Rioja",
    "America/Rio_Branco",           "Asia/Ulaanbaatar",     "Pacific/Gambier",              "America/Campo_Grande",
    "America/Winnipeg",             "Australia/Broken_Hill","Pacific/Saipan",               "America/Fortaleza",
    "Asia/Ashgabat",                "Europe/Copenhagen",    "Africa/Ceuta",                 "America/Iqaluit",
    "Asia/Ho_Chi_Minh",             "Europe/Oslo",          "Africa/Lusaka",                "America/Miquelon",
    "Asia/Muscat",                  "Europe/Volgograd",     "America/Araguaina",            "America/Punta_Arenas",
    "Asia/Tbilisi",                 "Pacific/Efate",        "America/Blanc-Sablon",         "America/Tijuana",
    "Atlantic/South_Georgia",       "Pacific/Palau",        "America/Dominica",             "Asia/Almaty",
    "Europe/Brussels",              "Africa/Blantyre",      "America/Indiana/Tell_City",    "Asia/Dubai",
    "Europe/Malta",                 "Africa/Lagos",         "America/Mazatlan",             "Asia/Kuwait",
    "Europe/Ulyanovsk",             "Africa/Windhoek",      "America/Phoenix",              "Asia/Shanghai",
    "Pacific/Auckland",             "America/Bahia",        "America/St_Thomas",            "Atlantic/Canary",
    "Pacific/Nauru",                "America/Danmarkshavn", "Antarctica/Syowa",             "Europe/Astrakhan",
    "Africa/Asmara",                "America/Hermosillo",   "Asia/Choibalsan",              "Europe/Lisbon",
    "Africa/Juba",                  "America/Managua",      "Asia/Khandyga",                "Europe/Skopje",
    "Africa/Ouagadougou",           "America/North_Dakota/New_Salem","Asia/Qyzylorda",      "Indian/Maldives",
    "America/Argentina/Tucuman",    "America/Sitka",        "Asia/Yangon",                  "Pacific/Kosrae",
    "America/Chihuahua",            "Antarctica/Macquarie", "Australia/Melbourne",          "America/Cancun",
    "America/Guatemala",            "Asia/Barnaul",         "Europe/Istanbul",              "Africa/El_Aaiun",
    "America/La_Paz",               "Asia/Jerusalem",       "Europe/Samara",                "Africa/Monrovia",
    "America/New_York",             "Asia/Phnom_Penh",      "Indian/Christmas",             "America/Argentina/Mendoza",
    "America/Santarem",             "Asia/Urumqi",          "Pacific/Guadalcanal",          "America/Rankin_Inlet",
    "America/Yakutat",              "Australia/Darwin",     "Pacific/Tahiti",               "America/Glace_Bay",
    "Asia/Atyrau",                  "Europe/Dublin",        "Africa/Conakry",               "America/Jamaica",
    "Asia/Hong_Kong",               "Europe/Paris",         "Africa/Malabo",                "America/Moncton",
    "Asia/Nicosia",                 "Europe/Warsaw",        "America/Argentina/Buenos_Aires","Asia/Macau",
    "Asia/Tehran",                  "Pacific/Fakaofo",      "America/Boa_Vista",            "America/Toronto",
    "Atlantic/St_Helena",           "Pacific/Pitcairn",     "America/Edmonton",             "Asia/Amman",
    "Europe/Bucharest",             "Africa/Brazzaville",   "America/Indiana/Vevay",        "Asia/Dushanbe",
    "Europe/Mariehamn",             "Africa/Libreville",    "America/Menominee",            "Europe/Ljubljana",
    "Europe/Vaduz",                 "America/Adak",         "America/Port-au-Prince",       "Asia/Singapore",
    "Pacific/Bougainville",         "America/Bahia_Banderas","America/St_Vincent",          "Atlantic/Cape_Verde",
    "Pacific/Niue",                 "America/Dawson",       "Antarctica/Troll",             "Europe/Athens",
    "Africa/Bamako",                "America/Indiana/Indianapolis","Asia/Colombo",          "Europe/Sofia",
    "Africa/Kampala",               "America/Manaus",       "Asia/Kolkata",                 "Indian/Mauritius",
    "Africa/Porto-Novo",            "America/Nuuk",         "Asia/Riyadh",                  "Pacific/Kwajalein",
    "America/Argentina/Ushuaia",    "America/St_Barthelemy","Asia/Yekaterinburg",
    "America/Costa_Rica",           "Antarctica/Mawson",    "Australia/Perth",
    // clang-format on
});

// Australia

const auto australiaCities = std::to_array<std::string_view>({
    // clang-format off
    "Sydney",               "Andergrove",           "Boulder",              "Stirling",
    "Melbourne",            "Moree",                "Picton",               "Perth",
    "Brisbane",             "Nowra",                "Albury",               "Barmera",
    "Perth",                "Colac",                "Mansfield",            "Kapunda",
    "Adelaide",             "Yanchep",              "Churchill",            "Thursday Island",
    "Gold Coast",           "Ballina",              "Bucasia",              "Terranora",
    "Cranbourne",           "Leeton",               "Temora",               "Woori Yallock",
    "Canberra",             "Moss Vale",            "Renmark",              "Saint Georges Basin",
    "Central Coast",        "Springwood",           "Tanunda",              "Tea Gardens",
    "Wollongong",           "Emu Plains",           "Loxton",               "Culburra",
    "Hobart",               "Ararat",               "Glenella",             "Yarra Glen",
    "Geelong",              "Tweed Heads",          "Numurkah",             "Beaconsfield Upper",
    "Townsville",           "Charters Towers",      "Korumburra",           "Deloraine",
    "Ipswich",              "Katoomba",             "Rasmussen",            "Greta",
    "Newcastle",            "Mooroopna",            "Tatura",               "North Wonthaggi",
    "Cairns",               "Maryborough",          "Old Bar",              "Howlong",
    "Darwin",               "Deniliquin",           "Narrandera",           "Williamstown",
    "Toowoomba",            "Mandurah",             "George Town",          "Waikerie",
    "Launceston",           "Bli Bli",              "Wyong",                "Hill Top",
    "Ballarat",             "Narrabri",             "Broadford",            "Hahndorf",
    "Bendigo",              "Clifton Springs",      "Drysdale",             "Jindabyne",
    "Mackay",               "Bargara",              "Cockatoo",             "Lawson",
    "Wagga Wagga",          "Kingscliff",           "Victor Harbor",        "Woodside",
    "Hervey Bay",           "Healesville",          "Moama",                "Narooma",
    "Pakenham",             "Fremantle",            "Latrobe",              "Grenfell",
    "Port Macquarie",       "Blaxland",             "Berri",                "Manilla",
    "Caloundra",            "Kyabram",              "Wellington",           "Daylesford",
    "Frankston",            "Sanctuary Point",      "Thirlmere",            "Lobethal",
    "Sunbury",              "Merrimac",             "Legana",               "The Oaks",
    "Gladstone",            "Murwillumbah",         "The Entrance",         "Aberdare",
    "Bathurst",             "Urraween",             "Cobar",                "Dodges Ferry",
    "Mildura",              "Kyneton",              "Gerringong",           "Launching Place",
    "Southport",            "Cootamundra",          "Margate",              "Rutherglen",
    "Dandenong",            "Castlemaine",          "Trafalgar",            "Goolwa",
    "Warrnambool",          "Bomaderry",            "Somerset",             "Willunga",
    "Burnie",               "Helensburgh",          "Kerang",               "Sandy Beach",
    "Quakers Hill",         "Port Augusta",         "Roxby Downs",          "Hadspen",
    "Caboolture",           "Yass",                 "Smithton",             "Canowindra",
    "Mount Gambier",        "Strathalbyn",          "Longford",             "Freeling",
    "Traralgon",            "Burpengary",           "Beechworth",           "Saint Arnaud",
    "Armidale",             "Waterford",            "Penguin",              "Baxter",
    "Whyalla",              "Lennox Head",          "Anna Bay",             "Walgett",
    "Griffith",             "Seymour",              "McLaren Vale",         "Esperance",
    "Mount Eliza",          "Nambucca Heads",       "Pearcedale",           "Yarram",
    "Nerang",               "Nuriootpa",            "Peregian Beach",       "Heddon Greta",
    "Lara",                 "Wauchope",             "Bellingen",            "Freshwater",
    "Taree",                "Tumut",                "Suffolk Park",         "Bangalow",
    "Banora Point",         "Tuncurry",             "Buninyong",            "Orbost",
    "Warragul",             "Glen Innes",           "Weston",               "Westbury",
    "Cessnock",             "Yamba",                "Sawtell",              "Lyndoch",
    "Horsham",              "Lakes Entrance",       "Silverdale",           "Camden Haven",
    "Australind",           "Kurri Kurri",          "Bay View",             "Wallerawang",
    "Barwon Heads",         "Wynyard",              "Lismore",              "Wattleglen",
    "Ulverstone",           "North Mackay",         "Koo-Wee-Rup",          "Bourke",
    "Echuca",               "Dromana",              "Merimbula",            "Mulwala",
    "Mount Barker",         "Mittagong",            "Scarness",             "Windsor",
    "Morwell",              "Alstonville",          "Lake Cathie",          "Nathalia",
    "Forster",              "Stawell",              "Condobolin",           "Oakdale",
    "Bongaree",             "Cannonvale",           "Paynesville",          "Cobden",
    "Penrith",              "Point Vernon",         "Maddingley",           "Queenstown",
    "Goonellabah",          "Leongatha",            "Hurstbridge",          "Denman",
    "Leopold",              "Scone",                "Quirindi",             "Batehaven",
    "Campbelltown",         "Whittlesea",           "Blayney",              "Brunswick Heads",
    "Muswellbrook",         "Corowa",               "Camperdown",           "Tathra",
    "Rutherford",           "Richmond",             "Aldgate",              "Yarragon",
    "Inverell",             "Cooranbong",           "Port Fairy",           "Yaroomba",
    "Parkes",               "Inverloch",            "Vincentia",            "Curlewis",
    "Nambour",              "New Norfolk",          "Euroa",                "Yallourn North",
    "Mareeba",              "Wingham",              "Marcoola",             "Drummond Cove",
    "Wallan",               "Woolgoolga",           "Mullumbimby",          "Surfside",
    "Corinda",              "Maffra",               "Tura Beach",           "Evandale",
    "Casino",               "Lithgow",              "Eden",                 "Kurrajong Heights",
    "Gympie",               "Millicent",            "West Wyalong",         "Seven Mile Beach",
    "Kingston",             "Worragee",             "Gilgandra",            "San Remo",
    "Grafton",              "Tahmoor",              "Robinvale",            "Valley Heights",
    "Bowral",               "Red Cliffs",           "Wilton",               "Greenwell Point",
    "Young",                "Glenbrook",            "Riverview",            "Innisfail",
    "Cowra",                "Nairne",               "Bogangar",             "Wahgunyah",
    "Swan Hill",            "Kiama Downs",          "Shoalhaven Heads",     "Tinonee",
    "Mudgee",               "Hazelbrook",           "Urunga",               "Mollymook",
    "Mount Evelyn",         "Encounter Bay",        "Bonny Hills",
    // clang-format on
});

const auto australiaStates = std::to_array<std::string_view>({
    "New South Wales",
    "Queensland",
    "Northern Territory",
    "South Australia",
    "Western Australia",
    "Tasmania",
    "Australian Capital Territory",
    "Victoria",
});

const auto australiaStreetSuffixes = std::to_array<std::string_view>({
    "Avenue", "Boulevard", "Circle",   "Circuit", "Court", "Crescent", "Crest", "Drive", "Estate Dr", "Grove",
    "Hill",   "Island",    "Junction", "Knoll",   "Lane",  "Loop",     "Mall",  "Manor", "Meadow",    "Mews",
    "Parade", "Parkway",   "Pass",     "Place",   "Plaza", "Ridge",    "Road",  "Run",   "Square",    "Station St",
    "Street", "Summit",    "Terrace",  "Track",   "Trail", "View Rd",  "Way",
});

const std::string_view australiaZipCodeFormat{"####"};

const auto australiaAddressFormats = std::to_array<std::string_view>({"{buildingNumber} {street}"});

const auto australiaBuildingNumberFormats = std::to_array<std::string_view>({"####", "###", "##"});

const auto australiaStreetFormats =
    std::to_array<std::string_view>({"{firstName} {streetSuffix}", "{lastName} {streetSuffix}"});

const auto australiaCityFormats = std::to_array<std::string_view>({"{cityName}"});

const CountryAddressesInfo australiaAddresses{
    australiaZipCodeFormat,
    (australiaAddressFormats),
    {},
    (australiaStreetFormats),
    {},
    {},
    (australiaStreetSuffixes),
    (australiaBuildingNumberFormats),
    (australiaCityFormats),
    {},
    (australiaCities),
    {},
    (australiaStates),
};

// Brazil

const auto brazilCitySuffixes = std::to_array<std::string_view>({
    "do Descoberto",
    "de Nossa Senhora",
    "do Norte",
    "do Sul",
});

const auto brazilStates = std::to_array<std::string_view>({
    // clang-format off
    "Acre",                 "Espírito Santo",       "Paraíba",              "Rondônia",
    "Alagoas",              "Goiás",                "Paraná",               "Roraima",
    "Amapá",                "Maranhão",             "Pernambuco",           "Santa Catarina",
    "Amazonas",             "Mato Grosso",          "Piauí",                "São Paulo",
    "Bahia",                "Mato Grosso do Sul",   "Rio de Janeiro",       "Sergipe",
    "Ceará",                "Minas Gerais",         "Rio Grande do Norte",  "Tocantins",
    "Distrito Federal",     "Pará",                 "Rio Grande do Sul",
    // clang-format on
});

const auto brazilStreetSuffixes = std::to_array<std::string_view>({
    "Rua",
    "Avenida",
    "Travessa",
    "Alameda",
    "Marginal",
    "Rodovia",
});

const std::string_view brazilZipCodeFormat{"#####-###"};

const auto brazilAddressFormats =
    std::to_array<std::string_view>({"{street} {buildingNumber}", "{street} {buildingNumber} {secondaryAddress}"});

const auto brazilSecondaryAddressFormats =
    std::to_array<std::string_view>({"Apto. ###", "Sobrado ##", "Casa #", "Lote ##", "Quadra ##"});

const auto brazilBuildingNumberFormats = std::to_array<std::string_view>({"#####", "####", "###"});

const auto brazilStreetFormats =
    std::to_array<std::string_view>({"{firstName} {streetSuffix}", "{lastName} {streetSuffix}"});

const auto brazilCityFormats = std::to_array<std::string_view>({"{firstName} {citySuffix}", "{lastName} {citySuffix}"});

const CountryAddressesInfo brazilAddresses{
    brazilZipCodeFormat,
    (brazilAddressFormats),
    (brazilSecondaryAddressFormats),
    (brazilStreetFormats),
    {},
    {},
    (brazilStreetSuffixes),
    (brazilBuildingNumberFormats),
    (brazilCityFormats),
    {},
    {},
    (brazilCitySuffixes),
    (brazilStates),
};

// Czech Republic

const auto czechCities = std::to_array<std::string_view>({
    // clang-format off
    "Abertamy",             "Fryšták",              "Košťany",              "Pardubice",
    "Adamov",               "Fulnek",               "Kouřim",               "Paskov",
    "Andělská Hora",        "Golčův Jeníkov",       "Krásno",               "Pec pod Sněžkou",
    "Aš",                   "Habartov",             "Kravaře",              "Pečky",
    "Bakov nad Jizerou",    "Habry",                "Krnov",                "Pelhřimov",
    "Bavorov",              "Hanušovice",           "Kroměříž",             "Petřvald",
    "Bechyně",              "Harrachov",            "Krupka",               "Pilníkov",
    "Beroun",               "Hartmanice",           "Kryry",                "Písek",
    "Bezdružice",           "Havířov",              "Kunovice",             "Planá",
    "Bílina",               "Havlíčkův Brod",       "Kunštát",              "Planá nad Lužnicí",
    "Bílovec",              "Hejnice",              "Kuřim",                "Plánice",
    "Blansko",              "Heřmanův Městec",      "Kutná Hora",           "Plasy",
    "Blatná",               "Hlinsko",              "Kyjov",                "Plesná",
    "Blovice",              "Hluboká nad Vltavou",  "Kynšperk nad Ohří",    "Plumlov",
    "Brno",                 "Hlučín",               "Lanškroun",            "Plzeň",
    "Broumov",              "Hluk",                 "Lanžhot",              "Poběžovice",
    "Brtnice",              "Hodkovice nad Mohelkou","Lázně Bělohrad",      "Počátky",
    "Brumov-Bylnice",       "Hodonín",              "Lázně Bohdaneč",       "Podbořany",
    "Bruntál",              "Holešov",              "Lázně Kynžvart",       "Poděbrady",
    "Bzenec",               "Holice",               "Ledeč nad Sázavou",    "Podivín",
    "Chabařovice",          "Holýšov",              "Ledvice",              "Pohořelice",
    "Cheb",                 "Hora Svaté Kateřiny",  "Letohrad",             "Police nad Metují",
    "Chlumec",              "Hrotovice",            "Letovice",             "Polička",
    "Chlumec nad Cidlinou", "Hroznětín",            "Libáň",                "Polná",
    "Choceň",               "Hrušovany nad Jevišovkou","Libčice nad Vltavou","Postoloprty",
    "Chodov",               "Hulín",                "Liběchov",             "Potštát",
    "Chomutov",             "Humpolec",             "Liberec",              "Prachatice",
    "Chotěboř",             "Husinec",              "Libochovice",          "Praha",
    "Chrast",               "Hustopeče",            "Město Albrechtice",    "Rabí",
    "Chrastava",            "Ivančice",             "Město Touškov",        "Radnice",
    "Chropyně",             "Ivanovice na Hané",    "Meziboří",             "Rájec-Jestřebí",
    "Chrudim",              "Jablonné nad Orlicí",  "Meziměstí",            "Rajhrad",
    "Chřibská",             "Jablonné v Podještědí","Mikulášovice",         "Rakovník",
    "Chvaletice",           "Jablunkov",            "Mikulov",              "Ralsko",
    "Chýnov",               "Jáchymov",             "Miletín",              "Raspenava",
    "Chyše",                "Janov",                "Milevsko",             "Rejštejn",
    "Cvikov",               "Janovice nad Úhlavou", "Milovice",             "Rokycany",
    "Čáslav",               "Janské Lázně",         "Mimoň",                "Rokytnice nad Jizerou",
    "Čelákovice",           "Jaroměř",              "Miroslav",             "Rokytnice v Orlických horách",
    "Černošice",            "Jaroměřice nad Rokytnou","Mirošov",            "Ronov nad Doubravou",
    "Černošín",             "Javorník",             "Mirotice",             "Rosice",
    "Černovice",            "Jemnice",              "Mirovice",             "Rotava",
    "Červená Řečice",       "Jesenice (okres Rakovník)","Mladá Boleslav",   "Roudnice nad Labem",
    "Červený Kostelec",     "Jeseník",              "Mladá Vožice",         "Rousínov",
    "Česká Kamenice",       "Jevíčko",              "Mnichovice",           "Rovensko pod Troskami",
    "Česká Lípa",           "Jevišovice",           "Mnichovo Hradiště",    "Roztoky",
    "Česká Skalice",        "Jičín",                "Mšeno",                "Rožďalovice",
    "Česká Třebová",        "Jirkov",               "Mýto",                 "Rožmberk nad Vltavou",
    "České Budějovice",     "Jiříkov",              "Náchod",               "Rožmitál pod Třemšínem",
    "České Velenice",       "Jistebnice",           "Nalžovské Hory",       "Rožnov pod Radhoštěm",
    "Český Brod",           "Kadaň",                "Náměšť nad Oslavou",   "Rtyně v Podkrkonoší",
    "Český Dub",            "Kamenický Šenov",      "Napajedla",            "Rudná",
    "Český Krumlov",        "Kaplice",              "Nasavrky",             "Rudolfov",
    "Český Těšín",          "Kardašova Řečice",     "Nechanice",            "Rumburk",
    "Dačice",               "Karlovy Vary",         "Nejdek",               "Rychnov nad Kněžnou",
    "Dašice",               "Karolinka",            "Němčice nad Hanou",    "Rychnov u Jablonce nad Nisou",
    "Děčín",                "Karviná",              "Nepomuk",              "Rychvald",
    "Desná",                "Kasejovice",           "Neratovice",           "Rýmařov",
    "Deštná",               "Kašperské Hory",       "Netolice",             "Řevnice",
    "Dobrovice",            "Kaznějov",             "Neveklov",             "Říčany",
    "Dobruška",             "Kdyně",                "Nový Jičín",           "Sadská",
    "Dobřany",              "Kelč",                 "Nový Knín",            "Sázava",
    "Dobřichovice",         "Kladno",               "Nymburk",              "Seč",
    "Dobříš",               "Kladruby",             "Nýrsko",               "Sedlčany",
    "Doksy",                "Klášterec nad Ohří",   "Nýřany",               "Sedlec-Prčice",
    "Dolní Benešov",        "Klatovy",              "Odolena Voda",         "Sedlice",
    "Dolní Bousov",         "Klecany",              "Odry",                 "Semily",
    "Dolní Kounice",        "Klimkovice",           "Olešnice",             "Sezemice",
    "Dolní Poustevna",      "Klobouky u Brna",      "Olomouc",              "Sezimovo Ústí",
    "Domažlice",            "Kojetín",              "Oloví",                "Skalná",
    "Dubá",                 "Kolín",                "Opava",                "Skuteč",
    "Dubí",                 "Konice",               "Opočno",               "Slaný",
    "Dubňany",              "Kopidlno",             "Orlová",               "Slatiňany",
    "Duchcov",              "Kopřivnice",           "Osečná",               "Slavičín",
    "Dvůr Králové nad Labem","Koryčany",            "Osek",                 "Slavkov u Brna",
    "Františkovy Lázně",    "Kosmonosy",            "Oslavany",             "Slavonice",
    "Frenštát pod Radhoštěm","Kostelec na Hané",    "Ostrava",              "Slušovice",
    "Frýdek-Místek",        "Kostelec nad Černými lesy","Ostrov",           "Smečno",
    "Frýdlant",             "Kostelec nad Labem",   "Otrokovice",           "Smiřice",
    "Frýdlant nad Ostravicí","Kostelec nad Orlicí", "Pacov",                "Smržovka",
    // clang-format on
});

const auto czechStates = std::to_array<std::string_view>({
    "Jihočeský kraj",
    "Jihomoravský kraj",
    "Karlovarský kraj",
    "Kraj Vysočina",
    "Královéhradecký kraj",
    "Liberecký kraj",
    "Moravskoslezský kraj",
    "Olomoucký kraj",
    "Pardubický kraj",
    "Plzeňský kraj",
    "Praha",
    "Středočeský kraj",
    "Ústecký kraj",
    "Zlínský kraj",
});

const auto czechStreetNames = std::to_array<std::string_view>({
    // clang-format off
    "Akademická",           "Egyptská",             "Kurčatovova",          "Miroslava Hamra",
    "Aksamitova",           "Eichlerova",           "Kusá",                 "Mirotická",
    "Akátová",              "Ellnerové",            "Kusého",               "Návětrná",
    "Alabastrová",          "Elsnicovo Náměstí",    "Kutilova",             "Názovská",
    "Albertov",             "Emilie Hyblerové",     "Kutnauerovo Náměstí",  "Nýdecká",
    "Albrechtická",         "Emlerova",             "Kutnohorská",          "Nýrská",
    "Albánská",             "Engelmüllerova",       "Kutrovická",           "Nýřanská",
    "Albíny Hochové",       "Fabiánská",            "Kuttelwascherova",     "Němčická",
    "Aldašínská",           "Fadějevova",           "Kutvirtova",           "Otavská",
    "Alej Českých Exulantů","Fajmanové",            "Kučerova",             "Otevřená",
    "Amforová",             "Fajtlova",             "Kučerové",             "Otická",
    "Amortova",             "Falcká",               "Kuťatská",             "Otlíkovská",
    "Ampérova",             "Faltysova",            "Kuželova",             "Otopašská",
    "Amurská",              "Famfulíkova",          "Kvapilova",            "Otovická",
    "Anastázova",           "Fantova",              "Kyjská",               "Otradovická",
    "Anderleho",            "Fibichova",            "Kykalova",             "Ottova",
    "Chládkova",            "Fikerova",             "Kymrova",              "Otvovická",
    "Chmelařská",           "Filipova",             "Kynická",              "Oty Pavla",
    "Chmelická",            "Filipovského",         "Kyselova",             "Otínská",
    "Chmelová",             "Filipíny Welserové",   "Kyslíková",            "Otěšínská",
    "Chmelířova",           "Fillova",              "Kysucká",              "Ouholická",
    "Choceradská",          "Filmařská",            "Kysúcká",              "Ouhrabkova",
    "Choceňská",            "Filosofská",           "Kytlická",             "Ovenecká",
    "Chocholouškova",       "Fingerova",            "Kytínská",             "Ovesná",
    "Chrpová",              "Finkovská",            "Kácovská",             "Ovocná",
    "Chrudimská",           "Finská",               "Kádnerova",            "Ovocnářská",
    "Chráněná",             "Firkušného",           "Kálikova",             "Ovocný Trh",
    "Cihelná",              "Fischlova",            "Kálmánova",            "Ovsíková",
    "Cuřínova",             "Fišerova",             "Káranská",             "Oválová",
    "Cvikovská",            "Flemingovo Nám.",      "Křejpského",           "Ovčárská",
    "Cvičebná",             "Flemingovo Náměstí",   "Křelovická",           "Ovčí Hájek",
    "Cvrčkova",             "Flájská",              "Křemelná",             "Ořechová",
    "Cyprichova",           "Flöglova",             "Křemencova",           "Ořešská",
    "Cíglerova",            "Foerstrova",           "Křemenná",             "Paběnická",
    "Cílkova",              "Folmavská",            "Lamačova",             "Pacajevova",
    "Cínovecká",            "Formanská",            "Langweilova",          "Paceřická",
    "Církova",              "Formánkova",           "Lannova",              "Panelová",
    "Církvická",            "Františka Šimáčka",    "Lanýžová",             "Panenky",
    "Církvičná",            "Frézařská",            "Lanžhotská",           "Panenská",
    "Císařská Louka",       "Frýdecká",             "Lhotákova",            "Pankrácké Náměstí",
    "Císařský Ostrov",      "Frýdlantská",          "Liberecká",            "Panská",
    "Cítovská",             "Fuchsova",             "Liberijská",           "Panská Zahrada",
    "Drimlova",             "Fügnerovo Nám.",       "Libečkova",            "Panský Dvůr",
    "Drnovská",             "Fügnerovo Náměstí",    "Libeňská",             "Panuškova",
    "Drobná",               "Gabinova",             "Libeňský Ostrov",      "Paprsková",
    "Drtikolova",           "Gabčíkova",            "Malátova",             "Papírenská",
    "Drtinova",             "Gagarinova",           "Malé Nám.",            "Papírníkova",
    "Druhanická",           "Galandova",            "Martinova",            "Parašutistů",
    "Druhého Odboje",       "Galileova",            "Martinovská",          "Pardubická",
    "Družicová",            "Gallašova",            "Martinská",            "Park Přátelství",
    "Družnosti",            "Galvaniho",            "Marty Krásové",        "Parková",
    "Družná",               "Gaussova",             "Marvanova",            "Parléřova",
    "Dudkova",              "Gdaňská",              "Maršovská",            "Parmská",
    "Dudínská",             "Gollova",              "Masarykovo Nábř.",     "Paroplavební",
    "Duhová",               "Golčova",              "Masarykovo Nábřeží",   "Partyzánská",
    "Dukelská",             "Gončarenkova",         "Masná",                "Pasecká",
    "Dukelských Hrdinů",    "Gorazdova",            "Matek",                "Pasteurova",
    "Dunajevského",         "Gotthardská",          "Meziluží",             "Pastevců",
    "Dunajská",             "Goyova",               "Mezipolí",             "Patočkova",
    "Dunická",              "Gočárova",             "Mezitraťová",          "Pavelkova",
    "Dunovského",           "Grafická",             "Mezivrší",             "Pavla Beneše",
    "Durychova",            "Grafitová",            "Meziškolská",          "Pavla Švandy Ze Semčic",
    "Dusíkova",             "Grammova",             "Mečislavova",          "Pavlická",
    "Duškova",              "Granátová",            "Mečovská",             "Pavlišovská",
    "Dušní",                "Gregorova",            "Mečíková",             "Pavlovická",
    "Dvorecká",             "Grussova",             "Michalovicova",        "Rackova Zahrada",
    "Dvorecké Nám.",        "Gruzínská",            "Michalská",            "Radbuzská",
    "Dvorecké Náměstí",     "Gutfreundova",         "Michelangelova",       "Radechovská",
    "Dvorní",               "Gutova",               "Michelská",            "Radešovská",
    "Dvorská",              "Gymnasijní",           "Michnova",             "Sadařská",
    "Dvoudílná",            "Hříbková",             "Michnovka",            "Sadová",
    "Dětský Ostrov",        "Hřídelecká",           "Mickiewiczova",        "Sadská",
    "Děvínská",             "Hůlkova",              "Mikanova",             "Sady Bratří Čapků",
    "Děčínská",             "Izraelská",            "Milovická",            "Safírová",
    "Dřevařská",            "Jana Ouřady",          "Milánská",             "Salabova",
    "Dřevnická",            "Janýrova",             "Milínská",             "Salačova",
    "Dřevná",               "Jančova",              "Milíčova",             "Salmovská",
    "Dřevčická",            "Jarešova",             "Milíčovská",           "Salvátorská",
    "Dřínovská",            "Jarkovská",            "Mimoňská",             "Samcova",
    "Dřínová",              "Jarmily Novotné",      "Minaříkova",           "Samohelova",
    "Dřítenská",            "Jarní",                "Minerální",            "Samota U Podleského Rybníka",
    "Eberlova",             "Jarníkova",            "Minická",              "Sarajevská",
    "Ebrova",               "Jaromíra Jindry",      "Minská",               "Saratovská",
    "Edisonova",            "Kurta Konráda",        "Miranova",             "Sartoriova",
    "Edvardova",            "Kurzova",              "Miroslava Hajna",
    // clang-format on
});

const std::string_view czechZipCodeFormat{"#####"};

const auto czechAddressFormats =
    std::to_array<std::string_view>({"{street} {buildingNumber}", "{street} {buildingNumber} {secondaryAddress}"});

const auto czechSecondaryAddressFormats = std::to_array<std::string_view>({"Apt. ###", "Suite ###"});

const auto czechBuildingNumberFormats = std::to_array<std::string_view>({"#", "##", "###"});

const auto czechStreetFormats = std::to_array<std::string_view>({"{streetName}"});

const auto czechCityFormats = std::to_array<std::string_view>({"{cityName}"});

const CountryAddressesInfo czechAddresses{
    czechZipCodeFormat,
    (czechAddressFormats),
    (czechSecondaryAddressFormats),
    (czechStreetFormats),
    {},
    (czechStreetNames),
    {},
    (czechBuildingNumberFormats),
    (czechCityFormats),
    {},
    (czechCities),
    {},
    (czechStates),
};

// Denmark

const auto denmarkCities = std::to_array<std::string_view>({
    // clang-format off
    "Albertslund",          "Hadsund",              "Løgten",               "Strøby Egede",
    "Arden",                "Harlev",               "Løgumkloster",         "Støvring",
    "Asnæs",                "Haslev",               "Mariager",             "Sundby",
    "Assentoft",            "Havdrup",              "Middelfart",           "Sunds",
    "Augustenborg",         "Hedehusene",           "Mårslet",              "Svejbæk",
    "Aulum",                "Hedensted",            "Nakskov",              "Svendborg",
    "Auning",               "Helsinge",             "Nexø",                 "Svinninge",
    "Ballerup",             "Helsingør",            "Nivå",                 "Svogerslev",
    "Beder-Malling",        "Herlev",               "Nordby",               "Sæby",
    "Bellinge",             "Herning",              "Nyborg",               "Søften",
    "Birkerød",             "Hillerød",             "Nykøbing F",           "Sønderborg",
    "Bjæverskov",           "Hinnerup",             "Nykøbing M",           "Søndersø",
    "Bogense",              "Hjallerup",            "Næstved",              "Tarm",
    "Borup",                "Hjortshøj",            "Nørre Åby",            "Taulov",
    "Brejning",             "Hjørring",             "Nørresundby",          "Thisted",
    "Broager",              "Hobro",                "Odder",                "Thurø By",
    "Brovst",               "Holbæk",               "Odense",               "Tinglev",
    "Brædstrup",            "Holstebro",            "Oksbøl",               "Tjæreborg",
    "Brøndby",              "Holsted",              "Otterup",              "Toftlund",
    "Brønderslev",          "Horsens",              "Padborg",              "Trige",
    "Brørup",               "Humlebæk",             "Pandrup",              "Tune",
    "Christiansfeld",       "Hundested",            "Præstø",               "Tølløse",
    "Dianalund",            "Hurup",                "Randers",              "Tørring",
    "Dragør",               "Hvide Sande",          "Ribe",                 "Taarbæk",
    "Dronninglund",         "Hvidovre",             "Ringkøbing",           "Tårnby",
    "Ejby",                 "Højslev Stationsby",   "Ringsted",             "Taastrup",
    "Esbjerg",              "Høng",                 "Roskilde",             "Ullerslev",
    "Farsø",                "Hørning",              "Rudersdal",            "Vallensbæk",
    "Farum",                "Hørsholm",             "Rudkøbing",            "Vamdrup",
    "Faxe Ladeplads",       "Høruphav",             "Rødding",              "Varde",
    "Faxe",                 "Ikast",                "Rødovre",              "Vejen",
    "Fensmark",             "Ishøj",                "Rønde",                "Vejle",
    "Fjerritslev",          "Jelling",              "Rønne",                "Vestbjerg",
    "Fredensborg",          "Juelsminde",           "Sabro",                "Vester Hassing",
    "Fredericia",           "Jyderup",              "Sakskøbing",           "Viborg",
    "Frederiksberg",        "Jyllinge",             "Sankt Klemens",        "Viby S",
    "Frederikshavn",        "Jægerspris",           "Silkeborg",            "Videbæk",
    "Frederikssund",        "Kalundborg",           "Sindal",               "Vildbjerg",
    "Frederiksværk",        "Kibæk",                "Skanderborg",          "Vinderup",
    "Frejlev",              "Kirke Hvalsø",         "Skibby",               "Virklund",
    "Galten",               "Kjellerup",            "Skive",                "Vissenbjerg",
    "Ganløse",              "Klarup",               "Skærbæk",              "Vodskov",
    "Gentofte",             "Kolding",              "Skævinge",             "Vordingborg",
    "Gistrup",              "Korsør",               "Skørping",             "Værløse",
    "Give",                 "København",            "Slagelse",             "Ølgod",
    "Gladsaxe",             "Køge",                 "Smørumnedre",          "Ølstykke",
    "Glamsbjerg",           "Kås",                  "Solbjerg",             "Aabenraa",
    "Glostrup",             "Langeskov",            "Solrød Strand",        "Aalborg",
    "Grenaa",               "Langå",                "Sorø",                 "Aalestrup",
    "Greve Strand",         "Lillerød",             "Stege",                "Aarhus",
    "Grindsted",            "Liseleje",             "Stenløse",             "Aars",
    "Græsted",              "Lunderskov",           "Stoholm",              "Årslev",
    "Gråsten",              "Lyngby",               "Store Heddinge",       "Aarup",
    "Guderup",              "Lynge-Uggeløse",       "Storvorde",
    "Haderslev",            "Lystrup",              "Strib",
    "Hadsten",              "Løgstør",              "Struer",
    // clang-format on
});

const auto denmarkStates = std::to_array<std::string_view>({
    "Region Hovedstaden",
    "Region Midtjylland",
    "Region Nordjylland",
    "Region Sjælland",
    "Region Syddanmark",
});

const auto denmarkStreetNames = std::to_array<std::string_view>({
    // clang-format off
    "Agervej",              "Gadekæret",            "Lærkevej",             "Sydvej",
    "Askevej",              "Galgebjergvej",        "Markvej",              "Sølvgade",
    "Bakkedraget",          "Gammel Kongevej",      "Mosevej",              "Søndergade",
    "Bakkegårdsvej",        "Gartnervej",           "Munkevej",             "Teglværksvej",
    "Bakkevej",             "Gl. Kongevej",         "Mælkevejen",           "Tjørnevej",
    "Banevænget",           "Granvej",              "Møllebækvej",          "Torvet",
    "Birkealle",            "Havnevej",             "Møllegade",            "Tranevej",
    "Birkeparken",          "Hedelundvej",          "Møllevænget",          "Trekanten",
    "Birkevej",             "Hejrevej",             "Mågevej",              "Troldhøjvej",
    "Bjergvej",             "Hestehavevej",         "Nedre Gade",           "Tulipanvej",
    "Bredgade",             "Hovedgaden",           "Nordre Strandvej",     "Tværgade",
    "Carlsmindevej",        "Højagervej",           "Nordvestpassagen",     "Udsigten",
    "Cedervej",             "Højvej",               "Nygade",               "Udsigtsbakken",
    "Chr. Winthersvej",     "Idrætsvej",            "Nytorv",               "Udsigtsvej",
    "Clematisvej",          "Ildervej",             "Nyvej",                "Ullevej",
    "Cypresvej",            "Industrigade",         "Nørrebrogade",         "Ulstrupvej",
    "Cypresvænget",         "Industrivej",          "Nørregade",            "Ulvevej",
    "Dalevej",              "Irisvej",              "Overgaden",            "Uplandsvej",
    "Dalgas Boulevard",     "Islandsvej",           "Parkvej",              "Valmuevej",
    "Dalsvinget",           "Jagtvej",              "Pilestræde",           "Valnøddevej",
    "Damvej",               "Jernbanegade",         "Pilevej",              "Vandtårnsvej",
    "Dronningensgade",      "Jernbanevej",          "Plantagevej",          "Ved Stranden",
    "Dybdalsvej",           "Jupitervej",           "Poppelvej",            "Vestergade",
    "Dyrskuevej",           "Jydevej",              "Præstegårdsvej",       "Vestergårdsvej",
    "Egevej",               "Jægergårdsvej",        "Præstevænget",         "Vibevej",
    "Egholmvej",            "Jægervej",             "Ravnevej",             "Viborgvej",
    "Ejstrupvej",           "Kastanievej",          "Rosenhaven",           "Ørnevej",
    "Ellevej",              "Kirkegade",            "Rosenvej",             "Østerbrogade",
    "Elmevej",              "Klostermarken",        "Rugårdsvej",           "Østergade",
    "Enevej",               "Klostervej",           "Ryttervej",            "Østervang",
    "Engvej",               "Kornmarken",           "Rævevej",              "Østre Alle",
    "Eskebjergvej",         "Kærbyvej",             "Rådhusvej",            "Østre Stationsvej",
    "Fasanvej",             "Kærparken",            "Skolegade",            "Åbjergvej",
    "Fjordvej",             "Kærvej",               "Skolestræde",          "Åboulevarden",
    "Fuglevangsvej",        "Liljens Kvarter",      "Skolevej",             "Ådalsvej",
    "Fuglevej",             "Liljevej",             "Skovbrynet",           "Ågade",
    "Fuglsangsvej",         "Lindevej",             "Skovvej",              "Åstrupvej",
    "Fyrretræsvej",         "Lunden",               "Slotsvej",             "Åvænget",
    "Fyrrevej",             "Lundevej",             "Solbakken",
    "Fyrvej",               "Lyngvej",              "Strandgade",
    // clang-format on
});

const std::string_view denmarkZipCodeFormat{"####"};

const auto denmarkAddressFormats =
    std::to_array<std::string_view>({"{street} {buildingNumber}", "{street} {buildingNumber} {secondaryAddress}"});

const auto denmarkSecondaryAddressFormats = std::to_array<std::string_view>({"#. tv", "#. th"});

const auto denmarkBuildingNumberFormats = std::to_array<std::string_view>({"#", "##", "###", "##A", "##B"});

const auto denmarkStreetFormats = std::to_array<std::string_view>({"{streetName}"});

const auto denmarkCityFormats = std::to_array<std::string_view>({"{cityName}"});

const CountryAddressesInfo denmarkAddresses{
    denmarkZipCodeFormat,
    (denmarkAddressFormats),
    (denmarkSecondaryAddressFormats),
    (denmarkStreetFormats),
    {},
    (denmarkStreetNames),
    {},
    (denmarkBuildingNumberFormats),
    (denmarkCityFormats),
    {},
    (denmarkCities),
    {},
    (denmarkStates),
};

// Estonia

const auto estoniaCities = std::to_array<std::string_view>({
    "Tallinn",
    "Tartu",
    "Narva",
    "Pärnu",
    "Kohtla-Järve",
});

const auto estoniaStreetNames = std::to_array<std::string_view>({
    "Laagna",   "Punane",    "Paepargi",   "Pae",    "Peterburi",   "Valukoja",       "Betooni", "Sõpruse",
    "Mustamäe", "Tuisu",     "Külmallika", "Tammi",  "Koore",       "Kuubi",          "Okka",    "Vaba",
    "Tähe",     "Õnne",      "Aleksandri", "Kalevi", "Turu",        "Tähe",           "Lina",    "Õnne",
    "Era",      "Vanemuise", "Tiigi",      "Tiigi",  "Juhan Liivi", "K. A. Hermanni", "Veski",
});

const auto estoniaStreetSuffixes = std::to_array<std::string_view>({
    "Tänav",
    "tn",
    "Tee",
    "Allee",
    "Plats",
    "Käik",
    "Põik",
});

const std::string_view estoniaZipCodeFormat{"#####"};

const auto estoniaAddressFormats = std::to_array<std::string_view>({"{street} {buildingNumber}"});

const auto estoniaBuildingNumberFormats = std::to_array<std::string_view>({"###", "##", "#"});

const auto estoniaStreetFormats = std::to_array<std::string_view>({"{streetName} {streetSuffix}"});

const auto estoniaCityFormats = std::to_array<std::string_view>({"{cityName}"});

const CountryAddressesInfo estoniaAddresses{
    estoniaZipCodeFormat,
    (estoniaAddressFormats),
    {},
    (estoniaStreetFormats),
    {},
    (estoniaStreetNames),
    (estoniaStreetSuffixes),
    (estoniaBuildingNumberFormats),
    (estoniaCityFormats),
    {},
    (estoniaCities),
    {},
    {},
};

// Finland

const auto finlandCities = std::to_array<std::string_view>({
    "Espoo",     "Helsinki", "Hyvinkää", "Iisalmi", "Joensuu",     "Jyväskylä", "Kokkola",
    "Kuopio",    "Lahti",    "Oulu",     "Pori",    "Porvoo",      "Raisio",    "Rovaniemi",
    "Sastamala", "Tampere",  "Turku",    "Vaasa",   "Valkeakoski", "Vantaa",
});

const auto finlandStates = std::to_array<std::string_view>({
    "Ahvenanmaa",   "Etelä-Karjala",   "Etelä-Pohjanmaa", "Etelä-Savo",      "Kainuu",
    "Kanta-Häme",   "Keski-Pohjanmaa", "Keski-Suomi",     "Kymenlaakso",     "Lappi",
    "Päijät-Häme",  "Pirkanmaa",       "Pohjanmaa",       "Pohjois-Karjala", "Pohjois-Pohjanmaa",
    "Pohjois-Savo", "Satakunta",       "Uusimaa",         "Varsinais-Suomi",
});

const auto finlandStreetSuffixes = std::to_array<std::string_view>({
    "katu",
    "tie",
    "kuja",
    "polku",
    "kaari",
    "linja",
    "raitti",
    "rinne",
    "penger",
    "ranta",
    "väylä",
});

const std::string_view finlandZipCodeFormat{"#####"};

const auto finlandAddressFormats =
    std::to_array<std::string_view>({"{street} {buildingNumber}", "{street} {buildingNumber} {secondaryAddress}"});

const auto finlandSecondaryAddressFormats =
    std::to_array<std::string_view>({"A", "B", "C", "A #", "A ##", "B #", "B ##", "C #", "C ##"});

const auto finlandBuildingNumberFormats = std::to_array<std::string_view>({"###", "##", "#"});

const auto finlandStreetFormats =
    std::to_array<std::string_view>({"{firstName} {streetSuffix}", "{lastName} {streetSuffix}"});

const auto finlandCityFormats = std::to_array<std::string_view>({"{cityName}"});

const CountryAddressesInfo finlandAddresses{
    finlandZipCodeFormat,
    (finlandAddressFormats),
    (finlandSecondaryAddressFormats),
    (finlandStreetFormats),
    {},
    {},
    (finlandStreetSuffixes),
    (finlandBuildingNumberFormats),
    (finlandCityFormats),
    {},
    (finlandCities),
    {},
    (finlandStates),
};

// France

const auto franceCities = std::to_array<std::string_view>({
    // clang-format off
    "Abbeville",                    "Fourmies",                     "Maisons-Alfort",               "Remire-Montjoly",
    "Achères",                      "Francheville",                 "Maisons-Laffitte",             "Rennes",
    "Agde",                         "Franconville",                 "Maizières-lès-Metz",           "Rezé",
    "Agen",                         "Fréjus",                       "Malakoff",                     "Riedisheim",
    "Aix-en-Provence",              "Fresnes",                      "Mamoudzou",                    "Rillieux-la-Pape",
    "Aix-les-Bains",                "Freyming-Merlebach",           "Mana",                         "Royan",
    "Ajaccio",                      "Frontignan",                   "Mandelieu-la-Napoule",         "Rueil-Malmaison",
    "Albertville",                  "Gagny",                        "Manosque",                     "Rumilly",
    "Albi",                         "Gaillac",                      "Mantes-la-Jolie",              "Sablé-sur-Sarthe",
    "Alençon",                      "Gaillard",                     "Mantes-la-Ville",              "Sada",
    "Alès",                         "Gap",                          "Marck",                        "Saint-Amand-les-Eaux",
    "Alfortville",                  "Garches",                      "Marcq-en-Barœul",              "Saint-André",
    "Asnières-sur-Seine",           "Gardanne",                     "Marignane",                    "Saint-André-de-Cubzac",
    "Athis-Mons",                   "Garges-lès-Gonesse",           "Marly",                        "Saint-André-les-Vergers",
    "Aubagne",                      "Genas",                        "Marly-le-Roi",                 "Saint-André-lez-Lille",
    "Aubenas",                      "Gennevilliers",                "Marmande",                     "Saint-Avé",
    "Bron",                         "Gentilly",                     "Maromme",                      "Saint-Avertin",
    "Bruay-la-Buissière",           "Gerzat",                       "Marquette-lez-Lille",          "Saint-Avold",
    "Bruay-sur-l'Escaut",           "Gex",                          "Marseille",                    "Sens",
    "Bruges",                       "Gien",                         "Martigues",                    "Septèmes-les-Vallons",
    "Brunoy",                       "Gif-sur-Yvette",               "Massy",                        "Sète",
    "Bruz",                         "Héricourt",                    "Matoury",                      "Sevran",
    "Bry-sur-Marne",                "Hérouville-Saint-Clair",       "Maubeuge",                     "Tarnos",
    "Bully-les-Mines",              "Hœnheim",                      "Mauges-sur-Loire",             "Tassin-la-Demi-Lune",
    "Bussy-Saint-Georges",          "Houilles",                     "Mauguio",                      "Taverny",
    "Cabestany",                    "Hyères",                       "Maurepas",                     "Tergnier",
    "Cachan",                       "Ifs",                          "Mayenne",                      "Thiais",
    "Caen",                         "Illkirch-Graffenstaden",       "Meaux",                        "Thiers",
    "Cagnes-sur-Mer",               "Illzach",                      "Melun",                        "Thionville",
    "Cahors",                       "Issoire",                      "Mende",                        "Thonon-les-Bains",
    "Calais",                       "Issoudun",                     "Mennecy",                      "Thorigny-sur-Marne",
    "Caluire-et-Cuire",             "Issy-les-Moulineaux",          "Menton",                       "Thouaré-sur-Loire",
    "Challans",                     "Istres",                       "Méricourt",                    "Thouars",
    "Chalon-sur-Saône",             "Ivry-sur-Seine",               "Montauban",                    "Tinqueux",
    "Châlons-en-Champagne",         "Jeumont",                      "Montbéliard",                  "Torcy",
    "Chamalières",                  "Joinville-le-Pont",            "Montbrison",                   "Toul",
    "Chambéry",                     "Joué-lès-Tours",               "Montceau-les-Mines",           "Toulon",
    "Chambray-lès-Tours",           "Jouy-le-Moutier",              "Montélimar",                   "Toulouse",
    "Champigny-sur-Marne",          "Juvignac",                     "Montereau-Fault-Yonne",        "Tourcoing",
    "Champs-sur-Marne",             "Juvisy-sur-Orge",              "Montesson",                    "Tournefeuille",
    "Chanteloup-les-Vignes",        "Kingersheim",                  "Monteux",                      "Tournon-sur-Rhône",
    "Chantilly",                    "Lanester",                     "Moorea-Maiao",                 "Tours",
    "Charenton-le-Pont",            "Lannion",                      "Morangis",                     "Trappes",
    "Charleville-Mézières",         "Laon",                         "Moret-Loing-et-Orvanne",       "Trélazé",
    "Chartres",                     "Lattes",                       "Morlaix",                      "Tremblay-en-France",
    "Chassieu",                     "Laval",                        "Morne-à-l'Eau",                "Trets",
    "Château-Gontier-sur-Mayenne",  "Lavaur",                       "Morsang-sur-Orge",             "Triel-sur-Seine",
    "Château-Thierry",              "Libourne",                     "Mougins",                      "Troyes",
    "Châteaubriant",                "Lieusaint",                    "Moulins",                      "Vauréal",
    "Cholet",                       "Liévin",                       "Mouvaux",                      "Vauvert",
    "Clamart",                      "Lille",                        "Mulhouse",                     "Vaux-le-Pénil",
    "Claye-Souilly",                "Limay",                        "Muret",                        "Vedène",
    "Clermont-Ferrand",             "Limeil-Brévannes",             "Nancy",                        "Vélizy-Villacoublay",
    "Clichy",                       "Limoges",                      "Ollioules",                    "Villeurbanne",
    "Dinan",                        "Lingolsheim",                  "Oloron-Sainte-Marie",          "Villiers-le-Bel",
    "Dole",                         "Lisieux",                      "Onet-le-Château",              "Villiers-sur-Marne",
    "Domont",                       "Livry-Gargan",                 "Orange",                       "Vincennes",
    "Douai",                        "Lognes",                       "Orée d'Anjou",                 "Vire Normandie",
    "Douarnenez",                   "Loire-Authion",                "Orléans",                      "Viroflay",
    "Doué-en-Anjou",                "Longjumeau",                   "Orly",                         "Viry-Châtillon",
    "Dourdan",                      "Longuenesse",                  "Ormesson-sur-Marne",           "Vitré",
    "Draguignan",                   "Longwy",                       "Papeete",                      "Vitrolles",
    "Drancy",                       "Lons",                         "Paris",                        "Vitry-le-François",
    "Draveil",                      "Lons-le-Saunier",              "Passy",                        "Vitry-sur-Seine",
    "Dreux",                        "Loos",                         "Pau",                          "Voiron",
    "Ducos",                        "Lorient",                      "Pélissanne",                   "Voisins-le-Bretonneux",
    "Dugny",                        "Lormont",                      "Périgueux",                    "Wambrechies",
    "Dumbéa",                       "Lourdes",                      "Pernes-les-Fontaines",         "Wasquehal",
    "Dunkerque",                    "Louviers",                     "Perpignan",                    "Wattignies",
    "Dzaoudzi",                     "Louvres",                      "Persan",                       "Wattrelos",
    "Fontainebleau",                "Lucé",                         "Pertuis",                      "Wittelsheim",
    "Fontenay-aux-Roses",           "Lunel",                        "Poitiers",                     "Wittenheim",
    "Fontenay-le-Comte",            "Lunéville",                    "Pont-Saint-Esprit",            "Woippy",
    "Fontenay-le-Fleury",           "Lyon",                         "Pont-Sainte-Maxence",          "Yerres",
    "Fontenay-sous-Bois",           "Lys-lez-Lannoy",               "Pont-à-Mousson",               "Yutz",
    "Forbach",                      "Mâcon",                        "Pont-du-Château",              "Yvetot",
    "Fort-de-France",               "Macouria",                     "Pontarlier",
    "Fos-sur-Mer",                  "Mahina",                       "Pontault-Combault",
    "Fougères",                     "Mainvilliers",                 "Pontchâteau",
    // clang-format on
});

const auto franceStates = std::to_array<std::string_view>({
    "Alsace",
    "Centre",
    "Languedoc-Roussillon",
    "Picardie",
    "Aquitaine",
    "Champagne-Ardenne",
    "Limousin",
    "Poitou-Charentes",
    "Auvergne",
    "Corse",
    "Lorraine",
    "Provence-Alpes-Côte d\"Azur",
    "Basse-Normandie",
    "Franche-Comté",
    "Midi-Pyrénées",
    "Rhône-Alpes",
    "Bourgogne",
    "Haute-Normandie",
    "Nord-Pas-de-Calais",
    "Bretagne",
    "Île-de-France",
    "Pays de la Loire",
});

const auto franceStreetPrefixes = std::to_array<std::string_view>(
    {"allée", "voie", "rue", "avenue", "boulevard", "quai", "passage", "impasse", "place", "chemin", "lotissement"});

const auto franceStreetSuffixes = std::to_array<std::string_view>(
    {"du Faubourg Saint-Honoré", "de Montmorency", "de Solférino", "de la Pompe", "de Rivoli", "de Paris",
     "du Faubourg-Saint-Denis",  "de la Huchette", "Saint-Honoré", "Pastourelle", "Oberkampf", "d'Alésia",
     "de la Chaussée-d'Antin",   "de la Bûcherie", "de Richelieu", "Montorgueil", "Delesseux", "Zadkine",
     "des Grands Augustins",     "des Saussaies",  "de Presbourg", "de la Harpe", "Bonaparte", "d'Orsel",
     "des Francs-Bourgeois",     "Saint-Séverin",  "des Lombards", "Charlemagne", "La Boétie", "Molière",
     "Monsieur-le-Prince",       "Saint-Jacques",  "de Caumartin", "de l'Abbaye", "de Seine",  "Joubert",
     "de la Ferronnerie",        "Saint-Bernard",  "d'Argenteuil", "de Tilsitt",  "de Nesle",  "d'Assas",
     "du Chat-qui-Pêche",        "des Panoramas",  "Saint-Denis",  "de la Paix",  "Marcadet",  "Vaneau",
     "Saint-Dominique",          "Adolphe Mille",  "d'Abbeville",  "de l'Odéon",  "Laffitte",  "Royale",
     "de la Victoire",           "de Vaugirard",   "des Rosiers",  "Mouffetard",  "du Havre",  "du Bac",
     "Pierre Charron",           "Du Sommerard",   "de Provence",  "du Dahomey",  "Dauphine",  "Lepic"});

const std::string_view franceZipCodeFormat{"#####"};

const auto franceAddressFormats = std::to_array<std::string_view>({"{buildingNumber} {street}"});

const auto franceBuildingNumberFormats = std::to_array<std::string_view>({"####", "###", "##", "#"});

const auto franceSecondaryAddressFormats = std::to_array<std::string_view>({"Apt. ###", "Étage #"});

const auto franceStreetFormats = std::to_array<std::string_view>({"{streetPrefix} {streetSuffix}"});

const auto franceCityFormats = std::to_array<std::string_view>({"{cityName}"});

const CountryAddressesInfo franceAddresses{
    franceZipCodeFormat,
    (franceAddressFormats),
    (franceSecondaryAddressFormats),
    (franceStreetFormats),
    (franceStreetPrefixes),
    {},
    (franceStreetSuffixes),
    (franceBuildingNumberFormats),
    (franceCityFormats),
    {},
    (franceCities),
    {},
    (franceStates),
};

// Germany

const auto germanyCities = std::to_array<std::string_view>({
    // clang-format off
    "Aachen",               "Euskirchen",           "Kleve",                "Pforzheim",
    "Aalen",                "Flensburg",            "Koblenz",              "Plauen",
    "Ahlen",                "Frankfurt (Oder)",     "Köln",                 "Potsdam",
    "Arnsberg",             "Frankfurt am Main",    "Konstanz",             "Pulheim",
    "Aschaffenburg",        "Frechen",              "Krefeld",              "Rastatt",
    "Augsburg",             "Freiburg im Breisgau", "Landshut",             "Ratingen",
    "Bad Homburg vor der Höhe","Friedrichshafen",   "Langenfeld (Rheinland)","Ravensburg",
    "Bad Kreuznach",        "Fulda",                "Langenhagen",          "Recklinghausen",
    "Bad Oeynhausen",       "Fürth",                "Leipzig",              "Regensburg",
    "Bad Salzuflen",        "Garbsen",              "Leonberg",             "Remscheid",
    "Baden-Baden",          "Gelsenkirchen",        "Leverkusen",           "Reutlingen",
    "Bamberg",              "Gera",                 "Lingen (Ems)",         "Rheine",
    "Bayreuth",             "Gießen",               "Lippstadt",            "Rosenheim",
    "Bergheim",             "Gladbeck",             "Lörrach",              "Rostock",
    "Bergisch Gladbach",    "Göppingen",            "Lübeck",               "Rüsselsheim am Main",
    "Berlin",               "Görlitz",              "Lüdenscheid",          "Saarbrücken",
    "Bielefeld",            "Goslar",               "Ludwigsburg",          "Salzgitter",
    "Böblingen",            "Göttingen",            "Ludwigshafen am Rhein","Sankt Augustin",
    "Bocholt",              "Greifswald",           "Lüneburg",             "Schwäbisch Gmünd",
    "Bochum",               "Grevenbroich",         "Lünen",                "Schweinfurt",
    "Bonn",                 "Gronau (Westf.)",      "Magdeburg",            "Schwerin",
    "Bottrop",              "Gummersbach",          "Mainz",                "Siegen",
    "Brandenburg an der Havel","Gütersloh",         "Mannheim",             "Sindelfingen",
    "Braunschweig",         "Hagen",                "Marburg",              "Solingen",
    "Bremen",               "Halle (Saale)",        "Marl",                 "Speyer",
    "Bremerhaven",          "Hamburg",              "Meerbusch",            "Stolberg (Rheinland)",
    "Castrop-Rauxel",       "Hameln",               "Menden (Sauerland)",   "Stralsund",
    "Celle",                "Hamm",                 "Minden",               "Stuttgart",
    "Chemnitz",             "Hanau",                "Moers",                "Trier",
    "Cottbus",              "Hannover",             "Mönchengladbach",      "Troisdorf",
    "Darmstadt",            "Hattingen",            "Mülheim an der Ruhr",  "Tübingen",
    "Delmenhorst",          "Heidelberg",           "München",              "Ulm",
    "Dessau-Roßlau",        "Heidenheim an der Brenz","Münster",            "Unna",
    "Detmold",              "Heilbronn",            "Neu-Ulm",              "Velbert",
    "Dinslaken",            "Herford",              "Neubrandenburg",       "Viersen",
    "Dormagen",             "Herne",                "Neumünster",           "Villingen-Schwenningen",
    "Dorsten",              "Herten",               "Neuss",                "Waiblingen",
    "Dortmund",             "Hilden",               "Neustadt an der Weinstraße","Weimar",
    "Dresden",              "Hildesheim",           "Neuwied",              "Wesel",
    "Duisburg",             "Hürth",                "Norderstedt",          "Wetzlar",
    "Düren",                "Ibbenbüren",           "Nordhorn",             "Wiesbaden",
    "Düsseldorf",           "Ingolstadt",           "Nürnberg",             "Wilhelmshaven",
    "Elmshorn",             "Iserlohn",             "Oberhausen",           "Willich",
    "Emden",                "Jena",                 "Offenbach am Main",    "Witten",
    "Erftstadt",            "Kaiserslautern",       "Offenburg",            "Wolfenbüttel",
    "Erfurt",               "Karlsruhe",            "Oldenburg (Oldenburg)","Wolfsburg",
    "Erlangen",             "Kassel",               "Osnabrück",            "Worms",
    "Eschweiler",           "Kempten (Allgäu)",     "Paderborn",            "Wuppertal",
    "Essen",                "Kerpen",               "Passau",               "Würzburg",
    "Esslingen am Neckar",  "Kiel",                 "Peine",                "Zwickau",
    // clang-format on
});

const auto germanyStates = std::to_array<std::string_view>({
    // clang-format off
    "Baden-Württemberg",    "Bremen",               "Niedersachsen",                "Sachsen",
    "Bayern",               "Hamburg",              "Nordrhein-Westfalen",          "Sachsen-Anhalt",
    "Berlin",               "Hessen",               "Rheinland-Pfalz",              "Schleswig-Holstein",
    "Brandenburg",          "Mecklenburg-Vorpommern","Saarland",                    "Thüringen",
    // clang-format on
});

const auto germanyStreetNames = std::to_array<std::string_view>({
    // clang-format off
    "Ackerweg",             "Flurstr.",             "Kurt-Schumacher-Ring",         "Rennbaumplatz",
    "Adalbert-Stifter-Str.","Föhrenweg",            "Kyllstr.",                     "Rennbaumstr.",
    "Brandenburger Str.",   "Fontanestr.",          "Langenfelder Str.",            "Reuschenberger Str.",
    "Breidenbachstr.",      "Forellental",          "Längsleimbach",                "Röntgenstr.",
    "Breslauer Str.",       "Fortunastr.",          "Lärchenweg",                   "Roonstr.",
    "Bruchhauser Str.",     "Friedrich-Naumann-Str.","Legienstr.",                  "Ropenstall",
    "Brückenstr.",          "Friedrich-Sertürner-Str.","Lehner Mühle",              "Ropenstaller Weg",
    "Brucknerstr.",         "Friedrichstr.",        "Leichlinger Str.",             "Rosenthal",
    "Brüder-Bonhoeffer-Str.","Friedrich-Weskott-Str.","Mauspfad",                   "Rostocker Str.",
    "Buchenweg",            "Görlitzer Str.",       "Max-Beckmann-Str.",            "Rotdornweg",
    "Bürgerbuschweg",       "Görresstr.",           "Max-Delbrück-Str.",            "Röttgerweg",
    "Burgloch",             "Graebestr.",           "Max-Ernst-Str.",               "Rückertstr.",
    "Burgplatz",            "Graf-Galen-Platz",     "Max-Holthausen-Platz",         "Rudolf-Breitscheid-Str.",
    "Burgstr.",             "Gregor-Mendel-Str.",   "Max-Horkheimer-Str.",          "Rudolf-Mann-Platz",
    "Burgweg",              "Greifswalder Str.",    "Max-Liebermann-Str.",          "Rudolf-Stracke-Str.",
    "Bürriger Weg",         "Grillenweg",           "Max-Pechstein-Str.",           "Ruhlachplatz",
    "Burscheider Str.",     "Gronenborner Weg",     "Max-Planck-Str.",              "Steinweg",
    "Buschkämpchen",        "Große Kirchstr.",      "Max-Scheler-Str.",             "Stephan-Lochner-Str.",
    "Butterheider Str.",    "Grunder Wiesen",       "Max-Schönenberg-Str.",         "Stephanusstr.",
    "Carl-Duisberg-Platz",  "Grundermühle",         "Maybachstr.",                  "Stettiner Str.",
    "Carl-Duisberg-Str.",   "Grundermühlenhof",     "Meckhofer Feld",               "Stixchesstr.",
    "Carl-Leverkus-Str.",   "Grundermühlenweg",     "Meisenweg",                    "Stöckenstr.",
    "Carl-Maria-von-Weber-Platz","Grüner Weg",      "Memelstr.",                    "Stralsunder Str.",
    "Cranachstr.",          "Grunewaldstr.",        "Muldestr.",                    "Straßburger Str.",
    "Dahlemer Str.",        "Grünstr.",             "Mülhausener Str.",             "Stresemannplatz",
    "Daimlerstr.",          "Günther-Weisenborn-Str.","Mülheimer Str.",             "Uhlandstr.",
    "Damaschkestr.",        "Gustav-Freytag-Str.",  "Münsters Gäßchen",             "Ulmenweg",
    "Danziger Str.",        "Gustav-Heinemann-Str.","Münzstr.",                     "Ulmer Str.",
    "Debengasse",           "Gustav-Radbruch-Str.", "Müritzstr.",                   "Ulrichstr.",
    "Dechant-Fein-Str.",    "Gut Reuschenberg",     "Myliusstr.",                   "Ulrich-von-Hassell-Str.",
    "Dechant-Krey-Str.",    "Hannah-Höch-Str.",     "Nachtigallenweg",              "Umlag",
    "Deichtorstr.",         "Hans-Arp-Str.",        "Nauener Str.",                 "Unstrutstr.",
    "Dhünnberg",            "Heckenweg",            "Ober dem Hof",                 "Unter dem Schildchen",
    "Dhünnstr.",            "Heerweg",              "Obere Lindenstr.",             "Unterölbach",
    "Dianastr.",            "Hegelstr.",            "Obere Str.",                   "Unterstr.",
    "Diedenhofener Str.",   "Heidberg",             "Oberölbach",                   "Uppersberg",
    "Diepental",            "Heidehöhe",            "Odenthaler Str.",              "Van't-Hoff-Str.",
    "Diepenthaler Str.",    "Heidestr.",            "Oderstr.",                     "Veit-Stoß-Str.",
    "Dieselstr.",           "Heimstättenweg",       "Okerstr.",                     "Vereinsstr.",
    "Dillinger Str.",       "Jenaer Str.",          "Olof-Palme-Str.",              "Viktor-Meyer-Str.",
    "Distelkamp",           "Johannes-Baptist-Str.","Ophovener Str.",               "Vincent-van-Gogh-Str.",
    "Dohrgasse",            "Johannes-Dott-Str.",   "Opladener Platz",              "Virchowstr.",
    "Domblick",             "Johannes-Popitz-Str.", "Parkstr.",                     "Voigtslach",
    "Dönhoffstr.",          "Johannes-Wislicenus-Str.","Pastor-Louis-Str.",         "Weizkamp",
    "Dornierstr.",          "Johannisburger Str.",  "Pastor-Scheibler-Str.",        "Werftstr.",
    "Drachenfelsstr.",      "Johann-Janssen-Str.",  "Pastorskamp",                  "Werkstättenstr.",
    "Dr.-August-Blank-Str.","Johann-Wirtz-Weg",     "Paul-Klee-Str.",               "Werner-Heisenberg-Str.",
    "Dresdener Str.",       "Josefstr.",            "Paul-Löbe-Str.",               "Werrastr.",
    "Driescher Hecke",      "Jüch",                 "Paulstr.",                     "Weyerweg",
    "Emil-Fischer-Str.",    "Julius-Doms-Str.",     "Peenestr.",                    "Widdauener Str.",
    "Emil-Nolde-Str.",      "Julius-Leber-Str.",    "Pescher Busch",                "Wiebertshof",
    "Engelbertstr.",        "Kaiserplatz",          "Peschstr.",                    "Wiehbachtal",
    "Engstenberger Weg",    "Kaiserstr.",           "Pestalozzistr.",               "Wiembachallee",
    "Entenpfuhl",           "Kaiser-Wilhelm-Allee", "Peter-Grieß-Str.",             "Wiesdorfer Platz",
    "Erbelegasse",          "Kalkstr.",             "Peter-Joseph-Lenné-Str.",      "Wiesenstr.",
    "Erftstr.",             "Kämpchenstr.",         "Pregelstr.",                   "Wilhelm-Busch-Str.",
    "Erfurter Str.",        "Kämpenwiese",          "Prießnitzstr.",                "Zauberkuhle",
    "Fichtenweg",           "Kämper Weg",           "Pützdelle",                    "Zedernweg",
    "Fichtestr.",           "Kamptalweg",           "Quarzstr.",                    "Zehlendorfer Str.",
    "Finkelsteinstr.",      "Kanalstr.",            "Quettinger Str.",              "Zehntenweg",
    "Finkenweg",            "Kandinskystr.",        "Rat-Deycks-Str.",              "Zeisigweg",
    "Fixheider Str.",       "Kantstr.",             "Rathenaustr.",                 "Zeppelinstr.",
    "Flabbenhäuschen",      "Kocherstr.",           "Ratherkämp",                   "Zschopaustr.",
    "Flensburger Str.",     "Kockelsberg",          "Ratiborer Str.",               "Zum Claashäuschen",
    "Fliederweg",           "Kolberger Str.",       "Raushofstr.",                  "Zündhütchenweg",
    "Florastr.",            "Kolmarer Str.",        "Regensburger Str.",            "Zur Alten Brauerei",
    "Florianweg",           "Kölner Gasse",         "Reinickendorfer Str.",         "Zur alten Fabrik",
    "Flotowstr.",           "Kölner Str.",          "Renkgasse",
    // clang-format on
});

const std::string_view germanyZipCodeFormat{"#####"};

const auto germanyAddressFormats =
    std::to_array<std::string_view>({"{street} {buildingNumber}", "{street} {buildingNumber} {secondaryAddress}"});

const auto germanySecondaryAddressFormats = std::to_array<std::string_view>({"Apt. ###", "Zimmer ###", "# OG"});

const auto germanyBuildingNumberFormats = std::to_array<std::string_view>({"###", "##", "#", "##a", "##b", "##c"});

const auto germanyStreetFormats = std::to_array<std::string_view>({"{streetName}"});

const auto germanyCityFormats = std::to_array<std::string_view>({"{cityName}"});

const CountryAddressesInfo germanyAddresses{
    germanyZipCodeFormat,
    (germanyAddressFormats),
    (germanySecondaryAddressFormats),
    (germanyStreetFormats),
    {},
    (germanyStreetNames),
    {},
    (germanyBuildingNumberFormats),
    (germanyCityFormats),
    {},
    (germanyCities),
    {},
    (germanyStates),
};

// India

const auto indiaCities = std::to_array<std::string_view>({
    // clang-format off
    "Achalpur",             "Mahe",                 "Rudrapur",             "Sirkali",
    "Achhnera",             "Mahemdabad",           "Rupnagar",             "Sirohi",
    "Adalaj",               "Mahendragarh",         "Sabalgarh",            "Sironj",
    "Adilabad",             "Mahesana",             "Salaya",               "Sirsa",
    "Adityapur",            "Mahidpur",             "Salem",                "Sirsaganj",
    "Adoni",                "Mahnar Bazar",         "Salur",                "Sirsi",
    "Adoor",                "Mahuva",               "Samalkha",             "Siruguppa",
    "Adra",                 "Maihar",               "Samalkot",             "Sitamarhi",
    "Adyar",                "Narkhed",              "Samana",               "Sitapur",
    "Ankleshwar",           "Nokha",                "Samastipur",           "Sitarganj",
    "Arakkonam",            "Paradip",              "Sambalpur",            "Sivaganga",
    "Arambagh",             "Paramakudi",           "Sambhal",              "Sivagiri",
    "Araria",               "Parangipettai",        "Sambhar",              "Sivakasi",
    "Arrah",                "Parasi",               "Samdhan",              "Sundargarh",
    "Arsikere",             "Paravoor",             "Samthar",              "Sundarnagar",
    "Aruppukkottai",        "Parbhani",             "Sanand",               "Supaul",
    "Arvi",                 "Pardi",                "Sardhana",             "Surandai",
    "Arwal",                "Parlakhemundi",        "Sarni",                "Surapura",
    "Asansol",              "Parli",                "Sarsod",               "Surat",
    "Asarganj",             "Partur",               "Sasaram",              "Suratgarh",
    "Ashok Nagar",          "Parvathipuram",        "Sasvad",               "Tarana",
    "Athni",                "Pasan",                "Satana",               "Taranagar",
    "Dalli-Rajhara",        "Pauni",                "Satara",               "Taraori",
    "Darbhanga",            "Pauri",                "Sathyamangalam",       "Tarbha",
    "Darjiling",            "Pavagada",             "Satna",                "Tarikere",
    "Imphal",               "Pedana",               "Sattenapalle",         "Tarn Taran",
    "Indore",               "Peddapuram",           "Sattur",               "Tasgaon",
    "Itarsi",               "Pulgaon",              "Saunda",               "Tehri",
    "Jharsuguda",           "Puliyankudi",          "Saundatti-Yellamma",   "Tekkalakote",
    "Kodungallur",          "Punalur",              "Sausar",               "Tenali",
    "Kohima",               "Punch",                "Savanur",              "Tenkasi",
    "Kolar",                "Raghunathganj",        "Savarkundla",          "Tenu dam-cum-Kathhara",
    "Kolkata",              "Raghunathpur",         "Savner",               "Terdal",
    "Ladwa",                "Rahatgarh",            "Sawai Madhopur",       "Tezpur",
    "Lahar",                "Rahuri",               "Sawantwadi",           "Thakurdwara",
    "Laharpur",             "Raiganj",              "Sedam",                "Thammampatti",
    "Lakheri",              "Raigarh",              "Sherghati",            "Thana Bhawan",
    "Lakhimpur",            "Raikot",               "Sherkot",              "Thrissur",
    "Lakhisarai",           "Raipur",               "Shiggaon",             "Thuraiyur",
    "Lakshmeshwar",         "Rehli",                "Shikaripur",           "Tikamgarh",
    "Lal Gopalganj Nindaura","Renigunta",           "Shikarpur, Bulandshahr","Tilda Newra",
    "Lalganj",              "Renukoot",             "Shikohabad",           "Tilhar",
    "Lalgudi",              "Reoti",                "Shillong",             "Tindivanam",
    "Lalitpur",             "Repalle",              "Shimla",               "Tinsukia",
    "Lalsot",               "Revelganj",            "Shirdi",               "Tiptur",
    "Lanka",                "Rewa",                 "Shirpur-Warwade",      "Tirora",
    "Lar",                  "Rewari",               "Shirur",               "Tiruchendur",
    "Madikeri",             "Rishikesh",            "Shishgarh",            "Tiruchengode",
    "Madurai",              "Risod",                "Sindagi",              "Tiruchirappalli",
    "Magadi",               "Robertsganj",          "Sindhagi",             "Warisaliganj",
    "Mahad",                "Robertson Pet",        "Sindhnur",             "Warora",
    "Mahalingapura",        "Rohtak",               "Singrauli",            "Warud",
    "Maharajganj",          "Ron",                  "Sinnar",               "Zunheboto",
    "Maharajpur",           "Roorkee",              "Sira",
    "Mahasamund",           "Rosera",               "Sircilla",
    "Mahbubnagar",          "Rudauli",              "Sirhind Fatehgarh Sahib",
    // clang-format on
});

const auto indiaStates = std::to_array<std::string_view>({
    // clang-format off
    "Andaman and Nicobar Islands","Delhi",          "Lakshadweep",          "Punjab",
    "Andra Pradesh",        "Goa",                  "Madya Pradesh",        "Rajasthan",
    "Arunachal Pradesh",    "Gujarat",              "Maharashtra",          "Sikkim",
    "Assam",                "Haryana",              "Manipur",              "Tamil Nadu",
    "Bihar",                "Himachal Pradesh",     "Meghalaya",            "Telangana",
    "Chandigarh",           "Jammu and Kashmir",    "Mizoram",              "Tripura",
    "Chhattisgarh",         "Jharkhand",            "Nagaland",             "Uttar Pradesh",
    "Dadar and Nagar Haveli","Karnataka",           "Odisha",               "Uttarakhand",
    "Daman and Diu",        "Kerala",               "Pondicherr",           "West Bengal",
    // clang-format on
});

const auto indiaStreetSuffixes = std::to_array<std::string_view>({
    "Pur",    "Puri",     "Halli",  "Wadi",    "Nagar",  "Abad",   "Palle",  "Pura",   "Patti",
    "Uru",    "Oor",      "Gaon",   "Puram",   "Ong",    "Street", "Park",   "Radial", "Junction",
    "Cove",   "Hollow",   "Rapids", "Cheri",   "Road",   "Padra",  "Nagara", "Athani", "Ridges",
    "Skyway", "Crossing", "Plains", "Parkway", "Points", "Falls",  "Brooks", "Theru",
});

const std::string_view indiaZipCodeFormat{"######"};

const auto indiaAddressFormats = std::to_array<std::string_view>({"{buildingNumber} {street}"});

const auto indiaSecondaryAddressFormats = std::to_array<std::string_view>({"Apt. ###", "Flat ###"});

const auto indiaBuildingNumberFormats = std::to_array<std::string_view>({"#####", "####", "###"});

const auto indiaStreetFormats =
    std::to_array<std::string_view>({"{firstName} {streetSuffix}", "{lastName} {streetSuffix}"});

const auto indiaCityFormats = std::to_array<std::string_view>({"{cityName}"});

const CountryAddressesInfo indiaAddresses{
    indiaZipCodeFormat,
    (indiaAddressFormats),
    (indiaSecondaryAddressFormats),
    (indiaStreetFormats),
    {},
    {},
    (indiaStreetSuffixes),
    (indiaBuildingNumberFormats),
    (indiaCityFormats),
    {},
    (indiaCities),
    {},
    (indiaStates),
};

// Italy

const auto italyCities = std::to_array<std::string_view>({
    // clang-format off
    "Agliè",          "Andezeno",      "Barbania",     "Brosso",        "Buriasco",      "Caluso",      "Cantoira",
    "Carmagnola",     "Cavour",        "Chiaverano",   "Ciconio",       "Coazze",        "Cumiana",     "Feletto",
    "Front",          "Giaveno",       "Grugliasco",   "Lauriano",      "Locana",        "Lusigliè",    "Mathi",
    "Mompantero",     "Nichelino",     "Novalesa",     "Oulx",          "Perrero",       "Pinerolo",    "Pomaretto",
    "Pramollo",       "Quassolo",      "Rivara",       "Rondissone",    "Rueglio",       "Santena",     "Sparone",
    "Usseaux",        "Varisella",     "Vidracco",     "Vinovo",        "Volvera",       "Balocco",     "Campertogno",
    "Cervatto",       "Cravagliana",   "Formigliana",  "Lamporo",       "Moncrivello",   "Pila",        "Rassa",
    "Rossa",          "Scopa",         "Valduggia",    "Vocca",         "Biandrate",     "Briona",      "Comignago",
    "Galliate",       "Invorio",       "Mezzomerico",  "Pisano",        "Sillavengo",    "Terdobbiate", "Vinzaglio",
    "Alto",           "Barge",         "Benevello",    "Bosia",         "Brondello",     "Canosio",     "Cartignano",
    "Castino",        "Cervere",       "Clavesana",    "Demonte",       "Envie",         "Frassino",    "Gorzegno",
    "Isasca",         "Macra",         "Marmora",      "Montanera",     "Murello",       "Nucetto",     "Pagno",
    "Peveragno",      "Pocapaglia",    "Revello",      "Robilante",     "Roddi",         "Saliceto",    "Sanfrè",
    "Sinio",          "Treiso",        "Venasca",      "Vignolo",       "Albugnano",     "Bruno",       "Canelli",
    "Castell'Alfero", "Coazzolo",      "Cortazzone",   "Fontanile",     "Maretto",       "Monale",      "Quaranti",
    "Scurzolengo",    "Tigliole",      "Viale",        "Balzola",       "Bosio",         "Carezzano",   "Casasco",
    "Cereseto",       "Dernice",       "Frugarolo",    "Giarole",       "Lerma",         "Molare",      "Montaldeo",
    "Mornese",        "Ottiglio",      "Pasturana",    "Prasco",        "Rivarone",      "Solero",      "Terruggia",
    "Trisobbio",      "Villalvernia",  "Bioglio",      "Camburzano",    "Cerrione",      "Donato",      "Magnano",
    "Mottalciata",    "Piedicavallo",  "Pray",         "Tollegno",      "Verrone",       "Lessona",     "Baceno",
    "Bognanco",       "Caprezzo",      "Crodo",        "Ghiffa",        "Macugnaga",     "Miazzina",    "Omegna",
    "Premia",         "Trasquera",     "Allein",       "Avise",         "Brissogne",     "Chamois",     "Cogne",
    "Etroubles",      "Gressan",       "Issime",       "Morgex",        "Barni",         "Bregnano",    "Cabiate",
    "Carbonate",      "Cavargna",      "Dizzasco",     "Faloppio",      "Guanzate",      "Lasnigo",     "Luisago",
    "Moltrasio",      "Musso",         "Pigra",        "Pusiano",       "Nosate",        "Pantigliate", "Rescaldina",
    "Sedriano",       "Tribiano",      "Vignate",      "Albino",        "Ardesio",       "Barbata",     "Bossico",
    "Brumano",        "Capizzone",     "Cerete",       "Colzate",       "Cusio",         "Fontanella",  "Gandosso",
    "Gorno",          "Lallio",        "Martinengo",   "Mozzo",         "Pagazzano",     "Parzanica",   "Piazzatorre",
    "Pradalunga",     "Ranica",        "Rovetta",      "Selvino",       "Sovere",        "Taleggio",    "Valbondione",
    "Valtorta",       "Viadanica",     "Zogno",        "Acquafredda",   "Artogne",       "Berlingo",    "Botticino",
    "Breno",          "Calvisano",     "Castelcovati", "Cellatica",     "Cigole",        "Cologne",     "Edolo",
    "Gambara",        "Gottolengo",    "Iseo",         "Lograto",       "Maclodio",      "Manerbio",    "Milzano",
    "Muscoline",      "Odolo",         "Ospitaletto",  "Passirano",     "Retorbido",     "Rosasco",     "Sommo",
    "Vidigulfo",      "Zerbo",         "Azzanello",    "Capergnanica",  "Castelleone",   "Crema",       "Fiesco",
    "Grontardo",      "Montodine",     "Pandino",      "Ricengo",       "Soresina",      "Tornata",     "Voltido",
    "Casalromano",    "Commessaggio",  "Gonzaga",      "Marmirolo",     "Ostiglia",      "Quistello",   "Sabbioneta",
    "Viadana",        "Barzago",       "Bulciago",     "Casatenovo",    "Cremeno",       "Erve",        "Merate",
    "Morterone",      "Pagnona",       "Premana",      "Sirtori",       "Valmadrera",    "Codogno",     "Galgagnano",
    "Maccastorna",    "Meleti",        "Sordio",       "Barlassina",    "Briosco",       "Concorezzo",  "Lesmo",
    "Stelvio",        "Tirolo",        "Vandoies",     "Vipiteno",      "Andalo",        "Bieno",       "Caldes",
    "Capriana",       "Cavareno",      "Cis",          "Dambel",        "Fierozzo",      "Giustino",    "Lavis",
    "Massimeno",      "Mezzolombardo", "Nogaredo",     "Pinzolo",       "Altissimo",     "Breganze",    "Caltrano",
    "Castegnero",     "Creazzo",       "Gallio",       "Longare",       "Montegaldella", "Orgiano",     "Roana",
    "Santorso",       "Solagna",       "Trissino",     "Villaverla",    "Valbrenta",     "Gosaldo",     "Sospirolo",
    "Casier",         "Codognè",       "Fontanelle",   "Loria",         "Montebelluna",  "Paese",       "Preganziol",
    "Sarmede",        "Vedelago",      "Cavarzere",    "Eraclea",       "Martellago",    "Pianiga",     "Spinea",
    "Comeglians",     "Enemonzo",      "Grimacco",     "Mortegliano",   "Pagnacco",      "Pontebba",    "Premariacco",
    "Ravascletto",    "Rigolato",      "Sedegliano",   "Talmassons",    "Torreano",      "Varmo",       "Sappada",
    "Monfalcone",     "Turriaco",      "Brugnera",     "Claut",         "Fontanafredda", "Porcia",      "Spilimbergo",
    "Airole",         "Bajardo",       "Castellaro",   "Chiusavecchia", "Dolcedo",       "Ospedaletti", "Pontedassio",
    "Sanremo",        "Triora",        "Vessalico",    "Arnasco",       "Bormida",       "Ceriale",     "Giustenice",
    "Mallare",        "Nasino",        "Pallare",      "Roccavignale",  "Stellanello",   "Vendone",     "Bogliasco",
    "Palanzano",      "Terenzo",       "Varsi",        "Brescello",     "Castellarano",  "Gattatico",   "Poviglio",
    "Toano",          "Bomporto",      "Fanano",       "Maranello",     "Montefiorino",  "Polinago",    "Sestola",
    "Argelato",       "Camugnano",     "Fontanelice",  "Marzabotto",    "Valsamoggia",   "Comacchio",   "Tresignana",
    "Conselice",      "Cesena",        "Modigliana",   "Sarsina",       "Gemmano",       "Saludecio",   "Pennabilli",
    "Comano",         "Montignoso",    "Zeri",         "Capannori",     "Massarosa",     "Pietrasanta", "Agliana",
    "Montale",        "Uzzano",        "Empoli",       "Impruneta",     "Pelago",        "Signa",       "Capoliveri",
    "Piombino",       "Bientina",      "Cascina",      "Montescudaio",  "Ponsacco",      "Vicopisano",  "Bucine",
    "Lucignano",      "Monteriggioni", "Poggibonsi",   "Sinalunga",     "Campagnatico",  "Gavorrano",   "Pitigliano",
    "Montemurlo",     "Bettona",       "Collazzone",   "Gubbio",        "Norcia",
    // clang-format on
});

const auto italyStates = std::to_array<std::string_view>({
    // clang-format off
    "Agrigento",            "Cremona",              "Milano",               "Rovigo",
    "Alessandria",          "Crotone",              "Modena",               "Salerno",
    "Ancona",               "Cuneo",                "Monza e della Brianza","Medio Campidano",
    "Aosta",                "Enna",                 "Napoli",               "Sassari",
    "Arezzo",               "Fermo",                "Novara",               "Savona",
    "Ascoli Piceno",        "Ferrara",              "Nuoro",                "Siena",
    "Asti",                 "Firenze",              "Olbia-Tempio",         "Siracusa",
    "Avellino",             "Foggia",               "Oristano",             "Sondrio",
    "Bari",                 "Forlì-Cesena",         "Padova",               "Taranto",
    "Barletta-Andria-Trani","Frosinone",            "Palermo",              "Teramo",
    "Belluno",              "Genova",               "Parma",                "Terni",
    "Benevento",            "Gorizia",              "Pavia",                "Torino",
    "Bergamo",              "Grosseto",             "Perugia",              "Ogliastra",
    "Biella",               "Imperia",              "Pesaro e Urbino",      "Trapani",
    "Bologna",              "Isernia",              "Pescara",              "Trento",
    "Bolzano",              "La Spezia",            "Piacenza",             "Treviso",
    "Brescia",              "L \'Aquila",           "Pisa",                 "Trieste",
    "Brindisi",             "Latina",               "Pistoia",              "Udine",
    "Cagliari",             "Lecce",                "Pordenone",            "Varese",
    "Caltanissetta",        "Lecco",                "Potenza",              "Venezia",
    "Campobasso",           "Livorno",              "Prato",                "Verbano-Cusio-Ossola",
    "Carbonia-Iglesias",    "Lodi",                 "Ragusa",               "Vercelli",
    "Caserta",              "Lucca",                "Ravenna",              "Verona",
    "Catania",              "Macerata",             "Reggio Calabria",      "Vibo Valentia",
    "Catanzaro",            "Mantova",              "Reggio Emilia",        "Vicenza",
    "Chieti",               "Massa-Carrara",        "Rieti",                "Viterbo",
    "Como",                 "Matera",               "Rimini",
    "Cosenza",              "Messina",              "Roma",
    // clang-format on
});

const auto italyStreetPrefixes = std::to_array<std::string_view>({
    "Piazza",
    "Strada",
    "Via",
    "Borgo",
    "Contrada",
    "Rotonda",
    "Incrocio",
});

const std::string_view italyZipCodeFormat{"#####"};

const auto italyAddressFormats =
    std::to_array<std::string_view>({"{street} {buildingNumber}", "{street} {buildingNumber} {secondaryAddress}"});

const auto italySecondaryAddressFormats = std::to_array<std::string_view>({"Appartamento ##", "Piano #"});

const auto italyBuildingNumberFormats = std::to_array<std::string_view>({"###", "##", "#"});

const auto italyStreetFormats =
    std::to_array<std::string_view>({"{streetPrefix} {firstName}", "{streetPrefix} {lastName}"});

const auto italyCityFormats = std::to_array<std::string_view>({"{cityName}"});

const CountryAddressesInfo italyAddresses{
    italyZipCodeFormat,
    (italyAddressFormats),
    (italySecondaryAddressFormats),
    (italyStreetFormats),
    (italyStreetPrefixes),
    {},
    {},
    (italyBuildingNumberFormats),
    (italyCityFormats),
    {},
    (italyCities),
    {},
    (italyStates),
};

// Poland

const auto polandCities = std::to_array<std::string_view>({
    // clang-format off
    "Aleksandrów Kujawski", "Dobczyce",             "Legionowo",            "Radlin",
    "Bierutów",             "Działoszyce",          "Legnica",              "Radłów",
    "Bieżuń",               "Działoszyn",           "Lubaczów",             "Rydzyna",
    "Biłgoraj",             "Dzierzgoń",            "Lubań",                "Ryglice",
    "Biskupiec",            "Dzierżoniów",          "Łomża",                "Ryki",
    "Bisztynek",            "Dziwnów",              "Łopuszno",             "Rymanów",
    "Blachownia",           "Elbląg",               "Łosice",               "Ryn",
    "Błaszki",              "Ełk",                  "Łowicz",               "Starachowice",
    "Błażowa",              "Frampol",              "Łódź",                 "Stargard",
    "Błonie",               "Frombork",             "Łuków",                "Starogard Gdański",
    "Bobolice",             "Garwolin",             "Maków Mazowiecki",     "Stary Sącz",
    "Bobowa",               "Gąbin",                "Maków Podhalański",    "Szamocin",
    "Bochnia",              "Gdańsk",               "Malbork",              "Szamotuły",
    "Bodzanów",             "Gdynia",               "Mikołajki",            "Szczecin",
    "Bodzentyn",            "Giżycko",              "Mikołów",              "Szczecinek",
    "Bogatynia",            "Glinojeck",            "Mikstat",              "Świeradów-Zdrój",
    "Boguchwała",           "Gliwice",              "Milanówek",            "Świerzawa",
    "Boguszów-Gorce",       "Głogów",               "Milicz",               "Świętochłowice",
    "Bojanowo",             "Głogów Małopolski",    "Miłakowo",             "Świnoujście",
    "Bolesławiec",          "Głogówek",             "Miłomłyn",             "Tarczyn",
    "Bolimów",              "Głowno",               "Olsztyn",              "Tarnobrzeg",
    "Bychawa",              "Głubczyce",            "Oświęcim",             "Tarnogród",
    "Byczyna",              "Głuchołazy",           "Otmuchów",             "Tarnowskie Góry",
    "Bydgoszcz",            "Głuszyca",             "Piła",                 "Tychowo",
    "Bystrzyca Kłodzka",    "Gniew",                "Piława Górna",         "Tychy",
    "Bytom",                "Gniewkowo",            "Pińczów",              "Ustrzyki Dolne",
    "Bytom Odrzański",      "Gniezno",              "Pionki",               "Wadowice",
    "Bytów",                "Gorzów Wielkopolski",  "Piotrków Kujawski",    "Wałbrzych",
    "Cedynia",              "Gostynin",             "Pleszew",              "Wałcz",
    "Cegłów",               "Gostyń",               "Płock",                "Warka",
    "Chełm",                "Gościno",              "Płońsk",               "Warszawa",
    "Choroszcz",            "Jastrzębie-Zdrój",     "Płoty",                "Warta",
    "Chorzele",             "Jabłonowo Pomorskie",  "Pniewy",               "Wiskitki",
    "Chorzów",              "Janikowo",             "Prabuty",              "Wisła",
    "Choszczno",            "Janowiec Wielkopolski","Praszka",              "Wiślica",
    "Chrzanów",             "Jelenia Góra",         "Prochowice",           "Witkowo",
    "Ciechanowiec",         "Jeziorany",            "Proszowice",           "Witnica",
    "Ciechanów",            "Jeżów",                "Prószków",             "Wleń",
    "Ciechocinek",          "Jędrzejów",            "Pruchnik",             "Włocławek",
    "Cieszanów",            "Jordanów",             "Prudnik",              "Wrocław",
    "Cieszyn",              "Józefów",              "Prusice",              "Wronki",
    "Dąbrowa Górnicza",     "Karpacz",              "Pruszcz",              "Września",
    "Dąbrowa Tarnowska",    "Kielce",               "Pruszcz Gdański",      "Zalewo",
    "Dąbrowice",            "Kietrz",               "Pruszków",             "Zambrów",
    "Debrzno",              "Kisielice",            "Przasnysz",            "Zamość",
    "Dębica",               "Kraków",               "Raciąż",               "Zator",
    "Dęblin",               "Latowicz",             "Racibórz",             "Żywiec",
    "Dębno",                "Lądek-Zdrój",          "Radków",
    // clang-format on
});

const auto polandStates = std::to_array<std::string_view>({
    "dolnośląskie",
    "kujawsko-pomorskie",
    "lubelskie",
    "lubuskie",
    "łódzkie",
    "małopolskie",
    "mazowieckie",
    "opolskie",
    "podkarpackie",
    "podlaskie",
    "pomorskie",
    "śląskie",
    "świętokrzyskie",
    "warmińsko-mazurskie",
    "wielkopolskie",
    "zachodniopomorskie",
});

const auto polandStreetNames = std::to_array<std::string_view>({
    // clang-format off
    "Piękna",               "Ciepła",               "Marcina Bielskiego",   "Tynkarska",
    "Babiego Lata",         "Brylowska",            "Aleja Narcyzy Żmichowskiej","Potrzebna",
    "Topolowa",             "Strąkowa",             "Ożarowska",            "Zbocze",
    "Tęczowa",              "Elektoralna",          "Wawrzyszewska",        "Batalionu AK \"Włochy\"",
    "Teodozji",             "Esperanto",            "Stanisława Staszica",  "Pryzmaty",
    "Szeroka",              "Falkowska",            "Sienna",               "Radarowa",
    "Gabriela Narutowicza", "Franciszka Raszei",    "Rodziny Kluczyńskich", "Zodiakalna",
    "Lipowa",               "Pawia",                "Stanisława Smolki",    "Witki",
    "Łąkowa",               "Giełdowa",             "Tunelowa",             "Astronautów",
    "Magnolii",             "Icchoka Lejba Pereca", "Pustola",              "Badylarska",
    "Malachitowa",          "Słodowiecka",          "Antka Rozpylacza",     "Bakalarska",
    "Marii Rodziewiczówny", "Sebastiana Klonowicza","Wandy Lurie",          "Bolesława Chrobrego",
    "Mikołaja Kopernika",   "Redutowa",             "Wolska",               "Chylońska",
    "Orzechowa",            "Przy Lasku",           "św. Stanisława",       "Fasolowa",
    "Klonowa",              "Szańcowa",             "Klecka",               "Globusowa",
    "Astrów",               "Górczewska",           "Srebrna",              "Popularna",
    "Morelowa",             "Żytnia",               "kard. Stefana Wyszyńskiego","Analityczna",
    "Malwy",                "Znana",                "Jana Kazimierza",      "Działkowa",
    "Malinowa",             "Radzanowska",          "Józefa Bellottiego",   "Komitetu Obrony Robotników",
    "Zakątek",              "Aleja Prymasa Tysiąclecia","Batalionu AK \"Parasol\"","Wirażowa",
    "Przyleśna",            "Prosta",               "Bitwy pod Lenino",     "Solipska",
    "Polna",                "Potrzebna",            "Romańska",             "Perlonowa",
    "Zadanie 12",           "Smocza",               "Bolecha",              "Saperów",
    "Powstańców Warszawy",  "Andrychowska",         "Grodziska",            "Rękodzielnicza",
    "Równa",                "Studzienna",           "Wincentego Pola",      "1 Sierpnia",
    "Sekwoi",               "Emanuela Ringelbluma", "Olgi Boznańskiej",     "Flagowa",
    "Zadrzewiona",          "Astronomów",           "Wieluńska",            "Kotwiczna",
    "Zadanie 02",           "Agawy",                "Tadeusza Krępowieckiego","Cienista",
    "Zadanie 04",           "Złota",                "Białowiejska",         "Naukowa",
    "Wydmowa",              "Syreny",               "Leonarda",             "Krótka",
    "Wschodnia",            "Sybiraków",            "Leszno",               "Łuczek",
    "Słoneczna",            "Stawki","gen. Jana Jura-Gorzechowskiego",      "Nadziei",
    "Jaśminowa",            "Przyce",               "Obozowa",              "Karatowa",
    "Perłowa",              "Przasnyska",           "Newelska",             "Hejnałowa",
    "Mazowiecka",           "Piaskowa",             "Miła",                 "Jagny",
    "Marii Skłodowskiej-Curie","Pamięci",           "Koszycka",             "Aksamitna",
    "Marii Konopnickiej",   "Deotymy",              "Juliusza Konstantego Ordona","Przesmyk",
    "Kubusia Puchatka",     "Szarych Szeregów",     "Szulborska",           "Obrońców Pokoju",
    "Koralowa",             "św. Wojciecha",        "Józefa Sowińskiego",   "Zdobnicza",
    "Juliusza Słowackiego", "Towarowa",             "Janusza Korczaka",     "Narożna",
    "Jeździecka",           "Dzika",                "Okopowa",              "Ogrodników",
    "Wąska",                "Edwarda Gibalskiego","Eustachego Tyszkiewicza","Franciszka Żwirki i Stanisława Wigury",
    "Zadanie 06",           "Goleszowska",          "Nakielska",            "Boryny",
    "Zadanie 13",           "Działdowska",          "Henryka Barona",       "Plastyczna",
    "Zapiecek",             "Dalibora",             "Hipolita Wawelberga",  "Nastrojowa",
    "Zaułek",               "Bodzanty",             "Hubalczyków",          "Jutrzenki",
    "Platanów",             "Budziszyńska",         "Jana Brożka",          "Hipotezy",
    "Dzielna",              "Burakowska",           "Opolski",              "Daleszycka",
    "Wspólna",              "Czelińska",            "Złocienia",            "Konewki",
    "Wilanowska",           "Erika Dahlbergha",     "Aleja Jana Pawła II",  "Czempińska",
    "Jana Pawła II",        "Grabowska",            "Ogrodowa",             "Tapicerska",
    "Zachodu Słońca",       "Fort Wola",            "Czorsztyńska",         "Tomnicka",
    "Dzika",                "Włodzimierza Majakowskiego","Emanuela Szafarczyka","Świetlista",
    "Juliana Ursyna Niemcewicza","Waliców",         "Pańska",               "Trojańska",
    "Rolna",                "Ulrychowska",          "Człuchowska",          "Wagonowa",
    "Aleja marsz. Józefa Piłsudskiego","Dywizjonu 303","Cypriana Kamila Norwida","Szybowcowa",
    "Różana",               "Kolejowa",             "Chmielna",             "Solińska",
    "Słonecznej Polany",    "Jana Krysta",          "Chłodna",              "Trzos",
    "Anny Walentynowicz",   "Olgi Johann",          "Dzielna",              "Skromna",
    "Ponczowa",             "Krochmalna",           "Bronisława Dobrzańskiego","Rejonowa",
    "Piechoty Łanowej",     "Ludwiki",              "Baltazara",            "Poziomkowa",
    "Karuzela",             "Łacińska",             "Góralska",             "Cegielniana",
    "Husarii",              "Łucka",                "Gniewkowska",          "Cyprysowa",
    "Kwitnącej Łąki",       "Marynin",              "Gizów",                "Czardasza",
    "Prymasa Augusta Hlonda","Wschowska",           "Józefa Bema",          "Głuszycka",
    "Kosiarzy",             "Jana Długosza",        "Edwarda Szymańskiego", "Podborska",
    "Zastruże",             "Organizacji Narodów Zjednoczonych","Armatnia", "Prudnicka",
    "Resorowa",             "Długomiła",            "Elekcyjna",            "Rebusowa",
    "Przekorna",            "Banderii",             "Emila Zegadłowicza",   "Wałowicka",
    "św. Urszuli Ledóchowskiej","Biała",            "Erazma Ciołka",        "Węgorzewska",
    "Zygmunta Vogla",       "Elbląska",             "Platynowa",            "Aleja Dwudziestolatków",
    "Winogronowa",          "Niska",                "Powązkowska",          "Żaluzji",
    "Rumiana",              "Jaktorowska",          "Przyokopowa",          "Znicz",
    "Wyprawa",              "Zwrotnicza",           "Rabsztyńska",          "Janiszowska",
    "Andrutowa",            "Grzybowska",           "Rodziny Lilpopów",     "Pawła Lipowczana",
    "Morysin",              "Jana Olbrachta",       "Rogalińska",           "Jakobinów",
    "Kazachska",            "Grenady",              "Siedmiogrodzka",       "Kazimierza Wielkiego",
    "Lawendy",              "Kozielska",            "Sieradzka",            "Kolneńska",
    "Łukasza Drewny",       "Nowolipki",            "Śliska",               "Krzysztofa Kolumba",
    "Poranek",              "Kolska",               "Tatarska",             "Wykusz",
    "Metryczna",            "Karolkowa",            "Traktorzystki",        "Budki Szczęśliwickie",
    "Wycieczka",            "Kacpra Karlińskiego",  "Twarda",               "Latarnika",
    "Orszady",              "Kaprys",               "Zdzisława Lubomirskiego","Denarowa",
    "Europejska",           "Sławińska",            "Gostyńska",            "Żegoty",
    "Dostatnia",            "Okocimska",            "Alojzego Pawełka",     "Żniwna",
    "Sarmacka",             "Nowolipie",            "Mordechaja Anielewicza","Instalatorów",
    "Gronowa",              "Mroczna",              "Spokojna",             "Świerszcza",
    "Zdrowa",               "Monte Cassino",        "Stanisława Worcella",  "Śląska",
    "Koralowa",             "Młocińska",            "Zawiszy",              "Sulmierzycka",
    "Adama Branickiego",    "Marcina Kasprzaka",    "Ignacego Daszyńskiego","Stawy",
    "Uprawna",              "Lasek na Kole",        "Kercelak",             "Stajenna",
    "Hektarowa",            "Mikołaja Wierzynka",   "Laskowa",              "Bratnia",
    "Aleksandra Gieysztora","Młynarska",            "Tylna",                "Wszemirowska",
    "Aleja Wilanowska",     "Zdzisława Kuźmirskiego-Pacaka","Lędzka",       "Wolności",
    "Zaściankowa",          "Kotlarska",            "Miedziana",            "Szczęsna",
    "Nowoursynowska",       "Kajetana Sołtyka",     "Moczydło",             "Światowa",
    "Bruzdowa",             "Mieczysława Dawida Apfelbauma","Sokołowska",   "Drukarzy",
    "Biedronki",            "Połczyńska",           "Mszczonowska",         "Dukatowa",
    "Calowa",               "Magistracka",          "Seweryna Krzyżanowskiego","Sycowska",
    "Obornicka",            "Księcia Janusza",      "Skierniewicka",        "Akurat",
    "Przedatki",            "Kajetana Garbińskiego","Stroma",               "Gęślarska",
    "Okrzeszyńska",         "Kacza",                "Redaktorska",          "Finałowa",
    "Rosochata",            "Dobrogniewa",          "Przednia",             "Centralna",
    "Królewicza Aleksandra","Płocka",               "Popas",                "Barometryczna",
    "Hoserów",              "Żelazna",              "Załuski",              "Emaliowa",
    "Boguszewska",          "Władysława Przanowskiego","Wyrzyska",
    "Aleje Jerozolimskie",  "Szlenkierów",          "Przepiórki",
    "Radziwie",             "Księdza Jerzego",      "Stoicka",
    // clang-format on
});

const auto polandStreetPrefixes =
    std::to_array<std::string_view>({"ulica", "aleja", "osiedle", "plac", "park", "skwer"});

const std::string_view polandZipCodeFormat{"##-###"};

const auto polandAddressFormats =
    std::to_array<std::string_view>({"{street} {buildingNumber}", "{street} {buildingNumber} {secondaryAddress}",
                                     "{street} {buildingNumber}/{buildingNumber}"});

const auto polandSecondaryAddressFormats = std::to_array<std::string_view>({"m. ###", "m. ##", "m. #"});

const auto polandBuildingNumberFormats = std::to_array<std::string_view>({"#", "##", "###"});

const auto polandStreetFormats = std::to_array<std::string_view>({"{streetPrefix} {streetName}"});

const auto polandCityFormats = std::to_array<std::string_view>({"{cityName}"});

const CountryAddressesInfo polandAddresses{
    polandZipCodeFormat,
    (polandAddressFormats),
    (polandSecondaryAddressFormats),
    (polandStreetFormats),
    (polandStreetPrefixes),
    (polandStreetNames),
    {},
    (polandBuildingNumberFormats),
    (polandCityFormats),
    {},
    (polandCities),
    {},
    (polandStates),
};

// Russia

const auto russiaCities = std::to_array<std::string_view>({
    // clang-format off
    "Абакан",               "Майкоп",               "Павловский",           "Таганрог",
    "Азов",                 "Махачкала",            "Пенза",                "Тамбов",
    "Калининград",          "Междуреченск",         "Первоуральск",         "Тверь",
    "Калуга",               "Мелеуз",               "Пермь",                "Тимашевск",
    "Каменск-Уральский",    "Миасс",                "Петрозаводск",         "Тихвин",
    "Каменск-Шахтинский",   "Минеральные",          "Петропавловск-Камчатский","Тихорецк",
    "Камышин",              "Минусинск",            "Подольск",             "Тобольск",
    "Канск",                "Михайловка",           "Полевской",            "Тольятти",
    "Каспийск",             "Михайловск",           "Прокопьевск",          "Томск",
    "Кемерово",             "Мичуринск",            "Прохладный",           "Троицк",
    "Керчь",                "Москва",               "Псков",                "Туапсе",
    "Кинешма",              "Мурманск",             "Пушкино",              "Туймазы",
    "Кириши",               "Муром",                "Пятигорск",            "Тула",
    "Киров",                "Мытищи",               "Раменское",            "Тюмень",
    "Кирово-Чепецк",        "Набережные",           "Ревда",                "Узловая",
    "Киселевск",            "Назарово",             "Реутов",               "Улан-Удэ",
    "Кисловодск",           "Назрань",              "Ржев",                 "Ульяновск",
    "Клин",                 "Нальчик",              "Рославль",             "Урус-Мартан",
    "Клинцы",               "Наро-Фоминск",         "Россошь",              "Усолье-Сибирское",
    "Ковров",               "Находка",              "Ростов-на-Дону",       "Уссурийск",
    "Когалым",              "Невинномысск",         "Рубцовск",             "Усть-Илимск",
    "Коломна",              "Нерюнгри",             "Рыбинск",              "Уфа",
    "Комсомольск-на-Амуре", "Нефтекамск",           "Рязань",               "Ухта",
    "Копейск",              "Нефтеюганск",          "Салават",              "Феодосия",
    "Королев",              "Нижневартовск",        "Сальск",               "Фрязино",
    "Кострома",             "Нижнекамск",           "Самара",               "Хабаровск",
    "Котлас",               "Нижний",               "Санкт-Петербург",      "Ханты-Мансийск",
    "Красногорск",          "Нижний",               "Саранск",              "Хасавюрт",
    "Краснодар",            "Новоалтайск",          "Сарапул",              "Химки",
    "Краснокаменск",        "Новокузнецк",          "Саратов",              "Чайковский",
    "Краснокамск",          "Новокуйбышевск",       "Саров",                "Чапаевск",
    "Краснотурьинск",       "Новомосковск",         "Свободный",            "Чебоксары",
    "Красноярск",           "Новороссийск",         "Севастополь",          "Челябинск",
    "Кропоткин",            "Новосибирск",          "Северодвинск",         "Черемхово",
    "Крымск",               "Новотроицк",           "Северск",              "Череповец",
    "Кстово",               "Новоуральск",          "Сергиев",              "Черкесск",
    "Кузнецк",              "Новочебоксарск",       "Серов",                "Черногорск",
    "Кумертау",             "Новочеркасск",         "Серпухов",             "Чехов",
    "Кунгур",               "Новошахтинск",         "Сертолово",            "Чистополь",
    "Курган",               "Новый",                "Сибай",                "Чита",
    "Курск",                "Ногинск",              "Симферополь",          "Шадринск",
    "Кызыл",                "Норильск",             "Славянск-на-Кубани",   "Шали",
    "Лабинск",              "Ноябрьск",             "Смоленск",             "Шахты",
    "Лениногорск",          "Нягань",               "Соликамск",            "Шуя",
    "Ленинск-Кузнецкий",    "Обнинск",              "Солнечногорск",        "Щекино",
    "Лесосибирск",          "Одинцово",             "Сосновый",             "Щелково",
    "Липецк",               "Озерск",               "Сочи",                 "Электросталь",
    "Лиски",                "Октябрьский",          "Ставрополь",           "Элиста",
    "Лобня",                "Омск",                 "Старый",               "Энгельс",
    "Лысьва",               "Орел",                 "Стерлитамак",          "Южно-Сахалинск",
    "Лыткарино",            "Оренбург",             "Ступино",              "Юрга",
    "Люберцы",              "Орехово-Зуево",        "Сургут",               "Якутск",
    "Магадан",              "Орск",                 "Сызрань",              "Ялта",
    "Магнитогорск",         "Павлово",              "Сыктывкар",
    // clang-format on
});

const auto russiaStates = std::to_array<std::string_view>({
    // clang-format off
    "Алтайский край",               "Кемеровская область - Кузбасс","Приморский край",              "Самарская область",
    "Амурская область",             "Кировская область",            "Псковская область",            "Саратовская область",
    "Архангельская область",        "Костромская область",          "Республика Адыгея (Адыгея)",   "Сахалинская область",
    "Астраханская область",         "Краснодарский край",           "Республика Алтай",             "Свердловская область",
    "Белгородская область",         "Красноярский край",            "Республика Башкортостан",      "Смоленская область",
    "Брянская область",             "Курганская область",           "Республика Бурятия",           "Ставропольский край",
    "Владимирская область",         "Курская область",              "Республика Дагестан",          "Тамбовская область",
    "Волгоградская область",        "Ленинградская область",        "Республика Ингушетия",         "Тверская область",
    "Воронежская область",          "Липецкая область",             "Республика Калмыкия",          "Томская область",
    "г. Москва",                    "Магаданская область",          "Республика Карелия",           "Тульская область",
    "г. Санкт - Петербург",         "Московская область",           "Республика Коми",              "Тюменская область",
    "г. Севастополь",               "Мурманская область",           "Республика Крым",              "Удмуртская Республика",
    "Еврейская автономная область", "Ненецкий автономный округ",    "Республика Марий Эл",          "Ульяновская область",
    "Забайкальский край",           "Нижегородская область",        "Республика Мордовия",          "Хабаровский край",
    "Ивановская область",           "Новгородская область",         "Республика Саха (Якутия)",     "Ханты-Мансийский автономный округ - Югра",
    "Иркутская область",            "Новосибирская область",        "Республика Северная Осетия - Алания","Челябинская область",
    "Кабардино - Балкарская Республика","Омская область",           "Республика Татарстан",         "Чеченская Республика",
    "Калининградская область",      "Оренбургская область",         "Республика Тыва",              "Чувашская Республика",
    "Калужская область",            "Орловская область",            "Республика Хакасия",           "Чукотский автономный округ",
    "Камчатский край",              "Пензенская область",           "Ростовская область",           "Ямало-ненецкий автономный округ",
    "Карачаево - Черкесская Республика","Пермский край",            "Рязанская область",            "Ярославская область",
    // clang-format on
});

const auto russiaStreetNames = std::to_array<std::string_view>({
    // clang-format off
    "Советская",      "Сиреневая",       "Сельская",        "Прудовая",      "Депутатская",
    "Авиационная",    "Аэродромная",     "Большая",         "Приморская",    "Алтайская",
    "Тополиная",      "Ростовская",      "Тракторная",      "Мелиоративная", "Ольховая",
    "Славянская",     "Радужная",        "Краснодарская",   "Стахановская",  "Ярославская",
    "Коллективная",   "Ангарская",       "Локомотивная",    "Ягодная",       "Смоленская",
    "Тепличная",      "Водопроводная",   "Республиканская", "Осенняя",       "Байкальская",
    "Саратовская",    "Казанская",       "Воронежская",     "Брянская",      "Производственная",
    "Техническая",    "Енисейская",      "Севастопольская", "Окружная",      "Орловская",
    "Хуторская",      "Тупиковая",       "Каштановая",      "Омская",        "Привольная",
    "Курортная",      "Ивановская",      "Выгонная",        "Крымская",      "Путейская",
    "Проезжая",       "Краснознаменная", "Одесская",        "Логовая",       "Высокая",
    "Ясная",          "Портовая",        "Снежная",         "Санаторная",    "Союзная",
    "Ульяновская",    "Сахалинская",     "Горняцкая",       "Прибрежная",    "Рыбацкая",
    "Полтавская",     "Тамбовская",      "Красноярская",    "Новосельская",  "Проточная",
    "Черноморская",   "Минская",         "Главная",         "Вольная",       "Хвойная",
    "Космическая",    "Моховая",         "Курская",         "Курганная",     "Угловая",
    "Камская",        "Инженерная",      "Лесозаводская",   "Астраханская",  "Белорусская",
    "Заовражная",     "Азовская",        "Ручейная",        "Волочаевская",  "Ставропольская",
    "Слободская",     "Тульская",        "Харьковская",     "Петровская",    "Владимирская",
    "Высоковольтная", "Лазурная",        "Покровская",      "Новгородская",  "Ленская",
    "Сплавная",       "Ударная",         "Калужская",       "Прудная",       "Краснопартизанская",
    "Ореховая",       "Таманская",       "Иркутская",       "Отрадная",      "Большевистская",
    "Троицкая",       "Лесхозная",       "Васильковая",     "Механическая",  "Путевая",
    "Кузнецкая",      "Физкультурная",   "Балтийская",      "Февральская",   "Лунная",
    "Высотная",       "Рязанская",       "Малиновая",
    // clang-format on
});

const auto russiaStreetPrefixes =
    std::to_array<std::string_view>({"улица", "аллея", "бульвар", "линия", "набережная", "тракт", "тупик", "шоссе",
                                     "переулок", "проспект", "мост", "авеню"});

const std::string_view russiaZipCodeFormat{"######"};

const auto russiaAddressFormats =
    std::to_array<std::string_view>({"{street} {buildingNumber}", "{street} {buildingNumber} {secondaryAddress}"});

const auto russiaSecondaryAddressFormats = std::to_array<std::string_view>({"кв. ###", "кв. ##", "кв. #"});

const auto russiaBuildingNumberFormats = std::to_array<std::string_view>({"#", "##", "###"});

const auto russiaStreetFormats = std::to_array<std::string_view>(
    {"{streetPrefix} {firstName}", "{streetPrefix} {lastName}", "{streetPrefix} {streetName}"});

const auto russiaCityFormats = std::to_array<std::string_view>({"{cityName}"});

const CountryAddressesInfo russiaAddresses{
    russiaZipCodeFormat,
    (russiaAddressFormats),
    (russiaSecondaryAddressFormats),
    (russiaStreetFormats),
    (russiaStreetPrefixes),
    (russiaStreetNames),
    {},
    (russiaBuildingNumberFormats),
    (russiaCityFormats),
    {},
    (russiaCities),
    {},
    (russiaStates),
};

// Spain

const auto spainCities = std::to_array<std::string_view>({
    // clang-format off
    "Parla",                "Ponferrada",           "Mollet del Vallés",    "Almería",
    "Telde",                "Zamora",               "Puertollano",          "San Sebastián",
    "Baracaldo",            "Alcalá de Guadaira",   "Madrid",               "Leganés",
    "San Fernando",         "Fuengirola",           "Barcelona",            "Santander",
    "Torrevieja",           "Mijas",                "Valencia",             "Burgos",
    "Lugo",                 "Sanlúcar de Barrameda","Sevilla",              "Castellón de la Plana",
    "Santiago de Compostela","La Línea de la Concepción","Zaragoza",        "Alcorcón",
    "Gerona",               "Majadahonda",          "Málaga",               "Albacete",
    "Cáceres",              "Sagunto",              "Murcia",               "Getafe",
    "Lorca",                "El Prat de LLobregat", "Palma de Mallorca",    "Salamanca",
    "Coslada",              "Viladecans",           "Las Palmas de Gran Canaria","Huelva",
    "Talavera de la Reina", "Linares",              "Bilbao",               "Logroño",
    "El Puerto de Santa María","Alcoy",             "Córdoba",              "Badajoz",
    "Cornellá de Llobregat","Irún",                 "Alicante",             "San Cristróbal de la Laguna",
    "Avilés",               "Estepona",             "Valladolid",           "León",
    "Palencia",             "Torremolinos",         "Vigo",                 "Tarragona",
    "Gecho",                "Rivas-Vaciamadrid",    "Gijón",                "Cádiz",
    "Orihuela",             "Molina de Segura",     "Hospitalet de LLobregat","Lérida",
    "Pontevedra",           "Paterna",              "La Coruña",            "Marbella",
    "Pozuelo de Alarcón",   "Granollers",           "Granada",              "Mataró",
    "Toledo",               "Santa Lucía de Tirajana","Vitoria",            "Dos Hermanas",
    "El Ejido",             "Motril",               "Elche",                "Santa Coloma de Gramanet",
    "Guadalajara",          "Cerdañola del Vallés", "Santa Cruz de Tenerife","Jaén",
    "Gandía",               "Arrecife",             "Oviedo",               "Algeciras",
    "Ceuta",                "Segovia",              "Badalona",             "Torrejón de Ardoz",
    "Ferrol",               "Torrelavega",          "Cartagena",            "Orense",
    "Chiclana de la Frontera","Elda",               "Móstoles",             "Alcobendas",
    "Manresa",              "Mérida",               "Jerez de la Frontera", "Reus",
    "Roquetas de Mar",      "Ávila",                "Tarrasa",              "Calahorra",
    "Ciudad Real",          "Valdemoro",            "Sabadell",             "Inca",
    "Rubí",                 "Cuenta",               "Alcalá de Henares",    "Aýna",
    "Benidorm",             "Collado Villalba",     "Pamplona",
    "San Sebastían de los Reyes","Benalmádena",     "Fuenlabrada",
    // clang-format on
});

const auto spainStates = std::to_array<std::string_view>({
    // clang-format off
    "Andalucía",            "Cantabria",            "Extremadura",          "País Vasco",
    "Aragón",               "Castilla-La Mancha",   "Galicia",              "Región de Murcia",
    "Principado de Asturias","Castilla y León",     "La Rioja",
    "Baleares",             "Cataluña",             "Comunidad de Madrid",
    "Canarias",             "Comunidad Valenciana", "Navarra",
    // clang-format on
});

const auto spainStreetSuffixes = std::to_array<std::string_view>({
    // clang-format off
    "Aldea",       "Apartamento", "Arrabal",  "Arroyo",       "Avenida",   "Bajada",      "Barranco",  "Barrio",
    "Bloque",      "Calle",       "Calleja",  "Camino",       "Carretera", "Caserio",     "Colegio",   "Colonia",
    "Conjunto",    "Cuesta",      "Chalet",   "Edificio",     "Entrada",   "Escalinata",  "Explanada", "Extramuros",
    "Extrarradio", "Ferrocarril", "Glorieta", "Gran Subida",  "Grupo",     "Huerta",      "Jardines",  "Lado",
    "Lugar",       "Manzana",     "Masía",    "Mercado",      "Monte",     "Muelle",      "Municipio", "Parcela",
    "Parque",      "Partida",     "Pasaje",   "Paseo",        "Plaza",     "Poblado",     "Polígono",  "Prolongación",
    "Puente",      "Puerta",      "Quinta",   "Ramal",        "Rambla",    "Rampa",       "Riera",     "Rincón",
    "Ronda",       "Rua",         "Salida",   "Sector",       "Sección",   "Senda",       "Solar",     "Subida",
    "Terrenos",    "Torrente",    "Travesía", "Urbanización", "Vía",       "Vía Pública",
    // clang-format on
});

const std::string_view spainZipCodeFormat{"#####"};

const auto spainAddressFormats =
    std::to_array<std::string_view>({"{street} {buildingNumber})", "{street} {buildingNumber} {secondaryAddress}"});

const auto spainSecondaryAddressFormats = std::to_array<std::string_view>({"Esc. ###", "Puerta ###"});

const auto spainBuildingNumberFormats = std::to_array<std::string_view>({"s/n.", "#", "##"});

const auto spainStreetFormats =
    std::to_array<std::string_view>({"{streetSuffix} {firstName}", "{streetSuffix} {firstName} {lastName}"});

const auto spainCityFormats = std::to_array<std::string_view>({"{cityName}"});

const CountryAddressesInfo spainAddresses{
    spainZipCodeFormat,
    (spainAddressFormats),
    (spainSecondaryAddressFormats),
    (spainStreetFormats),
    {},
    {},
    (spainStreetSuffixes),
    (spainBuildingNumberFormats),
    (spainCityFormats),
    {},
    (spainCities),
    {},
    (spainStates),
};

// Ukraine

const auto ukraineCities = std::to_array<std::string_view>({
    // clang-format off
    "Авдіївка",             "Вашківці",             "Звенигородка",         "Кропивницький",
    "Аджи-Мушкай",          "Великі Мости",         "Звягель",              "Куп'янськ",
    "Алмазна",              "Верхівцеве",           "Здолбунів",            "Курахове",
    "Алупка",               "Верхньодніпровськ",    "Зелене (Харків)",      "Ладижин",
    "Алушта",               "Вижниця",              "Зеленодольськ",        "Ланівці",
    "Алчевськ",             "Вилкове",              "Зимогір'я",            "Лебедин",
    "Амвросіївка",          "Винники",              "Зіньків",              "Лиман (місто)",
    "Ананьїв",              "Виноградів",           "Зміїв",                "Липовець",
    "Андрушівка",           "Вишгород",             "Знам'янка",            "Лисичанськ",
    "Антрацит (місто)",     "Вишневе (місто)",      "Золоте",               "Лозова",
    "Апостолове",           "Вільногірськ",         "Золотоноша",           "Лохвиця",
    "Армянськ",             "Вільнянськ",           "Золочів",              "Лубни",
    "Арциз",                "Вінниця",              "Зоринськ",             "Луганськ",
    "Балаклія",             "Вовчанськ",            "Зугрес",               "Лутугине",
    "Балта",                "Вознесенівка",         "Івано-Франківськ",     "Луцьк",
    "Бар (Україна)",        "Вознесенськ",          "Ізмаїл",               "Львів",
    "Баранівка",            "Волноваха",            "Ізюм",                 "Любомль",
    "Барвінкове",           "Володимир (місто)",    "Ізяслав",              "Люботин",
    "Батурин",              "Волочиськ",            "Іллінці",              "Макіївка",
    "Бахмач",               "Ворожба",              "Іловайськ",            "Мала Виска",
    "Бахмут",               "Вуглегірськ",          "Інкерман",             "Малин",
    "Бахчисарай",           "Вугледар",             "Ірміно",               "Мар'їнка",
    "Баштанка",             "Гадяч",                "Ірпінь",               "Марганець (місто)",
    "Белз",                 "Гайворон",             "Іршава",               "Маріуполь",
    "Бердичів",             "Гайсин",               "Ічня",                 "Мелітополь",
    "Бердянськ",            "Галич",                "Кагарлик",             "Мена (місто)",
    "Берегове",             "Генічеськ",            "Кадіївка",             "Мерефа",
    "Бережани",             "Географія Вільнянська","Калинівка (місто)",    "Миколаїв",
    "Березань (місто)",     "Герца",                "Калуш",                "Миколаїв (Львівська область)",
    "Березівка",            "Гірник (місто)",       "Кальміуське",          "Миколаївка (місто)",
    "Березне",              "Гостомель",            "Кам'янець-Подільський","Миргород",
    "Берестечко",           "Гребінка",             "Кам'янка (Черкаська область)","Хмільник",
    "Берислав",             "Гуляйполе",            "Кам'янка-Бузька",      "Ходорів",
    "Бершадь",              "Дебальцеве",           "Кам'янка-Дніпровська", "Хорол (місто)",
    "Бібрка",               "Деражня",              "Кам'янське",           "Хоростків",
    "Біла Церква",          "Дергачі",              "Камінь-Каширський",    "Хотин",
    "Білгород-Дністровський","Джабу",               "Канів",                "Хрестівка",
    "Білицьке",             "Джанкой",              "Карлівка",             "Христинівка",
    "Білогірськ",           "Дніпро (місто)",       "Каховка",              "Хрустальний",
    "Білозерське",          "Дніпрорудне",          "Керч",                 "Хуст",
    "Білопілля",            "Добромиль",            "Київ",                 "Часів Яр",
    "Біляївка",             "Добропілля",           "Кипуче",               "Червоноград",
    "Благовіщенське",       "Добросин",             "Ківерці",              "Червоносів",
    "Бобринець",            "Довжанськ",            "Кілія",                "Черкаси",
    "Бобровиця",            "Докучаєвськ",          "Кіцмань",              "Чернівці",
    "Богодухів",            "Долина (місто)",       "Кобеляки",             "Чернігів",
    "Богуслав",             "Долинська",            "Ковель",               "Чигирин",
    "Боково-Хрустальне",    "Донецьк",              "Кодима",               "Чистякове",
    "Болград",              "Дрогобич",             "Користувач:Козак Яна/Чернетка","Чоп",
    "Болехів",              "Дружба (місто)",       "Козятин",              "Чорнобиль",
    "Борзна",               "Дружківка",            "Коломия",              "Чорноморськ",
    "Борислав",             "Дубляни",              "Комарно",              "Чортків",
    "Бориспіль",            "Дубно",                "Конотоп",              "Чугуїв",
    "Бородянка",            "Дубровиця",            "Копичинці",            "Чуднів",
    "Борщів",               "Дунаївці",             "Корець",               "Шаргород",
    "Боссе (Донецьк)",      "Енергодар",            "Коростень",            "Шахтарськ",
    "Боярка",               "Євпаторія",            "Коростишів",           "Шепетівка",
    "Бровари",              "Єнакієве",             "Корсунь-Шевченківський","Шостка",
    "Броди",                "Жашків",               "Корюківка",            "Шпола",
    "Брянка",               "Жданівка",             "Косів",                "Шумськ",
    "Булгак (село)",        "Жидачів",              "Костопіль",            "Щастя (місто)",
    "Бунге (місто)",        "Житомир",              "Костянтинівка",        "Щолкіне",
    "Буринь",               "Жмеринка",             "Коцюбинське",          "Южне",
    "Бурштин (місто)",      "Жовква",               "Краматорськ",          "Южноукраїнськ",
    "Буськ",                "Жовті Води",           "Красилів",             "Яворів",
    "Буча",                 "Заводське",            "Красногорівка",        "Яготин",
    "Бучач",                "Залізне",              "Красноград",           "Ялта",
    "Валки (місто)",        "Заліщики",             "Кременець",            "Ямпіль",
    "Вараш",                "Запоріжжя",            "Кременчук",            "Яни Капу",
    "Василівка (місто)",    "Заставна",             "Кремінна",             "Янів (Київська область)",
    "Васильків",            "Збараж",               "Кривий Ріг",           "Яремче",
    "Ватутіне",             "Зборів",               "Кролевець",
    // clang-format on
});

const auto ukraineStates = std::to_array<std::string_view>({
    // clang-format off
    "АР Крим",                      "Запорізька область",           "Одеська область",              "Хмельницька область",
    "Вінницька область",            "Івано-Франківська область",    "Полтавська область",           "Черкаська область",
    "Волинська область",            "Київська область",             "Рівненська область",           "Чернівецька область",
    "Дніпропетровська область",     "Кіровоградська область",       "Сумська область",              "Чернігівська область",
    "Донецька область",             "Луганська область",            "Тернопільська область",        "Київ",
    "Житомирська область",          "Львівська область",            "Харківська область",           "Севастополь",
    "Закарпатська область",         "Миколаївська область",         "Херсонська область",
    // clang-format on
});

const auto ukraineStreetNames = std::to_array<std::string_view>({
    // clang-format off
    "Хрещатик",             "Крещатик",             "Айвазовського",                "Валківська",
    "Бессарабська",         "Печерська",            "Академіка Корольова",          "Валова",
    "Саксаганського",       "Харківська",           "Академіка Ромоданова",         "Варварівська",
    "Липська",              "Богдана Хмельницького","Генерала Алмазова",            "Варненська",
    "Золотоворітська",      "Нова",                 "Генерала Алмазова",            "Варшавська",
    "Артема",               "Героїв Майдану",       "Алматинська",                  "Варшавська",
    "Шевченка",             "Гагаріна",             "Алчевських",                   "Миколи Василенка",
    "Горького",             "Любченка",             "Алчевської",                   "Симона Петлюри",
    "Московська",           "Озерна",               "Христини Алчевської",          "Василицька",
    "Лесі Українки",        "Петра Могили",         "Альпійська",                   "Василівська",
    "Січових Стрільців",    "Сагайдачного",         "Альпійський",                  "Василівська",
    "Майдан Незалежності",  "Тичини",               "Амет-Хана Султана",            "Васильківська",
    "Прорізна",             "Азербайджанська",      "Академіка Амосова",            "Васильківський",
    "Інститутська",         "Азовська",             "Миколи Амосова",
    "Пушкінська",           "Азовська",             "Валентинівська",
    "Бульвар Тараса Шевченка","Азовський",          "Валіховський",
    // clang-format on
});

const auto ukraineStreetPrefixes = std::to_array<std::string_view>(
    {"вулиця", "аллея", "бульвар", "лінія", "набережна", "шоссе", "перевулок", "проспект", "міст", "авеню"});

const std::string_view ukraineZipCodeFormat{"#####"};

const auto ukraineAddressFormats =
    std::to_array<std::string_view>({"{street} {buildingNumber}", "{street} {buildingNumber} {secondaryAddress}"});

const auto ukraineSecondaryAddressFormats = std::to_array<std::string_view>({"кв. ###", "кв. ##", "кв. #"});

const auto ukraineBuildingNumberFormats = std::to_array<std::string_view>({"#", "##", "###"});

const auto ukraineStreetFormats = std::to_array<std::string_view>(
    {"{streetPrefix} {firstName}", "{streetPrefix} {lastName}", "{streetPrefix} {streetName}"});

const auto ukraineCityFormats = std::to_array<std::string_view>({"{cityName}"});

const CountryAddressesInfo ukraineAddresses{
    ukraineZipCodeFormat,
    (ukraineAddressFormats),
    (ukraineSecondaryAddressFormats),
    (ukraineStreetFormats),
    (ukraineStreetPrefixes),
    (ukraineStreetNames),
    {},
    (ukraineBuildingNumberFormats),
    (ukraineCityFormats),
    {},
    (ukraineCities),
    {},
    (ukraineStates),
};

// USA

const auto usaCities = std::to_array<std::string_view>({
    // clang-format off
    "Abilene",              "Flagstaff",            "Mesquite",             "Rogers",
    "Akron",                "Flint",                "Metairie",             "Rohnert Park",
    "Alafaya",              "Florence-Graham",      "Methuen Town",         "Rosemead",
    "Alameda",              "Florin",               "Miami",                "Roseville",
    "Albany",               "Greeley",              "Miami Beach",          "Roswell",
    "Albuquerque",          "Green Bay",            "Mobile",               "Round Rock",
    "Alexandria",           "Greensboro",           "Modesto",              "Rowland Heights",
    "Alhambra",             "Greenville",           "Moline",               "Rowlett",
    "Aliso Viejo",          "Greenwood",            "Monroe",               "Royal Oak",
    "Allen",                "Gresham",              "Montebello",           "Sacramento",
    "Allentown",            "Guaynabo",             "Monterey Park",        "Saginaw",
    "Aloha",                "Gulfport",             "Montgomery",           "Salem",
    "Alpharetta",           "Hacienda Heights",     "Moore",                "Salina",
    "Altadena",             "Hackensack",           "Moreno Valley",        "San Tan Valley",
    "Altamonte Springs",    "Haltom City",          "Morgan Hill",          "Sandy",
    "Altoona",              "Hamilton",             "Mount Pleasant",       "Sandy Springs",
    "Amarillo",             "Hammond",              "Mount Prospect",       "Sanford",
    "Ames",                 "Hampton",              "Mount Vernon",         "Santa Ana",
    "Anaheim",              "Hanford",              "Mountain View",        "Santa Barbara",
    "Anchorage",            "Harlingen",            "Muncie",               "Santa Clara",
    "Anderson",             "Harrisburg",           "Murfreesboro",         "Santa Clarita",
    "Blue Springs",         "Harrisonburg",         "Murray",               "Santa Cruz",
    "Boca Raton",           "Hartford",             "Murrieta",             "Santa Fe",
    "Boise City",           "Hattiesburg",          "Nampa",                "Santa Maria",
    "Bolingbrook",          "Haverhill",            "Napa",                 "Santa Monica",
    "Bonita Springs",       "Hawthorne",            "Naperville",           "Santa Rosa",
    "Bossier City",         "Hayward",              "Nashua",               "Santee",
    "Boston",               "Hemet",                "Nashville-Davidson",   "Sarasota",
    "Bothell",              "Hempstead",            "New Haven",            "Savannah",
    "Boulder",              "Henderson",            "New Orleans",          "Sayreville",
    "Bountiful",            "Hendersonville",       "New Rochelle",         "Schaumburg",
    "Bowie",                "Hesperia",             "New York",             "Schenectady",
    "Bowling Green",        "Hialeah",              "Newark",               "Scottsdale",
    "Boynton Beach",        "Hicksville",           "Newport Beach",        "South Valley",
    "Bozeman",              "High Point",           "Newport News",         "South Whittier",
    "Bradenton",            "Highland",             "Newton",               "Southaven",
    "Brandon",              "Highlands Ranch",      "Niagara Falls",        "Southfield",
    "Brentwood",            "Hillsboro",            "Noblesville",          "Sparks",
    "Bridgeport",           "Hilo",                 "Norfolk",              "Spokane",
    "Bristol",              "Hoboken",              "Normal",               "Spokane Valley",
    "Brockton",             "Hoffman Estates",      "Norwalk",              "Spring",
    "Broken Arrow",         "Hollywood",            "Novato",               "Spring Hill",
    "Carlsbad",             "Homestead",            "Novi",                 "Spring Valley",
    "Carmel",               "Honolulu",             "Oak Lawn",             "Springdale",
    "Carmichael",           "Hoover",               "Oak Park",             "Tacoma",
    "Carolina",             "Houston",              "Oakland",              "Tallahassee",
    "Carrollton",           "Huntersville",         "Oakland Park",         "Tamarac",
    "Carson",               "Huntington",           "Ocala",                "Tamiami",
    "Carson City",          "Huntington Beach",     "Oceanside",            "Tampa",
    "Cary",                 "Huntington Park",      "Odessa",               "Taunton",
    "Casa Grande",          "Huntsville",           "Ogden",                "Taylor",
    "Casas Adobes",         "Hutchinson",           "Oklahoma City",        "Taylorsville",
    "Casper",               "Irvine",               "Olathe",               "Temecula",
    "Castle Rock",          "Irving",               "Olympia",              "Tempe",
    "Castro Valley",        "Jackson",              "Omaha",                "Temple",
    "Catalina Foothills",   "Jacksonville",         "Ontario",              "Terre Haute",
    "Cathedral City",       "Janesville",           "Orange",               "Texas City",
    "Catonsville",          "Jefferson City",       "Orem",                 "The Hammocks",
    "Cedar Hill",           "Jeffersonville",       "Orland Park",          "The Villages",
    "Cedar Park",           "Jersey City",          "Palo Alto",            "The Woodlands",
    "Cedar Rapids",         "Johns Creek",          "Paradise",             "Thornton",
    "Centennial",           "Johnson City",         "Paramount",            "Thousand Oaks",
    "Centreville",          "Joliet",               "Parker",               "Tigard",
    "Ceres",                "Jonesboro",            "Parma",                "Tinley Park",
    "Cerritos",             "Joplin",               "Pasadena",             "Titusville",
    "Champaign",            "Jupiter",              "Pasco",                "Toledo",
    "Chandler",             "Jurupa Valley",        "Passaic",              "Toms River",
    "Chapel Hill",          "Kalamazoo",            "Paterson",             "Tonawanda",
    "Charleston",           "Kannapolis",           "Pawtucket",            "Topeka",
    "Charlotte",            "Kansas City",          "Peabody",              "Torrance",
    "Charlottesville",      "Kearny",               "Pearl City",           "Towson",
    "Chattanooga",          "Keller",               "Pearland",             "Tracy",
    "Cheektowaga",          "Kendale Lakes",        "Pembroke Pines",       "Trenton",
    "Chesapeake",           "Kendall",              "Pensacola",            "Troy",
    "Chesterfield",         "Kenner",               "Peoria",               "Trujillo Alto",
    "Cheyenne",             "Kennewick",            "Perris",               "Tuckahoe",
    "Chicago",              "Kenosha",              "Perth Amboy",          "Tucson",
    "Chico",                "Kent",                 "Petaluma",             "Tulare",
    "Chicopee",             "Kentwood",             "Pflugerville",         "Tulsa",
    "Chino",                "Kettering",            "Pharr",                "Turlock",
    "Chino Hills",          "Killeen",              "Plantation",           "Tuscaloosa",
    "Chula Vista",          "Kingsport",            "Pleasanton",           "Waldorf",
    "Dallas",               "Kirkland",             "Plymouth",             "Walnut Creek",
    "Daly City",            "Kissimmee",            "Pocatello",            "Waltham",
    "Danbury",              "Knoxville",            "Poinciana",            "Warner Robins",
    "Danville",             "Lancaster",            "Pomona",               "Warren",
    "Davenport",            "Lansing",              "Pompano Beach",        "Warwick",
    "Davie",                "Laredo",               "Ponce",                "Washington",
    "Davis",                "Largo",                "Pontiac",              "Waterbury",
    "Dayton",               "Las Cruces",           "Port Arthur",          "Waterloo",
    "Daytona Beach",        "Las Vegas",            "Port Charlotte",       "Watsonville",
    "DeKalb",               "Lauderhill",           "Port Orange",          "Waukegan",
    "DeSoto",               "Lawrence",             "Port St. Lucie",       "Waukesha",
    "Dearborn",             "Lawton",               "Portage",              "Wauwatosa",
    "Dearborn Heights",     "Layton",               "Porterville",          "Wellington",
    "Decatur",              "League City",          "Portland",             "Wesley Chapel",
    "Deerfield Beach",      "Leesburg",             "Portsmouth",           "West Allis",
    "Delano",               "Lehi",                 "Potomac",              "West Babylon",
    "Delray Beach",         "Lehigh Acres",         "Poway",                "West Covina",
    "Deltona",              "Lenexa",               "Providence",           "West Des Moines",
    "Denton",               "Levittown",            "Provo",                "West Hartford",
    "Denver",               "Lewisville",           "Pueblo",               "Wheaton",
    "Elyria",               "Lexington-Fayette",    "Quincy",               "White Plains",
    "Encinitas",            "Lincoln",              "Racine",               "Whittier",
    "Enid",                 "Manteca",              "Reston",               "Wichita",
    "Enterprise",           "Maple Grove",          "Revere",               "Wichita Falls",
    "Erie",                 "Margate",              "Rialto",               "Wilmington",
    "Escondido",            "Maricopa",             "Richardson",           "Wilson",
    "Euclid",               "Marietta",             "Richland",             "Winston-Salem",
    "Eugene",               "Marysville",           "Richmond",             "Woodbury",
    "Euless",               "Mayaguez",             "Rio Rancho",           "Woodland",
    "Evanston",             "McAllen",              "Riverside",            "Worcester",
    "Evansville",           "McKinney",             "Riverton",             "Wylie",
    "Everett",              "McLean",               "Riverview",            "Wyoming",
    "Fairfield",            "Medford",              "Roanoke",              "Yakima",
    "Fall River",           "Melbourne",            "Rochester",            "Yonkers",
    "Fargo",                "Memphis",              "Rochester Hills",      "Yorba Linda",
    "Farmington",           "Menifee",              "Rock Hill",            "York",
    "Farmington Hills",     "Mentor",               "Rockford",             "Youngstown",
    "Fayetteville",         "Merced",               "Rocklin",              "Yuba City",
    "Federal Way",          "Meriden",              "Rockville",
    "Findlay",              "Meridian",             "Rockwall",
    "Fishers",              "Mesa",                 "Rocky Mount",
    // clang-format on
});

const auto usaStates = std::to_array<std::string_view>(
    {"Alabama",       "Alaska",     "Arizona",      "Arkansas",     "California",     "Colorado",      "Connecticut",
     "Delaware",      "Florida",    "Georgia",      "Hawaii",       "Idaho",          "Illinois",      "Indiana",
     "Iowa",          "Kansas",     "Kentucky",     "Louisiana",    "Maine",          "Maryland",      "Massachusetts",
     "Michigan",      "Minnesota",  "Mississippi",  "Missouri",     "Montana",        "Nebraska",      "Nevada",
     "New Hampshire", "New Jersey", "New Mexico",   "New York",     "North Carolina", "North Dakota",  "Ohio",
     "Oklahoma",      "Oregon",     "Pennsylvania", "Rhode Island", "South Carolina", "South Dakota",  "Tennessee",
     "Texas",         "Utah",       "Vermont",      "Virginia",     "Washington",     "West Virginia", "Wisconsin",
     "Wyoming"});

const auto usaStreetSuffixes = std::to_array<std::string_view>(
    {"Alley",      "Avenue",     "Branch",    "Bridge",     "Brook",    "Brooks",   "Burg",     "Burgs",
     "Bypass",     "Camp",       "Canyon",    "Cape",       "Causeway", "Center",   "Centers",  "Circle",
     "Circles",    "Cliff",      "Cliffs",    "Club",       "Common",   "Corner",   "Corners",  "Course",
     "Court",      "Courts",     "Cove",      "Coves",      "Creek",    "Crescent", "Crest",    "Crossing",
     "Crossroad",  "Curve",      "Dale",      "Dam",        "Divide",   "Drive",    "Drives",   "Estate",
     "Estates",    "Expressway", "Extension", "Extensions", "Fall",     "Falls",    "Ferry",    "Field",
     "Fields",     "Flat",       "Flats",     "Ford",       "Fords",    "Forest",   "Forge",    "Forges",
     "Fork",       "Forks",      "Fort",      "Freeway",    "Garden",   "Gardens",  "Gateway",  "Glen",
     "Glens",      "Green",      "Greens",    "Grove",      "Groves",   "Harbor",   "Harbors",  "Haven",
     "Heights",    "Highway",    "Hill",      "Hills",      "Hollow",   "Inlet",    "Island",   "Islands",
     "Isle",       "Junction",   "Junctions", "Key",        "Keys",     "Knoll",    "Knolls",   "Lake",
     "Lakes",      "Land",       "Landing",   "Lane",       "Light",    "Lights",   "Loaf",     "Lock",
     "Locks",      "Lodge",      "Loop",      "Mall",       "Manor",    "Manors",   "Meadow",   "Meadows",
     "Mews",       "Mill",       "Mills",     "Mission",    "Motorway", "Mount",    "Mountain", "Mountains",
     "Neck",       "Orchard",    "Oval",      "Overpass",   "Park",     "Parks",    "Parkway",  "Parkways",
     "Pass",       "Passage",    "Path",      "Pike",       "Pine",     "Pines",    "Place",    "Plain",
     "Plains",     "Plaza",      "Point",     "Points",     "Port",     "Ports",    "Prairie",  "Radial",
     "Ramp",       "Ranch",      "Rapid",     "Rapids",     "Rest",     "Ridge",    "Ridges",   "River",
     "Road",       "Roads",      "Route",     "Row",        "Rue",      "Run",      "Shoal",    "Shoals",
     "Shore",      "Shores",     "Skyway",    "Spring",     "Springs",  "Spur",     "Spurs",    "Square",
     "Squares",    "Station",    "Stravenue", "Stream",     "Street",   "Streets",  "Summit",   "Terrace",
     "Throughway", "Trace",      "Track",     "Trafficway", "Trail",    "Tunnel",   "Turnpike", "Underpass",
     "Union",      "Unions",     "Valley",    "Valleys",    "Via",      "Viaduct",  "View",     "Views",
     "Village",    "Villages",   "Ville",     "Vista",      "Walk",     "Walks",    "Wall",     "Way",
     "Ways",       "Well",       "Wells"});

const std::string_view usaZipCodeFormat{"#####"};

const auto usaAddressFormats = std::to_array<std::string_view>({"{buildingNumber} {street}"});

const auto usaSecondaryAddressFormats = std::to_array<std::string_view>({"Apt. ###", "Suite ###"});

const auto usaBuildingNumberFormats = std::to_array<std::string_view>({"#####", "####", "###"});

const auto usaStreetFormats =
    std::to_array<std::string_view>({"{firstName} {streetSuffix}", "{lastName} {streetSuffix}"});

const auto usaCityFormats = std::to_array<std::string_view>({"{cityName}"});

const CountryAddressesInfo usaAddresses{
    usaZipCodeFormat,
    (usaAddressFormats),
    (usaSecondaryAddressFormats),
    (usaStreetFormats),
    {},
    {},
    (usaStreetSuffixes),
    (usaBuildingNumberFormats),
    (usaCityFormats),
    {},
    (usaCities),
    {},
    usaStates,
};

}
