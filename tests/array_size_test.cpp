#include "test_helpers.h"
#include <iostream>
#include <modules/person_data.h>

using namespace faker::person::data;

#define PRINT_ARRAY_SIZE(name)                                                                     \
    std::cout << "extern const std::array<std::string_view, " << name.size() << "> " << (#name)    \
              << ";" << std::endl

TEST(BasicTest, printsArraySizes)
{
    PRINT_ARRAY_SIZE(westernZodiacs);
    PRINT_ARRAY_SIZE(chineseZodiacs);

    PRINT_ARRAY_SIZE(albanianMalesFirstNames);
    PRINT_ARRAY_SIZE(albanianFemalesFirstNames);
    PRINT_ARRAY_SIZE(albanianLastNames);

    PRINT_ARRAY_SIZE(argentinianMalesFirstNames);
    PRINT_ARRAY_SIZE(argentinianFemalesFirstNames);
    PRINT_ARRAY_SIZE(argentinianLastNames);

    PRINT_ARRAY_SIZE(australianMalesFirstNames);
    PRINT_ARRAY_SIZE(australianFemalesFirstNames);
    PRINT_ARRAY_SIZE(australianLastNames);

    PRINT_ARRAY_SIZE(austrianMalesFirstNames);
    PRINT_ARRAY_SIZE(austrianFemalesFirstNames);
    PRINT_ARRAY_SIZE(austrianLastNames);
    PRINT_ARRAY_SIZE(austrianMalesPrefixes);
    PRINT_ARRAY_SIZE(austrianFemalesPrefixes);

    PRINT_ARRAY_SIZE(azerbaijaniMalesFirstNames);
    PRINT_ARRAY_SIZE(azerbaijaniFemalesFirstNames);
    PRINT_ARRAY_SIZE(azerbaijaniMalesLastNames);
    PRINT_ARRAY_SIZE(azerbaijaniFemalesLastNames);

    PRINT_ARRAY_SIZE(belarusianMalesFirstNames);
    PRINT_ARRAY_SIZE(belarusianFemalesFirstNames);
    PRINT_ARRAY_SIZE(belarusianMalesLastNames);
    PRINT_ARRAY_SIZE(belarusianFemalesLastNames);

    PRINT_ARRAY_SIZE(belgianMalesFirstNames);
    PRINT_ARRAY_SIZE(belgianFemalesFirstNames);
    PRINT_ARRAY_SIZE(belgianLastNames);
    PRINT_ARRAY_SIZE(belgianSuffixes);
    PRINT_ARRAY_SIZE(belgianPrefixes);
}
