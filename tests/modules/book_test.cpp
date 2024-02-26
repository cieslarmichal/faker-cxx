#include "../test_helpers.h"
#include <common/string_helper.h>
#include <faker/book.h>
#include <modules/book_data.h>

using namespace faker;

TEST(BookTest, shouldGenerateTitle)
{
    auto bookTitle = book::title();

    FAKER_EXPECT_CONTAINER_CONTAINS(book::data::titles, bookTitle);
}

TEST(BookTest, shouldGenerateGenre)
{
    auto bookGenre = book::genre();

    FAKER_EXPECT_CONTAINER_CONTAINS(book::data::genres, bookGenre);
}

TEST(BookTest, shouldGenerateAuthor)
{
    auto bookAuthor = book::author();

    FAKER_EXPECT_CONTAINER_CONTAINS(book::data::authors, bookAuthor);
}

TEST(BookTest, shouldGeneratePublisher)
{
    auto bookPublisher = book::publisher();

    FAKER_EXPECT_CONTAINER_CONTAINS(book::data::publishers, bookPublisher);
}

TEST(BookTest, shouldGenerateIsbn)
{
    auto bookIsbn = book::isbn();

    auto isbnNumbersGroups = StringHelper::split(bookIsbn, "-");

    ASSERT_EQ(bookIsbn.size(), 17);
    ASSERT_EQ(isbnNumbersGroups[0].size(), 3);
    ASSERT_EQ(isbnNumbersGroups[1].size(), 2);
    ASSERT_EQ(isbnNumbersGroups[2].size(), 2);
    ASSERT_EQ(isbnNumbersGroups[3].size(), 5);
    ASSERT_EQ(isbnNumbersGroups[4].size(), 1);
}

TEST(BookTest, shouldGenerateReleaseYear)
{
    auto releaseYear = book::releaseYear();

    ASSERT_TRUE((releaseYear >= 1940) && (releaseYear <= 2024));
}

TEST(BookTest, shouldGenerateTranslator)
{
    auto bookTranslator = book::translator();

    FAKER_EXPECT_CONTAINER_CONTAINS(book::data::translators, bookTranslator);
}

TEST(BookTest, shouldGenerateFormat)
{
    auto bookFormat = book::format();

    FAKER_EXPECT_CONTAINER_CONTAINS(book::data::bookFormats, bookFormat);
}

TEST(BookTest, shouldGeneratePage)
{
    auto bookPage = book::page();

    ASSERT_TRUE(bookPage >= 50 && bookPage <= 999);
}

TEST(BookTest, shouldGenerateSeries)
{
    auto randomSeries = book::series();

    FAKER_EXPECT_CONTAINER_CONTAINS(book::data::bookSeries, randomSeries);
}
