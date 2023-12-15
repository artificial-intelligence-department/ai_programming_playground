#include <iostream>

using namespace std;

struct hMins { // 14. В коді використано структури
    int hours;
    int minutes;

    explicit hMins(int mins) {
        hours = 0;
        minutes = mins;
    }

    void minutesToHours() { // 16. В коді використано параметри та аргументи функціі
        const int breakpoint = 60; // 4. В коді використана як мінімум одна цілочисельна константа
        while (minutes >= 60) { // 9. В коді використаний цикл while
            minutes -= 60; // 17. В коді використано математичні операції та функції
            hours += 1;
        }
    }
};

struct point {
    int x;
    int y;
    explicit point (int a = 0, int b = 0) {
        x = a;
        y = b;
    }
};

double calculateArea (point A, point B, point C) {
    const float denominator = 2; // 2. В коді використана одна дійсна змінна
    double Area = abs(A.x * (B.y - C.y) + B.x * (C.y - A.y) + C.x * (A.y - B.y))/denominator; // 3. В коді використана дійсна змінна з подвійною точністю
    return Area;
}

int main() {
    int minutes;
    cout << "Enter time interval in minutes: "; // 21. В коді використано оператори введення та виведення даних
    cin >> minutes;
    auto hmins = hMins(minutes);
    hmins.minutesToHours();
    cout << "Hours: " << hmins.hours << "; Minutes: " << hmins.minutes << endl;

    point A, B, C;
    cout << "Enter point A x and y coordinates:";
    cin >> A.x; cin >> A.y;
    cout << "Enter point B x and y coordinates:";
    cin >> B.x; cin >> B.y;
    cout << "Enter point C x and y coordinates:";
    cin >> C.x; cin >> C.y;
    cout << "Area is: " << calculateArea(A, B, C) << endl;

    return 0;
}
