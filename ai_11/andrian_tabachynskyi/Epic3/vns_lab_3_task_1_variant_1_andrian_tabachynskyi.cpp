#include <iostream>
#include <cmath>

using namespace std;

int main() {

	double y = 0.0;
	int k = 10;
	const double pi = 3.14;
	double x = 5 / pi;
	double x1 = pi;
	double crok = (x1 - x) / k;


	do {
		y += (pow(pi, 2) / 8) - pi / 4 * fabs(x);
		x += crok;
	} while (x <= x1);
	cout << y << endl;

	double x2 = 5 / pi;
	double e = 0.0001;
	double sum = 0.0;
	double a = 0.0;
	int n = 0;

	do {
		a = cos(2 * n - 1) * x2 / (pow((2 * n - 1), 2));
		sum += a;
		n++;
	} while (a >= e);

	cout << sum << endl;

	for (int n = 0; n < 40; n++) {
		a = cos(2 * n - 1) * x2 / (pow((2 * n - 1), 2));
		sum += a;
	}
	cout << sum << endl;
}