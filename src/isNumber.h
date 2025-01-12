
#ifndef IS_NUMBER_H // Functions.h include guard
#define IS_NUMBER_H

#include "assignment.h"

/**
 * Check if a string is only composed of numbers or not.
 */
bool isNumber(string input)
{
    for (int i = 0; i < strlen(input.c_str()); i++)
    {
        if (isdigit(input[i]))
            continue;
        else
            return false;
    }
    return true;
}

#endif // IS_NUMBER_H
