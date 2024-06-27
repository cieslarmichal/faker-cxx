#include "faker-cxx/Database.h"

#include <string>
#include <string_view>

#include "DatabaseData.h"
#include "faker-cxx/Helper.h"
#include "faker-cxx/String.h"
#include "faker-cxx/types/Hex.h"

namespace faker::database
{
std::string_view columnName()
{
    return Helper::arrayElement(columnNames);
}

std::string_view columnType()
{
    return Helper::arrayElement(columnTypes);
}

std::string_view collation()
{
    return Helper::arrayElement(collations);
}

std::string_view engine()
{
    return Helper::arrayElement(engines);
}

std::string mongoDbObjectId()
{
    return string::hexadecimal(24, HexCasing::Lower, HexPrefix::None);
}
}
