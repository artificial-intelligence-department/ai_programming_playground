#include <iostream>
#include <cmath>

using namespace std;

int distance(int x1, int y1, int z1, int x2, int y2, int z2) { // Функція для обчислення відстані між двома точками в тривимірному просторі
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) + pow(z2 - z1, 2));
}

bool isTriangle(int x1, int y1, int z1, int x2, int y2, int z2, int x3, int y3, int z3) { // Функція для перевірки існування трикутника в тривимірному просторі
    int a = distance(x1, y1, z1, x2, y2, z2);
    int b = distance(x2, y2, z2, x3, y3, z3);
    int c = distance(x3, y3, z3, x1, y1, z1);

    return (a + b > c) && (b + c > a) && (c + a > b);
}

int main() {
    int x1, y1, z1, x2, y2, z2, x3, y3, z3;

    cout << "enter coordinates A: ";
    cin >> x1 >> y1 >> z1;

    cout << "enter coordinates B: ";
    cin >> x2 >> y2 >> z2;

    cout << "enter coordinates C: ";
    cin >> x3 >> y3 >> z3;

    if (isTriangle(x1, y1, z1, x2, y2, z2, x3, y3, z3)) {
        cout << "triangle exist" << endl;
    } else {
        cout << "triangle doesnt exist" << endl;
    }

    return 0;
}
