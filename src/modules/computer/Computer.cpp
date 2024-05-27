#include "faker-cxx/Computer.h"

#include "ComputerData.h"
#include "faker-cxx/Helper.h"

namespace faker
{
std::string_view Computer::type()
{
    return Helper::arrayElement(computerTypes);
}

std::string_view Computer::manufacture()
{
    return Helper::arrayElement(computerManufacturers);
}

std::string_view Computer::model()
{
    return Helper::arrayElement(computerModels);
}

std::string_view Computer::cpuManufacture()
{
    return Helper::arrayElement(cpuManufacturers);
}

std::string_view Computer::cpuType()
{
    return Helper::arrayElement(cpuTypes);
}

std::string_view Computer::cpuModel()
{
    return Helper::arrayElement(cpuModels);
}

std::string_view Computer::gpuManufacture()
{
    return Helper::arrayElement(gpuManufacturers);
}

std::string_view Computer::gpuType()
{
    return Helper::arrayElement(gpuTypes);
}

std::string_view Computer::gpuModel()
{
    return Helper::arrayElement(gpuModels);
}
}
