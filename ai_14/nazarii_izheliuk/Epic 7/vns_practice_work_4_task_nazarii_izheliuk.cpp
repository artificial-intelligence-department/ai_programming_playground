#include<iostream>
#include<math.h>

using namespace std;

double function(double x) { //16. в коді використано параметри та аргументи функції			
    return 5 * (pow(x, 2)) - x + 2; //17. в коді використано математичні операції та математичні функції
}

double integral(double x1, double x2, int n) {  // 16. в коді використано параметри та аргументи функції

    double width = (x2 - x1) / n;

    double integral = 0;

    for (int i = 0; i < n; ++i) {
        double x_left = x1 + i * width;       
        double x_right = x1 + (i + 1) * width; 
        integral += function((x_left + x_right) / 2) * width; //15. в коді використано рекурсивну функцію
    }

    return integral;
}

int main() {
    double x1, x2;  //3. в коді використана як мінімум одна дійсний з подвійною точністю змінна
    int n;  //1. в коді використана як мінімум одна цілочисельна змінна

    cout << "Введіть межі інтегрування: ";
    cin >> x1 >> x2;    
    cout << "Введіть точність обчислення: "; 
    cin >> n;   //21. в коді використано оператори виведення та введення даних

    double result = integral(x1, x2, n); //16. в коді використано параметри та аргументи функції

    cout << "Результат: " << result << endl; //21. в коді використано оператори виведення та введення даних

    return 0;
}
