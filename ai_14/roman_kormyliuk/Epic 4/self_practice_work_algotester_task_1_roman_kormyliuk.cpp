#include <iostream>

using namespace std;

int main() {
int n;
cin >> n;

int a[n];
for (int i = 0; i < n; i++) {
    cin >> a[i];
}
// Створюємо масив довжини n, в якому будемо зберігати довжину найбільшої зростаючої підпослідовності, що закінчується на i-му елементі послідовності ai.
int mas[n];
for (int i = 0; i < n; i++) {
    mas[i] = 1;
}

// Проходимо по послідовності ai зліва направо.

for (int i = 1; i < n; i++) {
    for (int j = 0; j < i; j++) {
        if (a[i] > a[j] && mas[i] < mas[j] + 1) {
        mas[i] = mas[j] + 1;
        }
    }
}

// Знаходимо максимальне значення в масиві dp.

int max_element = 0;
for (int i = 0; i < n; i++) {
    if (max_element < mas[i]) {
        max_element = mas[i];
    }
}

cout << max_element << endl;

return 0;
}
