#include "format_helper.h"
#include "errors/token_generator_not_found_error.h"

namespace faker {

std::string FormatHelper::fillTokenValues(
    const std::string& format, std::function<std::string(std::string_view)> tokenValueGenerator)
{
    std::string filledFormat;

    int tokenStart = -1;

    for (auto i = 0u; i < format.size(); i++) {
        if (format[i] == '{') {
            tokenStart = static_cast<int>(i) + 1;
        } else if (format[i] == '}' && tokenStart != -1 && static_cast<unsigned>(tokenStart) < i) {
            const auto token = format.substr(
                static_cast<unsigned>(tokenStart), i - static_cast<unsigned>(tokenStart));
            filledFormat += tokenValueGenerator(token);
            tokenStart = -1;
        } else if (tokenStart == -1) {
            filledFormat += format[i];
        }
    }

    return filledFormat;
}

}
