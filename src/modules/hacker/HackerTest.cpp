#include "faker-cxx/Hacker.h"

#include <algorithm>

#include "gtest/gtest.h"

#include "src/modules/hacker/data/Abbreviations.h"
#include "src/modules/hacker/data/Adjectives.h"
#include "src/modules/hacker/data/Ingverbs.h"
#include "src/modules/hacker/data/Nouns.h"
// #include "src/modules/hacker/data/Phrases.h"
#include "src/modules/hacker/data/Verbs.h"

// testing Hacker module, test like Person module tests
// testing phrases will be different, test that each phrase will have a random word from each word list

using namespace ::testing;
using namespace faker;

class HackerTest : public Test {
public:
};

TEST_F(HackerTest, shouldGenerateAbbreviation) {
    std::string generatedAbbreviation = Hacker::abbreviation();

    ASSERT_TRUE(std::ranges::any_of(abbreviations, [generatedAbbreviation](const std::string& abbreviation) { return abbreviation == generatedAbbreviation; }));
}

TEST_F(HackerTest, shouldGenerateAdjective) {
    std::string generatedAdjective = Hacker::adjective();

    ASSERT_TRUE(std::ranges::any_of(adjectives, [generatedAdjective](const std::string& adjective) { return adjective == generatedAdjective; }));
}

TEST_F(HackerTest, shouldGenerateNoun) {
    std::string generatedNoun = Hacker::noun();

    ASSERT_TRUE(std::ranges::any_of(nouns, [generatedNoun](const std::string& noun) { return noun == generatedNoun; }));
}

TEST_F(HackerTest, shouldGenerateVerb) {
    std::string generatedVerb = Hacker::verb();

    ASSERT_TRUE(std::ranges::any_of(verbs, [generatedVerb](const std::string& verb) { return verb == generatedVerb; }));
}

TEST_F(HackerTest, shouldGenerateIngverb) {
    std::string generatedIngverb = Hacker::ingverb();

    ASSERT_TRUE(std::ranges::any_of(ingverbs, [generatedIngverb](const std::string& ingverb) { return ingverb == generatedIngverb; }));
}

/*TEST_F(HackerTest, shouldGeneratePhrase) {
    std::string generatedPhrase = Hacker::phrase();
    ASSERT_TRUE(std::ranges::any_of(phrases, [generatedPhrase](const std::string& phrase) { return phrase == generatedPhrase; }));
}
 */