#pragma once

#include <optional>
#include <string>

namespace faker::internet
{
std::string username(std::optional<std::string> firstName = std::nullopt,
                     std::optional<std::string> lastName = std::nullopt);

std::string email();
}
