#include "../include/faker-cxx/Structure.h"

#include <vector>

namespace faker
{

std::string faker::Sructure::json(const std::map<std::string, faker::Token> items)
{
    std::string result = "{";

    for (auto it = items.begin(); it != items.end(); ++it)
    {
        auto func = moduleFunctions.find(it->second)->second;
        result.append("\"" + it->first + "\":\"" + func() + "\"");

        
        if (std::next(it) != items.end())
        {
            result.append(",");
        }
    }

    result.append("}");
    return result;
}
std::string faker::Sructure::csv(const std::map<std::string, faker::Token> items, const unsigned int rows)
{
    std::string result = "";
    std::vector<std::function<std::string()>> funcs;
    for (auto it = items.begin(); it != items.end(); ++it)
    {
        result.append(it->first);
        funcs.push_back(moduleFunctions.find(it->second)->second);
        if (std::next(it) != items.end())
        {
            result.append(",");
        }
    }
    result.append("\n");
    std::size_t n = funcs.size();
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < n; ++j)
        {
            result.append(funcs[j]());
            if (j != n - 1)
            {
                result.append(",");
            }
        }
        result.append("\n");
    }

    return result;
}
}