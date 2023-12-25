#include <iostream>
#include <cmath>
using namespace std;
int main(){
    double x = 1.82,y=18.5, z = -3.4;
    double gamma = abs(pow(x,y/x)-pow(y/x,1/3));
    double phi = (x-y)*(y-z/(y-x))/(1+(y-x)*(y-x));
    cout << "gamma:" << gamma << '\n';
    cout << "phi:" << phi << '\n';
}