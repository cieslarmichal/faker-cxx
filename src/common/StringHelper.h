#pragma once

#include <string>
#include <vector>
#include "faker-cxx/Export.h"

namespace faker::common
{
    FAKER_CXX_EXPORT std::vector<std::string> split(const std::string& data, const std::string& separator = " ");
    FAKER_CXX_EXPORT std::string joinString(const std::vector<std::string>& data, const std::string& separator = " ");
    FAKER_CXX_EXPORT std::string join(const std::vector<std::string_view>& data, const std::string& separator = " ");
    FAKER_CXX_EXPORT std::string repeat(const std::string& data, int repetition);
    FAKER_CXX_EXPORT std::string toLower(const std::string& data);
    FAKER_CXX_EXPORT bool isPunctuation(char c);
    FAKER_CXX_EXPORT std::string removePunctuation(const std::string& word);
}
