#include "faker-cxx/book.h"

#include <string_view>

#include "book_data.h"
#include "faker-cxx/helper.h"

namespace faker::book
{
namespace
{
const struct BookDefinition& getBookDefinition(Locale locale)
{
    switch (locale)
    {
    case Locale::pl_PL:
        return plBookDefinition;
    default:
        return enUSBookDefinition;
    }
}
}

std::string_view title(Locale locale)
{
    const auto& bookDefinition = getBookDefinition(locale);

    return helper::randomElement(bookDefinition.titles);
}

std::string_view genre(Locale locale)
{
    const auto& bookDefinition = getBookDefinition(locale);

    return helper::randomElement(bookDefinition.genres);
}

std::string_view author(Locale locale)
{
    const auto& bookDefinition = getBookDefinition(locale);

    return helper::randomElement(bookDefinition.authors);
}

std::string_view publisher(Locale locale)
{
    const auto& bookDefinition = getBookDefinition(locale);

    return helper::randomElement(bookDefinition.publishers);
}

std::string_view format(Locale locale)
{
    const auto& bookDefinition = getBookDefinition(locale);

    return helper::randomElement(bookDefinition.formats);
}

std::string_view series(Locale locale)
{
    const auto& bookDefinition = getBookDefinition(locale);

    return helper::randomElement(bookDefinition.series);
}
}
