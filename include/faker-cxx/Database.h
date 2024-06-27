#pragma once

#include <string_view>

namespace faker::database
{
    /**
     * @brief Returns a random database column name.
     *
     * @returns Database column name.
     *
     * @code
     * faker::database::columnName() // "created_at"
     * @endcode
     */
    std::string_view columnName();

    /**
     * @brief Returns a random database column type.
     *
     * @returns Database column type.
     *
     * @code
     * faker::database::columnType() // "timestamp"
     * @endcode
     */
    std::string_view columnType();

    /**
     * @brief Returns a random database collation.
     *
     * @returns Database collation.
     *
     * @code
     * faker::database::collation() // "utf8_unicode_ci"
     * @endcode
     */
    std::string_view collation();

    /**
     * @brief Returns a random database engine.
     *
     * @returns Database engine.
     *
     * @code
     * faker::database::engine() // "ARCHIVE"
     * @endcode
     */
    std::string_view engine();

    /**
     * @brief Returns a MongoDB Object Id.
     *
     * @returns MongoDB Object Id.
     *
     * @code
     * faker::database::mongoDbObjectId() // "e175cac316a79afdd0ad3afb"
     * @endcode
     */
    std::string mongoDbObjectId();
}
