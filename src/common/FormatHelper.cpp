#include "FormatHelper.h"

#include <stdexcept>

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
}
