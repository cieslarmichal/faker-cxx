#ifndef BASE64_H
#define BASE64_H

#include <string>

namespace faker::base64 {
    std::string encode(const std::string &input);
    std::string decode(const void* data, const size_t len);
}

#endif
