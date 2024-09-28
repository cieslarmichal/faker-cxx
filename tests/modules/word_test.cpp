#include <algorithm>
#include <string>
#include <vector>

#include "gtest/gtest.h"

#include "common/string_helper.h"
#include "faker-cxx/word.h"
#include "word_data.h"
#include "locale.h"

using namespace faker::word;
using namespace faker;
using namespace ::testing;

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

    ASSERT_TRUE(std::ranges::any_of(conjunctions, [generatedConjunction](const std::string_view& word)
                                    { return word == generatedConjunction; }));
}

TEST_F(WordTest, shouldGenerateConjunctionWithExistingLength)
{
    const auto generatedConjunction = conjunction(5);

    ASSERT_TRUE(std::ranges::any_of(conjunctions, [generatedConjunction](const std::string_view& word)
                                    { return word == generatedConjunction; }));
}

TEST_F(WordTest, shouldGenerateConjunctionWithNonExistingLength)
{
    const auto generatedConjunction = conjunction(100);

    ASSERT_TRUE(std::ranges::any_of(conjunctions, [generatedConjunction](const std::string_view& word)
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

TEST_F(WordTest, returnsRandomElementWhenAllElementsLessthanGivenLength)
{
    std::vector<std::string> words = {"one", "three", "five"};
    std::optional<unsigned int> length = 6;

    auto result = sortedSizeRandomElement(length, words);

    ASSERT_TRUE(result == "one" || result == "three" || result == "five");
}

TEST_F(WordTest, returnsFirstElementWhenNoLengthMatch)
{
    std::vector<std::string> words = {"one", "three", "five"};
    std::optional<unsigned int> length = 4;

    auto result = sortedSizeRandomElement(length, words);

    ASSERT_TRUE(result == "three");
}




class WordTestLocale : public TestWithParam<Locale>
{
public:
};
TEST_F(WordTestLocale, shouldGenerateAdjectiveLocale)
{
    const faker::Locale locale = Locale::es_AR; 
    const auto generatedAdjective = adjectiveL( 7,locale);
    ASSERT_TRUE(std::ranges::any_of(_adjetives_sorted_map.at(locale), [generatedAdjective](const std::string_view& word)
                                    { return word == generatedAdjective; }));
}
TEST_F(WordTestLocale, shouldGenerateAdjectiveLocaleWithNoLocale)
{
    
    const auto generatedAdjective = adjectiveL();
    ASSERT_TRUE(std::ranges::any_of(adjectives, [generatedAdjective](const std::string_view& word)
                                   { return word == generatedAdjective; }));
}

TEST_F(WordTestLocale, shouldGenerateAdjectiveWithExistingLength)
{
    const faker::Locale locale = Locale::es_AR; 
    const auto generatedAdjective = adjectiveL(5,locale);

    ASSERT_TRUE(std::ranges::any_of(_adjetives_sorted_map.at(locale), [generatedAdjective](const std::string_view& word)
                                    { return word == generatedAdjective; }));
}

TEST_F(WordTestLocale, shouldGenerateAdjectiveWithNonExistingLength)
{
    const faker::Locale locale = Locale::es_AR; 
    const auto generatedAdjective = adjectiveL(0,locale);

    ASSERT_TRUE(std::ranges::any_of(_adjetives_sorted_map.at(locale), [generatedAdjective](const std::string_view& word)
                                    { return word == generatedAdjective; }));
}

TEST_F(WordTestLocale, shouldGenerateAdvervsLocale)
{
    const faker::Locale locale = Locale::es_AR; 
    const auto generatedAdverb = adverbL(7,locale);    
    ASSERT_TRUE(std::ranges::any_of(_adverbs_sorted_map.at(locale), [generatedAdverb](const std::string_view& word)
                                   { return word == generatedAdverb; }));
                                   
}

TEST_F(WordTestLocale, shouldGenerateAdverbLocale2)
{
    const faker::Locale locale = Locale::en_US; 
    const auto generatedAdverb = adverb();

    ASSERT_TRUE(std::ranges::any_of(_adverbs_sorted_map.at(locale), [generatedAdverb](const std::string_view& word)
                                    { return word == generatedAdverb; }));
}

TEST_F(WordTestLocale, shouldGenerateAdverbWithExistingLength)
{
    const faker::Locale locale = Locale::es_AR; 
    const auto generatedAdverb = adverbL(5,locale);

    ASSERT_TRUE(std::ranges::any_of(_adverbs_sorted_map.at(locale), [generatedAdverb](const std::string_view& word)
                                    { return word == generatedAdverb; }));
}

TEST_F(WordTestLocale, shouldGenerateAdverbWithNonExistingLength)
{
    const faker::Locale locale = Locale::es_AR; 
    const auto generatedAdverb = adverbL(0,locale);

    ASSERT_TRUE(std::ranges::any_of(_adverbs_sorted_map.at(locale), [generatedAdverb](const std::string_view& word)
                                    { return word == generatedAdverb; }));
}

TEST_F(WordTestLocale, shouldGenerateConjunction)
{
    const auto generatedConjunction = conjunction();

    ASSERT_TRUE(std::ranges::any_of(conjunctions, [generatedConjunction](const std::string_view& word)
                                    { return word == generatedConjunction; }));
}

TEST_F(WordTestLocale, shouldGenerateConjunctionWithExistingLength)
{
    const faker::Locale locale = Locale::es_AR; 
    const auto generatedConjunction = conjunctionL(5,locale);

    ASSERT_TRUE(std::ranges::any_of(_conjunctions_sorted_map.at(locale),[generatedConjunction](const std::string_view& word)
                                    { return word == generatedConjunction; }));
}

TEST_F(WordTestLocale, shouldGenerateConjunctionWithLength0)
{
    const faker::Locale locale = Locale::es_AR; 
    const auto generatedConjunction = conjunctionL(0,locale);    
    ASSERT_TRUE(std::ranges::any_of(_conjunctions_sorted_map.at(locale), [generatedConjunction](const std::string_view& word)
                                    { return word == generatedConjunction; }));
}


TEST_F(WordTestLocale, shouldGenerateInterjection)
{
    const faker::Locale locale = Locale::es_AR; 
    const auto generatedInterjection = interjectionL(0,locale);

    ASSERT_TRUE(std::ranges::any_of(_interjections_sorted_map.at(locale), [generatedInterjection](const std::string_view& word)
                                    { return word == generatedInterjection; }));
}

TEST_F(WordTestLocale, shouldGenerateInterjectionWithExistingLength)
{
    const faker::Locale locale = Locale::es_AR; 
    const auto generatedInterjection = interjectionL(5,locale);    
    ASSERT_TRUE(std::ranges::any_of(_interjections_sorted_map.at(locale), [generatedInterjection](const std::string_view& word)
                                    { return word == generatedInterjection; }));
}

TEST_F(WordTestLocale, shouldGenerateInterjectionWithLength0)
{
    const faker::Locale locale = Locale::es_AR; 
    const auto generatedInterjection = interjectionL(0,locale);

    ASSERT_TRUE(std::ranges::any_of(_interjections_sorted_map.at(locale), [generatedInterjection](const std::string_view& word)
                                    { return word == generatedInterjection; }));
}


TEST_F(WordTestLocale, shouldGenerateNoun)
{
    const faker::Locale locale = Locale::en_US; 
    const auto generatedNoun = nounL();

    ASSERT_TRUE(
        std::ranges::any_of(_nouns_sorted_map.at(locale), [generatedNoun](const std::string_view& word) { return word == generatedNoun; }));
}

TEST_F(WordTestLocale, shouldGenerateNounWithExistingLength)
{
    const faker::Locale locale = Locale::en_US; 
    const auto generatedNoun = nounL(5);

    ASSERT_TRUE(
        std::ranges::any_of(_nouns_sorted_map.at(locale), [generatedNoun](const std::string_view& word) { return word == generatedNoun; }));
}

TEST_F(WordTestLocale, shouldGenerateNOunWithLength0)
{
    const faker::Locale locale = Locale::es_AR; 
    const auto generatedNoun = nounL(0,locale);

    ASSERT_TRUE(
        std::ranges::any_of(_nouns_sorted_map.at(locale), [generatedNoun](const std::string_view& word) { return word == generatedNoun; }));
}


TEST_F(WordTestLocale, shouldGeneratePreposition)
{
    const faker::Locale locale = Locale::en_US; 
    const auto generatedPreposition = preposition();

    ASSERT_TRUE(std::ranges::any_of(_prepositions_sorted_map.at(locale), [generatedPreposition](const std::string_view& word)
                                    { return word == generatedPreposition; }));
}

TEST_F(WordTestLocale, shouldGeneratePrepositionWithExistingLength)
{
    const faker::Locale locale = Locale::es_AR; 
    const auto generatedPreposition = prepositionL(5,locale);
    
    ASSERT_TRUE(std::ranges::any_of(_prepositions_sorted_map.at(locale), [generatedPreposition](const std::string_view& word)
                                    { return word == generatedPreposition; }));
}

TEST_F(WordTestLocale, shouldGeneratePrepositionWithLength0)
{
    const faker::Locale locale = Locale::es_AR; 
    const auto generatedPreposition = prepositionL(0,locale);

    ASSERT_TRUE(std::ranges::any_of(_prepositions_sorted_map.at(locale), [generatedPreposition](const std::string_view& word)
                                    { return word == generatedPreposition; }));
}


TEST_F(WordTestLocale, shouldGenerateVerb)
{
    const faker::Locale locale = Locale::en_US; 
    const auto generatedVerb = verb();

    ASSERT_TRUE(
        std::ranges::any_of(_verbs_sorted_map.at(locale), [generatedVerb](const std::string_view& word) { return word == generatedVerb; }));
}

TEST_F(WordTestLocale, shouldGenerateVerbWithExistingLength)
{
    const faker::Locale locale = Locale::es_AR; 
    const auto generatedVerb = verbL(5,locale);

    ASSERT_TRUE(
        std::ranges::any_of(_verbs_sorted_map.at(locale), [generatedVerb](const std::string_view& word) { return word == generatedVerb; }));
}

TEST_F(WordTestLocale, shouldGenerateVerbWithExistingLength0)
{
    const faker::Locale locale = Locale::es_AR; 
    const auto generatedVerb = verbL(0,locale);
    ASSERT_TRUE(
        std::ranges::any_of(_verbs_sorted_map.at(locale), [generatedVerb](const std::string_view& word) { return word == generatedVerb; }));
}


TEST_F(WordTestLocale, shouldGenerateSample)
{
    const auto generatedSample = sample();
    const auto generatedSample2 = sample();

    std::cout<<"sample 1:"<<generatedSample<<"\n";
    std::cout<<"sample 2:"<<generatedSample2<<"\n";

    ASSERT_TRUE(std::ranges::any_of(_allWords, [generatedSample](const std::string_view& word)
                                    { return word == generatedSample; }));
}

TEST_F(WordTestLocale, shouldGenerateSampleWithExistingLength)
{
    const auto generatedSample = sample(5);

    ASSERT_TRUE(std::ranges::any_of(_allWords, [generatedSample](const std::string_view& word)
                                    { return word == generatedSample; }));
}

TEST_F(WordTestLocale, shouldGenerateSampleWithNonExistingLength)
{
    const auto generatedSample = sample(100);

    ASSERT_TRUE(std::ranges::any_of(_allWords, [generatedSample](const std::string_view& word)
                                    { return word == generatedSample; }));
}
