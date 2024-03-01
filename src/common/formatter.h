#ifndef FAKER_COMMON_FORMAT_HELPER_H
#define FAKER_COMMON_FORMAT_HELPER_H

#include <faker/types/precision.h>
#include <functional>
#include <string>

#if defined(__APPLE__) || defined(__MINGW32__)                                                     \
    || (defined(__GNUC__) && (__GNUC__ < 12) && !defined(__clang__))
#undef USE_STD_FORMAT
#else
#define USE_STD_FORMAT 1
#endif

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

std::string_view precision_format_str(precision_t prec);

}

#endif