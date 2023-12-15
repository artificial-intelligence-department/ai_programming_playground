#include<iostream>
#include<math.h>
#include <iomanip>

using namespace std;

int main(){
    double dpm, rad, result, am_round;

cin >> dpm;
cin >> rad;
cin >> am_round;

result  =  rad * 2 * M_PI * am_round * dpm;
cout << fixed << setprecision(7) << result;

    return 0;
}