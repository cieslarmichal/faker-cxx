#include "Datatype.h"

#include "Helper.h"

namespace faker
{
bool Datatype::boolean()
{
    return Number::decimal<float>(0., 1.) > 0.5;
}
}
