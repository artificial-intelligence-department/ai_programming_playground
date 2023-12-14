#include <iostream>
#include <cmath>

using namespace std;

float a = 0.75;
float b = 1.19;
float c = -2.5;


//розділимо систему на дві функції


float lower(float x) {          // - функція при х < 0.5         в коді використано додаткові функції для 
    float y = a*x + b*cos(x);                                 // кращого читання коду
     return y;
}

float higher(float x) {         // - функція при 0.5 <= х < 1
    float y = b*pow(x, 2) + c*sin(2*x);
    return y;
} 


int main() {

    //[0;1)

    for (float i = 0; i < 1; i += 0.1) {
        float x;
        x = i;
                                        // в коді використано умову if else для визначення того, яку функцію треба 
                                        // застосувати
        if (x < 0.5) {
            cout << "x = " << x << "\t" << "\t" << "y = " << lower(x) << endl;  // в коді використано
        }                                                                       // параметри та аргументи функцій
        else {
            cout << "x = " << x << "\t" << "\t" << "y = " << higher(x) << endl;
        }
    }

    return 0;
}