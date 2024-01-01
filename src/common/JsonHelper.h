#pragma once

#include <map>
#include <sstream>
#include <string>

namespace faker
{

class JsonHelper
{
public:
    // this function parse simple jason like {"key1":"value1","key2":"value2"}
    static std::map<std::string, std::string> simpleJsonParser(std::string json);
};
}
