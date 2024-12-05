#include <algorithm>
#include <string>
#include <vector>

#include "gtest/gtest.h"

#include "common/string_helper.h"
#include "faker-cxx/word.h"
#include "word_data.h"

using namespace faker::word;
using namespace faker;
using namespace ::testing;

namespace
{

const struct Idioms_Map& getIdiomsMap(Locale locale)
{
    if (idiomsMapSpan.find(locale) == idiomsMapSpan.end())
    {
        return enUSIdioms;
    }
    else
    {
        return idiomsMapSpan.at(locale);
    }
}

bool checkLocale(Locale locale)
{
    if (idiomsMapSpan.find(locale) == idiomsMapSpan.end())
    {
        return false;
    }
    else
    {
        return true;
    }
}

}

class WordTest : public Test
{
public:
};

TEST_F(WordTest, shouldGenerateAdjective)
{
    const auto generatedAdjective = adjective();

    ASSERT_TRUE(std::ranges::any_of(adjectives, [generatedAdjective](const std::string_view& word)
                                    { return word == generatedAdjective; }));
}

TEST_F(WordTest, shouldGenerateAdjectiveWithExistingLength)
{
    const auto generatedAdjective = adjective(5);

    ASSERT_TRUE(std::ranges::any_of(adjectives, [generatedAdjective](const std::string_view& word)
                                    { return word == generatedAdjective; }));
}

TEST_F(WordTest, shouldGenerateAdjectiveWithNonExistingLength)
{
    const auto generatedAdjective = adjective(100);

    ASSERT_TRUE(std::ranges::any_of(adjectives, [generatedAdjective](const std::string_view& word)
                                    { return word == generatedAdjective; }));
}

TEST_F(WordTest, shouldGenerateAdverb)
{
    const auto generatedAdverb = adverb();

    ASSERT_TRUE(std::ranges::any_of(adverbs, [generatedAdverb](const std::string_view& word)
                                    { return word == generatedAdverb; }));
}

TEST_F(WordTest, shouldGenerateAdverbWithExistingLength)
{
    const auto generatedAdverb = adverb(5);

    ASSERT_TRUE(std::ranges::any_of(adverbs, [generatedAdverb](const std::string_view& word)
                                    { return word == generatedAdverb; }));
}

TEST_F(WordTest, shouldGenerateAdverbWithNonExistingLength)
{
    const auto generatedAdverb = adverb(100);

    ASSERT_TRUE(std::ranges::any_of(adverbs, [generatedAdverb](const std::string_view& word)
                                    { return word == generatedAdverb; }));
}

TEST_F(WordTest, shouldGenerateConjunction)
{
    const auto generatedConjunction = conjunction();

    ASSERT_TRUE(std::ranges::any_of(_conjunctions_sorted, [generatedConjunction](const std::string_view& word)
                                    { return word == generatedConjunction; }));
}

TEST_F(WordTest, shouldGenerateConjunctionWithExistingLength)
{
    const auto generatedConjunction = conjunction(5);

    ASSERT_TRUE(std::ranges::any_of(_conjunctions_sorted, [generatedConjunction](const std::string_view& word)
                                    { return word == generatedConjunction; }));
}

TEST_F(WordTest, shouldGenerateConjunctionWithNonExistingLength)
{
    const auto generatedConjunction = conjunction(100);

    ASSERT_TRUE(std::ranges::any_of(_conjunctions_sorted, [generatedConjunction](const std::string_view& word)
                                    { return word == generatedConjunction; }));
}

TEST_F(WordTest, shouldGenerateInterjection)
{
    const auto generatedInterjection = interjection();

    ASSERT_TRUE(std::ranges::any_of(interjections, [generatedInterjection](const std::string_view& word)
                                    { return word == generatedInterjection; }));
}

TEST_F(WordTest, shouldGenerateInterjectionWithExistingLength)
{
    const auto generatedInterjection = interjection(5);

    ASSERT_TRUE(std::ranges::any_of(interjections, [generatedInterjection](const std::string_view& word)
                                    { return word == generatedInterjection; }));
}

