#include "../test_helpers.h"
#include <faker/database.h>
#include <modules/database_data.h>
#include <modules/string_data.h>

using namespace faker;

TEST(DatabaseTest, shouldGenerateColumnName)
{
    auto generatedColumnName = database::column_name();

    FAKER_EXPECT_CONTAINER_CONTAINS(database::data::columnNames, generatedColumnName);
}

TEST(DatabaseTest, shouldGenerateColumnType)
{
    auto generatedColumnType = database::column_type();

    FAKER_EXPECT_CONTAINER_CONTAINS(database::data::columnTypes, generatedColumnType);
}

TEST(DatabaseTest, shouldGenerateEngine)
{
    auto generatedEngine = database::engine();

    FAKER_EXPECT_CONTAINER_CONTAINS(database::data::engines, generatedEngine);
}

TEST(DatabaseTest, shouldGenerateCollation)
{
    auto generatedCollation = database::collation();

    FAKER_EXPECT_CONTAINER_CONTAINS(database::data::collations, generatedCollation);
}

TEST(DatabaseTest, shouldGenerateMongoDbObjectId)
{
    auto mongoDbObjectId = database::mongodb_object_id();

    ASSERT_EQ(mongoDbObjectId.size(), 24);
    ASSERT_TRUE(faker::testing::any_of(mongoDbObjectId, [](char hexNumberCharacter) {
        return string::data::hexLowerCharacters.find(hexNumberCharacter) != std::string::npos;
    }));
}
