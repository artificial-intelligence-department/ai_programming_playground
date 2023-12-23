#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	double a = 1000, b = 0.0001;
	double N = (pow(a + b, 3) - pow(a, 3)) / (3 * a * pow(b, 2) + pow(b, 3) + 3 * pow(a, 2) * b);
	cout << "result№1:" << N << endl;

	float a1 = 1000, b1 = 0.0001;
	float N1 = (pow(a1 + b1, 3) - pow(a1, 3)) / (3 * a1 * pow(b1, 2) + pow(b1, 3) + 3 * pow(a1, 2) * b1);
	cout << "result№2:" << N1 << endl;
	return 0;
}