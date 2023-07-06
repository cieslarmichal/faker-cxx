#include "Lorem.h"

#include <boost/algorithm/string/join.hpp>

#include "data/LoremWords.h"
#include "Helper.h"

namespace faker
{
std::string Lorem::word()
{
    return Helper::arrayElement<std::string>(loremWords);
}

std::string Lorem::words(int numberOfWords)
{
    std::vector<std::string> words;

    for (int i = 0; i < numberOfWords; i++)
    {
        words.push_back(word());
    }

    return boost::algorithm::join(words, " ");
}
}
