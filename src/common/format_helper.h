#ifndef FAKER_COMMON_FORMAT_HELPER_H
#define FAKER_COMMON_FORMAT_HELPER_H

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

namespace faker {
class FormatHelper {
public:
#ifdef USE_STD_FORMAT
    template <typename... Args>
    static std::string format(std::format_string<Args...> fmt, Args&&... args)
    {
        return std::format(fmt, std::forward<Args>(args)...);
    }
#else
    template <typename... Args>
    static std::string format(fmt::format_string<Args...> fmt, Args&&... args)
    {
        return fmt::format(fmt, std::forward<Args>(args)...);
    }
#endif

    static std::string fill_token_values(
        const char* format, std::function<std::string(std::string_view)> tokenValueGenerator)
    {
        return fill_token_values(std::string_view(format), tokenValueGenerator);
    }

    static std::string fill_token_values(
        std::string_view format, std::function<std::string(std::string_view)> tokenValueGenerator);

    static std::string fill_token_values(const std::string& format,
        std::function<std::string(std::string_view)> tokenValueGenerator);
};
}

#endif