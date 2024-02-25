#include "../common/format_helper.h"
#include "book_data.h"
#include <faker/book.h>
#include <faker/date.h>
#include <faker/helper.h>
#include <faker/number.h>
#include <faker/string.h>

namespace faker::book {
std::string_view title() { return Helper::arrayElement(books::titles); }

std::string_view genre() { return Helper::arrayElement(books::genres); }

std::string_view author() { return Helper::arrayElement(books::authors); }

std::string_view publisher() { return Helper::arrayElement(books::publishers); }

std::string isbn()
{
    return FormatHelper::format("{}-{}-{}-{}-{}", string::numeric(3, false), string::numeric(2),
        string::numeric(2), string::numeric(5), string::numeric(1));
}

int releaseYear() { return number::integer(1940, 2024); }

std::string_view translator() { return Helper::arrayElement(books::translators); }

std::string_view format() { return Helper::arrayElement(books::bookFormats); }

int page() { return number::integer(50, 999); }

std::string_view series() { return Helper::arrayElement(books::bookSeries); }
}
