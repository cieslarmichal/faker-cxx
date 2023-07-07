#pragma once

#include <string>

namespace faker
{
class Lorem
{
public:
    static std::string word();
    static std::string words(size_t numberOfWords = 3);
};
}
