#pragma once

#include <optional>
#include <string>

namespace faker
{
enum class Sex
{
    Male,
    Female,
};

class Person
{
public:
    static std::string firstName(std::optional<Sex> = std::nullopt);
    static std::string lastName();
    static std::string fullName(std::optional<Sex> = std::nullopt);
};
}
