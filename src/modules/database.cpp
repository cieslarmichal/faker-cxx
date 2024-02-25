#include "database_data.h"
#include <faker/database.h>
#include <faker/helper.h>
#include <faker/string.h>

namespace faker::database {
std::string_view columnName() { return Helper::arrayElement(columnNames); }

std::string_view columnType() { return Helper::arrayElement(columnTypes); }

std::string_view collation() { return Helper::arrayElement(collations); }

std::string_view engine() { return Helper::arrayElement(engines); }

std::string mongoDbObjectId() { return String::hexadecimal(24, HexCasing::Lower, HexPrefix::None); }
}
