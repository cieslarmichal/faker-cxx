#pragma once

#include "BaseGenerator.h"

#include <string>
#include <vector>

namespace faker
{
class DmlGenerator : BaseGenerator
{
public:
    DmlGenerator() : BaseGenerator(SqlCommandType::DML) { }
    DmlGenerator(const DmlGenerator& dmlGenerator) : BaseGenerator(dmlGenerator.CommandType) {}

    std::string generate() override;
};
}