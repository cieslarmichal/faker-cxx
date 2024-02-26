#include "database_data.h"
#include <faker/database.h>
#include <faker/helper.h>
#include <faker/string.h>

namespace faker::database {
std::string_view columnName() { return Helper::arrayElement(data::columnNames); }

std::string_view columnType() { return Helper::arrayElement(data::columnTypes); }

std::string_view collation() { return Helper::arrayElement(data::collations); }

std::string_view engine() { return Helper::arrayElement(data::engines); }

std::string mongoDbObjectId() { return string::hexadecimal(24, HexCasing::Lower, HexPrefix::None); }
}
