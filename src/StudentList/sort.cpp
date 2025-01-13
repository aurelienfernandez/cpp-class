#include "../assignment.hpp"

void StudentList::Sort()
{
    printChoices("By which element do you want to sort students?",
                 {"(1):By ID", "(2):By Age", "(3):By first name", "(0):Cancel"});
    int option = 0;
    bool isAscending = true;
    string input;
    while (1)
    {
        getline(cin, input);
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
        getline(cin, input);
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
        getline(cin, input);
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

bool StudentList::compare(const Student &s1, const Student &s2, int option, bool isAscending)
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

std::list<Student> StudentList::merge(const std::list<Student> &left, const std::list<Student> &right, int option, bool isAscending)
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

std::list<Student> StudentList::mergeSort(std::list<Student> &students, int option, bool isAscending)
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
