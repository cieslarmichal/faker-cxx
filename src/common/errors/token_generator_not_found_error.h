#ifndef FAKER_COMMON_ERRORS_TOKEN_GENERATOR_NOT_FOUND_ERROR_H
#define FAKER_COMMON_ERRORS_TOKEN_GENERATOR_NOT_FOUND_ERROR_H

#include <stdexcept>

namespace faker::errors {
struct TokenGeneratorNotFoundError : std::runtime_error {
    using std::runtime_error::runtime_error;
};
}

#endif