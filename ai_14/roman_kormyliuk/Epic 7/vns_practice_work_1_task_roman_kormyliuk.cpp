#include <iostream>
#include <cmath>
using namespace std;
int main(){
    double b = 15.5, x = -2.9, a = 1.5, s, y, P; // Визначення констант.
    y = cos(x * x * x) * cos(x* x * x) - x / sqrt(a*a + b*b); // Обчислення значень змінних.
    s = pow(sin(x+a),3); // Ввів число в степінь для кращого вигляду написання P.
    P = sqrt(x * x + b) - b * b * s / x * y; // Обчислюю значення P за формулою, заданою в задачі.
    cout << "P = " << P << endl; 
}