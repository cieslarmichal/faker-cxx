#include "faker-cxx/Computer.h"

#include <string_view>

#include "ComputerData.h"
#include "faker-cxx/Helper.h"

namespace faker::computer
{
std::string_view type()
{
    return Helper::arrayElement(computerTypes);
}

std::string_view manufacture()
{
    return Helper::arrayElement(computerManufacturers);
}

std::string_view model()
{
    return Helper::arrayElement(computerModels);
}

std::string_view cpuManufacture()
{
    return Helper::arrayElement(cpuManufacturers);
}

std::string_view cpuType()
{
    return Helper::arrayElement(cpuTypes);
}

std::string_view cpuModel()
{
    return Helper::arrayElement(cpuModels);
}

std::string_view gpuManufacture()
{
    return Helper::arrayElement(gpuManufacturers);
}

std::string_view gpuType()
{
    return Helper::arrayElement(gpuTypes);
}

std::string_view gpuModel()
{
    return Helper::arrayElement(gpuModels);
}
}
