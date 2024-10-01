#pragma once

#include <array>
#include <span>
#include <string_view>

namespace faker::vehicle
{
struct VehicleDefinition
{
    std::span<const std::string_view> bicycles;
    std::span<const std::string_view> colors;
    std::span<const std::string_view> fuelTypes;
    std::span<const std::string_view> manufacturers;
    std::span<const std::string_view> models;
    std::span<const std::string_view> vehicles;
};

const auto enUSBicycles = std::to_array<std::string_view>({
    "BMX bike",
    "Cargo bike",
    "City bike",
    "Electric bike",
    "Folding bike",
    "Hybrid bike",
    "Mountain bike",
    "Recumbent bike",
    "Road bike",
    "Tandem bike",
});

const auto enUSColors = std::to_array<std::string_view>({
    "Black",
    "Blue",
    "Gray",
    "Green",
    "Red",
    "Silver",
    "White",
});

const auto enUSFuelTypes = std::to_array<std::string_view>({
    "Biodiesel",
    "Diesel",
    "Electric",
    "Ethanol",
    "Gasoline",
    "Hybrid",
    "Hydrogen",
    "Methanol",
    "Natural gas",
    "Propane",
});

const auto enUSManufacturers = std::to_array<std::string_view>({
    "Acura",    "Alfa Romeo",    "Aston Martin", "Audi",       "BMW",    "Bentley", "Cadillac",   "Chevrolet",
    "Chrysler", "Dodge",         "Ferrari",      "Fiat",       "Ford",   "GMC",     "Honda",      "Hyundai",
    "Infiniti", "Jaguar",        "Jeep",         "Kia",        "Lexus",  "Lincoln", "Lotus",      "Maserati",
    "Mazda",    "Mercedes-Benz", "Mini",         "Mitsubishi", "Nissan", "Peugeot", "Porsche",    "Ram",
    "Renault",  "Rolls-Royce",   "Subaru",       "Suzuki",     "Tesla",  "Toyota",  "Volkswagen", "Volvo",
});

const auto enUSModels = std::to_array<std::string_view>({
    "Accord",
    "CR-V",
    "Camry",
    "Civic",
    "Corolla",
    "Escape",
    "Explorer",
    "F-150",
    "Fiesta",
    "Focus",
    "Mustang",
    "RAV4",
    "Ram 1500",
    "Silverado 1500",
});

const auto enUSVehicles = std::to_array<std::string_view>({
    "Boat",
    "Bus",
    "Car",
    "Minivan",
    "Motorcycle",
    "RV",
    "SUV",
    "Trailer",
    "Truck",
    "Van",
});

const VehicleDefinition enUSVehicleDefinition = {
    .bicycles = enUSBicycles,
    .vehicles = enUSVehicles,
    .models = enUSModels,
    .fuelTypes= enUSFuelTypes,
    .colors = enUSColors,
    .manufacturers = enUSManufacturers,
};

}
