#pragma once

#include <string_view>

namespace faker {
enum class FileType { Video, Audio, Image, Text, Application };

std::string_view toString(FileType type);
}
