#include <iostream>
#include <cmath>
using namespace std;


int Myroot(double, double, double, double&, double&);

int Myroot(double a, double b, double c, double &x1, double &x2)
{
	double d = b * b - 4 * a * c;

	if (d < 0)
	{
		return -1;
	}

	d = sqrt(d);
	
	x1 = (-b + d) / (2 * a);
	x2 = (-b - d) / (2 * a);

	if (x1 == x2)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

int main()
{
	system("chcp 1251");

	cout.precision(2);

	double x1, x2;

	double a, b, c;
	cout << "Введите через пробел коэффициенты квадратного уравнения (a, b, c): "; cin >> a; cin >> b; cin >> c;

	int result = Myroot(a, b, c, x1, x2);
	if (result == -1)
	{
		cout << "Корней уравнения нет";
	}
	else if (result == 1)
	{
		cout << "Корни уравнения x1 = " << x1 << ", x2 = " << x2;
	}
	else
	{
		cout << "Корень уравнения один x1 = x2 = " << x1;
	}

	return 0;
}
