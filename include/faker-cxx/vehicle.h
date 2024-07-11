#pragma once

#include <string_view>
#include "faker-cxx/export.h"

namespace faker::vehicle
{
    /**
     * @brief Returns a random bicycle type.
     *
     * @returns bicycle type.
     *
     * @code
     * faker::vehicle::bicycle() // "Electric bike"
     * @endcode
     */
    FAKER_CXX_EXPORT std::string_view bicycle();

    /**
     * @brief Returns a random vehicle color.
     *
     * @returns vehicle color.
     *
     * @code
     * faker::vehicle::color() // "Silver"
     * @endcode
     */
    FAKER_CXX_EXPORT std::string_view color();

    /**
     * @brief Returns a random vehicle fuel.
     *
     * @returns vehicle fuel.
     *
     * @code
     * faker::vehicle::fuel() // "Diesel"
     * @endcode
     */
    FAKER_CXX_EXPORT std::string_view fuel();

    /**
     * @brief Returns a random vehicle(car) manufacturer.
     *
     * @returns vehicle(car) manufacturer.
     *
     * @code
     * faker::vehicle::manufacturer() // "Ferrari"
     * @endcode
     */
    FAKER_CXX_EXPORT std::string_view manufacturer();

    /**
     * @brief Returns a random vehicle(car) model.
     *
     * @returns vehicle(car) model.
     *
     * @code
     * faker::vehicle::model() // "Fiesta"
     * @endcode
     */
    FAKER_CXX_EXPORT std::string_view model();

    /**
     * @brief Returns a random vehicle type.
     *
     * @returns vehicle type.
     *
     * @code
     * faker::vehicle::type() // "Van"
     * @endcode
     */
    FAKER_CXX_EXPORT std::string_view type();

    /**
     * @brief Returns a random vehicle(car).
     *
     * @returns vehicle composed by a manufacturer and model.
     *
     * @code
     * faker::vehicle::vehicleName() // "BMW Explorer"
     * @endcode
     */
    FAKER_CXX_EXPORT std::string vehicleName();

    /**
     * @brief Returns a vehicle identification number (VIN).
     *
     * @returns vehicle identification number.
     *
     * @code
     * faker::vehicle::vin() // "YV1MH682762184654"
     * @endcode
     */
    FAKER_CXX_EXPORT std::string vin();

    /**
     * @brief Returns a vehicle registration number (Vehicle Registration Mark - VRM).
     *
     * @returns vehicle registration number.
     *
     * @code
     * faker::vehicle::vrm() // "MF56UPA"
     * @endcode
     */
    FAKER_CXX_EXPORT std::string vrm();
}
