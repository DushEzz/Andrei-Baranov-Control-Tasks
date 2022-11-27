#include <iostream>
#include <string>
#include "time.h"

using namespace std;

int main()
{
    int hours, minutes, seconds;

    cout << "Hours: "; cin >> hours;
    cout << "Minutes: "; cin >> minutes;
    cout << "Seconds: "; cin >> seconds;

    Time time_1 = Time(hours, minutes, seconds);
    Time const time_2 = Time(45, 1, 87);
    Time const time_3 = Time(5, 0, 12);
    Time time_4 = Time().add(time_2, time_3);

    cout << "Inputed time: ";
    time_1.show_time();
    cout << "Result time: ";
    time_4.show_time();

    return 0;
}