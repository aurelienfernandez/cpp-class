#include "../assignment.hpp"

void StudentList::printAllStudents()
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

void StudentList::printStudent()
{
    string input;
    cout << "\nEnter an the id, firstname or lastname of the student you want to print.\n";
    getline(cin, input);
    Student student = getStudent(input);
    if (student.id != 0)
    {
        system("cls");
        printStudentInfo(student);
    }
    system("pause");
}
