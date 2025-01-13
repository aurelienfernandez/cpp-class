#include "../assignment.hpp"

void StudentList::deleteStudent()
{
    string input;
    if (studentList.empty())
    {
        cout << "The database is empty, you need to have at least 1 student to be able to use this feature.\n";
        system("pause");
        return;
    }
    cout << "Enter the id of the student you want to delete\n";
    while (1)
    {
        getline(cin, input);
        if (atoi(input.c_str()) == 0)
        {
            cout << "The ID cannot be equal to 0. Please enter a correct ID.\n";
            system("pause");
            continue;
        }
        else
        {
            break;
        }
    }

    list<Student>::iterator student = getIteratorByID(atoi(input.c_str()));
    if (student == studentList.end())
    {
        cout << "Student not found, you might have entered the wrong ID.\n";
        system("pause");
        return;
    }
    system("cls");
    // Print the table header manually
    std::cout << "--------------------------------------------\n";
    std::cout << "| First Name    | Last Name     | Age | ID |\n";
    std::cout << "--------------------------------------------\n";

    // Print the student data manually with fixed column widths
    std::cout << "| " << student->firstName;
    for (int i = student->firstName.length(); i < 14; ++i)
    {
        std::cout << " "; // Padding spaces for first name
    }

    std::cout << "| " << student->lastName;
    for (int i = student->lastName.length(); i < 14; ++i)
    {
        std::cout << " "; // Padding spaces for last name
    }

    std::cout << "| " << student->age;

    // Padding spaces for age (assuming age will fit in 4 characters max)
    for (int i = 0; i < 4 - std::to_string(student->age).length(); ++i)
    {
        std::cout << " ";
    }

    std::cout << "| " << student->id << " |\n";
    std::cout << "--------------------------------------------\n";

    printChoices("Are you sure you want to delete this student?",
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
            studentList.erase(student);
            system("cls");
            cout << "Student deleted.\n";
            system("pause");
            return;
        }
        else
        {
            cout << "Unknown input.\n";
        }
    }
}
