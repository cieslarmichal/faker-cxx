#pragma once

#include <string>

namespace faker::number
{
class NumberDataGenerator
{
public:
    static int integer(int max = 10000, int min = 0);
};
}
