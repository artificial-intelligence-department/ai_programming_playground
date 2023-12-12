#include <iostream>

using namespace std;

int main() {
// Визначення змінних
int x[10], y[10], chvert[4] = {0};
// Введення координат точок
for (int i = 0; i < 10; i++) {
    cout << "Введіть координату x точки " << i + 1 << ": ";
    cin >> x[i];
    cout << "Введіть координату y точки " << i + 1 << ": ";
    cin >> y[i];
}
// Підрахунок кількості точок у кожній чверті
for (int i = 0; i < 10; i++) {
    if (x[i] > 0 && y[i] > 0) {
        chvert[1]++;
    } else if (x[i] < 0 && y[i] > 0) {
        chvert[2]++;
    } else if (x[i] < 0 && y[i] < 0) {
        chvert[3]++;
    } else {
        chvert[0]++;
    }
}
// Визначення чверті з найбільшою кількістю точок
int max_index = 0;
for (int i = 1; i < 4; i++) {
    if (chvert[i] > chvert[max_index]) {
        max_index = i;
    }
}
// Виведення результату
switch (max_index) {
    case 0:
        cout << "Більше всього точок у першій чверті." << endl;
        break;
    case 1:
        cout << "Більше всього точок у другій чверті." << endl;
        break;
    case 2:
        cout << "Більше всього точок у третій чверті." << endl;
        break;
    case 3:
        cout << "Більше всього точок у четвертій чверті." << endl;
        break;
}
return 0;
}
