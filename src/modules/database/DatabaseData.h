#pragma once

#include <array>
#include <string_view>

namespace faker
{
const auto collations = std::to_array<std::string_view>({
    "utf8_unicode_ci",  "utf8_general_ci",  "utf8_bin",
    "ascii_bin",        "ascii_general_ci", "cp1250_bin",
    "cp1250_general_ci"
});

const auto columnNames = std::to_array<std::string_view>({
    "id",    "title",    "name",     "email",   "username", "first_name", "last_name",  "phone",      "token",
    "group", "category", "password", "comment", "avatar",   "status",     "created_at", "updated_at",
});

const auto columnTypes = std::to_array<std::string_view>({
    "int",      "varchar",   "text",   "date",    "datetime", "tinyint", "time",     "timestamp",
    "smallint", "mediumint", "bigint", "decimal", "float",    "double",  "real",     "bit",
    "boolean",  "serial",    "blob",   "binary",  "enum",     "set",     "geometry", "point",
});

const auto engines = std::to_array<std::string_view>({"InnoDB", "MyISAM", "MEMORY", "CSV", "BLACKHOLE", "ARCHIVE"});

}
