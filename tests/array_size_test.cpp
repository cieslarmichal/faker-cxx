#include "test_helpers.h"
#include <iostream>
#include <modules/phone_data.h>

using namespace faker::phone::data;

#define PRINT_ARRAY_SIZE(name)                                                                     \
    std::cout << "extern const std::array<std::string_view, " << name.size() << "> " << (#name)    \
              << ";" << std::endl

TEST(BasicTest, printsArraySizes)
{
    PRINT_ARRAY_SIZE(platforms);
    PRINT_ARRAY_SIZE(model_names);
    PRINT_ARRAY_SIZE(manufacturers);
    PRINT_ARRAY_SIZE(number_formats);
}
