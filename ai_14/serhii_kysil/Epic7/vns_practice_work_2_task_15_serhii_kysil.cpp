#include <iostream>
#include <cmath>
using namespace std;
int main(){
    double x, a, ha, hx, max, z, t;
    x = 1.0;
    a = -0.3;
    ha = 0.2;
    hx = 0.5;
    max = 4;
    while(x <= max){
        z = (sqrt(x - 1.5) + pow(x, a))/pow(x - 2, 1.0/3);
        cout<<"x: "<< x <<"; a: "<< a <<"; z = "<< z << endl;
        x += hx; 
        a += ha;
    }
    return 0;
}