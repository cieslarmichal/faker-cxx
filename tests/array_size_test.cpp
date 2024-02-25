#include "test_helpers.h"
#include <iostream>
#include <modules/system_data.h>

using namespace faker::system::data;

#define PRINT_ARRAY_SIZE(name)                                                                     \
    std::cout << "extern const std::array<std::string_view, " << name.size() << "> " << (#name)    \
              << ";" << std::endl

TEST(BasicTest, printsArraySizes)
{
    PRINT_ARRAY_SIZE(commonInterfaceTypes);
    PRINT_ARRAY_SIZE(cronDayOfWeek);
    PRINT_ARRAY_SIZE(directoryPaths);
    PRINT_ARRAY_SIZE(mimeTypes);
    PRINT_ARRAY_SIZE(commonMimeTypes);
    PRINT_ARRAY_SIZE(commonFileTypes);
}
