#include "faker-cxx/word.h"

#include <array>
#include <map>
#include <optional>
#include <string>
#include <string_view>
#include "faker-cxx/types/locale.h"

#include "word_data.h"

namespace faker::word
{



std::string_view sample( std::optional<unsigned int> length,const Locale locale)
{
    unsigned int aux_length{0};
    if(length)   
    {     
        aux_length=length.value();
    }
    else
    {
        aux_length=100;
    }
    auto localeLocal = locale;
    
    if(idiomsMapSpan.find(locale)==idiomsMapSpan.end())
    {
        localeLocal = Locale::en_US;
    }

    auto sorted= _allWords_map.at(localeLocal);
    return sortedSizeRandomElement(aux_length, sorted);

}

std::string words(unsigned numberOfWords,const Locale locale)
{
    if (numberOfWords == 0)
    {
        return "";
    }
    auto localeExt = locale;
    
    if(idiomsMapSpan.find(locale)==idiomsMapSpan.end())
    {
        localeExt = Locale::en_US;
    }
    std::string combined_words;
    if (numberOfWords <= 256)
    {
        std::array<unsigned int, 256> tmp{}; // fitting 1024 bytes worth of integers*
        const size_t last_index = ((_allWords_map.at(localeExt)).size()) - 1;
        size_t reserve_size = 0;

        for (unsigned i = 0; i < numberOfWords; i++)
        {
            tmp[i] = number::integer<unsigned int>(last_index);
            auto vw = (_allWords_map.at(localeExt))[tmp[i]];
            reserve_size += vw.size();
        }

        unsigned space_words = (numberOfWords - 1);
        combined_words.reserve(reserve_size + (numberOfWords - 1));
        for (unsigned i = 0; i < space_words; i++)
        {
            auto vw = (_allWords_map.at(localeExt))[tmp[i]];
            combined_words.append(vw.begin(), vw.end());
            combined_words.push_back(' ');
        }
        auto vw = (_allWords_map.at(localeExt))[tmp[numberOfWords - 1]];
        combined_words.append(vw.begin(), vw.end());
    }
    else
    {
        unsigned space_words = (numberOfWords - 1);
        for (unsigned i = 0; i < space_words; i++)
        {
            auto s = sample(1, localeExt);
            combined_words.append(s.begin(), s.end());
            combined_words.push_back(' ');
        }

        auto s = sample(1, localeExt);
        combined_words.append(s.begin(), s.end());
    }

    return combined_words;
}

std::string_view adjective(std::optional<unsigned int> length,const Locale locale)
{    
    unsigned int aux_length{0};
    if(length)   
    {     
        aux_length=length.value();
    }
    else
    {
        aux_length=0;
    }
    auto localeLocal = locale;
    
    if(idiomsMapSpan.find(locale)==idiomsMapSpan.end())
    {
        localeLocal = Locale::en_US;
    }
    auto sorted= _adjetives_sorted_map.at(localeLocal);
    return sortedSizeRandomElement(aux_length, sorted);
}

std::string_view adverb(std::optional<unsigned int> length, const Locale locale)
{
    unsigned int aux_length{0};
    if(length)   
    {     
        aux_length=length.value();
    }
    else
    {
        aux_length=0;
    }
    auto localeLocal = locale;
    
    if(idiomsMapSpan.find(locale)==idiomsMapSpan.end())
    {
        localeLocal = Locale::en_US;
    }
    auto sorted= _adverbs_sorted_map.at(localeLocal);
    return sortedSizeRandomElement(aux_length, sorted);
}

std::string_view conjunction(std::optional<unsigned int> length, const faker::Locale locale)
{
    unsigned int aux_length{0};
    if(length)   
    {     
        aux_length=length.value();
    }
    else
    {
        aux_length=0;
    }
    auto localeLocal = locale;
    
    if(idiomsMapSpan.find(locale)==idiomsMapSpan.end())
    {
        localeLocal = Locale::en_US;
    }
    auto sorted= _conjunctions_sorted_map.at(localeLocal);
    return sortedSizeRandomElement(aux_length, sorted);
}

std::string_view interjection(std::optional<unsigned int> length, const faker::Locale locale)
{
    unsigned int aux_length{0};
    if(length)   
    {     
        aux_length=length.value();
    }
    else
    {
        aux_length=0;
    }
    auto localeLocal = locale;
    
    if(idiomsMapSpan.find(locale)==idiomsMapSpan.end())
    {
        localeLocal = Locale::en_US;
    }
    auto sorted= _interjections_sorted_map.at(localeLocal);
    return sortedSizeRandomElement(aux_length, sorted);
}

std::string_view noun(std::optional<unsigned int> length, const Locale locale)
{
    unsigned int aux_length{0};
    if(length)   
    {     
        aux_length=length.value();
    }
    else
    {
        aux_length=0;
    }
    auto localeLocal = locale;
    
    if(idiomsMapSpan.find(locale)==idiomsMapSpan.end())
    {
        localeLocal = Locale::en_US;
    }

    auto sorted= _nouns_sorted_map.at(localeLocal);
    return sortedSizeRandomElement(aux_length, sorted);    
}

std::string_view preposition(std::optional<unsigned int> length, const Locale locale)
{
    unsigned int aux_length{0};
    if(length)   
    {     
        aux_length=length.value();
    }
    else
    {
        aux_length=0;
    }
    auto localeLocal = locale;
    
    if(idiomsMapSpan.find(locale)==idiomsMapSpan.end())
    {
        localeLocal = Locale::en_US;
    }

    auto sorted=_prepositions_sorted_map.at(localeLocal);
    return sortedSizeRandomElement(aux_length, sorted);
}

std::string_view verb(std::optional<unsigned int> length, const Locale locale)
{    
    unsigned int aux_length{0};
    if(length)   
    {     
        aux_length=length.value();
    }
    else
    {
        aux_length=0;
    }
    auto localeLocal = locale;
    
    if(idiomsMapSpan.find(locale)==idiomsMapSpan.end())
    {
        localeLocal = Locale::en_US;
    }
    auto sorted=(_verbs_sorted_map).at(localeLocal);
    return sortedSizeRandomElement(aux_length, sorted);
}

}
