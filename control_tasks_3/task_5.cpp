#include <iostream>
#include <string>

using namespace std;

string to_binary(int n)
{
    if (n == 1)
    {
        return "1";
    }
    else
    {
        return to_binary(n / 2) + to_string(n % 2);
    }
}

int main()
{
    system("chcp 1251");

    int n;
    cout << "Введите число, которое Вы хотите первести в двоичный формат: "; cin >> n;

    string result = to_binary(n);
    cout << "Результат: " << result << endl;

    return 0;
}