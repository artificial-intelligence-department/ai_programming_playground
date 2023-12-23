#include <iostream>
using namespace std;

 
int main() {
    int KOL;
    cout << "Enter the number of washers produced per hour:";
    cin >> KOL;

    const int servicetime = 1;  // Using const to initialize free time in the shift
    const int dayoff = 4;       // Using const to initialize free days in the month
    int pershift = KOL * 8 - servicetime;   //formula to calculate the number of washers produced per shift
    int perday = pershift * 2;                   //formula to calculate the number of washers produced per da
    int permonth = perday * 20 - dayoff;                  //formula to calculate the number of washers produced per month


    cout << "The number of washers produced per shift is equal to " << pershift << endl; //Output
    cout << "The number of washers produced per day is equal to " << perday << endl;
    cout << "The number of washers produced per month is equal to " << permonth << endl;

}