#include <iostream>
using namespace std;

struct Time
{
    int minutes;
    int hours;
};

int convertTime(Time time)
{
    return time.minutes + time.hours * 60;
}

Time convertTime(int minutes)
{
    Time time = {0};
    time.hours = minutes / 60;
    time.minutes = minutes % 60;
    return time;
}

int main()
{
    int time1 = 567;

    Time ttt = convertTime(time1);
    cout << ttt.hours << " hours " << ttt.minutes << " minutes \n";
    Time ggg = {0};
    ggg.hours = 4;
    ggg.minutes = 59;
    cout << convertTime(ggg) << " minutes \n";
}