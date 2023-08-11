#pragma once

#include <optional>
#include <string>
#include <unordered_map>
#include <vector>

namespace faker
{
struct NetworkInterfaceOptions
{
    std::optional<std::string> interfaceType;
    std::optional<std::string> interfaceSchema;
};
}
