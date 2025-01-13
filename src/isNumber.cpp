#include "isNumber.hpp"

bool isNumber(string input)
{
    for (int i = 0; i < input.size(); i++)
    {
        if (isdigit(input[i]))
            continue;
        else
            return false;
    }
    return true;
}
