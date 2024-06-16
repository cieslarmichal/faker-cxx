#include "faker-cxx/Book.h"

#include <string_view>

#include "BookData.h"
#include "faker-cxx/Helper.h"

namespace faker
{
std::string_view Book::title()
{
    return Helper::arrayElement(titles);
}

std::string_view Book::genre()
{
    return Helper::arrayElement(bookGenres);
}

std::string_view Book::author()
{
    return Helper::arrayElement(authors);
}

std::string_view Book::publisher()
{
    return Helper::arrayElement(publishers);
}

std::string_view Book::format()
{
    return Helper::arrayElement(bookFormats);
}

std::string_view Book::series()
{
    return Helper::arrayElement(bookSeries);
}
}
