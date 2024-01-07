#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main(){
cout << fixed << setprecision(2);
double R1 {};
double R2 {};
double R {};
cout << "Enter first electric chain: ";
cin >> R1;
cout << "Enter second electric chain: ";
cin >> R2;
R = 1 / (1/R1 + 1/R2);
cout << "Chain resistance is: "<< R;
    return 0;
}