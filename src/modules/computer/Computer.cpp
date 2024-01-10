#include "faker-cxx/Computer.h"

#include <string>

#include "data/ComputerData.h"
#include "faker-cxx/Helper.h"

namespace faker
{

std::string Computer::type()
{
    return Helper::arrayElement(data::ComputerTypes);
}

std::string Computer::manufacture()
{
    return Helper::arrayElement(data::ComputerManufactures);
}

std::string Computer::model()
{
    return Helper::arrayElement(data::ComputerModels);
}

std::string Computer::cpuManufacture()
{
    return Helper::arrayElement(data::ComputerCPUManufactures);
}

std::string Computer::cpuType()
{
    return Helper::arrayElement(data::ComputerCPUTypes);
}

std::string Computer::cpuModel()
{
    return Helper::arrayElement(data::ComputerCPUModels);
}

std::string Computer::gpuManufacture()
{
    return Helper::arrayElement(data::ComputerGPUManufactures);
}

std::string Computer::gpuType()
{
    return Helper::arrayElement(data::ComputerGPUTypes);
}

std::string Computer::gpuModel()
{
    return Helper::arrayElement(data::ComputerGPUModels);
}
}
