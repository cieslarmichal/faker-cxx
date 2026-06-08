#include "format_helper.h"

#include <optional>
#include <stdexcept>
#include <string>
#include <unordered_map>

namespace faker
{

std::string common::fillTokenValues(const std::string& format,
                                    std::unordered_map<std::string, std::function<std::string()>> tokenValueGenerators)
{
    std::string filledFormat;

    std::optional<std::string::size_type> tokenStart{};

    for (std::string::size_type i = 0; i < format.size(); i++)
    {
        if (format[i] == '{')
        {
            tokenStart = i + 1;
        }
        else if (format[i] == '}' && tokenStart.has_value() && *tokenStart < i)
        {
            const auto token = format.substr(*tokenStart, i - *tokenStart);

            const auto foundTokenGenerator = tokenValueGenerators.find(token);

            if (foundTokenGenerator == tokenValueGenerators.end())
            {
                throw std::runtime_error{common::format("Generator not found for token {}.", token)};
            }

            filledFormat += foundTokenGenerator->second();

            tokenStart.reset();
        }
        else if (!tokenStart.has_value())
        {
            filledFormat += format[i];
        }
    }

    return filledFormat;
}

std::string
common::fillTokenValues(const std::string& format,
                        std::unordered_map<std::string_view, std::function<std::string_view()>> tokenValueGenerators)
{
    std::string filledFormat;

    std::optional<std::string::size_type> tokenStart{};

    for (std::string::size_type i = 0; i < format.size(); i++)
    {
        if (format[i] == '{')
        {
            tokenStart = i + 1;
        }
        else if (format[i] == '}' && tokenStart.has_value() && *tokenStart < i)
        {
            const auto token = format.substr(*tokenStart, i - *tokenStart);

            const auto foundTokenGenerator = tokenValueGenerators.find(token);

            if (foundTokenGenerator == tokenValueGenerators.end())
            {
                throw std::runtime_error{common::format("Generator not found for token {}.", token)};
            }

            filledFormat += foundTokenGenerator->second();

            tokenStart.reset();
        }
        else if (!tokenStart.has_value())
        {
            filledFormat += format[i];
        }
    }

    return filledFormat;
}

std::string common::precisionFormat(Precision precision, double value)
{
    switch (precision)
    {
    case Precision::ZeroDp:
        return common::format("{:.0f}", value);
    case Precision::OneDp:
        return common::format("{:.1f}", value);
    case Precision::TwoDp:
        return common::format("{:.2f}", value);
    case Precision::ThreeDp:
        return common::format("{:.3f}", value);
    case Precision::FourDp:
        return common::format("{:.4f}", value);
    case Precision::FiveDp:
        return common::format("{:.5f}", value);
    case Precision::SixDp:
        return common::format("{:.6f}", value);
    case Precision::SevenDp:
        return common::format("{:.7f}", value);
    default:
        throw std::invalid_argument("Invalid precision");
    }
}

}
