#pragma once

#include "human.h"
#include <string>

using namespace std;

class teacher: public human
{
	private:
		double time;
	public:
		void get_data()
		{
			human::get_data();

			cout << "Input amount of hours: "; cin >> time;
		}

		void show()
		{
			human::show();
			cout << "Amount of hours: " << time << "\n\n";
		}
};
