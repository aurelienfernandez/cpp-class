#ifndef STUDENT_H // class.h include guard
#define STUDENT_H
#include "assignment.h"

/**
 * A class containing 4 different data:
 * - An ID
 * - An age
 * - A first name
 * - A last name
 */
class Student
{
public:
    int id;
    int age;
    string firstName;
    string lastName;
    Student(int ID, int AGE, string last, string first)
    {
        id = ID;
        age = AGE;
        lastName = last;
        firstName = first;
    }
};

/**
 * A class containing a list of students.
 * it contains the following features:
 * - Print all students,
 * - Print a single student,
 * - Add a student,
 * - Update a student,
 * - Delete a student,
 * - Sort the list.
 */
class StudentList
{
public:
    list<Student> studentList;
    StudentList(list<Student> list)
    {
        studentList = list;
    }

    /**
     * Requests the user for input and create a new student using the provided data.
     */
    void addStudent()
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
                cin >> input;
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
                cin >> input;
                firstname = input;
                cout << "Enter a lastname\n";
                cin >> input;
                lastname = input;
                if (exists(3, firstname) && exists(4, lastname))
                {
                    cout << "A student is already named " << firstname << " " << lastname << "\n";
                    printChoices("You can either:",
                                 {"(1): Enter a new firstname or lastname", "(0): Cancel"});
                    cin >> input;
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
                cin >> input;

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
            cin >> input;
            while (1)
            {
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

    /**
     * Requests the user for an ID and delete the student assigned it.
     */
    void deleteStudent()
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
            cin >> input;
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
        studentList.erase(student);
    }

    /**
     * Sorts the list of students depending on different options and if it is ascending or descending.
     * Options indicate which element is being sorted:
     * 1 = by IDs,
     * 2 = by ages,
     * 3 = by first names.
     */
    void Sort()
    {
        printChoices("By which element do you want to sort students?",
                     {"(1):By ID", "(2):By Age", "(3):By first name", "(0):Cancel"});
        int option = 0;
        bool isAscending = true;
        string input;
        while (1)
        {
            cin >> input;
            if (input == "0")
            {
                return;
            }
            else if (input == "1")
            {
                option = 1;
                break;
            }
            else if (input == "2")
            {
                option = 2;
                break;
            }
            else if (input == "3")
            {
                option = 3;
                break;
            }
            else
            {
                cout << "incorrect input.\n";
            }
        }

        system("cls");
        printChoices("By which order would your prefer to sort?",
                     {"(1):Ascending order", "(2):Descending order", "(0):Cancel"});
        while (1)
        {
            cin >> input;
            if (input == "0")
            {
                return;
            }
            else if (input == "1")
            {
                studentList = mergeSort(studentList, option, true);
                break;
            }
            else if (input == "2")
            {
                studentList = mergeSort(studentList, option, false);

                break;
            }
            else if (input == "3")
            {
            }

            else
            {
                cout << "incorrect input.\n";
            }
        }
        printChoices("The list has been sorted. Do you wish to print it?",
                     {"(1):YES", "(0):NO"});
        while (1)
        {
            cin >> input;
            if (input == "0")
            {
                return;
            }
            else if (input == "1")
            {
                system("cls");
                printAllStudents();
                return;
            }
            else
            {
                cout << "Incorrect input.\n";
            }
        }
    }

    /**
     * Requests the user for an ID.
     * If the student exists, prompts the user for a first name, last name and the age.
     * Once finished, update the student with the new info.
     */
    void updateStudent()
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
            cin >> input;
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
        cout << "Enter the new firstname of the student\n";
        cin >> firstName;
        system("cls");
        cout << "Enter the new lastname of the student\n";
        cin >> lastName;

        system("cls");
        cout << "Enter the new age of the student\n";
        while (1)
        {
            cin >> input;
            if (isNumber(input))
            {
                break;
            }
            cout << "The age should only contain numbers.\n";
        }

        age = atoi(input.c_str());

        Student newVersion = Student(id, age, lastName, firstName);

        *iterator = newVersion;
        printChoices("Do you wish to print all students?",
                     {"(1):YES", "(0):NO"});
        while (1)
        {
            cin >> input;
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

    /**
     * Checks if a student exists depending on an option,
     * the option is an int between 1 & 4, symbolizing
     * which element in the student is being searched
     */
    bool exists(int option, string input)
    {
        for (list<Student>::iterator student = studentList.begin(); student != studentList.end(); ++student)
        {
            switch (option)
            {
            case 1:
                if (student->id == atoi(input.c_str()))
                {
                    return true;
                }
                break;
            case 2:
                if (student->age == atoi(input.c_str()))
                {
                    return true;
                }
                break;
            case 3:
                if (student->firstName == input)
                {
                    return true;
                }
                break;
            case 4:
                if (student->lastName == input)
                {
                    return true;
                }
                break;
            default:
                cout << "Unknown option.\n";
                break;
            }
        }
        return false;
    }

    /**
     * Searches for a specific student by using a user input,
     * the function check all of the elements in each students.
     */
    Student getStudent(string input)
    {
        list<Student>::iterator result;
        bool isFound = false;
        for (list<Student>::iterator student = studentList.begin(); student != studentList.end(); ++student)
        {
            if (atoi(input.c_str()) == student->id || input == student->firstName || input == student->lastName)
            {
                if (isFound)
                {
                    cout << "Multiple students where found using either the firstname or lastname. Please try again with the ID if necessary.\n";
                    return Student(0, 0, "", "");
                }
                result = student;
                isFound = true;
            }
        }
        if (isFound)
        {
            return *result;
        }
        cout << "The student you are searching for is not in the database.\n";
        return Student(0, 0, "", "");
    }

    /**
     * Prints each student's details in the following order:
     * First name, last name, ID, age.
     */
    void printAllStudents()
    {
        if (studentList.empty())
        {
            cout << "The database is empty, please add a new student in order to print it.\n";
        }
        for (list<Student>::iterator student = studentList.begin(); student != studentList.end(); ++student)
        {
            printStudentInfo(*student);
        }
        system("pause");
    }

    /**
     * Asks for a specific student, either by ID, firstname or lastname,
     * and then print its info.
     */
    void printStudent()
    {
        string input;
        cout << "\nEnter an the id, firstname or lastname of the student you want to print.\n";
        cin >> input;
        Student student = getStudent(input);
        if (student.id != 0)
        {
            system("cls");
            printStudentInfo(student);
        }
        system("pause");
    }

private:
    /**
     * Prints the info of a student.
     */
    void printStudentInfo(Student student)
    {
        cout << "firstname: " << student.firstName << "\nlastname: "
             << student.lastName << "\nid: "
             << student.id << "\nage: "
             << student.age << "\n\n";
    }

    /**
     * From an ID, get the iterator of a student.
     * If no student is found, it returns the end of the list.
     */
    list<Student>::iterator getIteratorByID(int id)
    {
        list<Student>::iterator result;
        for (list<Student>::iterator student = studentList.begin(); student != studentList.end(); ++student)
        {
            if (id == student->id)
            {
                result = student;
                return result;
            }
        }
        return studentList.end();
    }

    /**
     * Compares two student depending on an "option",
     * the option indicate which element is choosen to sort the list:
     * 1: ID, 2: age, 3: first name.
     * A boolean named "isAscending" is used to identify
     *  if the list should be ascending or descending, allowing bidirectional sorting.
     */
    bool compare(const Student &s1, const Student &s2, int option, bool isAscending)
    {
        switch (option)
        {
        case 1: // Sort by ID
            return isAscending ? s1.id < s2.id : s1.id > s2.id;
        case 2: // Sort by Age
            return isAscending ? s1.age < s2.age : s1.age > s2.age;
        case 3: // Sort by first character of firstname
        {
            char c1 = s1.firstName.empty() ? 0 : s1.firstName[0];
            char c2 = s2.firstName.empty() ? 0 : s2.firstName[0];
            return isAscending ? c1 < c2 : c1 > c2;
        }
        default:
            throw std::invalid_argument("Invalid option. Use 1 for id, 2 for age, or 3 for first name.");
        }
    }

    std::list<Student> merge(const std::list<Student> &left, const std::list<Student> &right, int option, bool isAscending)
    {
        std::list<Student> result;
        auto it1 = left.begin();
        auto it2 = right.begin();

        while (it1 != left.end() && it2 != right.end())
        {
            if (compare(*it1, *it2, option, isAscending))
            {
                result.push_back(*it1);
                ++it1;
            }
            else
            {
                result.push_back(*it2);
                ++it2;
            }
        }

        result.insert(result.end(), it1, left.end());
        result.insert(result.end(), it2, right.end());

        return result;
    }

    std::list<Student> mergeSort(std::list<Student> &students, int option, bool isAscending)
    {
        if (students.size() <= 1)
        {
            return students;
        }

        auto mid = students.begin();
        std::advance(mid, students.size() / 2);

        std::list<Student> left(students.begin(), mid);
        std::list<Student> right(mid, students.end());

        left = mergeSort(left, option, isAscending);
        right = mergeSort(right, option, isAscending);

        return merge(left, right, option, isAscending);
    }
};
#endif