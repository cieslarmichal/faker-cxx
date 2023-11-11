#pragma once

#include "types/CronOptions.h"
#include "types/DirectoryPath.h"
#include "types/FileOptions.h"
#include "types/MimeTypes.h"
#include "types/NetworkInterfaceOptions.h"

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
    static std::string fileName(const FileOptions& options = {});

    /**
     * @brief Returns a file extension.
     *
     * @param mimeType value of MimeType enum.
     *
     * @returns A file extension.
     *
     * @code
     * System::fileExt(MimeType::Image) // "png"
     * @endcode
     */
    static std::string fileExtension(const std::optional<FileType>& mimeType = std::nullopt);

    /**
     * Returns a random file name with a given extension or a commonly used extension.
     *
     * @param ext Optional extension parameter.
     *
     * @returns A random file name with a given extension or a commonly used extension.
     *
     * @code
     * System::commonFileName() // "dollar.jpg"
     * System::commonFileName("txt") // "global_borders_wyoming.txt"
     * @endcode
     */
    static std::string commonFileName(const std::optional<std::string>& ext = std::nullopt);

    /**
     * Returns a commonly used file extension.
     *
     * @returns A commonly used file extension.
     *
     * @code
     * System::commonFileExt() // "gif"
     * @endcode
     */
    static std::string commonFileExtension();

    /**
     * Returns a mime-type.
     *
     * @returns A mime-type.
     *
     * @code
     * System::mimeType() // "video/vnd.vivo"
     * @endcode
     */
    static std::string mimeType();

    /**
     * Returns a commonly used file type.
     *
     * @returns A commonly used file type.
     *
     * @code
     * System::commonFileType() // "audio"
     * @endcode
     */
    static std::string commonFileType();

    /**
     * Returns a commonly used file type.
     *
     * @returns A commonly used file type.
     *
     * @code
     * System::fileType() // "image"
     * @endcode
     */
    static std::string fileType();

    /**
     * Returns a directory path.
     *
     * @returns A directory path.
     *
     * @code
     * System::directoryPath() // "/etc/mail"
     * @endcode
     */
    static std::string directoryPath();

    /**
     * Returns a file path.
     *
     * @returns A file path.
     *
     * @code
     * System::filePath() // "/usr/local/src/money.dotx"
     * @endcode
     */
    static std::string filePath();

    /**
     * Returns a semantic version.
     *
     * @returns A semantic version.
     *
     * @code
     * System::semver() // "1.1.2"
     * @endcode
     */
    static std::string semver();

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
     * System::networkInterface() // "enp2s7f8"
     *
     * NetworkInterfaceOptions options;
     * options.interfaceType = "wl";
     * System::networkInterface(options) // "wlsf4d2"
     *
     * NetworkInterfaceOptions options;
     * options.interfaceSchema = "mac";
     * System::networkInterface(options) // "enxd17705ed394f"
     *
     * NetworkInterfaceOptions options;
     * options.interfaceType = "en";
     * options.interfaceSchema = "pci";
     * System::networkInterface(options) // "enp1s9f1d2"
     * @endcode
     */
    static std::string networkInterface(const std::optional<NetworkInterfaceOptions>& options = {});

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
     * std::string cronExpr = System::cron(options) // "16 14 * 11 2 2038"
     *
     * CronOptions options
     * options.includeYear = false
     * std::string cronExpr = System::cron(options) // "16 14 * 11 2"
     *
     * CronOptions options
     * options.includeNonStandard = false
     * std::string cronExpr = System::cron(options) // 34 2 ? 8 *
     *
     * CronOptions options
     * options.includeNonStandard = true
     * std::string cronExpr = System::cron(options) // "@reboot"
     * @endcode
     */
    static std::string cron(const CronOptions& options = {});
};
}
