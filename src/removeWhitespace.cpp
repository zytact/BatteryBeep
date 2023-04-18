#include "removeWhitespace.h"

std::string removeWhitespace(std::string str)

{
    std::string result;

    for (char c : str)
    {
        if (!std::isspace(c))
        {
            result += c;
        }
    }

    return result;
}
