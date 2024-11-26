#include <algorithm>
#include <string_view>

#include "gtest/gtest.h"

#include "faker-cxx/sport.h"
#include "sport_data.h"
#include "locale.h"

using namespace ::testing;
using namespace faker;
using namespace faker::sport;


namespace
{

const struct SportDefinition& getSportMapDefinition(Locale locale)
{
    if (sportMapSpan.find(locale) == sportMapSpan.end())
    {
        return sportMapSpan.at(Locale::en_US);
    }
    else
    {
        return sportMapSpan.at(locale);
    }
}
}

class SportTestLocale : public TestWithParam<Locale>
{
public:
};

TEST_P(SportTestLocale, shouldGenerateSportLocale)
{
    auto extra = GetParam();
    auto sportDefinition = getSportMapDefinition(extra);
    const auto generatedSport = faker::sport::sportName(extra);
    

    ASSERT_TRUE(std::ranges::any_of(sportDefinition.sportNames, [generatedSport](const std::string_view& sport)
                                    { return sport == generatedSport; }));
}
TEST_P(SportTestLocale, shouldGenerateFemaleAthleteLocale)
{
    auto extra = GetParam();
    auto sportDefinition = getSportMapDefinition(extra);

    const auto generatedFemaleAthlete = femaleAthlete(extra);

    ASSERT_TRUE(std::ranges::any_of(sportDefinition.femaleAthletes, [generatedFemaleAthlete](const std::string_view& femaleAthlete)
                                    { return femaleAthlete == generatedFemaleAthlete; }));
}
TEST_P(SportTestLocale, shouldGenerateMaleAthleteLocale)
{    
    auto extra = GetParam();
    auto sportDefinition = getSportMapDefinition(extra);
    const auto generatedMaleAthlete = maleAthlete(extra);

    ASSERT_TRUE(std::ranges::any_of(sportDefinition.maleAthletes, [generatedMaleAthlete](const std::string_view& maleAthlete)
                                    { return maleAthlete == generatedMaleAthlete; }));
}


TEST_P(SportTestLocale, shouldGenerateSoccerTeamLocale)
{
    auto extra = GetParam();
    auto sportDefinition = getSportMapDefinition(extra);
    const auto generatedSoccerTeam = soccerTeam(extra);

    ASSERT_TRUE(std::ranges::any_of(sportDefinition.soccerTeams, [generatedSoccerTeam](const std::string_view& soccerTeam)
                                    { return soccerTeam == generatedSoccerTeam; }));
}

TEST_P(SportTestLocale, shouldGenerateSportEventLocale)
{
    auto extra = GetParam();
    auto sportDefinition = getSportMapDefinition(extra);
    const auto generatedSportEvent = sportEvent(extra);

    ASSERT_TRUE(std::ranges::any_of(sportDefinition.sportEvents, [generatedSportEvent](const std::string_view& sportEvent)
                                    { return sportEvent == generatedSportEvent; }));
}


INSTANTIATE_TEST_SUITE_P(testSportByLocale, SportTestLocale, ValuesIn(locales),
                         [](const TestParamInfo<Locale>& paramInfo) { return toString(paramInfo.param); });
