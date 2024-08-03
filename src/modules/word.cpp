#include "faker-cxx/word.h"

#include <array>
#include <optional>
#include <string>
#include <string_view>

#include "word_data.h"

namespace faker::word
{
std::string_view sample(std::optional<unsigned int> length)
{
    return sortedSizeRandomElement(length, _allWords);
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
    return sortedSizeRandomElement(length, _adjectives_sorted);
}

std::string_view adverb(std::optional<unsigned int> length)
{
    return sortedSizeRandomElement(length, _adverbs_sorted);
}

std::string_view conjunction(std::optional<unsigned int> length)
{
    return sortedSizeRandomElement(length, _conjunctions_sorted);
}

std::string_view interjection(std::optional<unsigned int> length)
{
    return sortedSizeRandomElement(length, _interjections_sorted);
}

std::string_view noun(std::optional<unsigned int> length)
{
    return sortedSizeRandomElement(length, _nouns_sorted);
}

std::string_view preposition(std::optional<unsigned int> length)
{
    return sortedSizeRandomElement(length, _prepositions_sorted);
}

std::string_view verb(std::optional<unsigned int> length)
{
    return sortedSizeRandomElement(length, _verbs_sorted);
}
}
