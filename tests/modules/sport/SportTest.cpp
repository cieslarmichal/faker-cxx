#include "faker-cxx/Sport.h"

#include <algorithm>
#include <string>

#include "gtest/gtest.h"

#include "data/FemaleAthletes.h"
#include "data/MaleAthletes.h"
#include "data/SoccerTeams.h"
#include "data/SportEvents.h"
#include "data/SportNames.h"

using namespace ::testing;
using namespace faker;

class SportTest : public Test
{
public:
};

TEST_F(SportTest, shouldGenerateSport)
{
    std::string generatedSport = Sport::sport();

    ASSERT_TRUE(std::ranges::any_of(sportNames,
                                    [generatedSport](const std::string& sport) { return sport == generatedSport; }));
}

TEST_F(SportTest, shouldGenerateSoccerTeam)
{
    std::string generatedSoccerTeam = Sport::soccerTeam();

    ASSERT_TRUE(std::ranges::any_of(soccerTeams, [generatedSoccerTeam](const std::string& soccerTeam)
                                    { return soccerTeam == generatedSoccerTeam; }));
}

TEST_F(SportTest, shouldGenerateSportEvent)
{
    std::string generatedSportEvent = Sport::sportEvent();

    ASSERT_TRUE(std::ranges::any_of(sportEvents, [generatedSportEvent](const std::string& sportEvent)
                                    { return sportEvent == generatedSportEvent; }));
}

TEST_F(SportTest, shouldGenerateMaleAthlete)
{
    std::string generatedMaleAthlete = Sport::maleAthlete();

    ASSERT_TRUE(std::ranges::any_of(maleAthletes, [generatedMaleAthlete](const std::string& maleAthlete)
                                    { return maleAthlete == generatedMaleAthlete; }));
}

TEST_F(SportTest, shouldGenerateFemaleAthlete)
{
    std::string generatedFemaleAthlete = Sport::femaleAthlete();

    ASSERT_TRUE(std::ranges::any_of(femaleAthletes, [generatedFemaleAthlete](const std::string& femaleAthlete)
                                    { return femaleAthlete == generatedFemaleAthlete; }));
}
