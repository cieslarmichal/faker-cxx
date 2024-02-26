#ifndef FAKER_DATABASE_H
#define FAKER_DATABASE_H

#include <string>

namespace faker::database {
/**
 * @brief Returns a random database column name.
 *
 * @returns database column name.
 *
 * @code
 * database::column_name() // "created_at"
 * @endcode
 */
std::string_view column_name();

/**
 * @brief Returns a random database column type.
 *
 * @returns database column type.
 *
 * @code
 * database::column_type() // "timestamp"
 * @endcode
 */
std::string_view column_type();

/**
 * @brief Returns a random database collation.
 *
 * @returns database collation.
 *
 * @code
 * database::collation() // "utf8_unicode_ci"
 * @endcode
 */
std::string_view collation();

/**
 * @brief Returns a random database engine.
 *
 * @returns database engine.
 *
 * @code
 * database::engine() // "ARCHIVE"
 * @endcode
 */
std::string_view engine();

/**
 * @brief Returns a MongoDB Object Id.
 *
 * @returns MongoDB Object Id.
 *
 * @code
 * database::mongodb_object_id() // "e175cac316a79afdd0ad3afb"
 * @endcode
 */
std::string mongodb_object_id();
}

#endif