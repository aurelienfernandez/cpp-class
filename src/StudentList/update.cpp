#include "../assignment.hpp"

void StudentList::updateStudent()
{
    string input;
    if (studentList.empty())
    {
        cout << "The database is empty, you need to have at least 1 student to use this feature.";
        system("pause");
        return;
    }

    int id;
    string firstName;
    string lastName;
    int age;

    cout << "Enter the ID of the student you want to modify\n";
    list<Student>::iterator iterator;
    while (1)
    {
        getline(cin, input);
        if (atoi(input.c_str()) == 0)
        {
            cout << "No student can have an ID equal to 0.\n";
            continue;
        }
        id = atoi(input.c_str());
        iterator = getIteratorByID(id);
        if (iterator != studentList.end())
        {
            break;
        }
        cout << "Student not found, you might have entered the wrong ID.\n";
    }
    system("cls");
    cout << "Enter the new first name of the student\n";
    cout << "Current first name is: " << iterator->firstName << "\n";
    getline(cin, firstName);

    system("cls");
    cout << "Enter the new las tname of the student\n";
    cout << "Current last name is: " << iterator->lastName << "\n";
    getline(cin, lastName);

    system("cls");
    cout << "Enter the new age of the student\n";
    cout << "Current age is: " << iterator->age << "\n";

    while (1)
    {
        getline(cin, input);
        if (isNumber(input))
        {
            break;
        }
        cout << "The age should only contain numbers.\n";
    }

    age = atoi(input.c_str());

    Student newVersion = Student(id, age, lastName, firstName);

    *iterator = newVersion;
    system("cls");
    printChoices("Do you wish to print all students?",
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
            printAllStudents();
            return;
        }
        else
        {
            cout << "Unknown input.\n";
        }
    }
}