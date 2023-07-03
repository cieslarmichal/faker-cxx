#include "../helpers/Generator.h"

#include "data/LoremWords.h"
#include "Generator.h"

namespace faker::lorem
{
std::string word()
{
    return helpers::arrayElement(loremWords);
}

std::string words(int numberOfWords)
{
    std::string result;

    for (int i = 0; i < numberOfWords; i++)
    {
        result += " " + helpers::arrayElement(loremWords);
    }

    return result;
}
}
