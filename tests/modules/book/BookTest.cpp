#include "faker-cxx/Book.h"

#include <algorithm>
#include <string_view>

#include "gtest/gtest.h"

#include "book/BookData.h"
#include "common/StringHelper.h"

using namespace ::testing;
using namespace faker;

class BookTest : public Test
{
public:
};

TEST_F(BookTest, shouldGenerateTitle)
{
    const auto bookTitle = Book::title();

    ASSERT_TRUE(std::ranges::any_of(titles, [bookTitle](const std::string_view& title) { return title == bookTitle; }));
}

TEST_F(BookTest, shouldGenerateGenre)
{
    const auto bookGenre = Book::genre();

    ASSERT_TRUE(std::ranges::any_of(bookGenres, [bookGenre](const std::string_view& genre) { return genre == bookGenre; }));
}

TEST_F(BookTest, shouldGenerateAuthor)
{
    const auto bookAuthor = Book::author();

    ASSERT_TRUE(
        std::ranges::any_of(authors, [bookAuthor](const std::string_view& author) { return author == bookAuthor; }));
}

TEST_F(BookTest, shouldGeneratePublisher)
{
    const auto bookPublisher = Book::publisher();

    ASSERT_TRUE(std::ranges::any_of(publishers, [bookPublisher](const std::string_view& publisher)
                                    { return publisher == bookPublisher; }));
}

TEST_F(BookTest, shouldGenerateIsbn)
{
    const auto bookIsbn = Book::isbn();

    const auto isbnNumbersGroups = StringHelper::split(bookIsbn, "-");

    ASSERT_EQ(bookIsbn.size(), 17);
    ASSERT_EQ(isbnNumbersGroups[0].size(), 3);
    ASSERT_EQ(isbnNumbersGroups[1].size(), 2);
    ASSERT_EQ(isbnNumbersGroups[2].size(), 2);
    ASSERT_EQ(isbnNumbersGroups[3].size(), 5);
    ASSERT_EQ(isbnNumbersGroups[4].size(), 1);
}

TEST_F(BookTest, shouldGenerateTranslator)
{
    const auto bookTranslator = Book::translator();

    ASSERT_TRUE(std::ranges::any_of(translators, [bookTranslator](const std::string_view& translator)
                                    { return translator == bookTranslator; }));
}

TEST_F(BookTest, shouldGenerateFormat)
{
    const auto bookFormat = Book::format();

    ASSERT_TRUE(std::ranges::any_of(bookFormats,
                                    [bookFormat](const std::string_view& format) { return format == bookFormat; }));
}

TEST_F(BookTest, shouldGenerateSeries)
{
    const auto randomSeries = Book::series();

    ASSERT_TRUE(std::ranges::any_of(bookSeries,
                                    [randomSeries](const std::string_view& series) { return series == randomSeries; }));
}
