#include <iostream>
#include <cmath>
using namespace std;

int main() {
float a = 1000, b = 0.0001;
float k = pow(a + b, 3);
float l = pow(a, 3) + (3 * pow(a, 2) * b);
float f = (3 * a * pow(b, 2));
float p = (3 * pow(b, 3));
float c = (k - l) / (f + p);

float result = c;

cout << "Result " << c;

return 0;

}
