#include "sport_data.h"

namespace faker::sport::data {
const std::array<std::string_view, 10> female_athletes = {
    "Serena Williams",
    "Simone Biles",
    "Mia Hamm",
    "Ronda Rousey",
    "Lindsey Vonn",
    "Alex Morgan",
    "Martina Navratilova",
    "Jackie Joyner-Kersee",
    "Nadia Comăneci",
    "Steffi Graf",
};

const std::array<std::string_view, 10> male_athletes = {
    "Lionel Messi",
    "Cristiano Ronaldo",
    "LeBron James",
    "Usain Bolt",
    "Michael Phelps",
    "Roger Federer",
    "Kobe Bryant",
    "Tom Brady",
    "Muhammad Ali",
    "Michael Jordan",
};

const std::array<std::string_view, 10> soccer_teams {
    "FC Barcelona",
    "Real Madrid CF",
    "Manchester United FC",
    "Liverpool FC",
    "FC Bayern Munich",
    "AC Milan",
    "Inter Milan",
    "Juventus FC",
    "Paris Saint-Germain FC",
    "Chelsea FC",
};

const std::array<std::string_view, 10> sport_events = {
    "World Cup",
    "Olympics",
    "Super Bowl",
    "World Athletics Championship",
    "UEFA Champions League",
    "NBA Finals",
    "Wimbledon",
    "ICC Cricket World Cup",
    "The Masters",
    "Rugby World Cup",
};

const std::array<std::string_view, 10> sport_names = {
    "Soccer",
    "Cricket",
    "Basketball",
    "Tennis",
    "Volleyball",
    "Table Tennis",
    "Golf",
    "Baseball",
    "American Football",
    "Rugby",
};
}
