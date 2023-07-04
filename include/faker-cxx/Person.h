#pragma once

#include <optional>
#include <string>

#include "Sex.h"

namespace faker
{
class Person
{
public:
    static std::string firstName(std::optional<Sex> = std::nullopt);
    static std::string lastName();
};
}
