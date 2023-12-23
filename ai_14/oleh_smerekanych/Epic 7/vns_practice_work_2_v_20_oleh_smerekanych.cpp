#include <iostream>      //підключив бібліотеку
using namespace std;

int main() {
    const int numpoints = 10;       // Кількість точок

    int quadrantcount[4] = {0};        // Масив для зберігання кількості точок у кожній чверті

    for (int i = 0; i < numpoints; ++i) {       // Запускаємо цикл для введення координат кожної точки
        double x, y;

        cout << "Enter coordinates for point " << i + 1 << " (x y): ";  // Просимо користувача ввести координати точки
        cin >> x >> y;

        if (x > 0 && y > 0) {
            quadrantcount[0]++;
        } else if (x < 0 && y > 0) {
            quadrantcount[1]++;             // Визначаємо в якій чверті знаходиться точка та збільшуємо відповідний лічильник
        } else if (x < 0 && y < 0) {
            quadrantcount[2]++;
        } else if (x > 0 && y < 0) {
            quadrantcount[3]++;
        }
    }

    int max_quadrant = 0;
    for (int i = 1; i < 4; ++i) {           // Знаходимо чверть з найбільшою кількістю точок
        if (quadrantcount[i] > quadrantcount[max_quadrant]) {
            max_quadrant = i;
        }
    }

    cout << "The quadrant with the most points is: " << max_quadrant + 1 << endl;       // Виводимо результат

    return 0;
}
