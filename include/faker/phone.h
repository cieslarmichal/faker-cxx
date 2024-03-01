#ifndef FAKER_PHONE_H
#define FAKER_PHONE_H

#include <optional>
#include <string>

namespace faker::phone {
enum class phone_number_format_t {
    default_format,
    afghanistan,
    aland_islands,
    albania,
    algeria,
    american_samoa,
    andorra,
    angola,
    anguilla,
    antigua_and_barbuda,
    argentina,
    armenia,
    aruba,
    australia,
    austria,
    azerbaijan,
    bahamas,
    bahrain,
    bangladesh,
    barbados,
    belarus,
    belgium,
    belize,
    benin,
    bermuda,
    bhutan,
    bolivia,
    Bosnia_and_herzegovina,
    botswana,
    brazil,
    brunei_darussalam,
    bulgaria,
    burkina_faso,
    burundi,
    cambodia,
    cameroon,
    canada,
    cape_verde,
    cayman_islands,
    central_african_republic,
    chad,
    chile,
    china,
    colombia,
    comoros,
    congo,
    cook_islands,
    costa_rica,
    croatia,
    cuba,
    curacao,
    cyprus,
    czechia,
    democratic_republic_of_congo,
    denmark,
    djibouti,
    dominica,
    dominican_republic,
    ecuador,
    egypt,
    el_salvador,
    equatorial_guinea,
    eritrea,
    estonia,
    eswatini,
    ethiopia,
    faroe_islands,
    fiji,
    finland,
    france,
    french_guiana,
    french_polynesia,
    gabon,
    gambia,
    georgia,
    germany,
    ghana,
    gibraltar,
    greece,
    greenland,
    grenada,
    guadeloupe,
    guam,
    guatemala,
    guernsey,
    guinea,
    guinea_bissau,
    guyana,
    haiti,
    holy_see_vatican_city_state,
    honduras,
    hong_kong,
    hungary,
    iceland,
    india,
    indonesia,
    iran,
    iraq,
    ireland,
    isle_of_man,
    israel,
    italy,
    jamaica,
    japan,
    jersey,
    jordan,
    republic_of_korea,
    kuwait,
    kyrgyz_republic,
    latvia,
    lebanon,
    lesotho,
    liberia,
    libyan_arab_jamahiriya,
    liechtenstein,
    lithuania,
    luxembourg,
    macao,
    madagascar,
    malawi,
    malaysia,
    maldives,
    mali,
    malta,
    marshall_islands,
    martinique,
    mauritania,
    mauritius,
    mayotte,
    mexico,
    micronesia,
    moldova,
    monaco,
    mongolia,
    montenegro,
    montserrat,
    morocco,
    mozambique,
    myanmar,
    namibia,
    nauru,
    nepal,
    netherlands,
    new_caledonia,
    new_zealand,
    nicaragua,
    niger,
    nigeria,
    niue,
    north_macedonia,
    northern_mariana_islands,
    norway,
    oman,
    pakistan,
    palau,
    palestine,
    panama,
    papua_new_guinea,
    paraguay,
    peru,
    philippines,
    poland,
    portugal,
    puerto_rico,
    qatar,
    reunion,
    romania,
    russian_federation,
    rwanda,
    saint_barthelemy,
    saint_helena,
    saint_kitts_and_nevis,
    saint_lucia,
    saint_martin,
    saint_pierre_and_miquelon,
    saint_vincent_and_grenadines,
    samoa,
    san_marino,
    sao_tome_and_principe,
    saudi_arabia,
    senegal,
    serbia,
    seychelles,
    sierra_leone,
    singapore,
    saint_maarten,
    slovakia,
    slovenia,
    solomon_islands,
    somalia,
    south_africa,
    south_sudan,
    spain,
    sri_lanka,
    sudan,
    suriname,
    svalbard_and_jan_mayen_islands,
    sweden,
    switzerland,
    syrian_arab_republic,
    taiwan,
    tajikistan,
    tanzania,
    thailand,
    timor_leste,
    togo,
    tonga,
    trinidad_and_tobago,
    tunisia,
    turkey,
    turkmenistan,
    turks_and_caicos_islands,
    tuvalu,
    uganda,
    ukraine,
    united_arab_emirates,
    england,
    usa,
    uruguay,
    uzbekistan,
    vanuatu,
    venezuela,
    vietnam,
    virgin_islands_british,
    virgin_islands_us,
    wallis_and_futuna,
    western_sahara,
    yemen,
    zambia,
    zimbabwe
};

/**
 * @brief Returns a random phone number.
 *
 * @param string The optional string to use.
 *
 * @returns Random phone number.
 *
 * @code
 * phone::number() // "961-770-7727"
 * phone::number("501-###-###") // "501-039-841"
 * phone::number("+48 91 ### ## ##") // "+48 91 463 61 70"
 * @endcode
 */
std::string number(std::optional<std::string> = std::nullopt);

/**
 * @brief Returns a random phone platform.
 *
 * @returns Random phone platform.
 *
 * @code
 * phone::platform() // "iOS"
 * @endcode
 */
std::string_view platform();

/**
 * @brief Returns a random phone model.
 *
 * @returns Random phone model.
 *
 * @code
 * phone::model_name() // "Samsung Galaxy S22"
 * @endcode
 */
std::string_view model_name();

/**
 * @brief Returns a random phone manufacturer.
 *
 * @returns Random phone manufacturer.
 *
 * @code
 * phone::manufacturer() // "Sony"
 * @endcode
 */
std::string_view manufacturer();

/**
 * @brief Returns a random phone number based on country phone number template.
 *
 * @param format Enum country format, more details in phone_number_format_t.h.
 *
 * @returns Random phone number based on country phone number template.
 *
 * @code
 * phone::number(phone_number_format_t::Usa) // "+1 (395) 714-1494"
 * @endcode
 */
std::string number(phone_number_format_t format);

/**
 * @brief Returns IMEI number.
 *
 * @returns IMEI number.
 *
 * @code
 * phone::imei() // "13-850175-913761-7"
 * @endcode
 */
std::string imei();
}

#endif