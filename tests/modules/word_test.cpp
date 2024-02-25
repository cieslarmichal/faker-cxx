#include "../test_helpers.h"
#include <algorithm>
#include <common/string_helper.h>
#include <faker/word.h>
#include <modules/word_data.h>

using namespace ::testing;
using namespace faker;

class WordTest : public Test {
public:
    WordTest()
    {
        allWords.insert(allWords.end(), words::adjectives.begin(), words::adjectives.end());
        allWords.insert(allWords.end(), words::adverbs.begin(), words::adverbs.end());
        allWords.insert(allWords.end(), words::conjunctions.begin(), words::conjunctions.end());
        allWords.insert(allWords.end(), words::interjections.begin(), words::interjections.end());
        allWords.insert(allWords.end(), words::nouns.begin(), words::nouns.end());
        allWords.insert(allWords.end(), words::prepositions.begin(), words::prepositions.end());
        allWords.insert(allWords.end(), words::verbs.begin(), words::verbs.end());
    }

    std::vector<std::string> allWords;
};

TEST_F(WordTest, shouldGenerateAdjective)
{
    const auto generatedAdjective = word::adjective();

    ASSERT_TRUE(faker::testing::contains(words::adjectives, generatedAdjective));
}

TEST_F(WordTest, shouldGenerateAdjectiveWithExistingLength)
{
    const auto generatedAdjective = word::adjective(5);

    ASSERT_TRUE(faker::testing::contains(words::adjectives, generatedAdjective));
}

TEST_F(WordTest, shouldGenerateAdjectiveWithNonExistingLength)
{
    const auto generatedAdjective = word::adjective(100);

    ASSERT_TRUE(faker::testing::contains(words::adjectives, generatedAdjective));
}

TEST_F(WordTest, shouldGenerateAdverb)
{
    const auto generatedAdverb = word::adverb();

    ASSERT_TRUE(faker::testing::contains(words::adverbs, generatedAdverb));
}

TEST_F(WordTest, shouldGenerateAdverbWithExistingLength)
{
    const auto generatedAdverb = word::adverb(5);

    ASSERT_TRUE(faker::testing::contains(words::adverbs, generatedAdverb));
}

TEST_F(WordTest, shouldGenerateAdverbWithNonExistingLength)
{
    const auto generatedAdverb = word::adverb(100);

    ASSERT_TRUE(faker::testing::contains(words::adverbs, generatedAdverb));
}

TEST_F(WordTest, shouldGenerateConjunction)
{
    const auto generatedConjunction = word::conjunction();

    ASSERT_TRUE(faker::testing::contains(words::conjunctions, generatedConjunction));
}

TEST_F(WordTest, shouldGenerateConjunctionWithExistingLength)
{
    const auto generatedConjunction = word::conjunction(5);

    ASSERT_TRUE(faker::testing::contains(words::conjunctions, generatedConjunction));
}

TEST_F(WordTest, shouldGenerateConjunctionWithNonExistingLength)
{
    const auto generatedConjunction = word::conjunction(100);

    ASSERT_TRUE(faker::testing::contains(words::conjunctions, generatedConjunction));
}

TEST_F(WordTest, shouldGenerateInterjection)
{
    const auto generatedInterjection = word::interjection();

    ASSERT_TRUE(faker::testing::contains(words::interjections, generatedInterjection));
}

TEST_F(WordTest, shouldGenerateInterjectionWithExistingLength)
{
    const auto generatedInterjection = word::interjection(5);

    ASSERT_TRUE(faker::testing::contains(words::interjections, generatedInterjection));
}

TEST_F(WordTest, shouldGenerateInterjectionWithNonExistingLength)
{
    const auto generatedInterjection = word::interjection(100);

    ASSERT_TRUE(faker::testing::contains(words::interjections, generatedInterjection));
}

TEST_F(WordTest, shouldGenerateNoun)
{
    const auto generatedNoun = word::noun();

    ASSERT_TRUE(faker::testing::contains(words::nouns, generatedNoun));
}

TEST_F(WordTest, shouldGenerateNounWithExistingLength)
{
    const auto generatedNoun = word::noun(5);

    ASSERT_TRUE(faker::testing::contains(words::nouns, generatedNoun));
}

TEST_F(WordTest, shouldGenerateNounWithNonExistingLength)
{
    const auto generatedNoun = word::noun(100);

    ASSERT_TRUE(faker::testing::contains(words::nouns, generatedNoun));
}

TEST_F(WordTest, shouldGeneratePreposition)
{
    const auto generatedPreposition = word::preposition();

    ASSERT_TRUE(faker::testing::contains(words::prepositions, generatedPreposition));
}

TEST_F(WordTest, shouldGeneratePrepositionWithExistingLength)
{
    const auto generatedPreposition = word::preposition(5);

    ASSERT_TRUE(faker::testing::contains(words::prepositions, generatedPreposition));
}

TEST_F(WordTest, shouldGeneratePrepositionWithNonExistingLength)
{
    const auto generatedPreposition = word::preposition(100);

    ASSERT_TRUE(faker::testing::contains(words::prepositions, generatedPreposition));
}

TEST_F(WordTest, shouldGenerateVerb)
{
    const auto generatedVerb = word::verb();

    ASSERT_TRUE(faker::testing::contains(words::verbs, generatedVerb));
}

TEST_F(WordTest, shouldGenerateVerbWithExistingLength)
{
    const auto generatedVerb = word::verb(5);

    ASSERT_TRUE(faker::testing::contains(words::verbs, generatedVerb));
}

TEST_F(WordTest, shouldGenerateVerbWithNonExistingLength)
{
    const auto generatedVerb = word::verb(100);

    ASSERT_TRUE(faker::testing::contains(words::verbs, generatedVerb));
}

TEST_F(WordTest, shouldGenerateSample)
{
    const auto generatedSample = word::sample();

    ASSERT_TRUE(faker::testing::contains(allWords, generatedSample));
}

TEST_F(WordTest, shouldGenerateSampleWithExistingLength)
{
    const auto generatedSample = word::sample(5);

    ASSERT_TRUE(faker::testing::contains(allWords, generatedSample));
}

TEST_F(WordTest, shouldGenerateSampleWithNonExistingLength)
{
    const auto generatedSample = word::sample(100);

    ASSERT_TRUE(faker::testing::contains(allWords, generatedSample));
}

TEST_F(WordTest, shouldGenerateWords)
{
    const auto generatedWords = word::words(5);

    const auto separatedWords = StringHelper::split(generatedWords, " ");

    ASSERT_TRUE(faker::testing::all_of(separatedWords, [this](const std::string& separatedWord) {
        return faker::testing::find(allWords, separatedWord) != allWords.end();
    }));
}
