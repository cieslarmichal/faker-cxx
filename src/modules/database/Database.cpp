#include "faker-cxx/Database.h"

#include "data/Collations.h"
#include "data/ColumnData.h"
#include "data/Engines.h"
#include "data/Tables.h"
#include "faker-cxx/Helper.h"
#include "faker-cxx/String.h"
#include "generators/DqlGenerator.h"
#include "generators/DmlGenerator.h"

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
    std::string command;
    switch (commandType)
    {
        case SqlCommandType::DCL:
            break;
        case SqlCommandType::DDL:
            break;
        case SqlCommandType::TCL:
            break;
        case SqlCommandType::DML:
        {
            DmlGenerator dmlGenerator;
            command = dmlGenerator.generate();
        }
        break;
        case SqlCommandType::DQL:
        {
            DqlGenerator dqlGenerator;
            command = dqlGenerator.generate();
        }
        break;
    }
    return command;
}
}
