#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    system("chcp 1251");

    ofstream out("array.txt", ios::out | ios::binary);
    if (!out) 
    {
        cout << "Файл открыть невозможно\n";

        return 1;
    }

    const int N = 10;
    int a[N] = { 1, 25, 6, 32, 43, 5, 96, 23, 4, 55 };

    int min = 0;
    int buf = 0;

    out << "Исходный массив: ";
    for (int i : a)
        out << i << " ";

    for (int i = 0; i < N; i++)
    {
        min = i;
        for (int j = i + 1; j < N; j++)
            min = (a[j] < a[min]) ? j : min;

        if (i != min)
        {
            buf = a[i];
            a[i] = a[min];
            a[min] = buf;
        }
    }

    out << "\nОтсортированный массив: ";
    for (int i : a)
        out << i << " ";

    out.close();

    return 0;
}
