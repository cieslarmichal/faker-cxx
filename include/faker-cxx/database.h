#pragma once

#include <string_view>
#include "faker-cxx/export.h"

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
    FAKER_CXX_EXPORT std::string_view columnName();

    /**
     * @brief Returns a random database column type.
     *
     * @returns Database column type.
     *
     * @code
     * faker::database::columnType() // "timestamp"
     * @endcode
     */
    FAKER_CXX_EXPORT std::string_view columnType();

    /**
     * @brief Returns a random database collation.
     *
     * @returns Database collation.
     *
     * @code
     * faker::database::collation() // "utf8_unicode_ci"
     * @endcode
     */
    FAKER_CXX_EXPORT std::string_view collation();

    /**
     * @brief Returns a random database engine.
     *
     * @returns Database engine.
     *
     * @code
     * faker::database::engine() // "ARCHIVE"
     * @endcode
     */
    FAKER_CXX_EXPORT std::string_view engine();

    /**
     * @brief Returns a MongoDB Object Id.
     *
     * @returns MongoDB Object Id.
     *
     * @code
     * faker::database::mongoDbObjectId() // "e175cac316a79afdd0ad3afb"
     * @endcode
     */
    FAKER_CXX_EXPORT std::string mongoDbObjectId();
}
