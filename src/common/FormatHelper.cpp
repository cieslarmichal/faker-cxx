#include "FormatHelper.h"

#include <functional>
#include <stdexcept>
#include <string>
#include <unordered_map>

namespace faker
{

// TODO: change to std::function<std::string_view()>
std::string
FormatHelper::fillTokenValues(const std::string& format,
                              std::unordered_map<std::string, std::function<std::string()>> tokenValueGenerators)
{
    std::string filledFormat;

    int tokenStart = -1;

    for (auto i = 0u; i < format.size(); i++)
    {
        if (format[i] == '{')
        {
            tokenStart = static_cast<int>(i) + 1;
        }
        else if (format[i] == '}' && tokenStart != -1 && static_cast<unsigned>(tokenStart) < i)
        {
            const auto token = format.substr(static_cast<unsigned>(tokenStart), i - static_cast<unsigned>(tokenStart));

            const auto foundTokenGenerator = tokenValueGenerators.find(token);

            if (foundTokenGenerator == tokenValueGenerators.end())
            {
                throw std::runtime_error{FormatHelper::format("Generator not found for token {}.", token)};
            }

            filledFormat += foundTokenGenerator->second();

            tokenStart = -1;
        }
        else if (tokenStart == -1)
        {
            filledFormat += format[i];
        }
    }

    return filledFormat;
}

std::string FormatHelper::fillTokenValues(
    const std::string& format,
    std::unordered_map<std::string_view, std::function<std::string_view()>> tokenValueGenerators)
{
    std::string filledFormat;

    int tokenStart = -1;

    for (auto i = 0u; i < format.size(); i++)
    {
        if (format[i] == '{')
        {
            tokenStart = static_cast<int>(i) + 1;
        }
        else if (format[i] == '}' && tokenStart != -1 && static_cast<unsigned>(tokenStart) < i)
        {
            const auto token = format.substr(static_cast<unsigned>(tokenStart), i - static_cast<unsigned>(tokenStart));

            const auto foundTokenGenerator = tokenValueGenerators.find(token);

            if (foundTokenGenerator == tokenValueGenerators.end())
            {
                throw std::runtime_error{FormatHelper::format("Generator not found for token {}.", token)};
            }

            filledFormat += foundTokenGenerator->second();

            tokenStart = -1;
        }
        else if (tokenStart == -1)
        {
            filledFormat += format[i];
        }
    }

    return filledFormat;
}

std::string FormatHelper::precisionFormat(Precision precision, double value)
{
    switch (precision)
    {
    case Precision::ZeroDp:
        return FormatHelper::format("{:.0f}", value);
    case Precision::OneDp:
        return FormatHelper::format("{:.1f}", value);
    case Precision::TwoDp:
        return FormatHelper::format("{:.2f}", value);
    case Precision::ThreeDp:
        return FormatHelper::format("{:.3f}", value);
    case Precision::FourDp:
        return FormatHelper::format("{:.4f}", value);
    case Precision::FiveDp:
        return FormatHelper::format("{:.5f}", value);
    case Precision::SixDp:
        return FormatHelper::format("{:.6f}", value);
    case Precision::SevenDp:
        return FormatHelper::format("{:.7f}", value);
    default:
        throw std::invalid_argument("Invalid precision");
    }
}

}
