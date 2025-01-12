
#ifndef PRINT_CHOICES_H // Functions.h include guard
#define PRINT_CHOICES_H

#include "assignment.h"

/**
 * Print a message along with a list of choices.
 * the intended format is the following:
 * "A message requesting a user input"
 * "(1):Choice 1"
 * "(2):Choice 2"
 * "(0):Cancel"
 * Beware, each return to line is already taken care of.
 */
void printChoices(string request, vector<string> allChoices)
{
    cout << request<<"\n";
    for (vector<string>::iterator choice = allChoices.begin(); choice != allChoices.end(); choice++)
    {
        cout << *choice << "\n";
    }
}

#endif // PRINT_CHOICES_H
