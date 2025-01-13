# cpp-class

## What is this repository?

This repository is an assignement asked by our current teacher Georgios Tsatiris. The assignement was the following:

1. Build a data type of your choice (class, struct), to represent one real-world set of entities (e.g. Students, Cars, Products, etc.). Think of appropriate attributes in each case (e.g. year of enrolment, name, etc.)

2. Create instances/objects of your data type and store them in a Data Structure of your choice (e.g. list, vector, BST). Optimally, the data structure should follow your own implementation. Data can be randomly generated.

3. Implement addition, retrieval, updating and removal functionalities, through a simple console menu.
Implement a version of Merge Sort, to sort your data structure based on a "sortable" attribute (e.g. year of enrolment, name)
Support any function that depends on search (retrieval, updating and removal), with your implementation of Binary Search (or, optionally, a 
suitable tree structure).

1. Maintain a public remote repository on GitHub, with just the necessary documentation on how to build and run your code. Include a short description about what your project does and what limitations it may have (bugs, unfinished tasks, etc.).

Moreover, this assignment is due on 12 January 2025.

## How to use?

### As a user

To use this progam as a user, just double click on the executable and follow the instructions.

> ⚠️ **Attention**: This program only works on windows machines.


### As a programmer

#### Structure

To simplify the use of this assignment I centralized every includes into a single file named [assignment.hpp](https://github.com/aurelienfernandez/cpp-class/blob/main/src/assignment.h).

Here is a representation of the current structure of the assignment:

```
src
├── StrudentList
|   ├── add.cpp
|   ├── delete.cpp
|   ├── print.cpp
|   ├── sort.cpp
|   ├── studentList.cpp
|   └── studentList.hpp
├── assignment.hpp
├── isNumber.hpp
├── isNumber.cpp
├── printChoices.hpp
├── printChoices.cpp
└── main.cpp
```

#### Example
Here is an example on how to use my work:
```c++
// Include this file in order to use the different classes and functions
#include "assignment.hpp" 

int main()
{
    StudentList students({Student(1, 26, "test1", "testName"),
                          Student(4, 33, "test2", "testName2"),
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
        cin >> input;  // Get user input
        system("cls"); // Clear console

        if (input == "0") // Quit
        {
            return 0;
        }
        else if (input == "1") // Prints all students
        {
            students.printAllStudents();
        }
        else if (input == "2") // Prints a single student
        {
            students.printStudent();
        }
        else if (input == "3") // Adds a student
        {
            students.addStudent(); 
        }
        else if (input == "4") // Updates a student
        {
            students.updateStudent();
        }
        else if (input == "5") // Deletes a student
        {
            students.deleteStudent();
        }
        else if (input == "6") // Sorts the list
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
```
If you do not have g++ in your device, download [mingw](https://www.mingw-w64.org/downloads/).

Once you have cloned the repo, written your code and installed migw, 
run this command in your terminal:
``` 
g++ ./[your file name].cpp  -o  [your file name].exe
```



> ⚠️ **Attention**:  Due to the way I wrote this program, the differents features are not made to work with other data structure and do not support new element. If you wish to modify the current data structure, most of the code would need to be reworked.

## Limitations

The main limitation is the architecture of my class and functions, I did not plan this assignement with polymorphism in mind.

Another limitation is the lack of elements in the student class. I aimed for the creation of the different features, thus I did not see any reason to include more variable for the student class.