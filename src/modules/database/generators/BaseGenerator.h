#pragma once

#include "faker-cxx/Database.h"
#include "faker-cxx/Helper.h"
#include "faker-cxx/Number.h"

#include <iostream>
#include <string>
#include <vector>

namespace faker
{
class BaseGenerator
{
protected:
    SqlCommandType CommandType;
    BaseGenerator(SqlCommandType commandType)
    {
        this->CommandType = commandType;
    }

    inline std::vector<std::string> getColumns()
    {
        std::vector<std::string> columns;
        unsigned long count = static_cast<unsigned int>(Number::integer(1, static_cast<int>(columnNames.size())));
        const auto& columnIndices = Number::indices(columnNames.size(), count);
        for (unsigned int i = 0; i < columnIndices.size(); i++)
        {
            columns.push_back(Helper::arrayElement(faker::columnNames));
        }
        return columns;
    }

    inline std::string getTable()
    {
        return "[" + Database::table() + "]";
    }
public:
    virtual std::string generate() = 0;
};
}
