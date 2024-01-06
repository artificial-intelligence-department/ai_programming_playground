#include <iostream>
#include <cmath>

using namespace std;

int main() {

float x1, x2, x3, y1, y2, y3; 

cout << "Введіть координати кутів (числа розділяйте пропуском)" << endl;
cout << "X1, Y1 => ";
cin >> x1 >> y1;
cout << "X2, Y2 => ";
cin >> x2 >> y2;
cout << "X3, Y3 => ";
cin >> x3 >> y3;


float S;

S = ((x1*y2 + x2*y3 + x3*y1)-(y1*x2 + y2*x3 + y3*x1))/2;

cout << "Площа трикутника: " << abs(S) << " кв. см";


return 0;
}