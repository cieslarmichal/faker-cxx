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
    auto generatedSoccerTeam = sport::soccerTeam();

    FAKER_EXPECT_CONTAINER_CONTAINS(sport::data::soccerTeams, generatedSoccerTeam);
}

TEST(SportTest, shouldGenerateSportEvent)
{
    auto generatedSportEvent = sport::sportEvent();

    FAKER_EXPECT_CONTAINER_CONTAINS(sport::data::sportEvents, generatedSportEvent);
}

TEST(SportTest, shouldGenerateMaleAthlete)
{
    auto generatedMaleAthlete = sport::maleAthlete();

    FAKER_EXPECT_CONTAINER_CONTAINS(sport::data::maleAthletes, generatedMaleAthlete);
}

TEST(SportTest, shouldGenerateFemaleAthlete)
{
    auto generatedFemaleAthlete = sport::femaleAthlete();

    FAKER_EXPECT_CONTAINER_CONTAINS(sport::data::femaleAthletes, generatedFemaleAthlete);
}
