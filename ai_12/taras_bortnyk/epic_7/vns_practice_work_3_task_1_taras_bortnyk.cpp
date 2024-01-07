#include <iostream>
using namespace std;

int main() {
    double notebook, cover, total;
    int num;

    cout << "Обчислення вартості покупки." << endl;
    cout << "Введіть початкові дані:" << endl;

    cout << "Ціна зошита (грн.) > ";
    cin >> notebook;

    cout << "Ціна обкладинок (грн.) > ";
    cin >> cover;

    cout << "Кількість комплектів > ";
    cin >> num;

    // Обчислення вартості покупки
    total = (notebook + cover) * num;

    cout << "Вартість покупки: " << total << " грн." << endl;

    return 0;
}