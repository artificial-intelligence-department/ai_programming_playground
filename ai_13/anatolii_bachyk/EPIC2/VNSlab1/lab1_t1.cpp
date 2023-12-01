#include <iostream>
#include <cmath>
#include <cstdio>


using namespace std;

int main(){
    int a = 1000;
    float b = 0.0001;

    double c = pow(a+b,2) - (pow(a,2) - 2*a*b);
    double d = pow(b,2);

    double e = c/d;
    cout<<(e);
}