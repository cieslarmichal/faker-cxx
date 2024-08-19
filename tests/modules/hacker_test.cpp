#include <algorithm>
#include <string>
#include <string_view>

#include "gtest/gtest.h"

#include "faker-cxx/hacker.h"
#include "hacker_data.h"

using namespace ::testing;
using namespace faker;
using namespace faker::hacker;

class HackerTest : public Test
{
public:
};

TEST_F(HackerTest, shouldGenerateAbbreviation)
{
    const auto generatedAbbreviation = abbreviation();

    ASSERT_TRUE(std::ranges::any_of(abbreviations, [generatedAbbreviation](const std::string_view& abbreviation)
                                    { return abbreviation == generatedAbbreviation; }));
}

TEST_F(HackerTest, shouldGenerateAdjective)
{
    const auto generatedAdjective = adjective();

    ASSERT_TRUE(std::ranges::any_of(adjectives, [generatedAdjective](const std::string_view& adjective)
                                    { return adjective == generatedAdjective; }));
}

TEST_F(HackerTest, shouldGenerateNoun)
{
    const auto generatedNoun = noun();

    ASSERT_TRUE(
        std::ranges::any_of(nouns, [generatedNoun](const std::string_view& noun) { return noun == generatedNoun; }));
}

TEST_F(HackerTest, shouldGenerateVerb)
{
    const auto generatedVerb = verb();

    ASSERT_TRUE(
        std::ranges::any_of(verbs, [generatedVerb](const std::string_view& verb) { return verb == generatedVerb; }));
}

TEST_F(HackerTest, shouldGenerateIngverb)
{
    const auto generatedIngverb = ingverb();

    ASSERT_TRUE(std::ranges::any_of(ingverbs, [generatedIngverb](const std::string_view& ingverb)
                                    { return ingverb == generatedIngverb; }));
}

TEST_F(HackerTest, shouldGeneratePhrase)
{
    const auto generatedPhrase = phrase();
    bool hasAdjective, hasNoun, hasVerb, hasAbbreviation, hasIngverb;
    hasAdjective = hasNoun = hasVerb = hasAbbreviation = hasIngverb = false;

    for (const std::string_view& adj : adjectives)
    {
        if (generatedPhrase.find(adj) != std::string::npos)
        {
            hasAdjective = true;
            break;
        }
    }

    for (const std::string_view& noun : nouns)
    {
        if (generatedPhrase.find(noun) != std::string::npos)
        {
            hasNoun = true;
            break;
        }
    }

    for (const std::string_view& verb : verbs)
    {
        if (generatedPhrase.find(verb) != std::string::npos)
        {
            hasVerb = true;
            break;
        }
    }

    for (const std::string_view& abbreviation : abbreviations)
    {
        if (generatedPhrase.find(abbreviation) != std::string::npos)
        {
            hasAbbreviation = true;
            break;
        }
    }

    for (const std::string_view& ingverb : ingverbs)
    {
        if (generatedPhrase.find(ingverb) != std::string::npos)
        {
            hasIngverb = true;
            break;
        }
    }

    ASSERT_TRUE((hasAdjective && hasNoun && hasVerb && hasAbbreviation && hasIngverb));
}
