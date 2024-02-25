#include "test_helpers.h"
#include <iostream>
#include <modules/sport_data.h>

using namespace faker::sport::data;

#define PRINT_ARRAY_SIZE(name)                                                                     \
    std::cout << "extern const std::array<std::string_view, " << name.size() << "> " << (#name)    \
              << ";" << std::endl

TEST(BasicTest, printsArraySizes)
{
    PRINT_ARRAY_SIZE(femaleAthletes);
    PRINT_ARRAY_SIZE(maleAthletes);
    PRINT_ARRAY_SIZE(soccerTeams);
    PRINT_ARRAY_SIZE(sportEvents);
    PRINT_ARRAY_SIZE(sportNames);
}
