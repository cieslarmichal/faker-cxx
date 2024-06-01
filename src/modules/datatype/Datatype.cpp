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
    if (probability != NAN)
    {
        double prob = probability;

        if (prob <= 0.f)
        {
            return false;
        }

        if (prob >= 1.f)
        {
            return true;
        }

        return Number::decimal(0.f, 1.f) < prob;
    }

    return Number::decimal(0.f, 1.f) < 0.5f;
}
}
