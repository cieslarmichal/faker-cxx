#include <iostream>

#include "faker-cxx/person.h"

int main()
{
    const auto personFullName = faker::person::fullName();
    std::cout << "Person full name: " << personFullName << std::endl;

    const auto jobTitle = faker::person::jobTitle();
    std::cout << "Person job title: " << jobTitle << std::endl;

    const auto hobby = faker::person::hobby();
    std::cout << "Person hobby: " << hobby << std::endl;

    const auto language = faker::person::language();
    std::cout << "Person language: " << language << std::endl;

    const auto nationality = faker::person::nationality();
    std::cout << "Person nationality: " << nationality << std::endl;

    const auto chineseZodiac = faker::person::chineseZodiac();
    std::cout << "Person chinese zodiac: " << chineseZodiac << std::endl;

    const auto passport = faker::person::passport();
    std::cout << "Person passport: " << passport << std::endl;

    return 0;
}
