#include <iostream>         //бібліотека 
using namespace std;

int main() {
    int n;      //ініціалізація цілочисельної змінної
    cout << "Enter amount of n: ";
    cin >> n;       //ввід числа 

    double sum = 0;     //ініціалізація дійсної змінної

    for (int i = 1; i <= n; ++i) {
        // Додаємо i-й член ряду до суми
        sum += 1.0 / i;
    }
    cout << "Sum of first numbers " << n << " members of ryad): " << sum << endl;       //вивід результату суми

    return 0;
}
