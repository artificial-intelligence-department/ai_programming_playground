#include <iostream>
using namespace std;

int main()
{
    const int hour_in_shift = 7;
    double count;
    cout<< " Enter count of details per hour: ";
    cin>> count;
    cout<<"Manufactured parts in one day with one shift: "<< count * hour_in_shift<<endl;
    cout<<" Manufactured parts in one day with two shifts: "<< count * hour_in_shift * 2<<endl;
    cout<<" Manufactured parts in one month without weekends: "<< count * hour_in_shift * 26 <<endl;
    return 0;
}