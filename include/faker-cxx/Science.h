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

    Unit(std::string name_, std::string symbol_, std::string usedToMeasure_)
        : name(name_), symbol(symbol_), usedToMeasure(usedToMeasure_)
    {
    }

    bool operator==(const Unit& obj) const
    {
        return (this->name == obj.name && this->symbol == obj.symbol && this->usedToMeasure == obj.usedToMeasure);
    }
};

class Science
{
public:
    /**
     * @brief Returns a random chemical element from the periodic table.
     *
     * @returns ChemicalElement
     *
     * @code
     * Science::chemicalElement() // Object of ChemicalElement containing info about a random element in the periodic table.
     * @endcode
     * 
     */
    static ChemicalElement chemicalElement();
    
    /**
     * @brief Returns a unit of measurement for either distance, mass, time, temp, current.
     *
     * @returns Unit
     *
     * @code
     * Science::unit() // Object of Unit containing info about a random unit of measurement.
     * @endcode
     * 
     */
    static Unit unit();
    
    /**
     * @brief Returns a unit of measurement for either distance.
     *
     * @returns Unit
     *
     * @code
     * Science::distanceUnit() // Object of Unit containing info about a random unit of measurement used to measure distance.
     * @endcode
     * 
     */
    static Unit distanceUnit();
    
    /**
     * @brief Returns a unit of measurement for either time.
     *
     * @returns Unit
     *
     * @code
     * Science::timeUnit() // Object of Unit containing info about a random unit of measurement used to measure time.
     * @endcode
     * 
     */
    static Unit timeUnit();

    /**
     * @brief Returns a unit of measurement for either mass.
     *
     * @returns Unit
     *
     * @code
     * Science::massUnit() // Object of Unit containing info about a random unit of measurement used to measure mass.
     * @endcode
     * 
     */
    static Unit massUnit();

    /**
     * @brief Returns a unit of measurement for either temp.
     *
     * @returns Unit
     *
     * @code
     * Science::tempUnit() // Object of Unit containing info about a random unit of measurement used to measure temp.
     * @endcode
     * 
     */
    static Unit tempUnit();
    
    /**
     * @brief Returns a unit of measurement for either current.
     *
     * @returns Unit
     *
     * @code
     * Science::currentUnit() // Object of Unit containing info about a random unit of measurement used to measure current.
     * @endcode
     * 
     */
    static Unit currentUnit();

};

}