#include "test_helpers.h"
#include <iostream>
#include <modules/music_data.h>

using namespace faker::music::data;

#define PRINT_ARRAY_SIZE(name)                                                                     \
    std::cout << "extern const std::array<std::string_view, " << name.size() << "> " << (#name)    \
              << ";" << std::endl

TEST(BasicTest, printsArraySizes)
{
    PRINT_ARRAY_SIZE(artists);
    PRINT_ARRAY_SIZE(genres);
    PRINT_ARRAY_SIZE(songNames);
}
