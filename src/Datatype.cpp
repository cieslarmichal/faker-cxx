#include "Datatype.h"

#include "Helper.h"

namespace faker
{
bool Datatype::boolean()
{
    return Helper::arrayElement(std::vector<bool>{true, false});
}
}
