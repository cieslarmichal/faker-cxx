#include "Lorem.h"

#include "data/LoremWords.h"
#include "Helper.h"

namespace faker
{
std::string Lorem::word()
{
    return Helper::arrayElement(loremWords);
}

std::string Lorem::words(int numberOfWords)
{
    std::string result;

    for (int i = 0; i < numberOfWords; i++)
    {
        result += " " + Helper::arrayElement(loremWords);
    }

    return result;
}
}
