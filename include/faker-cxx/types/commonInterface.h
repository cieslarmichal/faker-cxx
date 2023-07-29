#pragma once

#include <string>
#include <vector>
#include <unordered_map>

namespace faker
{
const std::vector<std::string> commonInterfaceTypes = {"en", "wl", "ww"};
const std::unordered_map<std::string, std::string> commonInterfaceSchemas = {
    {"index", "o"},
    {"slot", "s"},
    {"mac", "x"},
    {"pci", "p"}
};
}