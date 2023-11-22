#pragma once

#include <string>
#include <vector>

namespace faker
{
const std::vector<std::string> latvianMalesLastNames = {
    "Aigars",     "Alksnis",     "Andersons",   "Aspers",      "Auziņš",     "Ābele",       "Āboliņš",    "Āboltiņš",
    "Balodis",    "Beļavskis",   "Bergmanis",   "Bērziņš",     "Bērzīts",    "Birziņš",     "Birznieks",  "Bīriņš",
    "Blaus",      "Blekte",      "Breņķis",     "Briedis",     "Brunkevičs", "Builis",      "Bušs",       "Caune",
    "Cālītis",    "Cīrulis",     "Čudars",      "Danielsons",  "Dīriķis",    "Dombrovskis", "Dreimanis",  "Dzenis",
    "Eglītis",    "Endziņš",     "Fogelis",     "Freimanis",   "Gailis",     "Gailītis",    "Gibala",     "Graudiņš",
    "Gribusts",   "Grīnbergs",   "Grūbe",       "Jansons",     "Jēkabsons",  "Jukums",      "Kalējs",     "Kalniņš",
    "Karlsons",   "Kauliņš",     "Kārkliņš",    "Kļaviņš",     "Kohs",       "Koks",        "Krancis",    "Krastiņš",
    "Kraulis",    "Krauze",      "Krēsliņš",    "Krieviņš",    "Krievs",     "Kronbergs",   "Krūmiņš",    "Kulmanis",
    "Laiviņš",    "Landmanis",   "Lapiņš",      "Lapsiņš",     "Lasmanis",   "Laubergs",    "Lācis",      "Legzdiņš",
    "Lielmanis",  "Liepiņš",     "Līcis",       "Līdaks",      "Ločs",       "Lodiņš",      "Lūsis",      "Matisons",
    "Mednis",     "Meiers",      "Mekšs",       "Melderis",    "Melngailis", "Mihailovs",   "Miķelsons",  "Niedra",
    "Osis",       "Ostrovskis",  "Ozers",       "Ozoliņš",     "Ozols",      "Palters",     "Pavlovskis", "Pencis",
    "Petrovskis", "Pērkons",     "Pētersons",   "Podziņš",     "Polis",      "Pretkalniņš", "Priedītis",  "Puķītis",
    "Putniņš",    "Riekstiņš",   "Romanovskis", "Rozenbahs",   "Rozītis",    "Rubenis",     "Rudzītis",   "Runcis",
    "Salmiņš",    "Seržants",    "Sietnieks",   "Siliņš",      "Sīlis",      "Skudra",      "Smuģis",     "Sproģis",
    "Sprūde",     "Strautiņš",   "Strautmanis", "Strazdiņš",   "Širovs",     "Šīrants",     "Šmits",      "Šteins",
    "Tālbergs",   "Teicāns",     "Tiltiņš",     "Tīrelis",     "Tučs",       "Ūdris",       "Valters",    "Vasils",
    "Vecumnieks", "Veinbergs",   "Veiss",       "Vilks",       "Vilsons",    "Viļums",      "Vinters",    "Vītiņš",
    "Vītoliņš",   "Vītols",      "Vītums",      "Vollis",      "Zariņš",     "Zālītis",     "Zeidmanis",  "Zeltiņš",
    "Ziemelis",   "Zībers",      "Zunda",       "Zvaigzne",    "Zvejnieks",  "Zvinelis",    "Mucenieks",  "Dzirkalis",
    "Arājs",      "Sējējs",      "Podnieks",    "Ratnieks",    "Deģis",      "Bondars",     "Sondors",    "Namiķis",
    "Jumiķis",    "Muižnieks",   "Bajārs",      "Ķēniņš",      "Ķeizars",    "Barons",      "Vaivads",    "Zviedrs",
    "Vācietis",   "Lejiņš",      "Vanags",      "Celms",       "Liepa",      "Kalns",       "Celmiņš",    "Lejnieks",
    "Bisenieks",  "Kurzemnieks", "Saulietis",   "Pakalnietis", "Pridāns",    "Grodums",     "Kalnājs",    "Porgants",
    "Sukuts",     "Meškūns",     "Rožkalns",    "Mazjānis",    "Latkovskis", "Jankovskis",  "Šileiko",    "Budreiko",
    "Ivanovs",    "Morozovs",    "Logins",      "Gasjūns",     "Pauļuks",    "Sosārs",
};

const std::vector<std::string> latvianFemalesLastNames = {
    "Aigare",     "Alksne",      "Andersone",  "Aspere",     "Auziņa",     "Ābele",       "Āboliņa",   "Āboltiņa",
    "Balode",     "Beļavske",    "Bergmane",   "Bērziņa",    "Bērzīte",    "Birziņa",     "Birzniece", "Bīriņa",
    "Blaua",      "Blekte",      "Breņķe",     "Briede",     "Brunkeviča", "Buile",       "Buša",      "Cauna",
    "Cālīte",     "Cīrule",      "Čudara",     "Danielsone", "Dīriķe",     "Dombrovska",  "Dreimane",  "Dzene",
    "Eglīte",     "Endziņa",     "Fogele",     "Freimane",   "Gaile",      "Gailīte",     "Gibala",    "Graudiņa",
    "Gribuste",   "Grīnberga",   "Grūba",      "Jansone",    "Jēkabsone",  "Jukuma",      "Kalēja",    "Kalniņa",
    "Karlsone",   "Kauliņa",     "Kārkliņa",   "Kļaviņa",    "Koha",       "Koka",        "Krance",    "Krastiņa",
    "Kraule",     "Krauze",      "Krēsliņa",   "Krieviņa",   "Krieva",     "Kronberga",   "Krūmiņa",   "Kulmane",
    "Laiviņa",    "Landmane",    "Lapiņa",     "Lapsiņa",    "Lasmane",    "Lauberga",    "Lāce",      "Legzdiņa",
    "Lielmane",   "Liepiņa",     "Līce",       "Līdaka",     "Loča",       "Lodiņa",      "Lūse",      "Matisone",
    "Medne",      "Meiere",      "Mekša",      "Meldere",    "Melngaile",  "Mihailova",   "Miķelsone", "Niedra",
    "Ose",        "Ostrovska",   "Ozere",      "Ozoliņa",    "Ozola",      "Paltere",     "Pavlovska", "Pence",
    "Petrovska",  "Pērkona",     "Pētersone",  "Podziņa",    "Pole",       "Pretkalniņa", "Priedīte",  "Puķīte",
    "Putniņa",    "Riekstiņa",   "Romanovska", "Rozenbaha",  "Rozīte",     "Rubene",      "Rudzīte",   "Runce",
    "Salmiņa",    "Seržante",    "Sietniece",  "Siliņa",     "Sīle",       "Skudra",      "Smuģe",     "Sproģe",
    "Sprūde",     "Strautiņa",   "Strautmane", "Strazdiņa",  "Širova",     "Šīrante",     "Šmite",     "Šteina",
    "Tālberga",   "Teicāne",     "Tiltiņa",    "Tīrele",     "Tuča",       "Ūdre",        "Valtere",   "Vasile",
    "Vecumniece", "Veinberga",   "Veisa",      "Vilka",      "Vilsone",    "Viļuma",      "Vintere",   "Vītiņa",
    "Vītoliņa",   "Vītola",      "Vītuma",     "Volle",      "Zariņa",     "Zālīte",      "Zeidmane",  "Zeltiņa",
    "Ziemele",    "Zībere",      "Zunda",      "Zvaigzne",   "Zvejniece",  "Zvinele",     "Muceniece", "Dzirkale",
    "Arāja",      "Sējēja",      "Podniece",   "Ratniece",   "Deģe",       "Bondare",     "Sondore",   "Namiķe",
    "Jumiķe",     "Muižniece",   "Bajāre",     "Ķēniņa",     "Ķeizare",    "Barone",      "Vaivade",   "Zviedre",
    "Vāciete",    "Lejiņa",      "Vanaga",     "Celma",      "Liepa",      "Kalna",       "Celmiņa",   "Lejniece",
    "Biseniece",  "Kurzemniece", "Sauliete",   "Pakalniete", "Pridāne",    "Groduma",     "Kalnāja",   "Porgante",
    "Sukute",     "Meškūna",     "Rožkalne",   "Mazjāne",    "Latkovska",  "Jankovska",   "Šileiko",   "Budreiko",
    "Ivanova",    "Morozova",    "Logina",     "Gasjūne",    "Pauļuka",    "Sosāre",      "Meškūne",
};
}
