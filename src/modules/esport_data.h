#pragma once

#include <array>
#include <span>
#include <string_view>

namespace faker::esport
{
struct EsportDefinition
{
    std::span<const std::string_view> players;
    std::span<const std::string_view> teams;
    std::span<const std::string_view> leagues;
    std::span<const std::string_view> events;
    std::span<const std::string_view> games;
};

const auto enUSPlayers = std::to_array<std::string_view>(
    {"Adam",    "Alvaro",  "Brokenblade", "Canna",     "Caps",       "Carzzy",    "Closer",    "Comp",   "Elyoya",
     "Finn",    "Flakked", "Fresskowy",   "Hans Sama", "Humanoid",   "Hylissang", "Ice",       "IgNar",  "Irrelevant",
     "Isma",    "Jackies", "Jankos",      "Juhan",     "Jun",        "Labrov",    "Larssen",   "Luon",   "Lyncas",
     "Markoon", "Mikyx",   "Myrwn",       "Nisqy",     "Noah",       "Oscarinin", "Patrik",    "Photon", "Rahel",
     "Razork",  "Sheo",    "Supa",        "Targamas",  "Th3Antonio", "Trymbi",    "Upset",     "Vetheo", "Vladi",
     "Wunder",  "Yike",    "Zoelys",      "Zwyroo",    "nuc",        "Aiming",    "Andil",     "Bdd",    "BeryL",
     "Bulldog", "Calix",   "Callme",      "Canyon",    "Casting",    "Chovy",     "Clear",     "Clozer", "Cuzz",
     "DDoiV",   "Deft",    "Delight",     "DnDn",      "Doran",      "DuDu",      "Duro",      "Envyy",  "Execute",
     "FATE",    "Faker",   "Fisher",      "Frog",      "GuGer",      "Gumayusi",  "Hena",      "Jiwoo",  "Karis",
     "Kellin",  "Keria",   "Kiin",        "Kyeahoo",   "Leaper",     "Lehends",   "Lucid",     "Mihile", "Moham",
     "Morgan",  "Oner",    "Paduck",      "Peanut",    "PerfecT",    "Peyz",      "Pleata",    "Pollu",  "Pullbae",
     "Pyosik",  "Quantum", "Raptor",      "Rascal",    "Samver",     "SeTab",     "ShowMaker", "Sponge", "Sylvie",
     "Teddy",   "Viper",   "Vital",       "YoungJae",  "Zeka",       "Zeus",      "kingen"});

const auto enUSTeams = std::to_array<std::string_view>(
    {"Team Liquid",      "G2 Esports", "OpTic Gaming", "Natus Vincere", "Astralis",    "NRG",
     "7figures Esports", "HEROIC",     "Faze Clan",    "Fnatic",        "Virtus.pro",  "Ninjas in Pyjamas",
     "CompLexity",       "TSM",        "BIG",          "Karmine Corp",  "Cloud9",      "Evil Geniuses",
     "Team VItality",    "Mouz",       "100 Thieves",  "NaVi",          "Team Secret", "Vitality",
     "Gambit Esports",   "BDS",        "Gentle Mates"});

const auto enUSLeagues = std::to_array<std::string_view>(
    {"LEC", "LPL", "LCK", "LCS NA", "LFL", "PUBG Mobile Super League", "VCT", "VCT GC", "F1 Esports Series",
     "Overwatch League", "Superliga", "Prime League", "TCL", "Call of Duty League", "RLCS"});

const auto enUSEvents =
    std::to_array<std::string_view>({"MSI", "EMEA Masters", "League of Legends World Championship", "EWC",
                                     "The International", "Fortnite World Cup", "Six Invitational", "Capcom X Cup",
                                     "VCT Masters"
                                     "RLCS Major",
                                     "IEM"});

const auto enUSGames = std::to_array<std::string_view>({"Valorant", "League Of Legend", "Rocket League", "Fifa",
                                                        "Overwatch", "CSGO", "Fortnite", "Dota 2",
                                                        "Street Fighter,"
                                                        "Apex Legends",
                                                        "TFT", "PUBG", "Call of Duty"});

const EsportDefinition enUSEsportDefinition = {
    .players = enUSPlayers, .teams = enUSTeams, .leagues = enUSLeagues, .events = enUSEvents, .games = enUSGames};
}