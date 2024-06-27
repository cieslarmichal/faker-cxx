#include "faker-cxx/Word.h"

#include <algorithm>
#include <array>
#include <optional>
#include <string>
#include <string_view>

#include "faker-cxx/Helper.h"
#include "WordData.h"

namespace faker::word
{
template <typename It>
auto sortedSizeArrayElement(std::optional<unsigned int> length, It start, It end) -> decltype(*std::declval<It>())
{
    if (!length)
    {
        return helper::arrayElement(start, end);
    }

    size_t length_64 = *length;
    auto lower_it = ::std::lower_bound(start, end, length_64,
                                       [](const auto& lhs, const auto& value) { return lhs.size() < value; });

    if (lower_it == end)
    {
        return helper::arrayElement(start, end);
    }

    if (lower_it->size() != length)
    {
        return helper::arrayElement(start, end);
    }

    auto upper_it = lower_it;

    for (; upper_it != end; upper_it++)
    {
        if (upper_it->size() != lower_it->size())
        {

            break;
        }
    }

    return helper::arrayElement(lower_it, upper_it);
}

std::string_view sample(std::optional<unsigned int> length)
{
    return sortedSizeArrayElement(length, _allWords.cbegin(), _allWords.cend());
}

std::string words(unsigned numberOfWords)
{
    if (numberOfWords == 0)
    {
        return "";
    }

    std::string combined_words;
    if (numberOfWords <= 256)
    {
        std::array<unsigned int, 256> tmp{}; // fitting 1024 bytes worth of integers*
        const size_t last_index = _allWords.size() - 1;
        size_t reserve_size = 0;

        for (unsigned i = 0; i < numberOfWords; i++)
        {
            tmp[i] = number::integer<unsigned int>(last_index);
            auto vw = _allWords[tmp[i]];
            reserve_size += vw.size();
        }

        unsigned space_words = (numberOfWords - 1);
        combined_words.reserve(reserve_size + (numberOfWords - 1));
        for (unsigned i = 0; i < space_words; i++)
        {
            auto vw = _allWords[tmp[i]];
            combined_words.append(vw.begin(), vw.end());
            combined_words.push_back(' ');
        }
        auto vw = _allWords[tmp[numberOfWords - 1]];
        combined_words.append(vw.begin(), vw.end());
    }
    else
    {
        unsigned space_words = (numberOfWords - 1);
        for (unsigned i = 0; i < space_words; i++)
        {
            auto s = sample();
            combined_words.append(s.begin(), s.end());
            combined_words.push_back(' ');
        }

        auto s = sample();
        combined_words.append(s.begin(), s.end());
    }

    return combined_words;
}

std::string_view adjective(std::optional<unsigned int> length)
{
    return sortedSizeArrayElement(length, _adjectives_sorted.cbegin(), _adjectives_sorted.cend());
}

std::string_view adverb(std::optional<unsigned int> length)
{
    return sortedSizeArrayElement(length, _adverbs_sorted.cbegin(), _adverbs_sorted.cend());
}

std::string_view conjunction(std::optional<unsigned int> length)
{
    return sortedSizeArrayElement(length, _conjunctions_sorted.cbegin(), _conjunctions_sorted.cend());
}

std::string_view interjection(std::optional<unsigned int> length)
{
    return sortedSizeArrayElement(length, _interjections_sorted.cbegin(), _interjections_sorted.cend());
}

std::string_view noun(std::optional<unsigned int> length)
{
    return sortedSizeArrayElement(length, _nouns_sorted.cbegin(), _nouns_sorted.cend());
}

std::string_view preposition(std::optional<unsigned int> length)
{
    return sortedSizeArrayElement(length, _prepositions_sorted.cbegin(), _prepositions_sorted.cend());
}

std::string_view verb(std::optional<unsigned int> length)
{
    return sortedSizeArrayElement(length, _verbs_sorted.cbegin(), _verbs_sorted.cend());
}
}
