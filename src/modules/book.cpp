#include "../common/formatter.h"
#include "../common/random.h"
#include "book_data.h"
#include <faker/book.h>
#include <faker/date.h>
#include <faker/number.h>
#include <faker/string.h>

namespace faker::book {
std::string_view title() { return random::element(data::titles); }

std::string_view genre() { return random::element(data::genres); }

std::string_view author() { return random::element(data::authors); }

std::string_view publisher() { return random::element(data::publishers); }

std::string isbn()
{
    return utils::format("{}-{}-{}-{}-{}", string::numeric(3, false), string::numeric(2),
        string::numeric(2), string::numeric(5), string::numeric(1));
}

unsigned release_year() { return number::integer(1940U, 2024U); }

std::string_view translator() { return random::element(data::translators); }

std::string_view format() { return random::element(data::book_formats); }

unsigned page() { return number::integer(50U, 999U); }

std::string_view series() { return random::element(data::book_series); }
}
