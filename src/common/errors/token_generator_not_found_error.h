#pragma once

#include <stdexcept>

namespace faker::errors {
struct TokenGeneratorNotFoundError : std::runtime_error {
    using std::runtime_error::runtime_error;
};
}
