#pragma once

#include <array>
#include <string_view>

namespace faker::database
{
const auto collations = std::to_array<std::string_view>({
    "ascii_bin",
    "ascii_general_ci",
    "cp1250_bin",
    "cp1250_general_ci",
    "utf8_bin",
    "utf8_general_ci",
    "utf8_unicode_ci",
});

const auto columnNames = std::to_array<std::string_view>({
    "avatar",
    "category",
    "comment",
    "created_at",
    "email",
    "first_name",
    "group",
    "id",
    "last_name",
    "name",
    "password",
    "phone",
    "status",
    "title",
    "token",
    "updated_at",
    "username",
});

const auto columnTypes = std::to_array<std::string_view>({
    "bigint",
    "binary",
    "bit",
    "blob",
    "boolean",
    "date",
    "datetime",
    "decimal",
    "double",
    "enum",
    "float",
    "geometry",
    "int",
    "mediumint",
    "point",
    "real",
    "serial",
    "set",
    "smallint",
    "text",
    "time",
    "timestamp",
    "tinyint",
    "varchar",
});

const auto engines = std::to_array<std::string_view>({
    "ARCHIVE",
    "BLACKHOLE",
    "CSV",
    "InnoDB",
    "MEMORY",
    "MyISAM",
});

}
