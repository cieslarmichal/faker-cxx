#include "gtest/gtest.h"
#include "faker-cxx/Hacker.h"

#include <algorithm>
#include <string>
#include <iostream>

#include "data/Abbreviations.h"
#include "data/Adjectives.h"
#include "data/Ingverbs.h"
#include "data/Nouns.h"
#include "data/Verbs.h"
#include "data/Phrases.h"

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

TEST_F(HackerTest, shouldGeneratePhrase) {
    std::string generatedPhrase = Hacker::phrase();
    size_t limit = 1000000;
    size_t attempt = 0;

    while (attempt <= limit) {
        std::string newGeneratedPhrase = Hacker::phrase();
        if (newGeneratedPhrase == generatedPhrase) {
            std::cout << generatedPhrase << "\n";
            std::cout << newGeneratedPhrase << "\n";
            ASSERT_TRUE(true);
            break;
        }

        attempt++;
    }
}