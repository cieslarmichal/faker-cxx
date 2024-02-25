#include "test_helpers.h"
#include <iostream>
#include <modules/vehicle_data.h>

using namespace faker::vehicle::data;

#define PRINT_ARRAY_SIZE(name)                                                                     \
    std::cout << "extern const std::array<std::string_view, " << name.size() << "> " << (#name)    \
              << ";" << std::endl

TEST(BasicTest, printsArraySizes)
{
    PRINT_ARRAY_SIZE(bicycle_types);
    PRINT_ARRAY_SIZE(vehicle_colors);
    PRINT_ARRAY_SIZE(fuel_types);
    PRINT_ARRAY_SIZE(manufacturers);
    PRINT_ARRAY_SIZE(models);
    PRINT_ARRAY_SIZE(vehicle_types);
}
