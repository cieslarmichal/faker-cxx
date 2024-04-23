#pragma once

#include "faker-cxx/Database.h"
#include "../data/ColumnData.h"

#include <string>
#include <map>
#include <memory>

namespace faker
{
class ColumnTypeValueProvider
{
private:
    static std::string getAlphaNumericValue();
    static std::string getGenericStringValue();

public:
    static std::string getValue(std::string columnName);
};
}