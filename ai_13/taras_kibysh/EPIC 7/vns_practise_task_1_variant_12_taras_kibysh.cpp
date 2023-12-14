#include <iostream>
#include <cmath>

using namespace std;

int main(){
    // вводим велечини
    double x = 0.25, y = 1.31, a = 3.5, b =0.9;
    double  up, down, another; 
    // обчислюєм чисельник 
    up = pow(sin(a*pow(x, 3)+ b*pow(y,2)-a*b),3);
    //обчислюєм знаменник
    down = pow(pow((a * pow(x, 3) + b * pow(y, 2) - a), 2) + M_PI, 1/3);
    // обчислюєм длданок
    another = tan(a*pow(x,3) + b*pow(y,2) - a*b);

    // обчислюєм вираз
    double result = abs(up/down) + another;
    // виводим результат
    cout << result;



    return 0;
}