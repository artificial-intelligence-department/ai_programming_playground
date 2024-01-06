#include <iostream>
#include <cmath>
using namespace std;

struct Time {
    int m;  // Minutes
    double s;  // Seconds
};

int main() {
    double dist;
    Time time;

    cout << "Введіть довжину дистанції (метрів):" << endl;
    cin >> dist;
    
    cout << "Введіть час (хвилин.секунд):" << endl;
    cin >> time.m >> time.s;

    time.s *= 100;
    double v = (dist / 1000) / ((time.m * 60 + time.s) / 3600);
    
    
    cout << "Дистанція: " << dist << "м" << endl;
    cout << "Час: " << time.m << "хв " << time.s << "сек = " << (time.m * 60 + time.s) << "сек" << endl;
    cout << "Швидкість: " << v << "км/год" << endl;

    return 0;
}
