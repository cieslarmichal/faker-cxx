#include "faker-cxx/Hacker.h"

#include <algorithm>
#include <string>

#include "gtest/gtest.h"

#include "data/Abbreviations.h"
#include "data/Adjectives.h"
#include "data/Ingverbs.h"
#include "data/Nouns.h"
#include "data/Verbs.h"

using namespace ::testing;
using namespace faker;

class HackerTest : public Test
{
public:
};

TEST_F(HackerTest, shouldGenerateAbbreviation)
{
    std::string generatedAbbreviation = Hacker::abbreviation();

    ASSERT_TRUE(std::ranges::any_of(abbreviations, [generatedAbbreviation](const std::string& abbreviation)
                                    { return abbreviation == generatedAbbreviation; }));
}

TEST_F(HackerTest, shouldGenerateAdjective)
{
    std::string generatedAdjective = Hacker::adjective();

    ASSERT_TRUE(std::ranges::any_of(adjectives, [generatedAdjective](const std::string& adjective)
                                    { return adjective == generatedAdjective; }));
}

TEST_F(HackerTest, shouldGenerateNoun)
{
    std::string generatedNoun = Hacker::noun();

    ASSERT_TRUE(std::ranges::any_of(nouns, [generatedNoun](const std::string& noun) { return noun == generatedNoun; }));
}

TEST_F(HackerTest, shouldGenerateVerb)
{
    std::string generatedVerb = Hacker::verb();

    ASSERT_TRUE(std::ranges::any_of(verbs, [generatedVerb](const std::string& verb) { return verb == generatedVerb; }));
}

TEST_F(HackerTest, shouldGenerateIngverb)
{
    std::string generatedIngverb = Hacker::ingverb();

    ASSERT_TRUE(std::ranges::any_of(ingverbs, [generatedIngverb](const std::string& ingverb)
                                    { return ingverb == generatedIngverb; }));
}

TEST_F(HackerTest, shouldGeneratePhrase)
{
    std::string generatedPhrase = Hacker::phrase();
    bool hasAdjective, hasNoun, hasVerb, hasAbbreviation;
    hasAdjective = hasNoun = hasVerb = hasAbbreviation = false;

    for (const std::string& adj : adjectives)
    {
        if (generatedPhrase.find(adj) != std::string::npos)
        {
            hasAdjective = true;
            break;
        }
    }

    for (const std::string& noun : nouns)
    {
        if (generatedPhrase.find(noun) != std::string::npos)
        {
            hasNoun = true;
            break;
        }
    }

    for (const std::string& verb : verbs)
    {
        if (generatedPhrase.find(verb) != std::string::npos)
        {
            hasVerb = true;
            break;
        }
    }

    for (const std::string& abbreviation : abbreviations)
    {
        if (generatedPhrase.find(abbreviation) != std::string::npos)
        {
            hasAbbreviation = true;
            break;
        }
    }

    ASSERT_TRUE((hasAdjective && hasNoun && hasVerb && hasAbbreviation));
}
