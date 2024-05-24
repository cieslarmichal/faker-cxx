#include "faker-cxx/Database.h"

#include <algorithm>

#include "gtest/gtest.h"

#include "string/data/Characters.h"
#include "database/data/Collations.h"
#include "database/data/ColumnNames.h"
#include "database/data/ColumnTypes.h"
#include "database/data/Engines.h"

using namespace ::testing;
using namespace faker;

class DatabaseTest : public Test
{
public:
};

TEST_F(DatabaseTest, shouldGenerateColumnName)
{
    const auto generatedColumnName = Database::columnName();

    ASSERT_TRUE(std::ranges::any_of(columnNames, [generatedColumnName](const std::string& columnName)
                                    { return generatedColumnName == columnName; }));
}

TEST_F(DatabaseTest, shouldGenerateColumnType)
{
    const auto generatedColumnType = Database::columnType();

    ASSERT_TRUE(std::ranges::any_of(columnTypes, [generatedColumnType](const std::string& columnType)
                                    { return generatedColumnType == columnType; }));
}

TEST_F(DatabaseTest, shouldGenerateEngine)
{
    const auto generatedEngine = Database::engine();

    ASSERT_TRUE(std::ranges::any_of(engines, [generatedEngine](const std::string& engine)
                                    { return generatedEngine == engine; }));
}

TEST_F(DatabaseTest, shouldGenerateCollation)
{
    const auto generatedCollation = Database::collation();

    ASSERT_TRUE(std::ranges::any_of(collations, [generatedCollation](const std::string& collation)
                                    { return generatedCollation == collation; }));
}

TEST_F(DatabaseTest, shouldGenerateMongoDbObjectId)
{
    const auto mongoDbObjectId = Database::mongoDbObjectId();

    ASSERT_EQ(mongoDbObjectId.size(), 24);
    ASSERT_TRUE(std::ranges::any_of(mongoDbObjectId, [](char hexNumberCharacter)
                                    { return hexLowerCharacters.find(hexNumberCharacter) != std::string::npos; }));
}
