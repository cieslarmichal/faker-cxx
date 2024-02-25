#pragma once

#include <sstream>
#include <string>
#include <unordered_map>

namespace faker {

class JsonHelper {
public:
    // this function parse simple jason like {"key1":"value1","key2":"value2"}
    static std::unordered_map<std::string, std::string> simpleJsonParser(std::string json);
};
}
