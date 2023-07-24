#include "faker-cxx/System.h"

namespace faker
{
std::string System::fileName(const FileOptions& options)
{
    std::string baseName = Word::words();
    std::string extensionsStr;

    if (options.extensionCount > 0)
    {
        std::vector<std::string> randomExtensions;
        if(options.extensionRange.min == options.extensionRange.max)
        {
            for (int i = 0; i < options.extensionCount; ++i)
            {
                std::string randomExt = fileExt();
                randomExtensions.push_back(randomExt);
            }
            extensionsStr = "." + StringHelper::join(randomExtensions, ".");
        }
        else
        {
            int numExtensions;
            numExtensions = options.extensionRange.min + rand() % (options.extensionRange.max - options.extensionRange.min + 1);

            for (int i = 0; i < numExtensions; ++i)
            {
                std::string randomExt = fileExt();
                randomExtensions.push_back(randomExt);
            }

            extensionsStr = "." + StringHelper::join(randomExtensions, ".");
        }

    }
    return baseName + extensionsStr;
}

std::string System::fileExt(const std::optional<std::string>& mimeType)
{
    if (!mimeType->empty() && mimeType != std::nullopt)
    {
        auto it = std::find(commonMimeTypes.begin(), commonMimeTypes.end(), mimeType);
        if (it != commonMimeTypes.end())
        {
            const std::string& extension = *it;
            size_t pos = extension.find_last_of('/');
            return extension.substr(pos + 1);
        }
    }
    else
    {
        std::set<std::string> extensionSet;

        for (const auto& extension : commonMimeTypes)
        {
            size_t pos = extension.find_last_of('/');
            extensionSet.insert(extension.substr(pos + 1));
        }

        std::vector<std::string> extensions(extensionSet.begin(), extensionSet.end());
        return Helper::arrayElement<std::string>(extensions);
    }
    return "";
}

std::string System::commonFileName(const std::string& ext)
{
    FileOptions options;
    options.extensionCount = 0;
    std::string str = fileName(options);
    return str + (ext.empty() ? "." + commonFileExt() : "." + ext);
}

std::string System::commonFileExt()
{
    return fileExt(Helper::arrayElement<std::string>(commonMimeTypes));
}

std::string System::mimeType()
{
    std::vector<std::string> mimeTypeKeys;
    for(const auto& entry : commonMimeTypes)
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
    const auto& mimeTypes = commonMimeTypes;

    for (const auto& entry : mimeTypes) {
        const std::string& m = entry;
        size_t pos = m.find('/');
        if (pos != std::string::npos) {
            std::string type = m.substr(0, pos);
            typeSet.insert(type);
        }
    }

    std::vector<std::string> types(typeSet.begin(), typeSet.end());
    return Helper::arrayElement<std::string>(types);
}
}
