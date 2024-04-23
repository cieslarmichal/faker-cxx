#pragma once

#include <string>

namespace faker
{
enum class SqlCommandType
{
    DDL,
    DQL,
    DML,
    DCL,
    TCL,
};

class Database
{
public:
    /**
     * @brief Returns a random database column name.
     *
     * @returns Database column name.
     *
     * @code
     * Database::columnName() // "created_at"
     * @endcode
     */
    static std::string columnName();

    /**
     * @brief Returns a random database column type.
     *
     * @returns Database column type.
     *
     * @code
     * Database::columnType() // "timestamp"
     * @endcode
     */
    static std::string columnType();

    /**
     * @brief Returns a random database collation.
     *
     * @returns Database collation.
     *
     * @code
     * Database::collation() // "utf8_unicode_ci"
     * @endcode
     */
    static std::string collation();

    /**
     * @brief Returns a random database engine.
     *
     * @returns Database engine.
     *
     * @code
     * Database::engine() // "ARCHIVE"
     * @endcode
     */
    static std::string engine();

    /**
     * @brief Returns a MongoDB Object Id.
     *
     * @returns MongoDB Object Id.
     *
     * @code
     * Database::mongoDbObjectId() // "e175cac316a79afdd0ad3afb"
     * @endcode
     */
    static std::string mongoDbObjectId();

    /**
     * @brief Returns a table.
     *
     * @returns Table name.
     *
     * @code
     * Database::table() // "users"
     * @endcode
     */
    static std::string table();

    /**
     * @brief Returns a specified sqlCommand based on the commandType parameter.
     *
     * @param commandType SqlCommandType parameter to specify the SqlCommandType for generation.
     * 
     * @returns SqlCommand string leveraging the columns specified in `ColumnNames.h`.
     *
     * @code
     * Database::sqlCommand() // "SELECT [id], [name], [status] FROM [users];"
     * Database::sqlCommand(SqlCommandType::DML) // INSERT into users (id, name, email) VALUES ('id', 'name', 'email@gmail.com');
     * @endcode
     */
    static std::string sqlCommand(SqlCommandType commandType = SqlCommandType::DQL);
};
}
