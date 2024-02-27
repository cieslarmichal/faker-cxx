#include "../common/md5.h"
#include "../common/sha256.h"
#include <faker/crypto.h>
#include <faker/word.h>

namespace faker::crypto {

std::string sha256(std::optional<std::string> data)
{
    return data && !data->empty() ? utils::sha256(data.value()) : utils::sha256(word::sample());
}

std::string md5(std::optional<std::string> data)
{
    return data && !data->empty() ? utils::md5(data.value()) : utils::md5(word::sample());
}

}
