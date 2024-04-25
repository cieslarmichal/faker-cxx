#pragma once

#include "BaseGenerator.h"

#include <string>
#include <vector>

namespace faker
{
class DmlGenerator : BaseGenerator
{
private:
    std::string generateInsertStatement(std::string table, const std::vector<std::string>& columns);
    std::string generateUpdateStatement(std::string table, const std::vector<std::string>& columns);
    std::string generateDeleteStatement(std::string table);
public:
    DmlGenerator() : BaseGenerator(SqlCommandType::DML) { }
    DmlGenerator(const DmlGenerator& dmlGenerator) : BaseGenerator(dmlGenerator.CommandType) {}

    std::string generate() override;
};
}