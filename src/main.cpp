#include "assignment.hpp"

int main()
{
    StudentList students({Student(1, 26, "test1", "testName"),
                          Student(2, 33, "test2", "secondtestName"),
                          Student(3, 22, "Aurelien", "Fernandez")});

    string input;
    while (1)
    {
        system("cls"); // Clear console
        printChoices(
            "Choose an option:", {"(1):Print all students",
                                  "(2):Print a specific student",
                                  "(3):Add a student",
                                  "(4):Update a student",
                                  "(5):Remove a student",
                                  "(6):Sort database",
                                  "(0):Quit"});
        getline(cin, input); // Get user inputs
        system("cls");       // Clear console

        /*
=================================================================================
                                   QUIT
=================================================================================
        */
        if (input == "0")
        {
            return 0;
        }
        /*
=================================================================================
                        PRINT      ALL      STUDENT
=================================================================================
        */
        else if (input == "1")
        {
            students.printAllStudents();
        }
        /*
=================================================================================
                        PRINT      A        STUDENT
=================================================================================
        */
        else if (input == "2")
        {
            students.printStudent();
        }
        /*
=================================================================================
                        ADD        A        STUDENT
=================================================================================
        */
        else if (input == "3")
        {
            students.addStudent();
        }
        /*
=================================================================================
                        UPDATE     A        STUDENT
=================================================================================
       */
        else if (input == "4")
        {
            students.updateStudent();
        }
        /*
=================================================================================
                        DELETE     A        STUDENT
=================================================================================
        */
        else if (input == "5")
        {
            students.deleteStudent();
        }
        /*
=================================================================================
                        SORT                LIST
=================================================================================
        */
        else if (input == "6")
        {

            students.Sort();
        }
        else
        {
            cout << "Unkown input\n";
            system("pause");
        }
    }
}