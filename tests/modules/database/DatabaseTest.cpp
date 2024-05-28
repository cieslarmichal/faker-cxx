#include "faker-cxx/Database.h"

#include <algorithm>

#include "gtest/gtest.h"

#include "database/DatabaseData.h"
#include "string/data/Characters.h"

using namespace ::testing;
using namespace faker;

class DatabaseTest : public Test
{
public:
};

TEST_F(DatabaseTest, shouldGenerateColumnName)
{
    const auto generatedColumnName = Database::columnName();

    ASSERT_TRUE(std::ranges::any_of(columnNames, [generatedColumnName](const std::string_view& columnName)
                                    { return generatedColumnName == columnName; }));
}

TEST_F(DatabaseTest, shouldGenerateColumnType)
{
    const auto generatedColumnType = Database::columnType();

    ASSERT_TRUE(std::ranges::any_of(columnTypes, [generatedColumnType](const std::string_view& columnType)
                                    { return generatedColumnType == columnType; }));
}

TEST_F(DatabaseTest, shouldGenerateEngine)
{
    const auto generatedEngine = Database::engine();

    ASSERT_TRUE(std::ranges::any_of(engines, [generatedEngine](const std::string_view& engine)
                                    { return generatedEngine == engine; }));
}

TEST_F(DatabaseTest, shouldGenerateCollation)
{
    const auto generatedCollation = Database::collation();

    ASSERT_TRUE(std::ranges::any_of(collations, [generatedCollation](const std::string_view& collation)
                                    { return generatedCollation == collation; }));
}

TEST_F(DatabaseTest, shouldGenerateMongoDbObjectId)
{
    const auto mongoDbObjectId = Database::mongoDbObjectId();

    ASSERT_EQ(mongoDbObjectId.size(), 24);
    ASSERT_TRUE(std::ranges::any_of(mongoDbObjectId, [](char hexNumberCharacter)
                                    { return hexLowerCharacters.find(hexNumberCharacter) != std::string::npos; }));
}
