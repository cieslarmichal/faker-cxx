#include "faker-cxx/Database.h"

#include <string>
#include <string_view>

#include "DatabaseData.h"
#include "faker-cxx/Helper.h"
#include "faker-cxx/String.h"
#include "faker-cxx/types/Hex.h"

namespace faker
{
std::string_view Database::columnName()
{
    return Helper::arrayElement(columnNames);
}

std::string_view Database::columnType()
{
    return Helper::arrayElement(columnTypes);
}

std::string_view Database::collation()
{
    return Helper::arrayElement(collations);
}

std::string_view Database::engine()
{
    return Helper::arrayElement(engines);
}

std::string Database::mongoDbObjectId()
{
    return String::hexadecimal(24, HexCasing::Lower, HexPrefix::None);
}
}
