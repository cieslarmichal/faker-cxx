#include "VehicleData.h"

#include <array>
#include <string_view>

namespace faker
{
namespace vehicle
{
const std::array<std::string_view, 10> bicycle_types = {
    "BMX bike",
    "Cargo bike",
    "City bike",
    "Electric bike",
    "Folding bike",
    "Hybrid bike",
    "Mountain bike",
    "Recumbent bike",
    "Road bike",
    "Tandem bike"
};

const std::array<std::string_view, 7> vehicle_colors = {
    "Black",
    "Blue",
    "Gray",
    "Green",
    "Red",
    "Silver",
    "White"
};

const std::array<std::string_view, 10> fuel_types = {
    "Biodiesel",
    "Diesel",
    "Electric",
    "Ethanol",
    "Gasoline",
    "Hybrid",
    "Hydrogen",
    "Methanol",
    "Natural gas",
    "Propane"
};

const std::array<std::string_view, 40> manufacturers = {
    "Acura",
    "Alfa Romeo",
    "Aston Martin",
    "Audi",
    "BMW",
    "Bentley",
    "Cadillac",
    "Chevrolet",
    "Chrysler",
    "Dodge",
    "Ferrari",
    "Fiat",
    "Ford",
    "GMC",
    "Honda",
    "Hyundai",
    "Infiniti",
    "Jaguar",
    "Jeep",
    "Kia",
    "Lexus",
    "Lincoln",
    "Lotus",
    "Maserati",
    "Mazda",
    "Mercedes-Benz",
    "Mini",
    "Mitsubishi",
    "Nissan",
    "Peugeot",
    "Porsche",
    "Ram",
    "Renault",
    "Rolls-Royce",
    "Subaru",
    "Suzuki",
    "Tesla",
    "Toyota",
    "Volkswagen",
    "Volvo"
};

const std::array<std::string_view, 14> models = {
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
    "Silverado 1500"
};

const std::array<std::string_view, 10> vehicle_types = {
    "Boat",
    "Bus",
    "Car",
    "Minivan",
    "Motorcycle",
    "RV",
    "SUV",
    "Trailer",
    "Truck",
    "Van"
};
}
}
