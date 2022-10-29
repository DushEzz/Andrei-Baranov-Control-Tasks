#include iostream
#include string

using namespace std;

bool Input(int& a, int& b)
{
	cout << Введите два положительных числа через пробел ; cin  a; cin  b;

	if (a  0 && b  0)
	{
		return true;
	}

	return false;
}

int main()
{
	system(chcp 1251);

	int a, b;
	if (Input(a, b) == false)
	{
		cerr << "error";

		return 1;
	}

	int s = a + b;

	return 0;
}
