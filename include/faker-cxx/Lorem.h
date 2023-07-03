#pragma once

#include <string>

namespace faker
{
class Lorem
{
public:
    static std::string word();
    static std::string words(int numberOfWords = 3);
};
}
