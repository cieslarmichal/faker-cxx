#pragma once

#include <array>
#include <string_view>

namespace faker::computer
{
const auto computerTypes = std::to_array<std::string_view>({
    "Desktop",
    "Laptop",
    "Mainframe",
    "Supercomputer",
});

const auto computerManufacturers = std::to_array<std::string_view>({
    "Acer", "Alienware", "Apple",  "Asus", "Compaq",    "Dell",      "Fujitsu", "Gateway", "HCL",  "HP",
    "IBM",  "LG",        "Lenovo", "MSI",  "Microsoft", "Panasonic", "Razer",   "Samsung", "Sony", "Toshiba",
});

const auto computerModels = std::to_array<std::string_view>({
    "Alienware",      "Area-51",     "Aspire",    "Aurora",    "Blade",       "Blade Stealth",
    "EliteBook",      "Envy",        "GE Series", "GL Series", "GS Series",   "Galaxy Book",
    "IdeaPad",        "Inspiron",    "Latitude",  "Legion",    "Mac mini",    "MacBook Air",
    "MacBook Pro",    "NUC",         "Notebook",  "Odyssey",   "Pavilion",    "Precision",
    "Predator",       "Presario",    "ROG",       "Satellite", "Spectre",     "Surface Book",
    "Surface Laptop", "Surface Pro", "Swift",     "TUF",       "ThinkCentre", "ThinkPad",
    "ThinkStation",   "TravelMate",  "VAIO",      "VivoBook",  "XPS",         "Yoga",
    "ZenBook",        "iMac",        "m15",
});

const auto cpuManufacturers = std::to_array<std::string_view>({
    "AMD",
    "ARM",
    "Apple",
    "IBM",
    "Intel",
});

const auto cpuTypes = std::to_array<std::string_view>({
    "32-bit",
    "64-bit",
    "ARM",
    "CISC",
    "Deca-Core",
    "Dual-Core",
    "Heterogeneous System Architecture",
    "Hexa-Core",
    "Octa-Core",
    "Quad-Core",
    "RISC",
    "x86",
});

const auto cpuModels = std::to_array<std::string_view>({
    "ARM Cortex-A55", "ARM Cortex-A76", "ARM Cortex-A78",     "Apple M1",       "Apple M1 Max",   "Apple M1 Ultra",
    "Apple M2",       "Apple M2 Max",   "Apple M2 Pro",       "Apple M3 Max",   "Apple M3 Pro",   "Apple M3 Ultra",
    "Apple M3 Ultra", "Athlon 3000G",   "Core i3-10100",      "Core i5-11600K", "Core i7-11700K", "Core i9-11900K",
    "EPYC 7763",      "IBM POWER9",     "Pentium Gold G6400", "Ryzen 3 3300X",  "Ryzen 5 5600X",  "Ryzen 7 5800X",
    "Ryzen 9 5950X",  "Xeon E-2278G",
});

const auto gpuManufacturers = std::to_array<std::string_view>({
    "AMD",
    "ARM",
    "Intel",
    "NVIDIA",
    "Qualcomm",
});

const auto gpuTypes = std::to_array<std::string_view>({
    "Discrete",
    "Integrated",
});

const auto gpuModels = std::to_array<std::string_view>({
    "3dfx Voodoo3",
    "AMD Radeon RX 6700 XT",
    "AMD Radeon RX 6800 XT",
    "AMD Radeon RX 6900 XT",
    "ARM Mali-G78 MP14",
    "ATI Radeon 9800 Pro",
    "Imagination PowerVR GT7600",
    "Intel Xe Graphics",
    "Matrox Millennium G200",
    "NVIDIA GeForce GTX 1650",
    "NVIDIA GeForce GTX 1650 Super",
    "NVIDIA GeForce GTX 1660",
    "NVIDIA GeForce GTX 1660 Super",
    "NVIDIA GeForce GTX 1660 Ti",
    "NVIDIA GeForce RTX 3070",
    "NVIDIA GeForce RTX 3080",
    "NVIDIA GeForce RTX 3090",
    "Qualcomm Adreno 660",
    "S3 Graphics Savage4",
    "SiS 315",
    "Trident Blade3D",
    "VIA S3 Graphics Chrome 520",
    "XGI Volari V8",
});

}
