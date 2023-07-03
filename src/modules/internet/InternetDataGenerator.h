#pragma once

#include <optional>
#include <string>

namespace faker::person
{
class InternetDataGenerator
{
public:
    static std::string username(std::optional<std::string> firstName, std::optional<std::string> lastName);

    static std::string email();
};
}
