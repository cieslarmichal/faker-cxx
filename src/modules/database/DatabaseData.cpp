#include "DatabaseData.h"

#include <array>
#include <string_view>

namespace faker
{
const std::array<std::string_view, 7> collations = {"utf8_unicode_ci",  "utf8_general_ci",  "utf8_bin",
                                                    "ascii_bin",        "ascii_general_ci", "cp1250_bin",
                                                    "cp1250_general_ci"};

const std::array<std::string_view, 17> columnNames = {
    "id",    "title",    "name",     "email",   "username", "first_name", "last_name",  "phone",      "token",
    "group", "category", "password", "comment", "avatar",   "status",     "created_at", "updated_at",
};

const std::array<std::string_view, 24> columnTypes = {
    "int",      "varchar",   "text",   "date",    "datetime", "tinyint", "time",     "timestamp",
    "smallint", "mediumint", "bigint", "decimal", "float",    "double",  "real",     "bit",
    "boolean",  "serial",    "blob",   "binary",  "enum",     "set",     "geometry", "point",
};

const std::array<std::string_view, 6> engines = {"InnoDB", "MyISAM", "MEMORY", "CSV", "BLACKHOLE", "ARCHIVE"};

}
