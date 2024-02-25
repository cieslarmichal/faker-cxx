#include "../test_helpers.h"
#include <algorithm>
#include <common/string_helper.h>
#include <faker/book.h>
#include <modules/book_data.h>

using namespace faker;
using namespace faker::books;

class BookTest : public ::testing::Test {
public:
};

TEST_F(BookTest, shouldGenerateTitle)
{
    const auto bookTitle = book::title();

    ASSERT_TRUE(faker::testing::contains(titles, bookTitle));
}

TEST_F(BookTest, shouldGenerateGenre)
{
    const auto bookGenre = book::genre();

    ASSERT_TRUE(faker::testing::contains(genres, bookGenre));
}

TEST_F(BookTest, shouldGenerateAuthor)
{
    const auto bookAuthor = book::author();

    ASSERT_TRUE(faker::testing::contains(authors, bookAuthor));
}

TEST_F(BookTest, shouldGeneratePublisher)
{
    const auto bookPublisher = book::publisher();

    ASSERT_TRUE(faker::testing::contains(publishers, bookPublisher));
}

TEST_F(BookTest, shouldGenerateIsbn)
{
    const auto bookIsbn = book::isbn();

    const auto isbnNumbersGroups = StringHelper::split(bookIsbn, "-");

    ASSERT_EQ(bookIsbn.size(), 17);
    ASSERT_EQ(isbnNumbersGroups[0].size(), 3);
    ASSERT_EQ(isbnNumbersGroups[1].size(), 2);
    ASSERT_EQ(isbnNumbersGroups[2].size(), 2);
    ASSERT_EQ(isbnNumbersGroups[3].size(), 5);
    ASSERT_EQ(isbnNumbersGroups[4].size(), 1);
}

TEST_F(BookTest, shouldGenerateReleaseYear)
{
    const auto releaseYear = book::releaseYear();

    ASSERT_TRUE((releaseYear >= 1940) && (releaseYear <= 2024));
}

TEST_F(BookTest, shouldGenerateTranslator)
{
    const auto bookTranslator = book::translator();

    ASSERT_TRUE(faker::testing::contains(translators, bookTranslator));
}

TEST_F(BookTest, shouldGenerateFormat)
{
    const auto bookFormat = book::format();

    ASSERT_TRUE(faker::testing::contains(bookFormats, bookFormat));
}

TEST_F(BookTest, shouldGeneratePage)
{
    const auto bookPage = book::page();

    ASSERT_TRUE(bookPage >= 50 && bookPage <= 999);
}

TEST_F(BookTest, shouldGenerateSeries)
{
    const auto randomSeries = book::series();

    ASSERT_TRUE(faker::testing::contains(bookSeries, randomSeries));
}
