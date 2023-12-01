#pragma once

#include <string>


namespace faker
{
class Computer
{
public:
    static std::string type();
    static std::string manufacture();
    static std::string model();
    static std::string cpuManufacture();
    static std::string cpuType();
    static std::string cpuModel();
    static std::string gpuManufacture();
    static std::string gpuType();
    static std::string gpuModel();


private:
};

}