#include "../test_helpers.h"
#include <algorithm>
#include <faker/hacker.h>
#include <modules/hacker_data.h>
#include <string>

using namespace faker;

TEST(HackerTest, shouldGenerateAbbreviation)
{
    auto generatedAbbreviation = hacker::abbreviation();

    FAKER_EXPECT_CONTAINS(hacker::data::abbreviations, generatedAbbreviation);
}

TEST(HackerTest, shouldGenerateAdjective)
{
    auto generatedAdjective = hacker::adjective();

    FAKER_EXPECT_CONTAINS(hacker::data::adjectives, generatedAdjective);
}

TEST(HackerTest, shouldGenerateNoun)
{
    auto generatedNoun = hacker::noun();

    FAKER_EXPECT_CONTAINS(hacker::data::nouns, generatedNoun);
}

TEST(HackerTest, shouldGenerateVerb)
{
    auto generatedVerb = hacker::verb();

    FAKER_EXPECT_CONTAINS(hacker::data::verbs, generatedVerb);
}

TEST(HackerTest, shouldGenerateIngverb)
{
    auto generatedIngverb = hacker::ingverb();

    FAKER_EXPECT_CONTAINS(hacker::data::ingverbs, generatedIngverb);
}

TEST(HackerTest, shouldGeneratePhrase)
{
    auto generatedPhrase = hacker::phrase();

    bool hasAdjective, hasNoun, hasVerb, hasAbbreviation;
    hasAdjective = hasNoun = hasVerb = hasAbbreviation = false;

    // Check for adjectives
    for (const auto& adj : hacker::data::adjectives) {
        if (generatedPhrase.find(adj) != std::string::npos) {
            hasAdjective = true;
            break;
        }
    }

    // Check for nouns
    for (const auto& noun : hacker::data::nouns) {
        if (generatedPhrase.find(noun) != std::string::npos) {
            hasNoun = true;
            break;
        }
    }

    // Check for verbs
    for (const auto& verb : hacker::data::verbs) {
        if (generatedPhrase.find(verb) != std::string::npos) {
            hasVerb = true;
            break;
        }
    }

    // Check for abbreviations
    for (const auto& abbreviation : hacker::data::abbreviations) {
        if (generatedPhrase.find(abbreviation) != std::string::npos) {
            hasAbbreviation = true;
            break;
        }
    }

    ASSERT_TRUE((hasAdjective && hasNoun && hasVerb && hasAbbreviation));
}
