#include<iostream>
#include<cmath>
using namespace std;

int main() {
    // Частина 1 завдання 5
    float price_nb = 0, price_cov = 0;
    int amount_nb = 0;

    // Введення початкових даних
    cout << "Введіть початкові дані: " << endl;
    cout << "Ціна зошита (грн.) > ";
    cin >> price_nb;
    cout << "Ціна обкладинок (грн.) > ";
    cin >> price_cov;
    cout << "Кількість комплектів > ";
    cin >> amount_nb;

    // виведення вартості покупки
    cout << "Вартість покупки: " << amount_nb * (price_cov + price_nb) << " грн. " << endl;

    // Частина 2
    float r, S, V;

    // Введення значення r
    cout << "Введіть r: ";
    cin >> r;

    // Обчислення та виведення S
    S = 4 * M_PI * r * r;
    cout << "S = " << S << endl;

    // Обчислення та виведення V
    V = 0.75 * M_PI * pow(r, 3);
    cout << "V = " << V << endl;

    return 0;
}
