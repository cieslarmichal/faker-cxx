#include "include/faker-cxx/Word.h"

#include "gtest/gtest.h"

#include "data/words/Adjectives.h"
#include "data/words/Adverbs.h"
#include "data/words/Conjunctions.h"
#include "data/words/Interjections.h"
#include "data/words/Nouns.h"
#include "data/words/Prepositions.h"
#include "data/words/Verbs.h"
#include "StringHelper.h"
#include <algorithm>

using namespace ::testing;
using namespace faker;

class WordTest : public Test
{
public:
    WordTest()
    {
        allWords.insert(allWords.end(), adjectives.begin(), adjectives.end());
        allWords.insert(allWords.end(), adverbs.begin(), adverbs.end());
        allWords.insert(allWords.end(), conjunctions.begin(), conjunctions.end());
        allWords.insert(allWords.end(), interjections.begin(), interjections.end());
        allWords.insert(allWords.end(), nouns.begin(), nouns.end());
        allWords.insert(allWords.end(), prepositions.begin(), prepositions.end());
        allWords.insert(allWords.end(), verbs.begin(), verbs.end());
    }

    std::vector<std::string> allWords;
};

TEST_F(WordTest, shouldGenerateAdjective)
{
    const auto generatedAdjective = Word::adjective();

    ASSERT_TRUE(std::any_of(adjectives.begin(), adjectives.end(),
                            [generatedAdjective](const std::string& word) { return word == generatedAdjective; }));
}

TEST_F(WordTest, shouldGenerateAdjectiveWithExistingLength)
{
    const auto generatedAdjective = Word::adjective(5);

    ASSERT_TRUE(std::any_of(adjectives.begin(), adjectives.end(),
                            [generatedAdjective](const std::string& word) { return word == generatedAdjective; }));
}

TEST_F(WordTest, shouldGenerateAdjectiveWithNonExistingLength)
{
    const auto generatedAdjective = Word::adjective(100);

    ASSERT_TRUE(std::any_of(adjectives.begin(), adjectives.end(),
                            [generatedAdjective](const std::string& word) { return word == generatedAdjective; }));
}

TEST_F(WordTest, shouldGenerateAdverb)
{
    const auto generatedAdverb = Word::adverb();

    ASSERT_TRUE(std::any_of(adverbs.begin(), adverbs.end(),
                            [generatedAdverb](const std::string& word) { return word == generatedAdverb; }));
}

TEST_F(WordTest, shouldGenerateAdverbWithExistingLength)
{
    const auto generatedAdverb = Word::adverb(5);

    ASSERT_TRUE(std::any_of(adverbs.begin(), adverbs.end(),
                            [generatedAdverb](const std::string& word) { return word == generatedAdverb; }));
}

TEST_F(WordTest, shouldGenerateAdverbWithNonExistingLength)
{
    const auto generatedAdverb = Word::adverb(100);

    ASSERT_TRUE(std::any_of(adverbs.begin(), adverbs.end(),
                            [generatedAdverb](const std::string& word) { return word == generatedAdverb; }));
}

TEST_F(WordTest, shouldGenerateConjunction)
{
    const auto generatedConjunction = Word::conjunction();

    ASSERT_TRUE(std::any_of(conjunctions.begin(), conjunctions.end(),
                            [generatedConjunction](const std::string& word) { return word == generatedConjunction; }));
}

TEST_F(WordTest, shouldGenerateConjunctionWithExistingLength)
{
    const auto generatedConjunction = Word::conjunction(5);

    ASSERT_TRUE(std::any_of(conjunctions.begin(), conjunctions.end(),
                            [generatedConjunction](const std::string& word) { return word == generatedConjunction; }));
}

TEST_F(WordTest, shouldGenerateConjunctionWithNonExistingLength)
{
    const auto generatedConjunction = Word::conjunction(100);

    ASSERT_TRUE(std::any_of(conjunctions.begin(), conjunctions.end(),
                            [generatedConjunction](const std::string& word) { return word == generatedConjunction; }));
}

TEST_F(WordTest, shouldGenerateInterjection)
{
    const auto generatedInterjection = Word::interjection();

    ASSERT_TRUE(std::any_of(interjections.begin(), interjections.end(),
                            [generatedInterjection](const std::string& word)
                            { return word == generatedInterjection; }));
}

