#include <iostream>
#include <cmath>

using namespace std;

double x(double a)
{
    return pow(a, 1 / 3.0);
}

double x(int n, double a)
{
    if (n == 0)
        return a / 3;
    else
        return (a / (x(n - 1, a) * x(n - 1, a)) + 2 * x(n - 1, a)) / 3;
}

int main()
{
    system("chcp 1251");

    double a;
    cout << "a = "; cin >> a;
    
    double result_1 = x(a);

    cout << "Результат работы стандартной функции: " << result_1 << endl;

    int n = 1;
    double result_2;

    do
    {
        result_2 = x(n, a);

        n += 1;
    }
    while (abs(result_2 - result_1) >= 0.0001);

    cout << "Результат работы рекурсивной функции: " << result_2 << endl;

    return 0;
}