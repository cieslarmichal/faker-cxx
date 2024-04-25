#include "DmlGenerator.h"
#include "ColumnTypeValueProvider.h"

#include "faker-cxx/Number.h"

namespace faker
{

std::string DmlGenerator::generate()
{
        // get a random table name
    std::string table = getTable();

    // get random columns
    std::vector<std::string> columns = getColumns();

    std::string dmlStatement;

    auto dmlSubType = Number::integer(1, 3);

    switch (dmlSubType)
    {
        case 1: // INSERT
            dmlStatement = generateInsertStatement(table, columns);
            break;
        case 2: // UPDATE
            dmlStatement = generateUpdateStatement(table, columns);
            break;
        case 3: // DELETE
            dmlStatement = generateDeleteStatement(table);
            break;
        default:
            break;
    }

    return dmlStatement;
}

std::string DmlGenerator::generateInsertStatement(std::string table, const std::vector<std::string>& columns)
{
    std::string dmlStatement = "INSERT INTO " + table + " (";
    
    std::vector<std::string> columnValues;
    for (unsigned long i = 0; i < columns.size(); i++)
    {
        dmlStatement += columns[i];
        if (i < columns.size() - 1)
        {
            dmlStatement += ", ";
        }
        else
        {
            dmlStatement += ") ";
        }
        std::string columnValue = ColumnTypeValueProvider::getValue(columns[i], country, sex);
        columnValues.push_back(columnValue);
    }

    dmlStatement += " VALUES (";

    for (unsigned long i = 0; i < columnValues.size(); i++)
    {
        dmlStatement += columnValues[i];
        if (i < columnValues.size() - 1)
        {
            dmlStatement += ", ";
        }
        else
        {
            dmlStatement += ");";
        }
    }

    return dmlStatement;
}

std::string DmlGenerator::generateUpdateStatement(std::string table, const std::vector<std::string>& columns)
{
    std::string dmlStatement = "UPDATE " + table + " SET ";

    for (unsigned long i = 0; i < columns.size(); i++)
    {
        std::string columnValue = ColumnTypeValueProvider::getValue(columns[i], country, sex);
        dmlStatement += columns[i] + " = " + columnValue;

        if (i < columns.size() - 1)
        {
            dmlStatement += ", ";
        }
    }

    dmlStatement += " WHERE [id] = " + ColumnTypeValueProvider::getValue("id", country, sex);
    
    return dmlStatement;
}

std::string DmlGenerator::generateDeleteStatement(std::string table)
{
    std::string dmlStatement = "DELETE FROM " + table + " WHERE [id] = " + ColumnTypeValueProvider::getValue("id", country, sex);
    return dmlStatement;
}

}