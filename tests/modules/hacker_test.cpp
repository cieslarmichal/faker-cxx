#include "../test_helpers.h"
#include <algorithm>
#include <faker/hacker.h>
#include <modules/hacker_data.h>
#include <string>

using namespace ::testing;
using namespace faker;

class HackerTest : public Test {
public:
};

TEST_F(HackerTest, shouldGenerateAbbreviation)
{
    auto generatedAbbreviation = hacker::abbreviation();

    FAKER_EXPECT_CONTAINS(abbreviations, generatedAbbreviation);
}

TEST_F(HackerTest, shouldGenerateAdjective)
{
    auto generatedAdjective = hacker::adjective();

    FAKER_EXPECT_CONTAINS(adjectives, generatedAdjective);
}

TEST_F(HackerTest, shouldGenerateNoun)
{
    auto generatedNoun = hacker::noun();

    FAKER_EXPECT_CONTAINS(nouns, generatedNoun);
}

TEST_F(HackerTest, shouldGenerateVerb)
{
    auto generatedVerb = hacker::verb();

    FAKER_EXPECT_CONTAINS(verbs, generatedVerb);
}

TEST_F(HackerTest, shouldGenerateIngverb)
{
    auto generatedIngverb = hacker::ingverb();

    FAKER_EXPECT_CONTAINS(ingverbs, generatedIngverb);
}

TEST_F(HackerTest, shouldGeneratePhrase)
{
    auto generatedPhrase = hacker::phrase();
    bool hasAdjective, hasNoun, hasVerb, hasAbbreviation;
    hasAdjective = hasNoun = hasVerb = hasAbbreviation = false;

    // Check for adjectives
    for (const auto& adj : adjectives) {
        if (generatedPhrase.find(adj) != std::string::npos) {
            hasAdjective = true;
            break;
        }
    }

    // Check for nouns
    for (const auto& noun : nouns) {
        if (generatedPhrase.find(noun) != std::string::npos) {
            hasNoun = true;
            break;
        }
    }

    // Check for verbs
    for (const auto& verb : verbs) {
        if (generatedPhrase.find(verb) != std::string::npos) {
            hasVerb = true;
            break;
        }
    }

    // Check for abbreviations
    for (const auto& abbreviation : abbreviations) {
        if (generatedPhrase.find(abbreviation) != std::string::npos) {
            hasAbbreviation = true;
            break;
        }
    }

    ASSERT_TRUE((hasAdjective && hasNoun && hasVerb && hasAbbreviation));
}
