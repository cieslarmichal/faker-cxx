#include "faker-cxx/Database.h"

#include "data/Collations.h"
#include "data/ColumnNames.h"
#include "data/ColumnTypes.h"
#include "data/Engines.h"
#include "faker-cxx/Helper.h"
#include "faker-cxx/String.h"

namespace faker
{
std::string Database::columnName()
{
    return Helper::arrayElement<std::string>(columnNames);
}

std::string Database::columnType()
{
    return Helper::arrayElement<std::string>(columnTypes);
}

std::string Database::collation()
{
    return Helper::arrayElement<std::string>(collations);
}

std::string Database::engine()
{
    return Helper::arrayElement<std::string>(engines);
}

std::string Database::mongoDbObjectId()
{
    return String::hexadecimal(24, HexCasing::Lower, HexPrefix::None);
}
}
