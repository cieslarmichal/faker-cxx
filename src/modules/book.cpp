#include "../common/format_helper.h"
#include "../common/helper.h"
#include "book_data.h"
#include <faker/book.h>
#include <faker/date.h>
#include <faker/number.h>
#include <faker/string.h>

namespace faker::book {
std::string_view title() { return Helper::arrayElement(data::titles); }

std::string_view genre() { return Helper::arrayElement(data::genres); }

std::string_view author() { return Helper::arrayElement(data::authors); }

std::string_view publisher() { return Helper::arrayElement(data::publishers); }

std::string isbn()
{
    return FormatHelper::format("{}-{}-{}-{}-{}", string::numeric(3, false), string::numeric(2),
        string::numeric(2), string::numeric(5), string::numeric(1));
}

int releaseYear() { return number::integer(1940, 2024); }

std::string_view translator() { return Helper::arrayElement(data::translators); }

std::string_view format() { return Helper::arrayElement(data::bookFormats); }

int page() { return number::integer(50, 999); }

std::string_view series() { return Helper::arrayElement(data::bookSeries); }
}
