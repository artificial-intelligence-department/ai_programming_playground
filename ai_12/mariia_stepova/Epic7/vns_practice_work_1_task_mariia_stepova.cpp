#include <iostream>
#include <cmath>
using namespace std;
int main() {
   
    float a = 1.1;
    float b = 0.004;
    float x = 0.2;
    double y, z;
 // Використані 2 дійсних з подвійною точністю змінних та 3 дійсних змінні
   
    y = pow(sin(a * a), 3) - pow(x / b, 1.0 / 3);
 // в коді використано математичні операції та математичні функції
  
    z = (x * x) / a + pow(cos(pow(x + b, 3)), 2);
// в коді використано математичні операції та математичні функції

    cout << "y = " << y << endl;
    cout << "z = " << z << endl;
// в коді використано оператори виведення даних
   
    return 0;
}