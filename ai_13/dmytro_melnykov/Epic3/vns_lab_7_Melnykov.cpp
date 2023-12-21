#include <iostream>
#include <cmath>


using namespace std;

struct Point {
    double x, y;
};

// Функція для знаходження довжини відрізка між двома точками
double findDistance(const Point& p1, const Point& p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

// Функція для обчислення площі трикутника за координатами його вершин
double square(const Point& A, const Point& B, const Point& C) {
    double a = findDistance(B, C);
    double b = findDistance(A, C);
    double c = findDistance(A, B);

    // Застосовуємо формулу Герона для площі трикутника
    double s = 0.5 * (a + b + c);
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

// Функція площі трикутника з найбільгою діагоналлю багатокутника
double square1(const initializer_list<Point>& vertices) {
    double maxDiagonalLength = 0.0;

    // Знаходимо довжину найбільшої діагоналі
    for (auto it1 = vertices.begin(); it1 != vertices.end(); ++it1) {
        for (auto it2 = next(it1); it2 != vertices.end(); ++it2) {
            double diagonalLength = findDistance(*it1, *it2);
            if (diagonalLength > maxDiagonalLength) {
                maxDiagonalLength = diagonalLength;
            }
        }
    }

    // Площа трикутника (формула герона)
    double s = 0.5 * maxDiagonalLength;
    return sqrt(3.0) / 4.0 * pow(maxDiagonalLength, 2);
}

int main() {
    
    
    float ax;
    float ay;
    float bx;
    float by;
    float cx;
    float cy;
    Point A = {ax, ay};
    Point B = {bx, by};
    Point C = {cx, cy};
   
    cout <<"Enter ax:"; 
        cin>> ax;
    cout <<"Enter ay:";
        cin>>ay;
    cout <<"Enter bx:";
        cin>>bx;
    cout <<"Enter by:";
        cin>>by;
    cout <<"Enter cx:";
        cin>>cx;
    cout <<"Enter cy:";
        cin>>cy;

    // Площа трикутника ABC
    double areaABC = square(A, B, C);
    cout << "Square of triangle ABC: " << areaABC << endl;


    // Площа трикутника з діагоналлю найбільшої довжини
    double areaWithMaxDiagonal = square1({A, B, C});
    cout << "Square with  longer diagonal: " << areaWithMaxDiagonal << endl;

    return 0;
}