TEST_F(WordTest, shouldGenerateInterjectionWithNonExistingLength)
{
    const auto generatedInterjection = interjection(100);

    ASSERT_TRUE(std::ranges::any_of(interjections, [generatedInterjection](const std::string_view& word)
                                    { return word == generatedInterjection; }));
}

TEST_F(WordTest, shouldGenerateNoun)
{
    const auto generatedNoun = noun();

    ASSERT_TRUE(
        std::ranges::any_of(nouns, [generatedNoun](const std::string_view& word) { return word == generatedNoun; }));
}

TEST_F(WordTest, shouldGenerateNounWithExistingLength)
{
    const auto generatedNoun = noun(5);

    ASSERT_TRUE(
        std::ranges::any_of(nouns, [generatedNoun](const std::string_view& word) { return word == generatedNoun; }));
}

TEST_F(WordTest, shouldGenerateNounWithNonExistingLength)
{
    const auto generatedNoun = noun(100);

    ASSERT_TRUE(
        std::ranges::any_of(nouns, [generatedNoun](const std::string_view& word) { return word == generatedNoun; }));
}

TEST_F(WordTest, shouldGeneratePreposition)
{
    const auto generatedPreposition = preposition();

    ASSERT_TRUE(std::ranges::any_of(prepositions, [generatedPreposition](const std::string_view& word)
                                    { return word == generatedPreposition; }));
}

TEST_F(WordTest, shouldGeneratePrepositionWithExistingLength)
{
    const auto generatedPreposition = preposition(5);

    ASSERT_TRUE(std::ranges::any_of(prepositions, [generatedPreposition](const std::string_view& word)
                                    { return word == generatedPreposition; }));
}

TEST_F(WordTest, shouldGeneratePrepositionWithNonExistingLength)
{
    const auto generatedPreposition = preposition(100);

    ASSERT_TRUE(std::ranges::any_of(prepositions, [generatedPreposition](const std::string_view& word)
                                    { return word == generatedPreposition; }));
}

TEST_F(WordTest, shouldGenerateVerb)
{
    const auto generatedVerb = verb();

    ASSERT_TRUE(
        std::ranges::any_of(verbs, [generatedVerb](const std::string_view& word) { return word == generatedVerb; }));
}

TEST_F(WordTest, shouldGenerateVerbWithExistingLength)
{
    const auto generatedVerb = verb(5);

    ASSERT_TRUE(
        std::ranges::any_of(verbs, [generatedVerb](const std::string_view& word) { return word == generatedVerb; }));
}

TEST_F(WordTest, shouldGenerateVerbWithNonExistingLength)
{
    const auto generatedVerb = verb(100);

    ASSERT_TRUE(
        std::ranges::any_of(verbs, [generatedVerb](const std::string_view& word) { return word == generatedVerb; }));
}

TEST_F(WordTest, shouldGenerateSample)
{
    const auto generatedSample = sample();

    ASSERT_TRUE(std::ranges::any_of(_allWords, [generatedSample](const std::string_view& word)
                                    { return word == generatedSample; }));
}

TEST_F(WordTest, shouldGenerateSampleWithExistingLength)
{
    const auto generatedSample = sample(5);

    ASSERT_TRUE(std::ranges::any_of(_allWords, [generatedSample](const std::string_view& word)
                                    { return word == generatedSample; }));
}

TEST_F(WordTest, shouldGenerateSampleWithNonExistingLength)
{
    const auto generatedSample = sample(100);

    ASSERT_TRUE(std::ranges::any_of(_allWords, [generatedSample](const std::string_view& word)
                                    { return word == generatedSample; }));
}

TEST_F(WordTest, shouldGenerateWords)
{
    const auto generatedWords = words(5);

    const auto separatedWords = common::split(generatedWords, " ");

    ASSERT_TRUE(std::ranges::all_of(separatedWords, [](const std::string& separatedWord)
                                    { return std::ranges::find(_allWords, separatedWord) != _allWords.end(); }));
}

