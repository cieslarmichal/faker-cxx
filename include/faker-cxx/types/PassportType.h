#pragma once

#include <map>
#include <string>

namespace faker
{

enum class PassportCountry
{
    Usa,
    Poland,
    France,
    Romania,
};

const std::map<PassportCountry, std::string> passportFormats{
    {PassportCountry::Usa, "AA0000000"},
    {PassportCountry::Poland, "AA0000000"},
    {PassportCountry::France, "00AA00000"},
    {PassportCountry::Romania, "00000000"},
};

}
