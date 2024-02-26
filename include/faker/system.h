#ifndef FAKER_SYSTEM_H
#define FAKER_SYSTEM_H

#include <optional>
#include <string>

namespace faker::system {
enum class FileType { Video, Audio, Image, Text, Application };

std::string_view to_string(FileType type);

struct FileOptions {
    int extensionCount = 1;
    struct {
        int min = 1;
        int max = 1;
    } extensionRange;
};

struct CronOptions {
    bool includeYear = false;
    bool includeNonStandard = false;
};

// TODO: change to enums
struct NetworkInterfaceOptions {
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
 * system::filename() // "injustice.mpeg"
 *
 * FileOptions options
 * options.extensionCount = 3
 * system::filename(options) // "transformation.wav.mpeg.mp4"
 *
 * options.extensionRange.min = 1;
 * options.extensionRange.max = 3;
 * system::filename(options) // "sparkle.png.pdf"
 * @endcode
 */
std::string filename(const FileOptions& options = {});

/**
 * @brief Returns a file extension.
 *
 * @param mimeType value of MimeType enum.
 *
 * @returns A file extension.
 *
 * @code
 * system::file_ext(MimeType::Image) // "png"
 * @endcode
 */
std::string file_ext(const std::optional<FileType>& mimeType = std::nullopt);

/**
 * Returns a random file name with a given extension or a commonly used extension.
 *
 * @param ext Optional extension parameter.
 *
 * @returns A random file name with a given extension or a commonly used extension.
 *
 * @code
 * system::common_filename() // "dollar.jpg"
 * system::common_filename("txt") // "global_borders_wyoming.txt"
 * @endcode
 */
std::string common_filename(const std::optional<std::string>& ext = std::nullopt);

/**
 * Returns a commonly used file extension.
 *
 * @returns A commonly used file extension.
 *
 * @code
 * system::common_file_ext() // "gif"
 * @endcode
 */
std::string_view common_file_ext();

/**
 * Returns a mime-type.
 *
 * @returns A mime-type.
 *
 * @code
 * system::mime_type() // "video/vnd.vivo"
 * @endcode
 */
std::string_view mime_type();

/**
 * Returns a commonly used file type.
 *
 * @returns A commonly used file type.
 *
 * @code
 * system::common_file_type() // "audio"
 * @endcode
 */
std::string_view common_file_type();

/**
 * Returns a commonly used file type.
 *
 * @returns A commonly used file type.
 *
 * @code
 * system::file_type() // "image"
 * @endcode
 */
std::string_view file_type();

/**
 * Returns a directory path.
 *
 * @returns A directory path.
 *
 * @code
 * system::directory_path() // "/etc/mail"
 * @endcode
 */
std::string_view directory_path();

/**
 * Returns a file path.
 *
 * @returns A file path.
 *
 * @code
 * system::file_path() // "/usr/local/src/money.dotx"
 * @endcode
 */
std::string file_path();

/**
 * Returns a semantic version.
 *
 * @returns A semantic version.
 *
 * @code
 * system::semver() // "1.1.2"
 * @endcode
 */
std::string semver();

/**
 * Returns a random network interface.
 *
 * @param options The options to use. Defaults to an empty options structure @see
 * NetworkInterfaceOptions.h.
 * @param options.interfaceType The interface type. Can be one of `en`, `wl`, `ww`.
 * @param options.interfaceSchema The interface schema. Can be one of `index`, `slot`, `mac`,
 * `pci`.
 *
 * @returns A random network interface.
 *
 * @code
 * system::network_interface() // "enp2s7f8"
 *
 * NetworkInterfaceOptions options;
 * options.interfaceType = "wl";
 * system::network_interface(options) // "wlsf4d2"
 *
 * NetworkInterfaceOptions options;
 * options.interfaceSchema = "mac";
 * system::network_interface(options) // "enxd17705ed394f"
 *
 * NetworkInterfaceOptions options;
 * options.interfaceType = "en";
 * options.interfaceSchema = "pci";
 * system::network_interface(options) // "enp1s9f1d2"
 * @endcode
 */
std::string network_interface(const std::optional<NetworkInterfaceOptions>& options = {});

/**
 * Returns a random cron expression.
 *
 * @param options The options to use. Defaults to an empty options structure @see CronOptions.h.
 * @param options.includeYear Whether to include a year in the generated expression. Defaults to
 * `false`.
 * @param options.includeNonStandard Whether to include a @yearly, @monthly, @daily, etc text
 * labels in the generated expression. Defaults to `false`.
 *
 * @returns A random cron expression.
 *
 * @code
 * system.cron() // "22 * ? * ?"
 *
 * CronOptions options
 * options.includeYear = true
 * std::string cronExpr = system::cron(options) // "16 14 * 11 2 2038"
 *
 * CronOptions options
 * options.includeYear = false
 * std::string cronExpr = system::cron(options) // "16 14 * 11 2"
 *
 * CronOptions options
 * options.includeNonStandard = false
 * std::string cronExpr = system::cron(options) // 34 2 ? 8 *
 *
 * CronOptions options
 * options.includeNonStandard = true
 * std::string cronExpr = system::cron(options) // "@reboot"
 * @endcode
 */
std::string cron(const CronOptions& options = {});
}

#endif