#include <algorithm>
#include <cctype>
#include <string_view>

#include "gtest/gtest.h"

#include "common/string_helper.h"
#include "faker-cxx/lorem.h"
#include "lorem_data.h"

using namespace ::testing;
using namespace ::faker;
using namespace faker::lorem;

class LoremTest : public Test
{
public:
};

TEST_F(LoremTest, shouldGenerateWordVector)
{
    const int numberOfWords = 100;
    const auto generatedWords = wordVector(numberOfWords);

    ASSERT_EQ(generatedWords.size(), numberOfWords);

    ASSERT_TRUE
    (
        std::ranges::all_of(generatedWords,
        [](const std::string_view& generatedWord)
        {
            return std::ranges::any_of (
            loremWords, [generatedWord](const std::string_view& loremWord)
            {
                return loremWord == generatedWord;
            }); 
        }));
}

TEST_F(LoremTest, givenInvalidArguments_shouldThrowInvalidArgument)
{
    ASSERT_THROW(wordVector(-1), std::invalid_argument);
}

TEST_F(LoremTest, givenLengthOf0_shouldReturnEmptyVector)
{
    const auto generatedWords = wordVector(0);
    ASSERT_TRUE(generatedWords.empty());
}

TEST_F(LoremTest, shouldGenerateWord)
{
    const auto generatedWord = word();

    ASSERT_TRUE(std::ranges::any_of(loremWords,
                                    [generatedWord](const std::string_view& word) { return word == generatedWord; }));
}

TEST_F(LoremTest, shouldGenerateWords)
{
    const auto numberOfWords = 5;

    const auto generatedWords = words(numberOfWords);

    const auto separatedWords = common::split(generatedWords, " ");

    ASSERT_EQ(separatedWords.size(), numberOfWords);
    ASSERT_TRUE(std::ranges::all_of(
        separatedWords,
        [](const std::string& separatedWord)
        {
            return std::ranges::any_of(
                loremWords, [separatedWord](const std::string_view& word)
                { return word == static_cast<char>(std::tolower(separatedWord[0])) + separatedWord.substr(1); });
        }));
}

TEST_F(LoremTest, shouldGenerateSentence)
{
    const auto generatedSentence = sentence();

    const auto sentenceWithoutEndingDot = generatedSentence.substr(0, generatedSentence.size() - 1);

    const auto sentenceWords = common::split(sentenceWithoutEndingDot, " ");

    ASSERT_TRUE(std::isupper(generatedSentence[0]));
    ASSERT_TRUE(generatedSentence.ends_with("."));
    ASSERT_TRUE(sentenceWords.size() >= 3 && sentenceWords.size() <= 10);
    ASSERT_TRUE(std::ranges::all_of(
        sentenceWords,
        [](const std::string& sentenceWord)
        {
            return std::ranges::any_of(
                loremWords, [sentenceWord](const std::string_view& word)
                { return word == static_cast<char>(std::tolower(sentenceWord[0])) + sentenceWord.substr(1); });
        }));
}

TEST_F(LoremTest, shouldGenerateSentences)
{
    const auto generatedSentences = sentences();

    const auto separatedSentences = common::split(generatedSentences, ". ");

    for (auto sentence : separatedSentences)
    {
        sentence.erase(std::remove(sentence.begin(), sentence.end(), '.'), sentence.end());

        ASSERT_TRUE(std::isupper(sentence[0]));

        const auto sentenceWords = common::split(sentence, " ");

        ASSERT_TRUE(sentenceWords.size() >= 3 && sentenceWords.size() <= 10);

        ASSERT_TRUE(std::ranges::all_of(
            sentenceWords,
            [](const std::string& sentenceWord)
            {
                return std::ranges::any_of(
                    loremWords, [sentenceWord](const std::string_view& word)
                    { return word == static_cast<char>(std::tolower(sentenceWord[0])) + sentenceWord.substr(1); });
            }));
    }
}

TEST_F(LoremTest, shouldGenerateSlug)
{
    const auto generatedSlug = slug(3);

    const auto separatedWords = common::split(generatedSlug, "-");

    ASSERT_EQ(separatedWords.size(), 3);
    ASSERT_TRUE(std::ranges::all_of(
        separatedWords,
        [](const std::string& separatedWord)
        {
            return std::ranges::any_of(
                loremWords, [separatedWord](const std::string_view& word)
                { return word == static_cast<char>(std::tolower(separatedWord[0])) + separatedWord.substr(1); });
        }));
}

TEST_F(LoremTest, shouldGenerateParagraph)
{
    const auto generatedParagraph = paragraph();

    const auto separatedSentences = common::split(generatedParagraph, ". ");

    for (auto sentence : separatedSentences)
    {
        sentence.erase(std::remove(sentence.begin(), sentence.end(), '.'), sentence.end());

        ASSERT_TRUE(std::isupper(sentence[0]));

        const auto sentenceWords = common::split(sentence, " ");

        ASSERT_TRUE(sentenceWords.size() >= 3 && sentenceWords.size() <= 10);

        ASSERT_TRUE(std::ranges::all_of(
            sentenceWords,
            [](const std::string& sentenceWord)
            {
                return std::ranges::any_of(
                    loremWords, [sentenceWord](const std::string_view& word)
                    { return word == static_cast<char>(std::tolower(sentenceWord[0])) + sentenceWord.substr(1); });
            }));
    }
}

TEST_F(LoremTest, shouldGenerateParagraphs)
{
    const auto generatedParagraphs = paragraphs();

    const auto separatedParagraphs = common::split(generatedParagraphs, "\n");

    for (const auto& generatedParagraph : separatedParagraphs)
    {
        const auto separatedSentences = common::split(generatedParagraph, ". ");

        for (auto sentence : separatedSentences)
        {
            sentence.erase(std::remove(sentence.begin(), sentence.end(), '.'), sentence.end());

            ASSERT_TRUE(std::isupper(sentence[0]));

            const auto sentenceWords = common::split(sentence, " ");

            ASSERT_TRUE(sentenceWords.size() >= 3 && sentenceWords.size() <= 10);

            ASSERT_TRUE(std::ranges::all_of(
                sentenceWords,
                [](const std::string& sentenceWord)
                {
                    return std::ranges::any_of(
                        loremWords, [sentenceWord](const std::string_view& word)
                        { return word == static_cast<char>(std::tolower(sentenceWord[0])) + sentenceWord.substr(1); });
                }));
        }
    }
}
