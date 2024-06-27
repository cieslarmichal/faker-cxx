#include "faker-cxx/Lorem.h"

#include <cctype>
#include <string>
#include <string_view>
#include <vector>

#include "../../common/FormatHelper.h"
#include "../../common/StringHelper.h"
#include "faker-cxx/Helper.h"
#include "faker-cxx/Number.h"
#include "LoremData.h"

namespace faker::lorem
{
std::string_view word()
{
    return helper::arrayElement(loremWords);
}

std::string words(unsigned numberOfWords)
{
    std::vector<std::string_view> words;
    words.reserve(numberOfWords);

    for (unsigned i = 0; i < numberOfWords; i++)
    {
        words.push_back(word());
    }

    return StringHelper::join(words, " ");
}

std::string sentence(unsigned minNumberOfWords, unsigned maxNumberOfWords)
{
    const std::integral auto numberOfWords = number::integer(minNumberOfWords, maxNumberOfWords);

    const auto sentenceWords = words(numberOfWords);

    return FormatHelper::format("{}{}.", static_cast<char>(std::toupper(sentenceWords[0])), sentenceWords.substr(1));
}

std::string sentences(unsigned minNumberOfSentences, unsigned maxNumberOfSentences)
{
    const std::integral auto numberOfSentences = number::integer(minNumberOfSentences, maxNumberOfSentences);

    std::vector<std::string> sentences;
    sentences.reserve(numberOfSentences);

    for (unsigned i = 0; i < numberOfSentences; i++)
    {
        sentences.push_back(sentence());
    }

    return StringHelper::joinString(sentences, " ");
}

std::string slug(unsigned int numberOfWords)
{
    std::vector<std::string> words;
    words.reserve(numberOfWords);

    for (unsigned i = 0; i < numberOfWords; i++)
    {
        words.push_back(std::string(word()));
    }

    return StringHelper::joinString(words, "-");
}

std::string paragraph(unsigned int minNumberOfSentences, unsigned int maxNumberOfSentences)
{
    return sentences(minNumberOfSentences, maxNumberOfSentences);
}

std::string paragraphs(unsigned int minNumberOfParagraphs, unsigned int maxNumberOfParagraphs)
{
    const std::integral auto numberOfParagraphs = number::integer(minNumberOfParagraphs, maxNumberOfParagraphs);

    std::vector<std::string> paragraphs;
    paragraphs.reserve(numberOfParagraphs);

    for (unsigned i = 0; i < numberOfParagraphs; i++)
    {
        paragraphs.push_back(paragraph());
    }

    return StringHelper::joinString(paragraphs, "\n");
}

}
