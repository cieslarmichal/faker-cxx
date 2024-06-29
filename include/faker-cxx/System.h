#pragma once

#include <optional>
#include <string>
#include <string_view>
#include "faker-cxx/Export.h"

namespace faker::system
{
struct FAKER_CXX_EXPORT FileOptions
{
    int extensionCount = 1;

    struct
    {
        int min = 1;
        int max = 1;
    } extensionRange;
};

enum class FileType
{
    Application,
    Audio,
    Image,
    Text,
    Video,
};

struct FAKER_CXX_EXPORT CronOptions
{
    bool includeYear = false;
    bool includeNonStandard = false;
};

struct FAKER_CXX_EXPORT NetworkInterfaceOptions
{
    std::optional<std::string> interfaceType;
    std::optional<std::string> interfaceSchema;
};

/**
 * @brief Returns a random file name with extension.
 *
 * @param options An option struct.
 *
 * @returns Random file name with extension.
 *
 * @code
 * faker::system::fileName() // "injustice.mpeg"
 *
 * FileOptions options
 * options.extensionCount = 3
 * faker::system::fileName(options) // "transformation.wav.mpeg.mp4"
 *
 * options.extensionRange.min = 1;
 * options.extensionRange.max = 3;
 * faker::system::fileName(options) // "sparkle.png.pdf"
 * @endcode
 */
FAKER_CXX_EXPORT std::string fileName(const FileOptions& options = {});

/**
 * @brief Returns a file extension.
 *
 * @param mimeType value of MimeType enum.
 *
 * @returns A file extension.
 *
 * @code
 * faker::system::fileExtension(MimeType::Image) // "png"
 * @endcode
 */
FAKER_CXX_EXPORT std::string fileExtension(const std::optional<FileType>& mimeType = std::nullopt);

/**
 * Returns a random file name with a given extension or a commonly used extension.
 *
 * @param ext Optional extension parameter.
 *
 * @returns A random file name with a given extension or a commonly used extension.
 *
 * @code
 * faker::system::commonFileName() // "dollar.jpg"
 * faker::system::commonFileName("txt") // "global_borders_wyoming.txt"
 * @endcode
 */
FAKER_CXX_EXPORT std::string commonFileName(const std::optional<std::string>& ext = std::nullopt);

/**
 * Returns a commonly used file extension.
 *
 * @returns A commonly used file extension.
 *
 * @code
 * faker::system::commonFileExtension() // "gif"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view commonFileExtension();

/**
 * Returns a mime-type.
 *
 * @returns A mime-type.
 *
 * @code
 * faker::system::mimeType() // "video/vnd.vivo"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view mimeType();

/**
 * Returns a commonly used file type.
 *
 * @returns A commonly used file type.
 *
 * @code
 * faker::system::fileType() // "audio"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view fileType();

/**
 * Returns a directory path.
 *
 * @returns A directory path.
 *
 * @code
 * faker::system::directoryPath() // "/etc/mail"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view directoryPath();

/**
 * Returns a file path.
 *
 * @returns A file path.
 *
 * @code
 * faker::system::filePath() // "/usr/local/src/money.dotx"
 * @endcode
 */
FAKER_CXX_EXPORT std::string filePath();

/**
 * Returns a semantic version.
 *
 * @returns A semantic version.
 *
 * @code
 * faker::system::semver() // "1.1.2"
 * @endcode
 */
FAKER_CXX_EXPORT std::string semver();

/**
 * Returns a random network interface.
 *
 * @param options The options to use. Defaults to an empty options structure @see NetworkInterfaceOptions.h.
 * @param options.interfaceType The interface type. Can be one of `en`, `wl`, `ww`.
 * @param options.interfaceSchema The interface schema. Can be one of `index`, `slot`, `mac`, `pci`.
 *
 * @returns A random network interface.
 *
 * @code
 * faker::system::networkInterface() // "enp2s7f8"
 *
 * NetworkInterfaceOptions options;
 * options.interfaceType = "wl";
 * faker::system::networkInterface(options) // "wlsf4d2"
 *
 * NetworkInterfaceOptions options;
 * options.interfaceSchema = "mac";
 * faker::system::networkInterface(options) // "enxd17705ed394f"
 *
 * NetworkInterfaceOptions options;
 * options.interfaceType = "en";
 * options.interfaceSchema = "pci";
 * faker::system::networkInterface(options) // "enp1s9f1d2"
 * @endcode
 */
FAKER_CXX_EXPORT std::string networkInterface(const std::optional<NetworkInterfaceOptions>& options = {});

/**
 * Returns a random cron expression.
 *
 * @param options The options to use. Defaults to an empty options structure @see CronOptions.h.
 * @param options.includeYear Whether to include a year in the generated expression. Defaults to `false`.
 * @param options.includeNonStandard Whether to include a @yearly, @monthly, @daily, etc text labels in the
 * generated expression. Defaults to `false`.
 *
 * @returns A random cron expression.
 *
 * @code
 * system.cron() // "22 * ? * ?"
 *
 * CronOptions options
 * options.includeYear = true
 * std::string cronExpr = faker::system::cron(options) // "16 14 * 11 2 2038"
 *
 * CronOptions options
 * options.includeYear = false
 * std::string cronExpr = faker::system::cron(options) // "16 14 * 11 2"
 *
 * CronOptions options
 * options.includeNonStandard = false
 * std::string cronExpr = faker::system::cron(options) // 34 2 ? 8 *
 *
 * CronOptions options
 * options.includeNonStandard = true
 * std::string cronExpr = faker::system::cron(options) // "@reboot"
 * @endcode
 */
FAKER_CXX_EXPORT std::string cron(const CronOptions& options = {});
}
