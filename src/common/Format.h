#pragma once

#include <string>
#ifdef __apple__
    #include <fmt/core.h>
#else
    #include <format>
#endif

class Format {
public:
    #ifdef __apple__
        template<typename... Args>
        static std::string format(fmt::format_string<Args...> fmt, Args&&... args) {
            return fmt::format(fmt, std::forward<Args>(args)...);
        }
    #else
        template<typename... Args>
        static std::string format(std::format_string<Args...> fmt, Args&&... args) {
            return std::format(fmt, std::forward<Args>(args)...);
        }
    #endif
};
