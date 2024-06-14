#include "SportData.h"

#include <array>
#include <string_view>

namespace faker::sport
{
const std::array<std::string_view, 10> femaleAthletes = {
    "Alex Morgan",    "Jackie Joyner-Kersee", "Lindsey Vonn",    "Martina Navratilova", "Mia Hamm",
    "Nadia Comăneci", "Ronda Rousey",         "Serena Williams", "Simone Biles",        "Steffi Graf"};

const std::array<std::string_view, 10> maleAthletes = {
    "Cristiano Ronaldo", "Kobe Bryant",  "LeBron James",  "Lionel Messi", "Michael Jordan",
    "Michael Phelps",    "Muhammad Ali", "Roger Federer", "Tom Brady",    "Usain Bolt"};

const std::array<std::string_view, 10> soccerTeams = {
    "AC Milan",    "Chelsea FC",   "FC Barcelona",         "FC Bayern Munich",       "Inter Milan",
    "Juventus FC", "Liverpool FC", "Manchester United FC", "Paris Saint-Germain FC", "Real Madrid CF"};

const std::array<std::string_view, 10> sportEvents = {"ICC Cricket World Cup",
                                                      "NBA Finals",
                                                      "Olympics",
                                                      "Rugby World Cup",
                                                      "Super Bowl",
                                                      "The Masters",
                                                      "UEFA Champions League",
                                                      "Wimbledon",
                                                      "World Athletics Championship",
                                                      "World Cup"};

const std::array<std::string_view, 10> sportNames = {
    "American Football", "Baseball", "Basketball", "Cricket", "Golf", "Rugby", "Soccer",
    "Table Tennis",      "Tennis",   "Volleyball"};

}
