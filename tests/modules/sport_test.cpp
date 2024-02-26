#include "../test_helpers.h"
#include <faker/sport.h>
#include <modules/sport_data.h>

using namespace faker;

TEST(SportTest, shouldGenerateSport)
{
    auto generatedSport = sport::sport();

    FAKER_EXPECT_CONTAINER_CONTAINS(sport::data::sportNames, generatedSport);
}

TEST(SportTest, shouldGenerateSoccerTeam)
{
    auto generatedSoccerTeam = sport::soccer_team();

    FAKER_EXPECT_CONTAINER_CONTAINS(sport::data::soccerTeams, generatedSoccerTeam);
}

TEST(SportTest, shouldGenerateSportEvent)
{
    auto generatedSportEvent = sport::sport_event();

    FAKER_EXPECT_CONTAINER_CONTAINS(sport::data::sportEvents, generatedSportEvent);
}

TEST(SportTest, shouldGenerateMaleAthlete)
{
    auto generatedMaleAthlete = sport::male_athlete();

    FAKER_EXPECT_CONTAINER_CONTAINS(sport::data::maleAthletes, generatedMaleAthlete);
}

TEST(SportTest, shouldGenerateFemaleAthlete)
{
    auto generatedFemaleAthlete = sport::female_athlete();

    FAKER_EXPECT_CONTAINER_CONTAINS(sport::data::femaleAthletes, generatedFemaleAthlete);
}
