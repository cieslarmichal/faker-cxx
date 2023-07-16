#include "include/faker-cxx/Book.h"

#include "data/book/Authors.h"
#include "data/book/Genres.h"
#include "data/book/Publishers.h"
#include "data/book/Titles.h"
#include "include/faker-cxx/Helper.h"
#include "include/faker-cxx/String.h"

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
    return std::format("{}-{}-{}-{}-{}", String::numeric(3, false), String::numeric(2), String::numeric(2),
                       String::numeric(5), String::numeric(1));
}
}
