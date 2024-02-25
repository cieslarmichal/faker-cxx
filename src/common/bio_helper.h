#pragma once

#include <functional>
#include <regex>
#include <string>
#include <unordered_map>
#include <vector>

namespace faker {
class BioHelper {
public:
    static bool checkTokenFormat(const std::string& bio);
};
}
