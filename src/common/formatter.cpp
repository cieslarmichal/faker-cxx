#include "formatter.h"

namespace faker::utils {

std::string fill_token_values(
    std::string_view format, std::function<std::string(std::string_view)> tokenValueGenerator)
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

std::string fill_token_values(
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

std::string_view precision_format_str(Precision precision)
{
    switch (precision) {
    case Precision::ZeroDp:
        return "{:.0f}";
    case Precision::OneDp:
        return "{:.1f}";
    case Precision::TwoDp:
        return "{:.2f}";
    case Precision::ThreeDp:
        return "{:.3f}";
    case Precision::FourDp:
        return "{:.4f}";
    case Precision::FiveDp:
        return "{:.5f}";
    case Precision::SixDp:
        return "{:.6f}";
    case Precision::SevenDp:
        return "{:.7f}";
    default:
        throw std::invalid_argument("Invalid precision");
    }
}

}
