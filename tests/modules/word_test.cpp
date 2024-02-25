#include "../test_helpers.h"
#include <common/string_helper.h>
#include <faker/word.h>
#include <modules/word_data.h>

using namespace faker;

class WordTest : public ::testing::Test {
public:
    WordTest()
    {
        allWords.insert(
            allWords.end(), word::data::adjectives.begin(), word::data::adjectives.end());
        allWords.insert(allWords.end(), word::data::adverbs.begin(), word::data::adverbs.end());
        allWords.insert(
            allWords.end(), word::data::conjunctions.begin(), word::data::conjunctions.end());
        allWords.insert(
            allWords.end(), word::data::interjections.begin(), word::data::interjections.end());
        allWords.insert(allWords.end(), word::data::nouns.begin(), word::data::nouns.end());
        allWords.insert(
            allWords.end(), word::data::prepositions.begin(), word::data::prepositions.end());
        allWords.insert(allWords.end(), word::data::verbs.begin(), word::data::verbs.end());
    }

    std::vector<std::string> allWords;
};

TEST_F(WordTest, shouldGenerateAdjective)
{
    const auto generatedAdjective = word::adjective();

    FAKER_EXPECT_CONTAINS(word::data::adjectives, generatedAdjective);
}

TEST_F(WordTest, shouldGenerateAdjectiveWithExistingLength)
{
    const auto generatedAdjective = word::adjective(5);

    FAKER_EXPECT_CONTAINS(word::data::adjectives, generatedAdjective);
}

TEST_F(WordTest, shouldGenerateAdjectiveWithNonExistingLength)
{
    const auto generatedAdjective = word::adjective(100);

    FAKER_EXPECT_CONTAINS(word::data::adjectives, generatedAdjective);
}

TEST_F(WordTest, shouldGenerateAdverb)
{
    const auto generatedAdverb = word::adverb();

    FAKER_EXPECT_CONTAINS(word::data::adverbs, generatedAdverb);
}

TEST_F(WordTest, shouldGenerateAdverbWithExistingLength)
{
    const auto generatedAdverb = word::adverb(5);

    FAKER_EXPECT_CONTAINS(word::data::adverbs, generatedAdverb);
}

TEST_F(WordTest, shouldGenerateAdverbWithNonExistingLength)
{
    const auto generatedAdverb = word::adverb(100);

    FAKER_EXPECT_CONTAINS(word::data::adverbs, generatedAdverb);
}

TEST_F(WordTest, shouldGenerateConjunction)
{
    const auto generatedConjunction = word::conjunction();

    FAKER_EXPECT_CONTAINS(word::data::conjunctions, generatedConjunction);
}

TEST_F(WordTest, shouldGenerateConjunctionWithExistingLength)
{
    const auto generatedConjunction = word::conjunction(5);

    FAKER_EXPECT_CONTAINS(word::data::conjunctions, generatedConjunction);
}

TEST_F(WordTest, shouldGenerateConjunctionWithNonExistingLength)
{
    const auto generatedConjunction = word::conjunction(100);

    FAKER_EXPECT_CONTAINS(word::data::conjunctions, generatedConjunction);
}

TEST_F(WordTest, shouldGenerateInterjection)
{
    const auto generatedInterjection = word::interjection();

    FAKER_EXPECT_CONTAINS(word::data::interjections, generatedInterjection);
}

TEST_F(WordTest, shouldGenerateInterjectionWithExistingLength)
{
    const auto generatedInterjection = word::interjection(5);

    FAKER_EXPECT_CONTAINS(word::data::interjections, generatedInterjection);
}

TEST_F(WordTest, shouldGenerateInterjectionWithNonExistingLength)
{
    const auto generatedInterjection = word::interjection(100);

    FAKER_EXPECT_CONTAINS(word::data::interjections, generatedInterjection);
}

TEST_F(WordTest, shouldGenerateNoun)
{
    const auto generatedNoun = word::noun();

    FAKER_EXPECT_CONTAINS(word::data::nouns, generatedNoun);
}

TEST_F(WordTest, shouldGenerateNounWithExistingLength)
{
    const auto generatedNoun = word::noun(5);

    FAKER_EXPECT_CONTAINS(word::data::nouns, generatedNoun);
}

TEST_F(WordTest, shouldGenerateNounWithNonExistingLength)
{
    const auto generatedNoun = word::noun(100);

    FAKER_EXPECT_CONTAINS(word::data::nouns, generatedNoun);
}

TEST_F(WordTest, shouldGeneratePreposition)
{
    const auto generatedPreposition = word::preposition();

    FAKER_EXPECT_CONTAINS(word::data::prepositions, generatedPreposition);
}

TEST_F(WordTest, shouldGeneratePrepositionWithExistingLength)
{
    const auto generatedPreposition = word::preposition(5);

    FAKER_EXPECT_CONTAINS(word::data::prepositions, generatedPreposition);
}

TEST_F(WordTest, shouldGeneratePrepositionWithNonExistingLength)
{
    const auto generatedPreposition = word::preposition(100);

    FAKER_EXPECT_CONTAINS(word::data::prepositions, generatedPreposition);
}

TEST_F(WordTest, shouldGenerateVerb)
{
    const auto generatedVerb = word::verb();

    FAKER_EXPECT_CONTAINS(word::data::verbs, generatedVerb);
}

TEST_F(WordTest, shouldGenerateVerbWithExistingLength)
{
    const auto generatedVerb = word::verb(5);

    FAKER_EXPECT_CONTAINS(word::data::verbs, generatedVerb);
}

TEST_F(WordTest, shouldGenerateVerbWithNonExistingLength)
{
    const auto generatedVerb = word::verb(100);

    FAKER_EXPECT_CONTAINS(word::data::verbs, generatedVerb);
}

TEST_F(WordTest, shouldGenerateSample)
{
    const auto generatedSample = word::sample();

    FAKER_EXPECT_CONTAINS(allWords, generatedSample);
}

TEST_F(WordTest, shouldGenerateSampleWithExistingLength)
{
    const auto generatedSample = word::sample(5);

    FAKER_EXPECT_CONTAINS(allWords, generatedSample);
}

TEST_F(WordTest, shouldGenerateSampleWithNonExistingLength)
{
    const auto generatedSample = word::sample(100);

    FAKER_EXPECT_CONTAINS(allWords, generatedSample);
}

TEST_F(WordTest, shouldGenerateWords)
{
    const auto generatedWords = word::words(5);

    const auto separatedWords = StringHelper::split(generatedWords, " ");

    ASSERT_TRUE(faker::testing::all_of(separatedWords, [this](const std::string& separatedWord) {
        return faker::testing::find(allWords, separatedWord) != allWords.end();
    }));
}
