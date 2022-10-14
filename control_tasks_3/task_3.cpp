#include <iostream>
#include <cmath>

using namespace std;

double area(double a)
{
    return pow(3, 1.0 / 2) * a * a / 4;
}

double area(double a, double b, double c)
{
    double p = (a + b + c) / 2;

    return sqrt(p * (p - a) * (p - b) * (p - c));
}

int main()
{
    system("chcp 1251");

    double type;
    cout << "Введите тип треугольника (1 - равносторонний, 2 - разносторонний): "; cin >> type;

    while (type != 1 && type != 2)
    {
        cout << "Введите, пожалуйста, корректное значение типа треугольника (1 или 2): "; cin >> type;
    }
    
    if (type == 1)
    {
        double a;

        cout << "Введите сторону a: "; cin >> a;

        cout << "Площадь данного треугольника равна: " << area(a) << endl;
    }
    else
    {
        double a;
        double b;
        double c;

        cout << "Введите сторону a: "; cin >> a;
        cout << "Введите сторону b: "; cin >> b;
        cout << "Введите сторону c: "; cin >> c;

        if (a + b > c and b + c > a and a + c > b)
        {
            cout << "Площадь данного треугольника равна: " << area(a, b, c) << endl;
        }
        else
        {
            cout << "Такого треугольника не существует!" << endl;
        }
    }

    return 0;
}