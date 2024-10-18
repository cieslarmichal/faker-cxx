#include <algorithm>
#include <string_view>

#include "gtest/gtest.h"

#include "esport_data.h"
#include "faker-cxx/esport.h"

using namespace ::testing;
using namespace faker;
using namespace faker::esport;

namespace
{
const struct EsportDefinition& getEsportDefinition(Locale locale)
{
    switch (locale)
    {
    default:
        return enUSEsportDefinition;
    }
}
}

class EsportTest : public TestWithParam<Locale>
{
public:
};

TEST_F(EsportTest, shouldGeneratePlayer)
{
    const auto locale = GetParam();
    
    const auto& esportDefinition = getEsportDefinition(locale);

    const auto generatedPlayer = player(locale);

    ASSERT_TRUE(std::ranges::any_of(esportDefinition.players, [generatedPlayer](const std::string_view& player)
                                    { return generatedPlayer == player; }));
}

TEST_F(EsportTest, shouldGenerateTeam)
{
    const auto locale = GetParam();

    const auto& esportDefinition = getEsportDefinition(locale);

    const auto generatedTeam = team(locale);

    ASSERT_TRUE(
        std::ranges::any_of(esportDefinition.teams, [generatedTeam](const std::string_view& team) { return generatedTeam == team; }));
}

TEST_F(EsportTest, shouldGenerateLeague)
{
    const auto locale = GetParam();

    const auto& esportDefinition = getEsportDefinition(locale);

    const auto generatedLeague = league(locale);

    ASSERT_TRUE(std::ranges::any_of(esportDefinition.leagues, [generatedLeague](const std::string_view& league)
                                    { return generatedLeague == league; }));
}

TEST_F(EsportTest, shouldGenerateEvent)
{
    const auto locale = GetParam();

    const auto& esportDefinition = getEsportDefinition(locale);

    const auto generatedEvent = event(locale);

    ASSERT_TRUE(std::ranges::any_of(esportDefinition.events, [generatedEvent](const std::string_view& event)
                                    { return generatedEvent == event; }));
}

TEST_F(EsportTest, shouldGenerateGame)
{
    const auto locale = GetParam();

    const auto& esportDefinition = getEsportDefinition(locale);

    const auto generatedGame = game(locale);

    ASSERT_TRUE(
        std::ranges::any_of(esportDefinition.games, [generatedGame](const std::string_view& game) { return generatedGame == game; }));
}
