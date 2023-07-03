#include "StringDataGenerator.h"

#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <sstream>

namespace faker::string
{
std::string StringDataGenerator::uuid()
{
    std::stringstream uuid;

    uuid << boost::uuids::random_generator()();

    return uuid.str();
}
}
