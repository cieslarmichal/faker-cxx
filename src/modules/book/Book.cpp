#include "faker-cxx/Book.h"

#include <string_view>

#include "BookData.h"
#include "faker-cxx/Helper.h"

namespace faker::book
{
std::string_view title()
{
    return Helper::arrayElement(titles);
}

std::string_view genre()
{
    return Helper::arrayElement(bookGenres);
}

std::string_view author()
{
    return Helper::arrayElement(authors);
}

std::string_view publisher()
{
    return Helper::arrayElement(publishers);
}

std::string_view format()
{
    return Helper::arrayElement(bookFormats);
}

std::string_view series()
{
    return Helper::arrayElement(bookSeries);
}
}
