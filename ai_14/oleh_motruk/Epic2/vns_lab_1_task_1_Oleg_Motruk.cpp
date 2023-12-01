#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
float task_float(){
    float a , b , f_a , s_a , t_a; 
    a = 100.0;
    b = 0.001;
    f_a = pow((a+b),4);
    s_a = pow(a,4) + 4*pow(a,3)*b;
    t_a = 6*pow(a,2)*pow(b,2) + 4*a*pow(b,3) + pow(b,4);
    cout << (f_a - s_a )/t_a << endl;

    return 0;
}

double task_double(){
    double a , b , f_a , s_a , t_a; 
    a = 100.0;
    b = 0.001;
    f_a = pow((a+b),4);
    s_a = pow(a,4) + 4*pow(a,3)*b;
    t_a = 6*pow(a,2)*pow(b,2) + 4*a*pow(b,3) + pow(b,4);
    cout << (f_a - s_a )/t_a << endl;

    return 0;
}

int main(){
    task_float();

    task_double();
    return 0;
}