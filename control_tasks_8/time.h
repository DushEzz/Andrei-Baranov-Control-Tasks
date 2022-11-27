#pragma once

#include <string>
#include <fstream>

using namespace std;

class Time {
	public:
		Time();
		Time(int, int, int);

		void set_hours(int);
		int get_hours() const;
		void set_minutes(int);
		int get_minutes() const;
		void set_seconds(int);
		int get_seconds() const;
		void show_time() const;

		Time add(Time, Time);
	private:
		int hours, minutes, seconds;
};
