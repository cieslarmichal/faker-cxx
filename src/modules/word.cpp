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
std::string_view sample( std::optional<unsigned int> length,const faker::Locale locale)
{
    if(length)    
        return sampleLocale(length.value(),locale);
    else
        return sampleLocale(0,locale);

}

std::string_view sampleLocale(unsigned int length, const faker::Locale locale)
{
    if(length==0){
        length=100;
        }
    
    if(_allWords_map.find(locale)==_allWords_map.end())
    {
        auto localeLocal = faker::Locale::en_US;
        auto sorted= _allWords_map.at(localeLocal);
        return sortedSizeRandomElement(length, sorted);
    }
    else
    {
    auto sorted= _allWords_map.at(locale);
    return sortedSizeRandomElement(length, sorted);
    }
}

std::string words(unsigned numberOfWords,const faker::Locale locale)
{
    if (numberOfWords == 0)
    {
        return "";
    }
    return wordsLocale(numberOfWords,locale);
}

std::string wordsLocale(unsigned numberOfWords,faker::Locale locale)
{
    auto localeExt = locale;
    if (numberOfWords == 0)
    {
        return "";
    }
    if(_allWords_map.find(locale)==_allWords_map.end())
    {
        localeExt = faker::Locale::en_US;
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
            auto s = sampleLocale(1, localeExt);
            combined_words.append(s.begin(), s.end());
            combined_words.push_back(' ');
        }

        auto s = sampleLocale(1, localeExt);
        combined_words.append(s.begin(), s.end());
    }

    return combined_words;
}

std::string_view adjective(std::optional<unsigned int> length,const faker::Locale locale)
{    
    if(length)        
        return adjectiveLocale(length.value(),locale);
    else
        return adjectiveLocale(0,locale);
}

std::string_view adjectiveLocale(unsigned int length, const faker::Locale locale)
{
    if(length==0)
    {
        length=100;
    }

    auto localeLocal = locale;
    if(_allWords_map.find(locale)==_allWords_map.end())
    {
        localeLocal = faker::Locale::en_US;
    }    
    auto sorted= _adjetives_sorted_map.at(localeLocal);
    return sortedSizeRandomElement(length, sorted);
}

std::string_view adverb(std::optional<unsigned int> length, const faker::Locale locale)
{
    //return sortedSizeRandomElement(length, _adverbs_sorted);
    if(length)        
        return adverbLocale(length.value(),locale);
    else
        return adverbLocale(0,locale);
}

std::string_view adverbLocale(unsigned int length, const faker::Locale locale)
{
    if(length==0)
    {
        length=100;
    }
    auto localeLocal = locale;
    if(_allWords_map.find(locale)==_allWords_map.end())
    {
        localeLocal = faker::Locale::en_US;
    }    
    auto sorted= _adverbs_sorted_map.at(localeLocal);
    return sortedSizeRandomElement(length, sorted);
}

std::string_view conjunction(std::optional<unsigned int> length, const faker::Locale locale)
{
    if(length)        
        return conjunctionLocale(length.value(),locale);
    else
        return conjunctionLocale(0,locale);
    
}

std::string_view conjunctionLocale(unsigned int length, const faker::Locale locale)
{
    if(length==0)
    {
        length=100;
    }
    auto localeLocal = locale;
    if(_allWords_map.find(locale)==_allWords_map.end())
    {
        localeLocal = faker::Locale::en_US;
    }    
    auto sorted= _conjunctions_sorted_map.at(localeLocal);
    return sortedSizeRandomElement(length, sorted);
}

std::string_view interjection(std::optional<unsigned int> length, const faker::Locale locale)
{
    if(length)        
        return interjectionLocale(length.value(),locale);
    else
        return interjectionLocale(0,locale);
    
}

std::string_view interjectionLocale(unsigned int length, const faker::Locale locale) 
{
    if(length==0)
    {
        length=100;
    }
    auto localeLocal = locale;
    if(_allWords_map.find(locale)==_allWords_map.end())
    {
        localeLocal = faker::Locale::en_US;
    }    
    auto sorted= _interjections_sorted_map.at(localeLocal);
    return sortedSizeRandomElement(length, sorted);
}

std::string_view noun(std::optional<unsigned int> length, const faker::Locale locale)
{
    
    if(length)                
        return nounLocale(length.value(),locale);
    else
        return nounLocale(0,locale);
    
}

std::string_view nounLocale(unsigned int length, const faker::Locale locale)
{
    if(length==0)
    {
        length=100;
    }
    auto localeLocal = locale;
    if(_allWords_map.find(locale)==_allWords_map.end())
    {
        localeLocal = faker::Locale::en_US;
    }    
    auto sorted= _nouns_sorted_map.at(localeLocal);
    return sortedSizeRandomElement(length, sorted);
}

std::string_view preposition(std::optional<unsigned int> length, const faker::Locale locale)
{
    
    if(length)
        
        return prepositionLocale(length.value(),locale);
    else
        return prepositionLocale(0,locale);
}

std::string_view prepositionLocale(unsigned int length, const faker::Locale locale)
{
    if(length==0)
    {
        length=100;
    }
    auto localeLocal = locale;
    if(_allWords_map.find(locale)==_allWords_map.end())
    {
        localeLocal = faker::Locale::en_US;
    }    
    auto sorted=_prepositions_sorted_map.at(localeLocal);
    return sortedSizeRandomElement(length, sorted);
}

std::string_view verb(std::optional<unsigned int> length, const faker::Locale locale)
{    
    if(length)
        
        return verbLocale(length.value(),locale);
    else
        return verbLocale(0,locale);
}

std::string_view verbLocale(unsigned int length, const faker::Locale locale)
{
    if(length==0)
    {
        length=100;
    }
    auto localeLocal = locale;
    if(_allWords_map.find(locale)==_allWords_map.end())
    {
        localeLocal = faker::Locale::en_US;
    }    

    auto sorted=(_verbs_sorted_map).at(localeLocal);
    return sortedSizeRandomElement(length, sorted);}
}
