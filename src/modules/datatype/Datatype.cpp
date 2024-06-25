#include "faker-cxx/Datatype.h"

#include <cmath>

#include "faker-cxx/Number.h"

namespace faker::datatype
{
bool boolean()
{
    return number::decimal<float>(0.f, 1.f) > 0.5f;
}

bool boolean(double probability)
{
    if (probability != nan(""))
    {
        double prob = probability;

        if (prob <= 0.)
        {
            return false;
        }

        if (prob >= 1.)
        {
            return true;
        }

        return number::decimal(0., 1.) < prob;
    }

    return number::decimal(0., 1.) < 0.5;
}
}
