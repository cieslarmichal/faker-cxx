#pragma once

#include <array>
#include <string_view>

namespace faker
{
namespace vehicle
{
const auto bicycle_types = std::to_array<std::string_view>({
    "BMX bike",    "Cargo bike",    "City bike",      "Electric bike", "Folding bike",
    "Hybrid bike", "Mountain bike", "Recumbent bike", "Road bike",     "Tandem bike",
});

const auto vehicle_colors = std::to_array<std::string_view>({"Black", "Blue", "Gray", "Green", "Red", "Silver", "White"});

const auto fuel_types = std::to_array<std::string_view>({
    "Biodiesel", "Diesel",   "Electric", "Ethanol",     "Gasoline",
    "Hybrid",    "Hydrogen", "Methanol", "Natural gas", "Propane",
});

const auto manufacturers = std::to_array<std::string_view>({
    "Acura",    "Alfa Romeo",    "Aston Martin", "Audi",       "BMW",    "Bentley", "Cadillac",   "Chevrolet",
    "Chrysler", "Dodge",         "Ferrari",      "Fiat",       "Ford",   "GMC",     "Honda",      "Hyundai",
    "Infiniti", "Jaguar",        "Jeep",         "Kia",        "Lexus",  "Lincoln", "Lotus",      "Maserati",
    "Mazda",    "Mercedes-Benz", "Mini",         "Mitsubishi", "Nissan", "Peugeot", "Porsche",    "Ram",
    "Renault",  "Rolls-Royce",   "Subaru",       "Suzuki",     "Tesla",  "Toyota",  "Volkswagen", "Volvo",
});

const auto models = std::to_array<std::string_view>({
    "Accord",  "CR-V",     "Camry",    "Civic",         "Corolla",
    "Escape",  "Explorer", "F-150",    "Fiesta",        "Focus",
    "Mustang", "RAV4",     "Ram 1500", "Silverado 1500",
});

const auto vehicle_types = std::to_array<std::string_view>({
    "Boat", "Bus", "Car",     "Minivan", "Motorcycle",
    "RV",   "SUV", "Trailer", "Truck",   "Van",
});

}
}
