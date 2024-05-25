#include "faker-cxx/Book.h"

#include "../../common/FormatHelper.h"
#include "BookData.h"
#include "faker-cxx/Helper.h"
#include "faker-cxx/Number.h"
#include "faker-cxx/String.h"

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

std::string Book::isbn()
{
    return FormatHelper::format("{}-{}-{}-{}-{}", String::numeric(3, false), String::numeric(2), String::numeric(2),
                                String::numeric(5), String::numeric(1));
}

std::string_view Book::translator()
{
    return Helper::arrayElement(translators);
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
