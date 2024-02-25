#ifndef FAKER_COMMON_BIO_HELPER_H
#define FAKER_COMMON_BIO_HELPER_H

#include <functional>
#include <regex>
#include <string>
#include <vector>

namespace faker {
class BioHelper {
public:
    static bool checkTokenFormat(const std::string& bio);
};
}

#endif