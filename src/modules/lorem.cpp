#include "../common/formatter.h"
#include "../common/helper.h"
#include "../common/strings.h"
#include "lorem_data.h"
#include <faker/lorem.h>

namespace faker::lorem {
std::string_view word() { return Helper::arrayElement(data::loremWords); }

std::string words(unsigned numberOfWords)
{
    std::string result;

    for (unsigned i = 0; i < numberOfWords; i++) {
        if (i > 0) {
            result += ' ';
        }
        result += word();
    }

    return result;
}

std::string sentence(unsigned minNumberOfWords, unsigned maxNumberOfWords)
{
    const auto numberOfWords = number::integer(minNumberOfWords, maxNumberOfWords);

    const auto sentenceWords = words(numberOfWords);

    return utils::format(
        "{}{}.", static_cast<char>(std::toupper(sentenceWords[0])), sentenceWords.substr(1));
}

std::string sentences(unsigned minNumberOfSentences, unsigned maxNumberOfSentences)
{
    const auto numberOfSentences = number::integer(minNumberOfSentences, maxNumberOfSentences);

    std::vector<std::string> sentences;

    for (unsigned i = 0; i < numberOfSentences; i++) {
        sentences.push_back(sentence());
    }

    return utils::join(sentences, " ");
}

std::string slug(unsigned int numberOfWords)
{
    std::string result;

    for (unsigned i = 0; i < numberOfWords; i++) {
        if (i > 0) {
            result += '-';
        }
        result += word();
    }

    return result;
}

std::string paragraph(unsigned int minNumberOfSentences, unsigned int maxNumberOfSentences)
{
    return sentences(minNumberOfSentences, maxNumberOfSentences);
}

std::string paragraphs(unsigned int minNumberOfParagraphs, unsigned int maxNumberOfParagraphs)
{
    const auto numberOfParagraphs = number::integer(minNumberOfParagraphs, maxNumberOfParagraphs);

    std::vector<std::string> paragraphs;

    for (unsigned i = 0; i < numberOfParagraphs; i++) {
        paragraphs.push_back(paragraph());
    }

    return utils::join(paragraphs, "\n");
}

}
