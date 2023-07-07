#include "Lorem.h"

#include <sstream>

#include "data/LoremWords.h"
#include "Helper.h"

namespace faker
{
std::string Lorem::word()
{
    return Helper::arrayElement<std::string>(loremWords);
}

std::string Lorem::words(size_t numberOfWords)
{
    std::ostringstream words_accumulator;

    for (size_t i = 0; i < (numberOfWords - 1); ++i)
    {
        words_accumulator << word() << " ";
    }

    if (numberOfWords > 0) [[likely]]
    {
        words_accumulator << word();
    }

    return words_accumulator.str();
}
}
