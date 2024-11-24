#pragma once

#include <array>
#include <map>
#include <span>
#include <string>
#include <string_view>

namespace faker::sport
{
struct SportDefinition
{
    std::span<const std::string_view> femaleAthletes;
    std::span<const std::string_view> maleAthletes;
    std::span<const std::string_view> soccerTeams;
    std::span<const std::string_view> sportEvents;
    std::span<const std::string_view> sportNames;
};

//"en_US"

const auto enUsFemaleAthletes = std::to_array<std::string_view>({
    "Alex Morgan",
    "Jackie Joyner-Kersee",
    "Lindsey Vonn",
    "Martina Navratilova",
    "Mia Hamm",
    "Nadia Comăneci",
    "Ronda Rousey",
    "Serena Williams",
    "Simone Biles",
    "Steffi Graf",
});

const auto enUSMaleAthletes = std::to_array<std::string_view>({
    "Cristiano Ronaldo",
    "Kobe Bryant",
    "LeBron James",
    "Lionel Messi",
    "Michael Jordan",
    "Michael Phelps",
    "Muhammad Ali",
    "Roger Federer",
    "Tom Brady",
    "Usain Bolt",
});

const auto enUSSoccerTeams = std::to_array<std::string_view>({
    "AC Milan",
    "Chelsea FC",
    "FC Barcelona",
    "FC Bayern Munich",
    "Inter Milan",
    "Juventus FC",
    "Liverpool FC",
    "Manchester United FC",
    "Paris Saint-Germain FC",
    "Real Madrid CF",
});

const auto enUSSportEvents = std::to_array<std::string_view>({
    "ICC Cricket World Cup",
    "NBA Finals",
    "Olympics",
    "Rugby World Cup",
    "Super Bowl",
    "The Masters",
    "UEFA Champions League",
    "Wimbledon",
    "World Athletics Championship",
    "World Cup",
});

const auto enUSSportNames = std::to_array<std::string_view>({
    "American Football",
    "Baseball",
    "Basketball",
    "Cricket",
    "Golf",
    "Rugby",
    "Soccer",
    "Table Tennis",
    "Tennis",
    "Volleyball",
});

const SportDefinition enUSSportDefinition = {.femaleAthletes = enUsFemaleAthletes,
                                             .maleAthletes = enUSMaleAthletes,
                                             .soccerTeams = enUSSoccerTeams,
                                             .sportEvents = enUSSportEvents,
                                             .sportNames = enUSSportNames};

//"es_AR"

const auto esARFemaleAthletes = std::to_array<std::string_view>({
    "Gabriela Sabatini",
    "Gisela Dulko",
    "Paula Pareto",
    "Luciana Aymar",
    "Georgina Bardach",
    "Sabrina Ameghino",
    "Noemí Simonetto",
    "Micaela Retegui",
    "Cecilia Carranza Saroli",
    "VAnina Onetto",
});

const auto esARMaleAthletes = std::to_array<std::string_view>({
    "Emanuel Ginóbili",
    "Lionel Messi",
    "Diego Maradona",
    "Carlos Monzón",
    "Guillermo Vilas",
    "Carlos Reutemann",
    "Nicolino Locche",
    "Carlos Teves",
    "Walter Pérez",
    "Sebastián Crismanich",
});


const auto esARSoccerTeams = std::to_array<std::string_view>({
    "Boca Juniors",
    "River Plate",
    "Colon Santa Fe",
    "Independiente",
    "Rosario Central",
    "Racing",
    "San Lorenzo",
    "Newels Old Boys",
    "Velez Sarfield",
    "Talleres",
});


const auto esARSportEvents = std::to_array<std::string_view>({
    "Superliga",
    "Copa Argentina",
    "Primera B Nacional",
    "Liga Nacional de Basquet",
    "Turismo Carretera",
    "Copa Libertadores",
    "Liga de Voley Argentina",
    "Argentina Open Tennis",
    "Juegos Argentinos de Alto Rendimiento",
    "MotoGP",
});

const auto esARSportNames = std::to_array<std::string_view>({
    "Futbol",
    "Baseball",
    "Basquet",
    "Cricket",
    "Golf",
    "Rugby",
    "Polo",
    "Ping Pong",
    "Tenis",
    "Voley",
});

const SportDefinition esARSportDefinition = {.femaleAthletes = esARFemaleAthletes,
                                             .maleAthletes = esARMaleAthletes,
                                             .soccerTeams = esARSoccerTeams,
                                             .sportEvents = esARSportEvents,
                                             .sportNames = esARSportNames};

//"pt-br"

const auto ptBRFemaleAthletes = std::to_array<std::string_view>({
    "Amanda Nunes",
    "Natahsa Ferreira",
    "Paula Pareto",
    "Larissa França",
    "Juliana Veloso",
    "Leticia Santos",
    "Sissi",
    "Thaísa",
    "Marta Vieira",
});

const auto ptBRMaleAthletes = std::to_array<std::string_view>({
    "Pele",
    "Ayrton Senna",
    "Nelson Piquet",
    "Ronaldo",
    "Ronaldinho",
    "Guga Kuerten",
    "Kaka",
    "Neymar",
    "Garrincha",
    "Socrates",
});

const auto ptBRSoccerTeams = std::to_array<std::string_view>({
    "Sao Paulo",
    "Flamengo",
    "Inter Porto Alegre",
    "Santos",
    "Cruzeiro",
    "Corinthians",
    "Gremio",
    "Atletico Mineiro",
    "Vasco da Gamma",
    "Botafogo",
});

const auto ptBRSportEvents = std::to_array<std::string_view>({
    "Brasileirao",
    "Campeonato Paulista",
    "Copa Brasil",
    "GP Interlagos",
    "ATP 500 Rio de Janeiro",
    "ATP 250 Sao Paulo",
    "Libertadores de América",
    "MotoGP Rio do Janeiro",
});

const auto ptBRSportNames = std::to_array<std::string_view>({
    "Futebol",
    "Handebol",
    "Tênis",
    "boxe", 
    "Golf",
    "rúgbi",
    "Polo",
    "Natação",
    "Artes marciais",
    "Voleibol",
});

const SportDefinition ptBRSportDefinition = {.femaleAthletes = ptBRFemaleAthletes,
                                             .maleAthletes = ptBRMaleAthletes,
                                             .soccerTeams = ptBRSoccerTeams,
                                             .sportEvents = ptBRSportEvents,
                                             .sportNames = ptBRSportNames};


// General structure containing all the definitions   

const std::map<faker::Locale, const SportDefinition> sportMapSpan({
    {faker::Locale::en_US, {enUSSportDefinition}},
    {faker::Locale::es_AR, {esARSportDefinition}},
    {faker::Locale::pt_BR, {ptBRSportDefinition}},
});

}
