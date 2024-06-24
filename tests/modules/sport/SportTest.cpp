#include "faker-cxx/Sport.h"

#include <algorithm>
#include <string_view>

#include "gtest/gtest.h"

#include "sport/SportData.h"

using namespace ::testing;
using namespace faker;
using namespace faker::Sport;

class SportTest : public Test
{
public:
};

TEST_F(SportTest, shouldGenerateSport)
{
    const auto generatedSport = sport();

    ASSERT_TRUE(std::ranges::any_of(sportNames, [generatedSport](const std::string_view& sport)
                                    { return sport == generatedSport; }));
}

TEST_F(SportTest, shouldGenerateSoccerTeam)
{
    const auto generatedSoccerTeam = soccerTeam();

    ASSERT_TRUE(std::ranges::any_of(soccerTeams, [generatedSoccerTeam](const std::string_view& soccerTeam)
                                    { return soccerTeam == generatedSoccerTeam; }));
}

TEST_F(SportTest, shouldGenerateSportEvent)
{
    const auto generatedSportEvent = sportEvent();

    ASSERT_TRUE(std::ranges::any_of(sportEvents, [generatedSportEvent](const std::string_view& sportEvent)
                                    { return sportEvent == generatedSportEvent; }));
}

TEST_F(SportTest, shouldGenerateMaleAthlete)
{
    const auto generatedMaleAthlete = maleAthlete();

    ASSERT_TRUE(std::ranges::any_of(maleAthletes, [generatedMaleAthlete](const std::string_view& maleAthlete)
                                    { return maleAthlete == generatedMaleAthlete; }));
}

TEST_F(SportTest, shouldGenerateFemaleAthlete)
{
    const auto generatedFemaleAthlete = femaleAthlete();

    ASSERT_TRUE(std::ranges::any_of(femaleAthletes,
                                    [generatedFemaleAthlete](const std::string_view& femaleAthlete)
                                    { return femaleAthlete == generatedFemaleAthlete; }));
}
