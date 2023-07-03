#pragma once

#include <string>

namespace faker::person
{
class PersonDataGenerator
{
public:
    static std::string firstName();
    static std::string lastName();
};
}
