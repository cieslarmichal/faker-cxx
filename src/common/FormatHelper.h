#pragma once

#include <functional>
#include <string>
#include <string_view>
#include <unordered_map>

#include "faker-cxx/types/Precision.h"

#if !defined(HAS_STD_FORMAT)
#include <fmt/chrono.h>
#include <fmt/core.h>
#else
#include <format>

#endif

namespace faker
{
class FormatHelper
{
public:
#if !defined(HAS_STD_FORMAT)
    template <typename... Args>
    static std::string format(fmt::format_string<Args...> fmt, Args&&... args)
    {
        return fmt::format(fmt, std::forward<Args>(args)...);
    }
#else
    template <typename... Args>
    static std::string format(std::format_string<Args...> fmt, Args&&... args)
    {
        return std::format(fmt, std::forward<Args>(args)...);
    }
#endif

    static std::string precisionFormat(Precision precision, double value);

    static std::string
    fillTokenValues(const std::string& format,
                    std::unordered_map<std::string, std::function<std::string()>> tokenValueGenerators);

    static std::string
    fillTokenValues(const std::string& format,
                    std::unordered_map<std::string_view, std::function<std::string_view()>> tokenValueGenerators);
};
}
