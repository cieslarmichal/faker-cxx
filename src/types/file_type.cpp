#include <faker/types/file_type.h>

namespace faker {
std::string_view toString(FileType type)
{
    static std::unordered_map<FileType, std::string_view> enumToStringMapping {
        { FileType::Video, "video" }, { FileType::Audio, "audio" }, { FileType::Image, "image" },
        { FileType::Text, "text" }, { FileType::Application, "application" }
    };

    return enumToStringMapping.at(type);
}
}
