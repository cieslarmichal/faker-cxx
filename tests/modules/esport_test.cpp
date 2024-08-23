#include <algorithm>
#include <string_view>

#include "gtest/gtest.h"

#include "esport_data.h"
#include "faker-cxx/esport.h"

using namespace ::testing;
using namespace faker::esport;

class EsportTest : public Test
{
public:
};

TEST_F(EsportTest, shouldGeneratePlayer)
{
    const auto generatedPlayer = player();

    ASSERT_TRUE(std::ranges::any_of(players, [generatedPlayer](const std::string_view& player)
                                    { return generatedPlayer == player; }));
}

TEST_F(EsportTest, shouldGenerateTeam)
{
    const auto generatedTeam = team();

    ASSERT_TRUE(
        std::ranges::any_of(teams, [generatedTeam](const std::string_view& team) { return generatedTeam == team; }));
}

TEST_F(EsportTest, shouldGenerateLeague)
{
    const auto generatedLeague = league();

    ASSERT_TRUE(std::ranges::any_of(leagues, [generatedLeague](const std::string_view& league)
                                    { return generatedLeague == league; }));
}

TEST_F(EsportTest, shouldGenerateEvent)
{
    const auto generatedEvent = event();

    ASSERT_TRUE(std::ranges::any_of(events, [generatedEvent](const std::string_view& event)
                                    { return generatedEvent == event; }));
}

TEST_F(EsportTest, shouldGenerateGame)
{
    const auto generatedGame = game();

    ASSERT_TRUE(
        std::ranges::any_of(games, [generatedGame](const std::string_view& game) { return generatedGame == game; }));
}
