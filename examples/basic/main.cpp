#include <cstdlib>
#include <iostream>

#include "faker-cxx/Date.h"
#include "faker-cxx/Internet.h"
#include "faker-cxx/Location.h"
#include "faker-cxx/String.h"

int main()
{
    const auto id = faker::String::uuid();
    const auto email = faker::Internet::email();
    const auto password = faker::Internet::password();
    const auto city = faker::Location::city();
    const auto streetAddress = faker::Location::streetAddress();

    std::cout << id << std::endl;
    std::cout << email << std::endl;
    std::cout << password << std::endl;
    std::cout << city << std::endl;
    std::cout << streetAddress << std::endl;

    return EXIT_SUCCESS;
}