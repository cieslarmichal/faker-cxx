#pragma once

#include <map>
#include <string>

namespace faker
{
enum class FileType
{
    Video,
    Audio,
    Image,
    Text,
    Application
};

inline std::string toString(FileType type)
{
    std::map<FileType, std::string> enumToStringMapping{{FileType::Video, "video"},
                                                        {FileType::Audio, "audio"},
                                                        {FileType::Image, "image"},
                                                        {FileType::Text, "text"},
                                                        {FileType::Application, "application"}};
    return enumToStringMapping.at(type);
}
}
