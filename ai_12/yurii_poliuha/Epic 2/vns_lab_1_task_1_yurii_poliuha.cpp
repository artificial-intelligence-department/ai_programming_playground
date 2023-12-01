#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int a = 1000;
    double b = 0.0001;
    float f = 0.0001;
    double func_d = (pow(a - b, 3) - (pow(a, 3) - 3 * b * pow(a, 2))) / (pow(b, 3) - 3 * a * pow(b, 2));
    float func_f = (pow(a - f, 3) - (pow(a, 3) - 3 * f * pow(a, 2))) / (pow(f, 3) - 3 * a * pow(f, 2));
    cout<<"Double function: "<<func_d<<endl;
    cout<<"Float function: "<<func_f<<endl;
    return 0;
}