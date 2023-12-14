#include <iostream>
#include <cmath>
using namespace std;
int main(){
    double x, a, ha, hx, z, t;
    int max;
    x = 1.0;
    a = -0.3;
    ha = 0.2;
    hx = 0.5;
    max = 4;
    while(x <= max){ //цикл while(9), для придання кожному значенню х з кроком hx, кожного значення а з кроком ha та введенням цих аргуметів у формулу
        z = (sqrt(x - 1.5) + pow(x, a))/pow(x - 2, 1.0/3);
        cout<<"x: "<< x <<"; a: "<< a <<"; z = "<< z << endl;
        x += hx; 
        a += ha;
    }
    return 0;
}