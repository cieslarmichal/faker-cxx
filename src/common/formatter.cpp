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

std::string_view precision_format_str(precision_t prec)
{
    switch (prec) {
    case precision_t::zero_dp:
        return "{:.0f}";
    case precision_t::one_dp:
        return "{:.1f}";
    case precision_t::two_dp:
        return "{:.2f}";
    case precision_t::three_dp:
        return "{:.3f}";
    case precision_t::four_dp:
        return "{:.4f}";
    case precision_t::five_dp:
        return "{:.5f}";
    case precision_t::six_dp:
        return "{:.6f}";
    case precision_t::seven_dp:
        return "{:.7f}";
    default:
        throw std::invalid_argument("Invalid precision");
    }
}

}
