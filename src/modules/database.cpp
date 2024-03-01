#include "../common/random.h"
#include "database_data.h"
#include <faker/database.h>
#include <faker/string.h>

namespace faker::database {
std::string_view column_name() { return random::element(data::column_names); }

std::string_view column_type() { return random::element(data::column_types); }

std::string_view collation() { return random::element(data::collations); }

std::string_view engine() { return random::element(data::engines); }

std::string mongodb_object_id()
{
    return string::hexadecimal(24, hex_case_t::lower, hex_prefix_t::none);
}
}
