#include <iostream>

using namespace std;
int main() {
    // Оголошуємо змінну n для зберігання кількості членів ряду
    int n;

    // Зчитуємо кількість членів ряду з консолі
    cout << "Enter the number of members of the series: ";
    cin >> n;

    // Оголошуємо змінну sum для зберігання суми членів ряду
    double sum = 0;

    // Перебираємо члени ряду від 1 до n
    for (int i = 1; i <= n; i++) {
        // Додаємо до суми обернене значення поточного члена ряду
        sum += 1.0 / i;
    }

    // Виводимо суму членів ряду
    cout << "Sum equals:  " << sum << "\n";

    return 0;
}
