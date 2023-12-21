#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// Функція для обчислення точного значення ln(x/2)
double y(double x) { // 
    return 0.5 * log(x);
}

// Функція для обчислення значення ln(x/2) через розклад у степеневий ряд
double sum_n(int i, double x) {
    double sum = 0.0;
    double term = 1.0;

    for (int n = 0; n <= i; ++n) {
        term *= pow((x - 1) / (x + 1),2*n+1);
        sum += term / (2 * n + 1);
    }

    return sum;
}

// Функція для обчислення значення ln(x/2) з заданою точністю ε
double sum_e(double epsilon, double x) {
    double sum = 0.0;
    double term = 1.0;
    int n = 1;

    while (term > epsilon) {
        term *= pow((x - 1) / (x + 1),2*n+1);
        sum += term / (2 * n + 1);
        n++;
    }

    return sum;
}

int main() {
    // Задані параметри
    double a = 0.2;
    double b = 1.0;
    int k = 10;
    int n = 10;
    double epsilon = 0.0001;

    
    // Обчислення та вивід результатів для кожного x
    for (int i = 1; i <= k; i++) {
        double x = a + i * (b - a) / k;
        double function = y(x);
        double ap_sum_N = sum_n(n, x);
        double ap_sum_E = sum_e(epsilon, x);

        // Вивід результатів
        cout << fixed << setprecision(7);
        cout << " | X: " << x <<  " | Y: " << function <<  " | Sum n (10): " << ap_sum_N << " | Sum epsilon (0.0001): " << ap_sum_E << "\n";
    }

    return 0;
}
