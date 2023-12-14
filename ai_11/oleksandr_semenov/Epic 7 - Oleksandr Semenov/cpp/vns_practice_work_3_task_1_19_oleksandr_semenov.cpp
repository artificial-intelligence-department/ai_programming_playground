#include <iostream>
#include <fstream> // Додано для використання файлів
#include <cmath>

using namespace std;

struct Point {
    double x;
    double y;
};

// Функція для обчислення площі трикутника
double calculateTriangleArea(Point p1, Point p2, Point p3) {//17. в коді використано математичні операції та математичні функції
    // Обчислення сторін трикутника
    double a = sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
    double b = sqrt(pow(p3.x - p2.x, 2) + pow(p3.y - p2.y, 2));
    double c = sqrt(pow(p1.x - p3.x, 2) + pow(p1.y - p3.y, 2));

    // Обчислення площі за формулою Герона
    double p = (a + b + c) / 2;
    double area = sqrt(p * (p - a) * (p - b) * (p - c));
    return area;
}

int main() {
    // Введення координат кутів трикутника
    Point points[3]; // Використання масиву точок

    cout << "Обчислення площі трикутника." << endl;
    cout << "Введіть координати кутів (числа розділяйте пропуском):" << endl;

    for (int i = 0; i < 3; ++i) {
        cout << "x" << i + 1 << ", y" << i + 1 << " > ";
        cin >> points[i].x >> points[i].y;
    }

    // Обчислення площі трикутника
    double area = calculateTriangleArea(points[0], points[1], points[2]);


    // Запис результату у файл
    ofstream outFile("result.txt");  //19. в коді використано функції роботи з файлами, для того, щоб записати у файл
    if (outFile.is_open()) {
        outFile << "Площа трикутника: " << area << " кв.см." << endl;
        outFile.close();
    }

    // Зчитування з файлу
    ifstream inFile("result.txt");
    if (inFile.is_open()) {
        string line;
        while (getline(inFile, line)) {
            cout << line << endl;
        }
        inFile.close();
    }

    return 0;
}
