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

const std::vector<std::string> commonInterfaceTypes = {"en", "wl", "ww"};
const std::unordered_map<std::string, std::string> commonInterfaceSchemas = {
    {"index", "o"},
    {"slot", "s"},
    {"mac", "x"},
    {"pci", "p"}
};

}
