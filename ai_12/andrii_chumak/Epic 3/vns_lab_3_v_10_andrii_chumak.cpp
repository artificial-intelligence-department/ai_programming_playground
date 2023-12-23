#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

/*
Для х, що змінюється від a до b з кроком (b-a)/k, де (k=10), обчислити
функцію f(x), використовуючи її розклад в степеневий ряд у двох випадках:
а) для заданого n;
б) для заданої точності ε (ε=0.0001).
Для порівняння знайти точне значення функції.
*/

int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

// Функція обчислення суми для заданого n
double compute_Sn(double x, int n) {
    double Sn = 0.0;
    for (int k = 10; k <= n; k++) {
        Sn += cos(k * x) / factorial(k);
    }
    return Sn;
}

// Функція для обчислення суми із заданою точністю epsilon
double compute_Se(double x, double epsilon) {
    double Se = 0.0;
    int k = 10;
    double term = 1.0;
    while (abs(term) > epsilon) {
        Se += term;
        ++k;
        term = cos(k * x) / factorial(k);
    }
    return Se;
}

// Функція S(x)
double compute_S(double x) {
    return exp(cos(x)) * cos(sin(x));
}

int main() {
    // Задання параметрів
    double a = 0.1;
    double b = 1.0;
    double epsilon = 0.0001;
    int n = 20;

    // Результат
    for (double x = a; x <= b; x += 0.1) {
        double Sn = compute_Sn(x, n);
        double Se = compute_Se(x, epsilon);
        double Y = compute_S(x);
        std::cout << "X = " << x << " SN = " << Sn << " SE = " << Se << " Y = " << Y << endl;
        /*Тут X - значення параметра; SN - значення суми для заданого n; SE - значення
        суми для заданої точності; Y - точне значення функції*/
    }
}
