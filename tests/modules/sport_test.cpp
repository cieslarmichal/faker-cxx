#include "../test_helpers.h"
#include <algorithm>
#include <faker/sport.h>
#include <modules/sport_data.h>
#include <string>

using namespace ::testing;
using namespace faker;

class SportTest : public Test {
public:
};

TEST_F(SportTest, shouldGenerateSport)
{
    std::string generatedSport = sport::sport();

    ASSERT_TRUE(faker::testing::any_of(sportNames,
        [generatedSport](const std::string& sport) { return sport == generatedSport; }));
}

TEST_F(SportTest, shouldGenerateSoccerTeam)
{
    std::string generatedSoccerTeam = sport::soccerTeam();

    ASSERT_TRUE(
        faker::testing::any_of(soccerTeams, [generatedSoccerTeam](const std::string& soccerTeam) {
            return soccerTeam == generatedSoccerTeam;
        }));
}

TEST_F(SportTest, shouldGenerateSportEvent)
{
    std::string generatedSportEvent = sport::sportEvent();

    ASSERT_TRUE(
        faker::testing::any_of(sportEvents, [generatedSportEvent](const std::string& sportEvent) {
            return sportEvent == generatedSportEvent;
        }));
}

TEST_F(SportTest, shouldGenerateMaleAthlete)
{
    std::string generatedMaleAthlete = sport::maleAthlete();

    ASSERT_TRUE(faker::testing::any_of(
        maleAthletes, [generatedMaleAthlete](const std::string& maleAthlete) {
            return maleAthlete == generatedMaleAthlete;
        }));
}

TEST_F(SportTest, shouldGenerateFemaleAthlete)
{
    std::string generatedFemaleAthlete = sport::femaleAthlete();

    ASSERT_TRUE(faker::testing::any_of(
        femaleAthletes, [generatedFemaleAthlete](const std::string& femaleAthlete) {
            return femaleAthlete == generatedFemaleAthlete;
        }));
}
