#include "String.h"

#include <boost/uuid/string_generator.hpp>
#include <boost/uuid/uuid.hpp>

#include "gtest/gtest.h"

using namespace ::testing;
using namespace faker;

class StringTest : public Test
{
public:
    [[nodiscard]] static bool isValidUuid(const std::string& data)
    {
        boost::uuids::uuid result = boost::uuids::string_generator()(data);

        return result.version() != boost::uuids::uuid::version_unknown;
    }
};

TEST_F(StringTest, shouldGenerateUuid4)
{
    const auto uuid = String::uuid();

    ASSERT_TRUE(isValidUuid(uuid));
}
