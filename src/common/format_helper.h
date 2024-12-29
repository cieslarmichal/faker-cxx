#pragma once

#include <format>
#include <functional>
#include <string>
#include <string_view>
#include <unordered_map>

#include "faker-cxx/export.h"
#include "faker-cxx/types/precision.h"

namespace faker::common
{
template <typename... Args>
std::string format(std::format_string<Args...> fmt, Args&&... args)
{
    return std::format(fmt, std::forward<Args>(args)...);
}

FAKER_CXX_EXPORT std::string precisionFormat(Precision precision, double value);

FAKER_CXX_EXPORT std::string
fillTokenValues(const std::string& format,
                std::unordered_map<std::string, std::function<std::string()>> tokenValueGenerators);

FAKER_CXX_EXPORT std::string
fillTokenValues(const std::string& format,
                std::unordered_map<std::string_view, std::function<std::string_view()>> tokenValueGenerators);
}
