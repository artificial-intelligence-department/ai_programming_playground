#include <iostream>

using namespace std;

int main() {
    // Оголошуємо змінні R1, R2, R3 для зберігання опорів
    int R1,R2,R3;

    // Зчитуємо значення опорів з консолі
    cin >> R1 >> R2 >> R3;

    // Виводимо суму опорів, які підключені послідовно
    cout << "Resistance of an electric circuit of three resistors connected in series " << R1+R2+R3;

    return 0;
}
