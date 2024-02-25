#pragma once

#include <string_view>

namespace faker::computer {
/**
 * @brief Returns a random computer type.
 *
 * @returns computer type
 *
 * @code
 * computer::type() // Laptop
 * @endcode
 */
std::string_view type();

/**
 * @brief Returns a random computer manufacture name.
 *
 * @returns manufacture name
 *
 * @code
 * computer::manufacture() // HP
 * @endcode
 */
std::string_view manufacture();

/**
 * @brief Returns a random computer model.
 *
 * @returns computer model
 *
 * @code
 * computer::model() // MacBook Air
 * @endcode
 */
std::string_view model();

/**
 * @brief Returns a random CPU manufacture name.
 *
 * @returns CPU manufacture name
 *
 * @code
 * computer::cpuManufacture() // Intel
 * @endcode
 */
std::string_view cpuManufacture();

/**
 * @brief Returns a random CPU type.
 *
 * @returns CPU type
 *
 * @code
 * computer::cpuType() // x86
 * @endcode
 */
std::string_view cpuType();

/**
 * @brief Returns a random CPU model.
 *
 * @returns computer CPU model
 *
 * @code
 * computer::cpuModel() // Core i9-11900k
 * @endcode
 */
std::string_view cpuModel();

/**
 * @brief Returns a random GPU manufacture name.
 *
 * @returns GPU manufacture name
 *
 * @code
 * computer::gpuManufacture() // NVIDIA
 * @endcode
 */
std::string_view gpuManufacture();

/**
 * @brief Returns a random GPU type.
 *
 * @returns GPU type
 *
 * @code
 * computer::gpuType() // Integrated
 * @endcode
 */
std::string_view gpuType();

/**
 * @brief Returns a random GPU model.
 *
 * @returns computer GPU model
 *
 * @code
 * computer::gpuModel() // NVIDIA GeForce RTX 3080
 * @endcode
 */
std::string_view gpuModel();

}