TEST_F(WordTest, shouldReturnRandomElementWhenExactLengthNotFound)
{
    const unsigned int existingLength = 5;

    std::vector<std::string_view> matchingAdjectives;
    for (const auto& adj : _adjectives_sorted)
    {
        if (adj.size() == existingLength)
        {
            matchingAdjectives.push_back(adj);
        }
    }

    const auto generatedAdjective = adjective(existingLength + 1);

    ASSERT_TRUE(std::ranges::find(_adjectives_sorted, generatedAdjective) != _adjectives_sorted.end());
    ASSERT_TRUE(std::ranges::find(matchingAdjectives, generatedAdjective) == matchingAdjectives.end());
}

TEST_F(WordTest, shouldReturnEmptyStringForZeroWords)
{
    const auto result = words(0);
    ASSERT_TRUE(result.empty());
}

TEST_F(WordTest, shouldGenerateLargeNumberOfWords)
{
    const unsigned int largeWordCount = 300;
    const auto generatedWords = words(largeWordCount);
    const auto separatedWords = common::split(generatedWords, " ");

    ASSERT_EQ(separatedWords.size(), largeWordCount);
    for (const auto& word : separatedWords)
    {
        ASSERT_TRUE(std::ranges::find(_allWords, word) != _allWords.end());
    }
}

class WordTestLocale : public TestWithParam<Locale>
{
public:
};

TEST_P(WordTestLocale, shouldGenerateadjectiveLocale)
{
    auto locale = GetParam();
    auto idiomsMapLocal = getIdiomsMap(locale);

    const auto generatedAdjective = adjective(7, locale);

    ASSERT_TRUE(std::ranges::any_of(idiomsMapLocal.adjetives, [generatedAdjective](const std::string_view& word)
                                    { return word == generatedAdjective; }));
}

TEST_P(WordTestLocale, shouldGenerateadjectiveLocaleWithNoLocale)
{
    auto locale = Locale::en_US;
    auto idiomsMapLocal = getIdiomsMap(locale);

    const auto generatedAdjective = adjective();

    ASSERT_TRUE(std::ranges::any_of(idiomsMapLocal.adjetives, [generatedAdjective](const std::string_view& word)
                                    { return word == generatedAdjective; }));
}

TEST_P(WordTestLocale, shouldGenerateAdjectiveWithExistingLength)
{
    const auto locale = GetParam();
    const auto idiomsMapLocal = getIdiomsMap(locale);

    const auto generatedAdjective = adjective(5, locale);

    ASSERT_TRUE(std::ranges::any_of(idiomsMapLocal.adjetives, [generatedAdjective](const std::string_view& word)
                                    { return word == generatedAdjective; }));
}

TEST_P(WordTestLocale, shouldGenerateAdjectiveWithNonExistingLength)
{
    const auto locale = GetParam();
    const auto idiomsMapLocal = getIdiomsMap(locale);

    const auto generatedAdjective = adjective(0, locale);

    ASSERT_TRUE(std::ranges::any_of(idiomsMapLocal.adjetives, [generatedAdjective](const std::string_view& word)
                                    { return word == generatedAdjective; }));
}

TEST_P(WordTestLocale, shouldGenerateAdvervsLocale)
{
    const auto locale = GetParam();
    const auto idiomsMapLocal = getIdiomsMap(locale);

    const auto generatedAdverb = adverb(7, locale);

    ASSERT_TRUE(std::ranges::any_of(idiomsMapLocal.adverbs, [generatedAdverb](const std::string_view& word)
                                    { return word == generatedAdverb; }));
}

TEST_P(WordTestLocale, shouldGenerateadverbLocale2)
{
    const auto locale = GetParam();
    const auto idiomsMapLocal = getIdiomsMap(locale);

    const auto generatedAdverb = adverb(0, locale);

    ASSERT_TRUE(std::ranges::any_of(idiomsMapLocal.adverbs, [generatedAdverb](const std::string_view& word)
                                    { return word == generatedAdverb; }));
}

