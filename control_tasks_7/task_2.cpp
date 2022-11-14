#include <iostream>
#include <cmath>

using namespace std;

struct Roots
{
	double x_1;
	double x_2;

	void show_roots()
	{
		cout << "x1 = " << x_1 << ", x2 = " << x_2 << endl;
	}
};

bool check(double a, double b, double c)
{
	if (b * b - 4 * a * c < 0)
		return false;
	else 
		return true;
}

Roots solution(double a, double b, double c)
{
	Roots roots;

	roots.x_1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
	roots.x_2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);

	return roots;
}

int main()
{
	system("chcp 1251");

	double a, b, c;

	cout << "Введите коэффициенты a, b, c: "; cin >> a; cin >> b; cin >> c;

	if (check(a, b, c) == 0) 
	{
		cout << "Нет корней";

		return 0;
	}

	Roots result = solution(a, b, c);

	cout << "Ответ: "; result.show_roots();

	return 0;
}
