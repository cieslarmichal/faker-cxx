#include "../test_helpers.h"
#include <algorithm>
#include <faker/database.h>
#include <modules/database_data.h>
#include <modules/string_data.h>

using namespace ::testing;
using namespace faker;

class DatabaseTest : public Test {
public:
};

TEST_F(DatabaseTest, shouldGenerateColumnName)
{
    const auto generatedColumnName = database::columnName();

    ASSERT_TRUE(faker::testing::contains(columnNames, generatedColumnName));
}

TEST_F(DatabaseTest, shouldGenerateColumnType)
{
    const auto generatedColumnType = database::columnType();

    ASSERT_TRUE(faker::testing::contains(columnTypes, generatedColumnType));
}

TEST_F(DatabaseTest, shouldGenerateEngine)
{
    const auto generatedEngine = database::engine();

    ASSERT_TRUE(faker::testing::contains(engines, generatedEngine));
}

TEST_F(DatabaseTest, shouldGenerateCollation)
{
    const auto generatedCollation = database::collation();

    ASSERT_TRUE(faker::testing::contains(collations, generatedCollation));
}

TEST_F(DatabaseTest, shouldGenerateMongoDbObjectId)
{
    const auto mongoDbObjectId = database::mongoDbObjectId();

    ASSERT_EQ(mongoDbObjectId.size(), 24);
    ASSERT_TRUE(faker::testing::any_of(mongoDbObjectId, [](char hexNumberCharacter) {
        return hexLowerCharacters.find(hexNumberCharacter) != std::string::npos;
    }));
}
