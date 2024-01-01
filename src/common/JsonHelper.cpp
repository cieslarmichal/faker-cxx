#include "JsonHelper.h"

namespace faker
{

std::map<std::string, std::string> JsonHelper::simpleJsonParser(std::string json)
{
    std::map<std::string, std::string> result;
    std::istringstream stream(json);
    std::string key, value, temp;
    char ch;

    while (stream >> ch && ch != '}')
    {
        if (ch == '"')
        {

            std::getline(stream, key, '"');
            std::getline(stream, temp, ':');

            stream >> ch;
            std::getline(stream, value, '"');

            result[key] = value;
        }
    }

    return result;
}
}