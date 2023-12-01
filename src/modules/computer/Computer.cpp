#include "faker-cxx/Computer.h"

#include <string>

#include "data/ComputerData.h"
#include "faker-cxx/Helper.h"

std::string faker::Computer::type()
{
    return Helper::arrayElement(faker::data::ComputerTypes);
}

std::string faker::Computer::manufacture()
{
    return Helper::arrayElement(faker::data::ComputerManufactures);
}

std::string faker::Computer::model()
{
    return Helper::arrayElement(faker::data::ComputerModels);
}

std::string faker::Computer::cpuManufacture()
{
    return Helper::arrayElement(faker::data::ComputerCPUManufactures);
}

std::string faker::Computer::cpuType()
{
    return Helper::arrayElement(faker::data::ComputerCPUTypes);
}

std::string faker::Computer::cpuModel()
{
    return Helper::arrayElement(faker::data::ComputerCPUModels);
}

std::string faker::Computer::gpuManufacture()
{
    return Helper::arrayElement(faker::data::ComputerGPUManufactures);
}

std::string faker::Computer::gpuType()
{
    return Helper::arrayElement(faker::data::ComputerGPUTypes);
}

std::string faker::Computer::gpuModel()
{
    return Helper::arrayElement(faker::data::ComputerGPUModels);
}
