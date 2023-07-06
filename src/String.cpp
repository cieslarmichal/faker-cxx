#include "String.h"

#include <random>
#include <sstream>

namespace faker
{
std::string String::uuid()
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<> dist(0, 15);
    static std::uniform_int_distribution<> dist2(8, 11);

    std::stringstream ss;
    ss << std::hex;

    for (int i = 0; i < 8; i++)
    {
        ss << dist(gen);
    }

    ss << "-";
    for (int i = 0; i < 4; i++)
    {
        ss << dist(gen);
    }

    ss << "-4";
    for (int i = 0; i < 3; i++)
    {
        ss << dist(gen);
    }

    ss << "-";

    ss << dist2(gen);

    for (int i = 0; i < 3; i++)
    {
        ss << dist(gen);
    }

    ss << "-";

    for (int i = 0; i < 12; i++)
    {
        ss << dist(gen);
    };

    return ss.str();
}
}
