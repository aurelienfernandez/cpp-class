#include "../assignment.hpp"

void StudentList::addStudent()
{
    int id;
    string firstname;
    string lastname;
    int age;
    string input;

    while (1)
    {

        system("cls");
        cout << "Enter an ID\n";
        while (1)
        {
            getline(cin, input);
            if (exists(1, input))
            {
                cout << "A student already possess this ID. Please enter a new ID\n";
                continue;
            }
            else if (!isNumber(input))
            {
                cout << "An ID should contain only number. Please enter a correct ID.\n";
                continue;
            }
            else if (atoi(input.c_str()) == 0)
            {
                cout << "An ID should not be equal to 0. Please enter a correct ID.\n";
                continue;
            }
            else
            {
                id = atoi(input.c_str());
                break;
            }
        }
        system("cls");
        while (1)
        {
            cout << "Enter a firstname\n";
            getline(cin, input);
            firstname = input;
            cout << "Enter a lastname\n";
            getline(cin, input);
            lastname = input;
            if (exists(3, firstname) && exists(4, lastname))
            {
                cout << "A student is already named " << firstname << " " << lastname << "\n";
                printChoices("You can either:",
                             {"(1): Enter a new firstname or lastname", "(0): Cancel"});
                getline(cin, input);
                if (input == "0")
                {
                    return;
                }
                else if (input == "1")
                {
                    system("cls");
                    continue;
                }
            }
            break;
        }
        cout << "Enter an age\n";
        while (1)
        {
            getline(cin, input);

            if (!isNumber(input))
            {
                cout << "An age should only contain number. Please enter a correct age.\n";
                continue;
            }
            else
            {
                age = atoi(input.c_str());
                break;
            }
        }
        studentList.push_back(Student(id, age, firstname, lastname));
        printChoices(
            "Student added!\nDo you wish to add another student?",
            {"(1):YES", "(0):NO"});
        while (1)
        {
            getline(cin, input);
            if (input == "0")
            {
                return;
            }
            else if (input == "1")
            {
                addStudent();
                return;
            }
            else
            {
                cout << "Unkown input.\n";
            }
        }
    }
}
