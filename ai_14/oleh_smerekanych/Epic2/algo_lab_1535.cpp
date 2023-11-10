#include<iostream>
#include<math.h>

using namespace std;

int main(){
    float dpm, rad;
    int am_round;
    float result;   
cout << "Enter sum per meter: ";   
cin >> dpm;

cout << "Enter radius of wheel: ";   
cin >> rad;

cout << "Enter amount of rounds: ";   
cin >> am_round;

if (dpm>=0 && dpm <=1000 && am_round>=1 && am_round<=1000 && rad>0 && rad<=1000 ){
    result  =  rad * 2 * M_PI * am_round * dpm;
    cout << result;
}
else {
    cout << "Invalid operators!";
}
    return 0;
}