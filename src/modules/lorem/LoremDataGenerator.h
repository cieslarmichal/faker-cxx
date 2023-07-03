#pragma once

#include <string>

namespace faker::lorem
{
class LoremDataGenerator
{
public:
    static std::string word();
    static std::string words(int numberOfWords = 3);
};
}
