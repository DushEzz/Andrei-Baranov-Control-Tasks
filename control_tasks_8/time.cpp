#include <iostream>
#include <string>
#include "time.h"

using namespace std;

Time::Time()
{
    Time::hours = 0;
    Time::minutes = 0;
    Time::seconds = 0;
}

Time::Time(int hours, int minutes, int seconds)
{
    if (seconds >= 60) { minutes += (seconds / 60); seconds = seconds % 60; }
    if (minutes >= 60) { hours += (minutes / 60); minutes = minutes % 60; }
    if (hours >= 24) hours = hours % 24;

    Time::set_hours(hours);
    Time::set_minutes(minutes);
    Time::set_seconds(seconds);
}

void Time::set_hours(int time_hours)
{
    Time::hours = time_hours;
}

int Time::get_hours() const
{
    return Time::hours;
}

void Time::set_minutes(int time_minutes)
{
    Time::minutes = time_minutes;
}

int Time::get_minutes() const
{
    return Time::minutes;
}

void Time::set_seconds(int time_seconds)
{
    Time::seconds = time_seconds;
}

int Time::get_seconds() const
{
    return Time::seconds;
}

void Time::show_time() const
{
    if (hours <= 9) cout << "0" << hours << ":";
    else cout << hours << ":";
    if (minutes <= 9) cout << "0" << minutes << ":";
    else cout << minutes << ":";
    if (seconds <= 9) cout << "0" << seconds << endl;
    else cout << seconds << endl;
}

Time Time::add(Time time1, Time time2)
{
    Time time_result = Time(time1.get_hours() + time2.get_hours(), time1.get_minutes() + time2.get_minutes(), time1.get_seconds() + time2.get_seconds());
    return time_result;
}