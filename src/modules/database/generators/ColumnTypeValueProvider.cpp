#include "ColumnTypeValueProvider.h"

#include "faker-cxx/Lorem.h"
#include "faker-cxx/String.h"

namespace faker
{

std::string ColumnTypeValueProvider::getAlphaNumericValue()
{
    return "'" + String::alphanumeric() + "'";
}

std::string ColumnTypeValueProvider::getGenericStringValue()
{
    return "'" + Lorem::sentence() + "'";
}

std::string ColumnTypeValueProvider::getValue(std::string columnName)
{
    const auto iter1 = faker::columnTypeGeneratorMap.find(columnName);
    if (iter1 == faker::columnTypeGeneratorMap.end())
        throw;
    faker::DataGeneratorType generator = iter1->second;

    switch (generator)
    {
        case faker::DataGeneratorType::AlphaNumeric:
            return getAlphaNumericValue();
        default:
            return getGenericStringValue();
    }
}

}