#include <iostream>
#include <math.h>

using namespace std;

int main(){
    // Оголошення та ініціалізація змінних
    float a = -0.5;
    float b = 1.7;
    float t = 0.44;
    double s, y, k, m, q;

    // Обчислення m за допомогою експоненційної функції, синуса та множення
    m = exp(-b*t)* sin(a*t + b);
    // Обчислення k за допомогою кореня квадратного та модуля
    k = sqrt(fabs(b*t+a));
    // Обчислення q за допомогою множення, підняття до ступеня та косинуса
    q = a* pow(t, 2)*cos(2*t);
    // Обчислення s за допомогою синуса та віднімання
    s = b*sin(q)-1;
    // Обчислення y шляхом віднімання k від m
    y = m - k;
    
    // Виведення результатів
    cout<<"y = "<<y<<endl;
    cout<<"s = "<<s;

    return 0;
}
