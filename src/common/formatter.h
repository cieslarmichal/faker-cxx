#ifndef FAKER_COMMON_FORMAT_HELPER_H
#define FAKER_COMMON_FORMAT_HELPER_H

#include <faker/types/precision.h>
#include <functional>
#include <string>

#ifdef USE_STD_FORMAT
#include <format>
#else
#include <fmt/chrono.h>
#include <fmt/core.h>
#endif

namespace faker::utils {
#ifdef USE_STD_FORMAT
template <typename... Args> std::string format(std::format_string<Args...> fmt, Args&&... args)
{
    return std::format(fmt, std::forward<Args>(args)...);
}
#else
template <typename... Args> std::string format(fmt::format_string<Args...> fmt, Args&&... args)
{
    return fmt::format(fmt, std::forward<Args>(args)...);
}
#endif

std::string fill_token_values(
    std::string_view format, std::function<std::string(std::string_view)> tokenValueGenerator);

inline std::string fill_token_values(
    const char* format, std::function<std::string(std::string_view)> tokenValueGenerator)
{
    return fill_token_values(std::string_view(format), tokenValueGenerator);
}

std::string fill_token_values(
    const std::string& format, std::function<std::string(std::string_view)> tokenValueGenerator);

std::string precision_format(precision_t prec, double value);

}

#endif