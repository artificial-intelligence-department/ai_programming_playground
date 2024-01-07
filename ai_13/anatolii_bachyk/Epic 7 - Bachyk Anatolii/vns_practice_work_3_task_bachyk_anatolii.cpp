#include <iostream>
#include <cmath>

using namespace std;

void RunningSpeed() {
    double distance, time;

    cout << "Введіть довжину дистанції(метрів) > ";
    cin >> distance;

    cout << "Ведіть час (хвилини) > ";
    cin >> time;

    double timeInSeconds = time * 60;
    double speed = (distance / 1000) / (timeInSeconds / 3600);

    cout << "Дистанція: " << distance << " м" << endl;
    cout << "Часи " << time << " хв = " << timeInSeconds << " сек" << endl;
    cout << "Швидкість бігу = " << speed << " км/година" << endl;
}


void Sphere() {
    double r;
    cout << "Введіть радіус кулі > ";
    cin >> r;

    double volume = (4.0 / 3.0) * M_PI * pow(r, 3);
    double area = 4 * M_PI * pow(r, 2);

    cout << "Об'єм кулі = " << volume << endl;
    cout << "Площа поверхні кулі = " << area << endl;
}

int main() {
    RunningSpeed();
    Sphere();

    return 0;
}