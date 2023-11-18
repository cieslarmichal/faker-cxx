#pragma once

#include <string>
#include <vector>

namespace faker
{
const std::vector<std::string> slovenianLastNames{
    "Novak",     "Horvat",     "Krajnc",     "Kovač",     "Korošec",     "Mlakar",    "Kos",        "Vidmar",
    "Golob",     "žagar",      "Hočevar",    "Košir",     "Turk",        "Kralj",     "Zupan",      "Bizjak",
    "Hribar",    "Rozman",     "Zajc",       "Kotnik",    "Oblak",       "Petek",     "Kolar",      "Kastelic",
    "Zupanc",    "Koren",      "Babič",      "Kranjc",    "Medved",      "Majcen",    "Knez",       "Pušnik",
    "Kovačević", "Dolenc",     "Pirc",       "Petrović",  "Hrovat",      "Lah",       "Zadravec",   "Kuhar",
    "Lešnik",    "Bezjak",     "Kokalj",     "Jug",       "Zorko",       "Erjavec",   "Sever",      "Vidovič",
    "Jerman",    "Jereb",      "Bogataj",    "Primožič",  "Jovanović",   "Kosi",      "Hodžić",     "Lesjak",
    "Furlan",    "Lavrič",     "Perko",      "Logar",     "žižek",       "Marković",  "Debeljak",   "Jenko",
    "Krivec",    "Pavlin",     "Vodopivec",  "Zver",      "Rupnik",      "Jarc",      "Kramberger", "Toplak",
    "Breznik",   "Ilić",       "Hribernik",  "Jazbec",    "žibert",      "Marolt",    "Vidic",      "Eržen",
    "Pintar",    "Nikolić",    "Simonič",    "železnik",  "Demšar",      "Blažič",    "Jelen",      "Popović",
    "šinkovec",  "Fras",       "Dolinar",    "Ramšak",    "Hozjan",      "Leban",     "Cerar",      "Hren",
    "Javornik",  "Rus",        "Blatnik",    "Kobal",     "Gorjup",      "Kolenc",    "Podgoršek",  "Savić",
    "Rajh",      "Kokol",      "Koželj",     "Gajšek",    "Mohorič",     "Lazar",     "Nemec",      "Sušnik",
    "Gomboc",    "Mavrič",     "Mrak",       "šmid",      "Rožman",      "Cvetko",    "Pavlović",   "Bajc",
    "Likar",     "Vovk",       "Babić",      "Bevc",      "Tratnik",     "Povše",     "Zakrajšek",  "Begić",
    "Humar",     "Skok",       "Gorenc",     "Hadžić",    "Stopar",      "Rojc",      "Stojanović", "Založnik",
    "Leskovar",  "Sitar",      "Gorišek",    "štrukelj",  "šuligoj",     "Kranjec",   "Fekonja",    "škof",
    "Zorec",     "Romih",      "šuštar",     "Pahor",     "Bračko",      "Pevec",     "šturm",      "Volk",
    "Kukovec",   "Brglez",     "Simčič",     "Dolinšek",  "Kogovšek",    "Križman",   "Bregar",     "Arh",
    "Krašovec",  "Murko",      "Papež",      "Turnšek",   "Bukovec",     "Kosmač",    "Rutar",      "Tomažin",
    "Kramar",    "Starc",      "Vuković",    "Jamnik",    "Hafner",      "Vrhovnik",  "Planinc",    "Dizdarević",
    "Ferk",      "Vončina",    "Ravnikar",   "Bergant",   "Lebar",       "Lipovšek",  "Godec",      "Vuk",
    "Tomić",     "Lončar",     "Praprotnik", "Hojnik",    "Kumer",       "Halilović", "Grošelj",    "Urh",
    "Mlinar",    "Kristan",    "Stanković",  "Habjan",    "Resnik",      "Klemenc",   "Cimerman",   "Balažic",
    "Kalan",     "Cafuta",     "Jeraj",      "Gruden",    "Zalokar",     "Primc",     "Zajec",      "Fabjan",
    "Pirnat",    "Možina",     "Topolovec",  "Zorman",    "Trstenjak",   "Hudorovac", "Kraševec",   "Zalar",
    "Rojko",     "Lampret",    "Peternelj",  "Hvala",     "Gantar",      "Rijavec",   "Grm",        "Roškar",
    "Repnik",    "Kladnik",    "Planinšek",  "Delić",     "Sedej",       "Smrekar",   "Gobec",      "Frelih",
    "Simić",     "Rebernik",   "Lukić",      "šega",      "Ornik",       "Babnik",    "Leskovšek",  "Drnovšek",
    "Mastnak",   "Kušar",      "Hrastnik",   "Pajk",      "Vogrinec",    "Krapež",    "žnidar",     "Avsec",
    "šabić",     "Kocbek",     "Strnad",     "Jović",     "Rogelj",      "Juvan",     "Vesel",      "Knežević",
    "Kotar",     "šubic",      "Mohar",      "Križaj",    "Požar",       "Plohl",     "Mitrović",   "Kopač",
    "Rudolf",    "šket",       "Kržišnik",   "Beganović", "štefančič",   "Dobnik",    "Ristić",     "Kocjan",
    "Bajt",      "Polanec",    "Dežman",     "Lazić",     "Dedić",       "Gashi",     "Avdić",      "Gradišnik",
    "Plevnik",   "Drevenšek",  "Todorović",  "Gorše",     "Sluga",       "Sajovic",   "Smodiš",     "Ocvirk",
    "Bernik",    "Bertoncelj", "Kosec",      "Fajfar",    "Hriberšek",   "Poljanšek", "Jager",      "Slana",
    "Podobnik",  "Malovrh",    "Kmetec",     "Pipan",     "Jelenc",      "Ficko",     "škulj",      "Veber",
    "Peternel",  "Zidar",      "Stropnik",   "Marić",     "Podlesnik",   "Grilc",     "Vodušek",    "Vogrin",
    "Bašić",     "Kenda",      "Kern",       "Tušek",     "Bytyqi",      "Arnuš",     "Stare",      "Pišek",
    "Plut",      "Nagode",     "Hajdinjak",  "Zagorc",    "Kostanjevec", "Klinc",     "Mulec",      "Benko",
    "Laznik",    "žitnik",     "Janković",   "Mali",      "Oman",        "Fink",      "Ogrizek",    "Mihelčič",
    "Bajec",     "Pivk",       "Skubic",     "Kočar",     "Virant",      "Oražem",    "Boštjančič", "Grobelnik",
    "Markelj",   "Tomše",      "Bratuša",    "Saje",      "Makovec",     "Križan",
};
}
