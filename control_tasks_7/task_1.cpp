#include <iostream>

using namespace std;

struct Time
{
	int hours;
	int minutes;
	int seconds;

	void show_time()
	{
		if (hours < 10) 
			cout << "0";
		cout << hours << ":";
		if (minutes < 10) 
			cout << "0";
		cout << minutes << ":";
		if (seconds < 10)
			cout << "0";
		cout << seconds << "\n";
	}
};

Time input_time()
{
	Time time;

	cout << "Введите часы: "; cin >> time.hours;
	cout << "Введите минуты: "; cin >> time.minutes;
	cout << "Введите секунды: "; cin >> time.seconds;

	return time;
}

int convert_to_seconds(Time time)
{
	return time.hours * 3600 + time.minutes * 60 + time.seconds;
}

Time convert_to_time(int seconds)
{
	Time time;

	time.hours = (seconds / 3600) % 24;
	time.minutes = (seconds % 3600) / 60;
	time.seconds = (seconds % 3600) % 60;

	return time;
}

Time time_addition(Time time_1, Time time_2)
{
	Time time;

	int sum = convert_to_seconds(time_1) + convert_to_seconds(time_2);
	time = convert_to_time(sum);

	return time;
}

Time time_substraction(Time time_1, Time time_2)
{
	Time time;
	int sub = 0;

	int seconds_1 = convert_to_seconds(time_1);
	int seconds_2 = convert_to_seconds(time_2);

	sub = abs(seconds_1 - seconds_2);

	time = convert_to_time(sub);

	return time;
}


int main()
{
	system("chcp 1251");

	Time time = input_time();
	cout << "Введенное время - "; time.show_time();

	int seconds = convert_to_seconds(time);
	cout << "Введенное время в секундах - " << seconds << "\n";

	Time time_1 = input_time();
	Time time_2 = input_time();

	cout << "Результат сложения - "; time_addition(time_1, time_2).show_time();
	
	cout << "Результат вычитания - "; time_substraction(time_1, time_2).show_time();

	return 0;
}
