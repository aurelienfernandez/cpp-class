#ifndef STUDENT_H // class.h include guard
#define STUDENT_H
#include "../assignment.hpp"

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
    /**
     * Class constructor
     */
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

    /**
     * Class constructor
     */
    StudentList(list<Student> list);

    /**
     * Requests the user for input and create a new student using the provided data.
     */
    void addStudent();

    /**
     * Requests the user for an ID and delete the student assigned it.
     */
    void deleteStudent();

    /**
     * Sorts the list of students depending on different options and if it is ascending or descending.
     * Options indicate which element is being sorted:
     * 1 = by IDs,
     * 2 = by ages,
     * 3 = by first names.
     */
    void Sort();

    /**
     * Requests the user for an ID.
     * If the student exists, prompts the user for a first name, last name and the age.
     * Once finished, update the student with the new info.
     */
    void updateStudent();

    /**
     * Searches for a specific student by using a user input,
     * the function check all of the elements in each students.
     */
    Student getStudent(string input);

     /**
     * Prints each student's details in the following order:
     * First name, last name, ID, age.
     */
    void printAllStudents();

     /**
     * Asks for a specific student, either by ID, firstname or lastname,
     * and then print its info.
     */
    void printStudent();
private:
    /**
     * Checks if a student exists depending on an option,
     * the option is an int between 1 & 4, symbolizing
     * which element in the student is being searched
     */
    bool exists(int option, string input);

    /**
     * Prints the info of a student.
     */
    void printStudentInfo(Student student);

    /**
     * From an ID, get the iterator of a student.
     * If no student is found, it returns the end of the list.
     */
    list<Student>::iterator getIteratorByID(int id);

    /**
     * Compares two student depending on an "option",
     * the option indicate which element is choosen to sort the list:
     * 1: ID, 2: age, 3: first name.
     * The boolean named "isAscending" is used to identify
     * if the list should be ascending or descending, allowing bidirectional sorting.
     */
    bool compare(const Student &s1, const Student &s2, int option, bool isAscending);

    /**
     * Compares two sorted lists to identify which comes first depending on the elements
     * compared and if the list should be ascending or descending.
     */
    std::list<Student> merge(const std::list<Student> &left, const std::list<Student> &right, int option, bool isAscending);

    /**
     * Sorts the list of student depending on the which element (option) to sort:
     * 1: ID, 2:age, 3: first name.
     * The boolean named "isAscending" is used to identify
     * if the list should be ascending or descending, allowing bidirectional sorting.
     */
    std::list<Student> mergeSort(std::list<Student> &students, int option, bool isAscending);
};
#endif