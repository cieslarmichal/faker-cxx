#pragma once

#include <optional>
#include <string>
#include <string_view>
#include <unordered_map>
#include "faker-cxx/export.h"

namespace faker::phone
{
enum class PhoneNumberCountryFormat;
    /**
     * @brief Returns a random phone number.
     *
     * @param string The optional string to use.
     *
     * @returns Random phone number.
     *
     * @code
     * faker::phone::phoneNumberByFormat() // "961-770-7727"
     * faker::phone::phoneNumberByFormat("501-###-###") // "501-039-841"
     * faker::phone::phoneNumberByFormat("+48 91 ### ## ##") // "+48 91 463 61 70"
     * @endcode
     */
    FAKER_CXX_EXPORT std::string phoneNumberByFormat(std::optional<std::string> = std::nullopt);

    /**
     * @brief Returns a random phone platform.
     *
     * @returns Random phone platform.
     *
     * @code
     * faker::phone::platform() // "iOS"
     * @endcode
     */
    FAKER_CXX_EXPORT std::string_view platform();

    /**
     * @brief Returns a random phone model.
     *
     * @returns Random phone model.
     *
     * @code
     * faker::phone::modelName() // "Samsung Galaxy S22"
     * @endcode
     */
    FAKER_CXX_EXPORT std::string_view modelName();

    /**
     * @brief Returns a random phone manufacturer.
     *
     * @returns Random phone manufacturer.
     *
     * @code
     * faker::phone::manufacturer() // "Sony"
     * @endcode
     */
    FAKER_CXX_EXPORT std::string_view manufacturer();

    /**
     * @brief Returns a random phone number based on country phone number template.
     *
     * @param format Enum country format, more details in PhoneNumberCountryFormat.h.
     *
     * @returns Random phone number based on country phone number template.
     *
     * @code
     * faker::phone::number() // "234-532-654"
     * faker::phone::number(PhoneNumberCountryFormat::Usa) // "+1 (395) 714-1494"
     * @endcode
     */
    FAKER_CXX_EXPORT std::string phoneNumberByCountry(std::optional<PhoneNumberCountryFormat> format = std::nullopt);

    /**
     * @brief Returns IMEI number.
     *
     * @returns IMEI number.
     *
     * @code
     * faker::phone::imei() // "13-850175-913761-7"
     * @endcode
     */
    FAKER_CXX_EXPORT std::string imei();

    /**
     * @brief returns a random country area code
     *
     * @returns Random country area code
     *
     * @code
     * faker::phone::areaCode() // "+1"
     * @endcode
     */
    FAKER_CXX_EXPORT std::string_view areaCode();

    FAKER_CXX_EXPORT std::unordered_map<PhoneNumberCountryFormat, std::string> createPhoneNumberFormatMap();

enum class PhoneNumberCountryFormat
{
    Default,
    Afghanistan,
    AlandIslands,
    Albania,
    Algeria,
    AmericanSamoa,
    Andorra,
    Angola,
    Anguilla,
    AntiguaAndBarbuda,
    Argentina,
    Armenia,
    Aruba,
    Australia,
    Austria,
    Azerbaijan,
    Bahamas,
    Bahrain,
    Bangladesh,
    Barbados,
    Belarus,
    Belgium,
    Belize,
    Benin,
    Bermuda,
    Bhutan,
    Bolivia,
    BosniaAndHerzegovina,
    Botswana,
    Brazil,
    BruneiDarussalam,
    Bulgaria,
    BurkinaFaso,
    Burundi,
    Cambodia,
    Cameroon,
    Canada,
    CapeVerde,
    CaymanIslands,
    CentralAfricanRepublic,
    Chad,
    Chile,
    China,
    Colombia,
    Comoros,
    Congo,
    CookIslands,
    CostaRica,
    Croatia,
    Cuba,
    Curacao,
    Cyprus,
    Czechia,
    DemocraticRepublicOfTheCongo,
    Denmark,
    Djibouti,
    Dominica,
    DominicanRepublic,
    Ecuador,
    Egypt,
    ElSalvador,
    EquatorialGuinea,
    Eritrea,
    Estonia,
    Eswatini,
    Ethiopia,
    FaroeIslands,
    Fiji,
    Finland,
    France,
    FrenchGuiana,
    FrenchPolynesia,
    Gabon,
    Gambia,
    Georgia,
    Germany,
    Ghana,
    Gibraltar,
    Greece,
    Greenland,
    Grenada,
    Guadeloupe,
    Guam,
    Guatemala,
    Guernsey,
    Guinea,
    GuineaBissau,
    Guyana,
    Haiti,
    HolySeeVaticanCityState,
    Honduras,
    HongKong,
    Hungary,
    Iceland,
    India,
    Indonesia,
    Iran,
    Iraq,
    Ireland,
    IsleOfMan,
    Israel,
    Italy,
    Jamaica,
    Japan,
    Jersey,
    Jordan,
    RepublicOfKorea,
    Kuwait,
    KyrgyzRepublic,
    Latvia,
    Lebanon,
    Lesotho,
    Liberia,
    LibyanArabJamahiriya,
    Liechtenstein,
    Lithuania,
    Luxembourg,
    Macao,
    Madagascar,
    Malawi,
    Malaysia,
    Maldives,
    Mali,
    Malta,
    MarshallIslands,
    Martinique,
    Mauritania,
    Mauritius,
    Mayotte,
    Mexico,
    Micronesia,
    Moldova,
    Monaco,
    Mongolia,
    Montenegro,
    Montserrat,
    Morocco,
    Mozambique,
    Myanmar,
    Namibia,
    Nauru,
    Nepal,
    Netherlands,
    NewCaledonia,
    NewZealand,
    Nicaragua,
    Niger,
    Nigeria,
    Niue,
    NorthMacedonia,
    NorthernMarianaIslands,
    Norway,
    Oman,
    Pakistan,
    Palau,
    Palestine,
    Panama,
    PapuaNewGuinea,
    Paraguay,
    Peru,
    Philippines,
    Poland,
    Portugal,
    PuertoRico,
    Qatar,
    Reunion,
    Romania,
    RussianFederation,
    Rwanda,
    SaintBarthelemy,
    SaintHelena,
    SaintKittsAndNevis,
    SaintLucia,
    SaintMartin,
    SaintPierreAndMiquelon,
    SaintVincentAndTheGrenadines,
    Samoa,
    SanMarino,
    SaoTomeAndPrincipe,
    SaudiArabia,
    Senegal,
    Serbia,
    Seychelles,
    SierraLeone,
    Singapore,
    SintMaarten,
    Slovakia,
    Slovenia,
    SolomonIslands,
    Somalia,
    SouthAfrica,
    SouthSudan,
    Spain,
    SriLanka,
    Sudan,
    Suriname,
    SvalbardAndJanMayenIslands,
    Sweden,
    Switzerland,
    SyrianArabRepublic,
    Taiwan,
    Tajikistan,
    Tanzania,
    Thailand,
    TimorLeste,
    Togo,
    Tonga,
    TrinidadAndTobago,
    Tunisia,
    Turkey,
    Turkmenistan,
    TurksAndCaicosIslands,
    Tuvalu,
    Uganda,
    Ukraine,
    UnitedArabEmirates,
    UK,
    Usa,
    Uruguay,
    Uzbekistan,
    Vanuatu,
    Venezuela,
    Vietnam,
    VirginIslandsBritish,
    VirginIslandsUS,
    WallisAndFutuna,
    WesternSahara,
    Yemen,
    Zambia,
    Zimbabwe,
};
}
