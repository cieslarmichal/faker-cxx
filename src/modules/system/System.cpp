#include "faker-cxx/System.h"

#include <iostream>
#include <optional>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

#include "../src/common/StringHelper.h"
#include "common/FormatHelper.h"
#include "faker-cxx/Datatype.h"
#include "faker-cxx/Helper.h"
#include "faker-cxx/Internet.h"
#include "faker-cxx/Number.h"
#include "faker-cxx/String.h"
#include "faker-cxx/Word.h"
#include "SystemData.h"

namespace faker::system
{
namespace
{
const std::unordered_map<FileType, std::string_view> fileTypeToStringMapping{
    {FileType::Video, "video"},
    {FileType::Audio, "audio"},
    {FileType::Image, "image"},
    {FileType::Text, "text"},
    {FileType::Application, "application"},
};

std::string_view extension(std::string_view mimeType)
{
    const auto it = mimeTypesExtensions.find(mimeType);

    if (it == mimeTypesExtensions.end())
    {
        auto pos = mimeType.find_last_of('/');

        return mimeType.substr(pos + 1);
    }

    return it->second;
}
}

std::string fileName(const FileOptions& options)
{
    const auto baseName = word::words();

    std::string extensionsStr;

    if (options.extensionCount > 0)
    {
        std::vector<std::string> randomExtensions;

        if (options.extensionRange.min == options.extensionRange.max)
        {
            for (int i = 0; i < options.extensionCount; ++i)
            {
                randomExtensions.push_back(fileExtension());
            }

            extensionsStr = "." + StringHelper::joinString(randomExtensions, ".");
        }
        else
        {
            const std::integral auto numExtensions =
                faker::number::integer(options.extensionRange.min, options.extensionRange.max);

            for (int i = 0; i < numExtensions; ++i)
            {
                randomExtensions.push_back(fileExtension());
            }

            extensionsStr = "." + StringHelper::joinString(randomExtensions, ".");
        }
    }

    return baseName + extensionsStr;
}

std::string fileExtension(const std::optional<FileType>& mimeType)
{
    if (mimeType.has_value())
    {
        const auto& mimeTypeName = fileTypeToStringMapping.at(mimeType.value());

        std::vector<std::string> extensions;

        for (const auto& mime : mimeTypes)
        {
            size_t pos = mime.find_first_of('/');

            const auto mt = mime.substr(0, pos);

            if (mimeTypeName == mt)
            {
                extensions.emplace_back(mime.substr(pos + 1));
            }
        }

        return Helper::arrayElement(extensions);
    }
    else
    {
        std::set<std::string_view> extensionSet;

        for (const auto& mimeTypeName : mimeTypes)
        {
            extensionSet.insert(extension(mimeTypeName));
        }

        std::vector<std::string> extensions(extensionSet.begin(), extensionSet.end());

        return Helper::arrayElement(extensions);
    }
}

std::string commonFileName(const std::optional<std::string>& ext)
{
    FileOptions options;

    options.extensionCount = 0;

    std::string str = fileName(options);

    if (ext.has_value() && !ext.value().empty())
    {
        return str + "." + ext.value();
    }
    else
    {
        return str + "." + std::string{commonFileExtension()};
    }
}

std::string_view commonFileExtension()
{
    auto mimeType = Helper::arrayElement(commonMimeTypes);

    return extension(mimeType);
}

std::string_view mimeType()
{
    std::vector<std::string_view> mimeTypeKeys;

    mimeTypeKeys.reserve(mimeTypes.size());

    for (const auto& entry : mimeTypes)
    {
        mimeTypeKeys.push_back(entry);
    }

    return Helper::arrayElement(mimeTypeKeys);
}

std::string_view fileType()
{
    return Helper::arrayElement(commonFileTypes);
}

std::string_view directoryPath()
{
    return Helper::arrayElement(directoryPaths);
}

std::string filePath()
{
    return std::string{directoryPath()} + fileName();
}

std::string semver()
{
    const int major = faker::number::integer(9);
    const int minor = faker::number::integer(9);
    const int patch = faker::number::integer(9);

    return FormatHelper::format("{}.{}.{}", major, minor, patch);
}

std::string networkInterface(const std::optional<NetworkInterfaceOptions>& options)
{
    const auto defaultInterfaceType = Helper::arrayElement(commonInterfaceTypes);
    const std::string defaultInterfaceSchema = std::string(Helper::objectKey(commonInterfaceSchemas));

    std::string interfaceType = std::string(defaultInterfaceType);
    std::string interfaceSchema = defaultInterfaceSchema;

    if (options.has_value())
    {
        if (options->interfaceType.has_value() && !options->interfaceType.value().empty())
        {
            interfaceType = options->interfaceType.value();
        }

        if (options->interfaceSchema.has_value() && !options->interfaceSchema.value().empty())
        {
            interfaceSchema = options->interfaceSchema.value();
        }
    }

    std::string suffix;
    std::string prefix;
    auto digit = []() { return String::numeric(); };

    if (interfaceSchema == "index")
    {
        suffix = digit();
    }
    else if (interfaceSchema == "slot")
    {
        suffix = Helper::maybe<std::string>([&]() { return "f" + digit(); });
        suffix += Helper::maybe<std::string>([&]() { return "d" + digit(); });
    }
    else if (interfaceSchema == "mac")
    {
        suffix = Internet::mac("");
    }
    else if (interfaceSchema == "pci")
    {
        prefix = Helper::maybe<std::string>([&]() { return "P" + digit(); });
        suffix = digit() + "s" + digit();
        suffix += Helper::maybe<std::string>([&]() { return "f" + digit(); });
        suffix += Helper::maybe<std::string>([&]() { return "d" + digit(); });
    }

    return prefix + interfaceType + std::string(commonInterfaceSchemas.at(interfaceSchema)) + suffix;
}

std::string cron(const CronOptions& options)
{
    bool includeYear = options.includeYear;
    bool includeNonStandard = options.includeNonStandard;
    std::vector<std::string> minutes = {std::to_string(faker::number::integer(59)), "*"};
    std::vector<std::string> hours = {std::to_string(faker::number::integer(23)), "*"};
    std::vector<std::string> days = {std::to_string(faker::number::integer(1, 31)), "*", "?"};
    std::vector<std::string> months = {std::to_string(faker::number::integer(1, 12)), "*"};
    std::vector<std::string> daysOfWeek = {
        std::to_string(faker::number::integer(6)),
        std::string(
            cronDayOfWeek[static_cast<unsigned long>(faker::number::integer(0, static_cast<int>(cronDayOfWeek.size() - 1)))]),
        "*", "?"};

    std::vector<std::string> years;
    if (includeYear)
    {
        years.push_back(std::to_string(faker::number::integer(1970, 2099)));
    }
    else
    {
        years = {std::to_string(faker::number::integer(1970, 2099)), "*"};
    }

    const auto minute = Helper::arrayElement(minutes);
    const auto hour = Helper::arrayElement(hours);
    const auto day = Helper::arrayElement(days);
    const auto month = Helper::arrayElement(months);
    const auto dayOfWeek = Helper::arrayElement(daysOfWeek);
    const auto year = Helper::arrayElement(years);

    std::string standardExpression = minute + " " + hour + " " + day + " " + month + " " + dayOfWeek;

    if (includeYear)
    {
        standardExpression += " " + year;
    }

    std::vector<std::string> nonStandardExpressions = {"@annually", "@daily",  "@hourly", "@monthly",
                                                       "@reboot",   "@weekly", "@yearly"};

    return (!includeNonStandard || datatype::boolean(0)) ? standardExpression :
                                                           Helper::arrayElement<std::string>(nonStandardExpressions);
}
}
