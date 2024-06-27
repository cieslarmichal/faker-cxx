#include "faker-cxx/Computer.h"

#include <string_view>

#include "ComputerData.h"
#include "faker-cxx/Helper.h"

namespace faker::computer
{
std::string_view type()
{
    return helper::arrayElement(computerTypes);
}

std::string_view manufacture()
{
    return helper::arrayElement(computerManufacturers);
}

std::string_view model()
{
    return helper::arrayElement(computerModels);
}

std::string_view cpuManufacture()
{
    return helper::arrayElement(cpuManufacturers);
}

std::string_view cpuType()
{
    return helper::arrayElement(cpuTypes);
}

std::string_view cpuModel()
{
    return helper::arrayElement(cpuModels);
}

std::string_view gpuManufacture()
{
    return helper::arrayElement(gpuManufacturers);
}

std::string_view gpuType()
{
    return helper::arrayElement(gpuTypes);
}

std::string_view gpuModel()
{
    return helper::arrayElement(gpuModels);
}
}
