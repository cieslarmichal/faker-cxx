#include "computer_data.h"

namespace faker::computer::data {
const std::array<std::string_view, 4> ComputerTypes
    = { "Desktop", "Laptop", "Mainframe", "Supercomputer" };

const std::array<std::string_view, 20> ComputerManufactures = { "Apple", "Dell", "HP", "Lenovo",
    "Acer", "Asus", "Microsoft", "Samsung", "Toshiba", "Sony", "MSI", "Gateway", "Fujitsu", "HCL",
    "Panasonic", "LG", "IBM", "Compaq", "Alienware", "Razer" };

// todo - it is possible to link the models to brands in the future.
const std::array<std::string_view, 45> ComputerModels = { "MacBook Air", "MacBook Pro", "iMac",
    "Mac mini", "Inspiron", "XPS", "Alienware", "Latitude", "Precision", "Spectre", "Envy",
    "Pavilion", "EliteBook", "ThinkPad", "Yoga", "Legion", "IdeaPad", "Aspire", "Predator",
    "TravelMate", "Swift", "ZenBook", "ROG", "VivoBook", "TUF", "Surface Laptop", "Surface Pro",
    "Surface Book", "Galaxy Book", "Notebook", "Odyssey", "Satellite", "VAIO", "GS Series",
    "GE Series", "GL Series", "ThinkCentre", "ThinkStation", "Presario", "Area-51", "m15", "Aurora",
    "Blade", "Blade Stealth", "NUC" };

const std::array<std::string_view, 5> ComputerCPUManufactures
    = { "Intel", "AMD", "ARM", "IBM", "Apple" };

const std::array<std::string_view, 12> ComputerCPUTypes
    = { "Dual-Core", "Quad-Core", "Hexa-Core", "Octa-Core", "Deca-Core",
          "Heterogeneous System Architecture", "ARM", "x86", "64-bit", "32-bit", "RISC", "CISC" };

const std::array<std::string_view, 26> ComputerCPUModels
    = { "Core i9-11900K", "Core i7-11700K", "Core i5-11600K", "Core i3-10100", "Xeon E-2278G",
          "Pentium Gold G6400", "Ryzen 9 5950X", "Ryzen 7 5800X", "Ryzen 5 5600X", "Ryzen 3 3300X",
          "EPYC 7763", "Athlon 3000G", "Apple M1", "Apple M1 Max", "Apple M1 Ultra", "Apple M2",
          "Apple M2 Pro", "Apple M2 Max", "Apple M3 Ultra", "Apple M3 Pro", "Apple M3 Max",
          "Apple M3 Ultra", "IBM POWER9", "ARM Cortex-A78", "ARM Cortex-A76", "ARM Cortex-A55" };

const std::array<std::string_view, 5> ComputerGPUManufactures = {
    "NVIDIA",
    "AMD",
    "Intel",
    "ARM",
    "Qualcomm",
};

const std::array<std::string_view, 2> ComputerGPUTypes = { "Integrated", "Discrete" };

const std::array<std::string_view, 23> ComputerGPUModels
    = { "NVIDIA GeForce RTX 3090", "NVIDIA GeForce RTX 3080", "NVIDIA GeForce RTX 3070",
          "NVIDIA GeForce GTX 1660 Ti", "NVIDIA GeForce GTX 1660 Super", "NVIDIA GeForce GTX 1660",
          "NVIDIA GeForce GTX 1650 Super", "NVIDIA GeForce GTX 1650", "AMD Radeon RX 6900 XT",
          "AMD Radeon RX 6800 XT", "AMD Radeon RX 6700 XT", "Intel Xe Graphics",
          "ARM Mali-G78 MP14", "Qualcomm Adreno 660", "Imagination PowerVR GT7600",
          "VIA S3 Graphics Chrome 520", "Matrox Millennium G200", "SiS 315", "3dfx Voodoo3",
          "S3 Graphics Savage4", "XGI Volari V8", "Trident Blade3D", "ATI Radeon 9800 Pro" };

// todo - add more component names

}
