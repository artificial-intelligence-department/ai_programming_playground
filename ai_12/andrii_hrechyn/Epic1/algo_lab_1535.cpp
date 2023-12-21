// Algotester 1535

#include<iostream>
#include<math.h>
using namespace std;

int main(){
    float dollar_per_m, radius;
    int am_round;
    float result;   
cout << "Enter cost per meter: ";   
cin >> dollar_per_m;

cout << "Enter radius: ";   
cin >> radius;

cout << "Enter amount of rounds: ";   
cin >> am_round;

if (dollar_per_m>=0 && dollar_per_m <=1000 && am_round>=1 && am_round<=1000 && radius>0 && radius<=1000 ){
    result =   am_round * 2 * M_PI * radius * dollar_per_m;
    cout << result;
}
else {
    cout << "Invalid operators!";
}
    return 0;
}