TEST_F(WordTest, shouldGenerateInterjectionWithExistingLength)
{
    const auto generatedInterjection = Word::interjection(5);

    ASSERT_TRUE(std::any_of(interjections.begin(), interjections.end(),
                            [generatedInterjection](const std::string& word)
                            { return word == generatedInterjection; }));
}

TEST_F(WordTest, shouldGenerateInterjectionWithNonExistingLength)
{
    const auto generatedInterjection = Word::interjection(100);

    ASSERT_TRUE(std::any_of(interjections.begin(), interjections.end(),
                            [generatedInterjection](const std::string& word)
                            { return word == generatedInterjection; }));
}

TEST_F(WordTest, shouldGenerateNoun)
{
    const auto generatedNoun = Word::noun();

    ASSERT_TRUE(std::any_of(nouns.begin(), nouns.end(),
                            [generatedNoun](const std::string& word) { return word == generatedNoun; }));
}

TEST_F(WordTest, shouldGenerateNounWithExistingLength)
{
    const auto generatedNoun = Word::noun(5);

    ASSERT_TRUE(std::any_of(nouns.begin(), nouns.end(),
                            [generatedNoun](const std::string& word) { return word == generatedNoun; }));
}

TEST_F(WordTest, shouldGenerateNounWithNonExistingLength)
{
    const auto generatedNoun = Word::noun(100);

    ASSERT_TRUE(std::any_of(nouns.begin(), nouns.end(),
                            [generatedNoun](const std::string& word) { return word == generatedNoun; }));
}

TEST_F(WordTest, shouldGeneratePreposition)
{
    const auto generatedPreposition = Word::preposition();

    ASSERT_TRUE(std::any_of(prepositions.begin(), prepositions.end(),
                            [generatedPreposition](const std::string& word) { return word == generatedPreposition; }));
}

TEST_F(WordTest, shouldGeneratePrepositionWithExistingLength)
{
    const auto generatedPreposition = Word::preposition(5);

    ASSERT_TRUE(std::any_of(prepositions.begin(), prepositions.end(),
                            [generatedPreposition](const std::string& word) { return word == generatedPreposition; }));
}

TEST_F(WordTest, shouldGeneratePrepositionWithNonExistingLength)
{
    const auto generatedPreposition = Word::preposition(100);

    ASSERT_TRUE(std::any_of(prepositions.begin(), prepositions.end(),
                            [generatedPreposition](const std::string& word) { return word == generatedPreposition; }));
}

TEST_F(WordTest, shouldGenerateVerb)
{
    const auto generatedVerb = Word::verb();

    ASSERT_TRUE(std::any_of(verbs.begin(), verbs.end(),
                            [generatedVerb](const std::string& word) { return word == generatedVerb; }));
}

TEST_F(WordTest, shouldGenerateVerbWithExistingLength)
{
    const auto generatedVerb = Word::verb(5);

    ASSERT_TRUE(std::any_of(verbs.begin(), verbs.end(),
                            [generatedVerb](const std::string& word) { return word == generatedVerb; }));
}

TEST_F(WordTest, shouldGenerateVerbWithNonExistingLength)
{
    const auto generatedVerb = Word::verb(100);

    ASSERT_TRUE(std::any_of(verbs.begin(), verbs.end(),
                            [generatedVerb](const std::string& word) { return word == generatedVerb; }));
}

TEST_F(WordTest, shouldGenerateSample)
{
    const auto generatedSample = Word::sample();

    ASSERT_TRUE(std::any_of(allWords.begin(), allWords.end(),
                            [generatedSample](const std::string& word) { return word == generatedSample; }));
}

TEST_F(WordTest, shouldGenerateSampleWithExistingLength)
{
    const auto generatedSample = Word::sample(5);

    ASSERT_TRUE(std::any_of(allWords.begin(), allWords.end(),
                            [generatedSample](const std::string& word) { return word == generatedSample; }));
}

TEST_F(WordTest, shouldGenerateSampleWithNonExistingLength)
{
    const auto generatedSample = Word::sample(100);

    ASSERT_TRUE(std::any_of(allWords.begin(), allWords.end(),
                            [generatedSample](const std::string& word) { return word == generatedSample; }));
}

TEST_F(WordTest, shouldGenerateWords)
{
    const auto generatedWords = Word::words(5);

    const auto separatedWords = StringHelper::split(generatedWords, " ");

    ASSERT_TRUE(std::all_of(separatedWords.begin(), separatedWords.end(),
                            [this](const std::string& separatedWord)
                            { return std::find(allWords.begin(), allWords.end(), separatedWord) != allWords.end(); }));
}
