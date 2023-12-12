#include<iostream>
//#include<cmath>
using namespace std;

int main() {
    // Ініціалізація змінних
    int n = 5;
    double half_s = 0;
    double numbers[n];

    // Зчитування та обчислення значень для кожного введеного числа
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
        half_s = 0;

        // Обчислення середнього арифм. суми чисел
        for (int j = 0; j < i + 1; j++) {
            half_s += numbers[j];
        }
        cout << half_s / 2 << endl;
    }

    return 0;
}
