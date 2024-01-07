#include <iostream>

using namespace std;

int main()
{
 int KOL;
 cout << "Enter puck per hour: " << endl;
 cin >> KOL;

 const int shift_standart = 8; // звичайна зміна
 const int shift_day = 2; // 2 зміни
 const int month_days = 30;
 const int relax_days = 4; // вихідні дні
 const int profilactic_hour = 1; // час на профілактику верстата

 int work_hours = shift_standart - profilactic_hour;
 int work_days = month_days - relax_days;

 int puck_per_8 = KOL * work_hours;
 int puck_per_day = puck_per_8 * shift_day;
 int puck_per_month = puck_per_day * work_days;

 cout << "Puck per 8 hours: " << puck_per_8 << endl;
 cout << "Puck per 1 day: " << puck_per_day << endl;
 cout << "Puck per 1 month: " << puck_per_month << endl;

 return 0;

}
