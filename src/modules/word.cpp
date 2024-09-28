#include "faker-cxx/word.h"

#include <array>
#include <map>
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

std::string_view sampleL(unsigned int length, const faker::Locale locale)
{
    if(length==0){
        length=100;
        }
    auto sorted= _allWords_map.at(locale);
    return sortedSizeRandomElement(length, sorted);
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

std::string wordsL(unsigned numberOfWords,faker::Locale locale)
{
    if (numberOfWords == 0)
    {
        return "";
    }

    std::string combined_words;
    if (numberOfWords <= 256)
    {
        std::array<unsigned int, 256> tmp{}; // fitting 1024 bytes worth of integers*
        const size_t last_index = (_allWords_map.at(locale)).size() - 1;
        size_t reserve_size = 0;

        for (unsigned i = 0; i < numberOfWords; i++)
        {
            tmp[i] = number::integer<unsigned int>(last_index);
            auto vw = (_allWords_map.at(locale))[tmp[i]];
            reserve_size += vw.size();
        }

        unsigned space_words = (numberOfWords - 1);
        combined_words.reserve(reserve_size + (numberOfWords - 1));
        for (unsigned i = 0; i < space_words; i++)
        {
            auto vw = (_allWords_map.at(locale))[tmp[i]];
            combined_words.append(vw.begin(), vw.end());
            combined_words.push_back(' ');
        }
        auto vw = (_allWords_map.at(locale))[tmp[numberOfWords - 1]];
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
    if(length)
        
        return adjectiveL(length.value());
    else
        return adjectiveL();
}

std::string_view adjectiveL(unsigned int length, const faker::Locale locale)
{
    if(length==0){
        length=100;
        }
    auto sorted= _adjetives_sorted_map.at(locale);
    return sortedSizeRandomElement(length, sorted);
}

std::string_view adverb(std::optional<unsigned int> length)
{
    //return sortedSizeRandomElement(length, _adverbs_sorted);
    if(length)
        
        return adverbL(length.value());
    else
        return adverbL();
}

std::string_view adverbL(unsigned int length, const faker::Locale locale)
{
    if(length==0){
        length=100;
        }
    auto sorted= _adverbs_sorted_map.at(locale);
    return sortedSizeRandomElement(length, sorted);
}

std::string_view conjunction(std::optional<unsigned int> length)
{
    if(length)
        
        return conjunctionL(length.value());
    else
        return conjunctionL();
    
}

std::string_view conjunctionL(unsigned int length, const faker::Locale locale)
{
    if(length==0){length=100;}    
    auto sorted= _conjunctions_sorted_map.at(locale);
    return sortedSizeRandomElement(length, sorted);
}

std::string_view interjection(std::optional<unsigned int> length)
{
    //return sortedSizeRandomElement(length, _interjections_sorted);

    if(length)
        
        return interjectionL(length.value());
    else
        return interjectionL();
    
}

std::string_view interjectionL(unsigned int length, const faker::Locale locale) 
{
    if(length==0){length=100;}
    auto sorted= _interjections_sorted_map.at(locale);
    return sortedSizeRandomElement(length, sorted);
}

std::string_view noun(std::optional<unsigned int> length)
{
    
    if(length)
        
        return nounL(length.value());
    else
        return nounL();
    
}

std::string_view nounL(unsigned int length, const faker::Locale locale)
{
    if(length==0){length=100;}
    auto sorted= _nouns_sorted_map.at(locale);
    return sortedSizeRandomElement(length, sorted);
}

std::string_view preposition(std::optional<unsigned int> length)
{
    
    if(length)
        
        return prepositionL(length.value());
    else
        return prepositionL();
}

std::string_view prepositionL(unsigned int length, const faker::Locale locale)
{
    if(length==0){length=100;}
    auto sorted=_prepositions_sorted_map.at(locale);
    return sortedSizeRandomElement(length, sorted);
}

std::string_view verb(std::optional<unsigned int> length)
{    
    if(length)
        
        return verbL(length.value());
    else
        return verbL();
}

std::string_view verbL(unsigned int length, const faker::Locale locale)
{
    if(length==0){length=100;}

    auto sorted=(_verbs_sorted_map).at(locale);
    return sortedSizeRandomElement(length, sorted);}
}
