#include <iostream>
#include <map>

using namespace std;

struct StudentGrade
{
    string name;
    char grade;
};

int main()
{
    map <string, char> students;

    int n;

    cout << "Input number of students: "; cin >> n;

    for (int i = 0; i < n; i++)
    {
        StudentGrade student;

        cout << "Input student's name: "; cin >> student.name;
        cout << "Input student's grade: "; cin >> student.grade;

        students[student.name] = student.grade;

    }

    char choice; cout << "Do you want change grades? (y/n): "; cin >> choice;
    while (choice == 'y')
    {
        StudentGrade studenttochange;

        cout << "Input student's name: "; cin >> studenttochange.name;
        cout << "Input student's new grade: "; cin >> studenttochange.grade;

        students[studenttochange.name] = studenttochange.grade;

        cout << "Continue? (y/n): "; cin >> choice;
    }

    map <string, char>::iterator it = students.begin();
    for (int i = 0; i < n; i++, it++)
    {
        cout << "Student: " << it->first << ". Grade: " << it->second << endl;
    }
}
