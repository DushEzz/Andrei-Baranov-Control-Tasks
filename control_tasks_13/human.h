#pragma once

#include <string>
#include <sstream>
#include <iostream>

using namespace std;

class human
{
	private:
		string name;
		string last_name;
		string second_name;
	public:
		virtual void get_data()
		{
			cout << "Input last name: "; cin >> last_name;
			cout << "Input name: "; cin >> name;
			cout << "Input second name: "; cin >> second_name;
		}

		virtual void show()
		{
			cout << "FIO: " << last_name << " " << name << " " << second_name << endl;
		}
};
