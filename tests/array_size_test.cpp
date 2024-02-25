#include "test_helpers.h"
#include <iostream>
#include <modules/movie_data.h>

using namespace faker::movie;

#define PRINT_ARRAY_SIZE(name)                                                                     \
    std::cout << "extern const std::array<std::string_view, " << name.size() << "> " << (#name)    \
              << ";" << std::endl

TEST(BasicTest, printsArraySizes)
{
    PRINT_ARRAY_SIZE(actors);
    PRINT_ARRAY_SIZE(actresses);
    PRINT_ARRAY_SIZE(directors);
    PRINT_ARRAY_SIZE(genres);
    PRINT_ARRAY_SIZE(movies);
    PRINT_ARRAY_SIZE(tvShows);
}
