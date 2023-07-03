#pragma once

#include <string>

namespace faker::number
{
class NumberDataGenerator
{
public:
    static int integer(int min = 0, int max = 10000);
};
}
