#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int check(string);

string operate(string, string, string);

int check(string str)
{
	int spaces = 0;
	for (int i = 0; i < str.length(); i++) 
	{
		if (str[i] == ' ')
			spaces++; 
	}

	if (spaces != 3 || (spaces == 3 && str[str.length() - 1] == ' '))
		return -1;
	else
		return 1;
}

string operate(string f, string x, string y)
{
	int xi = stoi(x);
	int yi = stoi(y);

	if (f == "-a") 
		return to_string(xi + yi);
	else if (f == "-m") 
		return to_string(xi * yi);

	else
		return "неправильный флаг";
}

int main()
{
	system("chcp 1251");

	string str;
	cout << "Введите команду (выберите флаг: -a или -m): "; getline(cin, str);

	if (check(str) == -1)
	{
		cout << "Ошибка!"; 
		
		return 0;
	}

	string arr[4];

	int j = 0;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] != ' ') 
			arr[j] += str[i];
		else 
			j++;
	}
	
	cout << "Результат: " << operate(arr[1], arr[2], arr[3]);
}
