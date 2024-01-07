#include <iostream>
#include <cmath>
using namespace std;
#define pi 3.1415926535

int main() {
    double r1, r2, h, res;  
    //ввід необхідних даних  
    cout << "Enter radius of the cylinder: ";
    cin>> r1;
    cout << "Enter radius of the hole: ";
    cin >> r2;
    cout << "Enter height of the cylinder: ";
    cin >> h;

    // обчислюємо за формулою з завдання об'єм
    res = pi * h * abs((pow(r1, 2) - pow(r2, 2)));

    // вивід результату
    cout << "Your result: " << res << endl;
    return 0;
}
