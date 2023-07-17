#pragma once

#include <vector>

namespace faker
{
enum class BicCountry
{
    Poland,
};

const std::vector<BicCountry> supportedBicCountries{BicCountry::Poland};

}
