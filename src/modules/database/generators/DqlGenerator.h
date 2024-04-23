#pragma once

#include "BaseGenerator.h"

#include <string>

namespace faker
{
class DqlGenerator : BaseGenerator
{
public:
    DqlGenerator() : BaseGenerator(SqlCommandType::DQL) { }
    DqlGenerator(const DqlGenerator& dqlGenerator) : BaseGenerator(dqlGenerator.CommandType) {}

    std::string generate() override;
};
}