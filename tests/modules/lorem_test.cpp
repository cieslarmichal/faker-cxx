#include "../test_helpers.h"
#include <algorithm>
#include <common/string_helper.h>
#include <faker/lorem.h>
#include <modules/lorem_data.h>

using namespace faker;

TEST(LoremTest, shouldGenerateWord)
{
    const auto generatedWord = lorem::word();

    FAKER_EXPECT_CONTAINER_CONTAINS(lorem::data::loremWords, generatedWord);
}

TEST(LoremTest, shouldGenerateWords)
{
    const auto numberOfWords = 5;

    const auto generatedWords = lorem::words(numberOfWords);

    const auto separatedWords = utils::split(generatedWords, " ");

    ASSERT_EQ(separatedWords.size(), numberOfWords);
    ASSERT_TRUE(faker::testing::all_of(separatedWords, [](auto separatedWord) {
        return faker::testing::any_of(lorem::data::loremWords, [separatedWord](const auto& word) {
            return word
                == static_cast<char>(std::tolower(separatedWord[0])) + std::string(separatedWord.substr(1));
        });
    }));
}

TEST(LoremTest, shouldGenerateSentence)
{
    const auto sentence = lorem::sentence();

    const auto sentenceWithoutEndingDot = sentence.substr(0, sentence.size() - 1);

    const auto sentenceWords = utils::split(sentenceWithoutEndingDot, " ");

    ASSERT_TRUE(std::isupper(sentence[0]));
    FAKER_EXPECT_STRING_ENDS_WITH(sentence, ".");
    ASSERT_TRUE(sentenceWords.size() >= 3 && sentenceWords.size() <= 10);
    ASSERT_TRUE(faker::testing::all_of(sentenceWords, [](auto sentenceWord) {
        return faker::testing::any_of(lorem::data::loremWords, [sentenceWord](const auto& word) {
            return word
                == static_cast<char>(std::tolower(sentenceWord[0])) + std::string(sentenceWord.substr(1));
        });
    }));
}

TEST(LoremTest, shouldGenerateSentences)
{
    const auto sentences = lorem::sentences();

    const auto separatedSentences = utils::split(sentences, ". ");

    for (auto sentence2 : separatedSentences) {
        std::string sentence { sentence2 };
        sentence.erase(std::remove(sentence.begin(), sentence.end(), '.'), sentence.end());

        ASSERT_TRUE(std::isupper(sentence[0]));

        const auto sentenceWords = utils::split(sentence, " ");

        ASSERT_TRUE(sentenceWords.size() >= 3 && sentenceWords.size() <= 10);

        ASSERT_TRUE(faker::testing::all_of(sentenceWords, [](const auto& sentenceWord) {
            return faker::testing::any_of(
                lorem::data::loremWords, [sentenceWord](const auto& word) {
                    return word
                        == static_cast<char>(std::tolower(sentenceWord[0]))
                        + std::string(sentenceWord.substr(1));
                });
        }));
    }
}

TEST(LoremTest, shouldGenerateSlug)
{
    const auto generatedSlug = lorem::slug(3);

    const auto separatedWords = utils::split(generatedSlug, "-");

    ASSERT_EQ(separatedWords.size(), 3);
    ASSERT_TRUE(faker::testing::all_of(separatedWords, [](auto separatedWord) {
        return faker::testing::any_of(lorem::data::loremWords, [separatedWord](auto word) {
            return faker::testing::compare_no_case(separatedWord, word);
        });
    }));
}

TEST(LoremTest, shouldGenerateParagraph)
{
    const auto paragraph = lorem::paragraph();

    const auto separatedSentences = utils::split(paragraph, ". ");

    for (auto sentence2 : separatedSentences) {
        std::string sentence { sentence2 };
        sentence.erase(std::remove(sentence.begin(), sentence.end(), '.'), sentence.end());

        ASSERT_TRUE(std::isupper(sentence[0]));

        const auto sentenceWords = utils::split(sentence, " ");

        ASSERT_TRUE(sentenceWords.size() >= 3 && sentenceWords.size() <= 10);

        ASSERT_TRUE(faker::testing::all_of(sentenceWords, [](const auto& sentenceWord) {
            return faker::testing::any_of(
                lorem::data::loremWords, [sentenceWord](const auto& word) {
                    return faker::testing::compare_no_case(sentenceWord, word);
                });
        }));
    }
}

TEST(LoremTest, shouldGenerateParagraphs)
{
    const auto paragraphs = lorem::paragraphs();

    const auto separatedParagraphs = utils::split(paragraphs, "\n");

    for (const auto& paragraph : separatedParagraphs) {
        const auto separatedSentences = utils::split(paragraph, ". ");

        for (auto sentence2 : separatedSentences) {
            std::string sentence { sentence2 };
            sentence.erase(std::remove(sentence.begin(), sentence.end(), '.'), sentence.end());

            ASSERT_TRUE(std::isupper(sentence[0]));

            const auto sentenceWords = utils::split(sentence, " ");

            ASSERT_TRUE(sentenceWords.size() >= 3 && sentenceWords.size() <= 10);

            ASSERT_TRUE(faker::testing::all_of(sentenceWords, [](const auto& sentenceWord) {
                return faker::testing::any_of(
                    lorem::data::loremWords, [sentenceWord](const auto& word) {
                        return faker::testing::compare_no_case(sentenceWord, word);
                    });
            }));
        }
    }
}
