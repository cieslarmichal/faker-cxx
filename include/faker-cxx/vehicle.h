#pragma once

#include <string>
#include <string_view>

#include "faker-cxx/export.h"
#include "faker-cxx/types/locale.h"

namespace faker::vehicle
{
/**
 * @brief Returns a random bicycle type.
 *@param locale The locale. Defaults to `Locale::en_US`.
 *
 * @returns bicycle type.
 *
 * @code
 * faker::vehicle::bicycle() // "Electric bike"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view bicycle(Locale locale = Locale::en_US);

/**
 * @brief Returns a random vehicle color.
 * 
 *@param locale The locale. Defaults to `Locale::en_US`.
 *
 * @returns vehicle color.
 *
 * @code
 * faker::vehicle::color() // "Silver"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view color(Locale locale = Locale::en_US);

/**
 * @brief Returns a random vehicle fuel.
 * 
 *@param locale The locale. Defaults to `Locale::en_US`.
 *
 * @returns vehicle fuel.
 *
 * @code
 * faker::vehicle::fuel() // "Diesel"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view fuel(Locale locale = Locale::en_US);

/**
 * @brief Returns a random vehicle(car) manufacturer.
 *
 * @param locale The locale. Defaults to `Locale::en_US`.
 *
 * @returns vehicle(car) manufacturer.
 *
 * @code
 * faker::vehicle::manufacturer() // "Ferrari"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view manufacturer(Locale locale = Locale::en_US);

/**
 * @brief Returns a random vehicle(car) model.
 *
 * @param locale The locale. Defaults to `Locale::en_US`.
 *
 * @returns vehicle(car) model.
 *
 * @code
 * faker::vehicle::model() // "Fiesta"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view model(Locale locale = Locale::en_US);

/**
 * @brief Returns a random vehicle type.
 *
 * @param locale The locale. Defaults to `Locale::en_US`.
 *
 * @returns vehicle type.
 *
 * @code
 * faker::vehicle::type() // "Van"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view type(Locale locale = Locale::en_US);

/**
 * @brief Returns a random vehicle(car).
 *
 * @param locale The locale. Defaults to `Locale::en_US`.
 *
 * @returns vehicle composed by a manufacturer and model.
 *
 * @code
 * faker::vehicle::vehicleName() // "BMW Explorer"
 * @endcode
 */
FAKER_CXX_EXPORT std::string vehicleName(Locale locale = Locale::en_US);

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
