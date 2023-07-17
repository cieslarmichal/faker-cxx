#include "faker-cxx/Datatype.h"

#include "faker-cxx/Helper.h"

namespace faker
{
bool Datatype::boolean()
{
    return Number::decimal<float>(0.f, 1.f) > 0.5f;
}
}
