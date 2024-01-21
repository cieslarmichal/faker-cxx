#include "faker-cxx/Book.h"

#include "../../common/FormatHelper.h"
#include "data/Authors.h"
#include "data/Genres.h"
#include "data/Publishers.h"
#include "data/Titles.h"
#include "data/Translators.h"
#include "data/Series.h"
#include "faker-cxx/Helper.h"
#include "faker-cxx/String.h"
#include "faker-cxx/Date.h"
#include "faker-cxx/Number.h"

namespace faker
{
std::string Book::title()
{
    return Helper::arrayElement<std::string>(titles);
}

std::string Book::genre()
{
    return Helper::arrayElement<std::string>(genres);
}

std::string Book::author()
{
    return Helper::arrayElement<std::string>(authors);
}

std::string Book::publisher()
{
    return Helper::arrayElement<std::string>(publishers);
}

std::string Book::isbn()
{
    return FormatHelper::format("{}-{}-{}-{}-{}", String::numeric(3, false), String::numeric(2), String::numeric(2),
                                String::numeric(5), String::numeric(1));
}

std::string Book::releaseYear()
{
	return Date::pastDate(100).substr(0, 10);
}

std::string Book::translator()
{
	return Helper::arrayElement<std::string>(translators);
}

Book::BookFormat Book::format()
{
    return static_cast<Book::BookFormat>(Number::integer(0, 2));
}

int Book::page()
{
	return Number::integer(50, 999);
}

std::string Book::series()
{
	return Helper::arrayElement<std::string>(bookSeries);
}
}
