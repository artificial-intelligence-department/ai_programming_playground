#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	const double pi = M_PI; // константа M_PI для отримання значення pi
	double x = 1.45;
	double y = -1.22;
	double z = 3.5;
	double b = 1 + pow(z, 2) / (3 + pow(z, 2) / 5);
	double a = (2 * cos(x - pi / 6) * b) / (0.5 + pow(sin(y), 2));

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	return 0;
}
