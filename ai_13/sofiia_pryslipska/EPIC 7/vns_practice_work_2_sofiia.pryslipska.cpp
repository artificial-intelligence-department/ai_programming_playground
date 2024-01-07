#include <iostream>
using namespace std;


int main() {
    int x, y;
    int quadrant[4] = {0}; // Масив для підрахунку точок в кожній чверті


    for (int i = 0; i < 10; ++i) {
        cout << "Enter coordinates of point " << i + 1 << ": ";
        cin >> x >> y;


        // Перевірка, в якій чверті знаходиться точка та підрахунок кількості точок в кожній чверті
        if (x > 0 && y > 0) {
            quadrant[0]++; // Перша чверть
        } else if (x < 0 && y > 0) {
            quadrant[1]++; // Друга чверть
        } else if (x < 0 && y < 0) {
            quadrant[2]++; // Третя чверть
        } else if (x > 0 && y < 0) {
            quadrant[3]++; // Четверта чверть
        }
    }


    // Пошук чверті, в якій найбільше точок
    int maxQuadrant = 0;
    for (int i = 1; i < 4; ++i) {
        if (quadrant[i] > quadrant[maxQuadrant]) {
            maxQuadrant = i;
        }
    }


    cout << "The quadrant with the most points is quadrant " << maxQuadrant + 1 << "." << endl;
   
    return 0;
}
