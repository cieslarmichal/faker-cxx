#include "../common/formatter.h"
#include "../common/random.h"
#include "../common/strings.h"
#include "system_data.h"
#include <faker/datatype.h>
#include <faker/internet.h>
#include <faker/number.h>
#include <faker/string.h>
#include <faker/system.h>
#include <faker/word.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>

namespace faker::system {
namespace {
    std::string_view extension(std::string_view mime_type)
    {
        const auto it = data::mime_types_extensions.find(mime_type);
        if (it == data::mime_types_extensions.end()) {
            auto pos = mime_type.find_last_of('/');
            return mime_type.substr(pos + 1);
        } else {
            return it->second;
        }
    }

    std::vector<std::string_view> make_file_types()
    {
        std::unordered_set<std::string_view> types;

        for (const auto& mime : data::mime_types) {
            size_t pos = mime.find('/');
            types.insert(mime.substr(0, pos));
        }

        return std::vector<std::string_view> { types.begin(), types.end() };
    }
}

std::string filename(const file_options_t& options)
{
    std::string result = word::words();

    unsigned ext_count = 0;
    if (options.extension_count > 0) {
        ext_count = options.extension_count;
    } else if (options.extension_range.min != options.extension_range.max) {
        ext_count = random::integer(options.extension_range.min, options.extension_range.max);
    }

    for (unsigned i = 0; i < ext_count; ++i) {
        result += '.';
        result += file_ext();
    }

    return result;
}

std::string_view to_string(file_type_t type)
{
    switch (type) {
    case file_type_t::video:
        return "video";
    case file_type_t::audio:
        return "audio";
    case file_type_t::image:
        return "image";
    case file_type_t::text:
        return "text";
    case file_type_t::application:
        return "application";
    default:
        throw std::invalid_argument("Invalid file type");
    }
}

std::unordered_map<std::optional<file_type_t>, std::vector<std::string_view>> make_extenstions_map()
{
    static const std::unordered_map<std::string_view, file_type_t> mime_type_map {
        { "video", file_type_t::video }, { "audio", file_type_t::audio },
        { "image", file_type_t::image }, { "text", file_type_t::text },
        { "application", file_type_t::application }
    };

    std::unordered_map<std::optional<file_type_t>, std::unordered_set<std::string_view>> result_map;

    // obvious
    for (auto mime : data::mime_types) {
        size_t pos = mime.find('/');
        auto category = mime.substr(0, pos);
        auto ext = mime.substr(pos + 1);
        if (mime_type_map.find(category) != mime_type_map.end()) {
            result_map[mime_type_map.at(category)].emplace(ext);
        }
        result_map[std::nullopt].emplace(ext);
    }

    // non-obvious
    for (auto [key, value] : data::mime_types_extensions) {
        if (mime_type_map.find(key) != mime_type_map.end()) {
            result_map[mime_type_map.at(key)].emplace(value);
        }
        result_map[std::nullopt].emplace(value);
    }

    std::unordered_map<std::optional<file_type_t>, std::vector<std::string_view>> result;

    for (auto [key, value] : result_map) {
        result.emplace(key, std::vector<std::string_view> { value.begin(), value.end() });
    }

    return result;
}

std::string_view file_ext(const std::optional<file_type_t>& mime_type)
{
    static std::unordered_map<std::optional<file_type_t>, std::vector<std::string_view>> exts
        = make_extenstions_map();
    return random::element(exts[mime_type]);
}

std::string common_filename(const std::optional<std::string>& ext)
{
    file_options_t options;
    options.extension_count = 0;

    auto fname = filename(options);
    auto fext = ext.has_value() ? ext.value() : common_file_ext();

    return utils::format("{}.{}", fname, fext);
}

std::string_view common_file_ext()
{
    auto mime_type = random::element(data::common_mime_types);

    return extension(mime_type);
}

std::string_view mime_type() { return random::element(data::mime_types); }

std::string_view common_file_type() { return random::element(data::common_file_types); }

std::string_view file_type()
{
    static std::vector<std::string_view> types = make_file_types();
    return random::element(types);
}

std::string_view directory_path() { return random::element(data::directory_paths); }

std::string file_path()
{
    auto dir_part = directory_path();

    std::string result;
    result.reserve(dir_part.size() + 1 + filename().size());
    result += dir_part;
    result += filename();

    return result;
}

std::string semver()
{
    auto major = number::integer(9);
    auto minor = number::integer(9);
    auto patch = number::integer(9);
    return utils::format("{}.{}.{}", major, minor, patch);
}

std::string network_interface(const std::optional<NetworkInterfaceOptions>& options)
{
    std::string iface_type;
    std::string iface_schema;

    if (options && options->interfaceType && !options->interfaceType->empty()) {
        iface_type = *options->interfaceType;
    } else {
        iface_type = random::element(data::common_interface_types);
    }
    if (options && options->interfaceSchema && !options->interfaceSchema->empty()) {
        iface_schema = *options->interfaceSchema;
    } else {
        iface_schema = random::map_key(data::common_interface_schemas);
    }

    std::string suffix;
    std::string prefix;
    auto digit = []() { return string::numeric(); };

    if (iface_schema == "index") {
        suffix = digit();
    } else if (iface_schema == "slot") {
        if (random::boolean(0.5)) {
            suffix = "f" + digit();
        }
        if (random::boolean(0.5)) {
            suffix += "d" + digit();
        }
    } else if (iface_schema == "mac") {
        suffix = internet::mac("");
    } else if (iface_schema == "pci") {
        if (random::boolean(0.5)) {
            prefix = "P" + digit();
        }
        suffix = digit() + "s" + digit();
        if (random::boolean(0.5)) {
            suffix += "f" + digit();
        }
        if (random::boolean(0.5)) {
            suffix += "d" + digit();
        }
    }

    return utils::format(
        "{}{}{}{}", prefix, iface_type, data::common_interface_schemas.at(iface_schema), suffix);
}

std::string cron(cron_options_t options)
{
    if ((options & cron_options_t::include_non_standard) && random::boolean(0.5)) {
        return std::string(random::element(data::non_standard_cron_expressions));
    }

    std::string minute = random::boolean(0.5) ? std::to_string(number::integer(59)) : "*";
    std::string hour = random::boolean(0.5) ? std::to_string(number::integer(23)) : "*";
    std::string day = random::boolean(0.5) ? std::to_string(number::integer(1, 31)) : "*";
    std::string month = random::boolean(0.5) ? std::to_string(number::integer(1, 12)) : "*";

    std::string day_of_week;
    switch (random::integer(1u, 3u)) {
    case 1u:
        day_of_week = random::element(data::cron_day_of_week);
        break;
    case 2u:
        day_of_week = "*";
        break;
    case 3u:
        day_of_week = "?";
        break;
    }

    if (options & cron_options_t::include_year) {
        std::string year
            = random::boolean(0.5) ? std::to_string(number::integer(1970u, 2099u)) : "*";
        return utils::format("{} {} {} {} {} {}", minute, hour, day, month, day_of_week, year);
    }

    return utils::format("{} {} {} {} {}", minute, hour, day, month, day_of_week);
}
}