TEST_P(WordTestLocale, shouldGenerateAdverbWithExistingLength)
{

    const auto locale = GetParam();
    const auto idiomsMapLocal = getIdiomsMap(locale);

    const auto generatedAdverb = adverb(5, locale);

    ASSERT_TRUE(std::ranges::any_of(idiomsMapLocal.adverbs, [generatedAdverb](const std::string_view& word)
                                    { return word == generatedAdverb; }));
}

TEST_P(WordTestLocale, shouldGenerateAdverbWithNonExistingLength)
{
    const auto locale = GetParam();
    const auto idiomsMapLocal = getIdiomsMap(locale);

    const auto generatedAdverb = adverb(0, locale);

    ASSERT_TRUE(std::ranges::any_of(idiomsMapLocal.adverbs, [generatedAdverb](const std::string_view& word)
                                    { return word == generatedAdverb; }));
}

TEST_P(WordTestLocale, shouldGenerateConjunction)
{
    const auto locale = GetParam();
    const auto idiomsMapLocal = getIdiomsMap(locale);

    const auto generatedConjunction = conjunction(7, locale);

    ASSERT_TRUE(std::ranges::any_of(idiomsMapLocal.conjunctions, [generatedConjunction](const std::string_view& word)
                                    { return word == generatedConjunction; }));
}

TEST_P(WordTestLocale, shouldGenerateConjunctionWithExistingLength)
{
    const auto locale = GetParam();
    const auto idiomsMapLocal = getIdiomsMap(locale);

    const auto generatedConjunction = conjunction(5, locale);

    ASSERT_TRUE(std::ranges::any_of(idiomsMapLocal.conjunctions, [generatedConjunction](const std::string_view& word)
                                    { return word == generatedConjunction; }));
}

TEST_P(WordTestLocale, shouldGenerateConjunctionWithLength0)
{
    const auto locale = GetParam();
    const auto idiomsMapLocal = getIdiomsMap(locale);

    const auto generatedConjunction = conjunction(0, locale);

    ASSERT_TRUE(std::ranges::any_of(idiomsMapLocal.conjunctions, [generatedConjunction](const std::string_view& word)
                                    { return word == generatedConjunction; }));
}

TEST_P(WordTestLocale, shouldGenerateInterjection)
{
    const auto locale = GetParam();
    const auto idiomsMapLocal = getIdiomsMap(locale);

    const auto generatedInterjection = interjection(0, locale);

    ASSERT_TRUE(std::ranges::any_of(idiomsMapLocal.interjections, [generatedInterjection](const std::string_view& word)
                                    { return word == generatedInterjection; }));
}

TEST_P(WordTestLocale, shouldGenerateInterjectionWithExistingLength)
{
    const auto locale = GetParam();
    const auto idiomsMapLocal = getIdiomsMap(locale);

    const auto generatedInterjection = interjection(5, locale);

    ASSERT_TRUE(std::ranges::any_of(idiomsMapLocal.interjections, [generatedInterjection](const std::string_view& word)
                                    { return word == generatedInterjection; }));
}

TEST_P(WordTestLocale, shouldGenerateInterjectionWithLength0)
{
    const auto locale = GetParam();
    const auto idiomsMapLocal = getIdiomsMap(locale);

    const auto generatedInterjection = interjection(0, locale);

    ASSERT_TRUE(std::ranges::any_of(idiomsMapLocal.interjections, [generatedInterjection](const std::string_view& word)
                                    { return word == generatedInterjection; }));
}

TEST_P(WordTestLocale, shouldGenerateNoun)
{
    const auto locale = GetParam();
    const auto idiomsMapLocal = getIdiomsMap(locale);

    const auto generatedNoun = noun(0, locale);

    ASSERT_TRUE(std::ranges::any_of(idiomsMapLocal.nouns,
                                    [generatedNoun](const std::string_view& word) { return word == generatedNoun; }));
}

TEST_P(WordTestLocale, shouldGenerateNounWithExistingLength)
{
    const auto locale = GetParam();
    const auto idiomsMapLocal = getIdiomsMap(locale);

    const auto generatedNoun = noun(5, locale);

    ASSERT_TRUE(std::ranges::any_of(idiomsMapLocal.nouns,
                                    [generatedNoun](const std::string_view& word) { return word == generatedNoun; }));
}

