#pragma once

#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <random>
#include <ctime>
#include <set>

#include "../src/modules/system/data/FileOptions.h"
#include "../src/common/StringHelper.h"
#include "Helper.h"
#include "Word.h"

namespace faker
{
class System
{
public:
    /**
     * @brief Returns a random file name with extension.
     *
     * @param options An option struct.
     *
     * @returns Random file name with extension.
     *
     * @code
     * System::fileName() // "injustice.mpeg"
     *
     * FileOptions options
     * options.extensionCount = 3
     * System::fileName(options) // "transformation.wav.mpeg.mp4"
     *
     * options.extensionRange.min = 1;
     * options.extensionRange.max = 3;
     * System::fileName(options) // "sparkle.png.pdf"
     * @endcode
     */
    std::string fileName(const FileOptions& options = {});

    /**
     * @brief Returns a file extension.
     *
     * @param mimeType The optional string to use.
     *
     * @returns A file extension.
     *
     * @code
     * System::fileExt() //  "wav"
     * System::fileExt("application/pdf") // "pdf"
     * @endcode
     */
     std::string fileExt(const std::optional<std::string>& mimeType = std::nullopt);
private:
    const std::vector<std::string> commonFileTypes = {"video", "audio", "image", "text", "application"};
    const std::vector<std::string> commonMimeTypes = {
        "application/pdf",
        "audio/mpeg",
        "audio/wav",
        "image/png",
        "image/jpeg",
        "image/gif",
        "video/mp4",
        "video/mpeg",
        "text/html"
    };

    /*
     *   en -- ethernet
     *   wl -- wlan
     *   ww -- wwan
     * */
    const std::vector<std::string> commonInterfaceTypes = {"en", "wl", "ww"};
    const std::unordered_map<std::string, std::string> commonInterfaceSchemas = {
        {"index", "o"},
        {"slot", "s"},
        {"mac", "x"},
        {"pci", "p"}
    };
    const std::vector<std::string> CRON_DAY_OF_WEEK = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
};
}
