#pragma once

#include "faker-cxx/Database.h"
#include "faker-cxx/Helper.h"
#include "faker-cxx/Number.h"
#include "faker-cxx/types/Country.h"
#include "faker-cxx/types/Sex.h"
#include "../data/ColumnData.h"
#include "../src/common/FormatHelper.h"

#include <string>
#include <vector>

namespace faker
{
class BaseGenerator
{
protected:
    SqlCommandType CommandType;
    faker::Country country;
    faker::Sex sex;

    BaseGenerator(SqlCommandType commandType)
    {
        this->CommandType = commandType;
        this->country = Helper::arrayElement<faker::Country>(faker::countries);
        this->sex = Helper::arrayElement<faker::Sex>({ faker::Sex::Male, faker::Sex::Female });
    }

    inline std::vector<std::string> getColumns()
    {
        std::vector<std::string> columns;
        unsigned long count = static_cast<unsigned int>(Number::integer(1, static_cast<int>(columnNames.size())));
        const auto& columnIndices = Number::indices(columnNames.size(), count);
        for (unsigned int i = 0; i < columnIndices.size(); i++)
        {
            columns.push_back(faker::columnNames[columnIndices[i]]);
        }
        return columns;
    }

    inline std::string getTable()
    {
        return FormatHelper::format("[{}]", Database::table());
    }
public:
    virtual std::string generate() = 0;
};
}
