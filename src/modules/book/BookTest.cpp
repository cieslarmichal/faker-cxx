#include "faker-cxx/Book.h"

#include <algorithm>

#include "gtest/gtest.h"

#include "../../common/StringHelper.h"
#include "data/Authors.h"
#include "data/Genres.h"
#include "data/Publishers.h"
#include "data/Titles.h"

using namespace ::testing;
using namespace faker;

class BookTest : public Test
{
public:
};

TEST_F(BookTest, shouldGenerateTitle)
{
    const auto bookTitle = Book::title();

    ASSERT_TRUE(std::ranges::any_of(titles, [bookTitle](const std::string& title) { return title == bookTitle; }));
}

TEST_F(BookTest, shouldGenerateGenre)
{
    const auto bookGenre = Book::genre();

    ASSERT_TRUE(std::ranges::any_of(genres, [bookGenre](const std::string& genre) { return genre == bookGenre; }));
}

TEST_F(BookTest, shouldGenerateAuthor)
{
    const auto bookAuthor = Book::author();

    ASSERT_TRUE(std::ranges::any_of(authors, [bookAuthor](const std::string& author) { return author == bookAuthor; }));
}

TEST_F(BookTest, shouldGeneratePublisher)
{
    const auto bookPublisher = Book::publisher();

    ASSERT_TRUE(std::ranges::any_of(publishers, [bookPublisher](const std::string& publisher)
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
