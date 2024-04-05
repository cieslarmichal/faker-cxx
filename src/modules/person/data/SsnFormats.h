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
    {SsnCountry::UnitedKingdom, "LL ## ## ## L"},
    {SsnCountry::Germany, "####[0-2]#[0-1][0-2][1-2][5-9]##"},
    {SsnCountry::France, "## [0-1][0-2] [0-2]# ### ### ##"},
    {SsnCountry::Italy, "FFFF FFFF FFFF FFFF"},
    {SsnCountry::Spain, "X########L"},
    {SsnCountry::India, "LLLLL####L"},
};
}
