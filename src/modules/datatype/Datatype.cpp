#include "faker-cxx/Datatype.h"

#include <cmath>

#include "faker-cxx/Number.h"

namespace faker
{
bool Datatype::boolean()
{
    return Number::decimal<float>(0.f, 1.f) > 0.5f;
}

bool Datatype::boolean(double probability)
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

        return Number::decimal(0., 1.) < prob;
    }

    return Number::decimal(0., 1.) < 0.5;
}
}
