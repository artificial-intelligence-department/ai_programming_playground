#include <iostream> // Використали бібліотеку iostream, для роботи з виводом.
#include <cmath> // Використали бібліотеку cmath, для вирішення математичних завдань.

using namespace std; // Використали простор імен std;

int main() {
float a = 3.2; // Відоме значення a, яке було вказане в умові.
float b = 17.5; // Відоме значення b, яке було вказане в умові.
float x = -4.8; // Відоме значення x, яке було вказане в умові.
float exponent = exp(1.0); // Вказуємо змінну експоненти, щоб не конфліктувало, при піднесенні до степеня.
float rFirst, rSecond, sFirst, sSecond, yExample, zExample;
// rFirst - значення першої частини в виразі (невідомому) Y;
// rSecond - значення другої в виразі (невідомому) Y;
// sFirst - значення першої в виразі (невідомому) Z;
// sSecond - значення другої в виразі (невідомому) Z;
// yExample - весь вираз (невідомого) Y;
// zExample - весь вираз (невідомого) Z;

rFirst = pow(b, 2) * pow(tan(x), 3.0); // Присвоєння пеершій частині виразу значення, яке вказане в умові (Невідоме R)
rSecond = a / (pow(sin(x/2), 2.0)); // Присвоєння пеершій частині виразу значення, яке вказане в умові (Невідоме R)
sFirst = a * pow(exponent, -sqrt(3.0)); // Присвоєння пеершій частині виразу значення, яке вказане в умові (Невідоме R)
sSecond = cos(b * x / a); // Присвоєння пеершій частині виразу значення, яке вказане в умові (Невідоме R)
yExample = rFirst - rSecond; // Зібрали все до купи в один вираз невідомого R;
zExample = sFirst * sSecond; // Зібрали все до купи в один вираз невідомого S;
cout << "\nЗначення виразу Y = " << yExample; // Виводимо значення R.
cout << "\nЗначення виразу Z = " << zExample; // Виводимо значення S.


return 0; // Завершуємо програму.
}