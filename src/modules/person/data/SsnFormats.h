#pragma once

#include <map>
#include <string>
#include <vector>

#include "faker-cxx/types/SsnCountry.h"

namespace faker
{
const std::map<SsnCountry, std::string> ssnFormats{
    {SsnCountry::Poland, "##[0-1][0-2][0-2]######"},
    {SsnCountry::UnitedStates, "###-##-####"},
    // TODO: handle letters
    {SsnCountry::UnitedKingdom, "LL ## ## ## L"},
    // TODO: handle conditional values like if year starts with 2 then second number must be 0-3
    {SsnCountry::Germany, "####[0-2]#[0-1][0-2][1-2][5-9]##"},
    {SsnCountry::France, "## [0-1][0-2] [0-2]# ### ### ##"},
    // TODO: add alfa-numeric support
    {SsnCountry::Italy, "FFFF FFFF FFFF FFFF"},
    {SsnCountry::Spain, "X########L"},
    {SsnCountry::India, "LLLLL####L"},
};
}
