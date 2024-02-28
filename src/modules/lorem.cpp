#include "../common/formatter.h"
#include "../common/random.h"
#include "../common/strings.h"
#include "lorem_data.h"
#include <faker/lorem.h>
#include <faker/number.h>

namespace faker::lorem {
std::string_view word() { return random::element(data::lorem_words); }

std::string words(unsigned count)
{
    std::string result;

    for (unsigned i = 0; i < count; i++) {
        if (i > 0) {
            result += ' ';
        }
        result += word();
    }

    return result;
}

std::string sentence(unsigned min_word_count, unsigned max_word_count)
{
    auto result = words(number::integer(min_word_count, max_word_count));
    result[0] = std::toupper(result[0]);
    result += '.';
    return result;
}

std::string sentences(unsigned min_count, unsigned max_count)
{
    auto count = number::integer(min_count, max_count);
    std::string result;

    for (unsigned i = 0; i < count; i++) {
        if (i > 0) {
            result += ' ';
        }
        result += sentence();
    }

    return result;
}

std::string slug(unsigned word_count)
{
    std::string result;

    for (unsigned i = 0; i < word_count; i++) {
        if (i > 0) {
            result += '-';
        }
        result += word();
    }

    return result;
}

std::string paragraph(unsigned min_sentence_count, unsigned max_sentence_count)
{
    return sentences(min_sentence_count, max_sentence_count);
}

std::string paragraphs(unsigned min_count, unsigned max_count)
{
    auto count = number::integer(min_count, max_count);
    std::string result;

    for (unsigned i = 0; i < count; i++) {
        if (i > 0) {
            result += '\n';
        }
        result += paragraph();
    }

    return result;
}

}
