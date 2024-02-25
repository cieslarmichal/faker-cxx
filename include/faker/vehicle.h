#pragma once

#include <string>

namespace faker::vehicle {
/**
 * @brief Returns a random bicycle type.
 *
 * @returns bicycle type.
 *
 * @code
 * vehicle::bicycle() // "Electric bike"
 * @endcode
 */
std::string bicycle();

/**
 * @brief Returns a random vehicle color.
 *
 * @returns vehicle color.
 *
 * @code
 * vehicle::color() // "Silver"
 * @endcode
 */
std::string color();

/**
 * @brief Returns a random vehicle fuel.
 *
 * @returns vehicle fuel.
 *
 * @code
 * vehicle::fuel() // "Diesel"
 * @endcode
 */
std::string fuel();

/**
 * @brief Returns a random vehicle(car) manufacturer.
 *
 * @returns vehicle(car) manufacturer.
 *
 * @code
 * vehicle::manufacturer() // "Ferrari"
 * @endcode
 */
std::string manufacturer();

/**
 * @brief Returns a random vehicle(car) model.
 *
 * @returns vehicle(car) model.
 *
 * @code
 * vehicle::model() // "Fiesta"
 * @endcode
 */
std::string model();

/**
 * @brief Returns a random vehicle type.
 *
 * @returns vehicle type.
 *
 * @code
 * vehicle::type() // "Van"
 * @endcode
 */
std::string type();

/**
 * @brief Returns a random vehicle(car).
 *
 * @returns vehicle composed by a manufacturer and model.
 *
 * @code
 * vehicle::vehicle() // "BMW Explorer"
 * @endcode
 */
std::string vehicle();

/**
 * @brief Returns a vehicle identification number (VIN).
 *
 * @returns vehicle identification number.
 *
 * @code
 * vehicle::vin() // "YV1MH682762184654"
 * @endcode
 */
std::string vin();

/**
 * @brief Returns a vehicle registration number (vehicle Registration Mark - VRM).
 *
 * @returns vehicle registration number.
 *
 * @code
 * vehicle::vrm() // "MF56UPA"
 * @endcode
 */
std::string vrm();
}