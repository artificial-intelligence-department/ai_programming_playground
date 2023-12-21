#include<iostream>
using namespace std;

int time(int hours, int minutes)
{
    int hour_to_min;

    hour_to_min = (hours*60)+minutes;

    return hour_to_min;
}

void time(int minutes)
{
    int minutes_to_hour;
    minutes_to_hour = minutes/60;
    int remain = minutes % 60 ;
    cout<<minutes_to_hour<<" hours "<<remain<< " minutes";
}

int main()
{
    int a,b,d;
    cout<<"Enter hours and minutes"<<endl;
    cin>>a>>b;
    time(a,b);
    cout<<"Minutes: "<<time(a,b)<<endl;

    cout<<"Enter minutes: "<<endl;
    cin>>d;
    time(d);

    return 0;
}