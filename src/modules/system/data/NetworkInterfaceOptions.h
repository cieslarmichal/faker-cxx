#pragma once

#include <optional>
#include <string>

namespace faker
{
struct NetworkInterfaceOptions {
    std::optional<std::string> interfaceType;
    std::optional<std::string> interfaceSchema;
};
}
