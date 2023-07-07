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

TEST_F(LoremTest, shouldGenerateUsername)
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
                                                   [separatedWord](const std::string& word)
                                                   { return word == separatedWord; });
                            }));
}
