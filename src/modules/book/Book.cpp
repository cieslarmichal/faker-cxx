#include "faker-cxx/Book.h"

#include <string_view>

#include "BookData.h"
#include "faker-cxx/Helper.h"

namespace faker::book
{
std::string_view title()
{
    return helper::arrayElement(titles);
}

std::string_view genre()
{
    return helper::arrayElement(bookGenres);
}

std::string_view author()
{
    return helper::arrayElement(authors);
}

std::string_view publisher()
{
    return helper::arrayElement(publishers);
}

std::string_view format()
{
    return helper::arrayElement(bookFormats);
}

std::string_view series()
{
    return helper::arrayElement(bookSeries);
}
}
