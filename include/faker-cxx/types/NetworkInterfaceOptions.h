#pragma once

#include <optional>
#include <string>
#include <vector>
#include <unordered_map>

namespace faker
{
struct NetworkInterfaceOptions {
    std::optional<std::string> interfaceType;
    std::optional<std::string> interfaceSchema;
};
}
