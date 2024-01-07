#include <iostream>
#include <cmath>
using namespace std;

int main() {
    // Заголовок таблиці
    cout << "Ступені двійки: " << endl;
    // Виведення ступенів двійки
    for (int i = 0; i <= 10; ++i) {
        cout << "2^" << i << " = " << pow(2, i) << endl;
    }
    return 0;
}