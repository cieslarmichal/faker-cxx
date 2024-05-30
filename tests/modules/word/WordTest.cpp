//#include "faker-cxx/Word.h"
//
//#include <algorithm>
//#include <optional>
//#include <string> // Dodano, aby mo¿na by³o konwertowaæ std::string_view na std::string
//#include <string_view>
//
//#include "gtest/gtest.h"
//
//#include "common/StringHelper.h"
//#include "word/wordData.h"
//
//using namespace ::testing;
//using namespace faker;
//using namespace Words;
//
//class WordTest : public Test
//{
//public:
//    WordTest()
//    {
//        allWords.insert(allWords.end(), adjectives.begin(), adjectives.end());
//        allWords.insert(allWords.end(), adverbs.begin(), adverbs.end());
//        allWords.insert(allWords.end(), conjunctions.begin(), conjunctions.end());
//        allWords.insert(allWords.end(), interjections.begin(), interjections.end());
//        allWords.insert(allWords.end(), nouns.begin(), nouns.end());
//        allWords.insert(allWords.end(), prepositions.begin(), prepositions.end());
//        allWords.insert(allWords.end(), verbs.begin(), verbs.end());
//    }
//
//    std::vector<std::string_view> allWords;
//};
//
//TEST_F(WordTest, shouldGenerateAdjective)
//{
//    const auto generatedAdjective = Word::adjective();
//    ASSERT_TRUE(std::ranges::any_of(adjectives, [generatedAdjective](const std::string_view& word)
//                                    { return std::string(word) == std::string(generatedAdjective); }));
//}
//
//TEST_F(WordTest, shouldGenerateAdjectiveWithExistingLength)
//{
//    const auto generatedAdjective = Word::adjective(5);
//    ASSERT_TRUE(std::ranges::any_of(adjectives, [generatedAdjective](const std::string_view& word)
//                                    { return std::string(word) == std::string(generatedAdjective); }));
//}
//
//TEST_F(WordTest, shouldGenerateAdjectiveWithNonExistingLength)
//{
//    const auto generatedAdjective = Word::adjective(100);
//    ASSERT_TRUE(std::ranges::any_of(adjectives, [generatedAdjective](const std::string_view& word)
//                                    { return std::string(word) == std::string(generatedAdjective); }));
//}
//
//TEST_F(WordTest, shouldGenerateAdverb)
//{
//    const auto generatedAdverb = Word::adverb();
//    ASSERT_TRUE(std::ranges::any_of(adverbs, [generatedAdverb](const std::string_view& word)
//                                    { return std::string(word) == std::string(generatedAdverb); }));
//}
//
//TEST_F(WordTest, shouldGenerateAdverbWithExistingLength)
//{
//    const auto generatedAdverb = Word::adverb(5);
//    ASSERT_TRUE(std::ranges::any_of(adverbs, [generatedAdverb](const std::string_view& word)
//                                    { return std::string(word) == std::string(generatedAdverb); }));
//}
//
//TEST_F(WordTest, shouldGenerateAdverbWithNonExistingLength)
//{
//    const auto generatedAdverb = Word::adverb(100);
//    ASSERT_TRUE(std::ranges::any_of(adverbs, [generatedAdverb](const std::string_view& word)
//                                    { return std::string(word) == std::string(generatedAdverb); }));
//}
//
//TEST_F(WordTest, shouldGenerateConjunction)
//{
//    const auto generatedConjunction = Word::conjunction();
//    ASSERT_TRUE(std::ranges::any_of(conjunctions, [generatedConjunction](const std::string_view& word)
//                                    { return std::string(word) == std::string(generatedConjunction); }));
//}
//
//TEST_F(WordTest, shouldGenerateConjunctionWithExistingLength)
//{
//    const auto generatedConjunction = Word::conjunction(5);
//    ASSERT_TRUE(std::ranges::any_of(conjunctions, [generatedConjunction](const std::string_view& word)
//                                    { return std::string(word) == std::string(generatedConjunction); }));
//}
//
//TEST_F(WordTest, shouldGenerateConjunctionWithNonExistingLength)
//{
//    const auto generatedConjunction = Word::conjunction(100);
//    ASSERT_TRUE(std::ranges::any_of(conjunctions, [generatedConjunction](const std::string_view& word)
//                                    { return std::string(word) == std::string(generatedConjunction); }));
//}
//
//TEST_F(WordTest, shouldGenerateInterjection)
//{
//    const auto generatedInterjection = Word::interjection();
//    ASSERT_TRUE(std::ranges::any_of(interjections, [generatedInterjection](const std::string_view& word)
//                                    { return std::string(word) == std::string(generatedInterjection); }));
//}
//
//TEST_F(WordTest, shouldGenerateInterjectionWithExistingLength)
//{
//    const auto generatedInterjection = Word::interjection(5);
//    ASSERT_TRUE(std::ranges::any_of(interjections, [generatedInterjection](const std::string_view& word)
//                                    { return std::string(word) == std::string(generatedInterjection); }));
//}
//
//TEST_F(WordTest, shouldGenerateInterjectionWithNonExistingLength)
//{
//    const auto generatedInterjection = Word::interjection(100);
//    ASSERT_TRUE(std::ranges::any_of(interjections, [generatedInterjection](const std::string_view& word)
//                                    { return std::string(word) == std::string(generatedInterjection); }));
//}
//
//TEST_F(WordTest, shouldGenerateNoun)
//{
//    const auto generatedNoun = Word::noun();
//    ASSERT_TRUE(std::ranges::any_of(nouns, [generatedNoun](const std::string_view& word)
//                                    { return std::string(word) == std::string(generatedNoun); }));
//}
//
//TEST_F(WordTest, shouldGenerateNounWithExistingLength)
//{
//    const auto generatedNoun = Word::noun(5);
//    ASSERT_TRUE(std::ranges::any_of(nouns, [generatedNoun](const std::string_view& word)
//                                    { return std::string(word) == std::string(generatedNoun); }));
//}
//
//TEST_F(WordTest, shouldGenerateNounWithNonExistingLength)
//{
//    const auto generatedNoun = Word::noun(100);
//    ASSERT_TRUE(std::ranges::any_of(nouns, [generatedNoun](const std::string_view& word)
//                                    { return std::string(word) == std::string(generatedNoun); }));
//}
//
//TEST_F(WordTest, shouldGeneratePreposition)
//{
//    const auto generatedPreposition = Word::preposition();
//    ASSERT_TRUE(std::ranges::any_of(prepositions, [generatedPreposition](const std::string_view& word)
//                                    { return std::string(word) == std::string(generatedPreposition); }));
//}
//
//TEST_F(WordTest, shouldGeneratePrepositionWithExistingLength)
//{
//    const auto generatedPreposition = Word::preposition(5);
//    ASSERT_TRUE(std::ranges::any_of(prepositions, [generatedPreposition](const std::string_view& word)
//                                    { return std::string(word) == std::string(generatedPreposition); }));
//}
//
//TEST_F(WordTest, shouldGeneratePrepositionWithNonExistingLength)
//{
//    const auto generatedPreposition = Word::preposition(100);
//    ASSERT_TRUE(std::ranges::any_of(prepositions, [generatedPreposition](const std::string_view& word)
//                                    { return std::string(word) == std::string(generatedPreposition); }));
//}
//
//TEST_F(WordTest, shouldGenerateVerb)
//{
//    const auto generatedVerb = Word::verb();
//    ASSERT_TRUE(std::ranges::any_of(verbs, [generatedVerb](const std::string_view& word)
//                                    { return std::string(word) == std::string(generatedVerb); }));
//}
//
//TEST_F(WordTest, shouldGenerateVerbWithExistingLength)
//{
//    const auto generatedVerb = Word::verb(5);
//    ASSERT_TRUE(std::ranges::any_of(verbs, [generatedVerb](const std::string_view& word)
//                                    { return std::string(word) == std::string(generatedVerb); }));
//}
//
//TEST_F(WordTest, shouldGenerateVerbWithNonExistingLength)
//{
//    const auto generatedVerb = Word::verb(100);
//    ASSERT_TRUE(std::ranges::any_of(verbs, [generatedVerb](const std::string_view& word)
//                                    { return std::string(word) == std::string(generatedVerb); }));
//}
//
//TEST_F(WordTest, shouldGenerateSample)
//{
//    const auto generatedSample = Word::sample();
//    ASSERT_TRUE(std::ranges::any_of(allWords, [generatedSample](const std::string_view& word)
//                                    { return std::string(word) == std::string(generatedSample); }));
//}
//
//TEST_F(WordTest, shouldGenerateSampleWithExistingLength)
//{
//    const auto generatedSample = Word::sample(5);
//    ASSERT_TRUE(std::ranges::any_of(allWords, [generatedSample](const std::string_view& word)
//                                    { return std::string(word) == std::string(generatedSample); }));
//}
//
//TEST_F(WordTest, shouldGenerateSampleWithNonExistingLength)
//{
//    const auto generatedSample = Word::sample(100);
//    ASSERT_TRUE(std::ranges::any_of(allWords, [generatedSample](const std::string_view& word)
//                                    { return std::string(word) == std::string(generatedSample); }));
//}
//
//TEST_F(WordTest, shouldGenerateWords)
//{
//    const auto generatedWords = Word::words(5);
//    const auto separatedWords = StringHelper::split(std::string(generatedWords), " ");
//    ASSERT_TRUE(std::ranges::all_of(separatedWords, [this](const std::string& separatedWord)
//                                    { return std::ranges::find(allWords, separatedWord) != allWords.end(); }));
//}
