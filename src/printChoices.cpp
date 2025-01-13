#include "printChoices.hpp"

void printChoices(string request, vector<string> allChoices)
{
    cout << request << "\n";
    for (vector<string>::iterator choice = allChoices.begin(); choice != allChoices.end(); choice++)
    {
        cout << *choice << "\n";
    }
}
