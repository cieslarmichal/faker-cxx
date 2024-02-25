#include <faker/types/file_type.h>
#include <stdexcept>

namespace faker {
std::string_view toString(FileType type)
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
}
