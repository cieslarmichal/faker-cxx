#include "vehicle_data.h"

namespace faker::vehicle::data {
const std::array<std::string_view, 10> bicycle_types
    = { "Road bike", "Mountain bike", "Hybrid bike", "City bike", "BMX bike", "Folding bike",
          "Recumbent bike", "Tandem bike", "Electric bike", "Cargo bike" };

const std::array<std::string_view, 7> vehicle_colors = {
    "Black",
    "White",
    "Gray",
    "Silver",
    "Red",
    "Blue",
    "Green",
};

const std::array<std::string_view, 10> fuel_types = { "Gasoline", "Diesel", "Electric", "Hybrid",
    "Hydrogen", "Propane", "Natural gas", "Biodiesel", "Ethanol", "Methanol" };

const std::array<std::string_view, 40> manufacturers { "Acura", "Alfa Romeo", "Aston Martin", "Audi",
    "Bentley", "BMW", "Cadillac", "Chevrolet", "Chrysler", "Dodge", "Ferrari", "Fiat", "Ford",
    "GMC", "Honda", "Hyundai", "Infiniti", "Jaguar", "Jeep", "Kia", "Lexus", "Lincoln", "Lotus",
    "Maserati", "Mazda", "Mercedes-Benz", "Mini", "Mitsubishi", "Nissan", "Peugeot", "Porsche",
    "Ram", "Renault", "Rolls-Royce", "Subaru", "Suzuki", "Tesla", "Toyota", "Volkswagen", "Volvo" };

const std::array<std::string_view, 14> models = {
    "Fiesta",
    "Focus",
    "Mustang",
    "Escape",
    "Explorer",
    "F-150",
    "Ram 1500",
    "Silverado 1500",
    "Corolla",
    "Camry",
    "Accord",
    "Civic",
    "CR-V",
    "RAV4",
};

const std::array<std::string_view, 10> vehicle_types
    = { "Car", "Truck", "SUV", "Motorcycle", "Bus", "Van", "Minivan", "RV", "Trailer", "Boat" };

}
