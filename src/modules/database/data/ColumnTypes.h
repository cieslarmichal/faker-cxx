#pragma once

#include <string>
#include <vector>

namespace faker
{
const std::vector<std::string> columnTypes = {
    "int",      "varchar",   "text",   "date",    "datetime", "tinyint", "time",     "timestamp",
    "smallint", "mediumint", "bigint", "decimal", "float",    "double",  "real",     "bit",
    "boolean",  "serial",    "blob",   "binary",  "enum",     "set",     "geometry", "point",
};
}