TEST_P(WordTestLocale, shouldGenerateNOunWithLength0)
{

    const auto locale = GetParam();
    const auto idiomsMapLocal = getIdiomsMap(locale);

    const auto generatedNoun = noun(0, locale);

    ASSERT_TRUE(std::ranges::any_of(idiomsMapLocal.nouns,
                                    [generatedNoun](const std::string_view& word) { return word == generatedNoun; }));
}

TEST_P(WordTestLocale, shouldGeneratePreposition)
{
    const auto locale = GetParam();
    const auto idiomsMapLocal = getIdiomsMap(locale);

    const auto generatedPreposition = preposition(0, locale);

    ASSERT_TRUE(std::ranges::any_of(idiomsMapLocal.prepositions, [generatedPreposition](const std::string_view& word)
                                    { return word == generatedPreposition; }));
}

TEST_P(WordTestLocale, shouldGeneratePrepositionWithExistingLength)
{
    const auto locale = GetParam();
    const auto idiomsMapLocal = getIdiomsMap(locale);

    const auto generatedPreposition = preposition(5, locale);

    ASSERT_TRUE(std::ranges::any_of(idiomsMapLocal.prepositions, [generatedPreposition](const std::string_view& word)
                                    { return word == generatedPreposition; }));
}

TEST_P(WordTestLocale, shouldGeneratePrepositionWithLength0)
{
    const auto locale = GetParam();
    const auto idiomsMapLocal = getIdiomsMap(locale);
    const auto generatedPreposition = preposition(0, locale);

    ASSERT_TRUE(std::ranges::any_of(idiomsMapLocal.prepositions, [generatedPreposition](const std::string_view& word)
                                    { return word == generatedPreposition; }));
}

TEST_P(WordTestLocale, shouldGenerateVerb)
{
    const auto locale = GetParam();
    const auto idiomsMapLocal = getIdiomsMap(locale);

    const auto generatedVerb = verb(0, locale);

    ASSERT_TRUE(std::ranges::any_of(idiomsMapLocal.verbs,
                                    [generatedVerb](const std::string_view& word) { return word == generatedVerb; }));
}

TEST_P(WordTestLocale, shouldGenerateVerbWithExistingLength)
{
    const auto locale = GetParam();
    const auto idiomsMapLocal = getIdiomsMap(locale);

    const auto generatedVerb = verb(5, locale);

    ASSERT_TRUE(std::ranges::any_of(idiomsMapLocal.verbs,
                                    [generatedVerb](const std::string_view& word) { return word == generatedVerb; }));
}

TEST_P(WordTestLocale, shouldGenerateVerbWithExistingLength0)
{
    const auto locale = GetParam();
    const auto idiomsMapLocal = getIdiomsMap(locale);

    const auto generatedVerb = verb(0, locale);

    ASSERT_TRUE(std::ranges::any_of(idiomsMapLocal.verbs,
                                    [generatedVerb](const std::string_view& word) { return word == generatedVerb; }));
}

TEST_F(WordTestLocale, shouldGenerateSample)
{
    const auto locale = Locale::en_US;

    const auto generatedSample = sample();

    ASSERT_TRUE(std::ranges::any_of(_allWords_map.at(locale), [generatedSample](const std::string_view& word)
                                    { return word == generatedSample; }));
}

TEST_P(WordTestLocale, shouldGenerateSampleWithExistingLength)
{
    const auto locale = GetParam();
    Locale extra = locale;

    const auto generatedSample = sample(5, locale);

    if (!checkLocale(locale))
    {
        extra = Locale::en_US;
    }
    ASSERT_TRUE(std::ranges::any_of(_allWords_map.at(extra), [generatedSample](const std::string_view& word)
                                    { return word == generatedSample; }));
}

