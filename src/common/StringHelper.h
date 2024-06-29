#pragma once

#include <string>
#include <vector>
#include "faker-cxx/Export.h"

namespace faker
{
class StringHelper
{
public:
    FAKER_CXX_EXPORT static std::vector<std::string> split(const std::string& data, const std::string& separator = " ");
    FAKER_CXX_EXPORT static std::string joinString(const std::vector<std::string>& data, const std::string& separator = " ");
    FAKER_CXX_EXPORT static std::string join(const std::vector<std::string_view>& data, const std::string& separator = " ");
    FAKER_CXX_EXPORT static std::string repeat(const std::string& data, int repetition);
    FAKER_CXX_EXPORT static std::string toLower(const std::string& data);
    FAKER_CXX_EXPORT static bool isPunctuation(char c);
    FAKER_CXX_EXPORT static std::string removePunctuation(const std::string& word);
};
}
