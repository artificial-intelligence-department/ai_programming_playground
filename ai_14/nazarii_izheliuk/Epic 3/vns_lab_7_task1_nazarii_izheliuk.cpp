#include<iostream>
#include<cmath>
#include <stdarg.h>

using namespace std;

double distance(int x1, int y1, int x2, int y2 ){
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

double belong(int x, int y, int x1, int y1, int x2, int y2, int x3, int y3)
{
    double area1, area2, area3, p1, p2, p3;

    p1 = (sqrt(((pow(x1 - x2, 2) + pow(y1 - y2, 2)) + (pow(x2 - x, 2) + pow(y2 - y, 2)) + (pow(x - x1, 2) + pow(y - y1, 2)))))/2;

    p2 = (sqrt(((pow(x2 - x3, 2) + pow(y2 - y3, 2)) + (pow(x3 - x, 2) + pow(y2 - y, 2)) + (pow(x - x2, 2) + pow(y - y2, 2)))))/2; 

    p3 = (sqrt(((pow(x3 - x, 2) + pow(y3 - y, 2)) + (pow(x - x1, 2) + pow(y - y1, 2)) + (pow(x1 - x3, 2) + pow(y1 - y3, 2)))))/2; 

    area1 = sqrt(p1 * (p1 - sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2))) * (p1 - sqrt(pow(x2 - x, 2) + pow(y2 - y, 2))) * (p1 - sqrt(pow(x - x1, 2) + pow(y - y1, 2))));

    area2 = sqrt(p2 * (p2 - sqrt(pow(x2 - x3, 2) + pow(y2 - y3, 2))) * (p2 - sqrt(pow(x3 - x, 2) + pow(y3 - y, 2))) * (p2 - sqrt(pow(x - x2, 2) + pow(y - y2, 2))));

    area3 = sqrt(p3 * (p3 - sqrt(pow(x3 - x, 2) + pow(y3 - y, 2))) * (p3 - sqrt(pow(x - x1, 2) + pow(y - y1, 2))) * (p3 - sqrt(pow(x1 - x3, 2) + pow(y2 - y3, 2))));

    return area1 + area2 + area3;


}

bool belong(double x, double y, ...) {
    va_list args;
    va_start(args, y);

    int n = va_arg(args, int); 

    int c = 0;
    double x1, y1, x2, y2;

    for (int i = 0; i < n; i++) {
        x1 = va_arg(args, double);
        y1 = va_arg(args, double);

        if (i == n - 1) { 
            x2 = va_arg(args, double);
            y2 = va_arg(args, double);
        } else {
            x2 = va_arg(args, double);
            y2 = va_arg(args, double);
        }

        


        if (((y1 > y) != (y2 > y)) && (x < (x2 - x1) * (y - y1) / (y2 - y1) + x1))
            c++;
    }

    va_end(args);
    return c % 2 == 1; 
}

int main() {
    int n;
    cout << "Введіть кількість вершин: ";
    cin >> n;

    double x, y; 
    cout << "Введіть координату x точки: ";
    cin >> x;
    cout << "Введіть координату y точки: ";
    cin >> y;

    cout << "Введіть координати вершин:" << endl;
    double coords[2 * n];
    for (int i = 0; i < 2 * n; ++i) {
        cin >> coords[i];
    }

    if (belong(n * 2, x, y, coords[0], coords[1])) {
        cout << "Належить";
    } else {
        cout << "Не належить";
    }

    return 0;
}