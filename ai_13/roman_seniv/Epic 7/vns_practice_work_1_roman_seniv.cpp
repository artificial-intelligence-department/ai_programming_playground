#include <iostream>
#include <cmath>
using namespace std;

int main() {
    //використовую 3 дійсні(дробові) змінні типу double.
    double a = -0.5;
    double b = 1.7;
    double t = 0.44;

//використовую математичну функцію pow для знаходження степення числа, функцію sqrt для знаходження квадратного кореня, функцію abs для модуля
    // також тригонометричні функції sin i cos
    //використано математичні операції 

   
    double result = exp(-b * t) * sin(a * t + b) - sqrt(fabs(b * t + a));
    double result1 = b * sin(a * pow(t, 2) * cos(2 * t)) - 1;

    cout << result << endl;
    cout << result1 << endl;
    return 0;
}
