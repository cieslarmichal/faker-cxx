#ifndef FAKER_COMMON_MD5_H
#define FAKER_COMMON_MD5_H

#include <string>

namespace faker::utils {
std::string md5(std::string_view message);
}

#endif