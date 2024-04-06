#include "faker-cxx/System.h"

#include <algorithm>
#include <set>
#include <string>
#include <vector>

#include "../src/common/StringHelper.h"
#include "data/CommonInterface.h"
#include "data/CronDayOfWeek.h"
#include "data/DirectoryPath.h"
#include "data/MimeTypes.h"
#include "faker-cxx/Helper.h"
#include "faker-cxx/Internet.h"
#include "faker-cxx/String.h"
#include "faker-cxx/Word.h"

namespace faker
{
namespace
{
const std::map<FileType, std::string> fileTypeToStringMapping{{FileType::Video, "video"},
                                                              {FileType::Audio, "audio"},
                                                              {FileType::Image, "image"},
                                                              {FileType::Text, "text"},
                                                              {FileType::Application, "application"}};

std::string extension(const std::string& mimeType)
{
    const auto it = mimeTypesExtensions.find(mimeType);
    if (it == mimeTypesExtensions.end())
    {
        auto pos = mimeType.find_last_of('/');
        return mimeType.substr(pos + 1);
    }
    else
    {
        return it->second;
    }
}
}

std::string System::fileName(const FileOptions& options)
{
    std::string baseName = Word::words();
    std::string extensionsStr;

    if (options.extensionCount > 0)
    {
        std::vector<std::string> randomExtensions;
        if (options.extensionRange.min == options.extensionRange.max)
        {
            for (int i = 0; i < options.extensionCount; ++i)
            {
                std::string randomExt = fileExtension();
                randomExtensions.push_back(randomExt);
            }
            extensionsStr = "." + StringHelper::join(randomExtensions, ".");
        }
        else
        {
            int numExtensions;
            numExtensions =
                options.extensionRange.min + rand() % (options.extensionRange.max - options.extensionRange.min + 1);

            for (int i = 0; i < numExtensions; ++i)
            {
                std::string randomExt = fileExtension();
                randomExtensions.push_back(randomExt);
            }

            extensionsStr = "." + StringHelper::join(randomExtensions, ".");
        }
    }
    return baseName + extensionsStr;
}

std::string System::fileExtension(const std::optional<FileType>& mimeType)
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
                extensions.push_back(mime.substr(pos + 1));
            }
        }

        return Helper::arrayElement<std::string>(extensions);
    }
    else
    {
        std::set<std::string> extensionSet;

        for (const auto& mimeTypeName : mimeTypes)
        {
            extensionSet.insert(extension(mimeTypeName));
        }

        std::vector<std::string> extensions(extensionSet.begin(), extensionSet.end());

        return Helper::arrayElement<std::string>(extensions);
    }
}

std::string System::commonFileName(const std::optional<std::string>& ext)
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
        return str + "." + commonFileExtension();
    }
}

std::string System::commonFileExtension()
{
    auto mimeType = Helper::arrayElement<std::string>(commonMimeTypes);

    return extension(mimeType);
}

std::string System::mimeType()
{
    std::vector<std::string> mimeTypeKeys;

    mimeTypeKeys.reserve(mimeTypes.size());

    for (const auto& entry : mimeTypes)
    {
        mimeTypeKeys.push_back(entry);
    }

    return Helper::arrayElement<std::string>(mimeTypeKeys);
}

std::string System::commonFileType()
{
    return Helper::arrayElement<std::string>(commonFileTypes);
}

std::string System::fileType()
{
    std::set<std::string> typeSet;

    const auto& localMimeTypes = mimeTypes;

    for (const auto& entry : localMimeTypes)
    {
        const std::string& m = entry;

        size_t pos = m.find('/');

        if (pos != std::string::npos)
        {
            std::string type = m.substr(0, pos);
            typeSet.insert(type);
        }
    }

    std::vector<std::string> types(typeSet.begin(), typeSet.end());

    return Helper::arrayElement<std::string>(types);
}

std::string System::directoryPath()
{
    return Helper::arrayElement<std::string>(directoryPaths);
}

std::string System::filePath()
{
    return directoryPath() + fileName();
}

std::string System::semver()
{
    int major = Number::integer(9);
    int minor = Number::integer(9);
    int patch = Number::integer(9);

    std::stringstream ss;

    ss << major << '.' << minor << '.' << patch;

    return ss.str();
}

std::string System::networkInterface(const std::optional<NetworkInterfaceOptions>& options)
{
    const auto defaultInterfaceType = Helper::arrayElement<std::string>(commonInterfaceTypes);
    const std::string defaultInterfaceSchema = Helper::objectKey(commonInterfaceSchemas);

    std::string interfaceType = defaultInterfaceType;
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

    return prefix + interfaceType + commonInterfaceSchemas.at(interfaceSchema) + suffix;
}

std::string System::cron(const CronOptions& options)
{
    bool includeYear = options.includeYear;
    bool includeNonStandard = options.includeNonStandard;
    std::vector<std::string> minutes = {std::to_string(Number::integer(59)), "*"};
    std::vector<std::string> hours = {std::to_string(Number::integer(23)), "*"};
    std::vector<std::string> days = {std::to_string(Number::integer(1, 31)), "*", "?"};
    std::vector<std::string> months = {std::to_string(Number::integer(1, 12)), "*"};
    std::vector<std::string> daysOfWeek = {
        std::to_string(Number::integer(6)),
        cronDayOfWeek[static_cast<unsigned long>(Number::integer(0, static_cast<int>(cronDayOfWeek.size() - 1)))], "*",
        "?"};

    std::vector<std::string> years;
    if (includeYear)
    {
        years.push_back(std::to_string(Number::integer(1970, 2099)));
    }
    else
    {
        years = {std::to_string(Number::integer(1970, 2099)), "*"};
    }

    auto minute = Helper::arrayElement<std::string>(minutes);
    auto hour = Helper::arrayElement<std::string>(hours);
    auto day = Helper::arrayElement<std::string>(days);
    auto month = Helper::arrayElement<std::string>(months);
    auto dayOfWeek = Helper::arrayElement<std::string>(daysOfWeek);
    auto year = Helper::arrayElement<std::string>(years);

    std::string standardExpression = minute + " " + hour + " " + day + " " + month + " " + dayOfWeek;
    if (includeYear)
    {
        standardExpression += " " + year;
    }

    std::vector<std::string> nonStandardExpressions = {"@annually", "@daily",  "@hourly", "@monthly",
                                                       "@reboot",   "@weekly", "@yearly"};

    return (!includeNonStandard || Datatype::boolean(0)) ? standardExpression :
                                                           Helper::arrayElement<std::string>(nonStandardExpressions);
}
}
