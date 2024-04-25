#include "ColumnTypeValueProvider.h"
#include "DqlGenerator.h"

#include "faker-cxx/Helper.h"
#include "faker-cxx/Number.h"

#include <iostream>
#include <vector>

namespace faker
{
std::string DqlGenerator::generate()
{
    // get a random table name
    std::string table = getTable();

    // get random columns
    std::vector<std::string> columns = getColumns();

    std::string dqlStatement = "SELECT ";
    for (unsigned long i = 0; i < columns.size(); i++)
    {
        dqlStatement += FormatHelper::format("[{}]", columns[i]);
        if (i < columns.size() - 1)
        {
            dqlStatement += ", ";
        }
    }

    dqlStatement += " FROM " + table + ";";

    return dqlStatement;
}
}