#ifndef FAKER_COMPUTER_H
#define FAKER_COMPUTER_H

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
 * @brief Returns a random computer manufacturer name.
 *
 * @returns manufacturer name
 *
 * @code
 * computer::manufacturer() // HP
 * @endcode
 */
std::string_view manufacturer();

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
 * @brief Returns a random CPU manufacturer name.
 *
 * @returns CPU manufacturer name
 *
 * @code
 * computer::cpu_manufacturer() // Intel
 * @endcode
 */
std::string_view cpu_manufacturer();

/**
 * @brief Returns a random CPU type.
 *
 * @returns CPU type
 *
 * @code
 * computer::cpu_type() // x86
 * @endcode
 */
std::string_view cpu_type();

/**
 * @brief Returns a random CPU model.
 *
 * @returns computer CPU model
 *
 * @code
 * computer::cpu_model() // Core i9-11900k
 * @endcode
 */
std::string_view cpu_model();

/**
 * @brief Returns a random GPU manufacturer name.
 *
 * @returns GPU manufacturer name
 *
 * @code
 * computer::gpu_manufacturer() // NVIDIA
 * @endcode
 */
std::string_view gpu_manufacturer();

/**
 * @brief Returns a random GPU type.
 *
 * @returns GPU type
 *
 * @code
 * computer::gpu_type() // Integrated
 * @endcode
 */
std::string_view gpu_type();

/**
 * @brief Returns a random GPU model.
 *
 * @returns computer GPU model
 *
 * @code
 * computer::gpu_model() // NVIDIA GeForce RTX 3080
 * @endcode
 */
std::string_view gpu_model();

}

#endif