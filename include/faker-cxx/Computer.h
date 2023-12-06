#pragma once

#include <string>

namespace faker
{
class Computer
{
public:
    /*
     * @brief Returns a random computer type.
     *
     * @returns computer type
     *
     * @code
     * Computer::type() // Laptop
     */
    static std::string type();
    /*
     * @brief Returns a random computer manufacture name.
     *
     * @returns manufacture name
     *
     * @code
     * Computer::manufacture() // HP
     */
    static std::string manufacture();
    /*
     * @brief Returns a random computer model.
     *
     * @returns computer model
     *
     * @code
     * Computer::model() // MacBook Air
     */
    static std::string model();
    /*
     * @brief Returns a random CPU manufacture name.
     *
     * @returns CPU manufacture name
     *
     * @code
     * Computer::cpuManufacture() // Intel
     */
    static std::string cpuManufacture();
    /*
     * @brief Returns a random CPU type.
     *
     * @returns CPU type
     *
     * @code
     * Computer::cpuType() // x86
     */
    static std::string cpuType();
    /*
     * @brief Returns a random CPU model.
     *
     * @returns computer CPU model
     *
     * @code
     * Computer::cpuModel() // Core i9-11900k
     */
    static std::string cpuModel();
    /*
     * @brief Returns a random GPU manufacture name.
     *
     * @returns GPU manufacture name
     *
     * @code
     * Computer::gpuManufacture() // NVIDIA
     */
    static std::string gpuManufacture();
    /*
     * @brief Returns a random GPU type.
     *
     * @returns GPU type
     *
     * @code
     * Computer::gpuType() // Integrated
     */
    static std::string gpuType();
    /*
     * @brief Returns a random GPU model.
     *
     * @returns computer GPU model
     *
     * @code
     * Computer::gpuModel() // NVIDIA GeForce RTX 3080
     */
    static std::string gpuModel();
};

}