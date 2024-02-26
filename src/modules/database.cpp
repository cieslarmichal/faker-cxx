#include "../common/helper.h"
#include "database_data.h"
#include <faker/database.h>
#include <faker/string.h>

namespace faker::database {
std::string_view column_name() { return Helper::arrayElement(data::columnNames); }

std::string_view column_type() { return Helper::arrayElement(data::columnTypes); }

std::string_view collation() { return Helper::arrayElement(data::collations); }

std::string_view engine() { return Helper::arrayElement(data::engines); }

std::string mongodb_object_id()
{
    return string::hexadecimal(24, HexCasing::Lower, HexPrefix::None);
}
}
