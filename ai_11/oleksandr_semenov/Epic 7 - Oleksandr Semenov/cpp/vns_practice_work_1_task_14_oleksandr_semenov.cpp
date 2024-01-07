#include <iostream>
#include <cmath>

using namespace std;
 // Задані значення констант
    const double a = 1.1; // 3. в коді використана як мінімум одна дійсний з подвійною точністю змінна
    const double b = 0.004; // 3. в коді використана як мінімум одна дійсний з подвійною точністю змінна
    const double x = 0.2; // 3. в коді використана як мінімум одна дійсний з подвійною точністю змінна
int main() {
   double y;
   float z;
    // Розрахунок виразу y = sin^3(a^2) - \sqrt[3]{x/b}
    y = pow(sin(pow(a, 2)), 3) - cbrt(x / b);

    // Розрахунок виразу z = x^2/a + cos^2(x+b)^3
    z = pow(x, 2) / a + pow(cos(x + b), 6);

      cout <<"Результат для y:"<< y << endl;
      cout <<"Результат для z:"<< z << endl;

    

    return 0;
}
