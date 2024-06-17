#include "faker-cxx/Sport.h"

#include <algorithm>
#include <string_view>

#include "gtest/gtest.h"

#include "sport/SportData.h"

using namespace ::testing;
using namespace faker;

class SportTest : public Test
{
public:
};

TEST_F(SportTest, shouldGenerateSport)
{
    const auto generatedSport = Sport::sport();

    ASSERT_TRUE(std::ranges::any_of(sport::sportNames, [generatedSport](const std::string_view& sport)
                                    { return sport == generatedSport; }));
}

TEST_F(SportTest, shouldGenerateSoccerTeam)
{
    const auto generatedSoccerTeam = Sport::soccerTeam();

    ASSERT_TRUE(std::ranges::any_of(sport::soccerTeams, [generatedSoccerTeam](const std::string_view& soccerTeam)
                                    { return soccerTeam == generatedSoccerTeam; }));
}

TEST_F(SportTest, shouldGenerateSportEvent)
{
    const auto generatedSportEvent = Sport::sportEvent();

    ASSERT_TRUE(std::ranges::any_of(sport::sportEvents, [generatedSportEvent](const std::string_view& sportEvent)
                                    { return sportEvent == generatedSportEvent; }));
}

TEST_F(SportTest, shouldGenerateMaleAthlete)
{
    const auto generatedMaleAthlete = Sport::maleAthlete();

    ASSERT_TRUE(std::ranges::any_of(sport::maleAthletes, [generatedMaleAthlete](const std::string_view& maleAthlete)
                                    { return maleAthlete == generatedMaleAthlete; }));
}

TEST_F(SportTest, shouldGenerateFemaleAthlete)
{
    const auto generatedFemaleAthlete = Sport::femaleAthlete();

    ASSERT_TRUE(std::ranges::any_of(sport::femaleAthletes,
                                    [generatedFemaleAthlete](const std::string_view& femaleAthlete)
                                    { return femaleAthlete == generatedFemaleAthlete; }));
}
