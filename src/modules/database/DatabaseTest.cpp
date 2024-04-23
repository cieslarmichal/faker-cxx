#include "faker-cxx/Database.h"

#include <algorithm>

#include "gtest/gtest.h"

#include "../string/data/Characters.h"
#include "data/Collations.h"
#include "data/ColumnData.h"
#include "data/Engines.h"
#include "data/Tables.h"

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

TEST_F(DatabaseTest, shouldGenerateTable)
{
    const auto generatedTable = Database::table();

    ASSERT_TRUE(std::ranges::any_of(tables, [generatedTable](const std::string& table)
                                    { return generatedTable == table; }));
}

TEST_F(DatabaseTest, shouldMapToCorrectType)
{
    const auto columnName = Database::columnName();

    const auto it = faker::columnNameTypeMap.find(columnName);
    ASSERT_NE(faker::columnNameTypeMap.end(), it);

    const auto columnType = (*it).second;

    ASSERT_TRUE(std::ranges::any_of(columnTypes, [columnType](const std::string& type)
                                { return columnType == type; }));
}