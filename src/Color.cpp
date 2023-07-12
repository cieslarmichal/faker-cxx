#include "Color.h"

#include "data/Colors.h"
#include "Helper.h"

namespace faker
{
std::string Color::name()
{
    return Helper::arrayElement<std::string>(colors);
}
}
