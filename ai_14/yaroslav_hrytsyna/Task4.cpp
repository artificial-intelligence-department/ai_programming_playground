#include <iostream>
using namespace std;

int main() {
    int n;
    double sum = 0.0;

    // ввід
    cout << "Введіть кількість чисел: ";
    cin >> n;

    cout << "введіть " << n << " чисел:" << endl;

    for (int i = 0; i < n; ++i) {
        double num;
        cin >> num;

        //додаємо
        sum += num;
    }

    // шукаємо середнє
    double average = sum / n;

    // Вивід
    cout << "Середнє: " << average << endl;

    return 0; 
}
