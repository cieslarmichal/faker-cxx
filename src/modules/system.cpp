#include "../src/common/string_helper.h"
#include "system_data.h"
#include <algorithm>
#include <faker/helper.h>
#include <faker/internet.h>
#include <faker/string.h>
#include <faker/system.h>
#include <faker/word.h>
#include <unordered_set>
#include <vector>

namespace faker::system {
namespace {
    std::string_view extension(std::string_view mimeType)
    {
        const auto it = mimeTypesExtensions.find(mimeType);
        if (it == mimeTypesExtensions.end()) {
            auto pos = mimeType.find_last_of('/');
            return mimeType.substr(pos + 1);
        } else {
            return std::string(it->second);
        }
    }
}

std::string fileName(const FileOptions& options)
{
    std::string baseName = word::words();
    std::string extensionsStr;

    if (options.extensionCount > 0) {
        std::vector<std::string> randomExtensions;
        if (options.extensionRange.min == options.extensionRange.max) {
            for (int i = 0; i < options.extensionCount; ++i) {
                std::string randomExt = fileExtension();
                randomExtensions.push_back(randomExt);
            }
            extensionsStr = "." + StringHelper::join(randomExtensions, ".");
        } else {
            int numExtensions;
            numExtensions = options.extensionRange.min
                + rand() % (options.extensionRange.max - options.extensionRange.min + 1);

            for (int i = 0; i < numExtensions; ++i) {
                std::string randomExt = fileExtension();
                randomExtensions.push_back(randomExt);
            }

            extensionsStr = "." + StringHelper::join(randomExtensions, ".");
        }
    }
    return baseName + extensionsStr;
}

std::string fileExtension(const std::optional<FileType>& mimeType)
{
    if (mimeType.has_value()) {
        const auto mimeTypeName = toString(mimeType.value());
        std::vector<std::string_view> extensions;
        for (const auto& mime : mimeTypes) {
            size_t pos = mime.find_first_of('/');
            const auto mt = mime.substr(0, pos);
            if (mimeTypeName == mt) {
                extensions.push_back(mime.substr(pos + 1));
            }
        }
        return std::string(Helper::arrayElement(extensions));
    } else {
        std::unordered_set<std::string_view> extensionSet;

        for (const auto& mimeTypeName : mimeTypes) {
            extensionSet.insert(extension(mimeTypeName));
        }

        std::vector<std::string> extensions(extensionSet.begin(), extensionSet.end());
        return Helper::arrayElement<std::string>(extensions);
    }
}

std::string commonFileName(const std::optional<std::string>& ext)
{
    FileOptions options;

    options.extensionCount = 0;

    std::string str = fileName(options);

    str += '.';

    if (ext.has_value() && !ext.value().empty()) {
        str += ext.value();
    } else {
        str += commonFileExtension();
    }
    return str;
}

std::string_view commonFileExtension()
{
    auto mimeType = Helper::arrayElement(commonMimeTypes);

    return extension(mimeType);
}

std::string_view mimeType()
{
    std::vector<std::string_view> mimeTypeKeys;

    for (const auto& entry : mimeTypes) {
        mimeTypeKeys.push_back(entry);
    }

    return Helper::arrayElement(mimeTypeKeys);
}

std::string_view commonFileType() { return Helper::arrayElement(commonFileTypes); }

std::string_view fileType()
{
    std::unordered_set<std::string_view> typeSet;

    const auto& localMimeTypes = mimeTypes;

    for (const auto& entry : localMimeTypes) {
        auto m = entry;

        size_t pos = m.find('/');

        if (pos != std::string::npos) {
            auto type = m.substr(0, pos);
            typeSet.insert(type);
        }
    }

    std::vector<std::string_view> types(typeSet.begin(), typeSet.end());

    return Helper::arrayElement(types);
}

std::string_view directoryPath() { return Helper::arrayElement(directoryPaths); }

std::string filePath()
{
    auto dirPath = directoryPath();
    std::string result;
    result.reserve(dirPath.size() + 1 + fileName().size());
    result += dirPath;
    result += fileName();
    return result;
}

std::string semver()
{
    int major = number::integer(9);
    int minor = number::integer(9);
    int patch = number::integer(9);

    std::stringstream ss;

    ss << major << '.' << minor << '.' << patch;

    return ss.str();
}

std::string networkInterface(const std::optional<NetworkInterfaceOptions>& options)
{
    const auto defaultInterfaceType = Helper::arrayElement(commonInterfaceTypes);
    const auto defaultInterfaceSchema = Helper::objectKey(commonInterfaceSchemas);

    std::string interfaceType { defaultInterfaceType };
    std::string interfaceSchema { defaultInterfaceSchema };

    if (options.has_value()) {
        if (options->interfaceType.has_value() && !options->interfaceType.value().empty()) {
            interfaceType = options->interfaceType.value();
        }

        if (options->interfaceSchema.has_value() && !options->interfaceSchema.value().empty()) {
            interfaceSchema = options->interfaceSchema.value();
        }
    }

    std::string suffix;
    std::string prefix;
    auto digit = []() { return string::numeric(); };

    if (interfaceSchema == "index") {
        suffix = digit();
    } else if (interfaceSchema == "slot") {
        suffix = Helper::maybe<std::string>([&]() { return "f" + digit(); });
        suffix += Helper::maybe<std::string>([&]() { return "d" + digit(); });
    } else if (interfaceSchema == "mac") {
        suffix = internet::mac("");
    } else if (interfaceSchema == "pci") {
        prefix = Helper::maybe<std::string>([&]() { return "P" + digit(); });
        suffix = digit() + "s" + digit();
        suffix += Helper::maybe<std::string>([&]() { return "f" + digit(); });
        suffix += Helper::maybe<std::string>([&]() { return "d" + digit(); });
    }

    std::string result;
    result.reserve(prefix.size() + interfaceType.size()
        + commonInterfaceSchemas.at(interfaceSchema).size() + suffix.size());
    result += prefix;
    result += interfaceType;
    result += commonInterfaceSchemas.at(interfaceSchema);
    result += suffix;
    return result;
}

std::string cron(const CronOptions& options)
{
    bool includeYear = options.includeYear;
    bool includeNonStandard = options.includeNonStandard;
    std::vector<std::string> minutes = { std::to_string(number::integer(59)), "*" };
    std::vector<std::string> hours = { std::to_string(number::integer(23)), "*" };
    std::vector<std::string> days = { std::to_string(number::integer(1, 31)), "*", "?" };
    std::vector<std::string> months = { std::to_string(number::integer(1, 12)), "*" };
    std::vector<std::string> daysOfWeek = { std::to_string(number::integer(6)),
        std::string(cronDayOfWeek[static_cast<unsigned long>(
            number::integer(0, static_cast<int>(cronDayOfWeek.size() - 1)))]),
        "*", "?" };

    std::vector<std::string> years;
    if (includeYear) {
        years.push_back(std::to_string(number::integer(1970, 2099)));
    } else {
        years = { std::to_string(number::integer(1970, 2099)), "*" };
    }

    auto minute = Helper::arrayElement<std::string>(minutes);
    auto hour = Helper::arrayElement<std::string>(hours);
    auto day = Helper::arrayElement<std::string>(days);
    auto month = Helper::arrayElement<std::string>(months);
    auto dayOfWeek = Helper::arrayElement<std::string>(daysOfWeek);
    auto year = Helper::arrayElement<std::string>(years);

    std::string standardExpression
        = minute + " " + hour + " " + day + " " + month + " " + dayOfWeek;
    if (includeYear) {
        standardExpression += " " + year;
    }

    std::vector<std::string> nonStandardExpressions
        = { "@annually", "@daily", "@hourly", "@monthly", "@reboot", "@weekly", "@yearly" };

    return (!includeNonStandard || datatype::boolean(0))
        ? standardExpression
        : Helper::arrayElement<std::string>(nonStandardExpressions);
}
}
