#pragma once

#include <iostream>
#include <optional>
#include <string>

namespace faker
{

class ChemicalElement
{
public:
    std::string name;
    std::string symbol;
    int atomic_number;

    ChemicalElement() = default;

    ChemicalElement(std::string name_, std::string symbol_, int atomic_number_)
        : name(name_), symbol(symbol_), atomic_number(atomic_number_)
    {
    }

    ChemicalElement(std::string info) : name(""), symbol(""), atomic_number(-1)
    {

        auto idx1 = info.find_first_of('-');
        auto idx2 = info.find_last_of('-');

        std::string name_ = info.substr(0, idx1 - 1);
        std::string symbol_ = info.substr(idx1 + 2, idx2 - idx1 - 3);
        std::string atomic_number = info.substr(idx2 + 2, info.length() - idx2 - 2);
    }

    ~ChemicalElement() = default;

    bool operator==(const ChemicalElement& obj) const
    {
        return (this->name == obj.name && this->symbol == obj.symbol && this->atomic_number == obj.atomic_number);
    }
};

class Unit
{
public:
    std::string name;
    std::string symbol;
    std::string usedToMeasure;

    Unit(std::string name_, std::string symbol_, std::string usedToMeasure_) : name(name_), symbol(symbol_) {}

    bool operator==(const Unit& obj) const
    {
        return (this->name == obj.name && this->symbol == obj.symbol && this->usedToMeasure == obj.usedToMeasure);
    }
};

class Science
{
public:
    static ChemicalElement chemicalElement();
    static Unit unit();
    static Unit distanceUnit();
    static Unit timeUnit();
    static Unit massUnit();
    static Unit tempUnit();
    static Unit currentUnit();

};

}