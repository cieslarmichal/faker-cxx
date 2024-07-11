#include "faker-cxx/book.h"

#include <algorithm>
#include <string_view>

#include "gtest/gtest.h"

#include "book/book_data.h"

using namespace ::testing;
using namespace faker::book;

class BookTest : public Test
{
public:
};

TEST_F(BookTest, shouldGenerateTitle)
{
    const auto bookTitle = title();

    ASSERT_TRUE(std::ranges::any_of(titles, [bookTitle](const std::string_view& title) { return title == bookTitle; }));
}

TEST_F(BookTest, shouldGenerateGenre)
{
    const auto bookGenre = genre();

    ASSERT_TRUE(
        std::ranges::any_of(bookGenres, [bookGenre](const std::string_view& genre) { return genre == bookGenre; }));
}

TEST_F(BookTest, shouldGenerateAuthor)
{
    const auto bookAuthor = author();

    ASSERT_TRUE(
        std::ranges::any_of(authors, [bookAuthor](const std::string_view& author) { return author == bookAuthor; }));
}

TEST_F(BookTest, shouldGeneratePublisher)
{
    const auto bookPublisher = publisher();

    ASSERT_TRUE(std::ranges::any_of(publishers, [bookPublisher](const std::string_view& publisher)
                                    { return publisher == bookPublisher; }));
}

TEST_F(BookTest, shouldGenerateFormat)
{
    const auto bookFormat = format();

    ASSERT_TRUE(std::ranges::any_of(bookFormats,
                                    [bookFormat](const std::string_view& format) { return format == bookFormat; }));
}

TEST_F(BookTest, shouldGenerateSeries)
{
    const auto randomSeries = series();

    ASSERT_TRUE(std::ranges::any_of(bookSeries,
                                    [randomSeries](const std::string_view& series) { return series == randomSeries; }));
}