TEST_P(WordTestLocale, shouldGenerateSampleWithNonExistingLength)
{
    const auto locale = GetParam();
    Locale extra = locale;

    const auto generatedSample = sample(0, locale);

    if (!checkLocale(locale))
    {
        extra = Locale::en_US;
    }

    ASSERT_TRUE(std::ranges::any_of(_allWords_map.at(extra), [generatedSample](const std::string_view& word)
                                    { return word == generatedSample; }));
}

TEST_P(WordTestLocale, shouldGenerateWords)
{
    const auto locale = GetParam();
    Locale extra = locale;

    if (!checkLocale(locale))
    {
        extra = Locale::en_US;
    }

    const auto generatedWords = words(5, locale);

    const auto separatedWords = common::split(generatedWords, " ");

    const auto& datamap = _allWords_map.at(extra);

    ASSERT_TRUE(std::ranges::all_of(separatedWords, [&datamap](const std::string& separatedWord)
                                    { return std::ranges::find(datamap, separatedWord) != datamap.end(); }));
}

TEST_F(WordTestLocale, shouldReturnRandomElementWhenExactLengthNotFound)
{
    const unsigned int existingLength = 5;

    const auto locale = faker::Locale::es_AR;

    std::vector<std::string_view> matchingAdjectives;

    auto sorted = _adjetives_sorted_map.at(locale);

    for (const auto& adj : sorted)
    {
        if (adj.size() == existingLength)
        {
            matchingAdjectives.push_back(adj);
        }
    }

    const auto generatedAdjective = adjective(existingLength + 1, locale);

    ASSERT_TRUE(std::ranges::find(sorted, generatedAdjective) != sorted.end());
    ASSERT_TRUE(std::ranges::find(matchingAdjectives, generatedAdjective) == matchingAdjectives.end());
}

TEST_P(WordTestLocale, shouldReturnEmptyStringForZeroWords)
{
    const auto locale = GetParam();
    Locale extra = locale;

    if (!checkLocale(locale))
    {
        extra = Locale::en_US;
    }

    const auto result = words(0, extra);

    ASSERT_TRUE(result.empty());
}

TEST_P(WordTestLocale, shouldGenerateLargeNumberOfWords)
{

    const auto locale = GetParam();
    Locale extra = locale;

    if (!checkLocale(locale))
    {
        extra = Locale::en_US;
    }

    const unsigned int largeWordCount = 300;

    const auto generatedWords = words(largeWordCount, extra);

    const auto separatedWords = common::split(generatedWords, " ");

    auto dataset = _allWords_map.at(extra);

    ASSERT_EQ(separatedWords.size(), largeWordCount);

    for (const auto& word : separatedWords)
    {
        ASSERT_TRUE(std::ranges::find(dataset, word) != dataset.end());
    }
}

TEST_F(WordTestLocale, shouldReturnEnglishSampleifLocaleNotFilled)
{
    const Locale locale = Locale::es_BO;
    const Locale locale2 = Locale::en_US;

    const auto generatedSample = sample(0, locale);

    const auto dataset = _allWords_map.at(locale2);

    ASSERT_TRUE(std::ranges::any_of(dataset, [generatedSample](const std::string_view& word)
                                    { return word == generatedSample; }));
}

TEST_F(WordTestLocale, shouldReturnPortugueseSampleifAskedforPortugueseWord)
{
    const auto locale = Locale::pt_BR;

    const auto generatedSample = sample(0, locale);

    auto dataset = _allWords_map.at(locale);

    ASSERT_TRUE(std::ranges::any_of(dataset, [generatedSample](const std::string_view& word)
                                    { return word == generatedSample; }));
}

TEST_F(WordTestLocale, shouldReturnFrenchSampleifAskedforFrenchWord)
{
    const auto locale = Locale::fr_FR;

    const auto generatedSample = sample(0, locale);

    auto dataset = _allWords_map.at(locale);

    ASSERT_TRUE(std::ranges::any_of(dataset, [generatedSample](const std::string_view& word)
                                    { return word == generatedSample; }));
}

INSTANTIATE_TEST_SUITE_P(testWordByLocale, WordTestLocale, ValuesIn(locales),
                         [](const TestParamInfo<Locale>& paramInfo) { return toString(paramInfo.param); });
