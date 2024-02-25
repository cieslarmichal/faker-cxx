#include "../test_helpers.h"
#include <faker/database.h>
#include <modules/database_data.h>
#include <modules/string_data.h>

using namespace faker;

TEST(DatabaseTest, shouldGenerateColumnName)
{
    const auto generatedColumnName = database::columnName();

    FAKER_EXPECT_CONTAINS(columnNames, generatedColumnName);
}

TEST(DatabaseTest, shouldGenerateColumnType)
{
    const auto generatedColumnType = database::columnType();

    FAKER_EXPECT_CONTAINS(columnTypes, generatedColumnType);
}

TEST(DatabaseTest, shouldGenerateEngine)
{
    const auto generatedEngine = database::engine();

    FAKER_EXPECT_CONTAINS(engines, generatedEngine);
}

TEST(DatabaseTest, shouldGenerateCollation)
{
    const auto generatedCollation = database::collation();

    FAKER_EXPECT_CONTAINS(collations, generatedCollation);
}

TEST(DatabaseTest, shouldGenerateMongoDbObjectId)
{
    const auto mongoDbObjectId = database::mongoDbObjectId();

    ASSERT_EQ(mongoDbObjectId.size(), 24);
    ASSERT_TRUE(faker::testing::any_of(mongoDbObjectId, [](char hexNumberCharacter) {
        return string::data::hexLowerCharacters.find(hexNumberCharacter) != std::string::npos;
    }));
}
