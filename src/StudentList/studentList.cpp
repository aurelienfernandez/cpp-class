#include "../assignment.hpp"

StudentList::StudentList(list<Student> list)
{
    studentList = list;
}

Student StudentList::getStudent(string input)
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

bool StudentList::exists(int option, string input)
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

void StudentList::printStudentInfo(Student student)
{
    cout << "firstname: " << student.firstName << "\nlastname: "
         << student.lastName << "\nid: "
         << student.id << "\nage: "
         << student.age << "\n\n";
}

list<Student>::iterator StudentList::getIteratorByID(int id)
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

