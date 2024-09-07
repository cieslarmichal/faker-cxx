#include <algorithm>
#include <string_view>

#include "gtest/gtest.h"

#include "book_data.h"
#include "faker-cxx/book.h"

using namespace ::testing;
using namespace faker;
using namespace faker::book;

namespace
{
const struct BookDefinition& getBookDefinition(Locale locale)
{
    switch (locale)
    {
    case Locale::pl_PL:
        return plBookDefinition;
    default:
        return enUSBookDefinition;
    }
}
}

class BookTest : public TestWithParam<Locale>
{
public:
};

TEST_P(BookTest, shouldGenerateTitle)
{
    const auto locale = GetParam();

    const auto& bookDefinition = getBookDefinition(locale);

    const auto bookTitle = title(locale);

    ASSERT_TRUE(std::ranges::any_of(bookDefinition.titles,
                                    [bookTitle](const std::string_view& title) { return title == bookTitle; }));
}

TEST_P(BookTest, shouldGenerateGenre)
{
    const auto locale = GetParam();

    const auto& bookDefinition = getBookDefinition(locale);

    const auto bookGenre = genre(locale);

    ASSERT_TRUE(std::ranges::any_of(bookDefinition.genres,
                                    [bookGenre](const std::string_view& genre) { return genre == bookGenre; }));
}

TEST_P(BookTest, shouldGenerateAuthor)
{
    const auto locale = GetParam();

    const auto& bookDefinition = getBookDefinition(locale);

    const auto bookAuthor = author(locale);

    ASSERT_TRUE(std::ranges::any_of(bookDefinition.authors,
                                    [bookAuthor](const std::string_view& author) { return author == bookAuthor; }));
}

TEST_P(BookTest, shouldGeneratePublisher)
{
    const auto locale = GetParam();

    const auto& bookDefinition = getBookDefinition(locale);

    const auto bookPublisher = publisher(locale);

    ASSERT_TRUE(std::ranges::any_of(bookDefinition.publishers, [bookPublisher](const std::string_view& publisher)
                                    { return publisher == bookPublisher; }));
}

TEST_P(BookTest, shouldGenerateFormat)
{
    const auto locale = GetParam();

    const auto& bookDefinition = getBookDefinition(locale);

    const auto bookFormat = format(locale);

    ASSERT_TRUE(std::ranges::any_of(bookDefinition.formats,
                                    [bookFormat](const std::string_view& format) { return format == bookFormat; }));
}

TEST_P(BookTest, shouldGenerateSeries)
{
    const auto locale = GetParam();

    const auto& bookDefinition = getBookDefinition(locale);

    const auto randomSeries = series(locale);

    ASSERT_TRUE(std::ranges::any_of(bookDefinition.series,
                                    [randomSeries](const std::string_view& series) { return series == randomSeries; }));
}

INSTANTIATE_TEST_SUITE_P(TestBookByLocale, BookTest, ValuesIn(locales),
                         [](const TestParamInfo<Locale>& paramInfo) { return toString(paramInfo.param); });
