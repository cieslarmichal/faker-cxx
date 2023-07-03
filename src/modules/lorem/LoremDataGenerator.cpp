#include "LoremDataGenerator.h"

#include "../helpers/HelperDataGenerator.h"
#include "data/LoremWords.h"

namespace faker::lorem
{
std::string LoremDataGenerator::word()
{
    return helpers::HelperDataGenerator::arrayElement(loremWords);
}

std::string LoremDataGenerator::words(int numberOfWords)
{
    std::string result;

    for (int i = 0; i < numberOfWords; i++)
    {
        result += " " + helpers::HelperDataGenerator::arrayElement(loremWords);
    }

    return result;
}
}
