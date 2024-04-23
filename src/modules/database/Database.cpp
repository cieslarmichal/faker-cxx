#include "faker-cxx/Database.h"

#include "data/Collations.h"
#include "data/ColumnData.h"
#include "data/Engines.h"
#include "data/Tables.h"
#include "faker-cxx/Helper.h"
#include "faker-cxx/String.h"
#include "generators/DqlGenerator.h"

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

std::string Database::table()
{
    return Helper::arrayElement<std::string>(tables);
}

std::string Database::sqlCommand(SqlCommandType commandType)
{
    switch (commandType)
    {
        case SqlCommandType::DCL:
        case SqlCommandType::DDL:
        case SqlCommandType::DML:
        case SqlCommandType::TCL:
        case SqlCommandType::DQL:
            DqlGenerator generator;
            return generator.generate();
    }
}
}
