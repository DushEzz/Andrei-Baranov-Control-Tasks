#include <iostream>

using namespace std;

double sum(int n)
{
    if (n == 1)
    {
        return 5;
    }
    else
    {
        return n * 5 + sum(n - 1);
    }

}

int main()
{
    system("chcp 1251");

    int n;
    cout << "n = "; cin >> n;

    int result = sum(n);
    cout << "Результат: " << result << endl;

    return 0;
}