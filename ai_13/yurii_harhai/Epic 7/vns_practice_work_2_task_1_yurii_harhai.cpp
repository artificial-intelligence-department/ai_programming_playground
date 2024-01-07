#include<iostream>
#include<cmath>

using namespace std;

int main(){

double h {0.5};
double x{-2.5};
double z {};
double y {};

for(x; x<=2; x+=h){
    cout << "x is: " << x << endl;
    z=fabs(x)+pow(x,2);
    cout << "z is: "<< z << endl;
    y=z*(sin(pow((2+x),2)))/(2+x);
    cout << "y is: "<< y << endl;
    cout << endl;
}

return 0;
}