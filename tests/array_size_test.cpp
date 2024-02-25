#include "test_helpers.h"
#include <iostream>
#include <modules/location_data.h>

using namespace faker::location::data;

#define PRINT_ARRAY_SIZE(name)                                                                     \
    std::cout << "extern const std::array<std::string_view, " << name.size() << "> " << (#name)    \
              << ";" << std::endl

TEST(BasicTest, printsArraySizes)
{
    // PRINT_ARRAY_SIZE(australiaCities);
    // PRINT_ARRAY_SIZE(australiaStates);
    // PRINT_ARRAY_SIZE(australiaStreetSuffixes);
    // PRINT_ARRAY_SIZE(australiaAddressFormats);
    // PRINT_ARRAY_SIZE(australiaBuildingNumberFormats);

    // PRINT_ARRAY_SIZE(australiaSuburbs);
    // PRINT_ARRAY_SIZE(australiaStreets);
    // PRINT_ARRAY_SIZE(australiaPostcodes);
    // PRINT_ARRAY_SIZE(australiaStreetSuffixes);
}
