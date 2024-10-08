#include <algorithm>
#include <string_view>

#include "gtest/gtest.h"

#include "database_data.h"
#include "faker-cxx/database.h"
#include "number_data.h"

using namespace ::testing;
using namespace faker;
using namespace faker::database;

class DatabaseTest : public Test
{
public:
};

TEST_F(DatabaseTest, shouldGenerateColumnName)
{
    const auto generatedColumnName = columnName();

    ASSERT_TRUE(std::ranges::any_of(columnNames, [generatedColumnName](const std::string_view& columnName)
                                    { return generatedColumnName == columnName; }));
}

TEST_F(DatabaseTest, shouldGenerateColumnType)
{
    const auto generatedColumnType = columnType();

    ASSERT_TRUE(std::ranges::any_of(columnTypes, [generatedColumnType](const std::string_view& columnType)
                                    { return generatedColumnType == columnType; }));
}

TEST_F(DatabaseTest, shouldGenerateEngine)
{
    const auto generatedEngine = engine();

    ASSERT_TRUE(std::ranges::any_of(engines, [generatedEngine](const std::string_view& engine)
                                    { return generatedEngine == engine; }));
}

TEST_F(DatabaseTest, shouldGenerateCollation)
{
    const auto generatedCollation = collation();

    ASSERT_TRUE(std::ranges::any_of(collations, [generatedCollation](const std::string_view& collation)
                                    { return generatedCollation == collation; }));
}

TEST_F(DatabaseTest, shouldGenerateMongoDbObjectId)
{
    const auto generatedMongoDbObjectId = mongoDbObjectId();

    ASSERT_EQ(generatedMongoDbObjectId.size(), 24);
    ASSERT_TRUE(
        std::ranges::any_of(generatedMongoDbObjectId, [](char hexNumberCharacter)
                            { return number::hexLowerCharacters.find(hexNumberCharacter) != std::string::npos; }));
}
