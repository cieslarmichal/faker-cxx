#pragma once

#include <string>

namespace faker
{
class Vehicle
{
public:

    /**
     * @brief Returns a random bicycle type.
     *
     * @returns bicycle type.
     *
     * @code
     * Vehicle::bicycle() // "Electric bike"
     * @endcode
     */
    static std::string bicycle();

    /**
     * @brief Returns a random vehicle color.
     *
     * @returns vehicle color.
     *
     * @code
     * Vehicle::color() // "Silver"
     * @endcode
     */
    static std::string color();

    /**
     * @brief Returns a random vehicle fuel.
     *
     * @returns vehicle fuel.
     *
     * @code
     * Vehicle::fuel() // "Diesel"
     * @endcode
     */
    static std::string fuel();

    /**
     * @brief Returns a random vehicle(car) manufacturer.
     *
     * @returns vehicle(car) manufacturer.
     *
     * @code
     * Vehicle::manufacturer() // "Ferrari"
     * @endcode
     */
    static std::string manufacturer();

    /**
     * @brief Returns a random vehicle(car) model.
     *
     * @returns vehicle(car) model.
     *
     * @code
     * Vehicle::model() // "Fiesta"
     * @endcode
     */
    static std::string model();

    /**
     * @brief Returns a random vehicle type.
     *
     * @returns vehicle type.
     *
     * @code
     * Vehicle::type() // "Van"
     * @endcode
     */
    static std::string type();

    /**
     * @brief Returns a random vehicle(car).
     *
     * @returns vehicle composed by a manufacturer and model.
     *
     * @code
     * Vehicle::vehicle() // "BMW Explorer"
     * @endcode
     */
    static std::string vehicle();

    /**
     * @brief Returns a vehicle identification number (VIN).
     *
     * @returns vehicle identification number.
     *
     * @code
     * Vehicle::vin() // "YV1MH682762184654"
     * @endcode
     */
    static std::string vin();

    /**
     * @brief Returns a vehicle registration number (Vehicle Registration Mark - VRM).
     *
     * @returns vehicle registration number.
     *
     * @code
     * Vehicle::vrm() // "MF56UPA"
     * @endcode
     */
    static std::string vrm();
};
}