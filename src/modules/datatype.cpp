#include "faker-cxx/datatype.h"

#include "faker-cxx/number.h"

namespace faker::datatype
{
bool boolean()
{
    return number::decimal<float>(0.f, 1.f) > 0.5f;
}

bool boolean(double probability)
{
    if (probability <= double(0))
    {
        return false;
    }

    if (probability >= double(1))
    {
        return true;
    }

    return number::decimal(0., 1.) < probability;
}
}
