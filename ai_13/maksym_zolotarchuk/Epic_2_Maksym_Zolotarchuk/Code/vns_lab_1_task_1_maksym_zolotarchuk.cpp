#include <iostream>
#include <cmath>
using namespace std;

int main() {

double a = 1000, b = 0.0001, k, p, c;
double k = (pow(a + b, 3) - (pow(a, 3) + 3 * pow(a, 2) * b));
double p = (3 * a * pow(b, 2)) + (3 * pow(b, 3));
double c = k/p;

cout << "Result " << c;

return 0;

}
