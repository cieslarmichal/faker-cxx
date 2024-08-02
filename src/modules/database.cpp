#include "faker-cxx/database.h"

#include <string>
#include <string_view>

#include "database_data.h"
#include "faker-cxx/helper.h"
#include "faker-cxx/string.h"
#include "faker-cxx/types/hex.h"

namespace faker::database
{
std::string_view columnName()
{
    return helper::randomElement(columnNames);
}

std::string_view columnType()
{
    return helper::randomElement(columnTypes);
}

std::string_view collation()
{
    return helper::randomElement(collations);
}

std::string_view engine()
{
    return helper::randomElement(engines);
}

std::string mongoDbObjectId()
{
    return string::hexadecimal(24, HexCasing::Lower, HexPrefix::None);
}
}
