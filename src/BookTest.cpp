#include "include/faker-cxx/Book.h"

#include "gtest/gtest.h"

#include "data/book/Authors.h"
#include "data/book/Genres.h"
#include "data/book/Publishers.h"
#include "data/book/Titles.h"
#include "StringHelper.h"
#include <algorithm>

using namespace ::testing;
using namespace faker;

class BookTest : public Test
{
public:
};

TEST_F(BookTest, shouldGenerateTitle)
{
    const auto bookTitle = Book::title();

    ASSERT_TRUE(std::any_of(titles.begin(), titles.end(),
                            [bookTitle](const std::string& title) { return title == bookTitle; }));
}

TEST_F(BookTest, shouldGenerateGenre)
{
    const auto bookGenre = Book::genre();

    ASSERT_TRUE(std::any_of(genres.begin(), genres.end(),
                            [bookGenre](const std::string& genre) { return genre == bookGenre; }));
}

TEST_F(BookTest, shouldGenerateAuthor)
{
    const auto bookAuthor = Book::author();

    ASSERT_TRUE(std::any_of(authors.begin(), authors.end(),
                            [bookAuthor](const std::string& author) { return author == bookAuthor; }));
}

TEST_F(BookTest, shouldGeneratePublisher)
{
    const auto bookPublisher = Book::publisher();

    ASSERT_TRUE(std::any_of(publishers.begin(), publishers.end(),
                            [bookPublisher](const std::string& publisher) { return publisher == bookPublisher; }));
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
