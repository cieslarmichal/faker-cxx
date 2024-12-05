#include "faker-cxx/word.h"

#include <map>
#include <optional>
#include <string>
#include <string_view>

#include "faker-cxx/types/locale.h"
#include "word_data.h"

namespace faker::word
{
namespace
{
template <std::ranges::range Range>
auto sortedSizeRandomElement(std::optional<unsigned int> length, Range&& range) -> decltype(auto)
{
    size_t length_64 = *length;
    auto start = range.begin();
    auto end = range.end();

    auto lower_it = ::std::lower_bound(start, end, length_64,
                                       [](const auto& lhs, const auto& value) { return lhs.size() < value; });

    if (lower_it == end)
    {
        return helper::randomElement(range);
    }

    if (lower_it->size() != length)
    {
        return *lower_it;
    }

    auto upper_it = lower_it;

    for (; upper_it != end; upper_it++)
    {
        if (upper_it->size() != lower_it->size())
        {
            break;
        }
    }

    return helper::randomElement(std::ranges::subrange(lower_it, upper_it));
}
}

std::string_view sample(std::optional<unsigned int> length, Locale locale)
{
    unsigned int aux_length{0};

    if (length)
    {
        aux_length = length.value();
    }
    else
    {
        aux_length = 100;
    }

    auto localeLocal = locale;

    if (idiomsMapSpan.find(locale) == idiomsMapSpan.end())
    {
        localeLocal = Locale::en_US;
    }

    auto sorted = _allWords_map.at(localeLocal);

    return sortedSizeRandomElement(aux_length, sorted);
}

std::string words(unsigned numberOfWords, Locale locale)
{
    if (numberOfWords == 0)
    {
        return "";
    }
    auto localeExt = locale;

    if (idiomsMapSpan.find(locale) == idiomsMapSpan.end())
    {
        localeExt = Locale::en_US;
    }
    std::string combined_words;

    unsigned space_words = (numberOfWords - 1);
    for (unsigned i = 0; i < space_words; i++)
    {
        auto s = sample(1, localeExt);
        combined_words.append(s.begin(), s.end());
        combined_words.push_back(' ');
    }

    auto s = sample(1, localeExt);
    combined_words.append(s.begin(), s.end());

    return combined_words;
}

std::string_view adjective(std::optional<unsigned int> length, Locale locale)
{
    unsigned int aux_length{0};
    if (length)
    {
        aux_length = length.value();
    }
    else
    {
        aux_length = 0;
    }
    auto localeLocal = locale;

    if (idiomsMapSpan.find(locale) == idiomsMapSpan.end())
    {
        localeLocal = Locale::en_US;
    }
    auto sorted = _adjetives_sorted_map.at(localeLocal);
    return sortedSizeRandomElement(aux_length, sorted);
}

std::string_view adverb(std::optional<unsigned int> length, Locale locale)
{
    unsigned int aux_length{0};
    if (length)
    {
        aux_length = length.value();
    }
    else
    {
        aux_length = 0;
    }
    auto localeLocal = locale;

    if (idiomsMapSpan.find(locale) == idiomsMapSpan.end())
    {
        localeLocal = Locale::en_US;
    }
    auto sorted = _adverbs_sorted_map.at(localeLocal);
    return sortedSizeRandomElement(aux_length, sorted);
}

std::string_view conjunction(std::optional<unsigned int> length, const faker::Locale locale)
{
    unsigned int aux_length{0};
    if (length)
    {
        aux_length = length.value();
    }
    else
    {
        aux_length = 0;
    }
    auto localeLocal = locale;

    if (idiomsMapSpan.find(locale) == idiomsMapSpan.end())
    {
        localeLocal = Locale::en_US;
    }
    auto sorted = _conjunctions_sorted_map.at(localeLocal);
    return sortedSizeRandomElement(aux_length, sorted);
}

std::string_view interjection(std::optional<unsigned int> length, const faker::Locale locale)
{
    unsigned int aux_length{0};
    if (length)
    {
        aux_length = length.value();
    }
    else
    {
        aux_length = 0;
    }
    auto localeLocal = locale;

    if (idiomsMapSpan.find(locale) == idiomsMapSpan.end())
    {
        localeLocal = Locale::en_US;
    }
    auto sorted = _interjections_sorted_map.at(localeLocal);
    return sortedSizeRandomElement(aux_length, sorted);
}

std::string_view noun(std::optional<unsigned int> length, Locale locale)
{
    unsigned int aux_length{0};
    if (length)
    {
        aux_length = length.value();
    }
    else
    {
        aux_length = 0;
    }
    auto localeLocal = locale;

    if (idiomsMapSpan.find(locale) == idiomsMapSpan.end())
    {
        localeLocal = Locale::en_US;
    }

    auto sorted = _nouns_sorted_map.at(localeLocal);
    return sortedSizeRandomElement(aux_length, sorted);
}

std::string_view preposition(std::optional<unsigned int> length, Locale locale)
{
    unsigned int aux_length{0};
    if (length)
    {
        aux_length = length.value();
    }
    else
    {
        aux_length = 0;
    }
    auto localeLocal = locale;

    if (idiomsMapSpan.find(locale) == idiomsMapSpan.end())
    {
        localeLocal = Locale::en_US;
    }

    auto sorted = _prepositions_sorted_map.at(localeLocal);
    return sortedSizeRandomElement(aux_length, sorted);
}

std::string_view verb(std::optional<unsigned int> length, Locale locale)
{
    unsigned int aux_length{0};
    if (length)
    {
        aux_length = length.value();
    }
    else
    {
        aux_length = 0;
    }
    auto localeLocal = locale;

    if (idiomsMapSpan.find(locale) == idiomsMapSpan.end())
    {
        localeLocal = Locale::en_US;
    }
    auto sorted = (_verbs_sorted_map).at(localeLocal);
    return sortedSizeRandomElement(aux_length, sorted);
}

}
