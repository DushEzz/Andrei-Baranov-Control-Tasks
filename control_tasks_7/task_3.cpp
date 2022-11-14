#include <iostream>
#include <string>
#include <tuple>
#include <cmath>

using namespace std;

using Tuple = tuple<double, double, string>;

Tuple solution(double a, double b, double c)
{
	double x1, x2, d = b * b - 4 * a * c;
	string flag;

	if (d < 0)
		flag = "none";
	else if (d == 0)
	{
		flag = "one";
		
		x1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
		x2 = x1;
	}
	else
	{
		flag = "all";
		
		x1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
		x2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a); 
	}

	return make_tuple(x1, x2, flag);
}

void print_roots(tuple<double, double, string> tuple)
{
	if (get<2>(tuple) == "none")
	{
		cout << "Корней нет" << endl;
	}
	else if (get<2>(tuple) == "one")
	{
		cout << "Один корень: " << "x = " << get<0>(tuple) << endl;
	}
	else
	{
		cout << "Корни: x1 = " << get<0>(tuple) << ", x2 = " << get<1>(tuple) << endl;
	}
}

int main()
{
	system("chcp 1251");

	double a, b, c;

	cout << "Введите коэффициенты a, b, c: "; cin >> a; cin >> b; cin >> c;
	
	auto result = solution(a, b, c);
	print_roots(result);

	return 0;
}
