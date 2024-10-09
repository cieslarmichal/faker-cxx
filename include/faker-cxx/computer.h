#pragma once

#include <string_view>

#include "faker-cxx/export.h"

namespace faker::computer
{
/**
 * @brief Returns a random computer type.
 *
 * @returns Computer type.
 *
 * @code
 * faker::computer::type() // Laptop
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view type();

/**
 * @brief Returns a random computer manufacture name.
 *
 * @returns Manufacture name.
 *
 * @code
 * faker::computer::manufacture() // HP
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view manufacture();

/**
 * @brief Returns a random computer model.
 *
 * @returns Computer model.
 *
 * @code
 * faker::computer::model() // MacBook Air
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view model();

/**
 * @brief Returns a random CPU manufacture name.
 *
 * @returns CPU manufacture name.
 *
 * @code
 * faker::computer::cpuManufacture() // Intel
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view cpuManufacture();

/**
 * @brief Returns a random CPU type.
 *
 * @returns CPU type.
 *
 * @code
 * faker::computer::cpuType() // x86
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view cpuType();

/**
 * @brief Returns a random CPU model.
 *
 * @returns Computer CPU model.
 *
 * @code
 * faker::computer::cpuModel() // Core i9-11900k
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view cpuModel();

/**
 * @brief Returns a random GPU manufacture name.
 *
 * @returns GPU manufacture name.
 *
 * @code
 * faker::computer::gpuManufacture() // NVIDIA
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view gpuManufacture();

/**
 * @brief Returns a random GPU type.
 *
 * @returns GPU type.
 *
 * @code
 * faker::computer::gpuType() // Integrated
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view gpuType();

/**
 * @brief Returns a random GPU model.
 *
 * @returns Computer GPU model.
 *
 * @code
 * faker::computer::gpuModel() // NVIDIA GeForce RTX 3080
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view gpuModel();

}
