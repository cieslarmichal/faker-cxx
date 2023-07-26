#pragma once

#include <algorithm>
#include <ctime>
#include <random>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

#include "../src/common/StringHelper.h"
#include "../src/modules/system/data/FileOptions.h"
#include "../src/modules/system/data/NetworkInterfaceOptions.h"
#include "Helper.h"
#include "Number.h"
#include "Word.h"
#include "String.h"
#include "Internet.h"

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

      /**
      * Returns a random file name with a given extension or a commonly used extension.
      *
      * @param ext Extension. Empty string is considered to be not set.
      *
      * @returns A random file name with a given extension or a commonly used extension.
      *
      * @example
      * System::commonFileName() // "dollar.jpg"
      * System::commonFileName("txt") // "global_borders_wyoming.txt"
      *
      */
     std::string commonFileName(const std::string& ext);

      /**
      * Returns a commonly used file extension.
      *
      * @returns A commonly used file extension.
      *
      * @example
      * System::commonFileExt() // "gif"
      *
      */
      std::string commonFileExt();

      /**
      * Returns a mime-type.
      *
      * @returns A mime-type.
      *
      * @example
      * System::mimeType() // "video/vnd.vivo"
      *
      */
      std::string mimeType();

      /**
      * Returns a commonly used file type.
      *
      * @returns A commonly used file type.
      *
      * @example
      * System::commonFileType() // "audio"
      *
      */
       std::string commonFileType();

       /**
      * Returns a commonly used file type.
      *
      * @returns A commonly used file type.
      *
      * @example
      * System::fileType() // "image"
      *
      */
       std::string fileType();

       /**
      * Returns a directory path.
      *
      * @returns A directory path.
      *
      * @example
      * System::directoryPath() // "/etc/mail"
      *
      */
       std::string directoryPath();

       /**
      * Returns a file path.
      *
      * @returns A file path.
      *
      * @example
      * System::filePath() // "/usr/local/src/money.dotx"
      *
      */
      std::string filePath();

      /**
      * Returns a semantic version.
      *
      * @returns A semantic version.
      *
      * @example
      * System::semver() // "1.1.2"
      *
      */
      std::string semver();

      /**
      * Returns a random network interface.
      *
      * @param options The options to use. Defaults to an empty options structure @see NetworkInterfaceOptions.h.
      * @param options.interfaceType The interface type. Can be one of `en`, `wl`, `ww`.
      * @param options.interfaceSchema The interface schema. Can be one of `index`, `slot`, `mac`, `pci`.
      *
      * @example
      * system.networkInterface() // "enp2s7f8"
      *
      * NetworkInterfaceOptions options;
      * options.interfaceType = "wl";
      * system.networkInterface(options) // "wlsf4d2"
      *
      * NetworkInterfaceOptions options;
      * options.interfaceSchema = "mac";
      * system.networkInterface(options) // "enxd17705ed394f"
      *
      * NetworkInterfaceOptions options;
      * options.interfaceType = "en";
      * options.interfaceSchema = "pci";
      * system.networkInterface(options) // "enp1s9f1d2"
      *
      */
      std::string networkInterface(const std::optional<NetworkInterfaceOptions>& options = {});
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
