#include "../common/format_helper.h"
#include "../common/helper.h"
#include "../common/string_helper.h"
#include "system_data.h"
#include <algorithm>
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
        const auto it = data::mimeTypesExtensions.find(mimeType);
        if (it == data::mimeTypesExtensions.end()) {
            auto pos = mimeType.find_last_of('/');
            return mimeType.substr(pos + 1);
        } else {
            return it->second;
        }
    }
}

std::string filename(const FileOptions& options)
{
    std::string baseName = word::words();
    std::string extensionsStr;

    if (options.extensionCount > 0) {
        std::vector<std::string> randomExtensions;
        if (options.extensionRange.min == options.extensionRange.max) {
            for (int i = 0; i < options.extensionCount; ++i) {
                std::string randomExt = file_ext();
                randomExtensions.push_back(randomExt);
            }
            extensionsStr = "." + StringHelper::join(randomExtensions, ".");
        } else {
            int numExtensions;
            numExtensions = options.extensionRange.min
                + rand() % (options.extensionRange.max - options.extensionRange.min + 1);

            for (int i = 0; i < numExtensions; ++i) {
                std::string randomExt = file_ext();
                randomExtensions.push_back(randomExt);
            }

            extensionsStr = "." + StringHelper::join(randomExtensions, ".");
        }
    }
    return baseName + extensionsStr;
}

std::string_view to_string(FileType type)
{
    switch (type) {
    case FileType::Video:
        return "video";
    case FileType::Audio:
        return "audio";
    case FileType::Image:
        return "image";
    case FileType::Text:
        return "text";
    case FileType::Application:
        return "application";
    default:
        throw std::invalid_argument("Invalid file type");
    }
}

std::string file_ext(const std::optional<FileType>& mimeType)
{
    if (mimeType.has_value()) {
        const auto mimeTypeName = to_string(mimeType.value());
        std::vector<std::string_view> extensions;
        for (const auto& mime : data::mimeTypes) {
            size_t pos = mime.find_first_of('/');
            const auto mt = mime.substr(0, pos);
            if (mimeTypeName == mt) {
                extensions.push_back(mime.substr(pos + 1));
            }
        }
        return std::string(Helper::arrayElement(extensions));
    } else {
        std::unordered_set<std::string_view> extensionSet;

        for (const auto& mimeTypeName : data::mimeTypes) {
            extensionSet.insert(extension(mimeTypeName));
        }

        std::vector<std::string> extensions(extensionSet.begin(), extensionSet.end());
        return Helper::arrayElement<std::string>(extensions);
    }
}

std::string common_filename(const std::optional<std::string>& ext)
{
    FileOptions options;

    options.extensionCount = 0;

    std::string str = filename(options);

    str += '.';

    if (ext.has_value() && !ext.value().empty()) {
        str += ext.value();
    } else {
        str += common_file_ext();
    }
    return str;
}

std::string_view common_file_ext()
{
    auto mimeType = Helper::arrayElement(data::commonMimeTypes);

    return extension(mimeType);
}

std::string_view mime_type() { return Helper::arrayElement(data::mimeTypes); }

std::string_view common_file_type() { return Helper::arrayElement(data::commonFileTypes); }

std::string_view file_type()
{
    std::unordered_set<std::string_view> typeSet;

    const auto& localMimeTypes = data::mimeTypes;

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

std::string_view directory_path() { return Helper::arrayElement(data::directoryPaths); }

std::string file_path()
{
    auto dirPath = directory_path();
    std::string result;
    result.reserve(dirPath.size() + 1 + filename().size());
    result += dirPath;
    result += filename();
    return result;
}

std::string semver()
{
    int major = number::integer(9);
    int minor = number::integer(9);
    int patch = number::integer(9);
    return FormatHelper::format("{}.{}.{}", major, minor, patch);
}

std::string network_interface(const std::optional<NetworkInterfaceOptions>& options)
{
    const auto defaultInterfaceType = Helper::arrayElement(data::commonInterfaceTypes);
    const auto defaultInterfaceSchema = Helper::objectKey(data::commonInterfaceSchemas);

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
        + data::commonInterfaceSchemas.at(interfaceSchema).size() + suffix.size());
    result += prefix;
    result += interfaceType;
    result += data::commonInterfaceSchemas.at(interfaceSchema);
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
        std::string(data::cronDayOfWeek[static_cast<unsigned long>(
            number::integer(0, static_cast<int>(data::cronDayOfWeek.size() - 1)))]),
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
