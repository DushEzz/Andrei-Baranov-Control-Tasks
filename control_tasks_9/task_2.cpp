#include <iostream>
#include <string>

using namespace std;

class Time {
    public:
        class wrong_format {
            public:
                int h, m, s;

                wrong_format(int hours, int minutes, int seconds)
                {
                    h = hours;
                    m = minutes;
                    s = seconds;
                }
        };

        Time()
        {
            Time::hours = 0;
            Time::minutes = 0;
            Time::seconds = 0;
        }

        Time(int hours, int minutes, int seconds)
        {
            if (seconds < 0 || minutes < 0 || hours < 0)
                throw wrong_format(hours, minutes, seconds);

            if (seconds >= 60)
            {
                minutes += (seconds / 60);
                seconds = seconds % 60;
            }

            if (minutes >= 60)
            {
                hours += (minutes / 60);
                minutes = minutes % 60;
            
            }

            if (hours >= 24)
                hours = hours % 24;

            Time::set_hours(hours);
            Time::set_minutes(minutes);
            Time::set_seconds(seconds);
        }

        void set_hours(int hours)
        {
            Time::hours = hours;
        }

        int get_hours()
        {
            return Time::hours;
        }

        void set_minutes(int minutes)
        {
            Time::minutes = minutes;
        }

        int get_minutes()
        {
            return Time::minutes;
        }

        void set_seconds(int seconds)
        {
            Time::seconds = seconds;
        }

        int get_seconds()
        {
            return Time::seconds;
        }

        void show_time()
        {
            if (hours <= 9)
                cout << "0" << hours << ":";
            else
                cout << hours << ":";

            if (minutes <= 9)
                cout << "0" << minutes << ":";
            else
                cout << minutes << ":";

            if (seconds <= 9)
                cout << "0" << seconds << endl;
            else
                cout << seconds << endl;
        }

        Time add(Time time_1, Time time_2)
        {
            Time time_result = Time(time_1.get_hours() + time_2.get_hours(), time_1.get_minutes() + time_2.get_minutes(), time_1.get_seconds() + time_2.get_seconds());
            
            return time_result;
        }
    private:
        int hours, minutes, seconds;
};

int main()
{
    int hours, minutes, seconds;

    cout << "Hours: "; cin >> hours;
    cout << "Minutes: "; cin >> minutes;
    cout << "Seconds: "; cin >> seconds;

    try
    {
        Time time_1 = Time(hours, minutes, seconds);
        Time time_2 = Time(45, 1, 87);
        Time time_3 = Time(5, 0, 12);
        Time time_4 = Time().add(time_2, time_3);

        cout << "Inputed time: ";
        time_1.show_time();
        cout << "Result time: ";
        time_4.show_time();
    }
    catch (Time::wrong_format& wr)
    {
        cout << "Some of the inputed values are less than 0";
        
        return 1;
    }

    return 0;
}