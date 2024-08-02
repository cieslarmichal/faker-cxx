#include "faker-cxx/book.h"

#include <string_view>

#include "book_data.h"
#include "faker-cxx/helper.h"

namespace faker::book
{
std::string_view title()
{
    return helper::randomElement(titles);
}

std::string_view genre()
{
    return helper::randomElement(bookGenres);
}

std::string_view author()
{
    return helper::randomElement(authors);
}

std::string_view publisher()
{
    return helper::randomElement(publishers);
}

std::string_view format()
{
    return helper::randomElement(bookFormats);
}

std::string_view series()
{
    return helper::randomElement(bookSeries);
}
}
