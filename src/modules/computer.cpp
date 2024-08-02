#include "faker-cxx/computer.h"

#include <string_view>

#include "computer_data.h"
#include "faker-cxx/helper.h"

namespace faker::computer
{
std::string_view type()
{
    return helper::randomElement(computerTypes);
}

std::string_view manufacture()
{
    return helper::randomElement(computerManufacturers);
}

std::string_view model()
{
    return helper::randomElement(computerModels);
}

std::string_view cpuManufacture()
{
    return helper::randomElement(cpuManufacturers);
}

std::string_view cpuType()
{
    return helper::randomElement(cpuTypes);
}

std::string_view cpuModel()
{
    return helper::randomElement(cpuModels);
}

std::string_view gpuManufacture()
{
    return helper::randomElement(gpuManufacturers);
}

std::string_view gpuType()
{
    return helper::randomElement(gpuTypes);
}

std::string_view gpuModel()
{
    return helper::randomElement(gpuModels);
}
}
