#include <cstdlib>
#include <iostream>

#include "faker-cxx/Person.h"

int main() {
    const auto personFullName = faker::Person::fullName();
    std::cout << "Person full name: " << personFullName << std::endl;

    const auto jobTitle = faker::Person::jobTitle();
    std::cout << "Person job title: " << jobTitle << std::endl;

    const auto hobby = faker::Person::hobby();
    std::cout << "Person hobby: " << hobby << std::endl;

    const auto language = faker::Person::language();
    std::cout << "Person language: " << language << std::endl;

    const auto nationality = faker::Person::nationality();
    std::cout << "Person nationality: " << nationality << std::endl;

    const auto chineseZodiac = faker::Person::chineseZodiac();
    std::cout << "Person chinese zodiac: " << chineseZodiac << std::endl;

    const auto passport = faker::Person::passport();
    std::cout << "Person passport: " << passport << std::endl;

    return EXIT_SUCCESS;
}