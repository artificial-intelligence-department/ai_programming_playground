#include <iostream>

using namespace std;

int main() 
{
    // ініціалізуємо змінні
    int n;
    int a1 = 1;
    int d = 2;

    cout << "Введіть n: ";
    cin >> n;
    // Шукаємо Н член прогресії та Суму 
    int an = a1 + d * (n - 1);
    int sn = n * (a1 + an) / 2;
    // Виводимо суму
    cout << "Sn = " << sn << endl;

    return 0;
}

