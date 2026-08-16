#include "format_helper.h"

#include <iomanip>
#include <optional>
#include <sstream>
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
    int decimalPlaces;

    switch (precision)
    {
    case Precision::ZeroDp:
        decimalPlaces = 0;
        break;
    case Precision::OneDp:
        decimalPlaces = 1;
        break;
    case Precision::TwoDp:
        decimalPlaces = 2;
        break;
    case Precision::ThreeDp:
        decimalPlaces = 3;
        break;
    case Precision::FourDp:
        decimalPlaces = 4;
        break;
    case Precision::FiveDp:
        decimalPlaces = 5;
        break;
    case Precision::SixDp:
        decimalPlaces = 6;
        break;
    case Precision::SevenDp:
        decimalPlaces = 7;
        break;
    default:
        throw std::invalid_argument("Invalid precision");
    }

    // std::format's floating-point overloads pull in libc++'s std::to_chars, which Apple
    // marks unavailable before macOS 13.3, breaking builds targeting older deployment
    // targets. std::ostringstream avoids to_chars entirely and works everywhere.
    std::ostringstream stream;
    stream << std::fixed << std::setprecision(decimalPlaces) << value;
    return stream.str();
}

}
