#ifndef FAKER_TYPES_FILE_TYPE_H
#define FAKER_TYPES_FILE_TYPE_H

#include <string_view>

namespace faker {
enum class FileType { Video, Audio, Image, Text, Application };

std::string_view toString(FileType type);
}

#endif