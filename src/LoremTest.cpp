#include "Lorem.h"

#include "gtest/gtest.h"

#include "data/LoremWords.h"
#include "StringHelper.h"

using namespace ::testing;
using namespace faker;

class LoremTest : public Test
{
public:
};

TEST_F(LoremTest, shouldGenerateWord)
{
    const auto generatedWord = Lorem::word();

    ASSERT_TRUE(std::any_of(loremWords.begin(), loremWords.end(),
                            [generatedWord](const std::string& word) { return word == generatedWord; }));
}

TEST_F(LoremTest, shouldGenerateWords)
{
    const auto numberOfWords = 5;

    const auto generatedWords = Lorem::words(numberOfWords);

    const auto separatedWords = StringHelper::split(generatedWords, " ");

    ASSERT_EQ(separatedWords.size(), numberOfWords);
    ASSERT_TRUE(std::all_of(separatedWords.begin(), separatedWords.end(),
                            [](const std::string& separatedWord)
                            {
                                return std::any_of(loremWords.begin(), loremWords.end(),
                                                   [separatedWord](const std::string& word) {
                                                       return word ==
                                                              static_cast<char>(std::tolower(separatedWord[0])) +
                                                                  separatedWord.substr(1);
                                                   });
                            }));
}

TEST_F(LoremTest, shouldGenerateSentence)
{
    const auto sentence = Lorem::sentence();

    const auto sentenceWithoutEndingDot = sentence.substr(0, sentence.size() - 1);

    const auto sentenceWords = StringHelper::split(sentenceWithoutEndingDot, " ");

    ASSERT_TRUE(std::isupper(sentence[0]));
    ASSERT_TRUE(sentence.ends_with("."));
    ASSERT_TRUE(sentenceWords.size() >= 3 && sentenceWords.size() <= 10);
    ASSERT_TRUE(std::all_of(sentenceWords.begin(), sentenceWords.end(),
                            [](const std::string& sentenceWord)
                            {
                                return std::any_of(loremWords.begin(), loremWords.end(),
                                                   [sentenceWord](const std::string& word) {
                                                       return word == static_cast<char>(std::tolower(sentenceWord[0])) +
                                                                          sentenceWord.substr(1);
                                                   });
                            }));
}

TEST_F(LoremTest, shouldGenerateSentences)
{
    const auto sentences = Lorem::sentences();

    const auto separatedSentences = StringHelper::split(sentences, ". ");

    for (auto sentence : separatedSentences)
    {
        sentence.erase(std::remove(sentence.begin(), sentence.end(), '.'), sentence.end());

        ASSERT_TRUE(std::isupper(sentence[0]));

        const auto sentenceWords = StringHelper::split(sentence, " ");

        ASSERT_TRUE(sentenceWords.size() >= 3 && sentenceWords.size() <= 10);

        ASSERT_TRUE(std::all_of(sentenceWords.begin(), sentenceWords.end(),
                                [](const std::string& sentenceWord)
                                {
                                    return std::any_of(loremWords.begin(), loremWords.end(),
                                                       [sentenceWord](const std::string& word) {
                                                           return word ==
                                                                  static_cast<char>(std::tolower(sentenceWord[0])) +
                                                                      sentenceWord.substr(1);
                                                       });
                                }));
    }
}

TEST_F(LoremTest, shouldGenerateSlug)
{
    const auto generatedSlug = Lorem::slug(3);

    const auto separatedWords = StringHelper::split(generatedSlug, "-");

    ASSERT_EQ(separatedWords.size(), 3);
    ASSERT_TRUE(std::all_of(separatedWords.begin(), separatedWords.end(),
                            [](const std::string& separatedWord)
                            {
                                return std::any_of(loremWords.begin(), loremWords.end(),
                                                   [separatedWord](const std::string& word) {
                                                       return word ==
                                                              static_cast<char>(std::tolower(separatedWord[0])) +
                                                                  separatedWord.substr(1);
                                                   });
                            }));
}

TEST_F(LoremTest, shouldGenerateParagraph)
{
    const auto paragraph = Lorem::paragraph();

    const auto separatedSentences = StringHelper::split(paragraph, ". ");

    for (auto sentence : separatedSentences)
    {
        sentence.erase(std::remove(sentence.begin(), sentence.end(), '.'), sentence.end());

        ASSERT_TRUE(std::isupper(sentence[0]));

        const auto sentenceWords = StringHelper::split(sentence, " ");

        ASSERT_TRUE(sentenceWords.size() >= 3 && sentenceWords.size() <= 10);

        ASSERT_TRUE(std::all_of(sentenceWords.begin(), sentenceWords.end(),
                                [](const std::string& sentenceWord)
                                {
                                    return std::any_of(loremWords.begin(), loremWords.end(),
                                                       [sentenceWord](const std::string& word) {
                                                           return word ==
                                                                  static_cast<char>(std::tolower(sentenceWord[0])) +
                                                                      sentenceWord.substr(1);
                                                       });
                                }));
    }
}

TEST_F(LoremTest, shouldGenerateParagraphs)
{
    const auto paragraphs = Lorem::paragraphs();

    const auto separatedParagraphs = StringHelper::split(paragraphs, "\n");

    for (const auto& paragraph : separatedParagraphs)
    {
        const auto separatedSentences = StringHelper::split(paragraph, ". ");

        for (auto sentence : separatedSentences)
        {
            sentence.erase(std::remove(sentence.begin(), sentence.end(), '.'), sentence.end());

            ASSERT_TRUE(std::isupper(sentence[0]));

            const auto sentenceWords = StringHelper::split(sentence, " ");

            ASSERT_TRUE(sentenceWords.size() >= 3 && sentenceWords.size() <= 10);

            ASSERT_TRUE(std::all_of(sentenceWords.begin(), sentenceWords.end(),
                                    [](const std::string& sentenceWord)
                                    {
                                        return std::any_of(loremWords.begin(), loremWords.end(),
                                                           [sentenceWord](const std::string& word) {
                                                               return word ==
                                                                      static_cast<char>(std::tolower(sentenceWord[0])) +
                                                                          sentenceWord.substr(1);
                                                           });
                                    }));
        }
    }
}
