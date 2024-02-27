#ifndef FAKER_COMMON_SHA256_H
#define FAKER_COMMON_SHA256_H

#include <string>

namespace faker::utils {
std::string sha256(std::string_view message);
}

#endif