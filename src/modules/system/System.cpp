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
}
