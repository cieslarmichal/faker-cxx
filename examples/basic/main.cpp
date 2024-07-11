#include <iostream>

#include "faker-cxx/faker.h"

int main()
{
    const auto id = faker::string::uuid();
    const auto email = faker::internet::email();
    const auto password = faker::internet::password();
    const auto city = faker::location::city();
    const auto streetAddress = faker::location::streetAddress();
    const auto bornDate = faker::date::birthdateByYear(1970, 2000);

    std::cout << id << std::endl;
    std::cout << email << std::endl;
    std::cout << password << std::endl;
    std::cout << city << std::endl;
    std::cout << streetAddress << std::endl;
    std::cout << bornDate << std::endl;

    return 0;
}
