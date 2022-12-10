#include <iostream>

using namespace std;

class Time
{
    private:
        int hours, minutes, seconds;
    public:
        Time() : hours (0), minutes (0), seconds (0) { }

        Time(int h, int m, int s)
        {
            hours = h;
            minutes = m;
            seconds = s;

            if (seconds >= 60) 
            {
                minutes += seconds / 60;
                seconds = seconds % 60;
            }
            
            if (minutes >= 60)
            {
                hours += minutes / 60;
                minutes = minutes % 60;
            }

            if (hours >= 24)
            {
                hours = hours % 24;
            }
        }

        Time(float h)
        {
            hours = (h * 10) / 10;
            minutes = ((h - hours) * 60) / 10;
            seconds = (((h - hours) * 60) * 60) / 10;
        }

        operator float() const
        {
            float time = (hours * 3600 + minutes * 60 + seconds) / 3600;

            return time;
        }

        void get_time()
        {
            cout << "Input hours: "; cin >> hours;
            cout << "Input minutes: "; cin >> minutes;
            cout << "Input seconds: "; cin >> seconds;
        }

        void show_time()
        {
            if (hours <= 9) cout << "0" << hours << ":";
            else cout << hours << ":";

            if (minutes <= 9) cout << "0" << minutes << ":";
            else cout << minutes << ":";

            if (seconds <= 9) cout << "0" << seconds << endl;
            else cout << seconds << endl;
        }

        Time operator+ (const Time&) const;
        Time operator+ (const double&) const;
        Time operator- (const Time&) const;

        bool operator> (const Time&) const;
        bool operator< (const Time&) const;
        bool operator== (const Time&) const;

        friend std::ostream& operator<< (std::ostream& out, const Time& time);
};

std::ostream& operator<< (std::ostream& out, const Time& time)
{
    Time t = Time(time.hours, time.minutes, time.seconds);

    if (t.hours <= 9) out << "0" << t.hours << ":";
    else out << t.hours << ":";

    if (t.minutes <= 9) out << "0" << t.minutes << ":";
    else out << t.minutes << ":";

    if (t.seconds <= 9) out << "0" << t.seconds;
    else out << t.seconds;

    return out;
}

Time Time::operator+ (const Time& t_2) const
{
    int h = hours + t_2.hours;
    int m = minutes + t_2.minutes;
    int s = seconds + t_2.seconds;

    return Time(h, m, s);
}

Time Time::operator+ (const double& t_2) const
{
    Time time_2 = Time(t_2);

    int h = hours + time_2.hours;
    int m = minutes + time_2.minutes;
    int s = seconds + time_2.seconds;

    return Time(h, m, s);
}

Time Time::operator- (const Time& t_2) const
{
    int h = hours - t_2.hours;
    int m;
    int s;

    if (minutes < t_2.minutes)
    {
        m = minutes + 60 - t_2.minutes;
        h--;
    }
    else m = minutes - t_2.minutes;

    if (seconds < t_2.seconds)
    {
        s = seconds + 60 - t_2.seconds;
        m--;
    }
    else s = seconds - t_2.seconds;

    return Time(h, m, s);
}

bool Time::operator> (const Time& t_2) const
{
    double time_1 = hours * 3600 + minutes * 60 + seconds;
    double time_2 = t_2.hours * 3600 + t_2.minutes * 60 + t_2.seconds;

    if (time_1 > time_2) return true;
    else return false;
}

bool Time::operator< (const Time& t_2) const
{
    double time_1 = hours * 3600 + minutes * 60 + seconds;
    double time_2 = t_2.hours * 3600 + t_2.minutes * 60 + t_2.seconds;

    if (time_1 < time_2) return true;
    else return false;
}

bool Time::operator== (const Time& t_2) const
{
    double time_1 = hours * 3600 + minutes * 60 + seconds;
    double time_2 = t_2.hours * 3600 + t_2.minutes * 60 + t_2.seconds;

    if (time_1 == time_2) return true;
    else return false;
}

int main()
{
    Time time_1, time_2, time_3, time_4, time_5, time_6;

    time_1.get_time();
    cout << endl;
    time_2.get_time();

    time_3 = time_1 + time_2;
    time_4 = time_1 - time_2;
    time_5 = time_1 + 7.104;
    time_6 = 7.104 + time_1;

    cout << "time1 + time2 = " << time_3 << endl;
    cout << "time1 - time2 = " << time_4 << endl;

    cout << "Time + double = " << time_5 << endl;
    cout << "double + Time = " << time_6 << endl;

    bool time_gt = time_1 > time_2;
    bool time_lt = time_1 < time_2;
    bool time_eq = time_1 == time_2;

    if (time_gt == true) cout << time_1 << " > " << time_2 << endl;
    if (time_lt == true) cout << time_1 << " < " << time_2 << endl;
    if (time_eq == true) cout << time_1 << " = " << time_2 << endl;
}
