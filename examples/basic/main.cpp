#include <cstdlib>
#include <iostream>

#include "faker-cxx/Internet.h"
#include "faker-cxx/Location.h"
#include "faker-cxx/String.h"

int main()
{
    const auto id = faker::string::uuid();
    const auto email = faker::internet::email();
    const auto password = faker::internet::password();
    const auto city = faker::location::city();
    const auto streetAddress = faker::location::streetAddress();

    std::cout << id << std::endl;
    std::cout << email << std::endl;
    std::cout << password << std::endl;
    std::cout << city << std::endl;
    std::cout << streetAddress << std::endl;

    return EXIT_SUCCESS;
}
