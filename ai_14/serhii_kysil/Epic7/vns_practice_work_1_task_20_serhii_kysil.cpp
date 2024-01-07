#include <iostream>
#include <cmath> 
using namespace std;
int main(){
    double s, d; //дійсна змінні з подвійною точністю(3), для збереження результату математичних операцій нижче
    const double a = 0.5; //цілочисельна константа(4), для введення значень в формулу нижче
    const double b = 2.9;
    const double x = 0.3;
    s = (pow(a, x) + pow(b, -x)*sin(a - b))/(sqrt(fabs(a- b))); //математичні операції pow, sqrt та математичні функції sin і cos(17), для коректного обчислення результату
    d = a*exp(-sqrt(a))*cos((b*x)/a);
    cout << s << "\n" <<d; //функція виведення даних(21), для виводу отриманого результату 
    return 0;
}