#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main(){
cout << fixed << setprecision(3);
double r {};
double h {};
double pi {3.141592};
double S {};
cout << "Enter radius: ";
cin >> r;
cout << "Enter height: ";
cin >> h;
S = ((1.0/3)*(pi*pow(r,2))*(h));
cout << "Area of cone is: "<< S;
    return 0;
}