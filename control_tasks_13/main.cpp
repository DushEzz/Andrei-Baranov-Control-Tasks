#include <iostream>
#include <vector>
#include "human.h"
#include "student.h"
#include "teacher.h"

using namespace std;

int main()
{
    human* people[100];

    int n = 0;
    char choice;

    do
    {
        cout << "Student or teacher? (s/t): "; cin >> choice;
        if (choice == 's')
            people[n] = new student;
        else
            people[n] = new teacher;

        people[n++]->get_data();

        cout << "Continue? (y/n): "; cin >> choice;
    } while (choice == 'y');

    for (int j = 0; j < n; j++)
        people[j]->show();
    
    cout << endl;
    
    return 0;
}
