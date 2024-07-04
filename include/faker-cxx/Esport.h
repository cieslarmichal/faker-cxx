#pragma once

#include <faker-cxx/Export.h>
#include <string_view>

namespace faker::esport
{
// TODO: Add comments explaining each function's implementation details
FAKER_CXX_EXPORT std::string_view player();

FAKER_CXX_EXPORT std::string_view team();

FAKER_CXX_EXPORT std::string_view league();

FAKER_CXX_EXPORT std::string_view event();

FAKER_CXX_EXPORT std::string_view game();
}
