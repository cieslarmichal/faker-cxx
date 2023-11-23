#pragma once

#include <string>
#include <vector>

namespace faker
{
const std::vector<std::string> estonianLastNames = {
    "Tamm",       "Saar",      "Sepp",        "Kask",         "Mägi",       "Kukk",       "Rebane",     "Koppel",
    "Karu",       "Ilves",     "Lepik",       "Oja",          "Ivanov",     "Kuusk",      "Kaasik",     "Cuca",
    "Luik",       "Raudsepp",  "Vaher",       "Kallas",       "Lepp",       "Laur",       "Pärn",       "Kuusik",
    "Kivi",       "Ots",       "Liiv",        "Peterson",     "Teder",      "Mets",       "Põder",      "Kull",
    "Kütt",       "Puusepp",   "Kangur",      "Jakobson",     "Rand",       "Toom",       "Saks",       "Smirnov",
    "Leppik",     "Raud",      "Mitt",        "Sild",         "Sarapuu",    "Ivanova",    "Mölder",     "Roos",
    "Tamme",      "Allik",     "Kõiv",        "Paju",         "Paas",       "Laas",       "Pukk",       "Miller",
    "Palm",       "Tomson",    "Uibo",        "Põld",         "Jürgenson",  "Kalda",      "Lill",       "Männik",
    "Nõmm",       "Johanson",  "Orav",        "Unt",          "Parts",      "Lind",       "Hunt",       "Petrov",
    "Arro",       "Adamson",   "Hein",        "Lember",       "Rätsep",     "Järv",       "Nurk",       "Tali",
    "Pihlak",     "Kase",      "Aavik",       "Kruus",        "Valk",       "Hansen",     "Järve",      "Väli",
    "Vares",      "Aru",       "Rohtla",      "Kikas",        "Sikk",       "Mõttus",     "Soosaar",    "Kuznetsov",
    "Vassiljev",  "Kolk",      "Must",        "Sarv",         "Martin",     "Mänd",       "Annus",      "Kala",
    "Tilk",       "Luts",      "Varik",       "Tomingas",     "Raid",       "Smirnova",   "Pavlov",     "Kirsipuu",
    "Laine",      "Aas",       "Anderson",    "Lang",         "Kaur",       "Anton",      "Post",       "Aus",
    "Abel",       "Ojala",     "Kokk",        "Palu",         "Schmidt",    "Kuus",       "Kink",       "Gross",
    "Popov",      "Ott",       "Martinson",   "Rosenberg",    "Roots",      "Reimann",    "Sokolov",    "Allas",
    "Toome",      "Volkov",    "Sander",      "Kirs",         "Lipp",       "Põldma",     "Taal",       "Hanson",
    "Kalmus",     "Paal",      "Petrova",     "Link",         "Berg",       "Aun",        "Simson",     "Müürsepp",
    "Eller",      "Liivak",    "Kurg",        "Stepanov",     "Laan",       "Kass",       "Trei",       "Leis",
    "Koit",       "Morozov",   "Susi",        "Raja",         "Lumi",       "Meier",      "Vain",       "Lass",
    "Kim",        "Aasa",      "Parve",       "Mark",         "Lauri",      "Kozlov",     "Sutt",       "Soo",
    "Erm",        "Lebedev",   "Saul",        "Holm",         "Kuznetsova", "Popova",     "Poom",       "Soots",
    "Andersson",  "Jürgens",   "Kelder",      "Kalm",         "Eriksson",   "Kont",       "Kroon",      "Kutsar",
    "Pajula",     "Kasak",     "Salu",        "Koger",        "Nikitin",    "Peets",      "Siim",       "Johansson",
    "Ader",       "Savi",      "Novikov",     "Alas",         "Padar",      "Muru",       "Silm",       "Suvi",
    "Rosin",      "Kuzmin",    "Aleksandrov", "Markus",       "Zaitsev",    "Pihl",       "Joost",      "Meister",
    "Pavlova",    "Viik",      "Karp",        "Remmel",       "Orlov",      "Piho",       "Braun",      "Raidma",
    "Maksimov",   "Bergmann",  "Kool",        "Laks",         "Romanov",    "Li",         "Filippov",   "Antonov",
    "Hendrikson", "Talvik",    "Laos",        "Kruuse",       "Reinhold",   "Virtanen",   "Borissov",   "Solovjov",
    "Oks",        "Malm",      "Moor",        "Trofimov",     "Kovalenko",  "Türk",       "Tomberg",    "Jensen",
    "Noor",       "Fjodorova", "Kapp",        "Paap",         "Treier",     "Savolainen", "Bondarenko", "Kalle",
    "Rist",       "Ross",      "Stepanova",   "Larsson",      "Smith",      "Paulus",     "Orlova",     "Sillaots",
    "Jaanus",     "Vene",      "Semjonova",   "Vahi",         "Pent",       "Tisler",     "Volkova",    "Nilsson",
    "Lee",        "Roose",     "Janson",      "Makarov",      "Lehtonen",   "Kaup",       "Lille",      "Vill",
    "Frolov",     "Sisask",    "Erik",        "Raun",         "Karlsson",   "Belov",      "Loo",        "Vinogradov",
    "Lehtinen",   "Tasa",      "Pajo",        "Aava",         "Klein",      "Merila",     "Alt",        "Evert",
    "Pool",       "Lukas",     "Lääts",       "Mere",         "Pill",       "Vare",       "Baranov",    "Matt",
    "Steinberg",  "Reiman",    "Bogdanov",    "Pulk",         "Grünberg",   "Press",      "Koch",       "Soon",
    "Mandel",     "Jakovleva", "Andersen",    "Aleksandrova", "Kaldma",     "Sommer",     "Vilu",       "Mustonen",
    "Melnikov",   "Jaakson",   "Korhonen",    "Nieminen",     "Borissova",  "Rinne",      "Makarova",   "Otsa",
    "Hurt",       "Sorokin",   "Valdmann",    "Kanter",       "Kipper",     "Tint",       "Hint",       "Sein",
    "Nael",       "Bachmann",  "Laar",        "Suviste",      "Raig",       "Grigorjeva", "Sergejev",   "Klaas",
    "Nikitina",   "Haas",      "Lebedeva",    "Margus",       "Saag",       "Kirt",
};
}
