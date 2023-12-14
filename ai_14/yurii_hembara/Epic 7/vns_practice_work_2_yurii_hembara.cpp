#include<iostream>
#include<cmath>
using namespace std;

int main() {
    // Оголошення та ініціалізація змінних
    int R = 10, a = 0, b = 0;
    int X_coord[5];
    int Y_coord[5];
    // Введення координат п'яти точок
    for (int i = 0; i < 5; i++) {
        cout << "Input coordinated of point #" << i + 1 << " : ";
        cin >> X_coord[i] >> Y_coord[i];
    }
    // Перевірка, чи кожна точка знаходиться всередині кола з радіусом R
    for (int i = 0; i < 5; i++) {
        // Використання формули кола (x^2 + y^2 <= R^2)
        if (pow(X_coord[i], 2) + pow(Y_coord[i], 2) <= R * R) {
            cout << "Point #" << i + 1 << " with coordinates (" << X_coord[i] << ";" << Y_coord[i] << ") is inside the circle" << endl;
        }
    }
    return 0;
}
