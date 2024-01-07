#include <iostream>
#include <cmath>
using namespace std;
int main (){
   double b = 15.5; // Оголошуємо змінну b зі значенням 15.5
    double x = -2.9; // Оголошуємо змінну x зі значенням -2.9
    double a = 1.5; // Оголошуємо змінну a зі значенням 1.5
    double P, y; // Оголошуємо змінні P та y

    // Обчислюємо значення змінної y за формулою
    y = pow(cos(pow(x, 3)), 2) - (x / sqrt(pow(a, 2) + pow(b, 2)));

    // Обчислюємо значення змінної P за формулою, використовуючи обчислене значення y
    P = sqrt(pow(x, 2) + b) - (pow(b, 2) * pow(sin(x + a), 3) / x) * y;
    cout<<"y= "<<y<<endl;//виводимо у
    cout<<"P= "<<P;//виводимо Р
    
    return 0;
}