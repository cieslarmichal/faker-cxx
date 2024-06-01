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

namespace faker
{
std::string_view Lorem::word()
{
    return Helper::arrayElement(loremWords);
}

std::string Lorem::words(unsigned numberOfWords)
{
    std::vector<std::string> words;
    words.reserve(numberOfWords);

    for (unsigned i = 0; i < numberOfWords; i++)
    {
        words.push_back(std::string(word()));
    }

    return StringHelper::join(words, " ");
}

std::string Lorem::sentence(unsigned minNumberOfWords, unsigned maxNumberOfWords)
{
    const std::integral auto numberOfWords = Number::integer(minNumberOfWords, maxNumberOfWords);

    const auto sentenceWords = words(numberOfWords);

    return FormatHelper::format("{}{}.", static_cast<char>(std::toupper(sentenceWords[0])), sentenceWords.substr(1));
}

std::string Lorem::sentences(unsigned minNumberOfSentences, unsigned maxNumberOfSentences)
{
    const std::integral auto numberOfSentences = Number::integer(minNumberOfSentences, maxNumberOfSentences);

    std::vector<std::string> sentences;
    sentences.reserve(numberOfSentences);

    for (unsigned i = 0; i < numberOfSentences; i++)
    {
        sentences.push_back(sentence());
    }

    return StringHelper::join(sentences, " ");
}

std::string Lorem::slug(unsigned int numberOfWords)
{
    std::vector<std::string> words;
    words.reserve(numberOfWords);

    for (unsigned i = 0; i < numberOfWords; i++)
    {
        words.push_back(std::string(word()));
    }

    return StringHelper::join(words, "-");
}

std::string Lorem::paragraph(unsigned int minNumberOfSentences, unsigned int maxNumberOfSentences)
{
    return sentences(minNumberOfSentences, maxNumberOfSentences);
}

std::string Lorem::paragraphs(unsigned int minNumberOfParagraphs, unsigned int maxNumberOfParagraphs)
{
    const std::integral auto numberOfParagraphs = Number::integer(minNumberOfParagraphs, maxNumberOfParagraphs);

    std::vector<std::string> paragraphs;
    paragraphs.reserve(numberOfParagraphs);

    for (unsigned i = 0; i < numberOfParagraphs; i++)
    {
        paragraphs.push_back(paragraph());
    }

    return StringHelper::join(paragraphs, "\n");
}

}
