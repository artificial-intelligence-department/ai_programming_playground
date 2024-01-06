#include <iostream>
#include <cmath>
using namespace std;
int main() {
    double a = 2.4;
    double x;
    
    cout << "Enter the value of x: ";
    cin >> x;

    // Перевірка, чи x входить в діапазон [-3, 3]
    if (x >= -3.0 && x <= 3.0) {              //5. в коді використані умовні оператори та розгалуження
        // Розгалуження: перевірка ділення на нуль
        if (x + 1 != 0) {
            double z = (pow(a, x) * log(fabs(x + pow(2, 3)))) / (x + 1);

           cout << " z: " << z << endl;
        } else {
            cout << "Error: Division by zero." << endl;  //18. в коді використано оператори виведення та введення даних
        }
    } else {
        cout << "Error: x is out of range[-3, 3]." << endl;
    }

    return 0;
}
