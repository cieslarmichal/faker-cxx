#pragma once

#include <functional>
#include <string>
#include <unordered_map>
#include <vector>

#if defined(__APPLE__) || defined(__MINGW32__)                                                     \
    || (defined(__GNUC__) && (__GNUC__ < 12) && !defined(__clang__))
#include <fmt/format.h>
#else
#include <format>
#endif

namespace faker {
class FormatHelper {
public:
#if defined(__APPLE__) || defined(__MINGW32__)                                                     \
    || (defined(__GNUC__) && (__GNUC__ < 12) && !defined(__clang__))
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

    static std::string fillTokenValues(const std::string& format,
        std::unordered_map<std::string, std::function<std::string()>> tokenValueGenerators);
};
}
