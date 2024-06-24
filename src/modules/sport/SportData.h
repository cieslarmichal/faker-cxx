#pragma once

#include <array>
#include <string>

namespace faker::Sport
{
const auto femaleAthletes = std::to_array<std::string_view>({
    "Alex Morgan",    "Jackie Joyner-Kersee", "Lindsey Vonn",    "Martina Navratilova", "Mia Hamm",
    "Nadia Comăneci", "Ronda Rousey",         "Serena Williams", "Simone Biles",        "Steffi Graf",
});

const auto maleAthletes = std::to_array<std::string_view>({
    "Cristiano Ronaldo", "Kobe Bryant",  "LeBron James",  "Lionel Messi", "Michael Jordan",
    "Michael Phelps",    "Muhammad Ali", "Roger Federer", "Tom Brady",    "Usain Bolt",
});

const auto soccerTeams = std::to_array<std::string_view>({
    "AC Milan",    "Chelsea FC",   "FC Barcelona",         "FC Bayern Munich",       "Inter Milan",
    "Juventus FC", "Liverpool FC", "Manchester United FC", "Paris Saint-Germain FC", "Real Madrid CF",
});

const auto sportEvents = std::to_array<std::string_view>({
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

const auto sportNames = std::to_array<std::string_view>({
    "American Football", "Baseball", "Basketball", "Cricket", "Golf", "Rugby", "Soccer",
    "Table Tennis",      "Tennis",   "Volleyball",
});

}
