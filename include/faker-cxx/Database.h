#pragma once

#include <string_view>

namespace faker
{
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
    static std::string_view columnName();

    /**
     * @brief Returns a random database column type.
     *
     * @returns Database column type.
     *
     * @code
     * Database::columnType() // "timestamp"
     * @endcode
     */
    static std::string_view columnType();

    /**
     * @brief Returns a random database collation.
     *
     * @returns Database collation.
     *
     * @code
     * Database::collation() // "utf8_unicode_ci"
     * @endcode
     */
    static std::string_view collation();

    /**
     * @brief Returns a random database engine.
     *
     * @returns Database engine.
     *
     * @code
     * Database::engine() // "ARCHIVE"
     * @endcode
     */
    static std::string_view engine();

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
};
}
